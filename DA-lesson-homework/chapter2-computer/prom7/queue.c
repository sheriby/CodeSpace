#include <stdio.h>
#define maxlength 100

typedef int Elementtype;
typedef struct {
    int front;
    int count;
    Elementtype elements[maxlength];
} * QUEUE;

void MakeNull(QUEUE Q) {
    Q->front = 0;
    Q->count = 0;
}

int Empty(QUEUE Q) {
    if (Q->count == 0)
        return 1;
    else
        return 0;
}

int Full(QUEUE Q) {
    if (Q->count == maxlength)
        return 1;
    else
        return 0;
}
Elementtype Front(QUEUE Q) {
    if (Empty(Q))
        printf("queue is empty\n");
    else
        return (Q->elements[Q->front]);
}

void EnQueue(Elementtype x, QUEUE Q) {
    if (Full(Q))
        printf("queue is full\n");
    else {
        Q->elements[(Q->front + Q->count) % maxlength] = x;
        Q->count++;
    }
}

void DeQueue(QUEUE Q) {
    if (Empty(Q))
        printf("queue is empty\n");
    else
        Q->front = (Q->front + 1) % maxlength;
    Q->count--;
}

void Input(QUEUE Q, int n) {
    MakeNull(Q);
    int i = 0;
    Elementtype x;
    while (i < n) {
        scanf("%d", &x);
        EnQueue(x, Q);
        i++;
    }
}

void Output(QUEUE Q) {
    for (int i = 0; i < Q->count; i++) {
        printf("%d\t", Q->elements[(Q->front + i) % maxlength]);
    }
    printf("\n");
}

int main() {
    printf("================TEST================\n");
    QUEUE Q;
    int n;
    scanf("%d", &n);
    Input(Q, n);
    Output(Q);
    printf("%d\n", Front(Q));
    DeQueue(Q);
    Output(Q);
    EnQueue(2, Q);
    Output(Q);
    printf("================TEST================\n");
    return 0;
}
