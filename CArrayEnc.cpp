#include "CArrayEnc.hpp"

CArrayEnc::CArrayEnc(){
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
	}
}

int CArrayEnc::searchInTable(const string& searchstr){
	int position=-1;
	for (int index=0; index<LZW_DICT_SIZE; index++){
		if(m_symbolTable[index].getSymbol()==searchstr){
			position=index;
		}
	}
	return position;
}

vector<unsigned int> CArrayEnc::encode(const string& inputstr){
	//Wenn Eingabe leer, beenden
	if (inputstr=="") return {};
	string curstr = "";
	int num = 0;
	vector <unsigned int> encoded = {};

	//durch alle Zeichen iterieren
	for (std::string::const_iterator iter = inputstr.begin(); iter != inputstr.end(); ++iter){
		string extstr = curstr + *iter;
		//prüfen ob neue Zeichenkette in D
		if (searchInTable(extstr)!=-1){
			curstr = extstr;
			//neues Zeichen einlesen (for-Schleife inkrementiert)
		} else {
			encoded.push_back(searchInTable(curstr));
			m_symbolTable[256+num].setSymbol(extstr);
			num++;
			curstr= *iter;
		}
	}
	encoded.push_back(searchInTable(curstr));
	return encoded;
}

