#include "arrlist.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

struct ArrList {
    ElementType *elements;
    int size;
    int capacity;
};

void ERROR(const char *func, const char *info) {
    printf("Error Occurs in function [%s]: %s", func, info);
    exit(-1);
}

List initList(int capacity) {
    List list = (List)malloc(sizeof(struct ArrList));
    list->size = 0;
    list->elements = (ElementType *)malloc(sizeof(ElementType) * capacity);
    if (!list->elements) {
        ERROR("initList", "malloc fail!");
    }
    list->capacity = capacity;

    return list;
}

int length(List list) { return list->size; }

int capacity(List list) { return list->capacity; }

Position find(ElementType ele, List list) {
    int i;
    Position pos = list->elements;
    for (i = 0; i < list->size; ++i) {
        if (ele == *pos) {
            return pos;
        }
        pos++;
    }
    return NULL;
}

void insert(ElementType ele, List list) {
    if (list->capacity == list->size) {
        ERROR("insert", "this list is full!");
    }
    list->elements[list->size++] = ele;
}

void deleteEle(ElementType ele, List list) {
    int i;
    for (i = 0; i < list->size; ++i) {
        if (ele == list->elements[i]) {
            memcpy(list->elements + i, list->elements + i + 1,
                   sizeof(ElementType) * (list->capacity - i - 1));
            list->size--;
            return;
        }
    }
}

int isEmpty(List list) { return list->size == 0; }

void destroyList(List list) {
    free(list->elements);
    free(list);
}

void printList(List list) {
    int i;
    printf("List: [");
    for (i = 0; i < list->size - 1; ++i) {
        printf("%d, ", list->elements[i]);
    }
    printf("%d]\n", list->elements[i]);
}

static int isEnd(Position pos, List list) {
    return pos == list->elements + list->size;
}

List mergeList(List list1, List list2) {
    List res = initList(list1->capacity + list2->capacity);
    Position pos1 = list1->elements;
    Position pos2 = list2->elements;

    while (!isEnd(pos1, list1) && !isEnd(pos2, list2)) {
        if (*pos1 < *pos2) {
            insert(*pos1++, res);
        } else {
            insert(*pos2++, res);
        }
    }

    while (!isEnd(pos1, list1)) {
        insert(*pos1++, res);
    }

    while (!isEnd(pos2, list2)) {
        insert(*pos2++, res);
    }

    return res;
}
