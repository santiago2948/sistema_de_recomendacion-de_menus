#include "Comidas.h"
#include <cmath>

Comida::Comida(string tipo_comida, string Descripcion_comida, string imagen_comida, string titulo_comida, string Restaurante_comida, string descuento_comida, int precio, int hasSoda) {
    this->tipo_comida = tipo_comida;
    this->Descripcion_comida = Descripcion_comida;
    this->imagen_comida = imagen_comida;
    this->titulo_comida = titulo_comida;
    this->Restaurante_comida = Restaurante_comida;
    this->descuento_comida = descuento_comida;
    this->has_soda = (hasSoda == 1) ? true : false;
}

int Comida::calcPeso(string comida, int price, bool has_soda) {
    int peso = 0;

    if (this->price <= price + 10000 && this->price >= price - 10000) {
        peso += 10;
    }
    if (this->tipo_comida == comida) {
        peso += 10;
    }
    if (this->has_soda == has_soda) {
        peso += 10;
    }
    return peso;
}

Comida::Comida(const vector<string>& row) {
    if (row.size() >= 7) {
        tipo_comida = row[0];
        Descripcion_comida = row[1];
        imagen_comida = row[2];
        titulo_comida = row[3];
        Restaurante_comida = row[4];
        descuento_comida = row[5];
        price = stoi(row[6]);
    }
}

string Comida::getDescripcion(){
    return this->Descripcion_comida;
}