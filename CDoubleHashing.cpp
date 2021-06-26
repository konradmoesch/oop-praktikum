#include "CDoubleHashing.hpp"

//parameterloser Konstruktor (bei Singleton privat/verboten)
CDoubleHashing::CDoubleHashing() {}

//statische Membervariable fuer Singleton-Instanz
CDoubleHashing CDoubleHashing::m_instance;

//Funktion zum Erhalten der Singleton-Instanz
CDoubleHashing& CDoubleHashing::getInstance() {
	return m_instance;
}

//Hashfunktion; Double-Hashing mit Rehashing-Funktionalitaet
unsigned int CDoubleHashing::hash(unsigned int I, unsigned int J,
		unsigned int dict_size, unsigned int attempt) {
	unsigned long hash_value = (I + J) * (I + J + 1) / 2 + J;
	unsigned int result = ((hash_value % dict_size) + attempt * (1 + (hash_value % (dict_size - 2)))) % dict_size;

	return result;
}
