#include <stdio.h>
#include <stdlib.h>

extern void generate_password(char *password);

int main() {
    char password[13]; // Longitud de la contraseña + 1 para el carácter nulo

    // Generar la contraseña utilizando la función en ensamblador
    generate_password(password);

    // Solicitar el nombre de usuario
    char username[50];
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", username);

    // Almacenar la contraseña para el usuario
    printf("La contraseña generada para el usuario %s es: %s\n", username, password);

    return 0;
}

