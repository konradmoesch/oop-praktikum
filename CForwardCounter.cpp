#include "CForwardCounter.hpp"

//�berladene Funktion count() von CCounter
//inkrementiert den Z�hlerstand um 1
void CForwardCounter::count(){
	setValue(getValue()+1);
}


