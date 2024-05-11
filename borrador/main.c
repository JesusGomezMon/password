#include <stdio.h>

extern int buscar_mayuscula(char *cadena);
extern int buscar_minuscula(char *cadena);
extern int buscar_digito(char *cadena);
extern int buscar_caracter(char *cadena);
extern int longitud(char *cadena);

int main() {
    char buffer[256];
    int mayuscula, minuscula, digito, caracter, longitud1;
    printf("Ingresa un cadena de texto:");
    fgets(buffer,sizeof(buffer),stdin);
    mayuscula=buscar_mayuscula(buffer);
    minuscula=buscar_minuscula(buffer);
    digito=buscar_digito(buffer);
    caracter=buscar_caracter(buffer);
    longitud1=longitud(buffer);
    printf("Mayuscula: %d \nMinuscula: %d\nNumero: %d\nCaracter: %d\nLongitud: %d\n",mayuscula,minuscula,digito,caracter,longitud1);

    return 0;
}
