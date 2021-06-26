#include "CForwardCounter.hpp"

//Ueberladene Funktion count() von CCounter
//inkrementiert den Zaehlerstand um 1
void CForwardCounter::count(){
	setValue(getValue()+1);
}
