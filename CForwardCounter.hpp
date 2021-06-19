/*!\file CForwardCounter.hpp
 * \brief Das Headerfile für die Klasse CForwardCounter (aus Aufgabe 5).
 *
 * Diese Klasse ist von CCounter abgeleitet
 */
#ifndef CFORWARDCOUNTER_HPP_
#define CFORWARDCOUNTER_HPP_

#include "CCounter.hpp"

/*!
 * \class CForwardCounter
 * \brief Von CCounter abgeleitete Klasse CForwardCounter (aus Aufgabe 5) zur Implementierung des Zählers aus CCounter als einfach vorwärts inkrementierender Zähler
 *
 * void count() überlädt die Funktion der Basisklasse CCounter. Dabei wird der Zählerstand um 1 inkrementiert.
 */
class CForwardCounter: public CCounter {
public:
	/*!
	 * überladene Funktion count() aus CCounter.
	 * Inkrementiert den Zählerstand (um 1).
	 */
	void count();
};

#endif /* CFORWARDCOUNTER_HPP_ */
