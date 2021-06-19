/*!
 * \file CTrieDec.hpp
 * \brief Klasse CTrieDec f�r Decodierung mittels Trie (Aufgabenteil 2)
 *
 * Dieses File enth�lt die Klasse CTrieDec, welche zur Decodierung mit Hilfe eines Tries in Aufgabe 2 benutzt wird.
 * \todo cpp aufr�umen; Ausgabe entfernen
 */
#ifndef CTRIEDEC_HPP_
#define CTRIEDEC_HPP_

#include "CDec.hpp"
#include "CKnot.hpp"
#include "CForwardCounter.hpp"
#include "CDoubleHashing.hpp"

//! \todo weg mit dem? nur Debug?
#include <sstream>
#include <iterator>

/*!
 * \class CTrieDec
 * \brief Klasse f�r den Decoder mit Trie (Aufgabe 2)
 *
 * Klasse f�r den Decoder mittels Trie.
 * CTrieDec erbt von CDec.
 */
class CTrieDec: public CDec {
private:
	CKnot m_symbolTable[LZW_DICT_SIZE]; //!< Private Membervariable f�r das Dictionary.

public:
	/*!
	 * parameterloser Konstruktor
	 */
	CTrieDec();
	/*!
	 * decodiert den Vektor mit Hilfe des LZW-Algorithmus
	 * es wird dabei ein Trie als Dictionary benutzt
	 * @param encoded	Vektor der zu decodierenden Indexwerte
	 * @return decodierter String
	 * @todo debugOutput entfernen!
	 */
	string decode(const vector<unsigned int>& encoded);
	void debugOutput(string);
};

#endif /* CTRIEDEC_HPP_ */
