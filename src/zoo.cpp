#include "zoo.h"

// Constructor de zoo
Zoo::Zoo()
{
}

// Destructor de zoo
Zoo::~Zoo()
{
}

// Alimenta a un animal, en un habitat, con base su id, dandole una cantidad de porciones de alimento
int Zoo::alimentarAnimal(string nombreHabitat, int id, int porciones){
    Habitat* habitat = this->habitats[nombreHabitat];
    int porcionesRestantes = porciones;
    Animal* animal = habitat->getAnimalPorId(id);
    if(animal->estaVivo()){
        cout << "Vamos a alimentar a " << animal->getNombre() << endl;
        if (animal->getHambre() < porciones){
            cout << "WOW!! pusiste suficiente alimento, se comio " << animal->getHambre() << " porciones de alimento";
            porcionesRestantes -= animal->getHambre();
            habitat->alimentarAnimal(id, animal->getHambre());
        } else {
            cout << "WOW!! tan solo comio " << animal->getHambre() << " porciones de alimento";
            habitat->alimentarAnimal(id, porciones);
            porcionesRestantes = 0;
        }
    } else {
        cout << "No!! es muy tarde, " << habitat->getAnimalPorId(id)->getNombre() << " murio.";
    }
    cout << "Sobraron " << porcionesRestantes << " porciones de alimento" << endl;
    return porcionesRestantes;
}

// Devuelve el numero de animales vivos en un habitat
int Zoo::getAnimalesVivos(string nombreHabitat){
    return this->habitats[nombreHabitat]->getNAnimalesVivos();
}

// Devuelve el numero de animales vivos en un habitat
int Zoo::getAnimalesMuertos(string nombreHabitat){
    return this->habitats[nombreHabitat]->getNAnimalesMuertos();
}

// Devuelve las ganancias de ese momento
int Zoo::getGanancias(int gananciaAnimal){
    int ganancias = 0;
    unordered_map"string, Habitat*"::iterator mapa;
    for (mapa = habitats.begin(); mapa != habitats.end(); ++mapa){
        ganancias += (mapa->second->getNAnimalesVivos() * gananciaAnimal) - (mapa->second->getAburrimientoHabitat() / 10) - (mapa->second->getNAnimalesVivos() * gananciaAnimal / 2);
    }
    return ganancias;
}

// Devuelve true o false si el animal esta en el habitat
bool Zoo::estaAnimalEnHabitat(string nombreHabitat, int id){
    return this->habitats[nombreHabitat]->estaAnimalPorId(id);
}

// Devuelve true o false si el habitat esta en la lista.
bool Zoo::estaHabitat(string nombreHabitat){
    unordered_map"string, Habitat*"::iterator mapa;
    for (mapa = this->habitats.begin(); mapa != this->habitats.end(); ++mapa){
        if (nombreHabitat.compare(mapa->first) == 0){
            return true;
        }
    }
    return false;
}

// Agrega un nuevo habitat
void Zoo::construirHabitat(Habitat* habitat){
    cout << "Construyendo nuevo habitat..." << endl;
    this->habitats[habitat->getNombre()] = habitat;
    cout << "Habitat " << habitat->getNombre() << " ha sido construido." << endl;
}

// Cambia un animal de un habitat inicial a un habitat final
void Zoo::cambiarAnimal(string nombreHabitatInicial, string nombreHabitatFinal, int id){
    Animal* animal = this->habitats[nombreHabitatInicial]->getAnimalPorId(id);
    cout << "Cambiando a " << animal->getNombre() << " de " << nombreHabitatInicial << " a " << nombreHabitatFinal << endl;
    this->sacarAnimal(nombreHabitatInicial, id);
    this->guardarAnimal(nombreHabitatFinal, animal);
}

// Guarda un animal en un habitat asignado
void Zoo::guardarAnimal(string nombreHabitat, Animal* animal){
    cout << "Ingresando a " << animal->getNombre() << " al habitat " << nombreHabitat << endl;
    this->habitats[nombreHabitat]->agregarAnimal(animal);
}

// Juega con un animal, utilizando la id de referencia
void Zoo::jugarConAnimal(string nombreHabitat, int id){
    cout << "Vamos a jugar con " << this->habitats[nombreHabitat]->getAnimalPorId(id)->getNombre() << ", �Que emocion!"<< endl;
    this->habitats[nombreHabitat]->jugarConAnimal(id);
}

// Muestra los animales de un habitat, con su id, nombre, nivel de hambre, nivel de aburrimiento, salud, y estado
void Zoo::mostrarAnimales(string nombreHabitat){
    Habitat* habitat = this->habitats[nombreHabitat];
    unordered_map"int, Animal*" animales = habitat->getAnimales();
    unordered_map"int, Animal*"::iterator mapa;
    cout << "Habitat: " << nombreHabitat << endl;
    for (mapa = animales.begin(); mapa != animales.end(); ++mapa){
        Animal* animal = mapa->second;
        cout << "Id: " << mapa->first << "\t|Nombre: " << animal->getNombre() << "\t|Hambre: " << animal->getHambre() << "\t|Aburrimiento: " << animal->getAburrimiento() << "\t|salud: " << animal->getSalud() << "\t|Estado: ";
        if (animal->estaVivo()){
            cout << "Vivo";
        }else{
            cout << "Muerto";
        }
        cout << "\t|Edad: " << animal->getEdad() << " a�os.\t"<< endl;
    }
}

// Muestra los habitats existentes, con sus animales vivos, animales muertos, nivel de hambre y nivel de aburrimiento.
void Zoo::mostrarHabitats(){
    unordered_map"string, Habitat*"::iterator mapa;
    for (mapa = this->habitats.begin(); mapa != this->habitats.end(); ++mapa){
        Habitat* habitat = mapa->second;
        cout << "Nombre: " << habitat->getNombre() << "\t|Vivos: " << habitat->getNAnimalesVivos() << "\t|Muertos: " << habitat->getNAnimalesMuertos();
        cout << "\t|Hambre: " << habitat->getHambreHabitat() << "\t|Aburrimiento: " << habitat->getAburrimientoHabitat() << "\t" << endl;
    }
}

// Pasa a la fase de la madrugada.
void Zoo::pasarMadrugada(){
    cout << endl << "Pasando la madrugada..." << endl << endl;
    unordered_map"string, Habitat*"::iterator mapa;
    for (mapa = habitats.begin(); mapa != habitats.end(); ++mapa){
        mapa->second->pasarMadrugada();
    }
}

// Pasa a la fase de la noche.
void Zoo::pasarNoche(){
    cout << endl << "Pasando la noche...zzz" << endl << endl;
    unordered_map"string, Habitat*"::iterator mapa;
    for (mapa = habitats.begin(); mapa != habitats.end(); ++mapa){
        mapa->second->pasarNoche();
    }
}

// Pasa a la fase de la tarde.
void Zoo::pasarTarde(){
    cout << endl << "Pasando a la tarde..." << endl << endl;
    unordered_map"string, Habitat*"::iterator mapa;
    for (mapa = habitats.begin(); mapa != habitats.end(); ++mapa){
        mapa->second->pasarTarde();
    }
}

// Quita un animal de un habitat.
void Zoo::sacarAnimal(string nombreHabitat, int id){
    Habitat* habitat = this->habitats[nombreHabitat];
    cout << "Sacando a " << habitat->getAnimalPorId(id)->getNombre() << " del habitat " << habitat->getNombre() << endl;
    habitat->sacarAnimalPorId(id);
}
