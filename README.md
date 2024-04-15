[![Typing SVG](https://readme-typing-svg.herokuapp.com/?color=FFFFFF&size=35&center=true&vCenter=true&width=1000&lines=Gerenciamento+de+Posto+de+Saúde;Éverson+Alisson+e+Luiz+Eduardo+:%29)](https://git.io/typing-svg)

<h1 align="center">Grupo 18: Gerenciamento de Posto de Saúde</h1>

## Doscente da turma
- [Rosana Cibely Batista Rego](https://github.com/roscibely)

## Componentes da equipe
- [Éverson Alisson Queiroz Silva](https://github.com/Everson-Alisson)
- [Luiz Eduardo de A. Rodrigues](https://github.com/LuizEdu-AR)


## Linguagem utilizada

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

Neste arquivo você verá:
- [Linguagem](#2.0-Linguagem)
- [Introdução](#2.0-Introdução)
- [Problemática](#3.0-problemática)
- [Descrição](#4.0-descrição)
- [Organização do repositório](#5.0-organização-do-repositório)
- [Listas encadeadas](#6.0-listas-encadeadas)
- [Funções em Médico](#7.0-funções-em-médico)
- [Funções em Paciente](#8.0-funções-em-paciente)
- [Funções em tratativas](#9.0--funções-em-tratativas)
- [Funções em main](#10.0-funções-em-main)

## **1.0-Linguagem**
![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

## **2.0-Introdução**
A administração de um posto de saúde é essencial para assegurar seu funcionamento adequado e eficiente, envolvendo a gestão dos pacientes e dos médicos. Um sistema de gerenciamento dedicado para postos de saúde é desenvolvido com o objetivo de simplificar todas as operações necessárias para o funcionamento da instituição.

## **3.0-Problemática**
Projete um sistema na Linguagem C para gerenciamento de um posto de satde. Seu sistema deve ser capaz de manipular médicos e pacientes.
## **4.0-Descrição**

Os médicos devem ter os seguintes atributos:
- nome;
- especialidade;
- CRM (Conselho Regional de Medicina);
- pacientes atendidos.

Os pacientes devem ter os seguintes atributos:
- nome;
- idade;
- enfermidade;
- histórico médico.

Um menu com as seguintes opções deverá ser apresentado:
1. Registrar médico;
2. Consultar paciente;
3. Remover médico;
4. Remover paciente;
5. Editar informações do paciente;
6. Buscar paciente;
7. Listar médicos e seus pacientes;
8. Sair;

A opção Sair é a única que permite sair do programa. Sendo assim, após cada operaçao, o programa volta
ao menu. Além disso, você deve levar em consideração O seguinte: a cada execuçao do seu programa, OS
dados devem ser carregados (armazenados em um arquivo texto); cada novo médico ou paciente cadastrado
deve ser inserido em ordem alfabética (para isso, você pode utilizar as funções da biblioteca padrão deC,
string.h); você deve atualizar o arquivo texto para refletir o estado atual dos dados em virtude da adição
ou remoção.

## **5.0-Organização do Repositório**
A organização desse repositório está disposta da seguinte forma:

``` 
📁 - GerenciamentoDePostoDeSaude
│
└─── bin
│
└─── include
        │
        ├──medico.h
        ├──paciente.h
│
└─── src
        │
        ├──medico.c
        ├──paciente.c
        ├──main.c
        ├──funcoes.c
        ├──dados.txt
│
└───README.md
```

## **6.0-Listas Encadeadas**

Neste projeto, o sistema de gerenciamento para óticas foi desenvolvido utilizando listas encadeadas, que possibilitam percorrer a lista em uma única direção, do início ao fim.

As listas encadeadas são compostas por nós que armazenam dados e um ponteiro para o próximo nó na sequência. Essa estrutura proporciona uma maneira eficiente de lidar com conjuntos de dados dinâmicos.

Apesar de permitirem apenas a travessia sequencial da lista, as listas encadeadas simples oferecem uma solução eficaz para diversas aplicações de gestão de dados, especialmente quando a ordem dos elementos é relevante e as operações de inserção e remoção são frequentes.

### **Vantagens**
As principais vantagens apresentadas pelo uso de Listas encadeadas são:

- **Flexibilidade:** Oferecem flexibilidade na inserção e remoção de elementos, uma vez que não requerem uma alocação contígua de memória.

- **Inserção e remoção eficiente:** Em comparação com estruturas de dados como vetores, as listas encadeadas oferecem operações eficientes de inserção e remoção de elementos, especialmente quando se trata de operações no meio da lista.

- **Baixo custo de realocação:** A inserção e remoção de elementos em uma lista encadeada não requerem realocação de memória, o que pode ser vantajoso em situações onde a quantidade de elementos na lista é desconhecida ou variável.

### **Desvantagens**
As principais desvantagens apresentadas pelo uso de Listas encadeadas são:

- **Acesso sequencial e menor desempenho:** O acesso aos elementos de uma lista encadeada é sequencial, o que pode resultar em desempenho inferior em comparação com estruturas de dados que oferecem acesso aleatório, como arrays.

- **Consumo de memória**: As listas encadeadas podem consumir mais memória do que outras estruturas de dados, devido à necessidade de armazenar ponteiros adicionais para cada elemento.

## **7.0-Funções em Médico** 
### Função CriaListaMedico

- **Descrição:** Esta função cria um novo nó de médico e o adiciona à lista encadeada de médicos.

```c
void CriaListaMedico(ListaMedico **lista);
```

### Função AdicionaMedico

- **Descrição:** Esta função pega os dados informados pelo usuário como, por exemplo, nome, especialidade e crm do médico, e adiciona na lista.

```c
void AdicionaMedico(ListaMedico **lista, Medico *medico);
```

### Função imprimir_consultas

- **Descrição:** Esta função imprime os detalhes de todas as consultas presentes na lista encadeada. Se a lista estiver vazia, uma mensagem indicando que não há consultas é exibida.

```c
void imprimir_consultas(Consulta *lista_consultas);
```
### Função RemoveMedico

- **Descrição:** Esta função remove o médico presente na lista usando o crm digitado pelo usuário.

```c
void RemoveMedico(ListaMedico **lista, int crm);
```
### Função AdicionaMedicosDoArquivo

- **Descrição:** Esta função carrega os dados dos médicos presentes no banco de dados(dados.txt).

```c
ListaMedico *AdicionaMedicosDoArquivo(char NomeMedico[], char Especialidade[], int CRM);
```
## **8.0-Funções em Paciente**
### Função CriaListaPaciente

- **Descrição:** Esta função cria um novo nó de paciente e o adiciona à lista encadeada de pacientes.

```c
void CriaListaPaciente(ListaPaciente **lista);
```

### Função AdicionaPaciente

- **Descrição:** Esta função pega os dados informados pelo usuário como, por exemplo, nome, idade, enfermidade e histórico médico do paciente, e adiciona na lista.

```c
void AdicionaPaciente(ListaPaciente **lista, Paciente *paciente);
```

### Função RemovePaciente

- **Descrição:** Esta função remove o paciente presente na lista usando o nome digitado pelo usuário.

```c
void RemovePaciente(ListaPaciente **lista, char *nome);
```
### Função EditarInformacoesDoPaciente

- **Descrição:** Esta função edita todos os dados do paciente selecionado pelo usuário.

```c
void EditarInformacoesDoPaciente(ListaPaciente **lista);
```
### Função BuscarPaciente

- **Descrição:** Esta função pede o nome do médico ao qual o paciente é designado e em seguida o nome do paciente, após isso ele lista as informações do paciente.

```c
void BuscarPaciente(ListaPaciente **lista);
```
### Função Listarmedico

- **Descrição:** Esta função lista os médicos e os pacientes que estão designados.

```c
void Listarmedico(ListaMedico **lista);
```
### Função NovoPacienteTxt

- **Descrição:** Esta função carrega os dados dos pacientes presentes no banco de dados(dados.txt).

```c
void NovoPacienteTxt(ListaPaciente **lista, char *nome, int idade, char *enfermidade, char *historico_medico);
```

## **9.0-Funções em Tratativas**

### Função verificaCaracterEspecial

- **Descrição:** Esta função vai verrificar se há algum caractere especial, exceto 'espaço'.

```c
int verificaCaracterEspecial (char* nome);
```

### Função passarMaiuscula

- **Descrição:** Esta função alterar todas as letras para maiúscula.

```c
void passarMaiuscula(char *nome);
```

### Função verificaEscolha

- **Descrição:** Esta função é usada para verificar se o usuário escolheu apenas as opções contidas no menu.

```c
char verificaEscolha(char escolha);
```

### Função menu

- **Descrição:** Esta função cria o menu principal do código.

```c
void menu();
```

### Função Verificanum

- **Descrição:** Esta função verifica se tem número na string que o usuário digitou.

```c
int Verificanum(char* nome);
```

### Função Verificachar

- **Descrição:** Esta função vai unir as funções Verificanum e verificaCaracterEspecial.

```c
int Verificachar(char* nome);
```

### Função VerificanumInt

- **Descrição:** Esta função vai verirficar se o que o usuário digitou não contém letras ou caracteres especiais.

```c
int VerificanumInt(int *nome);```

## **10.0-Funções em main**

### Função menu

- **Descrição:** Esta função cria o menu principal do código.

```c
void menu();
```