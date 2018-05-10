#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 100

typedef struct
{
    //Generica de usuario
    char nombre[TAM][50];
    int id;
    int estado;
}eUsuario;

#endif // FUNCIONES_H_INCLUDED

/** \brief Esta funcion inicializa en 0 los estados de la estructura
 * \param lista[] eUsuario Estructura que se le inicializa el estado en 0
 * \param tam int Tamaño de la estructura
 * \return void
 */
void inicializarEstados(eUsuario lista[],int tam);

/** \brief Esta funcion carga las estructuras con datos
 * \param lista[] eUsuario Estructura que se va a cargar con datos
 * \param tam int Tamaño de la estructura que se va a cargar
 * \return void
 */
void cargarHardcode(eUsuario lista[],int tam);

/** \brief Esta funcion muestra un menu principal con opciones e invoca a las funciones
 * \param lista[] eUsuario Esta estructura se pasa al resto de las funciones
 * \param tam int Tamaño de la estructura
 * \return void
 */
void menu(eUsuario lista[],int tam);

/** \brief Esta funcion toma un string y lo valida
 * \param mensaje[] char Mensaje que se muestra al usuario
 * \param caracter[] char Array que guarda el string ingresado
 * \return char Retorna el string validado
 */
char getString(char mensaje[], char caracter[]);

/**
 * \brief Esta funcion toma un entero y lo valida
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param A int Entero que va a guardar el valor ingresado
 * \return int Retorna el entero validado
 */
int getInt(char mensaje[],int ent);

/** \brief Recibe un numero tipo float y lo retorna como int
 * \param mensaje[] char Mensaje que se muestra al usuario
 * \param numeroIngresado float Numero flotante ingresado
 * \return float El numero flotante ingresado por el usuario
 */
float getFloat(char mensaje[],float numeroIngresado);

/** \brief Esta funcion toma un caracter y lo valida
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param caracter char Caracter que va a guardar el input
 * \return char Caracter validado
 */
char getChar(char mensaje[],char caracter);

/** \brief Esta funcion convierte en mayuscula la primera letra del string que se ingresa
 * \param caracter[] char String a modificar
 * \return void
 */
void stringToUpper(char caracter[]);

/** \brief Esta funcion valida si el dato ingresado es un numero entero
 * \param datoAValidar[] char Dato a validar que debe pasarse como string
 * \return int Retorna el entero ya validado
 */
int validarStringEntero(char datoAValidar[]);

/** \brief Esta funcion valida si la cadena ingresada es un string
 * \param datoAValidar[] char Cadena a validar
 * \return char Retorna la cadena validada
 */
char validarStringCadena(char datoAValidar[]);

/** \brief Esta funcion valida si el dato ingresado es un caracter
 * \param datoAValidar char Caracter a validar
 * \return char Retorna el caracter validado
 */
char validarStringCaracter(char datoAValidar);

/** \brief Esta funcion valida si el dato ingresado es un numero flotante
 * \param datoAValidar[] char Dato a validar que debe pasarse como string
 * \return float Retorna el flotante validado
 */
float validarStringFloat(char datoAValidar[]);

/** \brief Esta funcion le pregunta al usuario si desea continuar
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \return char Retorna la respuesta del usuario
 */
char deseaContinuar(char mensaje[]);

/** \brief Esta funcion da de alta a los usuarios
 * \param lista[] eUsuario Estructura en la que se va a dar de alta a los usuarios
 * \param tam int Tamaño de la estructura
 * \param indice int Indice libre en el que se va a dar de alta al usuario
 * \return void
 */
void altaUsuario(eUsuario lista[],int tam,int indice);

/** \brief Esta funcion busca un estado libre para ingresar al usuario
 * \param lista[] eUsuario Estructura en la que se va a buscar el estado libre
 * \param tam int Tamaño de la estructura
 * \return int Indice en donde se encuentra el primer estado libre
 */
int buscarLibre(eUsuario lista[],int tam);

/** \brief Esta funcion asigna automaticamente un Id a las nuevas altas
 * \param lista[] eUsuario Estructura a la que se le asigna el ID
 * \param tam int Tamaño de la estructura
 * \return int Retorna el siguiente ID
 */
int idAutoIncremental(eUsuario lista[],int tam);

/** \brief Esta funcion muestra un elemento dentro de una estructura de arrays
 * \param lista[] eUsuario Estructura a mostrar
 * \param tam int Tamaño de la estructura
 * \param i int Subindice de la estructura que se va a mostrar
 * \return void
 */
void mostrarUno(eUsuario lista[],int tam,int i);

/** \brief Esta funcion invoca a mostrarUno y muestra todos los elementos de la estructura
 * \param lista[] eUsuario Estructura que se muestra
 * \param tam int Tamaño de la estructura
 * \return void
 */
void mostrarLista(eUsuario lista[],int tam);

/** \brief Esta funcion le presenta al usuario un menu en el que le permite elegir que modificar
 * \param lista[] eUsuario Estructura que se va a modificar
 * \param tam int Tamaño de la estructura
 * \return void
 */
void modificarUsuario(eUsuario lista[],int tam);

/** \brief Esta funcion toma un Id ingresado por el usuario y lo compara con todos los ID pertenecientes a la estructura
 * \param lista[] eUsuario Estructura con la que se comparara el ID ingresado
 * \param tam int Tamaño de la estructura
 * \param id int Id que ingresa el usuario
 * \return int El subindice en el que encontro el ID o -1 si no lo encontro
 */
int buscarPorId(eUsuario lista[],int tam,int id);

/** \brief Esta funcion permite modificar un string dentro de una estructura
 * \param lista[] eUsuario Estructura en la que se va a modificar el string
 * \param indice int Indice de la estructura en el que se va a modificar el string
 * \param caracter[] char Array de caracteres en donde se va a guardar el nuevo string ingresado
 * \return char Retorna el string modificado
 */
char modificarString(eUsuario lista[],int indice,char caracter[]);

/** \brief Esta funcion permite modificar un entero dentro de una estructura
 * \param lista[] eUsuario Estructura en la que se va a modificar el entero
 * \param indice int Indice de la estructura en el que se va a modificar el entero
 * \param dato int Variable que guarda el dato ingresado
 * \return int Retorna el entero modificado
 */
int modificarEntero(eUsuario lista[],int indice,int dato);

/** \brief Esta funcion permite modificar un flotante dentro de una estructura
 * \param lista[] eUsuario Estructura en la que se va a modificar el float
 * \param indice int Indice de la estructura en el que se va a modificar el float
 * \param dato float Variable que guarda el dato ingresado
 * \return float Retorna el flotante modificado
 */
float modificarFlotante(eUsuario lista[],int indice,float dato);

/** \brief Esta funcion pide un ID al usuario para realizar una baja
 * \param lista[] eUsuario Estructura en la que se va a dar de baja
 * \param tam int Tamaño de la estructura
 * \param mensaje[] char Mensaje que se muestra al usuario preguntando si desea efectuar la baja
 * \return void
 */
void darDeBaja(eUsuario lista[],int tam,char mensaje[]);

/** \brief Esta funcion confirma si el usuario realmente quiere realizar la baja. Si es asi cambia el estado de la estructura por 2
 * \param lista[] eUsuario Estructura a la que se va a realizar la baja
 * \param indice int Indice en la que se va a realizar la baja
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \return void
 */
void borrarEntidad(eUsuario lista[],int indice,char mensaje[]);

/** \brief Esta funcion ordena una estructura segun el criterio de ordenamiento que se requiera
 * \param lista[] eUsuario Estructura a ordenar
 * \param tam int Tamaño de la estructura
 * \return void
 */
void ordenarSegunCriterio(eUsuario lista[],int tam);

/** \brief Esta funcion muestra todos los usuarios dados de baja
 * \param lista[] eUsuario Estructura que tiene los usuarios borrados a mostrar
 * \param tam int Tamaño de la estructura
 * \return void
 */
void mostrarBorrados(eUsuario lista[],int tam);

/** \brief Esta funcion muestra dos estructuras relacionadas de manera 1 a 1
 * \param lista[] eUsuario Primera estructura a mostrar
 * \param tam int Tamaño de la primera estructura
 * \param lista[] eGenericaEstructuraDos Segunda estructura a mostrar
 * \param tamEstructura2 int Tamaño de la segunda estructura
 * \return void
 */
void mostrarUnoConUno(eUsuario lista[],int tam,eGenericaEstructuraDos lista[],int tamEstructura2);

/** \brief Esta funcion muestra dos estructuras relacionadas de manera 1 a muchos
 * \param lista[] eUsuario Primera estructura a mostrar (Uno)
 * \param tam int Tamaño de la primera estsructura
 * \param lista[] eGenericaEstructuraDos Segunda estructura a mostrar (Muchos)
 * \param tamEstructura2 int Tamaño de la segunda estructura
 * \return void
 */
void mostrarUnoConMuchos(eUsuario lista[],int tam,eGenericaEstructuraDos lista[],int tamEstructura2);

#endif // FUNCIONES_H_INCLUDED
