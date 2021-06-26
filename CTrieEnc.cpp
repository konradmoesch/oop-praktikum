#include "CTrieEnc.hpp"

CTrieEnc::CTrieEnc(){
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
			m_symbolTable[index].setParent(-1);
			//-2 wird standardmaeßig fuer alle Elemente gesetzt (siehe CKnot)
	}
}

bool getValuesEqual(CKnot table[], int pos, int parent, const string& val){
	return (table[pos].getParent()==parent && table[pos].getSymbol()==val);
}

vector<unsigned int> CTrieEnc::encode(const string& inputstr){
	//Wenn Eingabe leer, beenden
	if (inputstr=="") return {};

	//Elternposition: I, Numer. ASCII Wert fuer akt Zeichen: J
	int I = 0;
	//Hashing-Singleton
	CDoubleHashing& hasher = CDoubleHashing::getInstance();
	//Versuchs-Zaehler fuer Rehashing
	CForwardCounter attemptCounter;
	//Ausgabeverktor fuer encodete Zeichenkette
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
			//Wird auch ausgefuehrt, wenn unbelegt (parent=-2)
			//dann wird aber nicht die Schleife durchlaufen

			//neue Variable fuer Hashwert -> warum? Steht in der Aufgabenstellung
			//(Gegen Endlossschleife), aber es werden doch nur I und J sowie der Zaehler benutzt
			int newPosition = position;
			//neu hashen, bis leeres Feld oder der Wert gefunden wurde
			while ((m_symbolTable[newPosition].getParent()!=-2) || (getValuesEqual(m_symbolTable, newPosition, I, intToString(J)))) {
				//wenn Werte uebereinstimmen; Schleife abbrechen
				if (getValuesEqual(m_symbolTable, newPosition, I, intToString(J))) break;
				//Versuchszaehler inkrementieren
				attemptCounter.count();
				//neu hashen (veraenderter Zaehlerstand)
				newPosition = hasher.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());
			}
			//Wenn leeres Feld oder das Feld mit dem Wert gefunden wurde,
			//neue Position uebernehmen
			position=newPosition;
		}

		//pruefen ob auf leeren Knoten gestoßen
		if (m_symbolTable[position].getParent()==-2 || m_symbolTable[position].getSymbol()==""){
			//Debug-Ausgabe
			//dann soll hier das aktuelle Zeichen gespeichert werden
			//und parent auf die erste Zeichenkette zeigen
			m_symbolTable[position].setParent(I);
			m_symbolTable[position].setSymbol(intToString(J));

			//I an den Ausgabevektor anhaengen
			encoded.push_back(I);
			//I mit J ueberschreiben
			I = J;
			//neues Zeichen einlesen -> neuer Schleifendurchlauf?
		}

		//pruefen ob String schon vorhanden
		else if (getValuesEqual(m_symbolTable,position,I,intToString(J))){
			//gerade ermittelte Position wird in I gespeichert
			I = position;
			//und ein neues Zeichen J eingelesen -> Schleifendurchlauf?
		}
	}
	encoded.push_back(I);
	return encoded;
}
