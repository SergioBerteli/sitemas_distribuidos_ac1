#include "primos.h"

int verifica_primo(int value)
{
    for (int i = 2; i < value; i ++){
            if (value % i == 0){
            return 0;
        }
    }
    return 1;
}


void get_primes_in_range(int begin, int end, List * lista)
{
    for (int i = begin; i< end; i++){
        if (verifica_primo(i)){
            adiciona_val(lista, i);
        }
    }
}