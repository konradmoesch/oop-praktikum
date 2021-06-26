/*!\file CDoubleHashing.hpp
 * \brief Das Headerfile fuer die Singleton-Klasse CDoubleHashing (aus Aufgabe 7).
 *
 * Diese Klasse ist fuers Hashing zustaendig. Sie ist als Singleton ausgelegt (es darf nur eine Instanz existieren)
 */

#ifndef CDOUBLEHASHING_HPP_
#define CDOUBLEHASHING_HPP_

/*!
 * \class CDoubleHashing
 * \brief Klasse CDoubleHashing (aus Aufgabe 7) zur Implementierung der Double-Hashing-Funktionalitaet
 *
 * static CDoubleHashing& getInstance() ist eine statische Memberfunktion, die die Instanz des Singletons zurueckgibt
 * unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt) ist die Hash-Funktion
 *
 * static CDoubleHashing m_instance ist die private Membervariable um die Singleton-Instanz zu speichern
 * Der parameterlose Konstruktor (CDoubleHashing()), der Kopierkonstruktor (CDoubleHashing(const CDoubleHashing&)) und der Zuweisungsoperator (CDoubleHashing operator=(CDoubleHashing& other)) sind private Memberfunktionen und nicht deklariert (=delete)
 */
class CDoubleHashing {
private:
	static CDoubleHashing m_instance; //!< Private Membervariable fuer die Singleton-Instanz.
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
	 * getInstance() gibt die Singleton-Instanz zurueck
	 * @return Singleton-Instanz
	 */
	static CDoubleHashing& getInstance();
	/*!
	 * Hashfunktion
	 * @param I	erste zu hashende Zahl
	 * @param J	zweite zu hashende Zahl
	 * @param dict_size	Groeße der Hashtabelle
	 * @param attempt	Zaehler (fuer doppeltes Hashing)
	 * @return Hashwert
	 */
	unsigned int hash(unsigned int I, unsigned int J, unsigned int dict_size,
			unsigned int attempt);
};

#endif /* CDOUBLEHASHING_HPP_ */
