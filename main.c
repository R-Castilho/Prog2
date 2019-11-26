#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CAPACIDADE_MAXIMA 100 // valor total para armazenar em uma estrutura
  
struct aluno{
  int id;
  char nome[300];
  char cpf[15];
  char telefone[50];
  char email[100];
};

struct professor{
  int id;
  char nome[300];
  char cpf[15];
  char telefone[50];
  char email[100];
};

struct aula{
  int id;
  char tipo; 
  int dia;
  char horario[6];
  int id_prof;
  int minimo;
  int maximo;
  char faixa_etaria[6];
};

struct inscricao{
  int id_aula;
  int id_aluno;
};
    

// Protótipos 
// Gerais
void iniciar(int *nAlunos, struct aluno *alunos, int *nProfs, struct professor *professores, int *nAulas, struct aula *aulas);
void imprimirMenu();
int lerOpcao();

// Alunos
struct aluno leAluno();
int adicionaAluno(struct aluno aluno, struct aluno *alunos, int *nAlunos);
void arquivaAlunos(struct aluno *alunos, int nAlunos);

// Professores
struct professor leProf();
int adicionaProf(struct professor novoProf, struct professor *professores, int *nProfs);
void arquivaProfs(struct professor *professores, int nProfs);

struct aula leAula();
int adicionaAula(struct aula novoAula, struct aula *aulas, int *nAulas, struct professor *professores, int nProfs);
void arquivaAulas(struct aula *aulas, int nAulas);

void inscreverAluno(int id_aluno, int id_turma);
void cancelarInscricao(int id_aluno, int id_turma);
void fecharTurma(int n_alunos);
void confirmarTurmas();
void fecharPrograma();

// Programa Principal 
int main (){

  struct aluno alunos[CAPACIDADE_MAXIMA];
  int nAlunos;

  struct professor professores[CAPACIDADE_MAXIMA];
  int nProfs;

  struct aula aulas[CAPACIDADE_MAXIMA];
  int nAulas;

  struct inscricao inscricoes[CAPACIDADE_MAXIMA];
  //int nInscricoes;

  

  int opcao = 1;

  iniciar(&nAlunos, alunos, &nProfs, professores, &nAulas, aulas);
  
  do{
    imprimirMenu();
    opcao = lerOpcao();
    switch (opcao){
      case 1: // 1- Cadastrar aluno
        if(0){}; //P.O.G

        struct aluno novoAluno = leAluno();

        if(adicionaAluno(novoAluno, alunos, &nAlunos)){
          puts("Cadastro bem sucedido!\n");
        }
        else{
          puts("ERRO! O aluno não foi cadastrado.\n");
        }

        arquivaAlunos(alunos, nAlunos);

        break;

      case 2: // 2-  Cadastrar professor
        if(0){}; //P.O.G
        struct professor novoProf = leProf();

        if(adicionaProf(novoProf, professores, &nProfs)){
          puts("Cadastro bem sucedido!\n");
        }
        else{
          puts("ERRO! O professor não foi cadastrado.\n");
        }

        arquivaProfs(professores, nProfs);

        break;

      case 3: // 3- Cadastrar aulas
        if(0){}; //P.O.G

        struct aula novoAula = leAula();

        if(adicionaAula(novoAula, aulas, &nAulas, professores, nProfs)){
          puts("Cadastro bem sucedido!\n");
        }
        else{
          puts("ERRO! A aula não foi cadastrada.\n");
        }

        arquivaAulas(aulas, nAulas);

        break;
        
      case 4:  // 4- Inscrever aluno
        break;
        
      case 5:  // 5- Cancelar inscrição
        break;
  
      case 6:  // 6- Fechar turmas
        break;
      
      case 7:  // 7- Confirmar turmas
        break;

      case 8:  // 8- Fechar o programa
        printf("Encerrando o programa\n");
        exit(0);

        break;
      default:
        printf("Opcao invalida, tente novamente.\n");
        break;
      }
                    
      }while (opcao>0 && opcao<9);

}  // fim do main

// Funções auxiliares
// Função para imprimir na saída padrão o menu de funções do sistema
void imprimirMenu(){
  puts("Academia superação");
  puts("1- Cadastrar aluno");
  puts("2- Cadastrar professor");
  puts("3- Cadastrar aula");
  puts("4- Inscrever aluno");
  puts("5- Cancelar inscrição");
  puts("6- Fechar turmas");
  puts("7- Confirmar turmas");
  puts("8- Sair");
}
// Função para mostrar menu na tela e ler opção digitada
int lerOpcao(){
  int op;
  puts("Digite a opcao: ");
  scanf("%d", &op);
  return op;
}

// Função para iniciar variáveis do programa
void iniciar(int *nAlunos, struct aluno *alunos, int *nProfs, struct professor *professores, int *nAulas, struct aula *aulas){
  // Carregar alunos do arquivo
  *nAlunos = 0;
  FILE *fAlunos = fopen("alunos.csv", "r");
  if(fAlunos == NULL){
    printf("Erro de I/O");
    exit(1);
  }
  while(fscanf(fAlunos, "%i,%[^,],%[^,],%[^,],%[^\n]", &alunos[*nAlunos].id, alunos[*nAlunos].nome, alunos[*nAlunos].cpf, alunos[*nAlunos].telefone, alunos[*nAlunos].email) != EOF){
    *nAlunos += 1;
  }
  fclose(fAlunos);

  // Carregar professores do arquivo
  *nProfs = 0;
  FILE *fProfs = fopen("professores.csv", "r");
  if(fProfs == NULL){
    printf("Erro de I/O");
    exit(1);
  }
  while(fscanf(fProfs, "%i,%[^,],%[^,],%[^,],%[^\n]", &professores[*nProfs].id, professores[*nProfs].nome, professores[*nProfs].cpf, professores[*nProfs].telefone, professores[*nProfs].email) != EOF){
    *nProfs += 1;
  }
  fclose(fProfs);

  // Carregar aulas do arquivo
  *nAulas = 0;
  FILE *fAulas = fopen("aulas.csv", "r");
  if(fAulas == NULL){
    printf("Erro de I/O");
    exit(1);
  }
  while(fscanf(fAulas, "%i,%c,%i,%[^,],%i,%i,%i,%[^\n]", &aulas[*nAulas].id, &aulas[*nAulas].tipo, &aulas[*nAulas].dia, aulas[*nAulas].horario, &aulas[*nAulas].id_prof, &aulas[*nAulas].minimo, &aulas[*nAulas].maximo, aulas[*nAulas].faixa_etaria) != EOF){
    *nAulas += 1;
  }
  fclose(fAulas);
}

// Funções de Aluno
// Lê da entrada padrão e retorna um novo aluno
struct aluno leAluno(){
  struct aluno alu;

  printf("Cadastro de Aluno:");
  printf("\nId: ");
  scanf("%d", &alu.id);
  printf("Nome: ");
  scanf("%s", alu.nome);
  printf("CPF: ");
  scanf("%s", alu.cpf);
  printf("Telefone: ");
  scanf("%s", alu.telefone);
  printf("E-mail: ");
  scanf("%s", alu.email);

  return alu;
}
// Tenta adicionar um novo aluno à lista atual de alunos em memória.
// Retorno: 1 se for bem sucedido, caso contrário, 0.
int adicionaAluno(struct aluno novoAluno, struct aluno *alunos, int *nAlunos){
  if(*nAlunos < CAPACIDADE_MAXIMA){
    int repetido = 0; // Checa se o ID informado para o aluno já existe no banco de dados
    for(int i = 0; i < *nAlunos; i++){
      if(alunos[i].id == novoAluno.id){
        repetido = 1;
      }
    }
    if(repetido){
      puts("Já existe um aluno cadastrado com este ID.");
      return 0;
    }
    else{
      alunos[*nAlunos] = novoAluno;
      *nAlunos = *nAlunos + 1;
      return 1;
    }
  }
  else{puts("Limite de alunos atingindo!");}
  return 0;
}
// Escreve os alunos da memória no arquivo
void arquivaAlunos(struct aluno *alunos, int nAlunos){
  FILE *fAlunos = fopen("alunos.csv", "w");
  if(fAlunos == NULL){
    printf("Erro de I/O");
    exit(1);
  }
  for(int i = 0; i < nAlunos; i++){
    fprintf(fAlunos, "%d,%s,%s,%s,%s\n", alunos[i].id, alunos[i].nome, alunos[i].cpf, alunos[i].telefone, alunos[i].email);
  }
  fclose(fAlunos);
}


// Funções de Professor
// Lê da entrada padrão e retorna um novo professor
struct professor leProf(){
  
  struct professor prof;
  
  printf("Cadastro de Professor:");
  printf("\nId: ");
  scanf("%d", &prof.id);
  printf("Nome: ");
  scanf("%s", prof.nome);
  printf("CPF: ");
  scanf("%s", prof.cpf);
  printf("Telefone: ");
  scanf("%s", prof.telefone);
  printf("E-mail: ");
  scanf("%s", prof.email);
  
  return prof;
}

// Tenta adicionar um novo professor à lista atual de professores em memória.
// Retorno: 1 se for bem sucedido, caso contrário, 0.
int adicionaProf(struct professor novoProf, struct professor *professores, int *nProfs){
  if(*nProfs < CAPACIDADE_MAXIMA){
    int repetido = 0; // Checa se o ID informado para o professor já existe no banco de dados
    for(int i = 0; i < *nProfs; i++){
      if(professores[i].id == novoProf.id){
        repetido = 1;
      }
    }
    if(repetido){
      puts("Já existe um professor cadastrado com este ID.");
      return 0;
    }
    else{
      professores[*nProfs] = novoProf;
      *nProfs = *nProfs + 1;
      return 1;
    }
  }
  else{puts("Limite de professores atingindo!");}
  return 0;
}

// Escreve os professores da memória no arquivo
void arquivaProfs(struct professor *professores, int nProfs){
  FILE *fProfs = fopen("professores.csv", "w");
  if(fProfs == NULL){
    printf("Erro de I/O");
    exit(1);
  }
  for(int i = 0; i < nProfs; i++){
    fprintf(fProfs, "%d,%s,%s,%s,%s\n", professores[i].id, professores[i].nome, professores[i].cpf, professores[i].telefone, professores[i].email);
  }
  fclose(fProfs);
}

// Funções de aula
// Lê da entrada padrão e retorna uma nova aula
struct aula leAula(){
  struct aula aula;

  printf("Cadastro de Aula:");
  printf("\nId: ");
  scanf("%d", &aula.id);
  printf("Tipo: ");
  scanf(" %c", &aula.tipo);
  printf("Dia: ");
  scanf("%d", &aula.dia);
  printf("Horário: ");
  scanf("%s", aula.horario);
  printf("ID do professor: ");
  scanf("%d", &aula.id_prof);
  printf("Mínimo de alunos: ");
  scanf("%d", &aula.minimo);
  printf("Máximo de alunos: ");
  scanf("%d", &aula.maximo);
  printf("Faixa etária: ");
  scanf("%s", aula.faixa_etaria);

  return aula;
}
// Tenta adicionar uma nova aula à lista atual em memória.
// Retorno: 1 se for bem sucedido, caso contrário, 0.
int adicionaAula(struct aula novoAula, struct aula *aulas, int *nAulas, struct professor *professores, int nProfs){ 
  if(*nAulas < CAPACIDADE_MAXIMA){
    int repetido = 0; // Checa se o ID informado para a aula já existe no banco de dados
    for(int i = 0; i < *nAulas; i++){
      if(aulas[i].id == novoAula.id){
        repetido = 1;
      }
    }
    if(repetido){
      puts("Já existe uma aula cadastrada com este ID.");
      return 0;
    }
    else{
      int profExiste = 0; // Checa se o ID_PROF informado para a nova aula está atrelado a algum professor registrado no banco de dados
      for(int i = 0; i < nProfs; i++){
        if(professores[i].id == novoAula.id_prof){
          profExiste = 1;
        }
      }
      if(profExiste){ 
        aulas[*nAulas] = novoAula;
        *nAulas = *nAulas + 1;
        return 1;
      }
      else{
        puts("Não existe professor com o ID informado para a nova aula.");
        return 0;
      }
    }
  }
  else{puts("Limite de aulas atingindo!");}
  return 0;
};
// Escreve as aulas da memória no arquivo
void arquivaAulas(struct aula *aulas, int nAulas){
  FILE *fAulas = fopen("aulas.csv", "w");
  if(fAulas == NULL){
    printf("Erro de I/O");
    exit(1);
  }
  for(int i = 0; i < nAulas; i++){
    fprintf(fAulas, "%i,%c,%i,%s,%i,%i,%i,%s\n", aulas[i].id, aulas[i].tipo, aulas[i].dia, aulas[i].horario, aulas[i].id, aulas[i].minimo, aulas[i].maximo, aulas[i].faixa_etaria);
  }
  fclose(fAulas);
}
