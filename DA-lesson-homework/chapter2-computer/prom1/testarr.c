#include "arrlist.h"
#include <stdio.h>

void insertArr(int arr[], int len, List list) {
    int i;
    for (i = 0; i < len; ++i) {
        insert(arr[i], list);
    }
}

void test1() {
    printf("===============TEST=================\n");
    int arr[5] = {1, 3, 5, 7, 9};
    List list1 = initList(10);
    insertArr(arr, 5, list1);
    int arr2[5] = {2, 4, 6, 8, 10};
    List list2 = initList(8);
    insertArr(arr2, 5, list2);

    printList(list1);
    printList(list2);

    List res = mergeList(list1, list2);
    printList(res);
    printf("===============TEST=================\n");
}

void test2() {
    printf("===============TEST=================\n");
    int arr[6] = {1, 2, 9, 10, 17, 20};
    List list1 = initList(10);
    insertArr(arr, 6, list1);
    int arr2[3] = {2, 4, 11};
    List list2 = initList(8);
    insertArr(arr2, 3, list2);

    printList(list1);
    printList(list2);

    List res = mergeList(list1, list2);
    printList(res);
    printf("===============TEST=================\n");
}

int main(int argc, char *argv[]) {
    test1();
    test2();
    return 0;
}
