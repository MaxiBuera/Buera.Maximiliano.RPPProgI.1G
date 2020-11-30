#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTEBOOKS 5

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

eNotebook arrayNotebooks[NOTEBOOKS] = {
    {0,"HQ","ASD",100000},
    {0,"Intel","Compaq",100000},
    {0,"AMD","ASD",300000},
    {0,"HQ","ASD",200000},
    {0,"HQ","NOSE",100000},
};

void ordenarArray(eNotebook* arrayNotebooks,int orden);

int main()
{
    int i=0;

    //1)
    float precioProducto;
    float precioDescuento;
    printf("\nIngrese precio: ");
    scanf("%f",&precioProducto);
    precioDescuento = aplicarDescuento(precioProducto);
    printf("Descuento: %.2f\n",precioDescuento);


    //2)
    char* cadena = "Hala";
    char caracter = 'a';
    int resultado2 = contarCaracteres(cadena,caracter);
    printf("\nCadena: %s",cadena);
    printf("\nCantidad de veces que se repite el caracter '%c': %d\n",caracter,resultado2);


    //3)
    ordenarArray(arrayNotebooks,0);

    for(i=0;i<NOTEBOOKS;i++){

        printf("\n%s %.2f",arrayNotebooks[i].marca,arrayNotebooks[i].precio);
    }
    printf("\n");
    return 0;
}

float aplicarDescuento(float precioProducto){

    return precioProducto * 0.95;
}

int contarCaracteres(char* cadena, char caracter){

    int i=0;
    int contador=0;

    //while(*i != '\0'){
    while(cadena[i] != '\0'){
        if(cadena[i] == caracter){

            contador++;
        }
        i++;
    }

    return contador;
}

void ordenarArray(eNotebook* arrayNotebooks,int orden){

    int i,j;
    eNotebook auxiliar;

    if(arrayNotebooks != NULL)
    {
        for(i=0;i<NOTEBOOKS-1;i++){

            for(j=i+1;j<NOTEBOOKS;j++){

                if(strcmp(arrayNotebooks[i].marca, arrayNotebooks[j].marca) > 0){

                    auxiliar = arrayNotebooks[i];
                    arrayNotebooks[i] = arrayNotebooks[j];
                    arrayNotebooks[j] = auxiliar;
                }
                else if(strcmp(arrayNotebooks[i].marca, arrayNotebooks[j].marca) == 0 && arrayNotebooks[i].precio > arrayNotebooks[j].precio){

                    auxiliar = arrayNotebooks[i];
                    arrayNotebooks[i] = arrayNotebooks[j];
                    arrayNotebooks[j] = auxiliar;
                }
            }
        }
    }

}





