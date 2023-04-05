#include <stdio.h>
#include "stdint.h"
#include "libs/data_structures/vector/vector.c"

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();

    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}
