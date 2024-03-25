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

void coletarDadosPaciente(Paciente* paciente){

    FILE* arquivo = fopen(ArquivoPaciente, "a");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    printf("Digite o nome do paciente: ");
    fgets(paciente->nome, sizeof(paciente->nome), stdin);
    paciente->nome[strcspn(paciente->nome, "\n")] = '\0';

    printf("Digite a idade do paciente: ");
    scanf("%d", &paciente->idade);

    //limpa o buffer do teclado
    while (getchar() != '\n');

    printf("Digite a enfermidade do paciente: ");
    fgets(paciente->enfermidade, sizeof(paciente->enfermidade), stdin);
    paciente->enfermidade[strcspn(paciente->enfermidade, "\n")] = '\0';

    printf("Digite o historico medico do paciente: ");
    fgets(paciente->historico_medico, sizeof(paciente->historico_medico), stdin);
    paciente->historico_medico[strcspn(paciente->historico_medico, "\n")] = '\0';

    fclose(arquivo);
}
