# Aproximacion a π usando Monte Carlo y MPI
## Descripción
Este proyecto implementa un programa en C para calcular una aproximación de 𝜋 utilizando el método de Monte Carlo con paralelización mediante MPI (Message Passing Interface). El método distribuye el cálculo entre varios procesos, lo que permite aprovechar múltiples núcleos de una CPU para mejorar la eficiencia.

El algoritmo genera puntos aleatorios dentro de un cuadrado de lado 2 y evalúa cuántos caen dentro de un círculo inscrito en este cuadrado. La relación entre los puntos dentro del círculo y el total de puntos se utiliza para aproximar 𝜋.

---
## Características
1. **Paralelización:**
    Utiliza la librería MPI para distribuir los cálculos entre diferentes procesos.
2. **Calibración adaptable:**
    Permite configurar la cantidad de puntos y procesos a utilizar para la aproximación. 
3. **Medición de rendimiento:**
    Calcula el tiempo de ejecución y el error relativo respecto al valor teórico de 𝜋.
4. **Escalabilidad:**
    Es compatible con cualquier número de procesos, adaptándose automáticamente a la cantidad de iteraciones asignadas a cada proceso.
---
## Ejemplo de resultado

*Con 𝑁=10⁵ puntos y 4 procesos:*
```
Valor aproximado de PI: 3.142192000000000
Tiempo de ejecución: 0.0042 segundos
Error relativo: 0.019078 %
```
---
## Requisitos
* **Entorno MPI**
    * Open MPI o MPICH instalado en tu sistema.
* **Compilador C**
    *  mpicc para compilar el código con soporte para MPI.
* **Sistema operativo**
    * Compatible con Linux 

--- 
## Cómo Compilar y Ejecutar
1. **Compilación:**
    Utiliza el siguiente comando para compilar el programa:
    ```
    mpicc -o montecarlo_pi MonteCarlo_AproximacionPI.c -lm
    ```
    Donde `MonteCarlo_AproximacionPI.c` es el archivo fuente. Y `-lm` incluye la biblioteca matemática para funciones como `fabs` y constantes como `M_PI`
2. **Ejecución:**
    Ejecuta el programa usando `mpirun` con el número de procesos deseado:
    ```
    mpirun -np <num_procesos> ./montecarlo_pi
    Ej: mpirun -np 4 ./montecarlo_pi
    ```
3. **Parámetros Configurables:**
    * Modifica el valor de la variable `total_iteraciones` en el archivo fuente para cambiar el numero total de puntos aleatorios generados.
    * Cambia el número de procesos al ejecutar para observar el efecto en el tiempo de ejecución y la aproximación de 𝜋. Esto se hace desde el comando para ejecutar el codigo. 
