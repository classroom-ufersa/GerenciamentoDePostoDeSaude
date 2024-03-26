#include "include/paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente{
    char nome[50];
    int idade;
    char enfermidade[100];
    char historico_medico[100];
};

void AdicionarPaciente(Paciente* paciente){

    FILE* arquivo = fopen(ArquivoPaciente, "a");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    printf("Digite o nome do paciente: ");
    scanf("%s", paciente->nome); 

    printf("Digite a idade do paciente: ");
    scanf("%d", &paciente->idade);

    printf("Digite a enfermidade do paciente: ");
    scanf("%s", paciente->enfermidade);

    printf("Digite o historico medico do paciente: ");
    scanf("%s", paciente->historico_medico);

    fprintf(arquivo, "%s %d %s %s\n", paciente->nome, paciente->idade, paciente->enfermidade, paciente->historico_medico);

    fclose(arquivo);
}

