/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/

//estuturas de dados temporárias 
typedef struct comp_tree_t {
   int qtdeFilhos;
   int tipo;		//Tipo de nodo.
   int tipo_dado;	//Tipo de dado associado ao nodo.
   int result_reg;
   struct ILOC_OP_LIST * code;
   struct comp_dict_t * pt_tabela;
   struct comp_tree_t *filhos[];
} comp_tree_t;

//assinaturas das funções
int arvoreVazia(comp_tree_t *Arvore);
comp_tree_t* arvoreCria();
comp_tree_t* arvoreCriaNodo(int qtdeFilhos, int tipo);
int arvoreInsereNodo(comp_tree_t *Raiz, comp_tree_t *novoNodo);
void arvoreRemoveNodo1(comp_tree_t *Nodo);
void arvoreImprime(comp_tree_t *Arvore);
void arvoreRemoveNodo(comp_tree_t *Arvore, comp_tree_t *Nodo);
