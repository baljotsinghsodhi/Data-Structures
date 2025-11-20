#include <stdio.h>

void dec_to_bin(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }

    int binary_array[32];
    int i = 0;

    while (n > 0) {
        binary_array[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary_array[j]);
    }
    printf("\n");
}

int main() {
    int dec_num;
    printf("Enter a non-negative decimal number: ");
    if (scanf("%d", &dec_num) != 1 || dec_num < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }
    dec_to_bin(dec_num);
    return 0;
}
