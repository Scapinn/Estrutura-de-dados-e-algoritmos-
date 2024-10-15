#include <stdio.h>
#include <stdlib.h>

/*
Implementa��o de uma fila  usando array.
*/
//  Esse c�digo possui algumas implementa��es para m�todos  com a TAD fila.
typedef struct {
    int size;
    int front;
    int rear;
    int *array;
} Queue;

// Fun��o que criar uma fila. Note que  front e rear sendo incializadas em -1 faz com que, se esses forem iguais, a fila se encontra vazia.
// com base nisso tamb�m a estrat�gia para inserir elementos na fila.
void create(Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->array = (int*) malloc(q->size * sizeof(int));
}

// Fun��o para adicionar um elemento na fila. Verifica se a fila est� cheia, caso n�o, move a parte final em 1 e l� adiciona o valor
// isso � poss�vel pois a vari�vel � inicializada em -1.
void enqueue(Queue *q, int n) {
    if (q->rear == q->size - 1)
        printf("A fila est� cheia\n");
    else {
        q->rear++;
        q->array[q->rear] = n;
    }
}

// retira o elemento da fila. Lembrando que segue o principio FIFO - First In First Out
int dequeue(Queue *q) {
    int n = -1;

    if (q->front == q->rear)
        printf("A fila est� vazia\n");
    else {
        q->front++;
        n = q->array[q->front];
    }
    return n;
}

// Exibe os elementos da fila.
void display(Queue q) {
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.array[i]);
    printf("\n");
}

int main() {
    Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(q);

    return 0;
}


/*
Outras implementa��es
*/

/*Fun��o que cria e inicializa uma fila de tamanho {size}.  Note que nesse caso, somente com um tamanho cria uma fila*/
Queue *create (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->back = 0;
  q->size = size;
  q->array = (int *)malloc(size * sizeof(int));
  return q;
}

/*Fun��o para enfileirar {elem} na fila {q}.*/
void enqueue (Queue *q, int elem) {
  if (full(q)) {
    printf ("error: queue overflow!\n");
    exit(1);
  }
  q->array[q->back] = elem;
  q->back = (q->back + 1) % q->size;
}

/*Fun��o para desenfileirar o primeiro elemento da fila {q}.*/
int dequeue (Queue *q) {
  if (empty(q)) {
    printf ("error: queue underflow!\n");
    exit(1);
  }
  int e = q->array[q->front];
  q->front = (q->front + 1) % q->size;
  return e;
}

/*Fun��o que retorna mas n�o remove o primeiro elemento de {q}.*/
int front (Queue *q) {
  if (!empty(q))
    return q->array[q->front];
  else
    return ERROR;
}

/*Fun��o que verifica se a fila {q} est� vazia (true) ou n�o {false}.*/
int empty (Queue *q) {
  return (q->front == q->back);
}

/*Fun��o que verifica se a fila {q} est� cheia (true) ou n�o {false}.*/
int full (Queue *q) {
  return (q->front == ((q->back + 1) % q->size));
}

/*Fun��o que imprime uma fila {q}.*/
void print (Queue *q) {
  int i;
  printf("Queue: ");
  for (i = q->front; i != q->back; i = (i+1) % q->size) {
    printf ("%d ", q->array[i]);
  }
  printf("\n");
}

/*Fun��o que desaloca as estruturas de uma fila {q}.*/
void destroy (Queue *q) {
  free (q->array);
  free (q);
}







