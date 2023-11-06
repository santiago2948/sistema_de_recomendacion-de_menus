#include "recomendacion.h"
#include <algorithm>
typedef tuple<int, Comida*> menues;
Recomendacion::Recomendacion(vector<Comida>& MenuData){
    this->comidas=MenuData;
}

vector<tuple<int, Comida*>> Recomendacion::getRecomendacion(string tipo, int price, bool hasSoda){
    vector<tuple<int, Comida*>> reco;

    for(size_t i=0; i<this->comidas.size();i++){
            if(this->comidas[i].tipo_comida==tipo){
                tuple<int, Comida*> menues;

                get<0>(menues)=this->comidas[i].calcPeso(tipo, price, hasSoda);
                get<1>(menues)= &this->comidas[i];

                reco.push_back(menues);
            }
        }
        // Ordenar el vector de tuplas utilizando el comparador personalizado
        sort(reco.begin(), reco.end());

        for (const menues tuple : reco) {
            auto cosa =get<1>(tuple)->getDescripcion();
            cout << get<0>(tuple) << " " <<  cosa<<endl;
        }

        return reco;
}