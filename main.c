
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//altura
int altura = 0;
//variables para el tiempo
struct timeval inicio, fin;
//metodo para el tiempo
double tiempo(struct timeval *a, struct timeval *b){
return
(double)(a->tv_sec + (double)a->tv_usec/1000000) - (double)(b->tv_sec + (double)b->tv_usec/1000000);
}


typedef struct Otronum{
    int Num;
    struct Otronum *Siguiente;
}Otronum;
//metodo burbuja
typedef struct ListaB{
//struct ListaB *Buble_Sort;
struct Otronum *Primero;
}ListaB;

void InsertarBuble_Sort(ListaB *Coso, int num){
   //referenciadel nodo
   Otronum *Nuevo;
    Nuevo = malloc(sizeof(Otronum));
    Nuevo->Siguiente = NULL;
    Nuevo->Num = num;
//lista vacia
    if(Coso->Primero==NULL){
        Coso->Primero = Nuevo;
    }else{
        Otronum *NodoAux;
        NodoAux = Coso->Primero;

        while(NodoAux->Siguiente!=NULL){
            NodoAux = NodoAux->Siguiente;
        }
        NodoAux->Siguiente = Nuevo;
        NodoAux = Nuevo;
    }
}//mostrar burbuja
void MostrarBuble_Sort(ListaB *OtroCoso){

    Otronum *NodoAux;
    NodoAux= OtroCoso->Primero;

    while(NodoAux!=NULL){
        printf("%d ",NodoAux->Num);
        NodoAux = NodoAux->Siguiente;
    }


}
//Ordenamiento burbuja

int Tam_Archivo=0;

void OrdenamientoBuble_Sort (ListaB *ListaBuble){

int i,j;
int Temporal;
Otronum *NodoBuble;
NodoBuble=ListaBuble->Primero;
//recorriendo
    for (i=1;i<Tam_Archivo;i++){
    NodoBuble=ListaBuble->Primero;
    for(j=0;j<Tam_Archivo-i;j++){
//si su siguiente es mayor entonces cambian
    if(NodoBuble->Num > NodoBuble->Siguiente->Num)
    {

    Temporal=NodoBuble->Num;
    NodoBuble->Num=NodoBuble->Siguiente->Num;
    NodoBuble->Siguiente->Num=Temporal;
            }
    NodoBuble=NodoBuble->Siguiente;

        }
    }
}

//Nodo avl
typedef struct NodoNumero{
    int num;
    int FE;
    struct NodoNumero *Izquierda;
    struct NodoNumero *Derecha;
}NodoNumero;
//Estructura avl
typedef struct Arbol {
    struct NodoNumero *Raiz;
}Arbol;

ListaB *Buble_Sort;
Arbol *AVL;



//Rotaciones
//RII
NodoNumero *RII(NodoNumero *Num, NodoNumero *Num1){
    Num->Izquierda = Num1->Derecha;
    Num1->Derecha = Num;
    if(Num1->FE==-1){
        Num->FE=0;
        Num1->FE= 0;
    }
    else{
        Num->FE= -1;
        Num1->FE= 1;
    }
    return Num1;
}
//RDD
NodoNumero *RDD(NodoNumero *Num, NodoNumero *Num1){
    Num->Derecha = Num1->Izquierda;
    Num1->Izquierda = Num;
    if(Num1->FE==1){
        Num->FE=0;
        Num1->FE= 0;
    }
    else{
        Num->FE= 1;
        Num1->FE= -1;
    }
    return Num1;
}
//RID
NodoNumero *RID(NodoNumero *Num, NodoNumero *Num1){
    NodoNumero *Num2;
    Num2 = Num1->Derecha;
    Num1->Derecha= Num2->Izquierda;
    Num2->Izquierda = Num1;
    Num->Izquierda = Num2->Derecha;
    Num2->Derecha = Num;
    if(Num2->FE==1){
        Num1->FE = -1;
    }
    else{
        Num1->FE=0;
    }
    if(Num2->FE==-1){
        Num->FE= 1;
    }
    else{
        Num->FE=0;
    }
    Num2->FE=0;
    return Num2;
}
//RDI
NodoNumero *RDI(NodoNumero *Num, NodoNumero *Num1){
    NodoNumero *Num2;
    Num2 = Num1->Izquierda;
    Num1->Izquierda = Num2->Derecha;
    Num2->Derecha = Num1;
    Num->Derecha = Num2->Izquierda;
    Num2->Izquierda = Num;
    if(Num2->FE==1){
        Num->FE= -1;
    }
    else{
        Num->FE=0;
    }
    if(Num2->FE==-1){
        Num1->FE = 1;
    }
    else{
        Num1->FE=0;
    }
    Num2->FE=0;
    return Num2;
}

NodoNumero *Insertar(NodoNumero *Nodo, int num){
    NodoNumero *Nodoaux;
    if(Nodo==NULL){
        NodoNumero *Nuevo;
        Nuevo = (NodoNumero *)malloc(sizeof(NodoNumero));
        Nodo = Nuevo;
        Nodo->num = num;
        Nodo->Derecha = NULL;
        Nodo->Izquierda = NULL;
        Nodo->FE=0;
        altura = 1;
    }

    else{
        if(Nodo->num > num){
            Nodo->Izquierda = Insertar(Nodo->Izquierda,num);
            if(altura!=0){
                switch(Nodo->FE){
                    case 1:
                        Nodo->FE = 0;
                        altura=0;
                        break;
                    case 0:
                        Nodo->FE = -1;
                        break;
                    case -1:
                        Nodoaux = Nodo->Izquierda;
                        if(Nodoaux->FE==-1){
                            Nodo = RII(Nodo,Nodoaux);
                        }
                        else{
                            Nodo = RID(Nodo,Nodoaux);
                        }
                        altura=0;
                        break;
                }
            }
        }
        else if(Nodo->num < num){
            Nodo->Derecha = Insertar(Nodo->Derecha,num);
            if(altura!=0){
                switch(Nodo->FE){
                    case 1:
                        Nodoaux = Nodo->Derecha;
                        if(Nodoaux->FE==1){
                            Nodo = RDD(Nodo,Nodoaux);
                        }
                        else{
                            Nodo = RDI(Nodo,Nodoaux);
                        }
                        altura=0;
                        break;
                    case 0:
                        Nodo->FE = 1;
                        break;
                    case -1:
                        Nodo->FE = 0;
                        altura=0;
                        break;
                }
            }
        }
    }
    return Nodo;
}
//mostrar avl
void Mostrar(NodoNumero *Nodo){
    if(Nodo==NULL){
        return;
    }
    int Otroaux = Nodo->num;
    printf("%d",Otroaux);
    Mostrar(Nodo->Izquierda);
    Mostrar(Nodo->Derecha);
}

void InOrden(NodoNumero *Nodo){
    if(Nodo==NULL){
        return;
    }
    InOrden(Nodo->Izquierda);

    int Otroaux = Nodo->num;
    printf("%d ",Otroaux);
    InOrden(Nodo->Derecha);
}

void Lectura(char* Nombre){

    FILE* Archivo=NULL;
    char ReadLine[100];
    int endFile=0;
    Archivo = fopen(Nombre,"r");
    if(Archivo==NULL) return -1;
    endFile = fscanf(Archivo," %[^\n]",&ReadLine);
    int n = atoi(ReadLine);
    AVL->Raiz = Insertar(AVL->Raiz,n);
    InsertarBuble_Sort(Buble_Sort, n);
    Tam_Archivo+=1;
    while(endFile!=EOF){

        endFile = fscanf(Archivo," %[^\n]",&ReadLine);
        if(endFile!=EOF){
        int n = atoi(ReadLine);
        AVL->Raiz = Insertar(AVL->Raiz,n);
        InsertarBuble_Sort(Buble_Sort, n);
        Tam_Archivo+=1;
        }
    }
    printf("\nEl archivo a sido cargado con éxito!\n");
    fclose(Archivo);

}


void Menu(){
    int salir=0;
    int op=0;
    char NombreArchivo[250];
    while(salir==0){
        printf("\n****************************************************************\n");
        printf("Opciones de la aplicacion:\n");
        printf("1. Datos\n");
        printf("2. Recorrido(Inorden)\n");
        printf("3. Ordenamiento (Burbuja)\n");
        printf("4. Ordenamiento (Quiksort)\n");
        printf("5. Tiempos\n");
        printf("6. Graficar\n");
        printf("7. Salir del Programa\n");
        printf("\n****************************************************************\n");
        printf("Eliga una opción a ejecutar: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Archivo:\n");
                fflush(stdin);
                scanf("%s",&NombreArchivo);
                Lectura(NombreArchivo);
                break;
            case 2:
                printf("\nRecorrido del arbol\n");
                InOrden(AVL->Raiz);
                break;
            case 3:
                printf("\nOrdenamiento de burbuja\n");
                OrdenamientoBuble_Sort(Buble_Sort);
                MostrarBuble_Sort(Buble_Sort);
                break;
            case 4:
            //pendiente
                break;
            case 5:
                printf("\nAVL\n");
                gettimeofday(&inicio, NULL);
                InOrden(AVL->Raiz);
                gettimeofday(&fin, NULL);
              float time_arbol = tiempo(&fin, &inicio);
                printf("\nRecorrido del arbol: %lf segundos\n", time_arbol);

                break;
            case 6:
               //pendiente
                break;
            case 7:
                salir = 4;
                break;
        }
    }

}

int main()
{
    AVL =malloc(sizeof(Arbol));
    Buble_Sort = malloc(sizeof(ListaB));
    Menu();

    return 0;
}
