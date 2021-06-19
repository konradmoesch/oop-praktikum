#include "CArrayDec.hpp"
#include <iostream>


CArrayDec::CArrayDec(){
	//std::cout <<"CArrayDec()"<<std::endl;
	for(int index=0;index<256;index++){
			m_symbolTable[index].setSymbol(intToString(index));
			//std::cout<<i<<": "<<intToString(i)<<std::endl;
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

void CArrayDec::debugOutput(string decoded){
	std::cout << "--- aktueller Stand des Dictionary: ---" << std::endl;
	int index = 256;
	while (m_symbolTable[index].getSymbol() != ""){
		std::cout << index << " | " << m_symbolTable[index].getSymbol() << std::endl;
		index++;
	}
	std::cout << "---> aktuelle Ausgabe: " << decoded << std::endl;
}

string CArrayDec::decode(const vector<unsigned int>& encoded){
	if (encoded.empty()) {
		return "";
	}
	string decoded = "";
	string curDecoded = "";
	int num = 0;
	//todo i nutzen?
	for (unsigned int i=0; i<encoded.size(); i++){
		curDecoded = m_symbolTable[encoded[i]].getSymbol();

		//Sonderfall: Index noch nicht vollständig bekannt
		if (encoded[i]==256+i-1) curDecoded += curDecoded[0];

		m_symbolTable[256+num].setSymbol(curDecoded);
		if (num>0){
			m_symbolTable[256+num-1].setSymbol(m_symbolTable[256+num-1].getSymbol()+curDecoded[0]);
		}
		num++;

		decoded += curDecoded;
	}
	return decoded;
}
