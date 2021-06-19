/*!\file CEntry.hpp
 * \brief Das Headerfile f�r die Klasse CEntry (aus Aufgaben 4-6).
 *
 * Diese Klasse speichert Zeichenketten. Die Klasse CKnot erbt von dieser Klasse und erweitert diese um die Speicherung des �bergeordneten Knotens.
 */

#ifndef CENTRY_HPP_
#define CENTRY_HPP_

#include <string>
using namespace std;

/*!
 * \class CEntry
 * \brief Klasse CEntry (aus Aufgaben 4-6) zur Speicherung von Zeichenketten.
 *
 * CEntry() ist der parameterlose Konstruktor.
 * ~CEntry() ist der Destruktor.
 * const string& getSymbol() const gibt die gespeicherte Zeichenkette zur�ck.
 * void setSymbol(string) setzt die gespeicherte Zeichenkette auf den qua Parameter �bergebenen String.
 * static unsigned int getNumber() gibt die Anzahl an Objekten vom Typ CEntry zur�ck.
 *
 * m_symbol ist die private Membervariable, um die Zeichenkette zu speichern.
 * m_number ist die statische private Membervariable, um die Anzahl von CEntry-Objekten zu speichern.
 */
class CEntry {
public:
	/*!
	 * parameterloser Konstruktor
	 */
	CEntry();
	/*!
	 * Destruktor
	 */
	~CEntry();
	/*!
	 * Funktion getSymbol() zur Abfrage der gespeicherten Zeichenkette.
	 * @return gespeicherte Zeichenkette
	 */
	const string& getSymbol() const;
	/*!
	 * Funktion setSymbol(string) zur �nderung der gespeicherten Zeichenkette.
	 * @param symbol	zu speichernde Zeichenkette
	 */
	void setSymbol(const string& symbol);
	/*!
	 * Funktion getNumber() zur Abfrage der Anzahl der CEntry-Instanzen.
	 * @return Anzahl der CEntry-Objekte
	 */
	static unsigned int getNumber();
private:
	string m_symbol; //!< Private Membervariable f�r die Zeichenkette
	static unsigned int m_number; //!< Private Statische Membervariable f�r die Anzahl an CEntry-Objekten
};

#endif /* CENTRY_HPP_ */
