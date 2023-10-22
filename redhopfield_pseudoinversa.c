#include <stdio.h>
#include <stdlib.h>

#define N 100  // Número de neuronas (10x10)

int weights[N][N];  // Matriz de pesos para la red de Hopfield
int pattern[N];     // Patrón de entrada

// Se inicializan todos los pesos a 0
void initialize_weights() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            weights[i][j] = 0;
        }
    }
}

// Se entrena la red de Hopfield usando la técnica de pseudoinversa
void train_with_pseudoinverse(int patterns[][N], int num_patterns) {
    for (int p = 0; p < num_patterns; p++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // aca lo que se evita es actualizar el peso de una neurona consigo misma
                if (i != j) {
                    weights[i][j] += patterns[p][i] * patterns[p][j];
                }
            }
        }
    }
}

// Función de activación: si el valor es positivo o 0 retorna 1, sino retorna -1
int activate(int value) {
    if (value >= 0) return 1;
    else return -1;
}

// Se reconoce un patrón de entrada usando la red de Hopfield
void recognize_pattern(int input[N], int output[N]) {
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += weights[i][j] * input[j];
        }
        output[i] = activate(sum);
    }
}

// Muestra un patrón en formato 10x10
void display_pattern(int pat[N]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d ", pat[i * 10 + j]);
        }
        printf("\n");
    }
}

int main() {
    // Patrón de entrenamiento simulado para el aro "C"
    // 1 representa parte del aro
    int training_patterns[1][N] = { /*... (se mantiene igual) ... */ };

    // Inicializacion de los pesos y entrenamiento de la red
    initialize_weights();
    train_with_pseudoinverse(training_patterns, 1);

    // Moustra el patrón de entrenamiento
    printf("Patrón de entrenamiento:\n");
    display_pattern(training_patterns[0]);

    // Simula una imagen de entrada con algo de ruido
    int input_pattern[N] = { /*... (se mantiene igual) ... */ };

    // Usa la red para reconcoer el patrón
    int result[N];
    recognize_pattern(input_pattern, result);

    // Muestra el resultado del reconocimiento
    printf("\nResultado del reconocimiento :\n");
    display_pattern(result);

    return 0;
}