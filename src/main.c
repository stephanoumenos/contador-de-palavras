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
  uint8_t separadores = 1; ///< FLAG para indicar se há um separador de palavras
  uint8_t ultimo_foi_numero = 0, ultimo_foi_ponto = 0; ///< Para contornar casos especiais

  while (1){
    scanf("%c", &c);
    if(c=='\n')
        break;
    if( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') ){
    /*! Se é uma letra/numero */
        if( separadores ){
            tamanho++;
            separadores = 0; ///< Limpa pendência
        }
        if(c>='0' && c<='9')
            ultimo_foi_numero = 1;
        else ///< Se não é um numero, começa a contar nova palavra
            if( ultimo_foi_ponto ){
                ultimo_foi_ponto = 0;
                tamanho++;
            }

    } else{ ///< É um espaço/ponto/virgula/caracter de uma lingua estranha
        if(c!='.' && c!=','){
            separadores = 1;
            /*! Limpa pendências */
            ultimo_foi_numero = 0;
            ultimo_foi_ponto = 0;
        } else{
            if( ! ultimo_foi_numero )
                separadores = 1; ///< Não é pra numeros decimais
            else
                ultimo_foi_ponto = 1;
        }
    }
  }

  printf("%u", tamanho);
  return 0;
}
