#include "main.h"

int main(){
    List * teste = NULL;
    List * teste_2 = NULL;
    inicializa_lista(&teste);
    inicializa_lista(&teste_2);

    adiciona_val(teste, 1);
    adiciona_val(teste, 2);
    adiciona_val(teste_2, 3);
    adiciona_val(teste_2, 4);
    
    mesclar(teste, teste_2);
    
    List * temp = teste;
    while (temp->next != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }


}