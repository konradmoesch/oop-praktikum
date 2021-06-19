#include "CCounter.hpp"

//parameterloser Konstruktor; Membervariable initialisieren
CCounter::CCounter() : m_value(0) {}

//parameterloser (virtueller) Destruktor
CCounter::~CCounter() {}

//abstrakte Funktion zum Inkrementieren des Z�hlers; hier in der Basisklasse keine Funktion
void CCounter::count() {}

//getter-Funktion f�r Z�hlerwert
int CCounter::getValue() const {
	return m_value;
}

//setter-Funktion f�r Z�hlerwert
void CCounter::setValue(int val) {
	m_value = val;
}

//�berladener Vergleichsoperator (<) f�r Z�hler
bool CCounter::operator<(const CCounter &c2) const {
	return (m_value < c2.getValue()) ? true : false;
}

//�berladener Vergleichsoperator (>) f�r Z�hler
bool CCounter::operator>(const CCounter &c2) const {
	return (m_value > c2.getValue()) ? true : false;
}
