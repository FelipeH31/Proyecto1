#ifndef CARNIVORO_H
#define CARNIVORO_H

#include "animal.h"

class Carnivoro : public Animal
{
public:
    Carnivoro(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie, string habitat, string descripcion);
    ~Carnivoro();
};



#endif
