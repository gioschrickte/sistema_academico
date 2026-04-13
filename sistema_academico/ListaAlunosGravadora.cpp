#include "ListaAlunosGravadora.h"
#include "Disciplina.h"
#include "ListaDisciplinasGravadora.h"
#include <fstream>
#include <iostream>
using namespace std;

ListaAlunosGravadora::ListaAlunosGravadora(string arquivo)
	: ListaAlunos(), nomeArquivo(arquivo)
{}

ListaAlunosGravadora::~ListaAlunosGravadora(){}

void ListaAlunosGravadora::graveAlunos()
{
	ofstream out("alunos.dat", std::ios::out);
	if (out) {
		Elemento<Aluno>* pElaux = getAlunoPrim();

		while (pElaux != NULL) {
			Aluno* paux = pElaux->getInfo();

			out << paux->getNome() << " "
				<< paux->getRA() << " "
				<< paux->getId() << " " 
				<< paux->getDisciplina()->getNome() << endl;
			pElaux = pElaux->getProximo();
		}
		cout << " Os alunos foram gravados " << endl;
	}
	else {
		cerr << " Arquivo nao pode ser aberto " << endl;
		return;
	}
	out.close();
}

int ListaAlunosGravadora::recupereAlunos(ListaDisciplinasGravadora& ld) // precisa de ListaDisciplinas
{
	limpaLista();
	int cont = 0;

	std::ifstream in("alunos.dat", std::ios::in);
	if (in) {
		char nome[150], nomedisc[150];
		int id, RA;
		while (in >> nome >> RA >> id >> nomedisc) {
			Disciplina* pdisc = ld.localizar(nomedisc);
			if (pdisc) {
				Aluno* pal = new Aluno(id);
				pal->setNome(nome);
				pal->setRA(RA);
				pal->setDisciplina(pdisc);
				pdisc->incluaAluno(pal);
				incluaAluno(pal);
				cont++;
			}
			else {
				cout << " disciplina " << nomedisc << " nao encontrada " << endl;
				cout << " aluno " << nome << " nao incluido " << endl;
				cout << endl;
			}
		}
		cout << " Os alunos foram recuperados " << endl;
	}
	else {
		std::cerr << " Arquivo nao pode ser aberto " << endl;
		return 0;
	}
	in.close();
	return cont;
}