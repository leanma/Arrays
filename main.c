#include <stdio.h>
#include <stdlib.h>
#include "Vectores.h"

int main()
{
    msgIni();


    int flag=0,ce,ret,elem;
    int *vec=NULL;
    int op=msgMenu(vec,ce);

    while(op!=0)
    {

        switch (op)
        {
            case 1:
                vec=crearVector(sizeof(int),&ce);
                if(!vec)
                    ret=ERROR_MEMORIA;
                else
                {
                    flag=1;
                    ret=cargaVec(vec,ce);
                }
                break;
            case 2:
                if(flag)
                {
                    system("cls");
                    printf("----------------Agregado de Elemento----------------\n");
                    ingresaEntero(&elem);
                    ret=agregarElementoEnVector((void**)&vec,&ce,&elem,sizeof(int));
                }
                break;
            case 3:
                if(flag)
                {
                    system("cls");
                    printf("----------------Eliminado de Elemento----------------\n");
                    ingresaEntero(&elem);
                    ret=eliminarTElementoEnVector(vec,&ce,&elem,sizeof(int),cmpInt);
                }
                break;
            case 4:
                if(flag)
                    ordenarVectorSeleccion(vec,ce,sizeof(int),cmpInt);
                break;
            case 5:
                if(flag)
                {
                    system("cls");
                    printf("----------------Suma de los Elementos del Vector----------------\n");
                    ret=sumaVector(vec,ce,sizeof (int),'i');
                }
                break;
            case 6:
                if(flag)
                {
                    system("cls");
                    printf("----------------Promedio de los Elementos del Vector----------------\n");
                    ret=promedioVector(vec,ce,sizeof (int),'i');
                }
                break;
            case 7:
                if(flag)
                {
                    system("cls");
                    printf("----------------Mayor de los Elementos del Vector----------------\n");
                    int*max=hallarMayor(vec,ce,sizeof(int),cmpInt);
                    printf("Valor maximo --> %d\n",*max);
                    system("pause");
                    ret=TODO_OK;
                }
                break;
            case 8:
                if(flag)
                {
                    system("cls");
                    printf("----------------Minimo de los Elementos del Vector----------------\n");
                    int*min=hallarMenor(vec,ce,sizeof(int),cmpInt);
                    printf("Valor minimo --> %d\n",*min);
                    system("pause");
                    ret=TODO_OK;
                }
                break;
            case 9:
                if(flag)
                    ret=eliminarDuplicadosGen(vec,&ce,sizeof(int),cmpInt);
                break;
        }

        if(flag)
        {
            if(ret)
            {
                printf("\nCodigo de error: %d\n",ret);
                system("pause");
            }
            mostrarVector(vec,ce);
        }
        op=msgMenu(vec,ce);
    }
    if(flag)
        free(vec);
    printf("\nPROGRAMA FINALIZADO CON EXITO\nADIOS\n");
    return 0;
}

