#include "CTrieEnc.hpp"

CTrieEnc::CTrieEnc(){
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
			m_symbolTable[index].setParent(-1);
			//-2 wird standardm��ig f�r alle Elemente gesetzt (siehe CKnot)
	}
}

bool getValuesEqual(CKnot table[], int pos, int parent, const string& val){
	return (table[pos].getParent()==parent && table[pos].getSymbol()==val);
}

vector<unsigned int> CTrieEnc::encode(const string& inputstr){
	//Wenn Eingabe leer, beenden
	if (inputstr=="") return {};

	//Elternposition: I, Numer. ASCII Wert f�r akt Zeichen: J
	int I = 0;
	//Hashing-Singleton
	CDoubleHashing& hasher = CDoubleHashing::getInstance();
	//Versuchs-Z�hler f�r Rehashing
	CForwardCounter attemptCounter;
	//Ausgabeverktor f�r encodete Zeichenkette
	vector <unsigned int> encoded = {};

	//Erstes Zeichen blind einlesen
	std::string::const_iterator initialiter = inputstr.begin();
	I=charToInt(*initialiter);
	//encoded.push_back(charToInt(*initialiter));
	++initialiter;

	//durch alle Zeichen iterieren
	for (std::string::const_iterator iter=initialiter; iter != inputstr.end(); ++iter){
		//Neues Zeichen in J eingelesen
		int J = charToInt(*iter);

		//Rehashing soll bei Versuch 0 beginnen
		attemptCounter.setValue(0);
		//Position bestimmen mittels Hashing
		int position = hasher.hash(I, J, LZW_DICT_SIZE, 0);

		//wenn Position schon mit anderen Werten belegt (Kollision)
		if (!getValuesEqual(m_symbolTable, position, I, intToString(J))){
			//Wird auch ausgef�hrt, wenn unbelegt (parent=-2)
			//dann wird aber nicht die Schleife durchlaufen

			//neue Variable f�r Hashwert -> warum? Steht in der Aufgabenstellung
			//(Gegen Endlossschleife), aber es werden doch nur I und J sowie der Z�hler benutzt
			int newPosition = position;
			//neu hashen, bis leeres Feld oder der Wert gefunden wurde
			while ((m_symbolTable[newPosition].getParent()!=-2) || (getValuesEqual(m_symbolTable, newPosition, I, intToString(J)))) {
				//todo: Remove hacky shit, negating above produces endless loop
				if (getValuesEqual(m_symbolTable, newPosition, I, intToString(J))) break;
				//Versuchsz�hler inkrementieren
				attemptCounter.count();
				//neu hashen (ver�nderter Z�hlerstand)
				newPosition = hasher.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());
				//Debug-Ausgabe
			}
			//Wenn leeres Feld oder das Feld mit dem Wert gefunden wurde,
			//neue Position �bernehmen
			position=newPosition;
		}

		//pr�fen ob auf leeren Knoten gesto�en
		if (m_symbolTable[position].getParent()==-2 || m_symbolTable[position].getSymbol()==""){
			//Debug-Ausgabe
			//dann soll hier das aktuelle Zeichen gespeichert werden
			//und parent auf die erste Zeichenkette zeigen
			m_symbolTable[position].setParent(I);
			m_symbolTable[position].setSymbol(intToString(J));

			//I an den Ausgabevektor anh�ngen
			encoded.push_back(I);
			//I mit J �berschreiben
			I = J;
			//neues Zeichen einlesen -> neuer Schleifendurchlauf?
		}

		//pr�fen ob String schon vorhanden
		else if (getValuesEqual(m_symbolTable,position,I,intToString(J))){
			//gerade ermittelte Position wird in I gespeichert
			I = position;
			//und ein neues Zeichen J eingelesen -> Schleifendurchlauf?
		}
	}
	encoded.push_back(I);
	return encoded;
}
