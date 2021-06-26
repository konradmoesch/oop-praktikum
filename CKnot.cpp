#include "CKnot.hpp"

//parameterloser Konstruktor; initialisiert m_parent mit -2
CKnot::CKnot(): m_parent(-2){}

//Getter fuer ID des Elternelementes
int CKnot::getParent() const {
	return m_parent;
}

//Setter fuer das Elternelement
void CKnot::setParent(int parent) {
	m_parent = parent;
}
