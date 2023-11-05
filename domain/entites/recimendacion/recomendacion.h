#pragma once;
#include <iostream>
#include <tuple>
#include "../comidas/Comidas.h"
#include "../../../datasources/menuDatasource/menu_datasource.h"
using namespace std;

class Recomendacion{
public:
    Recomendacion(MenuDatasource& MenuDatasource);
    vector<tuple<int, Comida*>> getRecomendacion(String tipo,bool hasSoda, int price);
private:
    vector<Comida> comidas;
    Comida comidaRecomenda;
    MenuDatasource& MenuDatasource;
};