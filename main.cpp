#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>



int main() {
    // Abre el archivo CSV
    std::ifstream csvFile("assets/menus.csv");

    // Verifica si el archivo se abrió correctamente
    if (!csvFile.is_open()) {
        std::cerr << "Error al abrir el archivo CSV." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<std::string>> data; // Almacenará los datos CSV

    // Lee y analiza el archivo CSV línea por línea
    while (std::getline(csvFile, line)) {
        std::istringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) { // Suponiendo que el delimitador es una coma
            row.push_back(cell);
        }

        data.push_back(row);
    }

    // Cierra el archivo CSV
    csvFile.close();

    // Ahora puedes acceder a los datos CSV a través del vector "data"

    // Ejemplo: Mostrar el contenido de la primera celda
    if (!data.empty() && !data[0].empty()) {
        std::cout << "Contenido de la primera celda: " << data[0][0] << std::endl;
    }

    return 0;
}
