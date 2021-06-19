#include "XOutOfBounds.hpp"

//Konstruktor für Exception; initialisiert Fehlermeldung (m_msg)
XOutOfBounds::XOutOfBounds(const char* msg): m_msg(msg){}

//Destruktor; darf keine weiteren Exceptions werfen
XOutOfBounds::~XOutOfBounds() throw(){}

//what() darf auch keine weiteren Exceptions werfen
const char* XOutOfBounds::what() const throw(){
	return  m_msg.c_str();
}
