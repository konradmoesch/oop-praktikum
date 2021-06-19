#include "CTrieEnc.hpp"
#include <iostream>

CTrieEnc::CTrieEnc(){
	//std::cout <<"CArrayEnc()"<<std::endl;
	for(int index=0; index<256; index++){
			m_symbolTable[index].setSymbol(intToString(index));
			m_symbolTable[index].setParent(-1);
			//-2 wird standardmäßig für alle Elemente gesetzt (siehe CKnot)
			//std::cout<<index<<": "<<intToString(index)<<std::endl;
	}
}

void CTrieEnc::debugTrieOutput(){
	std::cout << "--- aktueller Stand des Dictionary: ---" << std::endl;
	int index = 256;
	while (m_symbolTable[index].getSymbol() != ""){
		std::cout << index << " | " << m_symbolTable[index].getSymbol() << std::endl;
		index++;
	}
}

void debugOutputVector(vector<unsigned int> vec){
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

bool getValuesEqual(CKnot table[], int pos, int parent, string val){
	//cout << "Verleiche: I=" << val << "(" << table[pos].getSymbol() << ")" << ", parent: " << parent << "("<< table[pos].getParent() << ")" <<endl;
	//cout << "Ausgabe der funct: " << (table[pos].getParent()==parent && table[pos].getSymbol()==val) << endl;
	return (table[pos].getParent()==parent && table[pos].getSymbol()==val);
}

vector<unsigned int> CTrieEnc::encode(const string& inputstr){
	//Wenn Eingabe leer, beenden
	if (inputstr=="") return {};

	//Variablen initialisieren
	std::cout << "String: " << inputstr << std::endl;
	string curstr = "";
	string extstr = "";
	//Elternposition: I, Numer. ASCII Wert f akt Zeichen: J
	int I = 0;
	int J = 0;
	//Hashing-Singleton
	CDoubleHashing& hasher = CDoubleHashing::getInstance();
	//Versuchs-Zähler für Rehashing
	CForwardCounter attemptCounter;
	//Ausgabeverktor für encodete Zeichenkette
	vector <unsigned int> encoded = {};

	//Erstes Zeichen blind einlesen
	std::string::const_iterator initialiter = inputstr.begin();
	I=charToInt(*initialiter);
	//encoded.push_back(charToInt(*initialiter));
	initialiter++;

	//durch alle Zeichen iterieren
	for (std::string::const_iterator iter=initialiter; iter != inputstr.end(); iter++){
		//Neues Zeichen in J eingelesen
		J = charToInt(*iter);
		cout << "Zeichen " << *iter << " mit Wert " << J << ": " << endl;;

		//Rehashing soll bei Versuch 0 beginnen
		attemptCounter.setValue(0);
		//Position bestimmen mittels Hashing
		cout << "Hashe (" << I <<  ", " << J << ", 0) ->";
		int position = hasher.hash(I, J, LZW_DICT_SIZE, 0);
		cout << position << endl;

		//wenn Position schon mit anderen Werten belegt (Kollision)
		if (!getValuesEqual(m_symbolTable, position, I, intToString(J))){
			//Wird auch ausgeführt, wenn unbelegt (parent=-2)
			//dann wird aber nicht die Schleife durchlaufen

			//neue Variable für Hashwert -> warum? Steht in der Aufgabenstellung
			//(Gegen Endlossschleife), aber es werden doch nur I und J sowie der Zähler benutzt
			int newPosition = position;
			//neu hashen, bis leeres Feld oder der Wert gefunden wurde
			while ((m_symbolTable[newPosition].getParent()!=-2) || (getValuesEqual(m_symbolTable, newPosition, I, intToString(J)))) {
				//todo: Remove hacky shit, negating above produces endless loop
				if (getValuesEqual(m_symbolTable, newPosition, I, intToString(J))) break;
				//Versuchszähler inkrementieren
				attemptCounter.count();
				//neu hashen (veränderter Zählerstand)
				newPosition = hasher.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());
				//Debug-Ausgabe
				cout << "Hashversuch " << attemptCounter.getValue() << ": berechnete Position für " << J << ": " << newPosition << ", parent hier: " << m_symbolTable[newPosition].getParent() << ", stimmen Werte überein? " << getValuesEqual(m_symbolTable, newPosition, I, intToString(J)) << endl;
			}
			//Wenn leeres Feld oder das Feld mit dem Wert gefunden wurde,
			//neue Position übernehmen
			position=newPosition;
		}

		//prüfen ob auf leeren Knoten gestoßen
		if (m_symbolTable[position].getParent()==-2 || m_symbolTable[position].getSymbol()==""){
			//Debug-Ausgabe
			cout << "leerer Knoten bei " << position << endl;
			//dann soll hier das aktuelle Zeichen gespeichert werden
			//und parent auf die erste Zeichenkette zeigen
			m_symbolTable[position].setParent(I);
			m_symbolTable[position].setSymbol(intToString(J));

			//I an den Ausgabevektor anhängen
			encoded.push_back(I);
			//I mit J überschreiben
			I = J;
			//neues Zeichen einlesen -> neuer Schleifendurchlauf?
		}

		//prüfen ob String schon vorhanden
		else if (getValuesEqual(m_symbolTable,position,I,intToString(J))){
			cout << "Schon bekannt, nehme Zeichen hinzu" << endl;
			//gerade ermittelte Position wird in I gespeichert
			I = position;
			//und ein neues Zeichen J eingelesen -> Schleifendurchlauf?
		}

		debugTrieOutput();
		debugOutputVector(encoded);

	}
	encoded.push_back(I);
	debugOutputVector(encoded);
	return encoded;
}
