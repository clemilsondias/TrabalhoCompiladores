/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva 
*/

//estuturas de dados temporárias 
typedef struct {
   char *chave;
   int tipo;
   int simbolo;
   int lineNumber;
   struct comp_dict_item_t *prox;
} comp_dict_item_t;

typedef struct {
   int info;
   comp_dict_item_t *Itens;
} comp_dict_t;


//assinatura das funções
int dicionarioExiste(comp_dict_t *Dicionario);
comp_dict_t* dicionarioCria(int info);
comp_dict_item_t* dicionarioCriaItem(char *chave,int numLinha,int intTipo,int intSimbolo);
void dicionarioInsereItem(comp_dict_t *Dicionario, comp_dict_item_t *novoItem);
int dicionarioProcuraChave(comp_dict_t *Dicionario, char *Chave);
void dicionarioRemoveChave(comp_dict_t *Dicionario, char *Chave);
void dicionarioRemove(comp_dict_t *Dicionario);
void dicionarioImprime(comp_dict_t *Dicionario);
int dicionarioQtdeItens(comp_dict_t *Dicionario);
void dicionarioAtualizaLinha(comp_dict_t *Dicionario, char *chave, int novoValor);


comp_dict_item_t* dicionarioRetornaChave(comp_dict_t *Dicionario, char *Chave);
