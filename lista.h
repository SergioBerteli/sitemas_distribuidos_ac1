typedef struct List{
    int value;
    struct List * next;
} List;

void inicializa_lista(List ** lista);

void adiciona_val(List * lista, int value);