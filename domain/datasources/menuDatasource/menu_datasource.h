#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector>
#include "../../entites/comidas/Comidas.h"
using namespace std;

class MenuDatasource{
    public:
        vector<Comida> getMenusint(const vector<vector<string>>& data);
        vector<Comida> getMenus();
        MenuDatasource();
        void prcesar();
    private:
};