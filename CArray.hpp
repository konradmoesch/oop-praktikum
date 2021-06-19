/*!\mainpage Programmierpraktikum von Konrad Mösch
 * In diesem Praktikum wird der LZW-Algorithmus mit einem Array und einem Trie implementiert
 * \author Konrad Janis Mösch (493608)
 * \date 19.06.2021
 * \version noch nicht fertig
 * \todo alle Dateien kommentieren
 * \todo Membervariablen fehlen?
 * \todo einheitliche Formulierung
 */

/*!\file CArray.hpp
 * \brief Das Headerfile für die Klasse CArray (aus Aufgabe 6).
 *
 * Diese Klasse ist ein Template für ein Datenfeld (eindimensionales Array)
 * \todo Alle Beschreibungen lesen und umformulieren!
 */
#include "XOutOfBounds.hpp"

#ifndef CARRAY_HPP_
#define CARRAY_HPP_

//! Template CArray (aus Aufgabe 6) zur Implementierung eines Datenfeldes (eindimensionales Array)
/*!
 * CArray() ist der parameterlose Konstruktor
 * ~CArray() ist der Destruktor
 * T& operator[](unsigned int index) gibt (wenn vorhanden) den Eintrag zum gegebenen Index zurück
 *
 * T* entries ist die private Membervariable für die Einträge der Liste.
 * unsigned int size ist die private Membervariable für die Größe des Arrays (Anzahl der Einträge) zur einfacheren Durchführung von Operationen auf das Array
 */

template <typename T, unsigned int N>
class CArray {
private:
	T* entries; //!< Private Membervariable für die Einträge.
	unsigned int size; //!< Private Membervariable für die Anzahl der Einträge.
public:
	/*!
	 * Operator[] zum Zugriff auf einen bestimmten Eintrag des Arrays.
	 * Wenn der Eintrag nicht vorhanden ist, wird eine XOutOfBounds-Exception geworfen.
	 * @param index	enthält den Index des Arrays (gegeben zwischen den eckigen Klammern).
	 * @return  enthält den Wert des Elements an der durch Index gegebenen Stelle des Arrays.
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
		entries = a.entries;
	}
	/*!
	 * Destruktor
	 * Der Speicher der Membervariablen wird freigegeben bzw. die Pointer / Werte zurückgesetzt.
	 */
	virtual ~CArray(){
		delete[] entries;
		entries = nullptr;
		size = 0;
	}
};

#endif /* CARRAY_HPP_ */
