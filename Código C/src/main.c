#include "include/medico.h"
#include "include/paciente.h"
#include "medico.c"
#include "paciente.c"
 
int main(void){
    
    Medico medico;
    char escolha;
    char verificarescolha[50];
    int ordem = 0;
    
    do
    {   
        printf("====MENU====\n\n");
        printf("1 - Registar medico\n");
        printf("2 - Adicionar paciente\n");
        printf("3 - Consultar paciente\n");
        printf("4 - Remover medico\n");
        printf("5 - Remover paciente\n");
        printf("6 - Editar informacoes do paciente\n");
        printf("7 - Buscar paciente\n");
        printf("8 - Listar medicos e seus pacientes\n");
        printf("9 - Sair do programa\n\n");
        printf("============\n");
       
        printf("escolha: ");
        scanf(" %s", verificarescolha);

        escolha = verificarescolha[0];

        switch(escolha)
        {
            int tecla;
            case '1':
                system("cls");
                RegistrarMedico(&medico);
                printf("nla\n");
            break;

            case '2':
                system("cls");
                AdicionarPaciente(&medico);
                printf("\n");
            break;

            case '3': 
                system("cls");
                printf("\n");
            break;

            case '4': 
                system("cls");
                printf("\n");
            break;
            
            case '5':
                system("cls");
                printf("\n");

            break;

            case '6':
                system("cls");
                printf("\n");
            break;

            case '7':
                system("cls");
                printf("\n");
            break;

            default:
                system("cls");
                printf("Saindo do programa\n");
            break;
        
        }
    
    }while (escolha != '8');
    
    printf("Programa encerrado com sucesso!\n");
    
    return 0;
}