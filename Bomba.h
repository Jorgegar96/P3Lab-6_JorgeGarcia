#ifndef BOMBA_H
#define BOMBA_H
#include "Item.h"
class Bomba: public Item{

	private: 
		int turno_explotar;

	public:
		Bomba(int, int, char);
		virtual int getTurno();
		void reduceTurno();
		~Bomba();
};

#endif
