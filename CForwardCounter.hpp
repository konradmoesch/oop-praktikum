/*!\file CForwardCounter.hpp
 * \brief Das Headerfile f�r die Klasse CForwardCounter (aus Aufgabe 5).
 *
 * Diese Klasse ist von CCounter abgeleitet
 */
#ifndef CFORWARDCOUNTER_HPP_
#define CFORWARDCOUNTER_HPP_

#include "CCounter.hpp"

/*!
 * \class CForwardCounter
 * \brief Von CCounter abgeleitete Klasse CForwardCounter (aus Aufgabe 5) zur Implementierung des Z�hlers aus CCounter als einfach vorw�rts inkrementierender Z�hler
 *
 * void count() �berl�dt die Funktion der Basisklasse CCounter. Dabei wird der Z�hlerstand um 1 inkrementiert.
 */
class CForwardCounter: public CCounter {
public:
	/*!
	 * �berladene Funktion count() aus CCounter.
	 * Inkrementiert den Z�hlerstand (um 1).
	 */
	void count();
};

#endif /* CFORWARDCOUNTER_HPP_ */
