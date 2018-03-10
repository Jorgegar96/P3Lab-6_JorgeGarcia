#include <string>
#include <vector>
#include "Item.h"
#ifndef ESCENARIO_H
#define ESCENARIO_H
using namespace std;

class Escenario{
	private:
		string name;
		vector<Bomba*> bombas;

	public:
		
		Escenario(string);
		virtual string getName();
		Item*** getMapa();
		vector<Bomba*> getBombas();
		void reducirConteo();
		void explosion(Bomba*);
		void addBomb(Bomba*);
		Item*** map;
};

#endif
