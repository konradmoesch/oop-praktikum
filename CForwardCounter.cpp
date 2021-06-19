#include "CForwardCounter.hpp"

//Überladene Funktion count() von CCounter
//inkrementiert den Zählerstand um 1
void CForwardCounter::count(){
	setValue(getValue()+1);
}


