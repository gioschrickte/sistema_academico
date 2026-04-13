#pragma once
#include "Pessoa.h"
#include "ListaUniversidadesGravadora.h"
#include "ListaDepartamentosGravadora.h"
#include "ListaDisciplinasGravadora.h"
#include "ListaAlunosGravadora.h"

class Principal
{
private:
	// Contadores para identificadores;
	int cont_idUniv;
	int cont_idDisc;
	int cont_idDepart;
	int cont_idAluno;
	// Listas
	ListaUniversidadesGravadora LUniversidades;
	ListaDepartamentosGravadora LDepartamentos;
	ListaDisciplinasGravadora LDisciplinas;
	ListaAlunosGravadora LAlunos;
public:
	Principal();
	~Principal();
	void Executar();
	void CadDisciplina();
	void CadDepartamento();
	void CadUniversidade();
	void CadAluno();
	void GravarTudo();
	void GravarUniversidades();
	void GravarDepartamentos();
	void GravarDisciplinas();
	void GravarAlunos();
	void RecuperarTudo();
	void RecuperarUniversidades();
	void RecuperarDepartamentos();
	void RecuperarDisciplinas();
	void RecuperarAlunos();
	void MenuCad();
	void MenuExe();
	void MenuGravar();
	void MenuRecuperar();
	void Menu();
};