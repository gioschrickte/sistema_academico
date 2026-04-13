#pragma once
#include "Elemento.h"
#include "Disciplina.h"

class ListaDisciplinas
{
private:
	Lista<Disciplina> LTDisciplinas;
public:
	ListaDisciplinas(int nd = 1000);
	~ListaDisciplinas();
	void incluaDisciplina(Disciplina* pdi);
	void listeDisciplinas();
	void limpaLista();
	Disciplina* localizar(char* n);
	Elemento<Disciplina>* getDisciplinaPrim();
};