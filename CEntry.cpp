#include "CEntry.hpp"

//Initialisierung der statischen Variablen für die Anzahl der Instanzen
unsigned int CEntry::m_number = 0;

//parameterlose Konstruktor- und Destruktorfunktionen
//diese passen die Membervariable m_number für die Anzahl der Instanzen an
CEntry::CEntry(): m_symbol(""){m_number++;}
CEntry::~CEntry(){m_number--;}

//Getter für m_symbol
const string& CEntry::getSymbol() const {
	return CEntry::m_symbol;
}

//Setter für m_symbol
void CEntry::setSymbol(string symbol){
	m_symbol = symbol;
}

//Getter für Anzahl der Instanzen
unsigned int CEntry::getNumber(){
	return m_number;
}
