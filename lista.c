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
