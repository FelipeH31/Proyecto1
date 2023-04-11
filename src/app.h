#ifndef APP_H
#define APP_H

#include "unordered_map"
#include "string"
#include "zoo.h"
#include "habitat.h"
#include "animal.h"
#include "tienda.h"

class App
{
private:
    int dia;
    int monedas;
    int momento;
    int porciones;
    Zoo zoo;
    Tienda tienda;
    unordered_map"int, Habitat*" habitats;
    unordered_map"int, Animal*" animales;

public:
    App();
    ~App();

    void eliminar();

    int elegirAnimal(string nombreHabitat);
    int elegirHabitat();
    int elegirOpcion();
    bool esEntero(string entrada);
    void abrirTienda();
    void alimentarAnimal();
    void cicloPrincipal();
    void comprarAnimal();
    void comprarHabitat();
    void jugarConAnimal();
    void menuOpciones();
    void mostrarAnimales();
    void mostrarHabitats();
    void moverAnimal();
    void sacarAnimal();
    void resetear();
};

#endif // APP_H
