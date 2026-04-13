#pragma once
#include "Elemento.h"
#include <iostream>
using namespace std;

template <class TIPO>
class Lista
{
private:
	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pAtual;
public:
	Lista();
	~Lista();

	void inicializa();
	void limpar();

	bool incluaElemento(Elemento<TIPO>* pElemento);
	bool incluaInfo(TIPO* pInfo);

	Elemento<TIPO>* getpPrimeiro();
	Elemento<TIPO>* getpAtual();
};

// Implementações

template <class TIPO>
Lista<TIPO>::Lista()
{
	inicializa();
}

template <class TIPO>
Lista<TIPO>::~Lista()
{
	limpar();
}

template <class TIPO>
void Lista<TIPO>::inicializa()
{
	pPrimeiro = NULL;
	pAtual = NULL;
}

template <class TIPO>
Elemento<TIPO>* Lista<TIPO>::getpPrimeiro()
{
	return pPrimeiro;
}

template <class TIPO>
Elemento<TIPO>* Lista<TIPO>::getpAtual()
{
	return pAtual;
}

template <class TIPO>
void Lista<TIPO>::limpar()
{
	Elemento<TIPO>* paux1;
	Elemento<TIPO>* paux2;
	paux1 = pPrimeiro;
	paux2 = paux1;
	while (paux1 != NULL)
	{
		paux2 = paux1->getProximo();
		delete(paux1);
		paux1 = paux2;
	}
	pPrimeiro = NULL;
	pAtual = NULL;
}

template<class TIPO>
bool Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
	if (pElemento != NULL)
	{
		if (pPrimeiro == NULL)
		{
			pPrimeiro = pElemento;
			pAtual = pPrimeiro;
			pPrimeiro->setProximo(NULL);
			pPrimeiro->setAnterior(NULL);			
		}
		else
		{
			pAtual->setProximo(pElemento);
			pElemento->setAnterior(pAtual);
			pAtual = pAtual->getProximo();
		}
		return true;
	}
	else
	{
		cerr << "Erro, elemento nulo." << endl;
		return false;
	}
}

template <class TIPO>
bool Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
	if (pInfo != NULL)
	{
		Elemento<TIPO>* pElemento = NULL;
		pElemento = new Elemento<TIPO>();
		pElemento->setInfo(pInfo);
		incluaElemento(pElemento);
		return true;
	}
	else
	{
		cerr << "Erro, elemento nulo." << endl;
		return false;
	}
}

