//Calculadora en c++

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
    int opcion;
    float num1, num2, resultado;
    do {
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Potencia" << endl;
        cout << "6. Raiz" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                resultado = num1 + num2;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 2:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                resultado = num1 - num2;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 3:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                resultado = num1 * num2;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 4:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                resultado = num1 / num2;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 5:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                resultado = pow(num1, num2);
                cout << "El resultado es: " << resultado << endl;
                break;
            case 6:
                cout << "Ingrese el numero: ";
                cin >> num1;
                resultado = sqrt(num1);
                cout << "El resultado es: " << resultado << endl;
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (opcion != 7);
    return 0;
}
