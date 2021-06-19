#include "CArrayEnc.hpp"
#include <iostream>

#include <sstream>
#include <iterator>

CArrayEnc::CArrayEnc(){
	//std::cout <<"CArrayEnc()"<<std::endl;
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
			//std::cout<<index<<": "<<intToString(index)<<std::endl;
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

void CArrayEnc::debugOutput(){
	std::cout << "--- aktueller Stand des Dictionary: ---" << std::endl;
	int index = 256;
	while (m_symbolTable[index].getSymbol() != ""){
		std::cout << index << " | " << m_symbolTable[index].getSymbol() << std::endl;
		index++;
	}
}

void debugVector(vector<unsigned int> vec){
	std::ostringstream oss;

	  if (!vec.empty())
	  {
	    // Convert all but the last element to avoid a trailing ","
	    std::copy(vec.begin(), vec.end()-1,
	        std::ostream_iterator<int>(oss, ","));

	    // Now add the last element with no delimiter
	    oss << vec.back();
	  }

	  std::cout << oss.str() << std::endl;
}

vector<unsigned int> CArrayEnc::encode(const string& inputstr){
	//Wenn Eingabe leer, beenden
	if (inputstr=="") return {};
	//std::cout << "String: " << inputstr << std::endl;
	string curstr = "";
	string extstr = "";
	int num = 0;
	vector <unsigned int> encoded = {};

	//durch alle Zeichen iterieren
	for (std::string::const_iterator iter = inputstr.begin(); iter != inputstr.end(); iter++){
		extstr = curstr + *iter;
		//prüfen ob neue Zeichenkette in D
		if (searchInTable(extstr)!=-1){
			curstr = extstr;
			//neues Zeichen einlesen (for-Schleife inkrementiert)
		} else {
			encoded.push_back(searchInTable(curstr));
			//debugVector(encoded);
			m_symbolTable[256+num].setSymbol(extstr);
			num++;
			//debugOutput();
			curstr= *iter;
		}
	}
	encoded.push_back(searchInTable(curstr));
	//debugVector(encoded);
	return encoded;
}

