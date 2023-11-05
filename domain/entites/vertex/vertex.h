#pragma once 
#include <iostream>
using namespace std;

class Arista;

class Vertex{
    string nombre;
    Vertex* sig;
    Arista* ari;
    friend class Graph;
    public:
        Vertex(string _nombre);
};