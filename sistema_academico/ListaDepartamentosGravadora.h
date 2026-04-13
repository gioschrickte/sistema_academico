#pragma once
#include "ListaDepartamentos.h"
#include "ListaUniversidades.h"
#include <string>
using namespace std;

class ListaDepartamentosGravadora : public ListaDepartamentos
{
private:
	string nomeArquivo;
public:
	ListaDepartamentosGravadora(string arquivo = "departamentos.dat");
	~ListaDepartamentosGravadora();
	void graveDepartamentos();
	int recupereDepartamentos(ListaUniversidades &lu);
};