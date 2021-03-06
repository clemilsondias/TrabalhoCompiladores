%{
/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/


#include <stdlib.h>
#include <string.h>
#include "../include/main.h"

int yylineno;
int escopo_eh_local;
int passou_declaracoes_funcao;
int com_eh_input;
int contador_args_chamada_funcao;
int contador_regressivo_args_chamada_funcao;
comp_dict_t *dicionario_escopo_global;
comp_dict_t *dicionario_escopo_local;
comp_dict_t *dicionario_atual;
comp_dict_item_t * pt_tabela_funcao;//Guarda um ponteiro para a entrada na tabela de simbolos da funcao que esta sendo reconhecida
comp_dict_item_t * pt_tabela_fun_chamada;

//Definicao de tamanhos de variaveis e vetores.
inline int sm_size_from_type_var(int type);
inline int sm_size_from_type_vec(int type,comp_list_t* dim_lst);


inline void sm_verify_if_variable(comp_dict_item_t* variable);
inline void sm_verify_if_vector(comp_dict_item_t* vector);
inline void sm_verify_if_function(comp_dict_item_t* item);
inline void inicializa_dic_escopo_global();
inline void inicializa_dic_escopo_local();
inline void sm_testa_tipos_output(comp_dict_item_t* item);
inline comp_dict_item_t* sm_define_tipo_funcao(int tipo_funcao, comp_dict_item_t* pt_tabela);
inline int sm_ret_verify_return_type(int fun_ret_type,int return_var_type);
inline void sm_insere_lista_args(int tipo,comp_dict_item_t* pt_id);
inline void sm_testa_qnt_args_missing(comp_dict_item_t* fun);
inline void sm_testa_qnt_args_excess_and_type(comp_dict_item_t* fun,comp_tree_t* expr);
inline int sm_fun_call_type_verify_coercion(int fun_arg_type,int expr_type);

//ETAPA 5
inline comp_list_t* sm_init_lista_dimensoes();
inline comp_list_t* sm_adiciona_dimensao(comp_list_t* lst,int t_dim);


%}

%union 
{ 
  comp_dict_item_t* symbol; 
};

%union
{
 comp_tree_t * tree_node;
};

%union
{
 int type_data;
};

%union
{
 comp_list_t* dim_lst;
};
 
/* Declaração dos tokens da gramática da Linguagem IKS */
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
		  fluxo_controle expressao_aritmetica expressao_logica
		  comando then then_else comandos_while_do
		  variavel_atr_simples variavel_atr_index_id variavel_atr_index_arvore
		  expressao_indexada_id chamada_funcao_id
%type <symbol> cabecalho id_funcao
%type <type_data> tipo decl_parametro
%type <dim_lst> dimensoes
%right '='
%nonassoc TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE '<' '>'
%left TK_OC_AND TK_OC_OR
%left '+' '-'
%left '*' '/'
%right '!'

%%
 /* Regras (e ações) da gramática da Linguagem K */


/* regra inicial da gramática */
s: {inicializa_dic_escopo_global();}
	k TOKEN_EOF {
		 if($2 != NULL){//Se tiver funcoes...
			 comp_tree_t * nodo_programa = arvoreCriaNodo(1,IKS_AST_PROGRAMA);
			 arvoreInsereNodo(nodo_programa,$2);
		 	 gv_declare(IKS_AST_PROGRAMA,(const void*)nodo_programa,NULL);
			 gv_connect(nodo_programa,$2);
		 }
		 return IKS_SYNTAX_SUCESSO; };

k: declaracoes {inicializa_dic_escopo_global();} k 	{
		 		if($1 != NULL && $3 != NULL){
					arvoreInsereNodo($1,$3);
			  		$$ = $3;
					gv_connect($1,$3);
			  	}
		  		else
					$$ = $3;
   		 	}
   |declaracoes		{$$ = $1;};

/* regra de declaracoes */
declaracoes: decl_variavel	{$$ = NULL;} 
           | decl_vetor		{$$ = NULL;}
	   | decl_funcao	{$$ =   $1;};

/* tipos de variáveis e vetores */
tipo: TK_PR_INT		{$$ = IKS_INT;}
    | TK_PR_FLOAT	{$$ = IKS_FLOAT;}
    | TK_PR_BOOL	{$$ = IKS_BOOL;}
    | TK_PR_CHAR	{$$ = IKS_CHAR;}
    | TK_PR_STRING	{$$ = IKS_STRING;};

/* declarações de variáveis e vetores */
decl_variavel: tipo ':' TK_IDENTIFICADOR ';'			{
									$3->tipo_dado = $1;
									$3->tipo_estrutura = IKS_TYPE_VARIABLE; //É uma variável simples...
									$3->tamanho = sm_size_from_type_var($1);
								};
decl_vetor: tipo ':' TK_IDENTIFICADOR dimensoes ';'	{
								$3->tipo_dado = $1;
								$3->tipo_estrutura = IKS_TYPE_VECTOR;//É um vetor...
								$3->lista_tamanhos_dimensao = $4;
								$3->tamanho = sm_size_from_type_vec($1,$4); 
							};

dimensoes:  '[' TK_LIT_INT ']'	{
					$$ = sm_init_lista_dimensoes();
					$$ = sm_adiciona_dimensao($$,atoi($2->chave));
				}
	  | '[' TK_LIT_INT ']' dimensoes	{
							$$ = sm_adiciona_dimensao($4,atoi($2->chave));
						};

/* declaracao de parametro de função */
decl_parametro: tipo ':' TK_IDENTIFICADOR {sm_insere_lista_args($1,$3);$3->tamanho = sm_size_from_type_var($1);}
              | tipo ':' TK_IDENTIFICADOR ',' {sm_insere_lista_args($1,$3);$3->tamanho = sm_size_from_type_var($1);} decl_parametro;

/* declaração de funções */
decl_funcao: cabecalho decl_locais passou_decl_action bloco {
						$$ = arvoreCriaNodo(2,IKS_AST_FUNCAO);/*PASS NODE UP*/
						$$->pt_tabela = (void*)$1;
						arvoreInsereNodo($$,$4);
						gv_declare(IKS_AST_FUNCAO,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
						gv_connect($$,$4);
					 }
	   | cabecalho passou_decl_action bloco {
				/*Mesma coisa aqui...*/
				$$ = arvoreCriaNodo(2,IKS_AST_FUNCAO);
				$$->pt_tabela = (void*)$1;
				arvoreInsereNodo($$,$3);
				gv_declare(IKS_AST_FUNCAO,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
				gv_connect($$,$3);
			     };

passou_decl_action: {passou_declaracoes_funcao = 1;};

/* cabeçalho de função (linha da declaração) */
cabecalho: tipo ':' id_funcao init_escopo_local_action '(' decl_parametro ')'	{$$ = sm_define_tipo_funcao($1,$3);}
	 | tipo ':' id_funcao init_escopo_local_action '(' ')'			{$$ = sm_define_tipo_funcao($1,$3);};

id_funcao: TK_IDENTIFICADOR {pt_tabela_funcao = $1; $$ = $1;};

init_escopo_local_action:{inicializa_dic_escopo_local();};


/* regra para declaração de variáveis locais de funções */
decl_locais: decl_variavel decl_locais 
           | decl_variavel;

/* regra para bloco de comandos entre chaves */
bloco: '{' comandos '}' {
				comp_tree_t * nodo_bloco = arvoreCriaNodo(2,IKS_AST_BLOCO);//Filhos: comandos dentro do bloco e proximo comando.
				if($2 != NULL)
					arvoreInsereNodo(nodo_bloco,$2);//Insere o nodo vindo de comandos. 
				$$ = nodo_bloco;
				gv_declare(IKS_AST_BLOCO,(const void*)$$,NULL);
				if($2 != NULL)
					gv_connect($$,$2);
			}
     | '{' '}' {
			$$ = arvoreCriaNodo(1,IKS_AST_BLOCO);//Somente um filho - o proximo comando, que sera definido um nivel acima.
			gv_declare(IKS_AST_BLOCO,(const void*)$$,NULL);
	       };
 

/* regra para sequência de comandos*/
comandos: comando_simples ';' comandos 	{
						if($3 != NULL){
							arvoreInsereNodo($1,$3);
							gv_connect($1,$3);
						}
						$$ = $1;
					}
        | fluxo_controle  comandos	{
						if($2 != NULL){
							arvoreInsereNodo($1,$2);
							gv_connect($1,$2);
						}
						$$ = $1;
					}
	| comando_simples ';'		{
						$$ = $1;
					}
	| fluxo_controle 		{
						$$ = $1;
					}
        | bloco ';' comandos		{
						if($3 != NULL){
							arvoreInsereNodo($1,$3);
							gv_connect($1,$3);
						}
						$$ = $1;
					}
	| bloco				{
						$$ = $1;
					}
        | ';'				{
						$$ = NULL;				
					};

/* regra para comando único em then e else (sem ponto e vírgula) */
comando: comando_simples{$$ = $1;}
       | fluxo_controle	{$$ = $1;};

/* comandos simples, ou seja, comando + ponto e vírgula */
comando_simples: atribuicao		{$$ = $1;}
               | entrada		{$$ = $1;}
               | saida 			{$$ = $1;}
               | retorno 		{$$ = $1;}
               | chamada_funcao		{$$ = $1;};
/*
//Modo antigo de se reconhecer uma atribuicao: deste modo, a ordem dos nodos na arvore criada pelo graphviz ficava confusa...
//atribuicao: TK_IDENTIFICADOR 	{
					comp_tree_t* id = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
					id->pt_tabela = $1;
					$$ = arvoreCriaNodo(3,IKS_AST_ATRIBUICAO);
					arvoreInsereNodo($$,id);
				} '='  expressao			{	//TODO: ADICIONAR PONTEIROS PARA A TABELA DE SIMBOLOS NOS NODOS!!!
										arvoreInsereNodo($$,$3);
										//$$ = arvoreCriaNodo(3,IKS_AST_ATRIBUICAO);
										//comp_tree_t* id = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR); //AST_IDENTIFICADOR||AST_INDEXADO + EXPRESSAO + prox comando
										//id->pt_tabela = $1;
										//arvoreInsereNodo($$,id);
										//arvoreInsereNodo($$,$3);

										//gv_declare(IKS_AST_ATRIBUICAO,(const void*)$$,NULL);
										//gv_declare(IKS_AST_IDENTIFICADOR,(const void*)id,((comp_dict_item_t*)id->pt_tabela)->chave);
										//gv_connect($$,id);
										//gv_connect($$,$3);
									}
          | TK_IDENTIFICADOR '[' expressao ']' '=' expressao		{
										$$ = arvoreCriaNodo(3,IKS_AST_ATRIBUICAO);
										comp_tree_t* idx = arvoreCriaNodo(2,IKS_AST_VETOR_INDEXADO);
										comp_tree_t* id = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR); //AST_IDENTIFICADOR||AST_INDEXADO + EXPRESSAO + prox comando
										id->pt_tabela = $1;
										arvoreInsereNodo($$,idx);
										arvoreInsereNodo($$,$6);
										arvoreInsereNodo(idx,id);
										arvoreInsereNodo(idx,$3);

										gv_declare(IKS_AST_ATRIBUICAO,(const void*)$$,NULL);
										gv_declare(IKS_AST_IDENTIFICADOR,(const void*)id,((comp_dict_item_t*)id->pt_tabela)->chave);
										gv_declare(IKS_AST_VETOR_INDEXADO,(const void*)idx,NULL);
										gv_connect($$,idx);
										gv_connect($$,$6);
										gv_connect(idx,id);
										gv_connect(idx,$3);
								};
*/
atribuicao:	variavel_atr_simples expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_ATRIBUICAO);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$2);
							gv_declare(IKS_AST_ATRIBUICAO,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$2);
							
							//Acoes semanticas...
							int has_to_convert = sm_atr_verify_coercion_possible($1->tipo_dado,$2->tipo_dado);//Determinar se deve ocorrer coercao.
							//TODO: usar este valor aqui, e depois para caso de vetor indexado tambem.	
						}

		|variavel_atr_index_id variavel_atr_index_arvore expressao ']' '=' expressao	{
													$$ = arvoreCriaNodo(3,IKS_AST_ATRIBUICAO);
													arvoreInsereNodo($$,$2);
													arvoreInsereNodo($$,$6);
													arvoreInsereNodo($2,$1);
													arvoreInsereNodo($2,$3);

													gv_declare(IKS_AST_ATRIBUICAO,(const void*)$$,NULL);
													gv_connect($$,$2);
													gv_connect($$,$6);
													gv_connect($2,$1);
													gv_connect($2,$3);
													sm_atr_verify_coercion_possible(IKS_INT,$3->tipo_dado);//TODO: coercao possivel nesse caso?
													int has_to_convert = sm_atr_verify_coercion_possible($1->tipo_dado,$6->tipo_dado);
								};


variavel_atr_simples:	TK_IDENTIFICADOR '='	{
							//Verificando que eh variavel...
							(void)sm_verify_if_variable($1);
							$$ = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
							$$->pt_tabela = (void*)$1;
							$$->tipo_dado = $1->tipo_dado;
							gv_declare(IKS_AST_IDENTIFICADOR,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
						};

variavel_atr_index_id: TK_IDENTIFICADOR		{
							//Verificando que eh vetor...
							(void)sm_verify_if_vector($1);
							$$ = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
							$$->pt_tabela = (void*)$1;
							$$->tipo_dado = $1->tipo_dado;
							gv_declare(IKS_AST_IDENTIFICADOR,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
						};
variavel_atr_index_arvore: '['	{
					$$ = arvoreCriaNodo(2,IKS_AST_VETOR_INDEXADO);
					gv_declare(IKS_AST_VETOR_INDEXADO,(const void*)$$,NULL);
				};

/* regra de input */
entrada: TK_PR_INPUT {com_eh_input = 1;} TK_IDENTIFICADOR 	{
						$$ = arvoreCriaNodo(2,IKS_AST_INPUT);
						comp_tree_t* id = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
						id->pt_tabela = (void*)$3;
						arvoreInsereNodo($$,id);
						gv_declare(IKS_AST_INPUT,(const void*)$$,NULL);
						gv_declare(IKS_AST_IDENTIFICADOR,(const void*)$$,((comp_dict_item_t*)id->pt_tabela)->chave);
						gv_connect($$,id);
					};

/* regra de output*/
saida: TK_PR_OUTPUT lista_elementos	{
						$$ = arvoreCriaNodo(2,IKS_AST_OUTPUT);
						arvoreInsereNodo($$,$2);
						
						gv_declare(IKS_AST_OUTPUT,(const void*)$$,NULL);
						gv_connect($$,$2);
					};

/* lista de elementos de output */
lista_elementos: expressao 				{
								sm_testa_tipos_output((comp_dict_item_t*)($1->pt_tabela));
								$$ = $1;
							}
               | expressao ',' lista_elementos		{
								sm_testa_tipos_output((comp_dict_item_t*)($1->pt_tabela));
								arvoreInsereNodo($1,$3);
								$$ = $1;
								
								gv_connect($$,$3);
							};

/* regra de retorno */
retorno: TK_PR_RETURN expressao	{
					int ret_coerc = sm_ret_verify_return_type(pt_tabela_funcao->tipo_dado,$2->tipo_dado);
					$$ = arvoreCriaNodo(2,IKS_AST_RETURN);
					arvoreInsereNodo($$,$2);
					gv_declare(IKS_AST_RETURN,(const void*)$$,NULL);
					gv_connect($$,$2);
				};

/* regra para chamada de função */
chamada_funcao:   chamada_funcao_id '(' lista_argumentos ')' 	{ 	sm_testa_qnt_args_missing((comp_dict_item_t*)($1->pt_tabela));
									$$ = arvoreCriaNodo(3,IKS_AST_CHAMADA_DE_FUNCAO);
									arvoreInsereNodo($$,$1);
									arvoreInsereNodo($$,$3);
									$$->tipo_dado = $1->tipo_dado;
									gv_declare(IKS_AST_CHAMADA_DE_FUNCAO,(const void*)$$,NULL);
									gv_connect($$,$1);
									gv_connect($$,$3);
								}
		| chamada_funcao_id '(' ')' 	{
							sm_testa_qnt_args_missing((comp_dict_item_t*)($1->pt_tabela));
							$$ = arvoreCriaNodo(3,IKS_AST_CHAMADA_DE_FUNCAO);
							arvoreInsereNodo($$,$1);
							$$->tipo_dado = $1->tipo_dado;
							gv_declare(IKS_AST_CHAMADA_DE_FUNCAO,(const void*)$$,NULL);
							gv_connect($$,$1);
						};
chamada_funcao_id: TK_IDENTIFICADOR	{
						$$ = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
						$$->pt_tabela = (void*)$1;
						$$->tipo_dado = $1->tipo_dado;
						gv_declare(IKS_AST_IDENTIFICADOR,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);

						//Etapa 4
						contador_args_chamada_funcao = 0;//Conta quantos argumentos estao sendo chamados na
						pt_tabela_fun_chamada = $1;
					};

/* regra para expressão aritmética */
expressao_aritmetica: expressao '+' expressao	{ 
							$$ = arvoreCriaNodo(3,IKS_AST_ARIM_SOMA);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_ARIM_SOMA,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);
							
							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
							$$->code = ILOC_concat_lists($$->code,$3->code);
							$$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_ADD),$1->result_reg,$2->result_reg,$2->result_reg);
						}
                    | expressao '-' expressao	{ 
							$$ = arvoreCriaNodo(3,IKS_AST_ARIM_SUBTRACAO);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_ARIM_SUBTRACAO,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);							
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_SUB),$1->result_reg,$2->result_reg,$2->result_reg);
						}
                    | expressao '*' expressao	{ 
							$$ = arvoreCriaNodo(3,IKS_AST_ARIM_MULTIPLICACAO);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_ARIM_MULTIPLICACAO,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_MULT),$1->result_reg,$2->result_reg,$2->result_reg);
						}
                    | expressao '/' expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_ARIM_DIVISAO);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_ARIM_DIVISAO,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);	

						}
		    | '-' expressao 		{
							$$ = arvoreCriaNodo(2,IKS_AST_ARIM_INVERSAO);
							arvoreInsereNodo($$,$2);
							gv_declare(IKS_AST_ARIM_INVERSAO,(const void*)$$,NULL);
							gv_connect($$,$2);

							$$->tipo_dado = $2->tipo_dado;
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_ADD/*??*/),,);
						};

/* regra para expressão lógica */
expressao_logica: expressao TK_OC_LE expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_LE);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_COMP_LE,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);
				
							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);
						}
                | expressao TK_OC_GE expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_GE);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_COMP_GE,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);	
						}
                | expressao '<' expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_L);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_COMP_L,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);
						}
		| expressao '>' expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_G);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_COMP_G,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);
						}
                | expressao TK_OC_EQ expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_IGUAL);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_COMP_IGUAL,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);
						} 
                | expressao TK_OC_NE expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_DIF);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_COMP_DIF,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);
						}
                | expressao TK_OC_AND expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_E);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_E,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);	
						}
                | expressao TK_OC_OR expressao	{
							$$ = arvoreCriaNodo(3,IKS_AST_LOGICO_OU);
							arvoreInsereNodo($$,$1);
							arvoreInsereNodo($$,$3);
							gv_declare(IKS_AST_LOGICO_OU,(const void*)$$,NULL);
							gv_connect($$,$1);
							gv_connect($$,$3);

							$$->tipo_dado = sm_infer_type_from_expr($1->tipo_dado,$3->tipo_dado);
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);
						}
		| '!' expressao 		{
							$$ = arvoreCriaNodo(2,IKS_AST_LOGICO_COMP_NEGACAO);
							arvoreInsereNodo($$,$2);
							gv_declare(IKS_AST_LOGICO_COMP_NEGACAO,(const void*)$$,NULL);
							gv_connect($$,$2);

							$$->tipo_dado = $2->tipo_dado;
							$$->code = ILOC_concat_lists($$->code,$1->code);
                                                        $$->code = ILOC_concat_lists($$->code,$3->code);
                                                        $$->code = ILOC_add_to_list($$->code,ILOC_create_operation(ILOC_DIV),$1->result_reg,$2->result_reg,$2->result_reg);
						};

/* regra para expressões em geral */
expressao: expressao_aritmetica	{	$$ = $1;
					$$->tipo_dado = $1->tipo_dado;
					$$->code = $1->code;//Pode dar problema caso se queira "passar" pelo codigo do nodo $1.
				}
         | expressao_logica	{	$$ = $1;
					$$->tipo_dado = $1->tipo_dado;
					$$->code = $1->code;
				}
         | '(' expressao ')'	{
					$$ = $2;
					$$->tipo_dado = $2->tipo_dado;
					$$->code = $2->code;
				}
         | expressao_indexada_id '[' expressao ']'	{
								$$ = arvoreCriaNodo(3,IKS_AST_VETOR_INDEXADO);
								arvoreInsereNodo($$,$1);
								arvoreInsereNodo($$,$3);
	
								gv_declare(IKS_AST_VETOR_INDEXADO,(const void*)$$,NULL);
								gv_connect($$,$1);
								gv_connect($$,$3);
								$$->tipo_dado = $1->tipo_dado;
							}
         | TK_IDENTIFICADOR	{
					$$ = arvoreCriaNodo(1/*pode ter mais!*/,IKS_AST_IDENTIFICADOR);
					$$->pt_tabela = (void*)$1;
					$$->tipo_dado = $1->tipo_dado;
					gv_declare(IKS_AST_IDENTIFICADOR,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
				}
         | TK_LIT_INT	{	
				$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
				$$->pt_tabela = (void*)$1;
				$$->tipo_dado = IKS_INT;
				gv_declare(IKS_AST_LITERAL,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
			}
         | TK_LIT_TRUE	{
				$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
				$$->pt_tabela = (void*)$1;
				$$->tipo_dado = IKS_BOOL;
				gv_declare(IKS_AST_LITERAL,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
			}
         | TK_LIT_FALSE	{	
				$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
				$$->pt_tabela = (void*)$1;
				$$->tipo_dado = IKS_BOOL;
				gv_declare(IKS_AST_LITERAL,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
			} 
         | TK_LIT_FLOAT	{	
				$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
				$$->pt_tabela = (void*)$1;
				$$->tipo_dado = IKS_FLOAT;
				gv_declare(IKS_AST_LITERAL,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
			}
         | chamada_funcao	{	$$ = $1;
					$$->tipo_dado = $1->tipo_dado;
				}
	 | TK_LIT_STRING{
				$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
				$$->pt_tabela = (void*)$1;
				$$->tipo_dado = IKS_STRING;

				//Adaptando a string de saida ao formato desejado...
				char * str_ptr = ((comp_dict_item_t*)$$->pt_tabela)->chave;
				char chave[strlen(str_ptr)+3];//Contando-se o '\0' e mais duas barras '\\'
				chave[0] = '\\';
				chave[1] = '\"';
				strcpy(chave+2,str_ptr+1);
				int pos = strlen(chave);
				chave[pos - 1] = '\\';
				chave[pos] = '\"';
				chave[pos + 1] = '\0';
				gv_declare(IKS_AST_LITERAL,(const void*)$$,chave);
			}
	 | TK_LIT_CHAR	{	
				$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
				$$->pt_tabela = (void*)$1;
				$$->tipo_dado = IKS_CHAR;
				gv_declare(IKS_AST_LITERAL,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
			};

expressao_indexada_id: 	TK_IDENTIFICADOR	{
							$$ = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
							$$->pt_tabela = (void*)$1;
							gv_declare(IKS_AST_IDENTIFICADOR,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
							$$->tipo_dado = $1->tipo_dado;//Olha a partir do tipo da tabela de simbolos.
						};

/* regra para lista de argumentos de chamadas de funções */
lista_argumentos: expressao 	{//Ultima expressao reconhecida, agora "subiremos" na arvore de derivacao testando cada tipo de argumento com as acoes da proxima regra.
					$$ = $1;
					contador_args_chamada_funcao++;
					contador_regressivo_args_chamada_funcao = contador_args_chamada_funcao;
					sm_testa_qnt_args_excess_and_type(pt_tabela_fun_chamada,$1);
				}
                | expressao ',' {contador_args_chamada_funcao++;} lista_argumentos	{
												$$ = $1;
												arvoreInsereNodo($1,$4);
												gv_connect($$,$4);
												sm_testa_qnt_args_excess_and_type(pt_tabela_fun_chamada,$1);
											};

/* regras para fluxos de controle */
fluxo_controle: TK_PR_IF '(' expressao_logica ')' TK_PR_THEN then_else	{
										$$ = arvoreCriaNodo(4,IKS_AST_IF_ELSE);
										arvoreInsereNodo($$,$3);//Condicao
										arvoreInsereNodo($$,$6);//Comando, se verdade
										$$->filhos[2] = NULL;//Comando, se falso //TODO : REVIEW THIS!!!!
										gv_declare(IKS_AST_IF_ELSE,(const void*)$$,NULL);
										gv_connect($$,$3);
										gv_connect($$,$6);
									}
              | TK_PR_IF '(' expressao_logica ')' TK_PR_THEN then TK_PR_ELSE then_else 	{ 
												$$ = arvoreCriaNodo(4,IKS_AST_IF_ELSE);
												arvoreInsereNodo($$,$3);//Condicao
												arvoreInsereNodo($$,$6);//Comando, se verdade
												arvoreInsereNodo($$,$8);//Comando, se falso
												gv_declare(IKS_AST_IF_ELSE,(const void*)$$,NULL);
												gv_connect($$,$3);
												gv_connect($$,$6);
												gv_connect($$,$8);
											}
              | TK_PR_WHILE '(' expressao_logica ')' TK_PR_DO comandos_while_do ';'	{
												$$ = arvoreCriaNodo(3,IKS_AST_WHILE_DO);
												arvoreInsereNodo($$,$3);//Condicao
												arvoreInsereNodo($$,$6);//Comando
												gv_declare(IKS_AST_WHILE_DO,(const void*)$$,NULL);
												gv_connect($$,$3);
												gv_connect($$,$6);
											}
              | TK_PR_DO comandos_while_do TK_PR_WHILE '(' expressao_logica ')' ';' 	{
												$$ = arvoreCriaNodo(3,IKS_AST_DO_WHILE);
												arvoreInsereNodo($$,$2);//Comando
												arvoreInsereNodo($$,$5);//Condicao
												gv_declare(IKS_AST_DO_WHILE,(const void*)$$,NULL);
												gv_connect($$,$2);
												gv_connect($$,$5);
											};

/* regra para blocos de comandos de then e else*/
then: comando	{
			$$ = $1;
		}
    | bloco	{
			$$ = $1;
		};
then_else: comando ';'	{
				$$ = $1;
			} 
         | bloco ';' 	{
				$$ = $1;
			};

comandos_while_do: comando	{
					$$ = $1;
				}
		| bloco		{
					$$ = $1;
				};

%%

int yyerror (char const *mensagem)
{
  fprintf (stderr, "ERRO %s na linha: %d\n",mensagem,yylineno);
  return IKS_SYNTAX_ERRO;
}

int sm_size_from_type_var(int type){
	switch(type){
		case IKS_INT:		{return IKS_SIZE_INT;}
		case IKS_FLOAT:		{return	IKS_SIZE_FLOAT;}
		case IKS_CHAR:		{return IKS_SIZE_CHAR;}
		case IKS_BOOL:		{return IKS_SIZE_BOOL;}
		case IKS_STRING:	{return 0;}//TODO: CUIDAR COM AS STRINGS!
		default:{
			fprintf(stderr, "ERRO : tipo informado inexistente...\n");
			exit(200);//TODO: o que fazer neste caso??
		} 
	};
}

inline int sm_size_from_type_vec(int type,comp_list_t* dim_lst){
	int length = listaCalculaProduto(dim_lst);
	switch(type){
		case IKS_INT:		{return IKS_SIZE_VECTOR_INT(length);}
		case IKS_FLOAT:		{return	IKS_SIZE_VECTOR_FLOAT(length);}
		case IKS_CHAR:		{return IKS_SIZE_VECTOR_CHAR(length);}
		case IKS_BOOL:		{return IKS_SIZE_VECTOR_BOOL(length);}
		case IKS_STRING:	{return 0;}//TODO: CUIDAR COM AS STRINGS!
		default:{
			fprintf(stderr, "ERRO : tipo informado inexistente...\n");
			exit(200);//TODO: o que fazer neste caso??
		} 
	};
}

inline int sm_infer_type_from_expr(int tau_one, int tau_two){

	switch(tau_one){
		case IKS_STRING:{if(tau_two == IKS_STRING) return IKS_STRING; else exit(IKS_ERROR_STRING_TO_X);}
		case IKS_CHAR:	{if(tau_two == IKS_CHAR)   return IKS_CHAR;   else exit(IKS_ERROR_CHAR_TO_X);  }
		default:{
			if(tau_two == IKS_STRING)
				exit(IKS_ERROR_STRING_TO_X);
			if(tau_two == IKS_CHAR)
				exit(IKS_ERROR_CHAR_TO_X);
			if(tau_two == IKS_FLOAT)
				return IKS_FLOAT;
			if(tau_two == IKS_INT)
				return IKS_INT;
			return IKS_BOOL;
		}
	};
}

/*
 *	Funcao que determina a possibilidade de coercao de valores em atribuicoes.
 */
int sm_atr_verify_coercion_possible(int type_var,int type_value){
	switch(type_var){
		case IKS_STRING:{if(type_value == IKS_STRING) return IKS_STRING; else 
											{
												if(type_value != IKS_CHAR)
													exit(IKS_ERROR_WRONG_TYPE);
												exit(IKS_ERROR_CHAR_TO_X);
											}}//TODO: ou seria IKS_ERROR_WRONG_TYPE??
		case IKS_CHAR:  {if(type_value == IKS_CHAR)   return IKS_CHAR;   else
											{
												if(type_value != IKS_STRING)
													exit(IKS_ERROR_WRONG_TYPE);  
												exit(IKS_ERROR_STRING_TO_X);
											}}
		default:{
			if(type_value == IKS_STRING)
				exit(IKS_ERROR_STRING_TO_X);
			if(type_value == IKS_CHAR)
				exit(IKS_ERROR_CHAR_TO_X);
			return type_var; //Fazer a coercao para qualquer tipo que seja, ja que qualquer uma eh possivel.
		}
	};

}

/*
 *	Verificacao do tipo do argumento de retorno de funcao.
 */
inline int sm_ret_verify_return_type(int fun_ret_type,int return_var_type){
	switch(fun_ret_type){
		case IKS_STRING:{if(return_var_type == IKS_STRING) return IKS_STRING; else exit(IKS_ERROR_WRONG_PAR_RETURN);}//TODO: ou seria IKS_ERROR_WRONG_TYPE??
		case IKS_CHAR:  {if(return_var_type == IKS_CHAR)   return IKS_CHAR;   else exit(IKS_ERROR_WRONG_PAR_RETURN);  }
		default:{
			if(return_var_type == IKS_STRING)
				exit(IKS_ERROR_WRONG_PAR_RETURN);
			if(return_var_type == IKS_CHAR)
				exit(IKS_ERROR_WRONG_PAR_RETURN);
			return fun_ret_type; //Fazer a coercao para qualquer tipo que seja, ja que qualquer uma eh possivel.
		}
	};
}

inline void sm_verify_if_variable(comp_dict_item_t* item){
	if(item->tipo_estrutura != IKS_TYPE_VARIABLE){
		if(item->tipo_estrutura == IKS_TYPE_VECTOR)
			exit(IKS_ERROR_VECTOR);//Caso em que se esta utilizando como variavel um identificador de um dado do tipo vetor.
		exit(IKS_ERROR_FUNCTION);
	}
}

inline void sm_verify_if_vector(comp_dict_item_t* item){
	if(item->tipo_estrutura != IKS_TYPE_VECTOR){
		if(item->tipo_estrutura == IKS_TYPE_VARIABLE)
			exit(IKS_ERROR_VARIABLE);
		exit(IKS_ERROR_FUNCTION);
	}
}

inline void sm_verify_if_function(comp_dict_item_t* item){
	if(item->tipo_estrutura != IKS_TYPE_FUNCTION){
		if(item->tipo_estrutura == IKS_TYPE_VARIABLE)
			exit(IKS_ERROR_VARIABLE);
		exit(IKS_ERROR_VECTOR);
	}
}

inline void inicializa_dic_escopo_global(){
	dicionario_atual = dicionario_escopo_global;
	escopo_eh_local = 0;
	passou_declaracoes_funcao = 0;
}

inline void inicializa_dic_escopo_local(){
	escopo_eh_local = 1;
	passou_declaracoes_funcao = 0;
	dicionario_escopo_global = dicionario_atual;
	dicionarioRemove(&dicionario_escopo_local);
	dicionario_atual = dicionario_escopo_local;
}

//Funcao que testa se o tipo do argumento utilizado num comando output eh correto.
inline void sm_testa_tipos_output(comp_dict_item_t* item){
	if(item->tipo_dado == IKS_CHAR)//Com os tipos atuais, unico caso onde a funcao nao esta definida
		exit(IKS_ERROR_WRONG_PAR_OUTPUT);
}

inline comp_dict_item_t* sm_define_tipo_funcao(int tipo_funcao, comp_dict_item_t* pt_tabela){
	pt_tabela_funcao = pt_tabela;
	pt_tabela->tipo_dado = tipo_funcao;
	pt_tabela->tipo_estrutura = IKS_TYPE_FUNCTION;
	return pt_tabela;
}

inline void sm_insere_lista_args(int tipo,comp_dict_item_t* pt_id){
	listaInsereNodo(&(pt_tabela_funcao->lista_args_funcao),listaCriaNodo(tipo));
	pt_id->tipo_dado = tipo;
	pt_id->tipo_estrutura = IKS_TYPE_VARIABLE;
}

inline void sm_testa_qnt_args_missing(comp_dict_item_t* fun){
	if(contador_args_chamada_funcao < listaQtdeNodos(fun->lista_args_funcao))
		exit(IKS_ERROR_MISSING_ARGS);
}
inline int sm_fun_call_type_verify_coercion(int fun_arg_type,int expr_type){
	switch(fun_arg_type){
		case IKS_STRING:{if(expr_type == IKS_STRING) return IKS_STRING; else exit(IKS_ERROR_WRONG_TYPE_ARGS);}//TODO: ou seria IKS_ERROR_WRONG_TYPE??
		case IKS_CHAR:  {if(expr_type == IKS_CHAR)   return IKS_CHAR;   else exit(IKS_ERROR_WRONG_TYPE_ARGS);}
		default:{
			if(expr_type == IKS_STRING)
				exit(IKS_ERROR_WRONG_TYPE_ARGS);
			if(expr_type == IKS_CHAR)
				exit(IKS_ERROR_WRONG_TYPE_ARGS);
			return fun_arg_type; //Fazer a coercao para qualquer tipo que seja, ja que qualquer uma eh possivel.
		}
	};
} 
inline void sm_testa_qnt_args_excess_and_type(comp_dict_item_t* fun,comp_tree_t* expr){
	if(contador_args_chamada_funcao > listaQtdeNodos(fun->lista_args_funcao))
		exit(IKS_ERROR_EXCESS_ARGS);
	contador_regressivo_args_chamada_funcao--;
	sm_fun_call_type_verify_coercion((listaRetornaNodoIdx(fun->lista_args_funcao,contador_regressivo_args_chamada_funcao))->info,expr->tipo_dado);
	
}

//ETAPA 5

inline comp_list_t* sm_init_lista_dimensoes(){
	return listaCria();
}

inline comp_list_t* sm_adiciona_dimensao(comp_list_t* lst,int t_dim){
	if(t_dim < 1)
		exit(IKS_ERROR_DIM_NOT_POSITIVE);
	return listaAdicionaNodo_Inicio(lst,listaCriaNodo(t_dim));//Adiciona novo elemento ao inicio da lista.
}

