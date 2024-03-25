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

}
