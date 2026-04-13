#include "ListaAlunos.h"
#include "Disciplina.h"
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <iostream>
using std::cout;
using std::endl;

ListaAlunos::ListaAlunos(int na)
{}
ListaAlunos::~ListaAlunos()
{
	limpaLista();
}

// inclui um novo aluno se houver espaco e a entrada for valida
void ListaAlunos::incluaAluno(Aluno* pa)
{
	if (pa != NULL)
	{
		LTAlunos.incluaInfo(pa);
	}
	else
		cout << "Erro, ponteiro invalido" << endl;
}
// percorre todos os elementos, mostrando-os em tela um a um
void ListaAlunos::listeAlunos()
{
	Elemento<Aluno>* pElaux = NULL;
	Aluno* pAlAux = NULL;
	pElaux = LTAlunos.getpPrimeiro();


	if (pElaux == NULL) {
		cout << "nenhum aluno cadastrado" << endl;
		return;
	}
	while (pElaux != NULL)
	{
		pAlAux = pElaux->getInfo();
		cout << " Aluno " << pAlAux->getNome() <<
			" matriculado na Disciplina " << pAlAux->getDisciplina()->getNome() << "." << endl;
		pElaux = pElaux->getProximo();
	}
	cout << endl;
}

void ListaAlunos::listeAlunos2()
{
	Elemento<Aluno>* pElaux = NULL;
	Aluno* pAlAux = NULL;
	pElaux = LTAlunos.getpAtual();


	if (pElaux == NULL) {
		cout << "nenhum aluno cadastrado" << endl;
		return;
	}
	while (pElaux != NULL)
	{
		pAlAux = pElaux->getInfo();
		cout << " Aluno " << pAlAux->getNome() <<
			" matriculado na Disciplina " << pAlAux->getDisciplina()->getNome() << "." << endl;
		pElaux = pElaux->getAnterior();
	}
	cout << endl;
}

Elemento<Aluno>* ListaAlunos::getAlunoPrim()
{
	return LTAlunos.getpPrimeiro();
}

void ListaAlunos::limpaLista()
{
	LTAlunos.limpar();
}