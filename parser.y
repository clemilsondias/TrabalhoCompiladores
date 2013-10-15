%{
/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/


#include <stdio.h>
//#include "../include/comp_dict.h"
#include "../include/main.h"

extern int  yylineno;

%}

%union 
{ 
  comp_dict_item_t* symbol; 
};

%union
{
 comp_tree_t * tree_node;
};

 
/* Declaração dos tokens da gramática da Linguagem K */
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token<symbol> TK_LIT_INT
%token<symbol> TK_LIT_FLOAT
%token<symbol> TK_LIT_FALSE
%token<symbol> TK_LIT_TRUE
%token<symbol> TK_LIT_CHAR
%token<symbol> TK_LIT_STRING
%token<symbol> TK_IDENTIFICADOR
%token TOKEN_ERRO
%token TOKEN_EOF
%type <tree_node> k
%type <tree_node> declaracoes

%right '='
%nonassoc TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE '<'
%left TK_OC_AND TK_OC_OR
%left '+' '-'
%left '*' '/'


%%
 /* Regras (e ações) da gramática da Linguagem K */


/* regra inicial da gramática */
s: k TOKEN_EOF { printf("RECONHECEU ENTRADA!\n");
		 printf("Valor de retorno: %p, Eh funcao: %d\n",$1, $1->tipo == IKS_AST_FUNCAO);
		 comp_tree_t * nodo_programa = arvoreCriaNodo(1/*NUMERO DE FILHOS?? 1??*/,IKS_AST_PROGRAMA);
		 arvoreInsereNodo($1,nodo_programa);
		 return IKS_SYNTAX_SUCESSO; };

k: declaracoes k {printf("Tem mais decls...\n");/*ADD NODE TO THE PARENT NODE, PASS PARENT NODE UP*/$$ = $2;}
   |declaracoes {printf("Eh a ultima decl...\n");/*PASS NODE UP IF FUNCAO*/ $$ = $1;};

/* regra de declaracoes */
declaracoes: decl_variavel {printf("BISON -> é variável!\n"); $$ = NULL;} 
           | decl_vetor {printf("BISON -> eh vetor!\n"); $$ = NULL;}
           | decl_funcao {printf("BISON -> eh funcao!\n");
			  comp_tree_t * nodo_funcao = arvoreCriaNodo(2/*FILHOS - 2? Comando + proxima funcao?*/,IKS_AST_FUNCAO);/*PASS NODE UP*/
			 $$ = nodo_funcao; 
			};

/* tipos de variáveis e vetores */
tipo: TK_PR_INT
    | TK_PR_FLOAT
    | TK_PR_BOOL
    | TK_PR_CHAR
    | TK_PR_STRING {printf("BISON -> tipo\n");};

/* declarações de variáveis e vetores */
decl_variavel: tipo ':' TK_IDENTIFICADOR ';' {printf("BISON -> decl variavel: %s\n",$3->chave);};
decl_vetor: tipo ':' TK_IDENTIFICADOR '[' TK_LIT_INT ']' ';' {printf("BISON -> decl vetor: %s\n",$3->chave);};

/* declaracao de parametro de função */
decl_parametro: tipo ':' TK_IDENTIFICADOR {printf("BISON -> decl parametro sem separador: %s\n",$3->chave);/*MAKE NODE, PASS UP*/}
              | tipo ':' TK_IDENTIFICADOR ',' decl_parametro {printf("BISON -> decl parametro com separador: %s\n",$3->chave);/*MAKE NODE, ADD CHILDREN NODES*/};

/* declaração de funções */
decl_funcao: cabecalho decl_locais bloco {printf("BISON -> decl função\n");}
	   | cabecalho bloco {printf("BISON -> decl funcao\n");};

/* cabeçalho de função (linha da declaração) */
cabecalho: tipo ':' TK_IDENTIFICADOR '(' decl_parametro ')' {printf("BISON -> cabeçalho: %s\n",$3->chave);}
	 | tipo ':' TK_IDENTIFICADOR '(' ')' {printf("BISON -> cabecalho sem parametros: %s\n", $3->chave);};

/* regra que processa as declarações de parametros de funções, se existirem */
/*parametros: decl_parametro parametros 
	  | decl_parametro {printf("BISON -> parametros\n");};*/

/* regra para declaração de variáveis locais de funções */
decl_locais: decl_variavel decl_locais 
           | decl_variavel {printf("BISON -> decl locais\n");};

/* regra para bloco de comandos entre chaves */
bloco: '{' comandos '}' {printf("BISON -> bloco\n");}
     | '{' '}';
 

/* regra para sequência de comandos*/
comandos: comando_simples ';' comandos {printf("BISON -> comandos via simples\n");} 
        | fluxo_controle  comandos {printf("BISON -> comandos via fluxo\n");}
	| comando_simples ';'
	| fluxo_controle 
        | bloco ';' comandos {printf("BISON -> comandos bloco\n");} 
	| bloco
        | ';'  {printf("BISON -> comandos so ponto e virgula\n");};

/* regra para comando único em then e else (sem ponto e vírgula) */
comando: comando_simples
	| fluxo_controle;

/* comandos simples, ou seja, comando + ponto e vírgula */
comando_simples: atribuicao 
               | entrada
               | saida 
               | retorno 
               | chamada_funcao;

/* regra para atribuições */
atribuicao: TK_IDENTIFICADOR '=' expressao {printf("BISON -> atribuição de expressão: %s = \n",$1->chave);}
          | TK_IDENTIFICADOR '=' TK_LIT_STRING {printf("BISON -> atribuição de string: %s = %s\n",$1->chave,$3->chave);}
          | TK_IDENTIFICADOR '=' TK_LIT_CHAR {printf("BISON -> atribuição de char: %s = %s\n",$1->chave,$3->chave);}    
          | TK_IDENTIFICADOR '[' expressao ']' '=' expressao {printf("BISON -> atribuição vetor expressao: %s =\n",$1->chave);}
          | TK_IDENTIFICADOR '[' expressao ']' '=' TK_LIT_STRING {printf("BISON -> atribuição vetor string: %s = %s\n",$1->chave,$6->chave);}
          | TK_IDENTIFICADOR '[' expressao ']' '=' TK_LIT_CHAR {printf("BISON -> atribuição vetor char: %s = %s\n",$1->chave,$6->chave);};    

/* regra de input */
entrada: TK_PR_INPUT TK_IDENTIFICADOR;

/* regra de output*/
saida: TK_PR_OUTPUT lista_elementos {printf("BISON -> output\n");};

/* lista de elementos de output */
lista_elementos: TK_LIT_STRING 
               | TK_LIT_STRING ',' lista_elementos 
               | expressao 
               | expressao ',' lista_elementos;

/* regra de retorno */
retorno: TK_PR_RETURN expressao;

/* regra para chamada de função */
chamada_funcao: TK_IDENTIFICADOR '(' lista_argumentos ')' { printf("BISON -> chamada de função: %s\n",$1->chave);};

/* regra para expressão aritmética */
expressao_aritmetica: expressao '+' expressao { printf("BISON -> aritmetica soma\n");}
                    | expressao '-' expressao { printf("BISON -> aritmetica subtração\n");}
                    | expressao '*' expressao { printf("BISON -> aritmetica multiplicacao\n");}
                    | expressao '/' expressao { printf("BISON -> aritmetica divisao\n");};

/* regra para expressão lógica */
expressao_logica: expressao TK_OC_LE expressao 
                | expressao TK_OC_GE expressao 
                | expressao '<' expressao  
                | expressao TK_OC_EQ expressao {printf("BISON -> teste igualdade\n");} 
                | expressao TK_OC_NE expressao {printf("BISON -> teste desigualdade\n");}
                | expressao TK_OC_AND expressao 
                | expressao TK_OC_OR expressao;

/* regra para expressões em geral */
expressao: expressao_aritmetica 
         | expressao_logica 
         | '(' expressao ')'
         | TK_IDENTIFICADOR '[' expressao ']' { printf("BISON -> expressão vetor\n");}
         | TK_IDENTIFICADOR { printf("BISON -> expressão ID: %s\n",$1->chave);}
         | TK_LIT_INT { printf("BISON -> expressão literal int: %s\n",$1->chave);}
         | '-' TK_LIT_INT { printf("BISON -> expressão literal int negativo: %s\n",$2->chave);}
         | TK_LIT_TRUE 
         | TK_LIT_FALSE  
         | TK_LIT_FLOAT { printf("BISON -> expressão literal float: %s\n",$1->chave);}
         | '-' TK_LIT_FLOAT  
         | chamada_funcao;

/* regra para lista de argumentos de chamadas de funções */
lista_argumentos: TK_LIT_CHAR
                | TK_LIT_CHAR ',' lista_argumentos 
                | TK_LIT_STRING 
                | TK_LIT_STRING ',' lista_argumentos 
                | expressao 
                | expressao ',' lista_argumentos 
                |;

/* regras para fluxos de controle */
fluxo_controle: TK_PR_IF '(' expressao_logica ')' TK_PR_THEN then_else {printf("BISON -> IF sem else\n");}
              | TK_PR_IF '(' expressao_logica ')' TK_PR_THEN then TK_PR_ELSE then_else {printf("BISON -> IF com else\n");}
              | TK_PR_WHILE '(' expressao_logica ')' TK_PR_DO comandos_while_do ';' {printf("BISON -> while\n");}
              | TK_PR_DO comandos_while_do TK_PR_WHILE '(' expressao_logica ')' ';' {printf("BISON -> do while\n");};

/* regra para blocos de comandos de then e else*/
then: comando {printf("BISON -> fim then comando\n");}
    | bloco {printf("BISON -> fim then bloco\n");};
then_else: comando ';' {printf("BISON -> fim else comando\n");} 
         | bloco ';' {printf("BISON -> fim else bloco\n");};

comandos_while_do: comando
		| bloco;

%%

int yyerror (char const *mensagem)
{
  fprintf (stderr, "ERRO %s na linha: %d\n",mensagem,yylineno);
  return IKS_SYNTAX_ERRO;
}
