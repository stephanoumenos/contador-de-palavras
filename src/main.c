/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <inttypes.h>

int main()
{
  char c;
  unsigned int tamanho = 0;

  while (c != '\n'){
    scanf("%c", &c);
    if( (c>='a' && c<='z') || (c>='A' && c<='Z') ){
    /*! Se é uma letra */

    } else{ ///< É um espaço/ponto/virgula/caracter de uma lingua estranha

    }
  }

  printf("%u", tamanho);

  return 0;
}
