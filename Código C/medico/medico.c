#include "medico.h"
#include "paciente/paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medico{
    char nome[40];
    char especialidade[30];
    int CRM;
    Paciente* pacientes;
};

// Função void para registrar um médico
void RegistrarMedico (Medico *medico, char *Arquivo) {
  
  FILE *Arquivo = fopen(ArquivoMedico, "at");

  if (Arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo: %s\n", ArquivoMedico);
    exit(1);
  }
  
  // Leitura dos dados do médico
  printf("Nome: ");
  scanf(" [^\n]%*c", medico->nome);

  printf("CRM: ");
  scanf("%d", &medico->CRM);

  printf("Especialidade: ");
  scanf(" %[^\n]%*c", medico->especialidade);

  // Exibe os dados do médico
  printf("\n**Dados do Médico:**\n");
  printf("Nome: %s\n", medico->nome);
  printf("CRM: %d\n", medico->CRM);
  printf("Especialidade: %s\n", medico->especialidade);

  fclose(ArquivoMedico);
}