#include "main.h"


int main(){
    List * teste = NULL;
    inicializa_lista(&teste);

    
    get_primes_in_range(100, 200, teste);
    List * temp = teste;
    while (temp->next != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }


}