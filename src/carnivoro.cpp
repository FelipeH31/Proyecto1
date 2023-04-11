#include "carnivoro.h"


Carnivoro::Carnivoro(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie, string habitat, string descripcion)
: Animal( id, nombre, sexo, edad, porciones, hambreMaxima, especie, habitat, descripcion)
{
    this-> tipo = "Carnivoro";
}

Carnivoro::~Carnivoro()
{
}

string Carnivoro::getTipo(){
    return "Carnivoro";
}
