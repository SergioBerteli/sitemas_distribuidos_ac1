#include "lista.h"
#include <stdlib.h>

void inicializa_lista(List ** lista)
{
    *lista = (List *) malloc(sizeof(List));
    (*lista)->next = NULL;
}

void adiciona_val(List * lista, int value) 
{
    if (lista->next== NULL){
        lista->value = value;
        lista->next = (List *) malloc(sizeof(List));
        lista->next->next = NULL;
        return;
    } else{
        adiciona_val(lista->next, value);
    }
}

void mesclar (List * lista1, List * lista2)
{
    List * temp = lista2;
    while (temp->next != NULL)
    {
        adiciona_val(lista1, temp->value);
        temp = temp->next;
    }
}