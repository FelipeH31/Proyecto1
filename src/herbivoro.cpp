#include "herbivoro.h"


Herbivoro::Herbivoro(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie,  string habitat, string descripcion)
: Animal( id, nombre, sexo, edad, porciones, hambreMaxima, especie, habitat, descripcion)
{
    this tipo = "Herbivoro";
}

Herbivoro::~Herbivoro()
{
}

string Herbivoro::getTipo(){
    return "Herbivoro";
}
