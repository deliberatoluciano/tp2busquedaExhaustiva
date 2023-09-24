#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LONGITUD_H 65 // Longitud de la línea horizontal H

// Función para simular la verificacion de la superficie
bool palparSuperficie(int posicion) {
    // En la práctica, esta función debería implementar la lógica para verificar si la posición actual es el punto A
    // En este ejemplo, simplemente comparamos con un valor fijo (posicionA)
    srand(time(NULL));
    int posicionA = rand() % LONGITUD_H; // Simulo la posición A desconocida
    return posicion == posicionA;
}

int main() {
    int posicionB = 20;
    int incrementoDeltaH = 1; // Incremento ΔH
    int direccion = -1; // 1 para derecha, -1 para izquierda

    // Comenzamos verificando la posición B
    if (verificarSuperficie(posicionB)) {
        printf("Punto de montaje A encontrado en la posición B: %d.\n", posicionB);
        return 0;
    }
    printf("Inicio de búsqueda en la posición B: %d.\n", posicionB);

    // Iniciamos la búsqueda exhaustiva desde B
    for (int i = 1; i < LONGITUD_H; i++) {
        int posicionActual = posicionB + i * direccion;

        // Si alcanzamos un extremo, cambiamos la dirección
        if (posicionActual < 0 || posicionActual >= LONGITUD_H) {
            printf("Cambio de dirección en el extremo, posición actual: %d.\n", posicionActual);
            direccion *= -1;
            i = 0; // Reinicio el contador para explorar el otro lado
            continue;
        }

        printf("Palpando la posición: %d.\n", posicionActual);

        // verificar la posición actual
        if (verificarSuperficie(posicionActual)) {
            printf("Punto de montaje A encontrado en la posición %d.\n", posicionActual);
            break;
        }
    }

    return 0;
}