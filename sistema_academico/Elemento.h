#pragma once
#include <stdio.h>

template <class TIPO>
class Elemento
{
private:
	Elemento<TIPO>* pProximo;
	Elemento<TIPO>* pAnterior;
	TIPO* pInfo;
public:
	Elemento();
	~Elemento();

	void setProximo(Elemento<TIPO>* pP);
	Elemento<TIPO>* getProximo();

	void setAnterior(Elemento<TIPO>* pA);
	Elemento<TIPO>* getAnterior();

	void setInfo(TIPO* pI);
	TIPO* getInfo();
};

// Implementações

template <class TIPO>
Elemento<TIPO>::Elemento()
{
	pProximo = NULL;
	pAnterior = NULL;
	pInfo = NULL;
}

template <class TIPO>
Elemento<TIPO>::~Elemento()
{
	pProximo = NULL;
	pAnterior = NULL;
	pInfo = NULL;
}

template <class TIPO>
void Elemento<TIPO>::setProximo(Elemento<TIPO>* pP)
{
	pProximo = pP;
}

template <class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getProximo()
{
	return pProximo;
}

template <class TIPO>
void Elemento<TIPO>::setAnterior(Elemento<TIPO>* pA)
{
	pAnterior = pA;
}

template <class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getAnterior()
{
	return pAnterior;
}

template <class TIPO>
void Elemento<TIPO>::setInfo(TIPO* pI)
{
	pInfo = pI;
}

template <class TIPO>
TIPO* Elemento<TIPO>::getInfo()
{
	return pInfo;
}