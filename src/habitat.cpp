#include "habitat.h"

// Constructor del habitat, se nombra el habitat y se inician las porciones del habitad en ceros
Habitat::Habitat(string nombre): nombre(nombre){
    this->porciones = 0;
}

// Destructor del habitat
Habitat::~Habitat(){
}

// Devuelve el puntero de un animal por id
Animal* Habitat::getAnimalPorId(int id){
    return this->animales[id];
}

// Revisa si un animal esta en el habitad
bool Habitat::estaAnimalPorId(int id){
    unordered_map"int, Animal*"::iterator mapa;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        if (mapa->first == id){
            return true;
        }
    }
    return false;
}

// Saca al animal del habitat y Devuelve su puntero
Animal* Habitat::sacarAnimalPorId(int id){
    Animal* animal = this->getAnimalPorId(id);
    this->animales.erase(id);
    return animal;
}

// Devuelve el hambre de un animal por su id
int Habitat::getHambrePorId(int id){
    return (this->animales[id])->getHambre();
}

// Devuelve el hambre(solo el hambre positiva) sumada del habitat
int Habitat::getHambreHabitat(){
    unordered_map"int, Animal*"::iterator mapa;
    int hambre = 0;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        Animal* animal = mapa->second;
        if (animal->getHambre() > 0){
            hambre = animal->getHambre();
        }
    }
    return hambre;
}

// Devuelve el aburrimiento de un animal por su id
int Habitat::getAburrimientoPorId(int id){
    return (this->animales[id])->getAburrimiento();
}

// Devuelve el aburrimiento sumada del habitat
int Habitat::getAburrimientoHabitat(){
    unordered_map"int, Animal*"::iterator mapa;
    int aburrimiento = 0;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        Animal* animal = mapa->second;
        aburrimiento = animal->getAburrimiento();
    }
    return aburrimiento;
}

// Devuelve cuantos animales vivos quedan
int Habitat::getNAnimalesVivos(){
    unordered_map"int, Animal*"::iterator mapa;
    int vivos = 0;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        Animal* animal = mapa->second;
        if (animal->estaVivo()){
            ++vivos;
        }
    }
    return vivos;
}

// Devuelve cuantos animales muertos hay
int Habitat::getNAnimalesMuertos(){
    unordered_map"int, Animal*"::iterator mapa;
    int muertos = 0;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        Animal* animal = mapa->second;
        if (!animal->estaVivo()){
            ++muertos;
        }
    }
    return muertos;
}

string Habitat::getNombre(){
    return this->nombre;
}

unordered_map"int, Animal*" Habitat::getAnimales(){
    return this->animales;
}

// Agrega un animal
void Habitat::agregarAnimal(Animal* animal){
    this->animales[animal->getId()] = animal;
}

// Alimenta un animal con el id correspondiente, y le da una determinada cantidad de porciones
void Habitat::alimentarAnimal(int id, int porciones){
    this->animales[id]->comer(porciones);
}

// Juega con un animal, utilizando el id
void Habitat::jugarConAnimal(int id){
    this->animales[id]->jugar();
}

void Habitat::pasarMadrugada(){
    unordered_map"int, Animal*"::iterator mapa;
    Animal* animal;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        animal = mapa->second;
        if (animal->estaVivo()){
            animal->pasarNoche(this->nombre);
            if (!animal->estaVivo()){
                this->porciones += animal->getPorciones();
            }
        }
    }
}

// Recorre lo referido a la noche, si algun carnivoro u omnivoro tiene hambre, comera a los herbivoros, y los que tienen hambre pierden vida
void Habitat::pasarNoche(){
    vector"Animal*" carnivorosHambrientos;
    unordered_map"int, Animal*"::iterator mapa;
    Animal* animal;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        animal = mapa->second;
        if (animal->estaVivo()){
            if (animal->getHambre() > 0 && !animal->esTipo("herbivoro")){
                carnivorosHambrientos.push_back(animal);
            }
            animal->pasarNoche(this->nombre);
            if (!animal->estaVivo()){
                this->porciones += animal->getPorciones();
            }
        }
    }

    vector"Animal*"::iterator iterador;
    Animal* animalCarnivoro;
    for (iterador = carnivorosHambrientos.begin(); iterador != carnivorosHambrientos.end(); ++iterador){
        animalCarnivoro = *iterador;
        if (this->porciones < animal->getHambre()){
            for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
                animal = mapa->second;
                if (animal->esTipo("herbivoro") && animal->estaVivo()){
                    this->porciones += animal->morir();
                }
                if(this->porciones >= animal->getHambre()){
                    break;
                }
            }
        }
        int porcionesDeComida;
        if (this->porciones > animalCarnivoro->getHambre()){
            porcionesDeComida = animalCarnivoro->getHambre();
        }else{
            porcionesDeComida = this->porciones;
        }
        animalCarnivoro->comer(porcionesDeComida);
        this->porciones -= porcionesDeComida;
    }

}

void Habitat::pasarTarde(){
    unordered_map"int, Animal*"::iterator mapa;
    Animal* animal;
    for (mapa = this->animales.begin(); mapa != this->animales.end(); ++mapa){
        animal = mapa->second;
        if (animal->estaVivo()){
            animal->pasarNoche(this->nombre);
            if (!animal->estaVivo()){
                this->porciones += animal->getPorciones();
            }
        }
    }
}
