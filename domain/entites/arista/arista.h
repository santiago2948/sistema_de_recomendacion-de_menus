#pragma once
#include <iostream>
using namespace std;

class Vertex;

class Arista{
    int precio;
    Arista* sig;
    Vertex* destino;

    friend class Graph;
    public:
        Arista(Vertex* _dest,int precio);
};