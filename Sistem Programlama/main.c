#define BIT_SET(VAR, BIT_NO) do { \
VAR |= 1<<BIT_NO; \
} while (0)


#define BIT_RESET(VAR, BIT_NO) do {    \
VAR &= ~(1<<BIT_NO); \
} while (0)



#define BIT_TOGGLE(VAR, BIT_NO) do { \
VAR ^= (1<<BIT_NO); \
} while (0)



#define BIT_GET(VAR, BIT_NO) ((VAR >> BIT_NO) & 1)

void print_bit(int var, int bit_count) {
    int i;
    for (i = bit_count-1 ; i >= 0 ; i--) {
        printf("%d", BIT_GET(var, i));
    }
    printf("\n");
}

int main() {

    int a = 0b00100;
    print_bit(a, 8);

    BIT_SET(a, 0); // a |= 0b1;
    print_bit(a, 8);

    BIT_RESET(a, 2); // a &= ~(0b100);
    print_bit(a, 8);

    BIT_TOGGLE(a, 3); // a ^= 0b1000;
    print_bit(a, 8);

    printf("a'nin 0. biti: %d\n", BIT_GET(a, 0));
    printf("a'nin 1. biti: %d\n", BIT_GET(a, 1));
    printf("a'nin 2. biti: %d\n", BIT_GET(a, 2));
    printf("a'nin 3. biti: %d\n", BIT_GET(a, 3));

    return 0;
}
