#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "domain/entites/recimendacion/recomendacion.h"
#include "domain/entites/Comidas/Comidas.h"
#include "domain\datasources\menuDatasource\menu_datasource.h"
using namespace std;

int main() {
    MenuDatasource data= MenuDatasource();
    vector<Comida> retorno = data.getMenus();
    Recomendacion cualquiercosa= Recomendacion(retorno);
    cualquiercosa.getRecomendacion("Colombiana", 2500, true);
}