#include <stdio.h>
#include <stdlib.h>
#include "LQR_Controller.h" 

int main(void) {
    LQR_Controller_initialize();
    
    // Apriamo il file con i dati di Simulink in lettura
    FILE *file_in = fopen("input_sensore.csv", "r");
    // Apriamo il file per salvare i risultati in scrittura
    FILE *file_out = fopen("risultati_sil.csv", "w");
    
    if (file_in == NULL || file_out == NULL) {
        printf("Errore nell'apertura dei file!\n");
        return 1;
    }

    fprintf(file_out, "Step,y_Sensore,u_Comando\n");
    
    double y_corrente;
    int step = 0;

    // Leggiamo il file riga per riga finché ci sono dati (fino a 10 secondi / 100 step)
    while (fscanf(file_in, "%lf", &y_corrente) == 1 && step <= 100) {
        
        // 1. Iniezione del dato REALE di Simulink
        LQR_Controller_U.y = y_corrente; 
        
        // 2. Calcolo del controllo
        LQR_Controller_step();

        // 3. Salvataggio del risultato
        fprintf(file_out, "%d,%f,%f\n", step, LQR_Controller_U.y, LQR_Controller_Y.u);
        step++;
    }

    fclose(file_in);
    fclose(file_out);
    LQR_Controller_terminate();
    
    printf("--- Validazione con Data Injection completata ---\n");
    return 0;
}