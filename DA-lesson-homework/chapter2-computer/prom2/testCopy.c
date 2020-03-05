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
    printf("============ TEST =============\n");
    int arr[5] = {1, 3, 5, 7, 9};
    List src = arr2List(arr, 5);
    List dst = initlist();

    copyList(src, dst);

    printList(src);
    printList(dst);

    printf("============ TEST =============\n");
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}
