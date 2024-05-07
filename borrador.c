#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minuscula(char *buffer);
int mayuscula(char *buffer);
int caracter_especial(char *buffer);
int numero( char *buffer);
int longitud(char *buffer);
void generador_contrasena(void);
void evaluacion_contrasena(void);

int main(void){
    char buffer[256];

    do{
        printf("****** Menu ******\n");
        printf("[1] Generador de contrasena.\n");
        printf("[2] Verificador de contrasena.\n");
        printf("[3] Salir del programa\n");
        printf("Ingresa tu eleccion:");
        fgets(buffer,256,stdin);
        if(longitud(buffer)==1){
            if(buffer[0]=='1'){
                generador_contrasena();
            }
            else if(buffer[0]=='2'){
                evaluacion_contrasena();
            }
            else if(buffer[0]=='3'){
                printf("Cerrando programa\n");
                break;
            }
            else{
                printf("Valor invalido\n");
            }
        }
        else{
            printf("Valor invalido\n");
        }
        system("pause");
        system("cls");
    }while(1);

    return 0;
}

void generador_contrasena(void){
    srand(time(NULL));
    int numero = rand() % 9;
    int valor;
    numero+=14;
    char buffer[numero];
    for(int i=0; i<numero; i++){
        valor=0;
        valor = rand() % 95;
        buffer[i]= valor+=32;
    }
    buffer[numero-1]='\0';
    printf("La contrasena generada es: %s \n",buffer);
}

void evaluacion_contrasena(void){
    char buffer[256];
    printf("Ingresa la contrasena a evaluar:");
    fgets(buffer,256,stdin);
    printf("Nivel de seguridad ");
    if( longitud(buffer)>=12 && minuscula(buffer) && mayuscula(buffer) && caracter_especial(buffer) && numero(buffer) )
    {
        printf("Alta\n");
    }

    else if( longitud(buffer)>=8 && minuscula(buffer) && mayuscula(buffer) && numero(buffer) )
    {
        printf("Media\n");
    }

    else{
        printf("Baja\n");
    }
}

int longitud(char *buffer)
{
    int i;
    i=0;
    while(buffer[i]!='\n' && buffer[i]!='\0'){
        i++;
    }
    return i;
}

int minuscula(char *buffer){
    for(int i=0; i<longitud(buffer); i++){
        if(buffer[i]>96 && buffer[i]<123){
            return 1;
        }
    }
    return 0;
}

int mayuscula(char *buffer){
     for(int i=0; i<longitud(buffer); i++){
        if(buffer[i]>64 && buffer[i]<91){
            return 1;
        }
    }
    return 0;
}

int caracter_especial(char *buffer){
    for(int i=0; i<longitud(buffer); i++){
        if( (buffer[i]>31 && buffer[i]<48) || (buffer[i]>57 && buffer[i]<65) || (buffer[i]>90 && buffer[i]<97) || buffer[i]>122 ) {
            return 1;
        }
    }
    return 0;
}

int numero( char *buffer){
     for(int i=0; i<longitud(buffer); i++){
        if(buffer[i]>47 && buffer[i]<58){
            return 1;
        }
    }
    return 0;
}
