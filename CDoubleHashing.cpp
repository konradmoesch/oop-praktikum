#include "CDoubleHashing.hpp"

//parameterloser Konstruktor (bei Singleton privat/verboten)
CDoubleHashing::CDoubleHashing() {}

//statische Membervariable für Singleton-Instanz
CDoubleHashing CDoubleHashing::m_instance;

//Funktion zum Erhalten der Singleton-Instanz
CDoubleHashing& CDoubleHashing::getInstance() {
	return m_instance;
}

//Hashfunktion; Double-Hashing mit Rehashing-Funktionalität
unsigned int CDoubleHashing::hash(unsigned int I, unsigned int J,
		unsigned int dict_size, unsigned int attempt) {
	unsigned long I_l = static_cast<unsigned long>(I);
	unsigned long J_l = static_cast<unsigned long>(J);
	unsigned long hash_value = (I_l + J_l) * (I_l + J_l + 1) / 2 + J_l;

	unsigned int h1 = hash_value % dict_size;
	unsigned int h2 = 1 + (hash_value % (dict_size - 2));
	unsigned int result = (h1 + attempt * h2) % dict_size;

	return result;
}
