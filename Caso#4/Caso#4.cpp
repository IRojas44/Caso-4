#include "../../Lista Poli/List.h"
#include "AVLTree/AVLTree.h"
#include <string>
#include <iostream>
#include "Personaje.h"
#include "Puerta.h"
#include <map>
#include <vector>

using namespace std; 
//pId: id de la puerta a la que se va a meter mas puertas
//pIdPuerta: id de la puerta que se va a meter
void agregarPuerta(List<Puerta> *lisPuertas, int pId, int pIdPuerta){
   float probabilidad = rand() / static_cast<float>(RAND_MAX);
   for (int i = 0; i < lisPuertas->getSize(); i++){
      if(lisPuertas->find(i)->getId()==pId){
         if (lisPuertas->find(i)->getEntradas()<4){
            if(probabilidad<=0.66){
               cout<<"Va con puerta"<<endl;
               lisPuertas->find(i)->agregarPuerta(pIdPuerta);
               for (int j = 0; j < 4; j++){
                  if(lisPuertas->find(i)->listaPuertas()->find(j)->getId()==pIdPuerta){
                     lisPuertas->find(i)->listaPuertas()->find(j)->agregarPuerta(pId);
                     break;
                  }
               }
            }else{
               cout<<"No va con puerta"<<endl;
            }
         }else{
            cout<<"No se pueden agregar mas puertas a esta puerta"<<endl;
            break;
         }
      }
   }
}
/*
void agregarCamarasyTuneles(List<Puerta> *lisPuertas, int pId){
   for (int i = 0; i < lisPuertas->getSize(); i++){
      if(lisPuertas->find(i)->getId()==pId){
         int cantMinerales = 1 + rand()%(20+1-1);
         int distancia = 10 + rand()%(80+1-10);
         int potencialMinado = cantMinerales * distancia;
         TreeNode * newNode = new TreeNode();
         newNode -> setValue(potencialMinado);
         lisPuertas->find(i)->getArbol()->setRoot(lisPuertas->find(i)->getArbol()->insert(lisPuertas->find(i)->getArbol()->getRoot(),newNode,distancia,cantMinerales));
      }
   }   
}
*/
int recorrerLaMina(List<Puerta> *lisPuertas, int eleccionPersonaje, int eleccionEstr, int minaElegida){
   int mineralesDelJugador = 0;
   Personaje *per;
   if(eleccionPersonaje==1){
      per = new Personaje("Explorador",20);
         if(eleccionEstr==1){
            cout<<"Estrategia: Entrar a la primera mina que se encuentre y sacar mineral"<<endl;
            for (int i = 0; i < lisPuertas->getSize(); i++){
               if(lisPuertas->find(i)->getArbol()->getRoot()!=NULL){
                  string str = to_string(lisPuertas->find(i)->getId());
                  cout<<"El "+per->getNom()+" se metio a la mina de la puerta: "+str<<endl;
                  if(lisPuertas->find(i)->getArbol()->getRoot()->getCantidad()<=8){
                     per->setCant(lisPuertas->find(i)->getArbol()->getRoot()->getCantidad());
                     float duracion = lisPuertas->find(i)->getArbol()->getRoot()->getDistancia()/per->getMtsPorSeg();
                     string strDuracion = to_string(duracion);
                     string strCant = to_string(lisPuertas->find(i)->getArbol()->getRoot()->getCantidad());
                     cout<<"El "+per->getNom()+" recogio "+strCant+" unidades de mineral y duro "+strDuracion+" segundos"<<endl;
                     mineralesDelJugador+=lisPuertas->find(i)->getArbol()->getRoot()->getCantidad();
                     break;
                  }else{
                     per->setCant(8); 
                     float duracion = lisPuertas->find(i)->getArbol()->getRoot()->getDistancia()/per->getMtsPorSeg();
                     string strDuracion = to_string(duracion);
                     string strCant = to_string(lisPuertas->find(i)->getArbol()->getRoot()->getCantidad());
                     cout<<"El "+per->getNom()+" recogio 8 unidades de mineral aunque habian "+strCant +" y duro "+strDuracion+" segundos"<<endl;
                     lisPuertas->find(i)->getArbol()->getRoot()->setCantMin(lisPuertas->find(i)->getArbol()->getRoot()->getCantidad()-8);
                     mineralesDelJugador+=8;
                     break;
                  }
               }
            }  
         }else if(eleccionEstr==2){
            //int minaElegida=4;
            string str = to_string(minaElegida);
            cout<<"Estrategia: Entrar a la mina de la puerta indicada: "+str<<endl;
            for (int i = 0; i < lisPuertas->getSize(); i++){
               if(lisPuertas->find(minaElegida)->getArbol()->getRoot()!=NULL){
                  
                  cout<<"El "+per->getNom()+" se metio a la mina de la puerta: "+str<<endl;
                  if(lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad()<=8){
                     per->setCant(lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad());
                     float duracion = lisPuertas->find(minaElegida)->getArbol()->getRoot()->getDistancia()/per->getMtsPorSeg();
                     string strDuracion = to_string(duracion);
                     string strCant = to_string(lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad());
                     cout<<"El "+per->getNom()+" recogio "+strCant+" unidades de mineral y duro "+strDuracion+" segundos"<<endl;
                     mineralesDelJugador+=lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad();
                     break;
                  }else{
                     per->setCant(8); 
                     float duracion = lisPuertas->find(minaElegida)->getArbol()->getRoot()->getDistancia()/per->getMtsPorSeg();
                     string strDuracion = to_string(duracion);
                     string strCant = to_string(lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad());
                     cout<<"El "+per->getNom()+" recogio 8 unidades de mineral aunque habian "+strCant+" y duro "+strDuracion+" segundos"<<endl;
                     lisPuertas->find(minaElegida)->getArbol()->getRoot()->setCantMin(lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad()-8);
                     mineralesDelJugador+=8;
                     break;
                  }
               }else{
                  cout<<"Esta puerta no tiene mina, mala suerte"<<endl;
                  break;
               }
            }
         }
   }else if(eleccionPersonaje==2){
      per = new Personaje("Carguero", 10);
      if(eleccionEstr==1){
            cout<<"Estrategia: Entrar a la primera mina que se encuentre y sacar mineral"<<endl;
            for (int i = 0; i < lisPuertas->getSize(); i++){
               if(lisPuertas->find(i)->getArbol()->getRoot()!=NULL){
                  string str = to_string(lisPuertas->find(i)->getId());
                  cout<<"El "+per->getNom()+" se metio a la mina de la puerta: "+str<<endl;
                  per->setCant(lisPuertas->find(i)->getArbol()->getRoot()->getCantidad());
                  float duracion = lisPuertas->find(i)->getArbol()->getRoot()->getDistancia()/per->getMtsPorSeg();
                  string strDuracion = to_string(duracion);
                  string strCant = to_string(lisPuertas->find(i)->getArbol()->getRoot()->getCantidad());
                  cout<<"El "+per->getNom()+" recogio "+strCant+" unidades de mineral y duro "+strDuracion+" segundos"<<endl;
                  mineralesDelJugador+=lisPuertas->find(i)->getArbol()->getRoot()->getCantidad();
                  break;
               }
            }  
         }else if(eleccionEstr==2){
            //int minaElegida=4;
            string str = to_string(minaElegida);
            cout<<"Estrategia: Entrar a la mina de la puerta indicada: "+str<<endl;
            for (int i = 0; i < lisPuertas->getSize(); i++){
               if(lisPuertas->find(minaElegida)->getArbol()->getRoot()!=NULL){
                  
                  cout<<"El "+per->getNom()+" se metio a la mina de la puerta: "+str<<endl;
                  float duracion = lisPuertas->find(minaElegida)->getArbol()->getRoot()->getDistancia()/per->getMtsPorSeg();
                  string strDuracion = to_string(duracion);
                  per->setCant(lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad());
                  string strCant = to_string(lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad());
                  cout<<"El "+per->getNom()+" recogio "+strCant+" unidades de mineral y duro "+strDuracion+" segundos"<<endl;
                  mineralesDelJugador+=lisPuertas->find(minaElegida)->getArbol()->getRoot()->getCantidad();
                  break;
                  
               }else{
                  cout<<"Esta puerta no tiene mina, mala suerte"<<endl;
                  break;
               }
            }
         }
   }
   string strCant = to_string(mineralesDelJugador);
   cout<<"El jugador hizo "+ strCant+" puntos en esta jugada"<<endl;
   return mineralesDelJugador;
}

int main() {
   int cantidadDePuertas=15;
   
   List<Puerta> *lisPuertas = new List<Puerta>;
   for (int i = 0; i <= cantidadDePuertas; i++){
      lisPuertas->add(new Puerta(i));
   }

   //Agregar puertas a otras
   agregarPuerta(lisPuertas, 0, 2);
   agregarPuerta(lisPuertas, 0, 1);
   agregarPuerta(lisPuertas, 0, 12);
   agregarPuerta(lisPuertas, 0, 8);
   agregarPuerta(lisPuertas, 0, 11);
   agregarPuerta(lisPuertas, 1, 4);
   agregarPuerta(lisPuertas, 2, 6);
   agregarPuerta(lisPuertas, 6, 2);
   agregarPuerta(lisPuertas, 7, 2);
   agregarPuerta(lisPuertas, 8, 5);
   agregarPuerta(lisPuertas, 0, 4); //validacion de las 4 puertas maximo
   agregarPuerta(lisPuertas, 12, 6);
   agregarPuerta(lisPuertas, 5, 10);
   agregarPuerta(lisPuertas, 10, 9);
   
   //Crear arboles (tuneles y camaras)
   for (int j = 0; j < 10; j++){
      //int i = 0;
      int i ;
      i = 1 + rand()%(cantidadDePuertas+1-1);
      int cantMinerales = 1 + rand()%(20+1-1);
      int distancia = 10 + rand()%(80+1-10);
      int potencialMinado = cantMinerales * distancia;
      TreeNode * newNode = new TreeNode();
      newNode -> setValue(potencialMinado);
      lisPuertas->find(i)->getArbol()->setRoot(lisPuertas->find(i)->getArbol()->insert(lisPuertas->find(i)->getArbol()->getRoot(),newNode,distancia,cantMinerales)); 
      
      
   }
   
   int puntosDelJugador1 = 0;
   puntosDelJugador1 += recorrerLaMina(lisPuertas,1,1,5);
   puntosDelJugador1 += recorrerLaMina(lisPuertas,2,1,5);
   puntosDelJugador1 += recorrerLaMina(lisPuertas,1,2,5);
   string strCant1 = to_string(puntosDelJugador1);
   cout<<"***El JUGADOR 1 hizo "+strCant1+" puntos"<<endl;


   int puntosDelJugador2 = 0;
   puntosDelJugador2 += recorrerLaMina(lisPuertas,1,2,12);
   puntosDelJugador2 += recorrerLaMina(lisPuertas,2,1,12);
   puntosDelJugador2 += recorrerLaMina(lisPuertas,2,2,12);
   string strCant2 = to_string(puntosDelJugador2);
   cout<<"***El JUGADOR 2 hizo "+strCant2+" puntos"<<endl;
   
   if(puntosDelJugador1>puntosDelJugador2){
      cout<<"El jugador 1 ha ganado"<<endl;
   }else if (puntosDelJugador1<puntosDelJugador2){
      cout<<"El jugador 2 ha ganado"<<endl;
   }else{
      cout<<"Es un empate"<<endl;
   }
   

   
   
}