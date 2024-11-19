#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

// Función para generar un número aleatorio en el rango [-1, 1]
double random_double() {
    return ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
}

// Función para calcular los puntos dentro del círculo
int calcular_puntos_circulo(int iteraciones) {
    int puntos_dentro_circulo = 0;
    for (int i = 0; i < iteraciones; i++) {
        double x = random_double();
        double y = random_double();
        if (x * x + y * y <= 1.0) {
            puntos_dentro_circulo++;
        }
    }
    return puntos_dentro_circulo;
}

int main(int argc, char** argv) {
    int total_iteraciones = (int)pow(10,7); // Total de iteraciones
    int my_rank, num_procs; // ID del proceso y número total de procesos
    int iteraciones_por_proceso;
    int puntos_dentro_local, puntos_dentro_total;
    double pi_aproximado;
    double tiempo_inicio, tiempo_fin;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    // Dividir las iteraciones entre los procesos
    iteraciones_por_proceso = total_iteraciones / num_procs;

    // Semilla para generación de números aleatorios
    srand(time(NULL) + my_rank);

    // Medir el tiempo de inicio
    if (my_rank == 0) {
        tiempo_inicio = MPI_Wtime();
    }

    // Calcular los puntos dentro del círculo para este proceso
    puntos_dentro_local = calcular_puntos_circulo(iteraciones_por_proceso);

    // Reducir los resultados y sumar los puntos dentro del círculo
    MPI_Reduce(&puntos_dentro_local, &puntos_dentro_total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calcular el valor aproximado de PI y medir el tiempo
    if (my_rank == 0) {
        pi_aproximado = 4.0 * puntos_dentro_total / total_iteraciones;
        tiempo_fin = MPI_Wtime();

        // Calcular el error relativo
        double pi_teorico = M_PI;
        double error_relativo = fabs((pi_aproximado - pi_teorico) / pi_teorico) * 100.0;

        // Mostrar resultados
        printf("Valor aproximado de PI: %.15f\n", pi_aproximado);
        printf("Tiempo de ejecución: %.4f segundos\n", tiempo_fin - tiempo_inicio);
        printf("Error relativo: %.6f %%\n", error_relativo);
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
