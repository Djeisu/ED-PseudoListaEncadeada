#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pseudo-lista.h"

#define MAX 4

struct pLista {
    int info[MAX];
    int prox[MAX];
    int inicio;
    int livre;
    int nElement;
};

PLista* plst_cria(){
    PLista* pl = (PLista*)malloc(sizeof(PLista));
    pl->inicio = 0;
    pl->nElement = 0;

    pl->livre = int_random(pl);

    for(int i = 0; i <= MAX; i++){
        pl->info[i] = -1;
        pl->prox[i] = -1;
    }
    return pl;
}

PLista* plts_insere(PLista* pl, int info){
    if(pl->nElement < MAX){
    //if(pl->info[pl->livre] == -1){
        pl->nElement++;
        pl->info[pl->livre] = info;
        printf("\n\nValor %d Inserido com Sucesso! Restam %d espacos livres.\n\n\n", info, (MAX - pl->nElement));
        if((pl->nElement-1) == 0){
            pl->inicio = pl->livre;

            pl->livre = int_random(pl);
            return pl;
        } else if (pl->info[pl->inicio] >= info) {
            pl->prox[pl->livre] = pl->inicio;
            pl->inicio = pl->livre;
            pl->livre = int_random(pl);
            return pl;
        } else{
            int* vInfo = pl->info;
            int* vProx = pl->prox;

            int ant = pl->inicio;
            int prx = vProx[ant];

            while (prx != -1 && vInfo[prx] < info) {
                ant = prx;
                prx = vProx[prx];
            }
            
            vProx[ant] = pl->livre;
            vProx[pl->livre] = prx;

            pl->livre = int_random(pl);
            return pl;
        }
    }else{
        printf("\n\nLista Cheia!!!\n\n\n");
        return pl;
    }
}

int int_random(PLista* pl){
    for(int i = 0; i < MAX+1; i++)
        if(pl->info[i] == -1)
            return i;
}

void plst_get_nElement(PLista* pl){
    printf("\n\n A Lista possui: %d Elementos.\n\n\n", pl->nElement);
}

PLista* plts_altera(PLista* pl, int info, int newInfo){
    printf("\n\n\nItem: %d\n", info);
   pl = plts_remove(pl,info);
   pl = plts_insere(pl,newInfo);
   return pl;
}

PLista* plts_remove(PLista* pl, int info){
    int inBusca = plts_busca(pl, info);
    if(inBusca != -1){
        int valor;

        for(int i = 0; i <= MAX; i++){
            if(pl->prox[i] == inBusca)
                valor = i;        
        }

        printf("\n\nValor %d removido com sucesso\n\n\n", info);

        pl->prox[valor] = pl->prox[inBusca];
        pl->info[inBusca] = -1;
        pl->prox[inBusca] = -1;
        pl->nElement--;
        pl->livre = inBusca;
    }else{
        printf("\n\nO valor não consta na lista\n\n\n");
    }

    return pl;
}

void plst_get_inicio(PLista* pl){
    printf("\n\nO primeiro elemento da lista é: %d.\n\n\n", pl->info[pl->inicio]);
}

void plts_imprime(PLista* pl, int a){
    
    int i = pl->inicio;

    if(a == 1 || a == 2){
        printf("\n\nNúmero de elementos: %d. \n", pl->nElement);
        printf("Inicio: %d \n\n", pl->info[pl->inicio]);
    }

    if(a == 1){
        for(int i = 0; i < MAX; i++)
        {   
            printf("id: %d ", i);
            printf("info: %d ", pl->info[i]);
            printf("prox: %d.\n", pl->prox[i]);
        }
        printf("\n\n");
    }
    else if(a == 2 && plts_vazia(pl)){
        while(pl->prox[i] != -1){
        printf("info: %d \n", pl->info[i]);
        i = pl->prox[i];
        }

        printf("info: %d \n\n\n", pl->info[i]);
    }
    else{
        printf("Valor Inválido \n\n\n");
    }
}

int plts_vazia(PLista* pl){
    for(int i = 0; i < MAX+1; i++)
    {   
        if(pl->info[i] != -1)
            return 1;
    }
    return 0;
}

int plts_busca(PLista* pl, int info){
    for(int i = 0; i < MAX; i++)
    {
        if(pl->info[i] == info)
            return i;
    }
    return -1;
}

int plts_pseudo_busca(PLista* pl, int info){
    int f = pl->inicio;
    int count = 1;

    while(pl->prox[f] != -1 && pl->info[f] != info){
        f = pl->prox[f];
        count++;
    }
    return count;
}

void plts_busca_imprime(PLista* pl, int info){
    
    int i = plts_busca(pl,info);
    int count = plts_pseudo_busca(pl, info);

    if(i != -1){
        if(pl->prox[i] != -1)
            printf("\n\nO valor %d está na posição %d do vetor info (real), sua pseudo posição é %dª na lista, o próximo item é o %d.\n\n\n",info,i,count,pl->info[pl->prox[i]]);
        else
            printf("\n\nO valor %d está na posição %d do vetor info (real), sua pseudo posição é %dª na lista, este é o último valor da lista.\n\n\n",info,i,count);
    }
    else{
        printf("\n\nO valor não consta na lista\n\n\n");
    }
}

// void plst_get_inicio(PLista *pl) {
//   int min, temp;
//   for(int i = 0; i < pl->nElement; i++)  {     
//       min = i;
//       for(int j = 0; j < pl->nElement; j++){
//           if(pl->info[j] < pl->info[min]){
//             min = j;
//           }
//       }

//       if(i != min){
//         pl->inicio = min;
//         pl->prox[i] = min;
//       }
//   }
// }