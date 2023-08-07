#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


#define TODO_OK 0
#define ERROR_MEMORIA 1
#define ERROR_TIPO_DATO 2


void msgIni();
int msgMenu(int* v,int ce);
void ingresaEntero(int*elem);

int* crearVector(size_t tamElem,int* ce);
int  cargaVec(int* vec,int ce);
void mostrarVector(int* v,int ce);

typedef int(*Cmp)(const void*,const void*);
int cmpInt(const void*,const void*);
void ordenarVectorSeleccion(void* v,int ce,size_t tamelem,Cmp cmp);
void* buscarMenor(void* ini,void* fin,size_t tamelem,Cmp cmp);
void intercambiar(void*x,void*y,size_t tamelem);

int agregarElementoEnVector(void** vec, int* ce, void* elem, size_t tamelem);

int eliminarElementoEnVector(void* vec,int* ce,size_t tamelem,int pos);
int eliminarTElementoEnVector(void* vec,int* ce,void* elem,size_t tamelem,Cmp cmp);

int sumaVector(void* vec,int ce,size_t tamelem,char tipo);
int promedioVector(void* vec,int ce,size_t tamelem,char tipo);

void* hallarMayor(void* vec,int ce,size_t tamelem,Cmp cmp);
void* hallarMenor(void* vec,int ce,size_t tamelem,Cmp cmp);

int eliminarDuplicadosGen(void*vec,int*ce,size_t tamelem,Cmp cmp);


#endif // VECTORES_H_INCLUDED
