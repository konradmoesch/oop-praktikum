/*!
 * \file CArrayEnc.hpp
 * \brief Klasse CArrayEnc f�r Encodierung mittels CArray (Aufgabenteil 1)
 *
 * Dieses File enth�lt die Klasse CArrayEnc, welche zur Encodierung mit Hilfe der Liste (CArray) in Aufgabe 1 benutzt wird.
 * \todo cpp aufr�umen
 */
#ifndef CARRAYENC_HPP_
#define CARRAYENC_HPP_

#include "CEnc.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"

/*!
 * \class CArrayEnc
 * \brief Klasse f�r den Encoder mit CArray (Aufgabe 1)
 *
 * Klasse f�r den Encoder mittels Liste.
 * CArrayEnc erbt von CEnc.
 */
class CArrayEnc: public CEnc {
private:
	CArray<CEntry, LZW_DICT_SIZE> m_symbolTable; //!< Private Membervariable f�r das Dictionary.

public:
	/*!
	 * parameterloser Konstruktor
	 */
	CArrayEnc();
	/*!
	 * Funktion zum Durchsuchen der Dictionary-Liste
	 * @param searchstr	zu suchender String
	 * @return Index (Adresse) des gesuchten Strings, wenn vorhanden. Sonst -1
	 */
	int searchInTable(const string& searchstr);
	/*!
	 * encodiert den String mit Hilfe des LZW-Algorithmus
	 * es wird dabei eine Liste (CArray) als Dictionary benutzt
	 * @param inputstr	zu codierender String
	 * @return encodeter Vektor
	 * @todo debugOutput entfernen!
	 */
	vector<unsigned int> encode(const string& inputstr);
};

#endif /* CARRAYENC_HPP_ */
