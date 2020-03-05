#include "ptrlist.h"
#include <stdio.h>

void insertArr(int arr[], int len, List list) {
    int i;
    for (i = 0; i < len; ++i) {
        insert(arr[i], list);
    }
}

void test() {
    printf("================ TEST ===================\n");
    int arr[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {2, 4, 6, 8, 10};

    List list1 = initlist();
    insertArr(arr, 5, list1);
    List list2 = initlist();
    insertArr(arr2, 5, list2);

    printList(list1);
    printList(list2);

    List res = mergeList(list1, list2);
    printList(res);
    printf("size => %d\n", size(res));
    printf("================ TEST ===================\n");
}

void test2() {
    printf("================ TEST ===================\n");
    int arr[4] = {1, 2, 9, 20};
    int arr2[8] = {2, 4, 6, 11, 17, 25, 28, 40};

    List list1 = initlist();
    insertArr(arr, 4, list1);
    List list2 = initlist();
    insertArr(arr2, 8, list2);

    printList(list1);
    printList(list2);

    List res = mergeList(list1, list2);
    printList(res);
    printf("size => %d\n", size(res));
    printf("================ TEST ===================\n");
}

int main(int argc, char *argv[]) {
    test();
    test2();
    return 0;
}
