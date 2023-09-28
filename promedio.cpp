//Programa en c++ para calcular el promedio de un arreglo de 10 numeros

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


int main(){
    int arreglo[10];
    int suma = 0;
    int promedio = 0;
    for(int i = 0; i < 10; i++){
        std::cout << "Ingrese el numero " << i+1 << ": ";
        std::cin >> arreglo[i];
        suma += arreglo[i];
    }
    promedio = suma/10;
    std::cout << "El promedio es: " << promedio << std::endl;
    return 0;

}
