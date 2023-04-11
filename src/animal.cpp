#include "animal.h"

/* Constructor de clase "Animal", en el cual se usan de parametro el id(unico para cada animal), nombre(unico para cada animal), sexo, edad,
porciones(cuantas porciones de carne da al morir), hambreMaxima(valor maximo del hambre), especie(especie del anima),
habitat(habitat natural del animal), descripcion(peque�a descripcion del animal)*/
Animal::Animal(int id, string nombre, string sexo, int edad, int porciones, int hambreMaxima, string especie, string habitat, string descripcion):
    id(id), nombre(nombre), edad(edad), porciones(porciones), hambreMaxima(hambreMaxima), especie(especie), habitat(habitat), descripcion(descripcion) {
    this->hambre = 0;
    this->salud = 100;
    this->aburrimiento = 0;
    this->cansancio = 0;
    this->vivo = true;
}

// Destructor del "animal"
Animal::~Animal(){
}

// Devuelve la cantidad de aburrimiento (0 = bien)
int Animal::getAburrimiento(){
    return this->aburrimiento;
}

// Devuelve el cansancio del animal
int Animal::getCansancio(){
    return this->cansancio;
}

// Devuelve la edad del animal
int Animal::getEdad(){
    return this->edad / 364;
}

// Devuelve el id del animal
int Animal::getId(){
    return this->id;
}

// Devuelve la cantidad (en porciones) del hambre del animal
int Animal::getHambre(){
    return this->hambre;
}

// Devuelve la maxima catidad de hambre antes de perder salud
int Animal::getHambreMaxima(){
    return this->hambreMaxima;
}

// Devuelve la cantidad de porciones de comida que da al morir
int Animal::getPorciones(){
    return this->porciones;
}

// Devuelve la salud(de 0 a 100)
int Animal::getSalud(){
    return this->salud;
}

// mata al animal, poniendo la salud en cero y vivo en false, ademas de devolver las porciones de comida que este suelta.
int Animal::morir(){
    this->vivo = false;
    this->salud = 0;
    this->aburrimiento = 0;
    this->hambre = 0;
    return this->getPorciones();
}

// Devuelve si esta vivo o no
bool Animal::estaVivo(){
    return this->vivo;
}

// Devuelve el nombre del animal
string Animal::getNombre(){
    return this->nombre;
}

// Devuelve la descripcion
string Animal::getDescripcion(){
    return this->descripcion;
}

// Devuelve la especie a la que pertenece
string Animal::getEspecie(){
    return this->especie;
}

// Devuelve el habitat en el que debe vivir
string Animal::getHabitat(){
    return this->habitat;
}

// Devuelve el tipo de alimientacion
string Animal::getTipo(){
    return "animal";
}

// Devuelve el tipo de alimientacion
bool Animal::esTipo(string tipo){
    return this->tipo.compare(tipo) == 0;
}

// Devuelve el sexo del animal
string Animal::getSexo(){
    return this->sexo;
}
// realiza los calculos de las horas de la mañana, cambiando salud, hambre, cansancio y aburrimiento
void Animal::pasarMadrugada(string habitatResidencia){
    this->cansancio += 5;
    this->aburrimiento += rand() % 10 + 15;
    this->hambre += this->hambreMaxima / 4;
}

// realiza los calculos de cuando duermen, cambiando salud, hambre, cansancio y aburrimiento
void Animal::pasarNoche(string habitatResidencia){
    if (this->habitat != habitatResidencia){
        this->salud -= 20;
    }

    if (this->hambre > 0 ){
        this->salud -= this->hambre * 2;
    } else {
        this->salud += 20;
        if (this->salud > 100){
            this->salud = 100;
        }
    }

    this->cansancio = 0;
    this->aburrimiento = rand() % 10 + 15;
    this->hambre += 2 * (this->hambreMaxima / 4);

    if (this->salud <= 0){
        this->morir();
    }
}

// realiza los calculos de las horas de la tarde, cambiando salud, hambre, cansancio y aburrimiento
void Animal::pasarTarde(string habitatResidencia){
    this->cansancio += 5;
    this->aburrimiento += rand() % 10 + 15;
    this->hambre += this->hambreMaxima / 4;
    ++this->edad;
}

// Alimenta al animal con una cantidad de porciones
void Animal::comer(int porcionesComida){
    this->hambre -= porcionesComida;
    if (this->hambre < -(this->hambreMaxima / 3)){
        this->hambre = -this->hambreMaxima / 3;
    }
}

// Jugar con el animal para reducir aburrimiento, pero aumenta cansancio y habre
void Animal::jugar(){
    int cambio = rand() % 20 + 10 - this->cansancio;
    cout << cambio << endl;
    this->aburrimiento -= cambio;
    this->cansancio += cambio / 4;
    this->hambre += cambio / 10 - 1;
    if (this->aburrimiento < 0){
        this->aburrimiento = 0;
    }
}
