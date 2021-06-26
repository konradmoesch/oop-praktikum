#include "CTrieDec.hpp"

//parameterloser Konstruktor; initialisiert Dictionary (mit ASCII-Alphabet)
CTrieDec::CTrieDec(){
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
			m_symbolTable[index].setParent(-1);
			//-2 wird standardmaeßig fuer alle Elemente gesetzt (siehe CKnot)
	}
}

//Funktion zum Vergleichen der Werte mit einem Knoten
//koennte in Enc und Dec gemeinsam genutzt werden, um Duplication zu vermeiden
bool getHashValuesEqual(CKnot table[], int pos, int parent, const string& val){
	return (table[pos].getParent()==parent && table[pos].getSymbol()==val);
}

//eigentliche Decodier-Funktion
string CTrieDec::decode(const vector<unsigned int>& encoded){
	//wenn Eingabevektor leer, brich ab
	if (encoded.empty()) {
		return "";
	}
	string decoded = "";

	//uA fuer Sonderfall (Eintrag noch nicht vollstaendig bekannt)
	int lastHashValue = 0;

	//Hashing-Singleton
	CDoubleHashing& hasher = CDoubleHashing::getInstance();
	//Versuchs-Zaehler fuer Rehashing
	CForwardCounter attemptCounter;

	//durch eingabevektor iterieren
	for (unsigned int curIndex=0; curIndex<encoded.size(); curIndex++){
		//aktuelles Zeichen decodieren
		string curDecoded = m_symbolTable[encoded[curIndex]].getSymbol();

		//wenn parent(s) vorhanden, diese zu curDecoded hinzufuegen (zsmbasteln)
		if (m_symbolTable[encoded[curIndex]].getParent()!=-2) {
			int index2 = m_symbolTable[encoded[curIndex]].getParent();
			string parentstr="";
			while (index2!=-1) {
				//so lange, wie Parents vorhanden
				//diese an den String anhaengen
				parentstr+=m_symbolTable[index2].getSymbol();
				index2=m_symbolTable[index2].getParent();
			}
			if (parentstr!="") {
				//anschließend String invertieren und an curDecoded anhaengen
				string tmpstr="";
				for (int l=parentstr.length(); l>0; l--) {
					tmpstr+=parentstr[l-1];
				}
				curDecoded=tmpstr+curDecoded;
			}
		}

		//dieser string soll nur aus dem ersten Zeichen bestehen,...
		string erstesZeichen = curDecoded;

		//Sondefallbehandlung, wenn noetig
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

		//... er wird hier gekuerzt
		erstesZeichen = erstesZeichen.substr(0,1);

		int position = encoded[curIndex];
		//nur wenn erstes Zeichen schon verarbeitet
		if (curIndex > 0) {
			//Dictionary-Eintrag Anlegen

			attemptCounter.setValue(0);
			position = hasher.hash(lastHashValue, charToInt(erstesZeichen[0]), LZW_DICT_SIZE, 0);
			//Rehashing
			//wenn Position schon mit anderen Werten belegt (Kollision)
			if (!getHashValuesEqual(m_symbolTable, position, lastHashValue, erstesZeichen)){
				//Wird auch ausgefuehrt, wenn unbelegt (parent=-2)
				//dann wird aber nicht die Schleife durchlaufen

				//neue Variable fuer Hashwert -> warum? Steht in der Aufgabenstellung
				//(Gegen Endlossschleife), aber es werden doch nur I und J sowie der Zaehler benutzt
				int newPosition = position;
				//neu hashen, bis leeres Feld oder der Wert gefunden wurde
				while ((m_symbolTable[newPosition].getParent()!=-2) || (getHashValuesEqual(m_symbolTable, newPosition, lastHashValue, erstesZeichen))) {
					//todo: Remove hacky shit, negating above produces endless loop
					if (getHashValuesEqual(m_symbolTable, newPosition, lastHashValue, intToString(encoded[curIndex]))) break;
					//Versuchszaehler inkrementieren
					attemptCounter.count();
					//neu hashen (veraenderter Zaehlerstand)
					newPosition = hasher.hash(lastHashValue, charToInt(erstesZeichen[0]), LZW_DICT_SIZE, attemptCounter.getValue());
				}
				//Wenn leeres Feld oder das Feld mit dem Wert gefunden wurde,
				//neue Position uebernehmen
				position=newPosition;
			}

			//Eintrag anlegen
			m_symbolTable[position].setSymbol(erstesZeichen);
			m_symbolTable[position].setParent(lastHashValue);

			lastHashValue=encoded[curIndex];

		} else {
			lastHashValue=encoded[curIndex];
		}

		//Sonderfallbehandlung
		if (sonderfall) {
			curDecoded = m_symbolTable[encoded[curIndex]].getSymbol();

			//wenn parent(s) vorhanden, diese zu curDecoded hinzufuegen (zsmbasteln)
			if (m_symbolTable[encoded[curIndex]].getParent()!=-2) {
				int index2 = m_symbolTable[encoded[curIndex]].getParent();
				string parentstr="";
				while (index2!=-1) {
					//so lange, wie Parents vorhanden
					//diese an den String anhaengen
					parentstr+=m_symbolTable[index2].getSymbol();
					index2=m_symbolTable[index2].getParent();
				}
				if (parentstr!="") {
					//anschließend String invertieren und an curDecoded anhaengen
					string tmpstr="";
					for (int l=parentstr.length(); l>0; l--) {
						tmpstr+=parentstr[l-1];
					}
					curDecoded=tmpstr+curDecoded;
				}
			}
		}

		//String an den decodierten Ausgabestring anhaengen
		decoded += curDecoded;
	}
	return decoded;
}
