#ifndef OMNIVORO_H
#define OMNIVORO_H

#include "animal.h"

class Omnivoro : public Animal
{
public:
    Omnivoro(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie, string habitat, string descripcion);
    ~Omnivoro();
};



#endif
