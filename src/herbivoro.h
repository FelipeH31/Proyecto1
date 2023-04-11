#ifndef HERBIVORO_H
#define HERBIVORO_H

#include "animal.h"

class Herbivoro : public Animal
{
public:
    Herbivoro(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie, string habitat, string descripcion);
    ~Herbivoro();
};



#endif
