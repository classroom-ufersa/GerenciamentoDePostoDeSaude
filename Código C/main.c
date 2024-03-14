#include "medico/medico.h"
#include "paciente/paciente.h"
 
int main(void){

    char escolha;
    char verificarescolha[50];
    
    do
    {   
        printf("====MENU====\n\n");
        printf("1 - Registar medico\n");
        printf("2 - Consultar paciente\n");
        printf("3 - Remover medico\n");
        printf("4 - Remover paciente\n");
        printf("5 - Editar informacoes do paciente\n");
        printf("6 - Buscar paciente\n");
        printf("7 - Listar medicos e seus pacientes\n");
        printf("8 - Sair do programa\n\n");
        printf("============\n");
       
        printf("escolha: ");
        scanf(" %s", verificarescolha);

        escolha = verificarescolha[0];

        switch(escolha)
        {
            int tecla;
            case '1':
                system("cls");
                printf("nla\n");
            break;

            case '2':
                system("cls");
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