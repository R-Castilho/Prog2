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
    void iniciar(int *nAlunos, struct aluno *alunos);
    void imprimeMenu();
    int lerOpcao();

    struct aluno leAluno();
    int adicionaAluno(struct aluno aluno, struct aluno *alunos, int *nAlunos);
    void arquivaAlunos(struct aluno *alunos, int nAlunos);
    
    struct professor CadastraProfessores();
    void arquivaProfessor(struct professor professor);
    
    void cadastraAula(struct aula aula);
    void inscreverAluno(int id_aluno, int id_turma);
    void cancelarInscricao(int id_aluno, int id_turma);
    void fecharTurma(int n_alunos);
    void confirmarTurmas();
    void fecharPrograma();
    
    // Programa Principal 
    int main (){

      struct aluno alunos[CAPACIDADE_MAXIMA];
      int nAlunos;
      struct aula aulas[CAPACIDADE_MAXIMA];
      //int nAulas;
      struct inscricao inscricoes[CAPACIDADE_MAXIMA];
      //int nInscricoes;
      struct professor professores[CAPACIDADE_MAXIMA];
      //int nProfessores;

      int opcao = 1;

      iniciar(&nAlunos, alunos);
      
      do{
        imprimeMenu();
        opcao = lerOpcao();
        switch (opcao){
          case 1: // 1- Cadastrar aluno
            if(0){}; //P.O.G

            //Ler novo aluno da entrada padrão
            struct aluno novoAluno = leAluno();

            //Adicionar a alunos
            if(adicionaAluno(novoAluno, alunos, &nAlunos)){
              puts("Cadastro bem sucedido!\n");
            }
            else{
              puts("ERRO! O aluno não foi cadastrado.\n");
            }

            arquivaAlunos(alunos, nAlunos);

            break;

          case 2: // 2-  Cadastrar professor
            break;

          case 3: // 3- Cadastrar turma
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
  
  void imprimeMenu(){
    puts("Academia superação");
    puts("1- Cadastrar aluno");
    puts("2- Cadastrar professor");
    puts("3- Cadastrar turma");
    puts("4- Inscrever aluno");
    puts("5- Cancelar inscrição");
    puts("6- Fechar turmas");
    puts("7- Confirmar turmas");
    puts("8- Sair");
  }
  // função para mostrar menu na tela e ler opção digitada
  int lerOpcao(){
    int op;
    puts("Digite a opcao: ");
    scanf("%d", &op);
    return op;
  }

  // função para iniciar variáveis do programa
  void iniciar(int *nAlunos, struct aluno *alunos){
    *nAlunos = 0;
    FILE *fAlunos = fopen("alunos.csv", "r");
    if(fAlunos == NULL){
      printf("Erro de I/O");
      exit(1);
    }
    //Carregar alunos do arquivo
    while(fscanf(fAlunos, "%i,%[^,],%[^,],%[^,],%[^\n]", &alunos[*nAlunos].id, alunos[*nAlunos].nome, alunos[*nAlunos].cpf, alunos[*nAlunos].telefone, alunos[*nAlunos].email) != EOF){
      *nAlunos += 1;
    }
    fclose(fAlunos);
  }

  // Funções de Aluno
  // Lê da entrada padrão e retorna um novo aluno
  struct aluno leAluno(){
    struct aluno alu;

    printf("Cadastro Aluno:");
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
      int repetido = 0;
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

  // Escreve os alunos em memória no arquivo
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

  struct professor cadastraProfessores (){
    
    struct professor prof;
    
    printf("Cadastro Professor:");
    printf("\n Id: ");
    scanf("%d", &prof.id);
    printf("\n Nome: ");
    scanf("%s", prof.nome);
    printf("\n CPF: ");
    scanf("%s", prof.cpf);
    printf("\n Telefone: ");
    scanf("%s", prof.telefone);
    printf("\n E-mail: ");
    scanf("%s", prof.email);
    
    return prof;
  }