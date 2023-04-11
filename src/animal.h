#ifndef ANIMAL_H
#define ANIMAL_H

#include "iostream"
#include "string"

using namespace std;

class Animal {
private:
    int aburrimiento;
    int cansancio;
    int edad;
    int id;
    int hambre;
    int porciones;
    int hambreMaxima;
    int salud;
    bool vivo;
    string nombre;
    string descripcion;
    string especie;
    string habitat;
    string sexo;
    protected:
    string tipo;
public:
    Animal(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie, string habitat, string descripcion);
    ~Animal();

    int getAburrimiento();
    int getCansancio();
    int getEdad();
    int getId();
    int getHambre();
    int getHambreMaxima();
    int getPorciones();
    int getSalud();
    int morir();
    bool estaVivo();
    bool esTipo(string tipo);
    string getNombre();
    string getDescripcion();
    string getEspecie();
    string getHabitat();
    string getTipo();
    string getSexo();

    void pasarMadrugada(string habitatResidencia);
    void pasarNoche(string habitatResidencia);
    void pasarTarde(string habitatResidencia);
    void comer(int porcionesComida);
    void jugar();
};

#endif
