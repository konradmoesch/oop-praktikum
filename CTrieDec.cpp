#include "CTrieDec.hpp"
#include <iostream>


CTrieDec::CTrieDec(){
	//std::cout <<"CArrayDec()"<<std::endl;
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
			m_symbolTable[index].setParent(-1);
			//-2 wird standardmäßig für alle Elemente gesetzt (siehe CKnot)
			//std::cout<<index<<": "<<intToString(index)<<std::endl;
	}
}

bool getHashValuesEqual(CKnot table[], int pos, int parent, string val){
	//cout << "Verleiche: I=" << val << "(" << table[pos].getSymbol() << ")" << ", parent: " << parent << "("<< table[pos].getParent() << ")" <<endl;
	//cout << "Ausgabe der funct: " << (table[pos].getParent()==parent && table[pos].getSymbol()==val) << endl;
	return (table[pos].getParent()==parent && table[pos].getSymbol()==val);
}

void debugTrieDict(vector<unsigned int> vec){
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

void CTrieDec::debugOutput(string decoded){
	std::cout << "--- aktueller Stand des Dictionary: ---" << std::endl;
	int index = 256;
	while (m_symbolTable[index].getSymbol() != ""){
		std::cout << index << " | " << m_symbolTable[index].getSymbol() << std::endl;
		index++;
	}
	std::cout << "---> aktuelle Ausgabe: " << decoded << std::endl;
}

string CTrieDec::decode(const vector<unsigned int>& encoded){
	//wenn Eingabevektor leer, brich ab
	if (encoded.empty()) {
		return "";
	}
	string decoded = "";
	string curDecoded = "";

	int lastHashValue=0;

	//Hashing-Singleton
	CDoubleHashing& hasher = CDoubleHashing::getInstance();
	//Versuchs-Zähler für Rehashing
	CForwardCounter attemptCounter;

	//durch eingabevektor iterieren
	for (unsigned int curIndex=0; curIndex<encoded.size(); curIndex++){
		//aktuelles Zeichen decodieren
		curDecoded = m_symbolTable[encoded[curIndex]].getSymbol();
		cout << encoded[curIndex] << "=" << curDecoded <<endl;

		//wenn parent(s) vorhanden, diese zu curDecoded hinzufügen (zsmbasteln)
		if (m_symbolTable[encoded[curIndex]].getParent()!=-2) {
			int index2 = m_symbolTable[encoded[curIndex]].getParent();
			//cout << "nicht leer (" << index2 << ")"<<endl;
			string parentstr="";
			while (index2!=-1) {
				parentstr+=m_symbolTable[index2].getSymbol();
				//cout << m_symbolTable[index2].getSymbol() << " angehaengt"<<endl;
				index2=m_symbolTable[index2].getParent();
				//cout << index2 << "ist parent"<<endl;
			}
			//cout << endl << parentstr << endl << "Length: " <<parentstr.length() <<endl;
			if (parentstr!="") {
					//reverse String, append to curDecoded
				string tmpstr="";
				//cout << "reversing" << endl;
				for (int l=parentstr.length(); l>0; l--) {
					//cout << parentstr[l-1]<< ",";
					tmpstr+=parentstr[l-1];
				}
				curDecoded=tmpstr+curDecoded;
				//cout << endl;
			}
		}

		cout << "curDecoded ist jetzt " << curDecoded << endl << endl;
		string erstesZeichen = curDecoded;

		//todo: Sonderfall
		bool sonderfall = false;
		if(m_symbolTable[encoded[curIndex]].getParent()==-2) {
			sonderfall = true;
			cout << "Sonderfall" << endl;
			//erstes Zeichen des letzten Strings bekommen
			int index=lastHashValue;
			while (m_symbolTable[index].getParent()!=-1){
				index=m_symbolTable[index].getParent();
			}
			erstesZeichen=m_symbolTable[index].getSymbol();
		}

		erstesZeichen = erstesZeichen.substr(0,1);

		int position = encoded[curIndex];
		if (curIndex > 0) {
			//Dictionary-Eintrag Anlegen
			cout << "Lege Eintrag an,hashe" << endl;

			attemptCounter.setValue(0);
			cout << lastHashValue << "," << charToInt(erstesZeichen[0]) << endl;
			position = hasher.hash(lastHashValue, charToInt(erstesZeichen[0]), LZW_DICT_SIZE, 0);
			//Rehashing
			//wenn Position schon mit anderen Werten belegt (Kollision)
			if (!getHashValuesEqual(m_symbolTable, position, lastHashValue, erstesZeichen)){
				//Wird auch ausgeführt, wenn unbelegt (parent=-2)
				//dann wird aber nicht die Schleife durchlaufen

				//neue Variable für Hashwert -> warum? Steht in der Aufgabenstellung
				//(Gegen Endlossschleife), aber es werden doch nur I und J sowie der Zähler benutzt
				int newPosition = position;
				//neu hashen, bis leeres Feld oder der Wert gefunden wurde
				while ((m_symbolTable[newPosition].getParent()!=-2) || (getHashValuesEqual(m_symbolTable, newPosition, lastHashValue, erstesZeichen))) {
					//todo: Remove hacky shit, negating above produces endless loop
					if (getHashValuesEqual(m_symbolTable, newPosition, lastHashValue, intToString(encoded[curIndex]))) break;
					//Versuchszähler inkrementieren
					attemptCounter.count();
					//neu hashen (veränderter Zählerstand)
					newPosition = hasher.hash(lastHashValue, charToInt(erstesZeichen[0]), LZW_DICT_SIZE, attemptCounter.getValue());
					//Debug-Ausgabe
					cout << "Hashversuch " << attemptCounter.getValue() << ": berechnete Position für " << erstesZeichen << ": " << newPosition << ", parent hier: " << m_symbolTable[newPosition].getParent() << ", stimmen Werte überein? " <<
							getHashValuesEqual(m_symbolTable, newPosition, lastHashValue, erstesZeichen) << endl;
				}
				//Wenn leeres Feld oder das Feld mit dem Wert gefunden wurde,
				//neue Position übernehmen
				position=newPosition;
				cout << lastHashValue << "," << erstesZeichen <<"=" << position << endl;
			}

			m_symbolTable[position].setSymbol(erstesZeichen);
			m_symbolTable[position].setParent(lastHashValue);

			lastHashValue=encoded[curIndex];

		} else {
			lastHashValue=encoded[curIndex];
		}

		//lastHashValue=charToInt(erstesZeichen[0]);
		//lastHashValue=encoded[curIndex-1];

		if (sonderfall) {
			cout << "Sonderfall: ";
			curDecoded = m_symbolTable[encoded[curIndex]].getSymbol();

			//wenn parent(s) vorhanden, diese zu curDecoded hinzufügen (zsmbasteln)
			if (m_symbolTable[encoded[curIndex]].getParent()!=-2) {
				int index2 = m_symbolTable[encoded[curIndex]].getParent();
				//cout << "nicht leer (" << index2 << ")"<<endl;
				string parentstr="";
				while (index2!=-1) {
					parentstr+=m_symbolTable[index2].getSymbol();
					//cout << m_symbolTable[index2].getSymbol() << " angehaengt"<<endl;
					index2=m_symbolTable[index2].getParent();
					//cout << index2 << "ist parent"<<endl;
				}
				//cout << endl << parentstr << endl << "Length: " <<parentstr.length() <<endl;
				if (parentstr!="") {
						//reverse String, append to curDecoded
					string tmpstr="";
					//cout << "reversing" << endl;
					for (int l=parentstr.length(); l>0; l--) {
						//cout << parentstr[l-1]<< ",";
						tmpstr+=parentstr[l-1];
					}
					curDecoded=tmpstr+curDecoded;
					//cout << endl;
				}
			}
			cout << curDecoded << endl;
		}

		decoded += curDecoded;
		debugOutput(decoded);
		debugTrieDict(encoded);
	}
	return decoded;
}
