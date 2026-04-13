#include "ListaUniversidadesGravadora.h"
#include <iostream>
#include <fstream>
using namespace std;

ListaUniversidadesGravadora::ListaUniversidadesGravadora(string arquivo)
	: ListaUniversidades(), nomeArquivo(arquivo)
{}

ListaUniversidadesGravadora::~ListaUniversidadesGravadora(){}

void ListaUniversidadesGravadora::graveUniversidades()
{
	ofstream out("universidades.dat", std::ios::out);
	if (out) {
		Elemento<Universidade>* paux = getUniversidadePrim();
		while (paux != NULL) {
			out << (paux->getInfo()->getNome()) << " " << (paux->getInfo()->getId()) << endl;
			paux = paux->getProximo();
		}
		cout << " As universidades foram gravadas " << endl;
	}
	else {
		std::cerr << " Arquivo nao pode ser aberto " << endl;
		return;
	}
	out.close();
}

int ListaUniversidadesGravadora::recupereUniversidades()
{
	limpaLista();

	int cont = 0;
	std::ifstream in("universidades.dat", std::ios::in);
	if (in) {
		char nome[150];
		int id;
		while (in >> nome >> id) {
			Universidade* puniv = new Universidade(id);
			puniv->setNome(nome);
			incluaUniversidade(puniv);
			cont++;
		}
		cout << " As universidades foram recuperadas " << endl;
	}
	else {
		std::cerr << " Arquivo nao pode ser aberto " << endl;
		return 0;
	}
	in.close();
	return cont;
}