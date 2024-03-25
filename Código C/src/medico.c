#include "include/medico.h"
#include "include/paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medico{
    char nome[40];
    char especialidade[30];
    int CRM;
    Paciente* pacientes;
};

void coletarDadosMedico(Medico* medico){

    FILE* arquivo = fopen(ArquivoMedico, "a");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    printf("Digite o nome do médico: ");
    fgets(medico->nome, sizeof(medico->nome), stdin);
    medico->nome[strcspn(medico->nome, "\n")] = '\0';

    printf("Digite a especialidade do médico: ");
    fgets(medico->especialidade, sizeof(medico->especialidade), stdin);
    medico->especialidade[strcspn(medico->especialidade, "\n")] = '\0';

    printf("Digite o CRM do médico: ");
    scanf("%d", &medico->CRM);

    //limpa o buffer do teclado
    while (getchar() != '\n');

    fclose(arquivo);
}
