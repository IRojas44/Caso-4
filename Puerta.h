#include "../../Lista Poli/List.h"

#ifndef PUERTA

#define PUERTA 1

class Puerta{
private:
    int id;
    int entradas;
    List<Puerta> *puertasAsociadas;
public:
    Puerta(int pId){
        id = pId;
        entradas = 0;
        puertasAsociadas = new List<Puerta>;
    }

    void agregarPuerta(int pIdPuerta){
        //Puerta puerta = Puerta(pIdPuerta);
        puertasAsociadas->add(new Puerta(pIdPuerta));
    }

    void usarEntrada(){
        entradas+1;
    }

    int getEntradas(){
        return entradas;
    }

    int getId(){
        return id;
    }

};

#endif