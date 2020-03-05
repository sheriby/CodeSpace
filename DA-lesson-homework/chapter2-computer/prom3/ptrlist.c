#include "ptrlist.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    ElementType ele;
    Position tail;
    Position next;
    int size;
};

List initlist() {
    List list = (List)malloc(sizeof(struct ListNode));
    list->next = NULL;
    list->tail = list;
    list->size = 0;
    return list;
}

int size(List list) { return list->size; }

Position find(ElementType ele, List list) {
    while (list) {
        if (list->ele == ele) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}
void insert(ElementType ele, List list) {
    Position pos = (Position)malloc(sizeof(struct ListNode));
    list->tail->next = pos;
    pos->ele = ele;
    pos->next = NULL;
    list->tail = pos;
    list->size++;
}

static Position findPrevByEle(ElementType ele, List list) {
    while (list && list->next) {
        if (list->next->ele == ele) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

static void deleteNext(Position prev, List list) {
    if (!prev || !list) {
        return;
    }
    Position next;
    if (prev->next == list->tail) {
        free(prev->next);
        prev->next = NULL;
        list->tail = prev;
    } else {
        next = prev->next;
        prev->next = prev->next->next;
        free(next);
    }
    list->size--;
}
void deleteEle(ElementType ele, List list) {
    Position pos = findPrevByEle(ele, list);
    deleteNext(pos, list);
}

static Position findPrevByPos(Position pos, List list) {
    while (list && list->next) {
        if (list->next == pos) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}
void deletePos(Position pos, List list) {
    Position prev = findPrevByPos(pos, list);
    deleteNext(prev, list);
}
int isEmpty(List list) { return list->next == NULL; }
void destroyList(List list) {
    Position next;
    while (list) {
        next = list->next;
        free(list);
        list = next;
    }
}
void printList(List list) {
    list = list->next;
    if (!list) {
        printf("List: []\n");
        return;
    }
    printf("List: [");
    while (list->next) {
        printf("%d, ", list->ele);
        list = list->next;
    }
    printf("%d]\n", list->ele);
}

List mergeList(List list1, List list2) {
    List list = initlist();
    Position pos = list;
    list->size = list1->size + list2->size;
    list1 = list1->next;
    list2 = list2->next;
    while (list1 && list2) {
        if (list1->ele < list2->ele) {
            pos->next = list1;
            list1 = list1->next;
        } else {
            pos->next = list2;
            list2 = list2->next;
        }
        pos = pos->next;
    }

    if (list1) {
        pos->next = list1;
        list->tail = list1->tail;
    } else {
        pos->next = list2;
        list->tail = list2->tail;
    }

    return list;
}

void copyList(List src, List dst) {
    Position pos;
    dst->size = src->size;
    src = src->next;
    while (src) {
        pos = (Position)malloc(sizeof(struct ListNode));
        pos->ele = src->ele;
        pos->next = NULL;
        dst->next = pos;
        dst = dst->next;
        if (!src->next) {
            dst->tail = pos;
            return;
        }
        src = src->next;
    }
}

static Position prev(List list, ElementType ele, int *index) {
    while (list && list->next) {
        if (list->next->ele == ele) {
            return list;
        }
        list = list->next;
        (*index)++;
    }
    return NULL;
}

int delete (List list, ElementType ele) {
    int index = 0;
    Position p = prev(list, ele, &index);
    if (!p) {
        return -1;
    }
    deleteNext(p, list);
    return index;
}
