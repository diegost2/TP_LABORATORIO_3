#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[300];
    int estado;
    int id;
}EMovie;

#endif // FUNCIONES_H_INCLUDED

/** \brief Modifica una pelicula completa
 *
 * \param movie estructura a ser modificada
 * \param limite cantidad de peliculas
 * \return void
 *
 */
void Modificar_Pelicula(EMovie *movie,int limite);

/** \brief Mostrar usuarios
 *
 * \param movie estructura a ser mostrada
 * \param limite cantidad de peliculas para mostrar
 * \return void
 *
 */
void Ver_Usuarios(EMovie *movie, int limite);

/** \brief Busca un ID
 *
 * \param movie estructura en donde se busca el ID
 * \param limite cantidad de peliculas
 * \param ingresado id ingresado para ser buscado
 * \return int retorna -1 si no encuentra el id, si no retorna el ID
 *
 */
int BuscarID(EMovie* movie, int limite,int ingresado);

/** \brief Guarda los cambios hechos
 *
 * \param movie estructura a ser guardada dentro de un archivo
 * \param tam cantidad de peliculas
 * \return int retorna 1 si no encontro el archivo, si lo encuentra retorna 0
 *
 */
int Guardar_Cambios(EMovie *movie, int tam);

/** \brief Carga el Archivo
 *
 * \param movie estructura a escribir
 * \param limite cantidad de peliculas
 * \return int si retorna 1 no se encontro el archivo, si devuelve 2 se encontro el archivo
 *
 */
int LoadMovie(EMovie *movie, int limite);

/** \brief Inicializa los estados y los id
 *
 * \param movie estuctura a ser modificada
 * \param limite cantidad de peliculas
 * \return void
 *
 */
void Init_Status(EMovie *movie, int limite);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie, int tam);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *movie, int limite);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movie la lista de peliculas a ser agregadas en el archivo.
 *  @param limite cantidad de peliculas a agregar.
 */
void Crear_HTML(EMovie *movie, int limite);


/** \brief pausa
 *
 * \param void
 * \return void
 *
 */
void Pause(void);

/** \brief Salto de linea y Limpiar pantalla
 *
 * \param void
 * \return void
 *
 */
void Clear(void);
