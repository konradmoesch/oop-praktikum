#include "CArrayDec.hpp"

//parameterloser Konstruktor; initialisiert das Dicitionary mit dem ASCII-Alphabet
CArrayDec::CArrayDec(){
	for(int index=0;index<256;index++){
			m_symbolTable[index].setSymbol(intToString(index));
	}
}

//Funktion zum Durchsuchen des Dictionarys nach einem gegebenen String
//string aus Performance-Gruenden als const reference Parameter
int CArrayDec::searchInTable(const string& searchstr){
	int position=-1;
	for (int index=0; index<LZW_DICT_SIZE; index++){
		if(m_symbolTable[index].getSymbol()==searchstr){
			position=index;
		}
	}
	//wenn nicht gefunden wird -1 zurueckgegeben
	return position;
}

//eigentliche Decodier-Funktion; restauriert einen String aus dem gegebenen Vektor
string CArrayDec::decode(const vector<unsigned int>& encoded){
	//bei leerem Vektor sofort abbrechen
	if (encoded.empty()) return "";

	string decoded = "";

	//Schleife iteriert durch die Elemente des Vektors
	for (unsigned int i=0; i<encoded.size(); i++){
		//curDecoded enthaelt das aktuell decodierte Element
		string curDecoded = m_symbolTable[encoded[i]].getSymbol();

		//Sonderfall: Index noch nicht vollstaendig bekannt;
		//dabei wird das erste Zeichen am Ende wiederholt
		if (encoded[i]==256+i-1) curDecoded += curDecoded[0];

		//einem neuen Eintrag den aktuell decodierten String hinzufuegen
		m_symbolTable[256+i].setSymbol(curDecoded);

		//fuer alle Vektorelemente außer dem ersten (Index=0):
		//an den in der letzten Runde erzeugten Eintrag das erste Zeichen des aktuell decodierten Strings anhaengen
		if (i){
			m_symbolTable[256+i-1].setSymbol(m_symbolTable[256+i-1].getSymbol()+curDecoded[0]);
		}

		//diesen aktuell decodierten String dem Ausgabestring hinzufuegen
		decoded += curDecoded;
	}
	return decoded;
}
