#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se a string contém apenas letras
int verificarApenasLetras(char* nome);

// Função para verificar se a string contém caracteres especiais
int verificaCaracterEspecial (char* nome);

// Função para passar a string para maiúscula
void passarMaiuscula(char *nome);

//função para verificar se a escolha do usuario é um numero e se é apenas um caracter
char verificaEscolha(char escolha);

//menu principal
void menu();

//Função para verificar se a string contém números
int Verificanum(char* nome);

//Função para verificar se a string contém letras
int Verificachar(char* nome);

// Função para verificar se a string contém apenas números inteiros
int VerificanumInt(int *nome);