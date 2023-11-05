#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Comida{
private: 
    string tipo_comida,Descripcion_comida,imagen_comida,titulo_comida,Restaurante_comida,descuento_comida;
    int price;
    bool has_soda;
public:

    Comida(string tipo_comida, string Descripcion_comida, string imagen_comida, string titulo_comida, string Restaurante_comida, string descuento_comida, int _precio, int hasSoda);
    int calcPeso(Comida* user);
    Comida(const vector<string>& row);
    string getDescripcion();

};