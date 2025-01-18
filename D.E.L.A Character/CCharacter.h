#pragma once
#include <string>
#include <iostream>
#include <list>
class CCharacter
{
	public:
        std::string nombre;
        std::string titulo;
        std::string raza;
        std::string clase;
        std::string objetoUnico;
        int PV = 0;
        int FUE = 0;
        int DES = 0;
        int VOL = 0;
        int oro = 0;
        int puntosCarga = 0;
        void rollPV();
        void rollOro();
        void rollObjetoUnico();
        void rollEstadisticas();
        void elegirRaza();
        void elegirClase();
        void elegirNombre();
        void printBienvenida();
        void printNombre();
        void printRaza();
        void printClase();
        void printObjeto();
        void printEstadisticas();
        void printPersonaje();

    private:
        int rollD4();
        int rollD6();
        
};

