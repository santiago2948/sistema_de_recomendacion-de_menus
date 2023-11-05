#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "domain/entites/Comidas/Comidas.h"
#include "domain\datasources\menuDatasource\menu_datasource.h"
using namespace std;

int main() {
    MenuDatasource data= MenuDatasource();
    data.prcesar();

    return 0;
}