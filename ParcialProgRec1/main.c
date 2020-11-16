#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1)Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un
    producto y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main. */
float aplicarDescuento(float precioProducto);



/*2) Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
    y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena */
int contarCaracteres(char* cadena, char caracter);

/*3)Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un
    array de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y
    mostrarlos desde el main. */

typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;
void ordenar(char* cadena);

int main()
{
    //1)
    float precioProducto;
    printf("\nIngrese precio: ");
    scanf("%f",&precioProducto);
    aplicarDescuento(precioProducto);


    //2)
    int resultado2 = contarCaracteres("Hola",'a');
    printf("Cantidad de veces que se repite el caracter: %d", resultado2);



    return 0;
}

float aplicarDescuento(float precioProducto){

    float precioDescuento = precioProducto * 0.95;

    return printf("Descuento: %.2f",precioDescuento);
}

int contarCaracteres(char* cadena, char caracter){

    int i;
    int contador=0;

    while(cadena[i]!='\0'){

        if(cadena[i] == caracter){

            contador++;
        }
        i++;
    }

    return contador;
}

