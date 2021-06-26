#include "CCounter.hpp"

//parameterloser Konstruktor; Membervariable initialisieren
CCounter::CCounter() : m_value(0) {}

//parameterloser (virtueller) Destruktor
CCounter::~CCounter() {}

//abstrakte Funktion zum Inkrementieren des Zaehlers; hier in der Basisklasse keine Funktion
void CCounter::count() {}

//getter-Funktion fuer Zaehlerwert
int CCounter::getValue() const {
	return m_value;
}

//setter-Funktion fuer Zaehlerwert
void CCounter::setValue(int val) {
	m_value = val;
}

//ueberladener Vergleichsoperator (<) fuer Zaehler
bool CCounter::operator<(const CCounter &c2) const {
	return (m_value < c2.getValue()) ? true : false;
}

//ueberladener Vergleichsoperator (>) fuer Zaehler
bool CCounter::operator>(const CCounter &c2) const {
	return (m_value > c2.getValue()) ? true : false;
}
