#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 10
int main()
{
    EMovie Movie[TAM];
    Init_Status(Movie, TAM);

    if(LoadMovie(Movie,TAM)==1)
	{
		printf("No se pudo abrir el fichero");

	}
	else
	{
		printf("Se cargaron las estructuras con exito\n\n");

	}

   Pause();
   Clear();

    char seguir='s';
    int opcion=0;
    int agregar;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula.\n");
        printf("2- Borrar pelicula.\n");
        printf("3- Modificar Pelicula. \n");
        printf("4- Generar Pagina Web.\n");
        printf("5- Salir.\n");

        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    Clear();
                    agregar=agregarPelicula(Movie,TAM);
                    if(agregar!=-1)
                    {
                        printf("Pelicula Agregada con exito!.\n");
                        Pause();
                        Clear();
                    }
                    else{
                        printf("Error al Agregar Pelicula.");
                        Pause();
                        Clear();
                    }
                    break;
                }
            case 2:
                {
                    Clear();
                    if(borrarPelicula(Movie,TAM)==1)
                    {
                        Clear();
                        printf("\nPelicula borrada con exito!\n\n");
                    }
                    else
                    {

                        printf("\nBorrado cancelado.\n\n");
                    }

                    Pause();
                    Clear();
                    break;
                }
            case 3:
                {
                    Clear();
                    Modificar_Pelicula(Movie,TAM);
                    Clear();
                    break;
                }
            case 4:
                {
                    Crear_HTML(Movie,TAM);
                    Pause();
                    Clear();
                    break;
                }
            case 5:
                {
                    Clear();
                    int retorno;
                    int opcion;
                    printf("\nEsta seguro salir ? ");
                    printf("\n1)SI.");
                    printf("\n2)NO.");
                    printf("\n\nOpcion: ");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:{
                            Clear();
                            retorno=Guardar_Cambios(Movie,TAM);
                            if(retorno==1)
                            {
                                printf("\nNo se encontro el archivo.");
                            }
                            else{
                                printf("\nSaliendo y Guardando cambios...");
                            }
                            seguir = 'n';
                            Pause();
                            break;
                            }
                        case 2:{
                            printf("\nVolviendo al Menu.");
                            seguir = 's';
                            Clear();
                            break;
                        }
                    }
                    break;
                }
        }
    }

    return 0;
}
