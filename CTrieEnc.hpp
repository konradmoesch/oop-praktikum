/*!
 * \file CTrieEnc.hpp
 * \brief Klasse CTrieEnc fuer Encodierung mittels Trie (Aufgabenteil 2)
 *
 * Dieses File enthaelt die Klasse CTrieEnc, welche zur Encodierung mit Hilfe eines Tries in Aufgabe 2 benutzt wird.
 */
#ifndef CTRIEENC_HPP_
#define CTRIEENC_HPP_

#include "CEnc.hpp"
#include "CKnot.hpp"
#include "CForwardCounter.hpp"
#include "CDoubleHashing.hpp"

/*!
 * \class CTrieEnc
 * \brief Klasse fuer den Encoder mit Trie (Aufgabe 2)
 *
 * Klasse fuer den Encoder mittels Trie.
 * CTrieEnc erbt von CEnc.
 */
class CTrieEnc: public CEnc {
private:
	CKnot m_symbolTable[LZW_DICT_SIZE]; //!< Private Membervariable fuer das Dictionary.

public:
	/*!
	 * parameterloser Konstruktor
	 */
	CTrieEnc();
	/*!
	 * encodiert den String mit Hilfe des LZW-Algorithmus
	 * es wird dabei ein Trie als Dictionary benutzt
	 * @param inputstr	zu codierender String
	 * @return encodeter Vektor
	 */
	vector<unsigned int> encode(const string& inputstr);
};

#endif /* CTRIEENC_HPP_ */
