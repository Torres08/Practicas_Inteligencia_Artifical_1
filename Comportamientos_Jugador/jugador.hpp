#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
      fil=col=99;
      brujula=0;
      ultimaAccion= actIDLE;
      girar_derecha=false;
      bien_situado=false;
      bikini = zapatillas = false;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Declarar aquí las variables de estado
  int fil,col,brujula;
  Action ultimaAccion;
  bool girar_derecha, bien_situado, bikini, zapatillas;
  char mapaAux[200][200]; // por si lo necesito

  // necesito variable para que gire aleatoriamente, cuando llegue a 0

  // funciones privadas 
  void ActualizarMapa(Sensores sensores);
  void Reiniciar();
  bool Avanzar(Sensores sensores);
  Action Girar(Sensores sensores);
};

#endif
