#include "graph.h"
#include <map>


Graph:: Graph(){
    head=NULL;
    tamano=0;
}

bool Graph::isEmpty(){
    bool answer= this->tamano==0? true: false;
    return answer;
}

int Graph::length(){
    return this->tamano;
}

Vertex* Graph::getVertex(string name){
    Vertex* i = this->head;

    while(i!=NULL){
        if(i->nombre==name) return i;
        i=i->sig;
    }

    return NULL;
}

void Graph::InsertVertex(string name, Comida comida){
    if(this->getVertex(name)==NULL){
        if(this->isEmpty()){
            this->head=new Vertex(comida,name);
        }else{
            Vertex* i = this->head;

            while(i!=NULL) i=i->sig;
            this->tamano++;
        }
    }else{
        cout<<"vertex alredy exist"<<endl;
    }
}


void Graph:: InsertArista(string origin, string dest, int price){
    Vertex* orig=this->getVertex(origin);
    Vertex* destino=this->getVertex(dest);
    if(orig==NULL)throw "el vertice origen no existe";

    else if(destino==NULL) throw "el vertice destino no existe";

    else{
        Arista* nueva= new Arista(destino , price);
        
        if(orig->ari==NULL) orig->ari=nueva;
        else{
            Arista* j= orig->ari;
            while(j->sig!=NULL) j= j->sig;
            j->sig=nueva;
        }
    }
}

void Graph:: mostrarListaAdyacencia(){
    Vertex* i=this->head;
    while(i!=NULL){
        Arista* j= i->ari;

            while(j!=NULL){
               cout<<i->nombre<<"->"<<j->precio<<"->"<<j->destino<<" ---- "; 
               j=j->sig;
            }
        cout<<endl;
    }
}

void Graph::eliminarAristas(Vertex* vertice){
    Arista* i= vertice->ari;
    while(vertice->ari!=NULL){
        i=vertice->ari;
        vertice->ari=vertice->ari->sig;
        delete(i);
    }
}

void Graph::deleteVertex(string name){
    if(this->getVertex(name)!= NULL){
        if(this->head->nombre==name){
            Vertex* k=this->head;
            this->head=this->head->sig;
            this->eliminarAristas(k);
            delete(k);
        }else{
        Vertex* i= this->head;
        Vertex* j= i->sig;
        while(j!=NULL){
            if(j->nombre==name){
                this->eliminarAristas(j);
                i->sig=j->sig;
                delete(j);
                tamano--;
                break;
            j=j->sig;
                }
            }
        }
    }else{
        cout<<"vertice no existente"<<endl;
    }
}
