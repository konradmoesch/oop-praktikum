/*!\file CEntry.hpp
 * \brief Das Headerfile fuer die Klasse CEntry (aus Aufgaben 4-6).
 *
 * Diese Klasse speichert Zeichenketten. Die Klasse CKnot erbt von dieser Klasse und erweitert diese um die Speicherung des uebergeordneten Knotens.
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
 * const string& getSymbol() const gibt die gespeicherte Zeichenkette zurueck.
 * void setSymbol(string) setzt die gespeicherte Zeichenkette auf den qua Parameter uebergebenen String.
 * static unsigned int getNumber() gibt die Anzahl an Objekten vom Typ CEntry zurueck.
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
	 * Funktion setSymbol(string) zur Aenderung der gespeicherten Zeichenkette.
	 * @param symbol	zu speichernde Zeichenkette
	 */
	void setSymbol(const string& symbol);
	/*!
	 * Funktion getNumber() zur Abfrage der Anzahl der CEntry-Instanzen.
	 * @return Anzahl der CEntry-Objekte
	 */
	static unsigned int getNumber();
private:
	string m_symbol; //!< Private Membervariable fuer die Zeichenkette
	static unsigned int m_number; //!< Private Statische Membervariable fuer die Anzahl an CEntry-Objekten
};

#endif /* CENTRY_HPP_ */
