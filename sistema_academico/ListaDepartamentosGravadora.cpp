#include "ListaDepartamentosGravadora.h"
#include <iostream>
#include <fstream>
using namespace std;

ListaDepartamentosGravadora::ListaDepartamentosGravadora(string arquivo)
	: ListaDepartamentos(), nomeArquivo(arquivo)
{}

ListaDepartamentosGravadora::~ListaDepartamentosGravadora() {}

void ListaDepartamentosGravadora::graveDepartamentos()
{
	std::ofstream out("departamentos.dat", std::ios::out);
	if (out) {
		Elemento<Departamento>* pElaux = getDepartamentoPrim();
		while (pElaux != NULL) {
			Departamento* paux = pElaux->getInfo();
			out << (paux->getNome()) << " " << (paux->getId())
				<< " " << (paux->getUniversidade())->getNome() << endl;
			pElaux = pElaux->getProximo();
		}
		cout << " Os departamentos foram gravados " << endl;
	}
	else {
		std::cerr << " Arquivo nao pode ser aberto " << endl;
		return;
	}
	out.close();
}

int ListaDepartamentosGravadora::recupereDepartamentos(ListaUniversidades& lu)
{
	limpaLista();

	int cont = 0;
	std::ifstream in("departamentos.dat", std::ios::in);
	if (in) {
		char nome[150], nomeuniv[150];
		int id;
		while (in >> nome >> id >> nomeuniv) {
			Universidade* puniv = lu.localizar(nomeuniv);
			if (puniv) {
				Departamento* pdep = new Departamento(id);
				pdep->setNome(nome);
				puniv->incluaDepartamento(pdep);
				incluaDepartamento(pdep);
				cont++;
			}
			else {
				cout << " universidade " << nomeuniv << " nao encontrada " << endl;
				cout << " departamento " << nome << " nao incluido " << endl;
				cout << endl;
			}
		}
		cout << " Os departamentos foram recuperados " << endl;
	}
	else {
		std::cerr << " Arquivo nao pode ser aberto " << endl;
		return 0;
	}
	in.close();
	return cont;
}