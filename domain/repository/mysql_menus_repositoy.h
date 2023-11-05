#include <tuple>
#include <iostream>
using namespace std; 
class MiObjeto {
public:
    MiObjeto(int valor) : valor_(valor) {}
    int getValor() const { return valor_; }
private:
    int valor_;
};

int main() {
    // Crear una tupla que almacena un entero y un objeto MiObjeto
    tuple<int, string> miTupla;

    // Asignar valores a la tupla
    get<0>(miTupla) = 42; // Asignar un entero
    get<1>(miTupla) = "monda"; // Asignar un objeto MiObjeto

    // Acceder a los valores almacenados en la tupla
    int entero = get<0>(miTupla);
    string objeto = get<1>(miTupla);

    // Imprimir los valores
    cout << "Entero: " << entero << endl;
    cout << "Valor del objeto: " << objeto << endl;

    return 0;
}
