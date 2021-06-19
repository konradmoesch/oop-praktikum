/*!\file XOutOfBounds.hpp
 * \brief Das Headerfile für die Klasse XOutOfBounds (aus Aufgabe 6).
 *
 * Diese Exception soll geworfen werden, wenn versucht wird, auf ein nicht vorhandenen Index zuzugreifen
 * \todo Alle Beschreibungen lesen und umformulieren!
 */

#ifndef XOUTOFBOUNDS_HPP_
#define XOUTOFBOUNDS_HPP_

#include<exception>
#include<string>

/*!
 * \class XOutOfBounds
 * \brief Klasse XOutOfBounds (aus Aufgabe 6) zur Implementierung von exception für den Zugriff auf einen falschen Index
 *
 * XOutOfBounds(const char* msg) ist der Konstruktor, die Beschreibung der Exception wird als Parameter übergeben
 * virtual ~XOutOfBounds() throw() ist der Destruktor; wirft die Exception.
 * virtual const char* what() const throw() gibt den Wert der Membervariablen m_msg zurück.
 *
 * string m_msg ist die private Membervariable für die Fehlermeldung.
 */
class XOutOfBounds: public std::exception {
private:
	std::string m_msg; //!< Private Membervariable für die Beschreibung der Exception.
public:
	/*!
	 * Konstruktor zur Erzeugung des Exception-Objektes
	 * @param msg	enthält die Beschreibung der Exception
	 */
	explicit XOutOfBounds(const char *msg);
	/*!
	 * Destruktor; wirft keine weiteren Exceptions
	 */
	virtual ~XOutOfBounds() throw ();
	/*!
	 * what() gibt den Wert der Beschreibung der Exception zurück; wirft keine weitere Exceptions
	 * @return gibt den Wert von m_msg zurück
	 */
	virtual const char* what() const throw ();
};

#endif /* XOUTOFBOUNDS_HPP_ */
