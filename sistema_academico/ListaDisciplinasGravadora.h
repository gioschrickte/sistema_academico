#pragma once
#include "ListaDisciplinas.h"
#include "ListaDepartamentos.h"

class ListaDisciplinasGravadora : public ListaDisciplinas
{
private:
	string nomeArquivo;
public:
	ListaDisciplinasGravadora(string arquivo = "disciplinas.dat");
	~ListaDisciplinasGravadora();
	void graveDisciplinas();
	int recupereDisciplinas(ListaDepartamentos& ld);
};