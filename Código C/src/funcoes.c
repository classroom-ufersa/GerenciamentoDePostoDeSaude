#include "/home/everson/Área de Trabalho/Correção2/everson2/everson/GerenciamentoDePostoDeSaude/Código C/include/funcoes.h"

int verificaCaracterEspecial (char* nome) {
    int i;
    for(i = 0; i < strlen(nome); i++){
        if(((nome[i] >= 33 && nome[i] <= 47) || (nome[i] >= 58 && nome[i] <= 64) || (nome[i] >= 91 && nome[i] <= 96) || (nome[i] >= 123 && nome[i] <= 126))){
            return 1;
        }
    }
    return 0;
}

//menu principal
void menu(){
    printf("1 - Registrar medico\n");
    printf("2 - Consultar paciente\n");
    printf("3 - Remover medico\n");
    printf("4 - Remover paciente\n");
    printf("5 - Editar informações de um paciente\n");
    printf("6 - Buscar paciente\n");
    printf("7 - Listar medicos e seus pacientes\n");
    printf("8 - Sair do programa\n");
    printf("============\n");
}

char verificaEscolha(char escolha) {
    while (getchar() != '\n'){
        printf("Digite uma opção válida: ");
        scanf("%c", &escolha);
    }
    return escolha;
}

void passarMaiuscula(char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) 
    {
        nome[i] = toupper(nome[i]);
    }
}

int Verificanum(char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (isdigit(nome[i])) {
            return 1;
        }
    }
    return 0;

}
int Verificachar(char* nome) {
    if (verificaCaracterEspecial(nome) == 1) {
        printf("Nome invalido! Digite apenas letras.\n");
        return 1;
    }
    if (Verificanum(nome) == 1) {
        printf("Nome invalido! Digite apenas letras.\n");
        return 1;
    }
    return 0;
}

// Função para verificar se a string contém apenas numeros inteiros
int VerificanumInt(int *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isdigit(nome[i])) {
            return 1; // Não são apenas números
        }
    }
    return 0; // São apenas números
}


