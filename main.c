#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define DIMHEAP 50

 typedef struct heap{
    int chaves[DIMHEAP];
    int n;
}heap;
    heap h;

int insercaoHeap(int x){
    if (h.n==DIMHEAP){
        return (-1);
    }
    h.n++;
    h.chaves[h.n]=x;
    subir(h.n);
    return(h.n);
    }
void subir(int i){
    int j;
    int aux;
    j=i/2;
    if(j>=1){
        if(h.chaves[i]<h.chaves[j]){
            aux=h.chaves[i];
            h.chaves[i]=h.chaves[j];
            h.chaves[j]=aux;
            subir(j);
        }
    }
}
int remocaoHeap(){
    int j;
    int aux;
    if(h.n==0)
        return(-1);              //heap vazia
    aux=h.chaves[1];
    h.chaves[1]=h.chaves[h.n];
    h.chaves[h.n]=aux;
    j=h.n;
    h.n--;
    descer(1);
    return(j);              //remocao com sucesso
    }
void descer(int i){
    int j;
    int aux;
    j=2*i;
    if(j<=h.n){
        if(j<h.n){
            if(h.chaves[j+1]<h.chaves[j])
                j++;
        }
    if(h.chaves[i]>h.chaves[j]){
        aux=h.chaves[i];
        h.chaves[i]=h.chaves[j];
        h.chaves[j]=aux;
        descer(j);
    }
    }
}

void imprimeHeap(){
    int i;
    if (h.n==0){
        printf("Arvore vazia!");
    }
    for(i=1;i<=h.n;i++){
        printf ("\n%d", h.chaves[i]);}
}

int main(){
    int numero;
    int op;
    int x;
    int a;
    h.n=0;
    heap* p;
    heap* L;
    heap* aux;
    aux = NULL;
    L = aux;
    do{
        printf("\n\n     HEAP");
        printf("\n1-Inserir \n2-Remover \n3-Mostra\n0-Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                insercaoHeap(numero);
                printf("Insercao com sucesso.");
                getch();
                break;
            case 2:
                remocaoHeap();
                getch();
                break;
            case 3:
                imprimeHeap();
                getch();
                break;
        }
    }while(op!=0);
    system("pause");
    return 0;

}
