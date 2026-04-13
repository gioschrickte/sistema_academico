#pragma once
#include "Lista.h"
#include "Departamento.h"

class ListaDepartamentos
{
protected:	
	Lista<Departamento> LTDepartamento;
public:
	ListaDepartamentos();
	~ListaDepartamentos();
	void incluaDepartamento(Departamento* pdi);
	void listeDepartamentos();
	void limpaLista();
	Departamento* localizar(char* n);
	Elemento<Departamento>* getDepartamentoPrim();
};