/*!\file CKnot.hpp
 * \brief Das Headerfile für die Klasse CKnot (aus Aufgabe 6).
 *
 * Diese Klasse erbt von CEntry und erweitert diese um die Speicherung des übergeordneten Knotens.
 * Wird für die Trie-Implementierung in Aufgabe 2 benötigt.
 */

#ifndef CKNOT_HPP_
#define CKNOT_HPP_

#include "CEntry.hpp"

/*!
 * \class CKnot
 * \brief Klasse CKnot (aus Aufgabe 6) zur Erweiterung der Klasse CEntry um die Speicherung des übergeordneten Knotens.
 *
 * CKnot() ist der parameterlose Konstruktor.
 * int getParent() const gibt den übergeordneten Knoten zurück.
 * void setParent(int parent) setzt den übergeordneten Knoten auf den durch den Parameter gegebenen Wert
 *
 * m_parent ist die private Membervariable, um die Adresse des übergeordneten Knotens zu speichern.
 */
class CKnot: public CEntry {
private:
	int m_parent; //!< Private Membervariable für den übergeordneten Knoten
public:
	/*!
	 * parameterloser Konstruktor
	 */
	CKnot();
	/*!
	 * Funktion getParent() zur Abfrage des gespeicherten übergeordneten Knotens.
	 * @return übergeordneter Knoten
	 */
	int getParent() const;
	/*!
	 * Funktion setParent() zur Änderung des übergeordneten Knotens.
	 * @param parent	übergeordneter Knoten
	 */
	void setParent(int parent);
};

#endif /* CKNOT_HPP_ */
