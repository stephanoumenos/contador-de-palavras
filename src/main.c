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
  uint8_t separadores = 1, ultimo_foi_numero = 0;

  while (c != '\n'){
    scanf("%c", &c);
    if( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') ){
    /*! Se é uma letra/numero */
        if( separadores ){
            tamanho++;
            separadores = 0;
        }
        if(c>='0' && c<='9')
            ultimo_foi_numero = 1;

    } else{ ///< É um espaço/ponto/virgula/caracter de uma lingua estranha
        if(c!='.' && c!=','){
            separadores = 1;
            if( ultimo_foi_numero )
                ultimo_foi_numero = 0;
        } else{
            if( ! ultimo_foi_numero )
                separadores = 1;
            else
                ultimo_foi_numero = 0;
        }
    }
  }

  printf("%u", tamanho);

  return 0;
}
