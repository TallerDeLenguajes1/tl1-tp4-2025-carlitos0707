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
int tamanio(Lista L);
void mostrar(Lista L);
Tarea buscarPorID(Lista L, short int id);
Tarea buscarPorPalabra(Lista L);
Lista cargarRealizadas(Lista L1,Lista L2);


int main(){
    int op,t,busqueda;
    char palabra[30];
    Tarea tarea;
    srand(time(NULL));
    Lista TareasPendientes,TareasRealizadas;
    TareasPendientes = crearLista();
    TareasPendientes = cargaTareas(TareasPendientes);
    TareasRealizadas = crearLista();
    TareasRealizadas = cargarRealizadas(TareasPendientes,TareasRealizadas);
    mostrar(TareasPendientes);
    mostrar(TareasRealizadas);
    do
    {
        printf("\n\n\nSeleccione una opcion\n\n\n");
        printf("\t 0. Tareas pendientes\n");
        printf("\t 1. Tareas realizadas\n");
        scanf("%d",&t);
        printf("\n\nSeleccione una operacion\n\n");
        printf("\t 0. busqueda por ID\n");
        printf("\t 1. busqueda por palabra");
        scanf("%d",busqueda);
        if (t == 0)
        {
            if (busqueda == 0)
            {
                tarea = buscarPorID(TareasPendientes);
            }
            else
            {
                tarea = buscarPorPalabra(TareasPendientes);
            }
        }
        else{
            if (busqueda == 0)
            {
                tarea = buscarPorID(TareasRealizadas);
            }
            else
            {
                tarea = buscarPorPalabra(TareasRealizadas);
            }
        }
        
    } while (op == 0);
    
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

int tamanio(Lista L){
    Lista aux = L;
    int cont=0;
    while (esListaVacia(aux) == 1)
    {
        cont++;
        aux = aux->Siguiente;
    }
    return cont;
}



Lista cargarRealizadas(Lista L1,Lista L2){
    int op,id;
    Tarea tarea;
    printf("\n\n\nLista de tareas pendientes\n\n\n");
    mostrar(L1);
    do
    {      
        printf("Cargar otra tarea\n\n");
        printf("\t 0. SI\n");
        printf("\t 1. NO\n");
        scanf("%d",&op);
    } while (op == 0);
    
}


Tarea buscarPorID(Lista L){
    Lista aux = L;
    int id;
    do
        {
            printf("\n\nSeleccione el ID de la tarea completada\n\n");
            scanf("%d",&id);
            if (id > tamanio(L))
            {
                printf("No se pudo encontrar la tarea\n");
            }
            if (id < 0)
            {
                printf("ID Invalido \n");
            }                       
        } while (id < 0 || id > tamanio(L));
    for (int i = 0; i < id; i++)
    {
        aux = aux->Siguiente;
    }
    return aux->T;
}


Tarea buscarPorPalabra(Lista L){
    Lista aux;
    printf("Ingrese una palabra\n");
}