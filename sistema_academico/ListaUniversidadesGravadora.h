#pragma once
#include "ListaUniversidades.h"
#include <string>
using namespace std;

class ListaUniversidadesGravadora : public ListaUniversidades
{
private:
	string nomeArquivo;
public:
	ListaUniversidadesGravadora(string arquivo = "universidades.dat");
	~ListaUniversidadesGravadora();

	void graveUniversidades();
	int recupereUniversidades();
};