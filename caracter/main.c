#include <stdio.h>

extern int buscar_caracter(char *cadena);

int main() {
    char buffer[256];
    int resultado;
    printf("Ingresa un cadena de texto:");
    fgets(buffer,sizeof(buffer),stdin);
    resultado = buscar_caracter(buffer);
    printf("El resultado es: %d\n", resultado);

    return 0;
}

