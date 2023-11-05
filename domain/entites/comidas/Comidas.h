#pragma once
#include <string>
#include <iostream>
using namespace std;

class Comida{
private: 
    string tipo_comida,Descripcion_comida,imagen_comida,titulo_comida,Restaurante_comida,descuento_comida;
    int price;
public:

    Comida(string tipo_comida, string Descripcion_comida, string imagen_comida, string titulo_comida, string Restaurante_comida, string descuento_comida, int _precio);
    Comida(Vector<string> row);
    int calcPeso(Comida* user, Comida* iterable);

};