/*!
 * \file CTrieDec.hpp
 * \brief Klasse CTrieDec fuer Decodierung mittels Trie (Aufgabenteil 2)
 *
 * Dieses File enthaelt die Klasse CTrieDec, welche zur Decodierung mit Hilfe eines Tries in Aufgabe 2 benutzt wird.
 */
#ifndef CTRIEDEC_HPP_
#define CTRIEDEC_HPP_

#include "CDec.hpp"
#include "CKnot.hpp"
#include "CForwardCounter.hpp"
#include "CDoubleHashing.hpp"

/*!
 * \class CTrieDec
 * \brief Klasse fuer den Decoder mit Trie (Aufgabe 2)
 *
 * Klasse fuer den Decoder mittels Trie.
 * CTrieDec erbt von CDec.
 */
class CTrieDec: public CDec {
private:
	CKnot m_symbolTable[LZW_DICT_SIZE]; //!< Private Membervariable fuer das Dictionary.

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
	 */
	string decode(const vector<unsigned int>& encoded);
};

#endif /* CTRIEDEC_HPP_ */
