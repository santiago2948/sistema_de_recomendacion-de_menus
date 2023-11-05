#include "menu_datasource.h"
MenuDatasource::MenuDatasource(){
}

vector<Comida> MenuDatasource:: getMenusint(const vector<vector<string>>& data){
    vector<Comida> comida;

        for (const auto& row : data){
            Comida comidas(row);
            comida.push_back(comidas);
        }
        return comida;
}

vector<Comida> MenuDatasource::getMenus(){
    vector<vector<string>> data;
     ifstream csvFile("assets/menus.csv");

     if (!csvFile.is_open()) {
        cerr << "Error al abrir el archivo CSV." << endl;
    }

        string line; // Almacenará los datos CSV
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

    vector<Comida> comida=this->getMenusint(data);
    return comida;
}

void MenuDatasource::prcesar(){
    vector<Comida> data = this->getMenus();
    for(size_t i=0; i< data.size(); i++){
        cout<<data[i].getDescripcion()<<endl;
    }
}