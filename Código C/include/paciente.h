#define ArquivoPaciente "listadepacientes.txt"
#include "funcoes.h"
#include "medico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

#define MAX_CARACTER 300

// Estrutura do paciente
typedef struct paciente Paciente; // Fix struct name inconsistency

// Estrutura da lista de pacientes
typedef struct listaPaciente ListaPaciente;

// Função para criar lista de pacientes
void CriaListaPaciente(ListaPaciente **lista);

// Função para adicionar paciente a algum medico
void AdicionaPaciente(ListaPaciente **lista, Paciente *paciente);

// Função para remover paciente de algum medico
void RemovePaciente(ListaPaciente **lista, char *nome);

// Função para editar informações do paciente
void EditarInformacoesDoPaciente(ListaPaciente **lista);

//Função para buscar pacientes
void BuscarPaciente(ListaPaciente **lista);

// Função para listar os medicos e seus pacientes
void Listarmedico(ListaMedico **lista);

// Função para pegar os dados do arquivo passar para a lista
void NovoPacienteTxt(ListaPaciente **lista, char *nome, int idade, char *enfermidade, char *historico_medico);
