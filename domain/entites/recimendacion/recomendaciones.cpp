#include "recomendacion.h"
#include <algorithm>
Recomendacion::Recomendacion(MenuDatasource& MenuDatasource){
    this->comidas=MenuDatasource;
}
    
vector<tuple<int, Comida*>> Recomendacion::getRecomendacion(String tipo, int price, bool hasSoda){
    vector<tuple<int, Comida*>> reco;
    typedef tuple<int, Comida*> menues;

    for(size_t i=0; i<this->comidas.size();i++){
            if(this->comidas[i].tipo_comida=="Mexicana"){
                reco.push_back(make_tuple(this->comidas[i].calcPeso("Mexicana", 25000, unavar), &this->comidas[i]));
            }
        }
        // Ordenar el vector de tuplas utilizando el comparador personalizado
        sort(reco.begin(), reco.end(), compareTuples);

        for (const menues tuple : reco) {
            auto cosa =get<1>(tuple)->getDescripcion();
            cout << get<0>(tuple) << " " <<  cosa<<endl;
        }

        return reco;
}