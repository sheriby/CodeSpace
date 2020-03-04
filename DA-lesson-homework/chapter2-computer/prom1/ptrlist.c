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
    printf("List: [");
    while (list->next) {
        printf("%d, ", list->ele);
    }
    printf("%d]", list->ele);
}

List mergeList(List list1, List list2) {
    List list = initlist();
    list->size = list1->size + list2->size;
    while (list1 && list2) {
        if (list1->ele < list2->ele) {
            list->next = list1;
            list1 = list1->next;
        } else {
            list->next = list2;
            list2 = list2->next;
        }
    }

    if (list1) {
        list->next = list1;
    } else {
        list->next = list2;
    }

    return list;
}
