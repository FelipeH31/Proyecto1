#include "tienda.h"
#include "herbivoro.h"
#include "carnivoro.h"
#include "omnivoro.h"

const string herbivoro = "Herviboro";
const string carnivoro = "Carnivoro";
const string omnivoro = "Omnivoro";

// Constructor de la tienda, donde se a�aden los habitats y animales comprables
Tienda::Tienda()
{
    this->animalesVendidos = 0;
    this->animalesEnVenta = 13;
    this->habitats.push_back("Sabana");
    this->habitats.push_back("Bosque");
    this->habitats.push_back("Antartico");
    this->animales[0] = {
        {
            "nombre","Le�n (Panthera leo)"
        },
        {
            "vidaMaxima","14"
        },
        {
            "Alimentacion", "Carnivoro"
        },
        {
            "porciones", "20"
        },
        {
            "hambreMinima", "7"
        },
        {
            "hambreMaxima", "9"
        },
        {
            "Habitat", "Sabana"
        },
        {
            "Descripcion", "El le�n es el rey de la selva y es uno de los animales m�s emblem�ticos del zool�gico. Los visitantes pueden observar su majestuosa melena y su comportamiento en manada."
        }
    };
    this->animales[1] = {
        {
            "nombre","Tigre (Panthera tigris)"
        },
        {
            "vidaMaxima","18"
        },
        {
            "Alimentacion", "Carnivoro"
        },
        {
            "porciones", "40"
        },
        {
            "hambreMinima", "5"
        },
        {
            "hambreMaxima", "7"
        },
        {
            "Habitat", "Bosque"
        },
        {
            "Descripcion", "El tigre es el felino m�s grande del mundo y uno de los animales m�s fascinantes del zool�gico. A menudo se pueden ver trepando en �rboles y nadando en lagos."
        }
    };
    this->animales[2] = {
        {
            "nombre","Elefante (Loxodonta africana)"
        },
        {
            "vidaMaxima","70"
        },
        {
            "Alimentacion", "Herbivoro"
        },
        {
            "porciones", "200"
        },
        {
            "hambreMinima", "12"
        },
        {
            "hambreMaxima", "20"
        },
        {
            "Habitat", "Sabana"
        },
        {
            "Descripcion", "Los elefantes son animales enormes y majestuosos que a menudo se encuentran en exhibiciones de zool�gicos. Los visitantes pueden disfrutar de verlos interactuar con sus cuidadores y jugar con otros elefantes en �reas de juego."
        }
    };
    this->animales[3] = {
        {
            "nombre","Jirafa (Giraffa camelopardalis)"
        },
        {
            "vidaMaxima","25"
        },
        {
            "Alimentacion", "Herbivoro"
        },
        {
            "porciones", "130"
        },
        {
            "hambreMinima", "10"
        },
        {
            "hambreMaxima", "20"
        },
        {
            "Habitat", "Sabana"
        },
        {
            "Descripcion", "La jirafa es uno de los animales m�s altos del mundo y una vista impresionante en el zool�gico. Los visitantes pueden verlas comer hojas de �rboles altos y usar su cuello largo para alcanzar ramas inaccesibles."
        }
    };
    this->animales[4] = {
        {
            "nombre","Cebra (Equus quagga)"
        },
        {
            "vidaMaxima","25"
        },
        {
            "Alimentacion", "Herbivoro"
        },
        {
            "porciones", "30"
        },
        {
            "hambreMinima", "10"
        },
        {
            "hambreMaxima", "15"
        },
        {
            "Habitat", "Sabana"
        },
        {
            "Descripcion", "Las cebras son animales sociales y a menudo se mantienen en manadas en zool�gicos. Los visitantes pueden observar sus patrones �nicos de rayas blancas y negras y su comportamiento en manada."
        }
    };
    this->animales[5] = {
        {
            "nombre","Rinoceronte (Diceros bicornis)"
        },
        {
            "vidaMaxima","50"
        },
        {
            "Alimentacion", "Herbivoro"
        },
        {
            "porciones", "140"
        },
        {
            "hambreMinima", "10"
        },
        {
            "hambreMaxima", "20"
        },
        {
            "Habitat", "Sabana"
        },
        {
            "Descripcion", "Los rinocerontes son animales grandes y poderosos que son populares en los zool�gicos por su singular apariencia y su comportamiento tranquilo. Los visitantes pueden verlos alimentarse de pasto y hojas, y tambi�n pueden aprender sobre los esfuerzos de conservaci�n para proteger a esta especie en peligro de extinci�n."
        }
    };
    this->animales[6] = {
        {
            "nombre","Gorila (Gorilla gorilla)"
        },
        {
            "vidaMaxima","40"
        },
        {
            "Alimentacion", "Herbivoro"
        },
        {
            "porciones", "14"
        },
        {
            "hambreMinima", "10"
        },
        {
            "hambreMaxima", "12"
        },
        {
            "Habitat", "Bosque"
        },
        {
            "Descripcion", "Los gorilas son primates poderosos y emocionalmente inteligentes que a menudo son una gran atracci�n en los zool�gicos. Los visitantes pueden verlos interactuar con otros gorilas y jugar con juguetes y enredaderas."
        }
    };
    this->animales[7] = {
        {
            "nombre","Orangut�n (Pongo pygmaeus)"
        },
        {
            "vidaMaxima","40"
        },
        {
            "Alimentacion", "Omnivoro"
        },
        {
            "porciones", "20"
        },
        {
            "hambreMinima", "5"
        },
        {
            "hambreMaxima", "7"
        },
        {
            "Habitat", "Bosque"
        },
        {
            "Descripcion", "Los orangutanes son primates peludos y tranquilos que son populares en los zool�gicos debido a su singular apariencia y su comportamiento tranquilo. Los visitantes pueden verlos comer frutas y nueces, y tambi�n pueden aprender sobre los esfuerzos de conservaci�n para proteger a esta especie en peligro de extinci�n."
        }
    };
    this->animales[8] = {
        {
            "nombre","Ping�ino (Spheniscus demersus)"
        },
        {
            "vidaMaxima","20"
        },
        {
            "Alimentacion", "Carnivoro"
        },
        {
            "porciones", "3"
        },
        {
            "hambreMinima", "2"
        },
        {
            "hambreMaxima", "2"
        },
        {
            "Habitat", "Antartico"
        },
        {
            "Descripcion", "Los ping�inos son aves acu�ticas fascinantes que son populares en los zool�gicos debido a su habilidad para nadar y su comportamiento social. Los visitantes pueden verlos deslizarse por el agua y descansar juntos en grupos."
        }
    };
    this->animales[9] = {
        {
            "nombre","Delf�n (Delphinus delphis)"
        },
        {
            "vidaMaxima","25"
        },
        {
            "Alimentacion", "Carnivoro"
        },
        {
            "porciones", "40"
        },
        {
            "hambreMinima", "5"
        },
        {
            "hambreMaxima", "7"
        },
        {
            "Habitat", "Bosque"
        },
        {
            "Descripcion", "Los delfines son mam�feros acu�ticos amigables e inteligentes que son una atracci�n popular en los zool�gicos. Los visitantes pueden verlos realizar acrobacias y aprender sobre los esfuerzos de conservaci�n para proteger a estas criaturas marinas."
        }
    };
    this->animales[10] = {
        {
            "nombre","Cocodrilo (Crocodylus niloticus)"
        },
        {
            "vidaMaxima","100"
        },
        {
            "Alimentacion", "Carnivoro"
        },
        {
            "porciones", "50"
        },
        {
            "hambreMinima", "10"
        },
        {
            "hambreMaxima", "15"
        },
        {
            "Habitat", "Bosque"
        },
        {
            "Descripcion", "Los cocodrilos son reptiles temibles y poderosos que son una vista impresionante en los zool�gicos. Los visitantes pueden verlos alimentarse de carne y aprender sobre su importancia en los ecosistemas acu�ticos."
        }
    };
    this->animales[11] = {
        {
            "nombre","Hipop�tamo (Hippopotamus amphibius)"
        },
        {
            "vidaMaxima","50"
        },
        {
            "Alimentacion", "Herbivoro"
        },
        {
            "porciones", "200"
        },
        {
            "hambreMinima", "10"
        },
        {
            "hambreMaxima", "20"
        },
        {
            "Habitat", "Sabana"
        },
        {
            "Descripcion", "Los hipop�tamos son mam�feros acu�ticos masivos y poderosos que son populares en los zool�gicos debido a su tama�o imponente y su comportamiento social. Los visitantes pueden verlos sumergirse en el agua y salir a la orilla para pastar."
        }
    };
    this->animales[12] = {
        {
            "nombre","Oso polar (Ursus maritimus)"
        },
        {
            "vidaMaxima","30"
        },
        {
            "Alimentacion", "Carnivoro"
        },
        {
            "porciones", "60"
        },
        {
            "hambreMinima", "10"
        },
        {
            "hambreMaxima", "15"
        },
        {
            "Habitat", "Antartico"
        },
        {
            "Descripcion", "Los osos polares son mam�feros grandes y majestuosos que son una atracci�n popular en los zool�gicos debido a su singular apariencia y comportamiento curioso. Los visitantes pueden verlos jugar en la nieve y aprender sobre los esfuerzos de conservaci�n para proteger a esta especie en peligro de extinci�n."
        }
    };
}

Tienda::~Tienda()
{
}

// verifica si todas las partes son enteros, tomado de: www.tutorialspoint.com/cplusplus-program-to-check-if-input-is-an-integer-or-a-string
bool Tienda::esEntero(string entrada){
    for (int i = 0; i < entrada.length(); i++){
        if (isdigit(entrada[i]) == false){
            return false;
        }
    }
    return true;
}

// Le da a elegir al usuario cuantas porciones de comida quiere comprar, y verifica que tenga el dinero para ello.
int Tienda::comprarConcentrado(int monedas){
    cout << "Monedas: " << monedas << endl;
    cout << "Vendedor: Cuanta comida deseas? Cada porcion es a una moneda." << endl;
    while(true){
        int cantidad = this->elegirNumero();
        if (cantidad > monedas){
            cout << "Vendedor: No tienes suficientes monedas, deberas llevar menos." << endl;
        }
        if (cantidad > 0){
            cout << "Vendedor: Bien, aqui tienes " << cantidad << " porciones de concentrado. Ten un buen dia." << endl;
            return cantidad;
        } else if (cantidad == 0){
            cout << "Vendedor: Sera en otro momento, ten buen dia." << endl;
            return cantidad;
        } else {
            cout << "No creo que sea una cantidad posible, mejor dime otra." << endl;
        }
    }
}

// Devuelve un numero ingresado por el usuario
int Tienda::elegirNumero(){
    string entrada;
    int numero;
    int intentos = 0;
    while(true){
        getline(cin, entrada);
        if (this->esEntero(entrada)){
            numero = stoi(entrada);
            return numero;
        } else {
            if (intentos > 5){
                cout << "Vendedor: Siguiente..." << endl;
                return 0;
            }
            cout << "Vendedor: Ingrese solo numeros." << endl;
            ++intentos;
        }
    }
    return 0;
}

// Genera un nuevo animal, dependiendo de las entradas del usuario
Animal* Tienda::comprarAnimal(){
    cout << "Vendedor: Tenemos los siguientes animales disponibles:" << endl;
    unordered_map"string, string" animalDescripcion;
    for (int i = 0; i < this->animalesEnVenta; ++i){
        animalDescripcion = this->animales[i];
        cout << i << ") Especie: " << animalDescripcion["nombre"] << ".\t|Tipo: " << animalDescripcion["Alimentacion"] << ".\t|Esperanza de vida: " << animalDescripcion["vidaMaxima"] << " a�os.\t|Habitat: " << animalDescripcion["Habitat"] << ".\t|Porciones de comida: " << animalDescripcion["hambreMinima"]
             << "-" << animalDescripcion["hambreMaxima"] << ".\t|" << endl;
    }
    cout << this->animalesEnVenta << ") ninguno." << endl;
    cout << "Vendedor: Cual quieres?" << endl;
    while(true){
        int opcion = this->elegirNumero();
        if (opcion == this->animalesEnVenta){
            Animal* animal = new Animal(-1, "Fawkes", "Macho", 255, 0, 999, "Phoenix", "Bosque", "El f�nix es una criatura legendaria de la mitolog�a que se ha hecho famosa por su habilidad para renacer de sus propias cenizas. Aunque no se puede ver un f�nix en un zool�gico real, a menudo se representa en obras de arte y en la cultura popular, y se ha convertido en un s�mbolo de la resurrecci�n y la regeneraci�n.");
            return animal;
        } else if (opcion " this->animalesEnVenta && opcion " -1){
            cout << "Vendedor: Como lo quiere nombrar?" << endl;
            string nombre;
            getline(cin, nombre);
            animalDescripcion = this->animales[opcion];
            string sexo;
            if (rand() % 2 == 0){
                sexo = "Macho";
            } else {
                sexo = "Hembra";
            }
            int hambreMinima = stoi(animalDescripcion["hambreMinima"]);
            int hambreMaxima = stoi(animalDescripcion["hambreMaxima"]);
            int variacion = hambreMaxima - hambreMinima;
            int hambre;
            if (variacion == 0){
                hambre = hambreMinima;
            } else {
                hambre = (rand() % variacion) + hambreMinima;
            }
            int edad = rand() % stoi(animalDescripcion["vidaMaxima"]);
            string tipo = animalDescripcion["Alimentacion"];
            Animal* animal;
            if (tipo.compare(carnivoro)){
                animal = new Carnivoro(this->animalesVendidos, nombre, sexo, edad, stoi(animalDescripcion["porciones"]), hambre, animalDescripcion["nombre"], animalDescripcion["Habitat"], animalDescripcion["Descripcion"]);
            } else if (tipo.compare(herbivoro)) {
                animal = new herbivoro(this->animalesVendidos, nombre, sexo, edad, stoi(animalDescripcion["porciones"]), hambre, animalDescripcion["nombre"], animalDescripcion["Habitat"], animalDescripcion["Descripcion"]);
            } else if (tipo.compare(omnivoro)) {
                animal = new Omnivoro(this->animalesVendidos, nombre, sexo, edad, stoi(animalDescripcion["porciones"]), hambre, animalDescripcion["nombre"], animalDescripcion["Habitat"], animalDescripcion["Descripcion"]);
            }
            ++this->animalesVendidos;
            return animal;
        } else {
            cout << "Vendedor: Mmmmmmmm, no entiendo, cual quieres?" << endl;
        }

    }
}

// Devuelve un habitat elegido por el usuario, y lo elimina de habitats posibles para construir
Habitat* Tienda::comprarHabitat(){
    cout << "Vendedor: Tenemos los siguientes habitats disponibles:" << endl;
    int n = this->habitats.size();
    for (int i = 0; i != n; ++i){
        cout << i + 1 << ") " << this->habitats[i] << endl;
    }
    cout << "0) ninguno." << endl;
    cout << "Vendedor: Cual quieres?" << endl;
    while(true){
        int opcion = this->elegirNumero();
        if (opcion == 0){
            Habitat* habitat = new Habitat("Nether");
            return habitat;
        } else if (opcion "= n && opcion " -1){
            --opcion;
            Habitat* habitat = new Habitat(this->habitats[opcion]);
            vector"string"::iterator habitatId = this->habitats.begin() + (opcion);
            this->habitats.erase(habitatId);
            return habitat;
        } else {
            cout << "Vendedor: Mmmmmmmm, no entiendo, cual quieres?" << endl;
        }

    }
}
