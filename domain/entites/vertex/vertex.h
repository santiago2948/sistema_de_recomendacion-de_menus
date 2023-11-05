#pragma once 
#include <iostream>
using namespace std;

class Arista;

class Comida{

};
class Vertex{
    Comida comida;
    string nombre;
    Vertex* sig;
    Arista* ari;
    friend class Graph;
    public:
        Vertex(Comida _comida, string _nombre);
};