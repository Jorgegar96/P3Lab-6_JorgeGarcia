#include "Normal.h"
#include <time.h>
#include <stdlib.h>
#include <typeinfo>
#include "Jugador.h"
#include "Obstaculo.h"
Normal:: Normal(int coord_x, int coord_y, char letra): Bomba(coord_x, coord_y, letra){
	srand(time(NULL));
	alcance = rand() % 4 + 1;
}

int Normal:: getAlcance(){
	return alcance;
}

void Normal:: explosion(Item*** mapa){
	int recorrido = 0;
	Jugador* jugador;
	for(int i=1; i <= alcance; i++){
		if (recorrido == 0){
			if(this->getX() + i < 11){
				if (typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()+i][this->getY()]) == typeid(Jugador)){
						jugador = dynamic_cast<Jugador*>(mapa[this->getX()+i][this->getY()]);
						jugador->perderVida();
					}
				}
			}
		}else if (recorrido == 1){
			if(this->getX() -i >= 0){
				if (typeid(*mapa[this->getX()-i][this->getY()]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()-i][this->getY()]) == typeid(Jugador)){
						dynamic_cast<Jugador*>(mapa[this->getX()-i][this->getY()]);
						jugador->perderVida();
					}
				}
			}
		}else if (recorrido == 2){
			if (this->getY() -i >= 0){
				if (typeid(*mapa[this->getX()][this->getY()-i]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()][this->getY()-i]) == typeid(Jugador)){
						dynamic_cast<Jugador*>(mapa[this->getX()][this->getY()-i]);
						jugador->perderVida();
					}
				}
			}
		}else if (recorrido == 3){
			if (this->getY() +i < 13){
				if (typeid(*mapa[this->getX()+i][this->getY()+i]) == typeid(Obstaculo) ){
					i = 1;
					recorrido++;
				}else{
					if (typeid(*mapa[this->getX()][this->getY()+i]) == typeid(Jugador)){
						dynamic_cast<Jugador*>(mapa[this->getX()][this->getY()+i]);
					}
				}
			}
		}
		if (i == alcance){
			recorrido++;
		}
	}	
}

Normal:: ~Normal(){

}
