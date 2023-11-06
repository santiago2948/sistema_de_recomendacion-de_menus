#pragma once
#include <iostream>
#include <tuple>
#include "../comidas/Comidas.h"
using namespace std;

class Recomendacion{

public:
    Recomendacion(vector<Comida>& comidas);
    vector<tuple<int, Comida*>> getRecomendacion(string tipo,int price,bool hasSoda);
    

private:
    vector<Comida> comidas;
};