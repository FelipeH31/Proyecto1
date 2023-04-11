#ifndef HABITAT_H
#define HABITAT_H

#include"iostream"
#include"string"
#include"unordered_map"
#include "vector"
#include"animal.h"


class Habitat
{
private:
    int porciones;
    string nombre;
    unordered_map"int, Animal*" animales;
public:
    Habitat(string nombre);
    ~Habitat();

    Animal* getAnimalPorId(int id);
    Animal* sacarAnimalPorId(int id);
    int getHambrePorId(int id);
    int getHambreHabitat();
    int getAburrimientoPorId(int id);
    int getAburrimientoHabitat();
    int getNAnimalesVivos();
    int getNAnimalesMuertos();
    bool estaAnimalPorId(int id);
    unordered_map"int, Animal*" getAnimales();
    string getNombre();

    void agregarAnimal(Animal* animal);
    void alimentarAnimal(int id, int porciones);
    void jugarConAnimal(int id);
    void pasarMadrugada();
    void pasarNoche();
    void pasarTarde();

};

#endif // HABITAT_H
