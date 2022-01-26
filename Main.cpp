#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define Delimc ";"//Delimitador de campo
#define DelimR "|"//Delimitador de registro

using namespace std;

FILE *fd;//Se crea el archivo con el puntero fd
FILE *fd1;
FILE *fd2;

fpos_t posActual; //Ver posicion en el archivo, tipos de archivo
fpos_t posLista;

void CrearLista(){//funcion crear lista
    char nombreLista[50],descripcionLista[500],CategoriaLista[50],rpt;
    if ((fd=fopen("rlv.txt","a+"))==NULL){//Si no se puede escribir texto
        cout<<"No se puede crear la lista";return;}

    do{
        fflush(stdin);
        cout<<"\n\n\t\t\t-----------------------CREAR LISTA------------------------------\n\n";
        cout<<"Ingresa el nombre de la lista: ";gets(nombreLista);
        cout<<"Ingresa la descripcion de la lista: ";gets(descripcionLista);
        cout<<"Ingresa la categoria a la que pertenece la lista: ";gets(CategoriaLista);

        fwrite(nombreLista,1,strlen(nombreLista),fd);
        //nombre, cuantos nombres, tamaño de longitud y en donde se guarda.

        fwrite(Delimc,1,1,fd);

        fwrite(descripcionLista,1,strlen(descripcionLista),fd);
        fwrite(Delimc,1,1,fd);

        fwrite(CategoriaLista,1,strlen(CategoriaLista),fd);
        fwrite(DelimR,1,1,fd);

        cout<<"\nDesea agregar mas listas [s/n]: ";cin>>rpt;



    }while(rpt=='s');
    fclose(fd);

}

void ImprimirLista(){
char k;//almacena cada elemento de nuestra lista

if ((fd=fopen("rlv.txt","rt"))==NULL){//leer archivo
        return;}

    while(!feof(fd)){
        k = fgetc(fd);
        if (k==';'){
            cout<<"\n";continue; //(es para que no se vea el ;)
        }
        if (k=='|'){
            cout<<"\n\n\n";continue;//(es para que no se vea el |)
        }
        cout<<k;
    }
    fclose(fd);
}

void BuscarLista(){
    char k,nom[50],nombreLista[50],descripcionLista[500],CategoriaLista[50];
    int c=0,x=0,y=0,z=0;
    if((fd=fopen("rlv.txt","rt"))==NULL){//si no se puede crear el archivo retorna
        return;}

    fflush(stdin);
    cout <<"\n\n\t\t\t---------------------BUSCAR LISTA---------------------";
    cout<<"\n\nIntroduce el nombre de la lista que deseas buscar: ";gets(nom);

    while(!feof(fd)){//mientras que no llegue al final el archivo
        k=fgetc(fd);
        if (k==';'){c++;nombreLista[x]='\0';descripcionLista[y]='\0';continue;}
        if (k=='|'){CategoriaLista[z]='\0';
            if(strcmp(nom,nombreLista)==0){

                cout<<"\nDescripcion de la lista: ";
                cout<<descripcionLista;

                cout<<"\n\nCategoria a la que pertenece: ";
                cout<<CategoriaLista;
                cout<<"\n\n";
                break;
            }
        c=0,x=0,y=0,z=0;continue;
        }


        if (c==0){nombreLista[x++]=k;}
        if (c==1){descripcionLista[y++]=k;}
        if (c==2){CategoriaLista[z++]=k;}

    }
fclose(fd);
}

void ModificarListas(){

	char k, nom[50],nombreLista[50],descripcionLista[500],CategoriaLista[50];
	int x=0;

	if ((fd1=fopen("rlv.txt","r+"))==NULL){return;}
	if ((fd2=fopen("tmp.txt","w+"))==NULL){return;}

	fgetpos(fd1, &posLista);

	fflush(stdin);
	cout<<"Introduce el nombre de la lista: ";gets(nom);

	while(!feof(fd1)){
        k=fgetc(fd1);

        if(k==';'){

          nombreLista[x]='\0';

        	if(strcmp(nom,nombreLista) == 0){

            fseek(fd1, 0, SEEK_SET);
            fgetpos(fd1, &posActual);
            while(posActual != posLista){

              k = fgetc(fd1);
              fputc(k, fd2);
              fgetpos(fd1, &posActual);
            }

            k = getc(fd1);

            while (k != '|') {
              k  = fgetc(fd1);  //solo para que avance el archivo hasta la proxima lista
            }

            cout<<"Ingresa el nuevo nombre de la lista: ";gets(nombreLista);

            fputs(nombreLista, fd2);
            fputc(';', fd2);

            cout<<"Ingresa la nueva descripcion de la lista: ";gets(descripcionLista);
            cout<<"Ingresa la nueva categoria a la que pertenece la lista: ";gets(CategoriaLista);

            fwrite(descripcionLista,1,strlen(descripcionLista),fd2);
            fwrite(Delimc,1,1,fd2);

            fwrite(CategoriaLista,1,strlen(CategoriaLista),fd2);

            while(!feof(fd1)){
              fputc(k, fd2);  //copia todo lo que esta despues de la lista a modificar en el temporal
              k = fgetc(fd1);
            }

            fclose(fd1);
            fclose(fd2);

            int result;

            remove("rlv.txt");

            result= rename( "tmp.txt" , "rlv.txt" );
            if ( result == 0 )
              puts ( "Lista modificada." );
            else
              perror( "Error modificando la lista." );

          return;

          }else{
            while (k != '|') {
              k  = fgetc(fd1);
            }
            fgetpos(fd1, &posLista); //tomamos la posicion de la siguiente lista
            k = fgetc(fd1); //para que quite el '|' de k y no entre en nombreaLista
            x=0; //para que vuelva a tomar el nombre de la lista para comparar


          }



        }

    nombreLista[x++]=k;

  }

  fclose(fd1);
  fclose(fd2);

}

void EliminarListas(){

	char k, nom[50], nombreLista[50];
	int x=0;

	if ((fd1=fopen("rlv.txt","r+"))==NULL){return;}
	if ((fd2=fopen("tmp.txt","w+"))==NULL){return;}

	fgetpos(fd1, &posLista);

	fflush(stdin);
	cout<<"Introduce el nombre de la lista: ";gets(nom);

	while(!feof(fd1)){
        k=fgetc(fd1);

        if(k==';'){

          nombreLista[x]='\0';

        	if(strcmp(nom,nombreLista) == 0){

            fseek(fd1, 0, SEEK_SET);
            fgetpos(fd1, &posActual);
            while(posActual != posLista){

              k = fgetc(fd1);
              fputc(k, fd2);
              fgetpos(fd1, &posActual);
            }

            k = getc(fd1);

            while (k != '|') {
              k  = fgetc(fd1);  //solo para que avance el archivo hasta la proxima lista
            }

            k = fgetc(fd1);

            while(!feof(fd1)){
              fputc(k, fd2);  //copia todo lo que esta despues de la lista a modificar en el temporal
              k = fgetc(fd1);
            }

            fclose(fd1);
            fclose(fd2);

            int result;

            remove("rlv.txt");

            result= rename( "tmp.txt" , "rlv.txt" );
            if ( result == 0 )
              puts ( "Lista eliminada." );
            else
              perror( "Error modificando la lista." );

          return;

          }else{
            while (k != '|') {
              k  = fgetc(fd1);
            }
            fgetpos(fd1, &posLista); //tomamos la posicion de la siguiente lista
            k = fgetc(fd1); //para que quite el '|' de k y no entre en nombreaLista
            x=0; //para que vuelva a tomar el nombre de la lista para comparar


          }



        }

    nombreLista[x++]=k;

  }

  fclose(fd1);
  fclose(fd2);

}


int main()
{
    int opc;

    do{

        cout<<"\n\n\t\t\t\t---------------------MENU----------------------\n\n";

        cout<<"\n1. Crear lista de peliculas";
        cout<<"\n2. Imprimir listas";
        cout<<"\n3. Buscar lista";
        cout<<"\n4. Modificar Listas";
        cout<<"\n5. Eliminar Listas";
        cout<<"\n6. Salir";
        cout<<"\nOpcion: ";
        cin>>opc;
        cout<<"\n\n ";


        switch(opc){
            case 1: {CrearLista();break;}

            case 2: {
            cout<<"\n\t\t\t------------------------IMPRIMIR LISTAS-----------------------\n\n";
                    ImprimirLista();break;}

            case 3: {BuscarLista();break;}

            case 4:{
            cout<<"\n\t\t\t------------------------MODIFICAR LISTA-----------------------\n\n";
                ModificarListas();break;}

            case 5:{
            cout<<"\n\t\t\t------------------------ELIMINAR LISTA-----------------------\n\n";
                EliminarListas();break;}
        }

    }while(opc!=6);

    system("pause");
    return 0;
}
