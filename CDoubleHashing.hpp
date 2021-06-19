/*!\file CDoubleHashing.hpp
 * \brief Das Headerfile für die Singleton-Klasse CDoubleHashing (aus Aufgabe 7).
 *
 * Diese Klasse ist fürs Hashing zuständig. Sie ist als Singleton ausgelegt (es darf nur eine Instanz existieren)
 * \todo Alle Beschreibungen lesen und umformulieren!
 */

#ifndef CDOUBLEHASHING_HPP_
#define CDOUBLEHASHING_HPP_

/*!
 * \class CDoubleHashing
 * \brief Klasse CDoubleHashing (aus Aufgabe 7) zur Implementierung der Double-Hashing-Funktionalität
 *
 * static CDoubleHashing& getInstance() ist eine statische Memberfunktion, die die Instanz des Singletons zurückgibt
 * unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt) ist die Hash-Funktion
 *
 * static CDoubleHashing m_instance ist die private Membervariable um die Singleton-Instanz zu speichern
 * Der parameterlose Konstruktor (CDoubleHashing()), der Kopierkonstruktor (CDoubleHashing(const CDoubleHashing&)) und der Zuweisungsoperator (CDoubleHashing operator=(CDoubleHashing& other)) sind private Memberfunktionen und nicht deklariert (=delete)
 */
class CDoubleHashing {
private:
	static CDoubleHashing m_instance; //!< Private Membervariable für die Singleton-Instanz.
	/*!
	 * parameterloser Konstruktor (bei Singleton verboten)
	 */
	CDoubleHashing();
	/*!
	 * Kopierkonstruktor (bei Singleton verboten)
	 */
	CDoubleHashing(const CDoubleHashing&) = delete;
	/*!
	 * Zuweisungsoperator (bei Singleton verboten)
	 */
	CDoubleHashing operator=(CDoubleHashing &other) = delete;
public:
	/*!
	 * getInstance() gibt die Singleton-Instanz zurück
	 * @return Singleton-Instanz
	 */
	static CDoubleHashing& getInstance();
	/*!
	 * Hashfunktion
	 * @param I	erste zu hashende Zahl
	 * @param J	zweite zu hashende Zahl
	 * @param dict_size	Größe der Hashtabelle
	 * @param attempt	Zähler (für doppeltes Hashing)
	 * @return Hashwert
	 */
	unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size,
			unsigned int attempt);
};

#endif /* CDOUBLEHASHING_HPP_ */
