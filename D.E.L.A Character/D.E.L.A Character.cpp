// D.E.L.A By Alex Sanchez
// Code by FunkyWizardDude
//

#include "CCharacter.h"
#include <vector>
int main()
{
   
    std::srand(time(nullptr));
    int numPersonajes;
    CCharacter personaje;
    std::vector<CCharacter> personajes;
    
    std::cout << "D.E.L.A MEDIEVAL FANTASY\n";
    std::cout << "Cuantos personaje vas a crear?\n";
    std::cin >> numPersonajes;

    for (int i = 0; i < numPersonajes; i++) {
        personaje.rollEstadisticas();
        personaje.rollObjetoUnico();
        personaje.printEstadisticas();
        personaje.elegirRaza();
        personaje.elegirClase();
        personaje.elegirNombre();
        std::cout << "guardando personaje numero " << i+1 << "\n";
        personajes.push_back(personaje);
    }
    
    std::cout << "\n";
    std::cout << "Lista de Personajes: \n";
    std::cout << "\n";
    for (int i = 0; i < numPersonajes; i++) {
        personajes[i].printPersonaje();
    }

    return 0;
}


