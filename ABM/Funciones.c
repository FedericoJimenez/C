#include<stdio.h>
#include"Funciones.h"
#include<string.h>
#include<ctype.h>

void inicializarEstados(eUsuario lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}

void cargarHarcode(eUsuario lista[],int tam)
{
    char nombre[20][50]= {"Luis","Anthony","Josefa","Lalo","Alberta","Eudoxio","Javier","Gonzalo","Gerson","Florencia","Francis","Ciruleo","Exelcio","Roberto","Alejandra","Carlos","Matias","Natalio","Dante","Franco"};
    int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    int edad[20]= {15,25,12,100,97,3,46,92,24,96,43,83,25,89,41,79,97,37,21,28};
    char direccion[20][50]= {"Farrel 9531","Rucci 2318","Remedios de escalada 1649","Bacacay 9313","Yatay 3216","Diamante 6598","Vasquez 3198","Avenida Nazca 751","San Pedrito 394","Tuyuti 2293","Lomas Valentinas 915","Paso de Burgos 8654","Avenida Mitre 2464","Liniers 2266","Florida 2349","Coronel D'elia 3616","San Martin 9741","Balbin 945","Viamonte 549","Manuel Belgrano 3954"};
    int telefono[20]= {39665247,46057895,22367458,66654897,10456964,46222596,78453256,34521689,11169878,45567785,37894563,22224458,66697852,22364415,77829953,82930100,05126472,55962232,47859965,88956621};
    char apellido[20][50]= {"Lazco","Dalario","Fernandez","Vargas","Bazco","Gal","Roasi","Vitale","Pacheco","Jimenez","Quispe","Lezcano","Velazquez","Gonzalez","Sini","Gasparro","Estarc","Acuñez","Venochi","Beneli"};
    int i;
    for(i=0; i<20; i++)
    {
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].Id=edad[i];
        lista[i].estado=1;
    }
}

void menu(eUsuario lista[],int tam)
{
    inicializarEstados(lista,tam);
    //cargarHarcode(lista,tam);
    char seguir='s';
    int opcion;
    int indice;
    int contador=0;
    do
    {
        printf("1- Agregar");
        printf("\n2- Mostrar");
        printf("\n3- Modificar");
        printf("\n4- Borrar");
        printf("\n5- Ordenar");
        printf("\n6- Mostrar Borrados");
        printf("\n7- Mostrar uno a uno");
        printf("\n8- Mostrar uno a muchos");
        printf("\n9- Salir\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            indice=buscarLibre(lista,tam);
            altaUsuario(lista,tam,indice);
            break;
        case 2:
            mostrarLista(lista,tam);
            break;
        case 3:
            modificarUsuario(lista,tam);
            break;
        case 4:
            darDeBaja(lista,tam,"\nEstas seguro que queres dar de baja este usuario? (S/N) ");
            break;
        case 5:
            ordenarSegunCriterio(lista,tam);
            break;
        case 6:
            mostrarBorrados(lista,tam);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            seguir='n';
            break;
        }
        if(seguir!='n')
        {
            seguir=deseaContinuar("\nDesea continuar con el programa? (S/N) ");

        }

        system("cls");
    }
    while(seguir=='s');
}

char getString(char mensaje[], char caracter[])
{

    printf("%s",mensaje);
    gets(caracter);
    fflush(stdin);
    caracter=validarStringCadena(caracter);
    return caracter;
}

int getInt(char mensaje[],int A)
{

    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    A=validarStringEntero(auxstring);
    return A;
}

float getFloat(char mensaje[],float numeroIngresado)
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    numeroIngresado=validarStringFloat(auxstring);
    return numeroIngresado;
}

char getChar(char mensaje[],char caracter)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%c",&caracter);
    caracter=validarStringCaracter(caracter);
    return caracter;
}

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}

int validarStringEntero(char datoAValidar[])
{
    int A;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ')
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ');
        }
        else
        {
            i=i+1;
        }
    }
    A=atoi(datoAValidar);
    return A;
}

char validarStringCadena(char datoAValidar[])
{
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isalpha(datoAValidar[i])==0&&datoAValidar[i]!=' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar[i])==0);
        }
        else if(datoAValidar[0]== ' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(datoAValidar[0]==' ');
        }
        else
        {
            i=i+1;
        }

    }
    return datoAValidar;
}

char validarStringCaracter(char datoAValidar)
{
        if(isalpha(datoAValidar)==0||datoAValidar==' ')
        {
            do
            {
                printf("\nIngresa un caracter valido ");
                scanf("%c",&datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar)==0||datoAValidar==' ');
        }
        return datoAValidar;
}

float validarStringFloat(char datoAValidar[])
{
    float numero;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(datoAValidar[i])==0)
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0);
        }
        else
        {
            i=i+1;
        }
    }
    numero=atof(datoAValidar);
    return numero;
}

char deseaContinuar(char mensaje[])
{
    char seguir;
    do
    {
        seguir=getChar(mensaje,seguir);
        seguir=tolower(seguir);
        fflush(stdin);
    }
    while(seguir!='s'&&seguir!='n');
    return seguir;
}

void altaUsuario(eUsuario lista[],int tam,int indice)
{
    if(indice!=-1)
    {
        getString("Ingresa tu nombre de usuario ",lista[indice].nombre);
        stringToUpper(lista[indice].nombre);
        lista[indice].Id=idAutoIncremental(lista,tam);
        lista[indice].estado=1;
    }
    else
    {
        printf("\nNo hay lugares libres");
    }
}

int buscarLibre(eUsuario lista[],int tam)
{
    int indice;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int idAutoIncremental(eUsuario lista[],int tam)
{
    int contador=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1||lista[i].estado==2)
        {
            contador=contador+1;
        }
    }
    return contador;
}

void mostrarUno(eUsuario lista[],int tam,int i)
{
    printf("\n\nNombre: %s\nId: %d",lista[i].nombre,lista[i].Id);
}

void mostrarLista(eUsuario lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarUno(lista,tam,i);
        }

    }
}

void modificarUsuario(eUsuario lista[],int tam)
{
    fflush(stdin);
    int Id;
    int indice;
    int opcion;
    opcion=getInt("\nQue queres modificar?\n1- Nombre\n",opcion);
    fflush(stdin);
    switch(opcion)
    {
    case 1:
        mostrarLista(lista,tam);
        Id=getInt("\nIngresa el Id del nombre que queres modificar ",Id);
        indice=buscarPorId(lista,tam,Id);
        modificarString(lista,indice,lista[indice].nombre);
        break;
    }
}

int buscarPorId(eUsuario lista[],int tam,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].Id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

char modificarString(eUsuario lista[],int indice,char caracter[])
{
    if(indice!=-1)
    {
        getString("\nIngresa el nuevo dato: ",lista[indice].nombre);
        stringToUpper(lista[indice].nombre);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

int modificarEntero(eUsuario lista[],int indice,int dato)
{
    if(indice!=-1)
    {
        getInt("\nIngresa el nuevo dato: ",lista[indice].Id);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

float modificarFlotante(eUsuario lista[],int indice,float dato)
{
    if(indice!=-1)
    {
        getFloat("\nIngresa el nuevo dato: ",lista[indice].Id);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

void darDeBaja(eUsuario lista[],int tam,char mensaje[])
{
    int Id;
    int indice;
    fflush(stdin);
    mostrarLista(lista,tam);
    Id=getInt("\nIngresa el Id a dar de baja ",Id);
    indice=buscarPorId(lista,tam,Id);
    borrarEntidad(lista,indice,mensaje);
}

void borrarEntidad(eUsuario lista[],int indice,char mensaje[])
{
    char pregunta;
    if(indice!=-1)
    {
        pregunta=deseaContinuar(mensaje);
        if(pregunta=='s')
        {
            lista[indice].estado=2;
        }

    }
    else
    {
        printf("\nId no encontrado");
    }
}

void ordenarSegunCriterio(eUsuario lista[],int tam)
{
    eUsuario aux;
    int i;
    int j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].estado==1&&lista[j].estado==1)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }
        }
    }
    mostrarLista(lista,tam);
}





void mostrarBorrados(eUsuario lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==2)
        {
            mostrarUno(lista,tam,i);
        }
    }
}

void mostrarUnoConUno(eUsuario lista[],int tam,eGenericaEstructuraDos lista[],int tamEstructura2)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tamEstructura2; j++)
        {
            if(lista[i].estado!=0)
            {


                if(lista[i].parametro==lista[j].parametro)
                {
                    printf("\n\n %s \n %s",lista[i].parametro,lista[j].parametro);
                    break;
                }
            }
        }
    }
}

void mostrarUnoConMuchos(eUsuario lista[],int tam,eGenericaEstructuraDos lista[],int tamEstructura2)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=0)
        {
            printf("     %s",lista[i].parametro);
            for(j=0; j<tamEstructura2; j++)
            {
                if(lista[j].parametro==lista[i].parametro)
                {
                    printf("\n  %s\n",lista[j].parametro);
                }
            }
        }
    }
}
