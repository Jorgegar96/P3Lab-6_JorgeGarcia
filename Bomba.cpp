#include "Bomba.h"

Bomba:: Bomba(int coord_x, int coord_y, char letra): Item(coord_x, coord_y, letra){
	turno_explotar = 3;
}

void Bomba:: reduceTurno(){
	turno_explotar--;
}

int Bomba:: getTurno(){
	return turno_explotar;
}

Bomba:: ~Bomba(){

}
