#define ArquivoPaciente "listadepacientes.txt"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do paciente
typedef struct paciente Paciente;

//Função para coletar os dados dos pacientes
void AdicionarPaciente(Paciente* paciente);
