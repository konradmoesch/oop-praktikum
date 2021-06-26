#include "CArrayEnc.hpp"

//parameterloser Konstruktor; initialisiert Dictionary mit ASCII-Alphabet
CArrayEnc::CArrayEnc(){
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
	}
}

//Funktion zum Durchsuchen des Dictionarys nach einem gegebenen String
//string aus Performance-Gruenden als const reference Parameter
int CArrayEnc::searchInTable(const string& searchstr){
	int position=-1;
	for (int index=0; index<LZW_DICT_SIZE; index++){
		if(m_symbolTable[index].getSymbol()==searchstr){
			position=index;
		}
	}
	//wenn nicht gefunden wird -1 zurueckgegeben
	return position;
}

//eigentliche Encodier-Funktion; codiert einen gegebenen String als Vektor
vector<unsigned int> CArrayEnc::encode(const string& inputstr){
	//Wenn Eingabe leer, beenden
	if (inputstr=="") return {};

	//Variablen
	string curstr = "";
	//Anzahl der neu angelegten Eintraege im Dictionary
	int num = 0;
	vector <unsigned int> encoded = {};

	//durch alle Zeichen iterieren
	for (std::string::const_iterator iter = inputstr.begin(); iter != inputstr.end(); ++iter){
		string extstr = curstr + *iter;
		//pruefen ob neue Zeichenkette in Dictionary schon enthalten
		if (searchInTable(extstr)!=-1){
			curstr = extstr;
			//neues Zeichen einlesen (for-Schleife inkrementiert)
		} else {
			//den Index des nicht-erweiterten Strings an den Ausgabevektor anhaengen
			encoded.push_back(searchInTable(curstr));
			//neuen Eintrag fuer den erweiterten String anlegen
			m_symbolTable[256+num].setSymbol(extstr);
			num++;
			curstr = *iter;
		}
	}
	//zuletzt den letzten curstr wieder anhaengen
	encoded.push_back(searchInTable(curstr));
	//und den Vektor zurueckgeben
	return encoded;
}
