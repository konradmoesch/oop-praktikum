#include "CArrayDec.hpp"

CArrayDec::CArrayDec(){
	for(int index=0;index<256;index++){
			m_symbolTable[index].setSymbol(intToString(index));
	}
}

int CArrayDec::searchInTable(const string& searchstr){
	int position=-1;
	for (int index=0; index<LZW_DICT_SIZE; index++){
		if(m_symbolTable[index].getSymbol()==searchstr){
			position=index;
		}
	}
	return position;
}

string CArrayDec::decode(const vector<unsigned int>& encoded){
	if (encoded.empty()) {
		return "";
	}
	string decoded = "";

	for (unsigned int i=0; i<encoded.size(); i++){
		string curDecoded = "";
		curDecoded = m_symbolTable[encoded[i]].getSymbol();

		//Sonderfall: Index noch nicht vollständig bekannt
		if (encoded[i]==256+i-1) curDecoded += curDecoded[0];

		m_symbolTable[256+i].setSymbol(curDecoded);
		if (i){
			m_symbolTable[256+i-1].setSymbol(m_symbolTable[256+i-1].getSymbol()+curDecoded[0]);
		}

		decoded += curDecoded;
	}
	return decoded;
}
