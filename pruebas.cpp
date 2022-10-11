#include "../../Lista Poli/List.h"
#include <string>
#include <iostream>
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

int main() {

   //map<tipollave, tipovalor> nombreDiccionario
   int cantidadDePuertas=15;
   //map <int, List<Puerta>> sisPuertas;
   
   List<Puerta> *lisPuertas = new List<Puerta>;
   for (int i = 0; i <= cantidadDePuertas; i++){
      lisPuertas->add(new Puerta(i));
   }

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
   /*
   for (int j = 0; j < 4; j++){
         while (lisPuertas->find(i)->getEntradas()>2){
         float probabilidad = rand() / static_cast<float>(RAND_MAX);
         if(probabilidad<=0.66){
            cout<<"Va con puerta"<<endl;
            //lisPuertas->find(i)->puertasAsociadas.
        }else{
            cout<<"No va con puerta"<<endl;
        }
      }
   }
   */
   /*
   for (int i = 0; i < cantidadDePuertas; i++){
      
      Puerta puerta = Puerta(i);
      while (puerta.getEntradas()>2){
         float probabilidad = rand() / static_cast<float>(RAND_MAX);
         if(probabilidad<=0.66){
            cout<<"Va con puerta"<<endl;
            puertas->add(new Puerta(i));
            sisPuertas.insert(pair<int, List<Puerta>> (i,*puertas));
            
        }else{
            cout<<"No va con puerta"<<endl;
        }
      }

   }
   
   for (int i = 0; i < cantidadDePuertas; i++){
      List<Puerta> *puertas = new List<Puerta>;
      sisPuertas.insert(pair<int, List<Puerta>> (i,*puertas));
   } 
   */
   
   
}