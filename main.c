#include <stdio.h>
#include <stdlib.h>
#include "pseudo-lista.h"

int main(int argc, char const *argv[])
{

    PLista* pl = plst_cria();

    // pl = plts_insere(pl, 95);
    // pl = plts_insere(pl, 37);
    // pl = plts_insere(pl, 52);
    // pl = plts_insere(pl, 65);
    // pl = plts_insere(pl, 22);
    // pl = plts_insere(pl, 5);
    // pl = plts_insere(pl, 10);
    // pl = plts_insere(pl, 75);

    // plts_imprime(pl);
    // plst_get_inicio(pl);

    int ctrl;
    int elemento;
    int newElemento;
    int a = 0;

    do{

        printf("1 - Inserir um Elemento \n");
        printf("2 - Quantos Elementos tem na lista? \n");
        printf("3 - Alterar Elemento da Lista \n");
        printf("4 - Remover Elemento da Lista \n");
        printf("5 - Imprimir Lista Completa \n");
        printf("6 - Imprimir 1ª Elemento da Lista \n");
        printf("7 - Testar se a lista está vazia \n");
        printf("8 - Buscar Elemento na lista \n");

        printf("\nEscolha uma ação: ");
        scanf("%d", &ctrl);

        switch(ctrl){
            case 1:
                printf("Informe um número inteiro: ");
                scanf("%d", &elemento);
                if(elemento >= 0)
                    pl = plts_insere(pl, elemento);
                else
                    printf("\n\nValor inválido, escolha outro número.\n\n");
                break;
            case 2:
                plst_get_nElement(pl);
                break;
            case 3:
                printf("Informe um número inteiro para alterar na lista: ");
                scanf("%d", &elemento);
                printf("Informe um novo número inteiro na lista: ");
                scanf("%d", &newElemento);
                if(elemento >= 0 && newElemento >= 0)
                    pl = plts_altera(pl, elemento, newElemento);
                else
                    printf("\n\nValor inválido, escolha outro número.\n\n");
                break;
            case 4:
                printf("Informe um número inteiro para remover da lista: ");
                scanf("%d", &elemento);
                if(elemento >= 0)
                    pl = plts_remove(pl,elemento);
                else
                    printf("\n\nValor inválido, escolha outro número.\n\n");
                break;
            case 5:
                printf("1 - Mostar Estrutura da Lista\n");
                
                if(plts_vazia(pl))
                    printf("2 - Mostrar Lista Ordenada\n");

                printf("\nEscolha uma ação: ");
                scanf("%d", &a);
                plts_imprime(pl, a);
                break;
            case 6:
                plst_get_inicio(pl);
                break;
            case 7:
                if(!plts_vazia(pl))
                    printf("\n\nLista Vazia\n\n\n");
                else
                    printf("\n\nLista Não Está Vazia\n\n\n");
                break;
            case 8:
                printf("Informe um número inteiro para buscar na lista: ");
                scanf("%d", &elemento);
                if(elemento >= 0)
                    plts_busca_imprime(pl,elemento);
                else
                    printf("\n\nValor inválido, escolha outro número.\n\n");
                break;
            default:
                if(ctrl == 0)
                    printf("\n\n Volte Sempre! \n\n\n");
                else
                    printf("\nValor inválido!!! escolha outro.\n\n\n");
                break;
        }

    }while(ctrl != 0);

    return 0;
}
