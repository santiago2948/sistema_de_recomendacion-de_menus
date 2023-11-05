#pragma once
#include "../arista/arista.h"
#include "../vertex/vertex.h"

class Graph{
    Vertex* head;
    int tamano;

    public:
        Graph();
        bool isEmpty(); // retorna verdadero si le grafo se encuentra vacio
        int length(); // retorna el tamaño (numero de aristas del grafo)
        Vertex* getVertex(string name);
        void InsertVertex(string name);
        void InsertArista(string orig, string dest, int price);
        void mostrarListaAdyacencia();
        void deleteVertex(string name);
        void eliminarArista(string orig, string dest);
        void eliminarTodo();
        void eliminarAristas(Vertex* vertice); //elimina las arisatas de un vertice especifico
        void Dijkstra(string origen); //despliega las rutas mas cortas entre el origen y los demas vertices
};