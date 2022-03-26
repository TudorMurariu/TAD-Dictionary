#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

Nod::Nod(TElem e, PNod urm, PNod pre) {
	this->e = e;
	this->urm = urm;
}

TElem Nod::element() {
	return e;
}

PNod Nod::urmator() {
	return urm;
}

PNod Nod::precedent() {
	return this->pre;
}


Dictionar::Dictionar() {
	this->Inceput = NULL;
}

Dictionar::~Dictionar() {
	/* de adaugat */
}

TValoare Dictionar::adauga(TCheie c, TValoare v){
	/// 
	TElem e;
	e.first = c;
	e.second = v;
	PNod newp = new Nod(e,nullptr,nullptr);

	if (this->Inceput == nullptr)
	{
		this->Inceput = newp;
		return NULL_TVALOARE;
	}

	PNod p = this->Inceput;
	while (p->urmator() != nullptr)
	{
		if (c == p->element().first)
		{
			TValoare aux = p->e.second;
			p->e.second = v;
			return aux;
		}
		p = p->urmator();
	}

	if (c == p->element().first)
	{
		TValoare aux = p->e.second;
		p->e.second = v;
		return aux;
	}

	if (p->urm != nullptr)
		p->urm->pre = newp;
	p->urm = newp;
	newp->pre = p;
	
	return NULL_TVALOARE;
}



//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const{
	///

	PNod p = this->Inceput;
	while (p != nullptr)
	{
		if (c == p->element().first)
			return p->e.second;
		p = p->urmator();
	}

	return NULL_TVALOARE;
}


TValoare Dictionar::sterge(TCheie c){
	/// 

	if (this->Inceput == nullptr)
		return NULL_TVALOARE;
	
	PNod p = this->Inceput;
	if (c == p->element().first)
	{
		this->Inceput = p->urm;
		this->Inceput->pre = nullptr;
		return p->e.second;
	}

	while (p->urmator() != nullptr)
	{
		if (c == p->element().first)
		{
			TValoare aux = p->e.second;
			p = p->pre;
			p->urm = p->urm->urm;
			return aux;
		}
		p = p->urmator();
	}

	if (c == p->element().first)
	{
		TValoare aux = p->e.second;
		p = nullptr;
		return aux;
	}

	return NULL_TVALOARE;
}


int Dictionar::dim() const {
	/// Numaram in variabila dim numarul de elemente din lista inlantuita si 
	/// returnam acest numar

	int dim = 0;
	PNod p = this->Inceput;
	while (p != nullptr)
	{
		dim++;
		p = p->urmator();
	}

	return dim;
}

bool Dictionar::vid() const{
	/// Verificam daca disctionarul este vid
	/// (verifica, daca inceputul listei este nullptr)
	return this->Inceput == nullptr;
}


IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}


