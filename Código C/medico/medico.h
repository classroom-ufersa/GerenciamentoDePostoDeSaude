#define ArquivoMedico "listademedicos.txt"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medico Medico;

void RegistrarMedico(Medico *medico, char *Arquivo);
