#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #define CLEAR "cls"
#else 
    #define CLEAR "clear"
#endif

using namespace std;

const int FILAS = 20;
const int COLUMNAS = 40;

// Función para imprimir el tablero
void imprimirTablero(const vector<vector<bool>>& tablero) {
    system(CLEAR); 

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j]) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

// Función para obtener el número de vecinos vivos de una celda
int obtenerVecinos(int x, int y, const vector<vector<bool>>& tablero) {
    int vecinos = 0;

    // Recorrer las 8 celdas vecinas
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Saltar la celda actual

            int newX = x + i;
            int newY = y + j;

            // Verificar si las coordenadas son válidas
            if (newX >= 0 && newX < FILAS && newY >= 0 && newY < COLUMNAS && tablero[newX][newY]) {
                vecinos++;
            }
        }
    }

    return vecinos;
}

int main() {
    // Inicializar tablero con celdas muertas
    vector<vector<bool>> tablero(FILAS, vector<bool>(COLUMNAS, false));

    // Inicializar algunas celdas vivas para probar
    tablero[10][20] = true;
    tablero[11][19] = true;
    tablero[12][19] = true;
    tablero[12][20] = true;
    tablero[12][20] = true;
    tablero[13][20] = true;
    tablero[14][20] = true;
    tablero[15][20] = true;
    tablero[16][20] = true;
    tablero[17][20] = true;

    while (true) {
        imprimirTablero(tablero);

        // Crear una copia del tablero para el siguiente estado
        vector<vector<bool>> nuevoTablero = tablero;

        // Aplicar reglas del Juego de la Vida
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                int vecinosVivos = obtenerVecinos(i, j, tablero);

                if (tablero[i][j] && (vecinosVivos < 2 || vecinosVivos > 3)) {
                    // Regla de subpoblación o sobrepoblación
                    nuevoTablero[i][j] = false;
                } else if (!tablero[i][j] && vecinosVivos == 3) {
                    // Regla de reproducción
                    nuevoTablero[i][j] = true;
                }
            }
        }

        // Actualizar tablero
        tablero = nuevoTablero;

        // Esperar un momento antes del siguiente ciclo
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
