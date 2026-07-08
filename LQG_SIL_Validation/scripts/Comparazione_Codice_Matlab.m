%% Script di Validazione SIL - Controllore LQG

% 1. Importazione dei dati generati dal codice C
% La funzione readtable riconosce automaticamente l'intestazione delle colonne
filename = 'risultati_sil.csv';
sil_data = readtable(filename);

% 2. Estrazione dei vettori per comodità di manipolazione
% Accediamo alle colonne usando esattamente i nomi definiti nel fprintf del C
step      = sil_data.Step;
tempo_C = step * 0.1;
y_sensore = sil_data.y_Sensore;
u_comando = sil_data.u_Comando;

% 3. Caricamento dei dati di riferimento Simulink
% (Sostituisci questa parte caricando il tuo log originale da out.mat o workspace)
% Esempio fittizio se hai salvato i dati di Simulink come variabili 'sim_y' e 'sim_u':
 sim_step = out.tout; % O il vettore dei tempi discreti
 sim_y    = squeeze(out.y.Data);
 sim_u    = squeeze(out.u.Data); 
% Salva il vettore del sensore in un file leggibile dal C
writematrix(squeeze(sim_y), 'input_sensore.csv');
%% 4. Generazione del Plot Comparativo
fig = figure('Name', 'Report Validazione SIL vs Simulink', 'Color', 'w', 'Position', [100, 100, 800, 600]);

% --- Subplot 1: Andamento del Sensore (y) ---
subplot(2,1,1);
% Plot dei dati del codice C (Cerchi blu collegati)
plot(tempo_C, y_sensore, 'b-o', 'LineWidth', 1.5, 'MarkerSize', 5, 'MarkerFaceColor', 'w');
hold on;
% Togli il commento alla riga successiva per sovrapporre la curva Simulink (Linea tratteggiata rossa)
plot(sim_step, sim_y, 'r--', 'LineWidth', 2); 

grid on;
title('Profilo del Sensore (y)', 'FontSize', 12, 'FontWeight', 'bold');
xlabel('Step Temporale (k)', 'FontSize', 11);
ylabel('Ampiezza', 'FontSize', 11);
legend('Codice C (SIL)','Matlab', 'Location', 'best'); % Aggiorna in {'Codice C (SIL)', 'Modello Simulink'}

% --- Subplot 2: Azione di Controllo (u) ---
subplot(2,1,2);
% Plot dei dati del codice C (Quadrati verdi collegati)
plot(tempo_C, u_comando, 'g-s', 'LineWidth', 1.5, 'MarkerSize', 5, 'MarkerFaceColor', 'w');
hold on;
% Togli il commento alla riga successiva per sovrapporre la curva Simulink
 plot(sim_step, sim_u, 'r--', 'LineWidth', 2);

grid on;
title('Azione di Controllo LQG (u)', 'FontSize', 12, 'FontWeight', 'bold');
xlabel('Step Temporale (k)', 'FontSize', 11);
ylabel('Comando Attuatore', 'FontSize', 11);
legend('Codice C (SIL)','Matlab', 'Location', 'best');