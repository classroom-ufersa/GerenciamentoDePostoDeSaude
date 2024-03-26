#define ArquivoMedico "listademedicos.txt"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura para medicos 
typedef struct medico Medico;

//Função para registrar medicos
void RegistrarMedico(Medico* medico);
