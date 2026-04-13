#pragma once
#include "Lista.h"
#include "Aluno.h"

class ListaAlunos
{
protected:
	Lista<Aluno> LTAlunos;
public:
	ListaAlunos(int na = 45);
	~ListaAlunos();

	void limpaLista();
	void incluaAluno(Aluno* pa);

	void listeAlunos();
	void listeAlunos2();

	void graveAlunos();
	void recupereAlunos();

	Elemento<Aluno>* getAlunoPrim();
};