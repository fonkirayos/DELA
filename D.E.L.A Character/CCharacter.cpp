#include "CCharacter.h"

void CCharacter::rollPV()
{
    std::list<int> pv;
    int PV = 0;

    for (int i = 0; i < 4; i++) {
        pv.push_back(rollD6());
    }
    pv.sort();
    pv.reverse();

    // Create an iterator for the list
    auto it = pv.begin();

    // Loop through the first three elements of the list
    for (int i = 0; i < 3 && it != pv.end(); ++i, ++it) {
        PV += *it;
    }
    CCharacter::PV = PV;
}

void CCharacter::rollOro()
{
    int oro = 0;

    for (int i = 0; i < 2; i++) {
        oro += rollD6();
    }

    oro *= 5;
    CCharacter::oro = oro;
}

void CCharacter::rollObjetoUnico()
{
    int objeto = 0;
    for (int i = 0; i < 3; i++) {
        objeto += rollD6();
    }

    switch (objeto)
    {
    default:
        break;
    case 3:
        objetoUnico = "Capa de Agilidad (-1 al Resultado al usar DES en Pruebas o Combate)";
        break;
    case 4:
        objetoUnico = " Colmillo de un Lobo Gigante";
        break;
    case 5:
        objetoUnico = " Rosa con Espinas";
        break;
    case 6:
        objetoUnico = "Daga Envenenada (2 Punto de Daño por 3 Asaltos)";
        break;
    case 7:
        objetoUnico = "Amuleto Sagrado";
        break;
    case 8:
        objetoUnico = "Totem de Madera";
        break;
    case 9:
        objetoUnico = "Casco de Caballero (1 Punto de Armadura al usarlo)";
        break;
    case 10:
        objetoUnico = " Botella de Vino";
        break;
    case 11:
        objetoUnico = "Baraja de Cartas";
        break;
    case 12:
        objetoUnico = "Laud de Trovador (Al usarlo en Combate apoyas a un Aliado dándole Ventaja en su siguiente ataque)";
        break;
    case 13:
        objetoUnico = "Craneo de Ocultista";
        break;
    case 14:
        objetoUnico = "Carta de un Ser Querido";
        break;
    case 15:
        objetoUnico = "Guantes de Combate (-1 al resultado al usar FUE en Pruebas o Combate)";
        break;
    case 16:
        objetoUnico = "Pluma y Tinta";
        break;
    case 17:
        objetoUnico = "Trozo de Metal en Bruto";
        break;
    case 18:
        objetoUnico = "Anillo de Poder (-1 al resultado al usar VOL en Pruebas o Combate)";
        break;
    }
}

void CCharacter::rollEstadisticas()
{
    std::cout << "Generando Estadisticas\n";
    rollPV();
    FUE = rollD4() + 1;
    DES = rollD4() + 1;
    VOL = rollD4() + 1;
    rollOro();
    puntosCarga = 10 + FUE;
}

void CCharacter::elegirRaza()
{
    int eleccion = 0;
    do {
        std::cout << "\n";
        printBienvenida();
        std::cout << "\n";
        printEstadisticas();
        std::cout << "\n";
        printObjeto();

        std::cout << "\n";
        std::cout << "Elige tu raza (utilizando numeros)\n";
        std::cout << "1) Enanos " << "Ventajas de Raza: Vision en la Oscuridad, Resistencia a Veneno y Competencia con Herramientas de Herrero\n";
        std::cout << "2) Elfos " << "Ventajas de Raza: Vision en la Oscuridad, Resistencia a Encantamiento y Trance\n";
        std::cout << "3) Medianos " << "Ventajas de Raza: Escurridizo, Suertudo y Resistencia a ser Sorprendido\n";
        std::cout << "4) Humano " << "Ventajas de Raza: Un segundo Objeto unico y Competencia con cualquier Herramienta\n";
        std::cin >> eleccion;

    } while (eleccion <= 0 || eleccion > 4);

    switch (eleccion)
    {
    default:
        break;
    case 1:
        raza = "Enano";
        break;
    case 2:
        raza = "Elfo";
        break;
    case 3:
        raza = "Mediano";
        break;
    case 4:
        raza = "Humano";
        break;
    }
}

void CCharacter::elegirClase()
{
    int eleccion = 0;
    do {
        printBienvenida();
        std::cout << "\n";
        printEstadisticas();
        std::cout << "\n";
        printObjeto();
        std::cout << "\n";
        printRaza();

        std::cout << "\n";
        std::cout << "Elige tu clase (utilizando numeros)\n";

        std::cout << "1) Guerrero\n";
        std::cout << "Caracteristica Principal: Fuerza\n";
        std::cout << "Habilidad Inicial: Ataque Multiple\n";
        std::cout << "Arma Inicial: Espada o Hacha de Mano\n";
        std::cout << "Objeto Inicial: Escudo de Madera\n";

        std::cout << "\n";

        std::cout << "2) Picaro\n";
        std::cout << "Caracteristica Principal: Destreza\n";
        std::cout << "Habilidad Inicial: Dedos Agiles\n";
        std::cout << "Arma Inicial: Daga o Arco corto\n";
        std::cout << "Objeto Inicial: Herramientas de ladron\n";

        std::cout << "\n";

        std::cout << "3) Usuario de Magia\n";
        std::cout << "Caracteristica Principal: Voluntad\n";
        std::cout << "Habilidad Inicial: Lanzamiento de Conjuros\n";
        std::cout << "Arma Inicial: Baston o Honda\n";
        std::cout << "Objeto Inicial: Libro de Hechizos\n";

        std::cout << "\n";
        std::cin >> eleccion;

    } while (eleccion <= 0 || eleccion > 3);

    switch (eleccion)
    {
    default:
        break;
    case 1:
        clase = "Guerrero";
        break;
    case 2:
        clase = "Picaro";
        break;
    case 3:
        clase = "Usuario de Magia";
        break;
    }
}

void CCharacter::elegirNombre()
{
    unsigned char qm = 168;
    std::cout << qm << "Cual es tu nombre?\n";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << qm << "Cual es tu titulo?\n";
    std::getline(std::cin, titulo);
}

void CCharacter::printBienvenida()
{
    std::cout << "D.E.L.A MEDIEVAL FANTASY\n";
}

void CCharacter::printNombre()
{
    std::cout << nombre << " " << titulo << "\n";
}

void CCharacter::printRaza()
{
    std::cout << raza << "\n";
}

void CCharacter::printClase()
{
    std::cout << clase << "\n";
}

void CCharacter::printObjeto()
{
    std::cout << "Objeto Unico: " << objetoUnico << "\n";
}

void CCharacter::printEstadisticas()
{
    std::cout << "ESTADISTICAS " << "\n";
    std::cout << "Puntos de Vida: " << PV << "\n";
    std::cout << "Fuerza: " << FUE << "\n";
    std::cout << "Destreza: " << DES << "\n";
    std::cout << "Voluntad: " << VOL << "\n";
    std::cout << "Oro: " << oro << "\n";
    std::cout << "Puntos de Carga: " << puntosCarga << "\n";
}

void CCharacter::printPersonaje()
{
    std::cout << "==============================================================" << "\n";
    printNombre();
    printRaza();
    printClase();
    printObjeto();
    printEstadisticas();
    std::cout << "==============================================================" << "\n";
}

int CCharacter::rollD4()
{
    return rand() % 4 + 1;
}

int CCharacter::rollD6()
{
    return rand() % 6 + 1;
}
