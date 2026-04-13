#include "Disciplina.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

// construtora e destrutora
Disciplina::Disciplina(int i, int na, const char* ac)
{
	id = i;
	cont_alunos = 0;
	numero_alunos = na;
	pDeptoAssociado = NULL;
	strcpy_s(area_conhecimento, ac);
}
Disciplina::~Disciplina()
{
	pDeptoAssociado = NULL;
}
// sets e gets
void Disciplina::setId(int n)
{
	id = n;
}
int Disciplina::getId()
{
	return id;
}
void Disciplina::setNome(const char* n)
{
	strcpy_s(nome, n);
}
const char* Disciplina::getNome()
{
	return nome;
}
void Disciplina::setDepartamento(Departamento* pd)
{
	pDeptoAssociado = pd;
}
Departamento* Disciplina::getDepartamento() {
	return pDeptoAssociado;
}
// metodos de inclusao na lista e de listagem
void Disciplina::incluaAluno(Aluno* pa)
{
	if (pa != NULL)
	{
		if ((cont_alunos < numero_alunos) || numero_alunos == -1)
		{
			ObjLAlunos.incluaAluno(pa);
			cont_alunos++;
		}
		else
			cout << "Aluno não incluído, turma ja lotada em " << numero_alunos << " alunos." << endl;
	}
	else
		cout << "Erro! Aluno não incluído, ponteiro inválido." << endl;
}
void Disciplina::listeAlunos()
{
	cout << "\n\n Alunos matriculados na disciplina " << area_conhecimento << ": " << endl;
	ObjLAlunos.listeAlunos();
}

void Disciplina::listeAlunos2()
{
	cout << "\n\n Alunos matriculados na disciplina " << area_conhecimento << ": " << endl;
	ObjLAlunos.listeAlunos2();
}