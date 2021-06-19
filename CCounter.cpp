#include "CCounter.hpp"

//parameterloser Konstruktor; Membervariable initialisieren
CCounter::CCounter() : m_value(0) {}

//parameterloser (virtueller) Destruktor
CCounter::~CCounter() {}

//abstrakte Funktion zum Inkrementieren des Zählers; hier in der Basisklasse keine Funktion
void CCounter::count() {}

//getter-Funktion für Zählerwert
int CCounter::getValue() const {
	return m_value;
}

//setter-Funktion für Zählerwert
void CCounter::setValue(int val) {
	m_value = val;
}

//überladener Vergleichsoperator (<) für Zähler
bool CCounter::operator<(const CCounter &c2) const {
	return (m_value < c2.getValue()) ? true : false;
}

//überladener Vergleichsoperator (>) für Zähler
bool CCounter::operator>(const CCounter &c2) const {
	return (m_value > c2.getValue()) ? true : false;
}
