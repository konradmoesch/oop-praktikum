#include "CKnot.hpp"

//parameterloser Konstruktor; initialisiert m_parent mit -2
CKnot::CKnot(): m_parent(-2){}

//Getter f�r ID des Elternelementes<
int CKnot::getParent() const {
	return m_parent;
}

//Setter f�r das Elternelement
void CKnot::setParent(int parent) {
	m_parent = parent;
}

