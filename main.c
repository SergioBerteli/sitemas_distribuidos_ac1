#include "main.h"

#define EM_EXECUCAO 1
#define RESULTADO 2
#define PARADA 3
#define INTERVALO_PRIMOS 1000

int main(int argc, char *argv[])
{
    List * lista_primos = NULL;
    inicializa_lista(&lista_primos);

    int msec = 0, trigger = 5000; /* 5s */
    clock_t before = clock();

    int rank, size;
    int comeco = 2;

    /* Start up MPI */

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* If we are the "manager" process (i.e., MPI_COMM_WORLD rank 0),
       put the number of times to go around the ring in the
       message. */

    if (0 == rank) { //se gerente

        do {
            for (int i = 1; i < size; i++) {
                int intervalo[2] = { comeco, comeco + INTERVALO_PRIMOS};
                MPI_Send(intervalo, 2, MPI_INT, i, EM_EXECUCAO, MPI_COMM_WORLD);
                comeco+= INTERVALO_PRIMOS;
            }

            for (int i = 1; i < size; i++) {
                MPI_Status status;
                int count;
                MPI_Probe(i, RESULTADO, MPI_COMM_WORLD, &status);
                MPI_Get_count(&status, MPI_INT, &count);

                int *buffer = (int *)malloc(count * sizeof(int));
                MPI_Recv(buffer, count, MPI_INT, i, RESULTADO, MPI_COMM_WORLD, &status);
                for (int pos; pos< count; pos ++){
                    adiciona_val(lista_primos, buffer[pos]);
                }
                free(buffer);
            }
            clock_t difference = clock() - before;
            msec = difference * 1000 / CLOCKS_PER_SEC;
        } while (msec < trigger); 
        for (int i = 1; i < size; i++) {
            MPI_Send(NULL, 0, MPI_INT, i, PARADA, MPI_COMM_WORLD);
        }

        List * temp = lista_primos;
        int conta_primos= 0;
        printf("[");
        while (temp->next != NULL)
        {
            printf("%d, \t", temp->value);
            conta_primos++;
            temp = temp->next;
        }
        printf("]");
        printf("\nPrimos encontrados: %d\n", conta_primos);
        
    } else // se executora
    {
        while (1) {
            printf("Executor %d iniciado\n", rank);
            MPI_Status status;
            int intervalo[2];

            MPI_Recv(intervalo, 2, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

            if (status.MPI_TAG == PARADA) break;

            int comeco= intervalo[0], fim = intervalo[1];
            int *amostras_primos= (int *)malloc((fim - comeco) * sizeof(int));
            int count = 0;

            for (int i = comeco; i < fim; i++) {
                if (verifica_primo(i)) amostras_primos[count++] = i;
            }

            MPI_Send(amostras_primos, count, MPI_INT, 0, RESULTADO, MPI_COMM_WORLD);
            free(amostras_primos);
        } 
    }

    MPI_Finalize();
    return 0;
}