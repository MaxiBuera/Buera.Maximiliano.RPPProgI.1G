#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTEBOOKS 3

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
    {0,"Intel","Compaq",100000},
    {0,"AMD","ASD",300000},
    {0,"HQ","NOSE",200000},
};

void ordenarArray(eNotebook* arrayNotebooks,int orden);

int main()
{
    int i=0;

    //1)
    /*float precioProducto;
    printf("\nIngrese precio: ");
    scanf("%f",&precioProducto);
    aplicarDescuento(precioProducto);*/


    //2)
    int resultado2 = contarCaracteres("Hala",'a');
    printf("\nCantidad de veces que se repite el caracter: %d\n", resultado2);


    //3)
    ordenarArray(arrayNotebooks,0);

    for(i=0;i<NOTEBOOKS;i++){

        printf("\n%s",arrayNotebooks[i].marca);
    }

    return 0;
}

float aplicarDescuento(float precioProducto){

    float precioDescuento = precioProducto * 0.95;

    return printf("Descuento: %.2f",precioDescuento);
}

int contarCaracteres(char* cadena, char caracter){

    char *i;
    i = cadena;
    int contador=0;

    while(*i != '\0'){

        if(*i == caracter){

            contador++;
        }

        i++;
    }

    return contador;
}

void ordenarArray(eNotebook* arrayNotebooks,int orden){

    int flagSwap;
    int i;
    eNotebook auxiliar;

    if(arrayNotebooks != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<NOTEBOOKS-1;i++)
            {

                if((strcmp(arrayNotebooks[i].marca,arrayNotebooks[i+1].marca) > 0 && !orden) || (strcmp(arrayNotebooks[i].marca,arrayNotebooks[i+1].marca) < 0 && orden)) //<------------
                {
                    if((strcmp(arrayNotebooks[i].marca,arrayNotebooks[i+1].marca) == 0){

                        if(arrayNotebooks[i].precio > arrayNotebooks[i+1].precio){

                            auxiliar = arrayNotebooks[i];
                            arrayNotebooks[i] = arrayNotebooks[i+1];
                            arrayNotebooks[i+1] = auxiliar;
                            flagSwap = 1;
                       }
                    }

                    auxiliar = arrayNotebooks[i];
                    arrayNotebooks[i] = arrayNotebooks[i+1];
                    arrayNotebooks[i+1] = auxiliar;
                    flagSwap = 1;
                }

            }
        }while(flagSwap);
    }

}

