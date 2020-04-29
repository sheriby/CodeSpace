#include "stackArr.h"
#include <stdio.h>

void convert(int m, int n, Stack s) {
    printf("%d(%d) is ", m, n);
    makeEmpty(s);
    while (m) {
        push(m % n, s);
        m = m / n;
    }

    while (!isEmpty(s)) {
        printf("%d", topAndPop(s));
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Stack s = createStack(10);
    convert(255, 2, s);
    convert(255, 8, s);
    convert(255, 4, s);
    return 0;
}
