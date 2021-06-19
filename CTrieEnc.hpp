/*!
 * \file CTrieEnc.hpp
 * \brief Klasse CTrieEnc für Encodierung mittels Trie (Aufgabenteil 2)
 *
 * Dieses File enthält die Klasse CTrieEnc, welche zur Encodierung mit Hilfe eines Tries in Aufgabe 2 benutzt wird.
 * \todo cpp aufräumen; Ausgabe entfernen
 */
#ifndef CTRIEENC_HPP_
#define CTRIEENC_HPP_

#include "CEnc.hpp"
#include "CKnot.hpp"
#include "CForwardCounter.hpp"
#include "CDoubleHashing.hpp"

//! \todo weg damit? nur debug?
#include <sstream>
#include <iterator>

/*!
 * \class CTrieEnc
 * \brief Klasse für den Encoder mit Trie (Aufgabe 2)
 *
 * Klasse für den Encoder mittels Trie.
 * CTrieEnc erbt von CEnc.
 */
class CTrieEnc: public CEnc {
private:
	CKnot m_symbolTable[LZW_DICT_SIZE]; //!< Private Membervariable für das Dictionary.

public:
	/*!
	 * parameterloser Konstruktor
	 */
	CTrieEnc();
	void debugTrieOutput();
	/*!
	 * encodiert den String mit Hilfe des LZW-Algorithmus
	 * es wird dabei ein Trie als Dictionary benutzt
	 * @param inputstr	zu codierender String
	 * @return encodeter Vektor
	 * @todo debugTrieOutput entfernen!
	 */
	vector<unsigned int> encode(const string& inputstr);
};

#endif /* CTRIEENC_HPP_ */
