#include <stdio.h>

#define maxsize 100

typedef int Elementtype;

typedef struct {
    Elementtype element;
    int next;
} spacestr;
spacestr SPACE[maxsize];
typedef int position, cursor;
cursor available;

void Initialize() {
    int j;
    for (j = 0; j < maxsize - 1; j++) {
        SPACE[j].next = j + 1;
    }
    SPACE[j].next = -1;
    available = 0;
}

cursor GetNode() {
    position p;
    if (SPACE[available].next == -1)
        p = -1;
    else {
        p = SPACE[available].next;
        SPACE[available].next = SPACE[p].next;
    }
    return p;
}

void FreeNode(cursor q) {
    SPACE[q].next = available;
    available = q;
}

void Insert(Elementtype x, position p, cursor M) {
    position q;
    q = GetNode();
    SPACE[q].element = x;
    SPACE[q].next = SPACE[p].next;
    SPACE[p].next = q;
}

void Delete(cursor M, position p) {
    position q;
    q = GetNode();
    if (SPACE[p].next != -1) {
        if (SPACE[SPACE[p].next].next != -1) {
            q = SPACE[p].next;
            SPACE[p].next = SPACE[q].next;
            FreeNode(q);
        } else {
            q = SPACE[p].next;
            FreeNode(q);
        }
    }
}

void Merge(cursor M, cursor N) {
    position p = M;
    position q = N;
    while (SPACE[p].next != -1)
        p = SPACE[p].next;
    SPACE[p].next = SPACE[q].next;
    position r = available;
    SPACE[N].next = r;
    available = N;
}

void Input(cursor M) {
    Elementtype x;
    cursor p = 0;
    printf("please input the list(end with -1)\n");
    while (1) {
        scanf("%d", &x);
        if (x != -1) {
            Insert(x, p, M);
            p = SPACE[p].next;
        } else {
            SPACE[p].element = -1;
            p = -1;
            break;
        }
    }
}

void Output(cursor M) {
    position p;
    p = M;
    while (p != -1) {
        printf("%d\t", SPACE[p].element);
        p = SPACE[p].next;
    }
    printf("\n");
}

int main() {
    printf("=================== TEST ====================\n");
    Initialize();
    SPACE[0].element = 2;
    SPACE[0].next = 6;
    SPACE[1].element = 4;
    SPACE[1].next = 3;
    SPACE[2].next = 4;
    SPACE[3].element = 8;
    SPACE[3].next = -1;
    SPACE[4].element = 10;
    SPACE[4].next = 7;
    SPACE[5].next = 0;
    SPACE[6].element = 16;
    SPACE[6].next = 1;
    SPACE[7].element = 18;
    SPACE[7].next = 9;
    SPACE[8].element = 20;
    SPACE[8].next = -1;
    SPACE[9].element = 22;
    SPACE[9].next = 8;
    available = 10;

    cursor M = 2;
    cursor N = 5;
    Output(M);
    Output(N);
    Merge(M, N);
    Output(M);
    Delete(M, 3);
    Insert(34, 3, M);
    Output(M);
    printf("=================== TEST ====================\n");
    return 0;
}
