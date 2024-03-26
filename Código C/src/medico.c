#include "include/medico.h"
#include "include/paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medico{
    char nome[40];
    char especialidade[30];
    int crm;
    Paciente* pacientes;
};

void RegistrarMedico(Medico* medico){

    FILE* arquivo = fopen(ArquivoMedico, "a");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    printf("Digite o nome do médico: ");
    scanf("%s", medico->nome);

    printf("Digite a especialidade do médico: ");
    scanf("%s", medico->especialidade);

    printf("Digite o CRM do médico: ");
    scanf("%d", &medico->crm);

    fprintf(arquivo, "%s %s %d %s \n", medico->nome, medico->especialidade, medico->crm, medico->pacientes->nome);
    printf("Novo medico adicionado!\n");
    fclose(arquivo);
}


