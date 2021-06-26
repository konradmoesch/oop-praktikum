/*!\file XOutOfBounds.hpp
 * \brief Das Headerfile fuer die Klasse XOutOfBounds (aus Aufgabe 6).
 *
 * Diese Exception soll geworfen werden, wenn versucht wird, auf ein nicht vorhandenen Index zuzugreifen
 */

#ifndef XOUTOFBOUNDS_HPP_
#define XOUTOFBOUNDS_HPP_

#include<exception>
#include<string>

/*!
 * \class XOutOfBounds
 * \brief Klasse XOutOfBounds (aus Aufgabe 6) zur Implementierung von exception fuer den Zugriff auf einen falschen Index
 *
 * XOutOfBounds(const char* msg) ist der Konstruktor, die Beschreibung der Exception wird als Parameter uebergeben
 * virtual ~XOutOfBounds() throw() ist der Destruktor; wirft die Exception.
 * virtual const char* what() const throw() gibt den Wert der Membervariablen m_msg zurueck.
 *
 * string m_msg ist die private Membervariable fuer die Fehlermeldung.
 */
class XOutOfBounds: public std::exception {
private:
	std::string m_msg; //!< Private Membervariable fuer die Beschreibung der Exception.
public:
	/*!
	 * Konstruktor zur Erzeugung des Exception-Objektes
	 * @param msg	enthaelt die Beschreibung der Exception
	 */
	explicit XOutOfBounds(const char *msg);
	/*!
	 * Destruktor; wirft keine weiteren Exceptions
	 */
	virtual ~XOutOfBounds() throw ();
	/*!
	 * what() gibt den Wert der Beschreibung der Exception zurueck; wirft keine weitere Exceptions
	 * @return gibt den Wert von m_msg zurueck
	 */
	virtual const char* what() const throw ();
};

#endif /* XOUTOFBOUNDS_HPP_ */
