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
%type <tree_node> k declaracoes decl_funcao bloco expressao
		  retorno saida entrada comandos comando_simples
		  atribuicao lista_elementos chamada_funcao lista_argumentos
		  fluxo_controle
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

k: declaracoes k {printf("Tem mais decls...\n");
		  /*ADD NODE TO THE PARENT NODE, PASS PARENT NODE UP*/
		  if($1 != NULL && $2 != NULL){
			arvoreInsereNodo($1,$2);
		  	$$ = $1;
		  }
		  else
			$$ = $2;
   		 }
   |declaracoes {printf("Eh a ultima decl...\n");
		 /*PASS NODE UP (Won't be NULL if it is a function node)*/
		 $$ = $1;};

/* regra de declaracoes */
declaracoes: decl_variavel {printf("BISON -> é variável!\n");
			    $$ = NULL;
			   } 
           | decl_vetor {printf("BISON -> eh vetor!\n");
			 $$ = NULL;
			}
           | decl_funcao {printf("BISON -> eh funcao!\n");
			  comp_tree_t * nodo_funcao = arvoreCriaNodo(2/*FILHOS - 2? Comando + proxima funcao?*/,IKS_AST_FUNCAO);/*PASS NODE UP*/
			  $$ = nodo_funcao; 
			 };

/* tipos de variáveis e vetores */
tipo: TK_PR_INT
    | TK_PR_FLOAT
    | TK_PR_BOOL
    | TK_PR_CHAR
    | TK_PR_STRING;

/* declarações de variáveis e vetores */
decl_variavel: tipo ':' TK_IDENTIFICADOR ';' {printf("BISON -> decl variavel: %s\n",$3->chave);};
decl_vetor: tipo ':' TK_IDENTIFICADOR '[' TK_LIT_INT ']' ';' {printf("BISON -> decl vetor: %s\n",$3->chave);};

/* declaracao de parametro de função */
decl_parametro: tipo ':' TK_IDENTIFICADOR {printf("BISON -> decl parametro sem separador: %s\n",$3->chave);/*MAKE NODE, PASS UP*/}
              | tipo ':' TK_IDENTIFICADOR ',' decl_parametro {printf("BISON -> decl parametro com separador: %s\n",$3->chave);/*MAKE NODE, ADD CHILDREN NODES*/};

/* declaração de funções */
decl_funcao: cabecalho decl_locais bloco {
						/*Passar os nodos de comandos por aqui!!*/
						$$ = $3;//Algo assim...
					 }
	   | cabecalho bloco {
				/*Mesma coisa aqui...*/
				$$ = $2;
			     };

/* cabeçalho de função (linha da declaração) */
cabecalho: tipo ':' TK_IDENTIFICADOR '(' decl_parametro ')'
	 | tipo ':' TK_IDENTIFICADOR '(' ')';


/* regra para declaração de variáveis locais de funções */
decl_locais: decl_variavel decl_locais 
           | decl_variavel;

/* regra para bloco de comandos entre chaves */
bloco: '{' comandos '}' {
				comp_tree_t * nodo_bloco = arvoreCriaNodo(2,IKS_AST_BLOCO);//Filhos: comandos dentro do bloco e proximo comando.
				arvoreInsereNodo(nodo_bloco,$2);//Insere o nodo vindo de comandos. 
				$$ = nodo_bloco;
			}
     | '{' '}' {
			$$ = arvoreCriaNodo(1,IKS_AST_BLOCO);//Somente um filho - o proximo comando, que sera definido um nivel acima.
	       };
 

/* regra para sequência de comandos*/
comandos: comando_simples ';' comandos 	{
						arvoreInsereNodo($1,$3);
						$$ = $1;
					}
        | fluxo_controle  comandos	{
						arvoreInsereNodo($1,$2);
						$$ = $1;
					}
	| comando_simples ';'		{
						$$ = $1;
					}
	| fluxo_controle 		{
						$$ = $1;
					}
        | bloco ';' comandos		{
						arvoreInsereNodo($1,$3);
						$$ = $1;
					}
	| bloco				{
						$$ = $1;
					}
        | ';'				{
						$$ = NULL;				
	};

/* regra para comando único em then e else (sem ponto e vírgula) */
comando: comando_simples
	| fluxo_controle;

/* comandos simples, ou seja, comando + ponto e vírgula */
comando_simples: atribuicao		{$$ = $1;}
               | entrada		{$$ = $1;}
               | saida 			{$$ = $1;}
               | retorno 		{$$ = $1;}
               | chamada_funcao		{$$ = $1;};

/* regra para atribuições */
atribuicao: TK_IDENTIFICADOR '=' expressao				{	//TODO: ADICIONAR PONTEIROS PARA A TABELA DE SIMBOLOS NOS NODOS!!!
										$$ = arvoreCriaNodo(3,IKS_AST_IDENTIFICADOR); //AST_IDENTIFICADOR||AST_INDEXADO + EXPRESSAO + prox comando
									 	
									}
          | TK_IDENTIFICADOR '=' TK_LIT_STRING				{
										$$ = arvoreCriaNodo(3,IKS_AST_IDENTIFICADOR);
									}
          | TK_IDENTIFICADOR '=' TK_LIT_CHAR				{
										$$ = arvoreCriaNodo(3,IKS_AST_IDENTIFICADOR);
									}
          | TK_IDENTIFICADOR '[' expressao ']' '=' expressao		{
										$$ = arvoreCriaNodo(3,IKS_AST_VETOR_INDEXADO);
									};

/* regra de input */
entrada: TK_PR_INPUT TK_IDENTIFICADOR 	{
						$$ = arvoreCriaNodo(2,IKS_AST_INPUT);
						arvoreInsereNodo($$,arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR));
					};

/* regra de output*/
saida: TK_PR_OUTPUT lista_elementos	{
						$$ = arvoreCriaNodo(2,IKS_AST_OUTPUT);
						arvoreInsereNodo($$,$2);
					};

/* lista de elementos de output */
lista_elementos: TK_LIT_STRING	{
					$$ = arvoreCriaNodo(0,IKS_AST_LITERAL);//SERA O ULTIMO DA LISTA...
				} 
               | TK_LIT_STRING ',' lista_elementos 	{
								$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
								arvoreInsereNodo($$,$3);
							}
               | expressao 				{
								$$ = $1;
							}
               | expressao ',' lista_elementos		{	//TODO: PODE-SE TER A OPCAO DE TER MAIS FILHOS PARA A EXPRESSAO!! ALOCAR UM APONTADOR AO MENOS!!
								arvoreInsereNodo($1,$3);
								$$ = $1;
							};

/* regra de retorno */
retorno: TK_PR_RETURN expressao	{
					$$ = arvoreCriaNodo(2,IKS_AST_RETURN);
					arvoreInsereNodo($$,$2);
				};

/* regra para chamada de função */
chamada_funcao:   TK_IDENTIFICADOR '(' lista_argumentos ')' 	{ 
									$$ = arvoreCriaNodo(3,IKS_AST_CHAMADA_DE_FUNCAO);
									arvoreInsereNodo($$,$3);
								}
		| TK_IDENTIFICADOR '(' ')' 	{
							$$ = arvoreCriaNodo(3,IKS_AST_CHAMADA_DE_FUNCAO);//TODO: REVIEW
						};

/* regra para expressão aritmética */
expressao_aritmetica: expressao '+' expressao	{ 

						}
                    | expressao '-' expressao	{ 

						}
                    | expressao '*' expressao	{ 

						}
                    | expressao '/' expressao	{

						};

/* regra para expressão lógica */
expressao_logica: expressao TK_OC_LE expressao	{
							
						}
                | expressao TK_OC_GE expressao	{
							
						}
                | expressao '<' expressao	{
							
						}
                | expressao TK_OC_EQ expressao	{
							
						} 
                | expressao TK_OC_NE expressao	{
							
						}
                | expressao TK_OC_AND expressao	{
							
						}
                | expressao TK_OC_OR expressao	{
							
						};

/* regra para expressões em geral */
expressao: expressao_aritmetica	{
				}
         | expressao_logica	{
				}
         | '(' expressao ')'	{
				}
         | TK_IDENTIFICADOR '[' expressao ']'	{
						}
         | TK_IDENTIFICADOR	{
				}
         | TK_LIT_INT	{
			}
         | '-' TK_LIT_INT	{
				}
         | TK_LIT_TRUE	{
			}
         | TK_LIT_FALSE	{
			} 
         | TK_LIT_FLOAT	{
			}
         | '-' TK_LIT_FLOAT	{
				}  
         | chamada_funcao	{
				}
	 | TK_LIT_STRING	{
				}
	 | TK_LIT_CHAR	{
			};

/* regra para lista de argumentos de chamadas de funções */
lista_argumentos: expressao 	{
					$$ = $1;
				}
                | expressao ',' lista_argumentos	{
								$$ = $1;
								arvoreInsereNodo($1,$3);
							};

/* regras para fluxos de controle */
fluxo_controle: TK_PR_IF '(' expressao_logica ')' TK_PR_THEN then_else { }
              | TK_PR_IF '(' expressao_logica ')' TK_PR_THEN then TK_PR_ELSE then_else { }
              | TK_PR_WHILE '(' expressao_logica ')' TK_PR_DO comandos_while_do ';' { }
              | TK_PR_DO comandos_while_do TK_PR_WHILE '(' expressao_logica ')' ';' { };

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
