#include <iostream>
#include <string>
#include "Escenario.h"
#include "Jugador.h"
#include "Item.h"
#include "Obstaculo.h"
#include "Bomba.h"
#include "Normal.h"
#include "Espina.h"
#include "V.h"
#include "Invisible.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
	Escenario* e = new Invisible("s");
	dynamic_cast<Invisible*>(e)->imprimirMapa();
	return 0;
}
