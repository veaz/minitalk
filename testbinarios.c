#include <stdio.h>

const char *bit_rep[16] = { [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011", [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111", [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011", [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111", };

void print_byte(char byte)
{
    printf("Binario = %s%s", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}


int main()
{
    unsigned char foo;

    foo = 97;
    printf("NOT(~) = Me da el valor contrario\n");
    printf("foo = %i\n", foo);
    print_byte(foo);
    printf("\n~foo = %i\n", ~foo);
    print_byte(~foo);

    printf("OR(|) 0 = Me da el mismo valor\n");
    printf("foo = %i\n", foo);
    print_byte(foo);
    printf("\n~foo = %i\n", ~foo);
    print_byte(~foo);

}