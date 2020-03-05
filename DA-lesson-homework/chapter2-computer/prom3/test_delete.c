#include "ptrlist.h"
#include <stdio.h>

List arr2List(int arr[], int len) {
    int i;
    List list = initlist();
    for (i = 0; i < len; ++i) {
        insert(arr[i], list);
    }
    return list;
}

void test() {
    printf("=========== TEST ================\n");
    int arr[5] = {1, 3, 5, 7, 9};
    List list = arr2List(arr, 5);
    printList(list);
    printf("Search 7\n");
    int res = delete (list, 7);
    printf("FOUND INDEX => %d\n", res);

    printf("=========== TEST ================\n");
}

void test2() {
    printf("=========== TEST ================\n");
    int arr[5] = {1, 3, 5, 7, 9};
    List list = arr2List(arr, 5);
    printList(list);
    printf("Search 10\n");
    int res = delete (list, 10);
    printf("FOUND INDEX => %d\n", res);

    printf("=========== TEST ================\n");
}

int main(int argc, char *argv[]) {
    test();
    test2();
    return 0;
}
