#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "domain/entites/Comidas/Comidas.h"
using namespace std;



vector <Comida> procesar_Data(const vector<vector<string>>& data){
        vector<Comida> comida;
        for (const auto& row : data){
            Comida comidas(row);
            comida.push_back(comidas);
        }
        return comida;
    }


int main() {
    // Abre el archivo CSV
    ifstream csvFile("assets/menus.csv");

    // Verifica si el archivo se abrió correctamente
    if (!csvFile.is_open()) {
        cerr << "Error al abrir el archivo CSV." << endl;
        return 1;
    }

    string line;
    vector<vector<string>> data; // Almacenará los datos CSV

    // Lee y analiza el archivo CSV línea por línea
    while (getline(csvFile, line)) {
        istringstream ss(line);
        vector<string> row;
        string cell;

        while (getline(ss, cell, ',')) { // Suponiendo que el delimitador es una coma
            row.push_back(cell);
        }

        data.push_back(row);
    }

    // Cierra el archivo CSV
    csvFile.close();
    //Se procesa
    
    // Ahora puedes acceder a los datos CSV a través del vector "data"
    // Ejemplo: Mostrar el contenido de la primera celda
    if (!data.empty() && !data[0].empty()) {
        vector<Comida> retorno=procesar_Data(data);
        for(size_t i =0; i< retorno.size();i++){
            cout<< retorno[i].getDescripcion()<<endl;
        }
    }

    
    return 0;


}