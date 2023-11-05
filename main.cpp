#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "domain/entites/recimendacion/recomendacion.h"
#include "domain/entites/Comidas/Comidas.h"
#include "domain\datasources\menuDatasource\menu_datasource.h"
using namespace std;

typedef tuple<int, Comida*> menues;

bool compareTuples(const menues a, const menues b) {
    return get<0>(a) > get<0>(b);
}

int main() {
    MenuDatasource data= MenuDatasource();
    vector<Comida> retorno = data.getMenus();
    Recomendacion cualquiercosa= Recomendacion(retorno);
    cualquiercosa.getRecomendacion(tipo, price, bool):
}