#include "/home/everson/Área de Trabalho/GerenciamentoDePostoDeSaude/Código C/include/medico.h"
#include "/home/everson/Área de Trabalho/GerenciamentoDePostoDeSaude/Código C/include/paciente.h"
#include "/home/everson/Área de Trabalho/GerenciamentoDePostoDeSaude/Código C/include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificacao;

struct paciente{
    char nome[50];
    int idade;
    char enfermidade[100];
    char historico_medico[100];
};

struct listaPaciente{
    Paciente* pacientes;
    ListaPaciente *prox;
};

void CriaListaPaciente(ListaPaciente **lista){
    *lista = NULL;
}

void AdicionaPaciente(ListaPaciente **lista, Paciente *paciente){
    ListaPaciente *novo = (ListaPaciente*) malloc(sizeof(ListaPaciente));
    novo->pacientes = paciente;
    novo->prox = *lista;
    *lista = novo;    
}

void RemovePaciente(ListaPaciente **lista, char *nome){
    ListaPaciente *aux = *lista;
    ListaPaciente *ant = NULL;
    
    while(aux != NULL && strcmp(aux->pacientes->nome, nome) != 0){
        ant = aux;
        aux = aux->prox;
    }
    
    if(aux == NULL){
        printf("Paciente nao encontrado!\n");
        return;
    }
    
    if(ant == NULL){
        *lista = aux->prox;
    }else{
        ant->prox = aux->prox;
    }
    
    free(aux);
    printf("Paciente removido com sucesso!\n");
}

void EditarInformacoesDoPaciente(ListaPaciente **lista){
    printf("Digite o nome do paciente que deseja editar: ");
    char nome5[50];
    scanf(" %[^\n]", nome5);
    verificacao = Verificachar(nome5);
    if(verificacao == 1){
        while(Verificachar(nome5) == 1){
                        
            printf("Deseja tentar novamente? (s/n)\n");
            char tentar;
            scanf(" %c", &tentar);
            if(tentar == 'n'){
                break;
            }
            printf("Digite o nome do paciente que deseja editar: ");
            scanf(" %[^\n]", nome5);
        }
    }
    passarMaiuscula(nome5);

    ListaPaciente *aux = *lista;

    while(aux != NULL && strcmp(aux->pacientes->nome, nome5) != 0){
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("Paciente nao encontrado!\n");
        return;
    }
    
    printf("Digite o novo nome do paciente: ");
    scanf(" %[^\n]", aux->pacientes->nome);
    verificacao = Verificachar(aux->pacientes->nome);

    if(verificacao == 1){
        while(Verificachar(aux->pacientes->nome) == 1){
                        
            printf("Deseja tentar novamente? (s/n)\n");
            char tentar;
            scanf(" %c", &tentar);
            if(tentar == 'n'){
                break;
            }
            printf("Digite o novo nome do paciente: ");
            scanf(" %[^\n]", aux->pacientes->nome);
        }
    }
    passarMaiuscula(aux->pacientes->nome);

    printf("Digite a nova idade do paciente: ");
    scanf("%d", &aux->pacientes->idade);
    verificacao = VerificanumInt(&aux->pacientes->idade);
    if(verificacao == 0){
        while(VerificanumInt(&aux->pacientes->idade) == 0){
                        
            printf("Deseja tentar novamente? (s/n)\n");
            char tentar;
            scanf(" %c", &tentar);
            if(tentar == 'n'){
                break;
            }
            printf("Digite a nova idade do paciente: ");
            scanf("%d", &aux->pacientes->idade);
        }
    }
            
    printf("Digite a nova enfermidade do paciente: ");
    scanf(" %[^\n]", aux->pacientes->enfermidade);
    verificacao = Verificachar(aux->pacientes->enfermidade);
    if(verificacao == 1){
        while(Verificachar(aux->pacientes->enfermidade) == 1){
                        
            printf("Deseja tentar novamente? (s/n)\n");
            char tentar;
            scanf(" %c", &tentar);
            if(tentar == 'n'){
                break;
            }
            printf("Digite a nova enfermidade do paciente: ");
            scanf(" %[^\n]", aux->pacientes->enfermidade);
        }
    }
    passarMaiuscula(aux->pacientes->enfermidade);

    printf("Digite o novo historico medico do paciente: ");
    scanf(" %[^\n]", aux->pacientes->historico_medico);
    verificacao = Verificachar(aux->pacientes->historico_medico);
    if(verificacao == 1){
        while(Verificachar(aux->pacientes->historico_medico) == 1){
                        
            printf("Deseja tentar novamente? (s/n)\n");
            char tentar;
            scanf(" %c", &tentar);
            if(tentar == 'n'){
                break;
            }
            printf("Digite o novo historico medico do paciente: ");
            scanf(" %[^\n]", aux->pacientes->historico_medico);
        }
    }

    passarMaiuscula(aux->pacientes->historico_medico);

    printf("Informacoes do paciente editadas com sucesso!\n");
}

void BuscarPaciente(ListaPaciente **lista){
    printf("Digite o nome do paciente que deseja buscar: ");
    char nome6[50];
    scanf(" %[^\n]", nome6);
    verificacao = Verificachar(nome6);
    if(verificacao == 1){
        while(Verificachar(nome6) == 1){
                        
            printf("Deseja tentar novamente? (s/n)\n");
            char tentar;
            scanf(" %c", &tentar);
            if(tentar == 'n'){
                break;
            }
            printf("Digite o nome do paciente que deseja buscar: ");
            scanf(" %[^\n]", nome6);
        }
    }

    passarMaiuscula(nome6);

    ListaPaciente *aux = *lista;

    while(aux != NULL && strcmp(aux->pacientes->nome, nome6) != 0){
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("Paciente nao encontrado!\n");
        return;
    }

    printf("Nome: %s\n", aux->pacientes->nome);
    printf("Idade: %d\n", aux->pacientes->idade);
    printf("Enfermidade: %s\n", aux->pacientes->enfermidade);
    printf("Historico Medico: %s\n", aux->pacientes->historico_medico);
}

void Listarmedico(ListaMedico **lista)
{
    ListaMedico *aux = *lista;
    printf("======lista de medicos======\n\n");
    while(aux != NULL)
    {
        printf("Nome: %s\n", aux->medicos->nome);
        printf("Especialidade: %s\n", aux->medicos->especialidade);
        printf("CRM: %d\n\n", aux->medicos->crm);
        printf("Pacientes: \n\n");
        ListaPaciente *aux2 = aux->medicos->pacientes;
        while(aux2 != NULL)
        {
            printf("Nome: %s\n", aux2->pacientes->nome);
            printf("Idade: %d\n", aux2->pacientes->idade);
            printf("Enfermidade: %s\n", aux2->pacientes->enfermidade);
            printf("Historico Medico: %s\n\n", aux2->pacientes->historico_medico);
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }
    printf("======fim da lista de medicos======\n");
}

void NovoPacienteTxt(ListaPaciente **lista, char *nome, int idade, char *enfermidade, char *historico_medico){
    Paciente *novo = (Paciente*) malloc(sizeof(Paciente));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    strcpy(novo->enfermidade, enfermidade);
    strcpy(novo->historico_medico, historico_medico);
    AdicionaPaciente(lista, novo);
    printf("Paciente adicionado com sucesso!\n");
}
