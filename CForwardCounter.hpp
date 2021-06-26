/*!\file CForwardCounter.hpp
 * \brief Das Headerfile fuer die Klasse CForwardCounter (aus Aufgabe 5).
 *
 * Diese Klasse ist von CCounter abgeleitet
 */
#ifndef CFORWARDCOUNTER_HPP_
#define CFORWARDCOUNTER_HPP_

#include "CCounter.hpp"

/*!
 * \class CForwardCounter
 * \brief Von CCounter abgeleitete Klasse CForwardCounter (aus Aufgabe 5) zur Implementierung des Zaehlers aus CCounter als einfach vorwaerts inkrementierender Zaehler
 *
 * void count() ueberlaedt die Funktion der Basisklasse CCounter. Dabei wird der Zaehlerstand um 1 inkrementiert.
 */
class CForwardCounter: public CCounter {
public:
	/*!
	 * Ueberladene Funktion count() aus CCounter.
	 * Inkrementiert den Zaehlerstand (um 1).
	 */
	void count();
};

#endif /* CFORWARDCOUNTER_HPP_ */
