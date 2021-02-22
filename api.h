#ifndef API_H_
#define API_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct arv Arv;
typedef struct pilha Pilha;

Arv *arv_criavazia(void);
Arv *insere(Arv *a, int chave);
Arv *busca(Arv *a, int chave);
void arv_imprime(Arv *a);
void stack_preorder(Arv *a, void (*visit)(Arv *));
void stack_inorder(Arv *a, void (*visit)(Arv *));
void stack_postorder(Arv *a, void (*visit)(Arv *));
void printChave(Arv *a);
Arv *arv_libera(Arv *a);
Pilha *cria_pilha();
void push(Arv *a, Pilha *pilha);
Arv *pop(Pilha *pilha);
Pilha *destroi_pilha(Pilha *pilha);

#endif /* API_H_ */