#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;


struct Nodo{
    Tarea T;
    struct Nodo* Siguiente;
}typedef Nodo;

typedef Nodo* Lista;

Lista crearLista();
Lista cargaTareas(Lista L);
int esListaVacia(Lista L);
void mostrar(Lista L);
Lista cargarRealizadas(Lista L1,Lista L2);


int main(){
    srand(time(NULL));
    Lista TareasPendientes;
    TareasPendientes = crearLista();
    TareasPendientes = cargaTareas(TareasPendientes);
    mostrar(TareasPendientes);
}


Lista crearLista(){
    return NULL;
}


int esListaVacia(Lista L){
    if (L == NULL)
    {
        return 0;
    }
    else{
        return 1;
    }
    
}




Lista cargaTareas(Lista L){
    int op,i=0;
    char desc[100];
    do
    {
        printf("\n\n\n**********Cargar tarea: %d**********\n\n\n",i + 1000);
        Nodo* nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->T.TareaID = 1000 + i;
        nuevo->T.Duracion = rand()%(100 - 10 + 1) + 10;
        printf("Ingrese la descripcion del producto\n");
        fflush(stdin);
        gets(desc);
        nuevo->T.Descripcion = (char *)malloc(sizeof(char) * strlen(desc));
        strcpy(nuevo->T.Descripcion,desc);
        nuevo->Siguiente = L;
        L = nuevo;
        i++;
        printf("\n\n\nIngresar Nueva tarea\n");
        printf("\t 0. SI\n");
        printf("\t 1. NO\n\n\n");
        scanf("%d",&op);
    } while (op == 0);
    return L;
}



void mostrar(Lista L){
    if (esListaVacia(L) == 0)
    {
        printf("No hay tareas pendientes");
    }
    else{ 
        Lista aux;
        aux = L;
        while(esListaVacia(aux) == 1){
            printf("\n\n*******Tarea: %d*******\n\n",aux->T.TareaID);
            printf("\tDuracion: %d Hs\n\n",aux->T.Duracion);
            printf("\tDescripcion: ");
            puts(aux->T.Descripcion);
            aux = aux->Siguiente;
        }
    }
}