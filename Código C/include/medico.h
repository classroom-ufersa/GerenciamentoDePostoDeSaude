#define ArquivoMedico "listademedicos.txt"
#include "funcoes.h"    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Estrutura para medicos 
typedef struct medico Medico;

//Estrutura para lista de medicos
typedef struct listaMedico ListaMedico;

//Função para criar lista de medicos
void CriaListaMedico(ListaMedico **lista);

//Função para adicionar medico a lista
void AdicionaMedico(ListaMedico **lista, Medico *medico);

//Função para remover medico da lista
void RemoveMedico(ListaMedico **lista, int crm);

//Função para pegar os dados do arquivo passar para a lista
ListaMedico *AdicionaMedicosDoArquivo(char NomeMedico[], char Especialidade[], int CRM);
