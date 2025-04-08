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
