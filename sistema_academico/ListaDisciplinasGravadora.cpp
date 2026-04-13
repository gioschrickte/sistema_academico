#include "ListaDisciplinasGravadora.h"
#include <fstream>
#include <iostream>
using namespace std;

ListaDisciplinasGravadora::ListaDisciplinasGravadora(string arquivo)
	: ListaDisciplinas(), nomeArquivo(arquivo)
{}

ListaDisciplinasGravadora::~ListaDisciplinasGravadora(){}

void ListaDisciplinasGravadora::graveDisciplinas()
{
	ofstream out("disciplinas.dat", std::ios::out);
	if (out) {
		Elemento<Disciplina>* pElaux = getDisciplinaPrim();
		while (pElaux != NULL) {
			Disciplina* paux = pElaux->getInfo();
			out << (paux->getNome()) << " " << (paux->getId())
				<< " " << (paux->getDepartamento())->getNome() << endl;
			pElaux = pElaux->getProximo();
		}
		cout << " As disciplinas foram gravadas " << endl;
	}
	else {
		std::cerr << " Arquivo nao pode ser aberto " << endl;
		return;
	}
	out.close();
}

int ListaDisciplinasGravadora::recupereDisciplinas(ListaDepartamentos& ld)
{
	limpaLista();

	int cont = 0;
	std::ifstream in("disciplinas.dat", std::ios::in);
	if (in) {		
		char nome[150], nomedep[150];
		int id;
		while (in >> nome >> id >> nomedep) {
			Departamento* pdep = ld.localizar(nomedep);
			if (pdep) {
				Disciplina* pdisc = new Disciplina(id);
				pdisc->setNome(nome);
				pdisc->setDepartamento(pdep);
				pdep->incluaDisciplina(pdisc);
				incluaDisciplina(pdisc);
				cont++;
			}
			else {
				cout << " departamento " << nomedep << " nao encontrado " << endl;
				cout << " disciplina " << nome << " nao incluida " << endl;
				cout << endl;
			}
		}
		cout << " As disciplinas foram recuperados " << endl;
	}
	else {
		std::cerr << " Arquivo nao pode ser aberto " << endl;
		return 0;
	}
	in.close();
	return cont;
}