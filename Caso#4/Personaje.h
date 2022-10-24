#include<iostream>
using namespace std;
#ifndef PERSONAJE

#define PERSONAJE 1

class Personaje{
private:
    string nombre;
    int mtsPorSeg;
    int cantMineral;
public:
    Personaje(){
        nombre = "";
        mtsPorSeg = 0;
        cantMineral = 0;
    }

    Personaje(string pNombre ,int pMtsPorSeg){
        nombre = pNombre;
        mtsPorSeg = pMtsPorSeg;
        cantMineral = 0;
    }

    void setCant(int cant){
        cantMineral = cant;
    }

    string getNom(){
        return nombre;
    }

    int getCant(){
        return cantMineral;
    }

    int getMtsPorSeg(){
        return mtsPorSeg;
    }
};

#endif