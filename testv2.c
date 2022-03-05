#include <stdio.h>
#include <string.h>

char *itoa(int value, char *result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) {
        *result = '\0';
        return result;
    }

    char *ptr;
    char *ptr1;
    char tmp_char;
    int tmp_value;

    ptr = result;
    ptr1 = result;
    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
    } while (value);

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}


int main(void) {
    // El texto que vamos a traducir
    char *texto = "ab";
    printf("En texto es: %s\n", texto);
    char *relleno = "00000000";
    // El número que irá tomando cada letra
    int decimal = 0;
    char cadena[9];
    int i = 0;
    printf("En binario es: \n");
    while (texto[i] != '\0') {
        decimal = (long) texto[i];// Obtener valor ASCII del carácter
        // Convertir y almacenar el binario en "cadena"
        itoa(decimal, cadena, 2);
        // Diferencia para saber si no mide 8
        int diferencia = 8 - (int) strlen(cadena);
        // Imprimir. El %*.*s es para rellenar la cadena con ceros a la izquierda
        // https://stackoverflow.com/questions/276827/string-padding-in-c/9741091#9741091
        printf("%*.*s%s ", diferencia, diferencia, relleno, cadena);
        i++;
    }
}