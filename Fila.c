#include <stdio.h>
#include <stdlib.h>

/*
Implementação de uma fila  usando array.
*/
//  Esse código possui algumas implementações para métodos  com a TAD fila.
typedef struct {
    int size;
    int front;
    int rear;
    int *array;
} Queue;

// Função que criar uma fila. Note que  front e rear sendo incializadas em -1 faz com que, se esses forem iguais, a fila se encontra vazia.
// com base nisso também a estratégia para inserir elementos na fila.
void create(Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->array = (int*) malloc(q->size * sizeof(int));
}

// Função para adicionar um elemento na fila. Verifica se a fila está cheia, caso não, move a parte final em 1 e lá adiciona o valor
// isso é possível pois a variável é inicializada em -1.
void enqueue(Queue *q, int n) {
    if (q->rear == q->size - 1)
        printf("A fila está cheia\n");
    else {
        q->rear++;
        q->array[q->rear] = n;
    }
}

// retira o elemento da fila. Lembrando que segue o principio FIFO - First In First Out
int dequeue(Queue *q) {
    int n = -1;

    if (q->front == q->rear)
        printf("A fila está vazia\n");
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
Outras implementações
*/

/*Função que cria e inicializa uma fila de tamanho {size}.  Note que nesse caso, somente com um tamanho cria uma fila*/
Queue *create (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->back = 0;
  q->size = size;
  q->array = (int *)malloc(size * sizeof(int));
  return q;
}

/*Função para enfileirar {elem} na fila {q}.*/
void enqueue (Queue *q, int elem) {
  if (full(q)) {
    printf ("error: queue overflow!\n");
    exit(1);
  }
  q->array[q->back] = elem;
  q->back = (q->back + 1) % q->size;
}

/*Função para desenfileirar o primeiro elemento da fila {q}.*/
int dequeue (Queue *q) {
  if (empty(q)) {
    printf ("error: queue underflow!\n");
    exit(1);
  }
  int e = q->array[q->front];
  q->front = (q->front + 1) % q->size;
  return e;
}

/*Função que retorna mas não remove o primeiro elemento de {q}.*/
int front (Queue *q) {
  if (!empty(q))
    return q->array[q->front];
  else
    return ERROR;
}

/*Função que verifica se a fila {q} está vazia (true) ou não {false}.*/
int empty (Queue *q) {
  return (q->front == q->back);
}

/*Função que verifica se a fila {q} está cheia (true) ou não {false}.*/
int full (Queue *q) {
  return (q->front == ((q->back + 1) % q->size));
}

/*Função que imprime uma fila {q}.*/
void print (Queue *q) {
  int i;
  printf("Queue: ");
  for (i = q->front; i != q->back; i = (i+1) % q->size) {
    printf ("%d ", q->array[i]);
  }
  printf("\n");
}

/*Função que desaloca as estruturas de uma fila {q}.*/
void destroy (Queue *q) {
  free (q->array);
  free (q);
}







