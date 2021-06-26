/*!
 * \file CArrayDec.hpp
 * \brief Klasse CArrayDec fuer Decodierung mittels CArray (Aufgabenteil 1)
 *
 * Dieses File enthaelt die Klasse CArrayDec, welche zur Decodierung mit Hilfe der Liste (CArray) in Aufgabe 1 benutzt wird.
 */
#ifndef CARRAYDEC_HPP_
#define CARRAYDEC_HPP_

#include "CDec.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"

/*!
 * \class CArrayDec
 * \brief Klasse fuer den Decoder mit CArray (Aufgabe 1)
 *
 * Klasse fuer den Decoder mittels Liste.
 * CArrayDec erbt von CDec.
 */
class CArrayDec: public CDec {
private:
	CArray<CEntry, LZW_DICT_SIZE> m_symbolTable; //!< Private Membervariable fuer das Dictionary.

public:
	/*!
	 * parameterloser Konstruktor
	 */
	CArrayDec();
	/*!
	 * Funktion zum Durchsuchen der Dictionary-Liste
	 * @param searchstr	zu suchender String
	 * @return Index (Adresse) des gesuchten Strings, wenn vorhanden. Sonst -1
	 */
	int searchInTable(const string &searchstr);
	/*!
	 * decodiert den Vektor mit Hilfe des LZW-Algorithmus
	 * es wird dabei eine Liste (CArray) als Dictionary benutzt
	 * @param encoded	Vektor der zu decodierenden Indexwerte
	 * @return decodierter String
	 */
	string decode(const vector<unsigned int> &encoded);
};

#endif /* CARRAYDEC_HPP_ */
