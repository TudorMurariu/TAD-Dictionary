#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>

using namespace std;

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
	this->p = nullptr;
}


void IteratorDictionar::prim() {
	/// Resetam iteratorul
	this->p = this->dict.Inceput;
}


void IteratorDictionar::urmator() {
	/// Trecem iteratorul la urmatorul nod din lista
	/// Daca nu putem trece la urmatorul trimitem o eroare
	
	if (!this->valid())
		throw exception();

	this->p = this->p->urmator();
}


TElem IteratorDictionar::element() const{
	/// Verificam daca iteratorul este valid
	/// returnam valoarea elementului din container referit de iterator
	
	if(!this->valid())
		throw exception();

	return this->p->element();
}


bool IteratorDictionar::valid() const {
	/// Verificam daca iteratorul este valid(element al listei)
	/// Ajunge sa verificam doar daca iteratorul nu este null

	if (this->p == nullptr)
		return false;

	return true;
}

