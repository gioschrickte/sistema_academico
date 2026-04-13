#include "ListaUniversidades.h"
#include <iostream>
using std::cout;
using std::endl;

ListaUniversidades::ListaUniversidades()
{}
ListaUniversidades::~ListaUniversidades()
{
	LTUniversidade.limpar();
}
// inclui uma nova universidade se houver espaco e a entrada for valida
void ListaUniversidades::incluaUniversidade(Universidade* pdi)
{
	LTUniversidade.incluaInfo(pdi);
}
// percorre todos os elementos, mostrando-os em tela um a um
void ListaUniversidades::listeUniversidades()
{
	Elemento<Universidade>* pElaux;
	pElaux = LTUniversidade.getpPrimeiro();
	if (pElaux == NULL) {
		cout << "nenhuma universidade cadastrada" << endl;
		return;
	}
	while (pElaux != NULL)
	{
		cout << " Universidade " << pElaux->getInfo()->getNome() << "." << endl;
		pElaux = pElaux->getProximo();
	}
	cout << endl;
}

void ListaUniversidades::limpaLista()
{
	LTUniversidade.limpar();
}

// localiza uma universidade de nome "n" na lista de universidades
Universidade* ListaUniversidades::localizar(char* n)
{
	Elemento<Universidade>* paux;
	paux = LTUniversidade.getpPrimeiro();
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
Elemento<Universidade>* ListaUniversidades::getUniversidadePrim() {
	return LTUniversidade.getpPrimeiro();
}