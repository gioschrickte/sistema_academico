#include "ListaDepartamentos.h"
#include "Universidade.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;

ListaDepartamentos::ListaDepartamentos()
{}
ListaDepartamentos::~ListaDepartamentos()
{
	LTDepartamento.limpar();
}
// inclui um novo departamento se houver espaco e a entrada for valida
void ListaDepartamentos::incluaDepartamento(Departamento* pdi)
{
	LTDepartamento.incluaInfo(pdi);
}

void ListaDepartamentos::limpaLista()
{
	LTDepartamento.limpar();
}

// percorre todos os elementos, mostrando-os em tela um a um
void ListaDepartamentos::listeDepartamentos()
{
	Elemento<Departamento>* paux;
	paux = LTDepartamento.getpPrimeiro();
	if (paux == NULL) {
		cout << "nenhum departamento cadastrada" << endl;
		return;
	}
	while (paux != NULL)
	{
		Departamento* pDepaux = paux->getInfo();
		cout << " Departamento " << pDepaux->getNome()
			<< " da universidade " << pDepaux->getUniversidade()->getNome() << "." << endl;
		paux = paux->getProximo();
	}
	cout << endl;
}
// localiza uma universidade de nome "n" na lista de universidades
Departamento* ListaDepartamentos::localizar(char* n)
{
	Elemento<Departamento>* paux;
	paux = LTDepartamento.getpPrimeiro();
	while (paux != NULL)
	{
		if (0 == strcmp(n, paux->getInfo()->getNome()))
		{
			return paux->getInfo();
		}
		paux = paux->getProximo();
	}
	return NULL;
}
Elemento<Departamento>* ListaDepartamentos::getDepartamentoPrim() {
	return LTDepartamento.getpPrimeiro();
}