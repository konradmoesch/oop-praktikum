#include "CTrieDec.hpp"


CTrieDec::CTrieDec(){
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
			m_symbolTable[index].setParent(-1);
			//-2 wird standardmäßig für alle Elemente gesetzt (siehe CKnot)
	}
}

//Funktion zum Vergleichen der Werte mit einem Knoten
//könnte in Enc und Dec gemeinsam genutzt werden, um Duplication zu vermeiden
bool getHashValuesEqual(CKnot table[], int pos, int parent, const string& val){
	return (table[pos].getParent()==parent && table[pos].getSymbol()==val);
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

		//wenn parent(s) vorhanden, diese zu curDecoded hinzufügen (zsmbasteln)
		if (m_symbolTable[encoded[curIndex]].getParent()!=-2) {
			int index2 = m_symbolTable[encoded[curIndex]].getParent();
			string parentstr="";
			while (index2!=-1) {
				parentstr+=m_symbolTable[index2].getSymbol();
				index2=m_symbolTable[index2].getParent();
			}
			if (parentstr!="") {
					//reverse String, append to curDecoded
				string tmpstr="";
				for (int l=parentstr.length(); l>0; l--) {
					tmpstr+=parentstr[l-1];
				}
				curDecoded=tmpstr+curDecoded;
			}
		}

		string erstesZeichen = curDecoded;

		bool sonderfall = false;
		if(m_symbolTable[encoded[curIndex]].getParent()==-2) {
			sonderfall = true;
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

			attemptCounter.setValue(0);
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
				}
				//Wenn leeres Feld oder das Feld mit dem Wert gefunden wurde,
				//neue Position übernehmen
				position=newPosition;
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
			//todo: mit oben zusammenfügen
			curDecoded = m_symbolTable[encoded[curIndex]].getSymbol();

			//wenn parent(s) vorhanden, diese zu curDecoded hinzufügen (zsmbasteln)
			if (m_symbolTable[encoded[curIndex]].getParent()!=-2) {
				int index2 = m_symbolTable[encoded[curIndex]].getParent();
				string parentstr="";
				while (index2!=-1) {
					parentstr+=m_symbolTable[index2].getSymbol();
					index2=m_symbolTable[index2].getParent();
				}
				if (parentstr!="") {
						//reverse String, append to curDecoded
					string tmpstr="";
					for (int l=parentstr.length(); l>0; l--) {
						tmpstr+=parentstr[l-1];
					}
					curDecoded=tmpstr+curDecoded;
				}
			}
		}

		decoded += curDecoded;
	}
	return decoded;
}
