#pragma once
#include "Elemento.h"
#include "Universidade.h"

class ListaUniversidades
{
protected:
	Lista<Universidade> LTUniversidade;
public:
	ListaUniversidades();
	~ListaUniversidades();
	void incluaUniversidade(Universidade* pdi);
	void listeUniversidades();
	void limpaLista();
	Universidade* localizar(char* n);
	Elemento<Universidade>* getUniversidadePrim();
};