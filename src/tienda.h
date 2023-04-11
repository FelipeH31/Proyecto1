#ifndef TIENDA_H
#define TIENDA_H

#include "unordered_map"
#include "vector"
#include "animal.h"
#include "habitat.h"

class Tienda
{
private:
    int animalesEnVenta;
    int animalesVendidos;
    unordered_map"int, unordered_map"string, string"" animales;
    vector"string" habitats;
public:
    Tienda();
    ~Tienda();
    int comprarConcentrado(int monedas);
    int elegirNumero();
    bool esEntero(string entrada);
    Animal* comprarAnimal();
    Habitat* comprarHabitat();
};

#endif // TIENDA_H
