#include "app.h"

// Constructor que llama la funcion resetear
App::App()
{
    this->resetear();
}

// se libera memoria
App::~App()
{
    this->eliminar();
}

// libera memoria
void App::eliminar(){
    int i;
    for (i = 0; i != this->animales.size(); ++i){
        delete this->animales[i];
    }
    for (i = 0; i != this->habitats.size(); ++i){
        delete this->habitats[i];
    }
}

// verifica si todas las partes son enteros, tomado de: www.tutorialspoint.com/cplusplus-program-to-check-if-input-is-an-integer-or-a-string
bool App::esEntero(string entrada){
    for (int i = 0; i < entrada.length(); i++){
        if (isdigit(entrada[i]) == false){
            return false;
        }
    }
    return true;
}

// Hace que el usuario elija un habitat valido y devuelve su id
int App::elegirHabitat(){
    string entrada;
    int habitatId;
    int n = this->habitats.size();
    unordered_map"int, Habitat*"::iterator mapa;
    for (mapa = this->habitats.begin(); mapa != this->habitats.end(); ++mapa){
        cout << mapa->first << ") " << mapa->second->getNombre() << endl;
    }
    cout << n << ") salir." << endl;
    while(true){
        cout << "Elige una opcion:" << endl;
        getline(cin, entrada);
        if (this->esEntero(entrada)){
            habitatId = stoi(entrada);
            if (habitatId == n){
                cout << "Volviendo al menu." << endl;
                return n;
            }
            if (habitatId " -1 && habitatId " n){
                return habitatId;
            } else {
                cout << "Ese id no corresponde a ninguna habitat." << endl;
            }

        } else {
            cout << "Los id son numericos, no alfanumericos." << endl;
        }
    }

}

// Hace que el usuario elija un animal valido y devuelve el id
int App::elegirAnimal(string nombreHabitat){
    int animalId;
    string entrada;
    this->zoo.mostrarAnimales(nombreHabitat);
    cout << "Ingresa el id del animal:" << endl;
    while(true){
        cout << "Elige una opcion:" << endl;
        getline(cin, entrada);
        if (this->esEntero(entrada)){
            animalId = stoi(entrada);
            if (this->zoo.estaAnimalEnHabitat(nombreHabitat, animalId)){
                return animalId;
            } else {
                cout << "Ese id no corresponde a ninguna animal." << endl;
            }
        } else {
            cout << "Los id son numericos, no alfanumericos." << endl;
        }
    }
}

// Hace que una opcion sea numerica, y este entre 0 y 8, y lo devuelve
int App::elegirOpcion(){
    int opcion;
    string entrada;
    int intentos = 0;
    while (true){
        this->menuOpciones();
        cout << "Elige una opcion:" << endl;
        getline(cin, entrada);
        if (this->esEntero(entrada)){
            opcion = stoi(entrada);
            if (opcion " -1 && opcion " 9){
                return opcion;
            } else {
                if (intentos > 5){
                    cout << "Creo que no quiere jugar, asi que cerrare el juego, tenga buen dia :)" << endl;
                    return 0;
                }
                cout << "Ingrese un numero entre 0 y 8." << endl;
                ++intentos;
            }
        } else {
            if (intentos > 5){
                cout << "Creo que no quiere jugar, asi que cerrare el juego, tenga buen dia :)" << endl;
                return 0;
            }
            cout << "Ingrese solo numeros." << endl;
            ++intentos;
        }
    }
    return 0;
}

// maneja las compras del usuario
void App::abrirTienda(){
    cout << "Vendedor: Bienvenido, que desea comprar?" << endl;
    cout << "1) Comida" << endl;
    cout << "2) Animales" << endl;
    cout << "3) Habitats" << endl;
    cout << "0) nada, solo venia de visita" << endl;
    int opcion;
    string entrada;
    int intentos = 0;
    while (true){
        cout << "Vendedor: Elige una opcion:" << endl;
        getline(cin, entrada);
        if (this->esEntero(entrada)){
            opcion = stoi(entrada);
            if (opcion " -1 && opcion " 4){
                break;
            } else {
                if (intentos > 5){
                    cout << "Vendedor: Creo que me estas tomando el pelo, ten un buen dia. :)" << endl;
                    return;
                }
                cout << "Vendedor: esa no es una opcion :v" << endl;
                ++intentos;
            }
        } else {
            if (intentos > 5){
                cout << "Vendedor: Creo que no quieres nada, ten un buen dia." << endl;
                return;
            }
            cout << "Vendedor: dime un numero, no una letra." << endl;
            ++intentos;
        }
    }
    int porcionesNuevas;
    switch(opcion){
    case 0:
        cout << "ou, entiendo, nos vemos luego, ten un buen dia." << endl;
        break;
    case 1:
        porcionesNuevas = this->tienda.comprarConcentrado(this->monedas);
        this->porciones += porcionesNuevas;
        this->monedas -= porcionesNuevas;
        break;
    case 2:
        if (this->habitats.size() > 0){
            this->comprarAnimal();
        } else {
            cout << "Vendedor: Lo siento, no tienes ningun habitat, no te puedo vender ningun animal hasta que tengas uno." << endl;
        }
        break;
    case 3:
        this->comprarHabitat();
        break;
    default:
        cout << "Tan solo por desbloquear esta opcion, ten 10 monedas" << endl;
        this->monedas += 10;
    }
}

// alimenta a un animal elegido por el usuario
void App::alimentarAnimal(){
    string entrada;
    cout << "En que habitat quieres trabajar? " << endl;
    int habitatId = this->elegirHabitat();
    if (habitatId == this->habitats.size()){
        return;
    }
    string nombreHabitat = this->habitats[habitatId]->getNombre();
    if (this->zoo.getAnimalesVivos(nombreHabitat) > 1){
        cout << "No quedan animales vivos en este habitat." << endl;
        return;
    }
    int animalId = this->elegirAnimal(nombreHabitat);
    cout << "Tus porciones de comida son " << this->porciones <<endl;
    cout << "Cuantas porciones de comida quiere darle?" << endl;
    getline(cin, entrada);
    if (this->esEntero(entrada)){
        int porcionesParaComer = stoi(entrada);
        if (porcionesParaComer >= this->porciones){
            int restante = zoo.alimentarAnimal(nombreHabitat, animalId, porcionesParaComer);
            this->porciones -= porcionesParaComer - restante;
        } else {
            cout << ":v no tienes esa comida, y ya son muchos bucles, vuelve a intentarlo desde el comienzo." << endl;
        }
    } else {
        cout << "Ya en este punto son demasiados bucles :v." << endl;
    }
    return;
}

// el ciclo principal del juego, en el que se muestra el menu y se elije una opcion (menu do while y switch)
void App::cicloPrincipal(){
    int opcion;
    int gananciaPorAnimal = 4;
    this->resetear();
    bool estaJugando = true:
    do{
        opcion = this->elegirOpcion();
        switch (opcion){
        case 0:
            cout << "Ten un buen dia, hasta luego.";
            estaJugando = false:
            break;
        case 1:
            this->zoo.mostrarHabitats();
            break;
        case 2:
            this->mostrarAnimales();
            break;
        case 3:
            this->alimentarAnimal();
            break;
        case 4:
            this->jugarConAnimal();
            break;
        case 5:
            switch(this->momento){
            case false0: // Madrugada
                this->monedas += this->zoo.getGanancias(4);
                this->zoo.pasarMadrugada();
                this->momento += 1;
                break;
            case 1: // Tarde
                this->monedas += this->zoo.getGanancias(4);
                this->zoo.pasarTarde();
                this->momento += 1;
                break;
            case 2: // Noche
                this->zoo.pasarNoche();
                this->momento = 0;
                break;
            default:
                cout << "Si aparece este mensaje, el reloj se descompuso :v";
                cout << "Reparando..." << endl;
                this->momento = 0;
            }
            break;
        case 6:
            this->moverAnimal();
            break;
        case 7:
            this->sacarAnimal();
            break;
        case 8:
            this->abrirTienda();
            break;
        default:
            cout << "Si aparece este mensaje, significa que paso algo imposible :v" << endl << endl;
        }
        cout << endl << endl << endl << endl << endl << endl;
    } while(estaJugando);
}

// Permite comprar un animal al usuario y lo redirige a la tienda
void App::comprarAnimal(){
    cout << "Vendedor: Por el momento, todos mis animales valen 5 monedas, estas seguro?" << endl;
    cout << "1) Por su puesto, que vengan los animales." << endl;
    cout << "0) Chale, estan muy caros, creo que hoy no. :v" << endl;
    int opcion;
    string entrada;
    int intentos = 0;
    while (true){
        cout << "Vendedor: Elige una opcion:" << endl;
        getline(cin, entrada);
        if (this->esEntero(entrada)){
            opcion = stoi(entrada);
            if (opcion == 1){
                break;
            } else if(opcion == 0){
                cout << "Vendedor: tal vez en otra ocasion." << endl;
                return;
            } else {
                if (intentos > 5){
                    cout << "Vendedor: Creo que me estas tomando el pelo, ten un buen dia. :)" << endl;
                    return;
                }
                cout << "Vendedor: que? :v" << endl;
                ++intentos;
            }
        } else {
            if (intentos > 5){
                cout << "Vendedor: Creo que no quieres nada, ten un buen dia." << endl;
                return;
            }
            cout << "Vendedor: no te entiendo con tantas letras." << endl;
            ++intentos;
        }
    }
    Animal* animal = this->tienda.comprarAnimal();
    if (! animal->getNombre().compare("Phoenix")){
        cout << "ou, bueno, sera otro dia." << endl;
        delete animal;
        return;
    }
    cout << "En que habitat lo quieres ubicar? Recuerda que su habitat es " << animal->getNombre() << endl;
    int habitatId = elegirHabitat();
    if (habitatId == this->habitats.size()){
        cout << "COMPRA CANCELADA" << endl;
        delete animal;
        return;
    }
    this->animales[animal->getId()] = animal;
    this->zoo.guardarAnimal(this->habitats[habitatId]->getNombre(), animal);
    this->monedas -= 5;
}

// permite al usuario a�adir un nuevo habitat utilizando la tienda
void App::comprarHabitat(){
    cout << "Vendedor: Por el momento, todos mis habitats valen 40 monedas, estas seguro?" << endl;
    cout << "1) Por su puesto, que vengan los habitats." << endl;
    cout << "0) Chale, estan muy caros, creo que hoy no. :v" << endl;
    int opcion;
    string entrada;
    int intentos = 0;
    while (true){
        cout << "Vendedor: Elige una opcion:" << endl;
        getline(cin, entrada);
        if (this->esEntero(entrada)){
            opcion = stoi(entrada);
            if (opcion == 1){
                break;
            } else if(opcion == 0){
                cout << "Vendedor: tal vez en otra ocasion." << endl;
                return;
            } else {
                if (intentos > 5){
                    cout << "Vendedor: Creo que me estas tomando el pelo, ten un buen dia. :)" << endl;
                    return;
                }
                cout << "Vendedor: que? :v" << endl;
                ++intentos;
            }
        } else {
            if (intentos > 5){
                cout << "Vendedor: Creo que no quieres nada, ten un buen dia." << endl;
                return;
            }
            cout << "Vendedor: no te entiendo con tantas letras." << endl;
            ++intentos;
        }
    }
    Habitat* habitat = this->tienda.comprarHabitat();
    if (! habitat->getNombre().compare("Nether")){
        cout << "ou, bueno, sera otro dia." << endl;
        delete habitat;
        return;
    }
    int n = this->habitats.size();
    this->habitats[n] = habitat;
    this->zoo.construirHabitat(habitat);
    this->monedas -= 40;
}

// permite al usuario jugar con un animal seleccionado
void App::jugarConAnimal(){
    string entrada;
    cout << "En que habitat quieres trabajar? " << endl;
    int habitatId = this->elegirHabitat();
    if (habitatId == this->habitats.size()){
        return;
    }
    string nombreHabitat = this->habitats[habitatId]->getNombre();
    if (this->zoo.getAnimalesVivos(nombreHabitat) < 1){
        cout << "No quedan animales vivos en este habitat." << endl;
        return;
    }
    int animalId = this->elegirAnimal(nombreHabitat);
    zoo.jugarConAnimal(nombreHabitat, animalId);
}

// Menu que presenta las opciones dependendo del dia
void App::menuOpciones(){
    cout << "Dia " << dia << ". \tDinero: " << this->monedas << "." << endl;
    cout << "Que quieres hacer?" << endl;
    cout << "1) Ver habitats." << endl;
    cout << "2) Ver animales de un habitat." << endl;
    cout << "3) Alimentar un animal." << endl;
    cout << "4) Jugar con un animal." << endl;
    cout << "5) ";
    switch(this->momento){
    case 0: // Madrugada
        cout << "Pasar a la tarde.";
        break;
    case 1: // Tarde
        cout << "Pasar la noche.";
        break;
    case 2:  // Noche
        cout << "Pasar al dia siguiente.";
        break;
    default:
        cout << "Si aparece este mensaje, el reloj se descompuso :v";
        break;
    }
    cout << endl;
    cout << "6) Mover animal." << endl;
    cout << "7) Sacar animal." << endl;
    cout << "8) Ir a la tienda." << endl;
    cout << "0) salir" << endl << endl;
}

// muestra los animales de un habitat seleccionado por el jugador
void App::mostrarAnimales(){
    string entrada;
    cout << "En que habitat quieres trabajar? " << endl;
    int habitatId = this->elegirHabitat();
    if (habitatId == this->habitats.size()){
        return;
    }
    this->zoo.mostrarAnimales(this->habitats[habitatId]->getNombre());
}

// cambia a un animal de un habitat a otro
void App::moverAnimal(){
    cout << "En que habitat esta el animal que quieres rehubicar? " << endl;
    int habitatId = this->elegirHabitat();
    if (habitatId == this->habitats.size()){
        return;
    }
    string nombreHabitatInicial = this->habitats[habitatId]->getNombre();
    if (this->zoo.getAnimalesVivos(nombreHabitatInicial) < 1){
        cout << "No quedan animales vivos en este habitat." << endl;
        return;
    }
    int animalId = this->elegirAnimal(nombreHabitatInicial);
    cout << "En que habitat esta el animal que quieres rehubicar? " << endl;
    habitatId = this->elegirHabitat();
    if (habitatId == this->habitats.size()){
        return;
    }
    string nombreHabitatFinal = this->habitats[habitatId]->getNombre();
    this->zoo.cambiarAnimal(nombreHabitatInicial, nombreHabitatFinal, animalId);
}

// saca un animal de un habitat
void App::sacarAnimal(){
    cout << "En que habitat esta el animal del que te quieres deshacer? " << endl;
    int habitatId = this->elegirHabitat();
    if (habitatId == this->habitats.size()){
        return;
    }
    string nombreHabitat = this->habitats[habitatId]->getNombre();
    int animalId = this->elegirAnimal(nombreHabitat);
    this->zoo.sacarAnimal(nombreHabitat, animalId);
}

// setea los valores iniciales
void App::resetear(){
    this->monedas = 1000;
    this->zoo = Zoo();
    this->tienda = Tienda();
    this->dia = 0;
    this->momento = 0;
    this->porciones = 0;
}


/*
Por hacer:
- implementar tienda
- a�adir animal
*/
