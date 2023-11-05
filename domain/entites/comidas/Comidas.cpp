#include "Comidas.h"

Comida::Comida(string tipo_comida, string Descripcion_comida, string imagen_comida, string titulo_comida, string Restaurante_comida, string descuento_comida, int precio){
    this->tipo_comida= tipo_comida;
    this->Descripcion_comida=Descripcion_comida;
    this->imagen_comida= imagen_comida;
    this->titulo_comida=titulo_comida;
    this->Restaurante_comida=Restaurante_comida;
    this->descuento_comida=descuento_comida;
}
