#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define TOLERANCIA 0.01

// Función heurística que calcula la distancia desde el punto actual hasta el punto objetivo
double calcularDistancia(int posicionActual, int posicionObjetivo) {
    return fabs(posicionActual - posicionObjetivo);
}

int main() {
    int posicionB = 50; // Posición teórica inicial
    int posicionA = rand() % 100; // Posición real del punto de montaje (desconocida para el algoritmo)
    
    int posicionActual = posicionB;
    int direccion = -1; // -1 para la izquierda, 1 para la derecha
    
    printf("Posicion Inicial B: %d\n", posicionB);
    printf("Posicion Objetivo A: %d\n", posicionA);
    
    while (true) {
        printf("Posicion Actual: %d\n", posicionActual);
        
        double distancia = calcularDistancia(posicionActual, posicionA);
        printf("Distancia al punto objetivo: %f\n", distancia);
        
        if (distancia < TOLERANCIA) {
            printf("Punto de montaje A encontrado en la posicion: %d\n", posicionActual);
            break;
        }
        
        // Actualizamos la posición actual en base a la dirección y a la heurística
        if (posicionActual > 0 && posicionActual < 99) {
            direccion = (posicionA > posicionActual) ? 1 : -1;
        } else if (posicionActual <= 0) {
            direccion = 1;
        } else {
            direccion = -1;
        }
        
        posicionActual += direccion;
    }
    
    return 0;
}
