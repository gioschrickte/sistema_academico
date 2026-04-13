#pragma once
#include "ListaAlunos.h"
#include "ListaDisciplinasGravadora.h"
#include <string>
using namespace std;

class ListaAlunosGravadora : public ListaAlunos
{
private:
	string nomeArquivo;
public:
	ListaAlunosGravadora(string arquivo = "alunos.dat");
	~ListaAlunosGravadora();

	void graveAlunos();
	int recupereAlunos(ListaDisciplinasGravadora& ld);
};