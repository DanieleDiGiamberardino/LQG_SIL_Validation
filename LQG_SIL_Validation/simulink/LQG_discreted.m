% Implementation of an LQG(Linear Quadratic Gaussian)
% Fasi: 1 Definiamo LQR per ottenere K sulla base del sistema nominale
% Fase: 2 Definiamo il sistema con i noise struttura classica
% Fase: 3 Kalman sul modello noise ottengo stima 
% Fase: 4 Creo LQG uso lqgreg(kalmf,K) 
% Fase: 5 Chiudo l'anello uso feedback(sys_noise,LQG,spec)
% Fase: 6 Simulo il modello t=0:0.01:10 ecc uso lsim
clc 
clear all

% Matrix of System
A = [0 1 ; -1 -0.5]; % x1 = position x2 = velocity cart
B = [0 ; 1];
C = [1 0];
D = 0;

%Sample time
Ts = 0.1;

% Define the system
sys = ss(A,B,C,D);

% Matrix of LQR
Q = [100 0 ; 0 1];
R = 0.1;

% Discrete nominal system
sys_nominal_discrete = c2d(sys,Ts,'zoh');
[Ad, Bd, Cd, Dd] = ssdata(sys_nominal_discrete);

% Discrete LQR Gain
K_discrete = dlqr(Ad, Bd, Q, R);
disp('Guadagno Discreto LQR K:');
disp(K_discrete);

% L'LQR si calcola SEMPRE sulla matrice A del plant originale
[K, P_lqr, E_lqr] = lqr(A, B, Q, R);
disp('Guadagno LQR K:');
disp(K);

% Parameter of Kalman Filter
W = 0.1;
V = 0.05;

% Definiamo come entra il disturbo. G = B significa che il disturbo 
% agisce come una forza sulla massa (stesso punto di ingresso di u).
G = [0; 1]; 
H = 0;      % Il rumore di processo non va direttamente nel sensore

% Creiamo il sistema esteso [u; w] richiesto da MATLAB per Kalman
% Gli ingressi ora sono due: il controllo u(t) e il disturbo w(t)
sys_noise = ss(A, [B, G], C, [D, H]);

% Definiamo il modello discreto del sys_noise per importalo su simulink
sys_noise_discrete = c2d(sys_noise,Ts,'zoh');
[ Ads, BGds, Cds, Dds] = ssdata(sys_noise_discrete);

Bds = BGds(:,1);
Gds = BGds(:,2);

% Sintesi dello stimatore ottimo
[kalmf, L, P_est] = kalman(sys_noise, W, V);
disp('Guadagno di Kalman L:');
disp(L);

% Creazione del Sistema a Ciclo Chiuso
% lqgreg crea il controllore (ingresso: y misurata, uscita: comando u)
LQG_controller = lqgreg(kalmf, K);

% Indichiamo a MATLAB quali "porte" collegare.
% In sys_noise, l'ingresso u è la colonna 1. L'uscita y è la riga 1.
in_u = 1; 
out_y = 1;

% Chiudiamo l'anello
sys_cl = feedback(sys_noise, LQG_controller, in_u, out_y, +1);

% sys_cl ha 2 ingressi: Input 1 = u_riferimento, Input 2 = w_disturbo.
% Estraiamo il sistema considerando SOLO il secondo ingresso (il disturbo)
% La sintassi sys(uscite, ingressi) ci permette di filtrare:
sys_cl_disturbo = sys_cl(:, 2); 

% Simulazione con Disturbo Stocastico
t = 0:0.01:10; 

% Creiamo il disturbo come vettore colonna (length(t) righe, 1 colonna)
w_disturbo = 0.5 * randn(length(t), 1); 

% Vettore degli stati iniziali: [x1; x2; x1_stimato; x2_stimato]
x0_tot = [3; 0; -3; 0]; 

% Simuliamo l'evoluzione del sistema
figure;
% Ora passiamo a lsim il sistema filtrato che ha un solo ingresso!
lsim(sys_cl_disturbo, w_disturbo, t, x0_tot);
title('Simulazione LQG: Reiezione al disturbo e convergenza');
xlabel('Tempo (s)');
ylabel('Posizione y (m)');
grid on;




