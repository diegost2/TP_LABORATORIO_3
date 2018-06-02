#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define OCUPADO 1
#define LIBRE -1

void Crear_HTML(EMovie *movie,int limite)
{
    FILE *P_Texto;
    int i;
   // char buffer[1000];

    P_Texto=fopen("Mitexto.html","w");

    if(P_Texto==NULL)
    {
        printf("No se pudo abrir el Archivo.");
    }
    else{
           for(i=0;i<limite;i++){

        if(P_Texto!=NULL)
        {
            fprintf(P_Texto,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");

            for(i=0; i<limite; i++)
            {
                if((movie+i)->estado==1)
                {
                    if(!feof(P_Texto))
                    fprintf(P_Texto,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'> %s </a></h3><ul><li>Genero: %s </li><li>Puntaje: %d Pts.</li><li>Duracion: %d Min. </li></ul><p> %s </p></article>",(movie+i)->linkImagen,(movie+i)->titulo,(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion,(movie+i)->descripcion);
                }
            }
            fprintf(P_Texto,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");

        }

            }
    }
        fclose(P_Texto);
      printf("Listado creado con exito\n");
}


void Modificar_Pelicula(EMovie *movie,int limite)
{

    int id;
    int busqueda;
    int opcion;
    Ver_Usuarios(movie,limite);
    printf("\n\nIngrese ID de la pelicula a modificar: ");
    scanf("%d",&id);
    busqueda=BuscarID(movie,limite,id);
    if(busqueda!=-1)
    {
        printf("\nEsta seguro de querer modificar completamente la pelicula: %s ",(movie+busqueda)->titulo);
        printf("\n1)SI.");
        printf("\n1)NO.");
        printf("\nOpcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                {
                    if(busqueda!=-1)
                    {
                        printf("El ID ingresado ya existe.");
                        Pause();
                    }
                    else{
                    printf("\nIngrese titulo: ");
                    fflush(stdin);
                    gets((movie+busqueda)->titulo);

                    printf("\nIngrese Genero: ");
                    fflush(stdin);
                    gets((movie+busqueda)->genero);

                    printf("\nIngrese Duracion: ");
                    fflush(stdin);
                    scanf("%d",&(movie+busqueda)->duracion);

                    printf("\nIngrese descripcion: ");
                    fflush(stdin);
                    gets((movie+busqueda)->descripcion);

                    printf("\nIngrese Link de Imagen: ");
                    fflush(stdin);
                    gets((movie+busqueda)->linkImagen);

                    printf("\nIngrese puntuacion: ");
                    scanf("%d",&(movie+busqueda)->puntaje);

                    (movie+busqueda)->id=id;
                    (movie+busqueda)->estado=1;
                    }
                    Clear();
                    printf("Modificacion Exitosa!.");
                    break;
                }
            case 2:
                {
                    printf("Modificacion cancelada.");
                    break;
                }

        }
    }
    else{
        printf("No se encontro ID.");
        Pause();
    }
}


void Ver_Usuarios(EMovie *movie, int limite)
{
    int i;
    printf("\nID \tTitulo \t\t\tPuntaje \n\n");
    for(i=0;i<limite;i++)
    {
        if((movie+i)->estado==1)
        {
            printf("\n %d \t %s \t%d Pts.\n",(movie+i)->id,(movie+i)->titulo,(movie+i)->puntaje);
        }
    }
}

void Crear_TxT(EMovie *movie,int limite)
{
    FILE *P_Texto;
    int i;

    P_Texto=fopen("Mitexto.txt","w");

    if(P_Texto==NULL)
    {
        printf("No se pudo abrir el Archivo.");
    }
    else{
           for(i=0;i<limite;i++){

            if((movie+i)->estado!=-1)
            {
                fprintf(P_Texto,"\nPelicula: %s \nGenero: %s \nDuracion: %d  Min.\nDescripcion: %s \nPuntaje: %d  Pts.\n\n",(movie+i)->titulo,(movie+i)->genero,(movie+i)->duracion,(movie+i)->descripcion,(movie+i)->puntaje);
            }

            }
    }
        fclose(P_Texto);
      printf("Listado creado con exito\n");
}

int Guardar_Cambios(EMovie *movie, int tam)
{
    FILE *P_Archivo;
    P_Archivo=fopen("MiPelicula.dat","wb");
    if(P_Archivo==NULL)
    {
        return 1;
    }
    fwrite(movie,sizeof(EMovie),tam,P_Archivo);
    fclose(P_Archivo);

    return 0;
}

int LoadMovie(EMovie *movie, int limite)
{
	int flag = 0;
	FILE *pelicula;

	pelicula=fopen("MiPelicula.dat", "rb");
	if(pelicula==NULL)
	{
		pelicula= fopen("MiPelicula.dat", "wb");
		if(pelicula==NULL)
		{
			return 1;
		}

		flag=1;
	}



	if(flag ==0)
	{

	    if(feof(pelicula))
        {
            fread(movie,sizeof(EMovie),limite,pelicula);
            return 2;
        }
    }

	fclose(pelicula);
	return 0;

}

int BuscarID(EMovie* movie, int limite, int ingresado)
{
    int i,retorno=-1;

    for(i=0;i<limite;i++)
    {
        if((movie+i)!=NULL)
        {
            if((movie+i)->id==ingresado)
            {
                if((movie+i)->estado!=-1){
                    retorno=i;
                    break;
                }
            }

        }
    }
    return retorno;
}



int LugarLibre(EMovie* movie, int limite, int Next)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if((movie+i)!=NULL)
        {
            if((movie+i)->estado==Next)
            {
                Next=i;
                break;
            }

        }
    }
    return Next;
}

void Init_Status(EMovie* movie, int limite)
{
    for(int i=0;i<limite;i++)
    {
        if((movie+i)!= NULL ){
            (movie+i)->estado=-1;
            (movie+i)->id=0;
        }
    }
}


int agregarPelicula(EMovie *movie, int tam)
{
    int retorno=-1;
    int id;
    int EspacioObtenido;
    int encontro;

    EspacioObtenido=LugarLibre(movie,tam,-1);
    if(EspacioObtenido==-1)
    {
        printf("\nNo hay mas espacio...\n\n");

    }
    else{
        printf("Ingrese ID: ");
        fflush(stdin);
        scanf("%d",&id);
        encontro=BuscarID(movie,tam,id);
        if(encontro!=-1)
        {
            printf("El ID ingresado ya existe.");
            Pause();
        }

        else{

        printf("\nIngrese Titulo: ");
        fflush(stdin);
        gets((movie+EspacioObtenido)->titulo);

        printf("\nIngrese Genero: ");
        fflush(stdin);
        gets((movie+EspacioObtenido)->genero);

        printf("\nIngrese Duracion: ");
        fflush(stdin);
        scanf("%d",&(movie+EspacioObtenido)->duracion);

        printf("\nIngrese descripcion: ");
        fflush(stdin);
        gets((movie+EspacioObtenido)->descripcion);

        printf("\nIngrese Link de Imagen: ");
        fflush(stdin);
        gets((movie+EspacioObtenido)->linkImagen);

        printf("\nIngrese puntuacion: ");
        scanf("%d",&(movie+EspacioObtenido)->puntaje);
        (movie+EspacioObtenido)->estado=1;
        (movie+EspacioObtenido)->id=id;

        retorno=1;
            }
        Clear();
    }

    return retorno;
}


int borrarPelicula(EMovie *movie, int limite)
{
    int id;
    int encontro;
    int retorno=0;
    int respuesta;
    Ver_Usuarios(movie,limite);
    printf("\nIngrese ID a borrar: ");
    scanf("%d",&id);
    encontro=BuscarID(movie,limite,id);
    if(encontro!=-1)
    {
        printf("\nEsta seguro de borrar la pelicula: %s ",(movie+encontro)->titulo);

        printf("\n\n1)SI");
        printf("\n2)NO");
        printf("\n\nOpcion: ");
        scanf("%d",&respuesta);
        switch(respuesta)
        {
        case 1:
            {
                (movie+encontro)->estado=-1;
                retorno=1;
                break;
            }
        case 2:
            {
                retorno=0;
                Pause();
                break;
            }
        }
    }
    else{
        Clear();
        printf("\nNo se encontro el ID.\n");
    }

    return retorno;
}



void Clear(void){
    system("cls");
}

void Pause(void){
    printf("\n");
    system("pause");

}
