/*!\file CKnot.hpp
 * \brief Das Headerfile f�r die Klasse CKnot (aus Aufgabe 6).
 *
 * Diese Klasse erbt von CEntry und erweitert diese um die Speicherung des �bergeordneten Knotens.
 * Wird f�r die Trie-Implementierung in Aufgabe 2 ben�tigt.
 */

#ifndef CKNOT_HPP_
#define CKNOT_HPP_

#include "CEntry.hpp"

/*!
 * \class CKnot
 * \brief Klasse CKnot (aus Aufgabe 6) zur Erweiterung der Klasse CEntry um die Speicherung des �bergeordneten Knotens.
 *
 * CKnot() ist der parameterlose Konstruktor.
 * int getParent() const gibt den �bergeordneten Knoten zur�ck.
 * void setParent(int parent) setzt den �bergeordneten Knoten auf den durch den Parameter gegebenen Wert
 *
 * m_parent ist die private Membervariable, um die Adresse des �bergeordneten Knotens zu speichern.
 */
class CKnot: public CEntry {
private:
	int m_parent; //!< Private Membervariable f�r den �bergeordneten Knoten
public:
	/*!
	 * parameterloser Konstruktor
	 */
	CKnot();
	/*!
	 * Funktion getParent() zur Abfrage des gespeicherten �bergeordneten Knotens.
	 * @return �bergeordneter Knoten
	 */
	int getParent() const;
	/*!
	 * Funktion setParent() zur �nderung des �bergeordneten Knotens.
	 * @param parent	�bergeordneter Knoten
	 */
	void setParent(int parent);
};

#endif /* CKNOT_HPP_ */
