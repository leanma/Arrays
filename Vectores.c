#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vectores.h"


void msgIni()
{
    printf("\n*******************************\n");
    printf("*        \\--WELCOME!!--/      *\n");
    printf("*         \\   O    O  /       *\n");
    printf("*          \\    ^    /        *\n");
    printf("*           \\  ___  /         *\n");
    printf("*           /       \\         *\n");
    printf("*          /         \\        *\n");
    printf("*******************************\n\n");

    system("pause");
}


int msgMenu(int* v,int ce)
{
    int op;
    system("cls");
    do{
        printf("-------MENU VECTORES:-------\n");
        printf("1 ---> Cargar un Vector\n");
        printf("2 ---> Agregar un Valor al Vector\n");
        printf("3 ---> Eliminar un valor del Vector\n");
        printf("4 ---> Ordenar el Vector\n");
        printf("5 ---> Retornar la Suma de los Valores\n");
        printf("6 ---> Retornar el Promedio de los Valores\n");
        printf("7 ---> Retornar el Mayor de los Valores\n");
        printf("8 ---> Retornar el Menor de los Valores\n");
        printf("9 ---> Eliminar los Valores Duplicados\n");
        printf("0 ---> Salir\n");

        if(v)
            mostrarVector(v,ce);

        printf("\nIngrese la opcion deseada:\t");

        scanf("%d",&op);
        if(op<0 || op>10)
        {
            system("cls");
            printf("\nOPCION NO VALIDA\n");
        }
    }while(op<0 || op>10);


    return op;
}

void mostrarVector(int* v,int ce)
{
    int*ult=v+ce;
    printf("\nVECTOR: [\t");
    for(int*i=v;i<ult;i++)
    {
        printf("%d\t",*i);
    }
    printf("]\n");
}

int* crearVector(size_t tamElem,int* ce)
{
    system("cls");
    printf("----------------Creacion del Vector----------------\n");
    do{
        printf("Ingrese la cantidad de elementos del vector:\t");
        scanf("%d",ce);
        if(*ce<0)
            printf("La cantidad de elementos debe ser mayor igual a 0\n");
    }while(*ce<0);

    void* vec=malloc(tamElem*(*ce));
    if(!vec)
        return NULL;
    return vec;
}

int  cargaVec(int* vec,int ce)
{
    int* vec_ptr=vec;
    for(int i=0;i<ce;i++)
    {
        printf("Ingrese el valor: %d-->",i+1);
        scanf("%d",vec_ptr);
        vec_ptr++;
    }
    return TODO_OK;
}





int cmpInt(const void* p1,const void* p2)
{
    int* valor1=(int *)p1;
    int* valor2=(int *)p2;
    return *valor1-*valor2;
}





void ordenarVectorSeleccion(void* v,int ce,size_t tamelem,Cmp cmp)
{
    void* m;
    void* ult = (char*)v + (ce - 1) * tamelem;

    for(char* i = (char*)v; i < (char*)ult; i += tamelem)
    {
        m=buscarMenor(i,ult,tamelem,cmp);
        if(m!=i)
            intercambiar(m,i,tamelem);
    }
}

void* buscarMenor(void* ini,void* fin,size_t tamelem,Cmp cmp)
{
    void*m=ini;

    for(char* j = (char*)ini + tamelem; j <= (char*)fin; j += tamelem)
    {
        if(cmp(j,m)<0)
            m=j;
    }
    return m;
}

void intercambiar(void*x,void*y,size_t tamelem)
{
    void* xtemp=malloc(tamelem);
    if(!xtemp)
    {
        puts("No memoria");
        return;
    }
    memcpy(xtemp,x,tamelem);
    memcpy(x,y,tamelem);
    memcpy(y,xtemp,tamelem);
    free(xtemp);
}


void ingresaEntero(int* elem)
{
    printf("\nIngrese el valor:\t");
    scanf("%d",elem);
}

int agregarElementoEnVector(void** vec, int* ce, void* elem, size_t tamelem)
{
    *vec = realloc(*vec, (*ce + 1) * tamelem);
    if (*vec == NULL)
        return ERROR_MEMORIA;

    char* vec_ptr = (char*)(*vec) + (*ce) * tamelem;
    memcpy(vec_ptr, elem, tamelem);
    (*ce)++;

    return TODO_OK;
}



int eliminarElementoEnVector(void* vec,int* ce,size_t tamelem,int pos)
{
    if (*ce == 0 || pos < 0 || pos >= *ce)
        return -1;

    char* vec_ptr = (char*)vec;
    char* actual = vec_ptr + (pos * tamelem);
    char* siguiente = actual + tamelem;

    for (int i = pos; i < *ce - 1; i++)
    {
        memcpy(actual, siguiente, tamelem);
        actual += tamelem;
        siguiente += tamelem;
    }
    (*ce)--;

    return TODO_OK;
}


int eliminarTElementoEnVector(void* vec,int* ce,void* elem,size_t tamelem,Cmp cmp)
{
    if (*ce == 0)
        return -1;

    char* elem_ptr = (char*)elem;
    char* vec_ptr = (char*)vec;

    for (int i = 0; i < *ce; i++)
    {
        if (cmp(elem_ptr, vec_ptr + (i * tamelem)) == 0)
        {
            eliminarElementoEnVector(vec, ce, tamelem, i);
            i--;
        }
    }
    return TODO_OK;
}


int sumaVector(void* vec,int ce,size_t tamelem,char tipo)
{
 double acum = 0.0;
    char* fin = (char*)vec + ce * tamelem;

    switch (tipo) {
        case 'i':
            for (char* i = (char*)vec; i < fin; i += tamelem) {
                int* valor = (int*)i;
                acum += *valor;
            }
            break;
        case 'f':
            for (char* i = (char*)vec; i < fin; i += tamelem) {
                float* valor = (float*)i;
                acum += *valor;
            }
            break;
        case 'd':
            for (char* i = (char*)vec; i < fin; i += tamelem) {
                double* valor = (double*)i;
                acum += *valor;
            }
            break;
        default:
            printf("Tipo de dato no soportado.\n");
            return ERROR_TIPO_DATO;
    }

    printf("Resultado de la suma--> %.2f\n",acum);
    system("pause");
    return TODO_OK;
}


int promedioVector(void* vec,int ce,size_t tamelem,char tipo)
{
 double acum = 0.0;
    char* fin = (char*)vec + ce * tamelem;

    switch (tipo) {
        case 'i':
            for (char* i = (char*)vec; i < fin; i += tamelem) {
                int* valor = (int*)i;
                acum += *valor;
            }
            break;
        case 'f':
            for (char* i = (char*)vec; i < fin; i += tamelem) {
                float* valor = (float*)i;
                acum += *valor;
            }
            break;
        case 'd':
            for (char* i = (char*)vec; i < fin; i += tamelem) {
                double* valor = (double*)i;
                acum += *valor;
            }
            break;
        default:
            printf("Tipo de dato no soportado.\n");
            return ERROR_TIPO_DATO;
    }

    printf("Resultado de la suma--> %.2f\n",acum/ce);
    system("pause");
    return TODO_OK;
}


void* hallarMayor(void* vec,int ce,size_t tamelem,Cmp cmp)
{
    void*m=vec;
    void*fin=(char*)vec+ce*tamelem;

    for(char* i = (char*)vec + tamelem; i < (char*)fin; i += tamelem)
    {
        if(cmp(i,m)>0)
            m=i;
    }
    return m;
}

void* hallarMenor(void* vec,int ce,size_t tamelem,Cmp cmp)
{
    void*m=vec;
    void*fin=(char*)vec+ce*tamelem;

    for(char* i = (char*)vec + tamelem; i < (char*)fin; i += tamelem)
    {
        if(cmp(i,m)<0)
            m=i;
    }
    return m;
}

int eliminarDuplicadosGen(void*vec,int*ce,size_t tamelem,Cmp cmp)
{
    char* inicio = (char*)vec;
    char* fin = (char*)vec + (*ce) * tamelem;

    for (char* i = inicio; i < fin; i += tamelem)
    {
        char* j = i + tamelem;
        while (j < fin)
        {
            if (cmp(i, j) == 0)
            {
                char* k = j + tamelem;
                while (k < fin)
                {
                    memcpy(k - tamelem, k, tamelem);
                    k += tamelem;
                }
                fin -= tamelem;
                (*ce)--;
            }
            else {
                j += tamelem;
            }
        }
    }
    return TODO_OK;
}
