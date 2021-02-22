#include "api.h"

struct arv
{
    int chave;
    Arv *esq;
    Arv *dir;
};

struct pilha
{
    Arv *node[10000000];
    int topo;
};

Arv *arv_criavazia(void)
{
    return NULL;
}

Arv *insere(Arv *a, int chave)
{

    if (busca(a, chave) != NULL)
        return a;

    if (a == NULL)
    {
        a = (Arv *)malloc(sizeof(Arv));
        a->chave = chave;
        a->esq = a->dir = NULL;
    }
    else if (chave < a->chave)
        a->esq = insere(a->esq, chave);
    else
        a->dir = insere(a->dir, chave);

    return a;
}

Arv *busca(Arv *a, int chave)
{
    if (a == NULL)
        return NULL;
    else if (a->chave > chave)
        return busca(a->esq, chave);
    else if (a->chave < chave)
        return busca(a->dir, chave);
    else
        return a;
}

void printChave(Arv *a)
{
    printf("%d ", a->chave);
}

void stack_preorder(Arv *a, void (*visit)(Arv *))
{
    if (a == NULL)
        return;

    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;

    push(a, p);

    while (p->topo != 0)
    {
        a = pop(p);
        //(*visit)(a);
        if (a->dir != NULL)
            push(a->dir, p);
        if (a->esq != NULL)
            push(a->esq, p);
    }

    free(p);
}

void stack_inorder(Arv *a, void (*visit)(Arv *))
{
    if (a == NULL)
        return;
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;

    while (1)
    {

        if (a != NULL)
        {
            push(a, p);
            a = a->esq;
        }
        else
        {
            if (p->topo == 0)
                break;
            a = pop(p);
            //(*visit)(a);
            a = a->dir;
        }
    }
}

// void stack_postorder(Arv *a, void (*visit)(Arv *))
// {
//     Arv* atual = a;
//     Pilha *p = (Pilha *)malloc(sizeof(Pilha));
//     p->topo = 0;

//     while(atual!=NULL || p->topo != 0 ){
//         if(atual!=NULL){
//             push(atual, p);
//             atual = atual->esq;
//         } else{
//             Arv* temp =
//         }
//     }
//     (*visit)(a);
// }

void arv_imprime(Arv *a)
{
    printf("<");
    if (a != NULL)
    {
        printf("%d", a->chave);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");
}

Arv *arv_libera(Arv *a)
{
    if (a != NULL)
    {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

void push(Arv *a, Pilha *p)
{
    if (p->topo == 100)
        return;

    p->node[p->topo] = a;

    p->topo++;
}

Arv *pop(Pilha *p)
{

    if (p->topo == 0)
        return NULL;

    Arv *a = (Arv *)malloc(sizeof(Arv));
    a = p->node[p->topo - 1];

    p->topo--;

    return a;
}