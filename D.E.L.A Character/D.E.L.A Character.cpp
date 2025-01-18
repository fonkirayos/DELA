// D.E.L.A By Alex Sanchez
// Code by FunkyWizardDude
//

#include "CCharacter.h"

int main()
{
   
    std::srand(time(nullptr));

    CCharacter character;
    character.rollEstadisticas();
    character.rollObjetoUnico();
    character.printEstadisticas();
    character.elegirRaza();
    character.elegirClase();
    character.elegirNombre();
    character.printPersonaje();

    return 0;
}


