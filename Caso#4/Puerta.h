#include "../../Lista Poli/List.h"
#include "AVLTree/AVLTree.h"
#ifndef PUERTA

#define PUERTA 1

class Puerta{
private:
    int id;
    int entradas;
    List<Puerta> *puertasAsociadas;
    AVLTree *tunelesYCamaras;
public:
    Puerta(int pId){
        id = pId;
        entradas = 0;
        puertasAsociadas = new List<Puerta>;
        tunelesYCamaras = new AVLTree;
    }

    void agregarPuerta(int pIdPuerta){
        //Puerta puerta = Puerta(pIdPuerta);
        puertasAsociadas->add(new Puerta(pIdPuerta));
        entradas++;
    }

    List<Puerta>* listaPuertas(){
        return puertasAsociadas;
    }

    int getEntradas(){
        return entradas;
    }

    int getId(){
        return id;
    }

    AVLTree* getArbol(){
        return tunelesYCamaras;
    }

       

    

};

#endif