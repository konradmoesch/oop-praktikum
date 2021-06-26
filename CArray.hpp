/*!\mainpage Programmierpraktikum von Konrad Moesch
 * In diesem Praktikum wird der LZW-Algorithmus mit einem Array und einem Trie implementiert
 * \author Konrad Janis Moesch (493608)
 * \date 26.06.2021
 * \version fertig (endgueltige Abgabe)
 */

/*!\file CArray.hpp
 * \brief Das Headerfile fuer die Klasse CArray (aus Aufgabe 6).
 *
 * Diese Klasse ist ein Template fuer ein Datenfeld (eindimensionales Array)
 */
#include "XOutOfBounds.hpp"

#ifndef CARRAY_HPP_
#define CARRAY_HPP_

//! Template CArray (aus Aufgabe 6) zur Implementierung eines Datenfeldes (eindimensionales Array)
/*!
 * CArray() ist der parameterlose Konstruktor
 * ~CArray() ist der Destruktor
 * T& operator[](unsigned int index) gibt (wenn vorhanden) den Eintrag zum gegebenen Index zurueck
 *
 * T* entries ist die private Membervariable fuer die Eintraege der Liste.
 * unsigned int size ist die private Membervariable fuer die Groeﬂe des Arrays (Anzahl der Eintraege) zur einfacheren Durchfuehrung von Operationen auf das Array
 */

//T ist Typ der Elemente der Liste, N die Anzahl der Elemente
template <typename T, unsigned int N>
class CArray {
private:
	T* entries; //!< Private Membervariable fuer die Eintraege.
	unsigned int size; //!< Private Membervariable fuer die Anzahl der Eintraege.
public:
	/*!
	 * Operator[] zum Zugriff auf einen bestimmten Eintrag des Arrays.
	 * Wenn der Eintrag nicht vorhanden ist, wird eine XOutOfBounds-Exception geworfen.
	 * @param index	enthaelt den Index des Arrays (gegeben zwischen den eckigen Klammern).
	 * @return  enthaelt den Wert des Elements an der durch Index gegebenen Stelle des Arrays.
	 */
	T& operator[](unsigned int index) {
		if (index>=N)
			throw XOutOfBounds("Index zu gross");
		return entries[index];
	}
	/*!
	 * parameterloser Konstruktors
	 */
	CArray(){
		size = N;
		entries = new T[size];
	}
	/*!
	 * Kopierkonstruktor
	 * @param a    Die Membervariablen (size und entries) werden mit den Werten der Membervariablen des Parameters a initialisiert.
	 */
	CArray(const CArray& a){
		size = a.size;
		entries = new T[size];
		*entries = *a.entries;
	}
	/*!
	 * Destruktor
	 * Der Speicher der Membervariablen wird freigegeben bzw. die Pointer / Werte zurueckgesetzt.
	 */
	virtual ~CArray(){
		delete[] entries;
		entries = nullptr;
		size = 0;
	}
};

#endif /* CARRAY_HPP_ */
