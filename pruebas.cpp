#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono> // Librería para medir tiempos

// Prototipos de las funciones definidas en MCS.cpp
int MCS_MEM(std::vector<int>& E, int i, int n, std::vector<int>& M);
int MCS(std::vector<int>& E);

// Prototipos de las funciones definidas en MCS_BU.cpp
void reconstruccion(std::vector<int>& M, std::vector<int>& E);
int MCS_BU(std::vector<int>& E);

void procesarEntradas(const std::string& archivo, const std::string& salida) {
    std::ifstream entrada(archivo);
    if (!entrada.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return;
    }

    std::ofstream salida_archivo(salida);
    if (!salida_archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(entrada, linea)) {
        // Verificar si la línea no está vacía
        if (!linea.empty()) {
            std::vector<int> entrada_vector;
            std::stringstream ss(linea);
            std::string elemento;
            while (std::getline(ss, elemento, ',')) {
                entrada_vector.push_back(std::stoi(elemento));
            }
            // for (int elem : entrada_vector) {
            // std::cout << elem << " ";
            // }
            // std::cout << std::endl;
            // Medir tiempo de ejecución de MCS_MEM
            auto start = std::chrono::steady_clock::now();
            int result_MCS_MEM = MCS(entrada_vector);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            double tiempo_MCS = elapsed_seconds.count();

            // Medir tiempo de ejecución de MCS_BU
            start = std::chrono::steady_clock::now();
            int result_MCS_BU = MCS_BU(entrada_vector);
            end = std::chrono::steady_clock::now();
            elapsed_seconds = end - start;
            double tiempo_MCS_BU = elapsed_seconds.count();

            // Escribir los tiempos formateados en el archivo de salida
            salida_archivo << entrada_vector.size()<<","<<tiempo_MCS << ", " << tiempo_MCS_BU << std::endl;
        }
    }

    entrada.close();
    salida_archivo.close();
}


int main() {
    procesarEntradas("entradas.txt","salida.txt");
    return 0;
}
