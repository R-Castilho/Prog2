#include<stdio.h>
#include<stdlib.h>
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

    //Protótipos de funções de alunos
    void arquivaAlunos(struct aluno *alunos);
    struct aluno leAluno();
    
    struct professor CadastraProfessores();
    void arquivaProfessor(struct professor professor);
    
    void cadastraAula(struct aula aula);
    void inscreverAluno(int id_aluno, int id_turma);
    void cancelarInscricao(int id_aluno, int id_turma);
    void fecharTurma(int n_alunos);
    void confirmarTurmas();
    void fecharPrograma();


    // função para mostrar menu na tela e ler opção digitada
    int lerOpcao();
    
    // Programa Principal 
    int main (){
      struct aluno alunos[CAPACIDADE_MAXIMA];
      struct aula aulas[CAPACIDADE_MAXIMA];
      struct inscricao inscricoes[CAPACIDADE_MAXIMA];
      struct professor professores[CAPACIDADE_MAXIMA];


      int opcao = 1;
      
      do{
        opcao = lerOpcao();
        switch (opcao){
          case 1: // 1- Cadastra aluno
            if(0); //P.O.G
            struct aluno novoAluno;
            //Ler aluno da entrada padrão

            //Adicionar a alunos
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
            exit(0);
            break;

          default:
            printf("Opcao invalida, tente novamente.\n");
            break;
          }
                        
          }while (opcao>0 && opcao<9);
  
   }  // fim do main


  int lerOpcao(){
    int op;
    puts("Academia superação\nDigite a opcao: ");
    scanf("%d", &op);
    return op;
  }

  struct aluno leAluno(){
    struct aluno alu;

    printf("Cadastro Aluno:");
    printf("\nId: ");
    scanf("%d", &alu.id);
    printf("\nNome: ");
    scanf("%s", alu.nome);
    printf("\nCPF: ");
    scanf("%s", alu.cpf);
    printf("\nTelefone: ");
    scanf("%s", alu.telefone);
    printf("\nE-mail: ");
    scanf("%s", alu.email);

    return alu;
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