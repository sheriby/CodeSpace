#include <malloc.h>
#include <stdio.h>

typedef int Elementtype;
struct celltype {
    Elementtype element;
    struct celltype *next, *previous;
};

typedef struct celltype *DLIST;
typedef struct celltype *position;

void Delete(position p) //删除p节点
{
    if (p->previous != NULL) {
        p->previous->next = p->next;
        free(p);
    }
    if (p->next != NULL) {
        p->next->previous = p->previous;
        free(p);
    }
    if (p->next == NULL) {
        p->previous->next = NULL;
        free(p);
    }
    //如果是头节点不删除
}

void MakeNull(DLIST DL) //将双向链表置空
{
    position p = DL;
    free(p->next);
    DL = (DLIST)malloc(sizeof(struct celltype));
    DL->next = NULL;
    DL->previous = NULL;
}

void Insert(Elementtype x, position p) //在节点P后添加节点
{
    position q = (position)malloc(sizeof(struct celltype));
    q->element = x;
    q->next = p->next;
    p->next->previous = q;
    p->next = q;
    q->previous = p;
}

position Locate(Elementtype x, DLIST DL) //定位第一个X元素
{
    position p = DL;
    while (p->next != NULL) {
        if (p->next->element == x)
            return p->next;
        else
            p = p->next;
    }
    return p->next;
}

int Swap(Elementtype x, DLIST DL) //交换
{
    position p, q;
    p = Locate(x, DL);
    if (p == NULL)
        return 0;
    else {
        q = p->previous;
        p->previous = q->previous;
        q->previous->next = p;
        p->next->previous = q;
        q->next = p->next;
        p->next = q;
        p->previous = q;
        return 1;
    }
}

void Input(DLIST DL, int n) {
    position p = DL;
    p->previous = NULL;
    p->next = (position)malloc(sizeof(struct celltype));
    p->next->next = NULL;
    p->next->previous = DL;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        Insert(x, p);
    }
}

void Output(DLIST DL) {
    position p = DL;
    while (p->next != NULL) {
        printf("%d\t", p->next->element);
        p = p->next;
    }
    printf("\n");
}

int main() {
    printf("=================TEST=================\n");
    DLIST DL = (DLIST)malloc(sizeof(struct celltype));
    int n, x;
    scanf("%d", &n);
    Input(DL, n);
    Output(DL);
    scanf("%d", &x);
    Swap(x, DL);
    Output(DL);
    printf("=================TEST=================\n");
    return 0;
}
