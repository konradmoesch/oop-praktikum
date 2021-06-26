/*!\file CKnot.hpp
 * \brief Das Headerfile fuer die Klasse CKnot (aus Aufgabe 6).
 *
 * Diese Klasse erbt von CEntry und erweitert diese um die Speicherung des uebergeordneten Knotens.
 * Wird fuer die Trie-Implementierung in Aufgabe 2 benoetigt.
 */

#ifndef CKNOT_HPP_
#define CKNOT_HPP_

#include "CEntry.hpp"

/*!
 * \class CKnot
 * \brief Klasse CKnot (aus Aufgabe 6) zur Erweiterung der Klasse CEntry um die Speicherung des uebergeordneten Knotens.
 *
 * CKnot() ist der parameterlose Konstruktor.
 * int getParent() const gibt den uebergeordneten Knoten zurueck.
 * void setParent(int parent) setzt den uebergeordneten Knoten auf den durch den Parameter gegebenen Wert
 *
 * m_parent ist die private Membervariable, um die Adresse des uebergeordneten Knotens zu speichern.
 */
class CKnot: public CEntry {
private:
	int m_parent; //!< Private Membervariable fuer den uebergeordneten Knoten
public:
	/*!
	 * parameterloser Konstruktor
	 */
	CKnot();
	/*!
	 * Funktion getParent() zur Abfrage des gespeicherten uebergeordneten Knotens.
	 * @return uebergeordneter Knoten
	 */
	int getParent() const;
	/*!
	 * Funktion setParent() zur Aenderung des uebergeordneten Knotens.
	 * @param parent	uebergeordneter Knoten
	 */
	void setParent(int parent);
};

#endif /* CKNOT_HPP_ */
