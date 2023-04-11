#ifndef ZOO_H
#define ZOO_H

#include "unordered_map"
#include "string"
#include "animal.h"
#include "habitat.h"

using namespace std;

class Zoo
{
private:
    unordered_map"string, Habitat*" habitats;
public:
    Zoo();
    ~Zoo();

    int alimentarAnimal(string nombreHabitat, int id, int porciones);
    int getAnimalesVivos(string nombreHabitat);
    int getAnimalesMuertos(string nombreHabitat);
    int getGanancias(int gananciasAnimal);
    bool estaAnimalEnHabitat(string nombreHabitat, int id);
    bool estaHabitat(string nombreHabitat);
    void construirHabitat(Habitat* habitat);
    void cambiarAnimal(string nombreHabitatInicial, string nombreHabitatFinal, int id);
    void guardarAnimal(string nombreHabitat, Animal* animal);
    void jugarConAnimal(string nombreHabitat, int id);
    void mostrarAnimales(string nombreHabitat);
    void mostrarHabitats();
    void pasarMadrugada();
    void pasarNoche();
    void pasarTarde();
    void sacarAnimal(string nombreHabitat, int id);
};

#endif // ZOO_H
