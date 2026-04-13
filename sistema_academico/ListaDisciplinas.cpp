#include "ListaDisciplinas.h"
#include <iostream>
using std::cout;
using std::endl;

ListaDisciplinas::ListaDisciplinas(int nd)
{}
ListaDisciplinas::~ListaDisciplinas()
{
	LTDisciplinas.limpar();
}
// inclui uma nova disciplina se houver espaco e a entrada for valida
void ListaDisciplinas::incluaDisciplina(Disciplina* pdi)
{
	LTDisciplinas.incluaInfo(pdi);
}
// percorre todos os elementos, mostrando-os em tela um a um
void ListaDisciplinas::listeDisciplinas()
{
	Elemento<Disciplina>* pElaux;
	pElaux = LTDisciplinas.getpPrimeiro();
	if (pElaux == NULL) {
		cout << "nenhuma disciplina cadastrada" << endl;
		return;
	}
	while (pElaux != NULL)
	{
		Disciplina* paux = pElaux->getInfo();
		cout << " Disciplina " << paux->getNome()
			<< " do Departamento " << paux->getDepartamento()->getNome() << "." << endl;
		pElaux = pElaux->getProximo();
	}
	cout << endl;
}

void ListaDisciplinas::limpaLista()
{
	LTDisciplinas.limpar();
}

// localiza uma disciplina de nome "n" na lista de disciplinas
Disciplina* ListaDisciplinas::localizar(char* n)
{
	Elemento<Disciplina>* pElaux;
	pElaux = LTDisciplinas.getpPrimeiro();
	while (pElaux != NULL)
	{
		if (0 == strcmp(n, pElaux->getInfo()->getNome()))
		{
			return pElaux->getInfo();
		}
		pElaux = pElaux->getProximo();
	}
	return NULL;
}
Elemento<Disciplina>* ListaDisciplinas::getDisciplinaPrim() {
	return LTDisciplinas.getpPrimeiro();
}