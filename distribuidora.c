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
Lista  QuitarNodo(Lista  L, Tarea dato);
Tarea buscarPorID(Lista L);
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
    printf("\n\n\nTareas pendientes\n\n\n");
    mostrar(TareasPendientes);
    printf("\n\n\nTareas completadas\n\n\n");
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
        scanf("%d",&busqueda);
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
    return 0;
}


Lista crearLista(){
    return NULL;
}


int esListaVacia(Lista L){
    if (L == NULL)
    {
        return 1;
    }
    else{
        return 0;
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
        nuevo->T.Descripcion = (char *)malloc(sizeof(char) * (strlen(desc) + 1));
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
    if (esListaVacia(L) == 1)
    {
        printf("No hay tareas");
    }
    else{ 
        Lista aux;
        aux = L;
        while(esListaVacia(aux) == 0){
            printf("\n\n*******Tarea: %d*******\n\n",aux->T.TareaID);
            printf("\tDuracion: %d Hs\n\n",aux->T.Duracion);
            printf("\tDescripcion: ");
            puts(aux->T.Descripcion);
            aux = aux->Siguiente;
        }
    }
}




Lista cargarRealizadas(Lista L1,Lista L2){
    int op,id;
    Tarea tarea;
    printf("\n\n\nLista de tareas pendientes\n\n\n");
    mostrar(L1);
    do
    {   
        tarea = buscarPorID(L1); //busca el nodo
        if (tarea.TareaID != -1)
        {
            Lista aux = QuitarNodo(L1,tarea); //desvincula el nodo de la lista de tareas pendientes
            if (aux != NULL)
            {
                aux->Siguiente = L2;
                L2 = aux;
            }
        }
        printf("Cargar otra tarea\n\n");
        printf("\t 0. SI\n");
        printf("\t 1. NO\n");
        scanf("%d",&op);
    } while (op == 0);
    return L2;
}


Lista  QuitarNodo(Lista  L, Tarea dato){
    Lista * aux = &L;
    while (esListaVacia(*aux) == 0 && (*aux)->T.TareaID != dato.TareaID){
        aux = &(*aux)->Siguiente;
    }
    if(*aux){
        Lista temp = *aux;
        *aux = (*aux)->Siguiente;
        temp->Siguiente = NULL;
        return temp;
    }
    return NULL;
}


Tarea buscarPorID(Lista L){
    Lista aux = L;
    int id;
    printf("Ingrese un ID\n");
    scanf("%d",&id);
    while (esListaVacia(L) == 1 && aux->T.TareaID != id)
    {
        aux = aux->Siguiente;
    }
    if (aux->T.TareaID == id)
    {
        return aux->T;
    }
    else{
        printf("Tarea no encontrada\n");
        Tarea vacia = {-1,NULL,0};
        return vacia;
    }
}


Tarea buscarPorPalabra(Lista L){
    Lista aux = L;
    char palabra[50];
    printf("Ingrese una palabra\n");
    fflush(stdin);
    gets(palabra);
    while (esListaVacia(aux) == 0 && strstr(aux->T.Descripcion,palabra) == NULL)
    {
        aux = aux->Siguiente;
    }
    if (strstr(aux->T.Descripcion,palabra) != NULL)
    {
        return aux->T;
    }
    else{
        printf("No se encontro la tarea\n");
        Tarea vacia = {-1,NULL,0};
        return vacia;
    }
}