#include "omnivoro.h"


Omnivoro::Omnivoro(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie, string habitat, string descripcion)
: Animal( id, nombre, sexo, edad, porciones, hambreMaxima, especie, habitat, descripcion)
{
    this tipo = "Omnivoro";
}

Omnivoro::~Omnivoro()
{
}

string Omnivoro::getTipo(){
    return "Omnivoro";
}
