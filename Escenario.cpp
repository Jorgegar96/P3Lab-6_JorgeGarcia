#include "Escenario.h"
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

Escenario:: Escenario(string name){
	this->name = name;	
}

string Escenario:: getName(){
	return name;
}

Item*** Escenario:: getMapa(){
	return map;
}

vector<Bomba*> Escenario:: getBombas(){
	return bombas;
}	

void Escenario:: reducirConteo(){
	for (int i=0; i < bombas.size(); i++){
		bombas.at(i)->reduceTurno();
		if (bombas.at(i)->getTurno() == 0){
			explosion(bombas.at(i));
			delete bombas.at(i);
			bombas.at(i) = NULL;
			bombas.erase(bombas.begin() + i);
		}
	}
}

void Escenario:: explosion(Bomba* bomb){
	//if (dynamic_cast<>)
}

void Escenario:: addBomb(Bomba* bomb){
	bombas.push_back(bomb);
}

//Escenario:: ~Escenario(){

//}
