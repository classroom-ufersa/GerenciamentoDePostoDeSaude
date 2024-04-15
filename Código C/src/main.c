#include "medico.c"
#include "paciente.c"
#include "funcoes.c"
int main(void){
    
    char escolha;
    int verificacao;
    
    ListaMedico *medico;
    CriaListaMedico(&medico);

    //Carregando os dados do arquivo
    FILE *arquivo = fopen("dados.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    //carregando os dados do arquivo para a lista
    char linha[300];

    char NomedoMedicotxt[300];
    char Especialidadetxt[300];
    int CRMtxt;
    char NomedoPacientetxt[300];
    int Idadetxt;
    char Enfermidadetxt[300];
    char HistoricoMedicotxt[300];

    while(fgets(linha, 300, arquivo) != NULL){
        if(strstr(linha, "Nome do medico: ") != NULL){
            sscanf(linha, "Nome do medico: %s   Especialidade: %s   Crm: %d", NomedoMedicotxt, Especialidadetxt, &CRMtxt);
            Medico *medicodados = (Medico*) malloc(sizeof(Medico));
            strcpy(medicodados->nome, NomedoMedicotxt);
            strcpy(medicodados->especialidade, Especialidadetxt);
            medicodados->crm = CRMtxt;
            AdicionaMedico(&medico, medicodados);
        }else if(strstr(linha, "pacientes: ") != NULL){
            while(fgets(linha, 300, arquivo) != NULL && strstr(linha, "Nome: ") != NULL){
                sscanf(linha, "Nome: %s  Idade: %d  Enfermidade: %s  Historico: %s", NomedoPacientetxt, &Idadetxt, Enfermidadetxt, HistoricoMedicotxt);
                Paciente *paciente = (Paciente*) malloc(sizeof(Paciente));
                strcpy(paciente->nome, NomedoPacientetxt);
                paciente->idade = Idadetxt;
                strcpy(paciente->enfermidade, Enfermidadetxt);
                strcpy(paciente->historico_medico, HistoricoMedicotxt);
                AdicionaPaciente(&medico->medicos->pacientes, paciente);
            }
        }
    }

    fclose(arquivo);

    do
    {   
        menu();
        printf("Digite a opcao desejada: ");
        scanf(" %c", &escolha);
        verificacao = verificaEscolha(escolha);
        system("clear");
        
        switch(escolha)
        {
    
            case '1':
                //variavel para armazenar os dados do medico
                Medico *medicodados = (Medico*) malloc(sizeof(Medico));

                printf("Digite o nome do medico: ");
                scanf(" %[^\n]", medicodados->nome);
                verificacao = Verificachar(medicodados->nome);
                if(verificacao == 1){
                    while(Verificachar(medicodados->nome) == 1){

                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do medico: ");
                    scanf(" %[^\n]", medicodados->nome);
                    }
                }
                passarMaiuscula(medicodados->nome);

                printf("Digite a especialidade do medico: ");
                scanf(" %[^\n]", medicodados->especialidade);
                verificacao = Verificachar(medicodados->especialidade);
                if(verificacao == 1){
                    while(Verificachar(medicodados->especialidade) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite a especialidade do medico: ");
                    scanf(" %[^\n]", medicodados->especialidade);
                    }
                }
                passarMaiuscula(medicodados->especialidade);

                printf("Digite o CRM do medico: ");
                scanf("%d", &medicodados->crm);
                verificacao = VerificanumInt(&medicodados->crm);
                if(verificacao == 0){
                    while(VerificanumInt(&medicodados->crm) == 0){
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o CRM do medico: ");
                    scanf("%d", &medicodados->crm);
                    }
                }

                AdicionaMedico(&medico, medicodados);

                printf("Medico registrado com sucesso!\n");
                
            break;

            case '2':
                printf("Digite o nome do medico que ira fazer a consulta: ");
                char nome[50];
                scanf(" %[^\n]", nome);
                verificacao = Verificachar(nome);
                if(verificacao == 1){
                    while(Verificachar(nome) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do medico que ira fazer a consulta: ");
                    scanf(" %[^\n]", nome);
                    }
                }

                passarMaiuscula(nome);

                ListaMedico *aux = medico;
                
                while(aux != NULL && strcmp(aux->medicos->nome, nome) != 0){
                    aux = aux->prox;
                }
                
                if(aux == NULL){
                    printf("Medico nao encontrado!\n");
                    break;
                }
                
                //coletando dados dos pacientes
                Paciente *paciente = (Paciente*) malloc(sizeof(Paciente));
                printf("Digite o nome do paciente: ");
                scanf(" %[^\n]", paciente->nome);
                verificacao = Verificachar(paciente->nome);
                if(verificacao == 1){
                    while(Verificachar(paciente->nome) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do paciente: ");
                    scanf(" %[^\n]", paciente->nome);
                    }
                }
                passarMaiuscula(paciente->nome);

                printf("Digite a idade do paciente: ");
                scanf("%d", &paciente->idade);
                verificacao = VerificanumInt(&paciente->idade); 
                if(verificacao == 0){
                    while(VerificanumInt(&paciente->idade) == 0){
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite a idade do paciente: ");
                    scanf("%d", &paciente->idade);
                    }
                }
                
                printf("Digite a enfermidade do paciente: ");
                scanf(" %[^\n]", paciente->enfermidade);
                verificacao = Verificachar(paciente->enfermidade);
                if(verificacao == 1){
                    while(Verificachar(paciente->enfermidade) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite a enfermidade do paciente: ");
                    scanf(" %[^\n]", paciente->enfermidade);
                    }
                }

                passarMaiuscula(paciente->enfermidade);
                
                printf("Digite o historico medico do paciente: ");
                scanf(" %[^\n]", paciente->historico_medico);
                verificacao = Verificachar(paciente->historico_medico);
                if(verificacao == 1){
                    while(Verificachar(paciente->historico_medico) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o historico medico do paciente: ");
                    scanf(" %[^\n]", paciente->historico_medico);
                    }
                }
                passarMaiuscula(paciente->historico_medico);    

                AdicionaPaciente(&aux->medicos->pacientes, paciente);
                printf("Paciente registrado com sucesso!\n");

            break;

            case '3': 
                int crm;
                printf("Digite o CRM do medico que deseja remover: ");
                scanf("%d", &crm);
                verificacao = VerificanumInt(&crm);
                if(verificacao == 0){
                    while(VerificanumInt(&crm) == 1){
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o CRM do medico que deseja remover: ");
                    scanf("%d", &crm);
                    }
                }
                RemoveMedico(&medico, crm);
            break;

            case '4': 
                printf("Digite o nome do medico que ira remover o paciente: ");
                char nome2[50];
                scanf(" %[^\n]", nome2);
                verificacao = Verificachar(nome2);
                if(verificacao == 1){
                    while(Verificachar(nome2) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do medico que ira remover o paciente: ");
                    scanf(" %[^\n]", nome2);
                    }
                }
                passarMaiuscula(nome2);

                ListaMedico *aux4 = medico;
                
                while(aux4 != NULL && strcmp(aux4->medicos->nome, nome2) != 0){
                    aux4 = aux4->prox;
                }
                
                if(aux4 == NULL){
                    printf("Medico nao encontrado!\n");
                    break;
                }
                
                printf("Digite o nome do paciente que deseja remover: ");
                char nome3[50];
                scanf(" %[^\n]", nome3);
                verificacao = Verificachar(nome3);
                if(verificacao == 1){
                    while(Verificachar(nome3) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do paciente que deseja remover: ");
                    scanf(" %[^\n]", nome3);
                    }
                }
                passarMaiuscula(nome3);

                RemovePaciente(&aux4->medicos->pacientes, nome3);
               
            break;
            
            case '5':
                printf("Digite o nome do medico do paciente que deseja editar: ");
                char nome4[50];
                scanf(" %[^\n]", nome4);
                verificacao = Verificachar(nome4);
                if(verificacao == 1){
                    while(Verificachar(nome4) == 1){
                        
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do medico do paciente que deseja editar: ");
                    scanf(" %[^\n]", nome4);
                    }
                }
                passarMaiuscula(nome4);

                ListaMedico *aux5 = medico;

                while(aux5 != NULL && strcmp(aux5->medicos->nome, nome4) != 0){
                    aux5 = aux5->prox;
                }

                if(aux5 == NULL){
                    printf("Medico nao encontrado!\n");
                    break;
                }

                EditarInformacoesDoPaciente(&aux5->medicos->pacientes);

            break;

            case '6':
                printf("Digite o nome do medico a qual o paciente pertence:\n");
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
                    printf("Digite o nome do medico a qual o paciente pertence:\n");
                    scanf(" %[^\n]", nome5);
                    }
                }

                passarMaiuscula(nome5);

                ListaMedico *aux6 = medico;

                while(aux6 != NULL && strcmp(aux6->medicos->nome, nome5) != 0){
                    aux6 = aux6->prox;
                }

                if(aux6 == NULL){
                    printf("Medico nao encontrado!\n");
                    break;
                }

                BuscarPaciente(&aux6->medicos->pacientes);
            break;

            case '7':
                Listarmedico(&medico);
            break;

            default:
                system("clear");
                printf("Saindo do programa\n");
            break;
        
        }
    
    }while (escolha != '8');

        ListaMedico *aux = medico;

        arquivo = fopen("dados.txt", "w");
        //passando as barracas e os seus produtos para o arquivo
        while (aux != NULL)
        {
            fprintf(arquivo, "Nome do medico: %s   ", aux->medicos->nome);
            fprintf(arquivo, "Especialidade: %s   ", aux->medicos->especialidade);
            fprintf(arquivo, "Crm: %d\n", aux->medicos->crm);

            fprintf(arquivo, "pacientes: \n");
            
            ListaPaciente *aux2 = aux->medicos->pacientes;

            while (aux2 != NULL)
            {
                fprintf(arquivo, "Nome: %s  ", aux2->pacientes->nome);
                fprintf(arquivo, "Idade: %d  ", aux2->pacientes->idade);
                fprintf(arquivo, "Enfermidade: %s  ", aux2->pacientes->enfermidade);
                fprintf(arquivo, "Historico: %s\n", aux2->pacientes->historico_medico);
                
                aux2 = aux2->prox;
            }
            fprintf(arquivo, "\n");
            aux = aux->prox;
        }

        //fechando o arquivo
        fclose(arquivo);

    free(medico);

    printf("Programa encerrado com sucesso!\n");
    
    return 0;
}