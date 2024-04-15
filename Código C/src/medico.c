#include "/home/everson/Área de Trabalho/GerenciamentoDePostoDeSaude/Código C/include/medico.h"
#include "/home/everson/Área de Trabalho/GerenciamentoDePostoDeSaude/Código C/include/paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medico{
    char nome[40];
    char especialidade[30];
    int crm;
    ListaPaciente* pacientes; 
};

struct listaMedico{
    Medico* medicos;
    ListaMedico *prox;
};

void CriaListaMedico(ListaMedico **lista){
    *lista = NULL;
}

void AdicionaMedico(ListaMedico **lista, Medico *medico){
    ListaMedico *novo = (ListaMedico*) malloc(sizeof(ListaMedico));
    novo->medicos = medico;
    novo->prox = *lista;
    *lista = novo;    
}

void RemoveMedico(ListaMedico **lista, int crm){
    ListaMedico *aux = *lista;
    ListaMedico *ant = NULL;
    
    while(aux != NULL && aux->medicos->crm != crm){
        ant = aux;
        aux = aux->prox;
    }
    
    if(aux == NULL){
        printf("Medico nao encontrado!\n");
        return;
    }
    
    if(ant == NULL){
        *lista = aux->prox;
    }else{
        ant->prox = aux->prox;
    }
    
    free(aux);
    printf("Medico removido com sucesso!\n");
}

ListaMedico *AdicionaMedicosDoArquivo(char NomeMedico[], char Especialidade[], int CRM){
    ListaMedico *novo = (ListaMedico*) malloc(sizeof(ListaMedico));
    strcpy(novo->medicos->nome, NomeMedico);
    strcpy(novo->medicos->especialidade, Especialidade);
    novo->medicos->crm = CRM;
    novo->prox = NULL;
    return novo;
}