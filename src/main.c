/* COMPONENTES:
	Clemilson Dias
	Arthur Foscarini
	Rafael Galuschka
*/
/*
   main.c

   Arquivo principal do analisador sintático.
*/
#include "main.h"

/*
void yyerror (char const *mensagem)
{
  fprintf (stderr, "%s\n", mensagem);
}
*/
char arquivo_saida[] = "saida.dot";

int main (int argc, char **argv)
{
  gv_init(arquivo_saida);
  int resultado = yyparse();
  gv_close();
  return resultado;
}

