#include "stdio.h"
#include "string.h"
//
//int main() {
//    int a = 25, b = -25, c = 3;
//
//
//    for (int j = 0; j < 20; j++) {
//        for (int i = 0; i < 50; i++) {
//            a = 23*a + b - j*c;
//        }
//    }
//
//    c = -a;
//
//        printf("c = %d\n",c);
//
//    return c;
//}

int main() {
    unsigned int data, temp, test, j, k, max_count;
    max_count = 32;
    data = 0;
    for (unsigned int i = 0; i < 32; i++){
        temp = data;
        test = 0;
        j = 0;
        while (j < max_count) {
            test = 1 << j;
            temp = data | test;
            temp = temp & ~test;
            test = 0;
            j++;
            if (temp != data) {
                printf("testing error with test value of %x\n", temp);
                while(1);
            }
        }
        max_count--;
        data = data | (1 << (max_count));
        printf("data = %x\n", data);
    }

    max_count = 32;
    data = 0xffffffff;
    k = 0;
    for (unsigned int i = 0; i < 32; i++){
        temp = data;
        test = 0;
        j = k;
        while (j < max_count) {
            test = 0x80000000 >> j;
            temp = data & ~test;
            temp = temp | test;
            test = 0;
            j++;
            if (temp != data) {
                printf("testing error with test value of %x\n", temp);
                while(1);
            }
        }
        data = data & ~(0x80000000 >> (32-max_count));
        k++;
        max_count--;
        printf("data = %x\n", data);
        data = 0xffffffff;
    }
}
