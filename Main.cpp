#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define Delimc ";"
#define DelimR "|"

using namespace std;

FILE *fd;
FILE *fd1;
FILE *fd2;



void CrearLista(){
    char nombreLista[50],descripcionLista[500],CategoriaLista[50],rpt;
    if ((fd=fopen("rlv.txt","wt"))==NULL){
        cout<<"No se puede crear la lista";return;}

    do{
        fflush(stdin);
        cout<<"\n\nCREAR LISTA\n\n";
        cout<<"Ingresa el nombre de la lista: ";gets(nombreLista);
        cout<<"Ingresa la descripcion de la lista: ";gets(descripcionLista);
        cout<<"Ingresa la categoria a la que pertenece la lista: ";gets(CategoriaLista);

        fwrite(nombreLista,1,strlen(nombreLista),fd);
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

if ((fd=fopen("rlv.txt","rt"))==NULL){
        return;}

    while(!feof(fd)){
        k = fgetc(fd);
        if (k==';'){
            cout<<" ";//continue; //(es para que no se vea el ;)
        }
        if (k=='|'){
            cout<<"\n";continue;//(es para que no se vea el |)
        }
        cout<<k;
    }
    fclose(fd);
}

void BuscarLista(){
    char k,nom[20],nombreLista[50],descripcionLista[500],CategoriaLista[50];
    int c=0,x=0,y=0,z=0;
    if((fd=fopen("rlv.txt","rt"))==NULL){
        return;}

    fflush(stdin);
    cout <<"\n\n\t\t\t---------------------BUSCAR LISTA---------------------";
    cout<<"\n\nIntroduce el nombre de la lista que deseas buscar: ";gets(nom);

    while(!feof(fd)){
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


/*
void ModificarListas(){

------------------ESTA PARTE DE MODIFICAR NO JALA AUN :( POR ESO LO COMENTE----------------

char k, nom[30],nombreLista[50],descripcionLista[500],CategoriaLista[50];
int c=0,x=0,y=0,z=0;

if ((fd1=fopen("rlv.txt","rt"))==NULL){return;}
if ((fd2=fopen("tmp.txt","wt"))==NULL){return;}

fflush(stdin);
cout<<"Introduce el nombre de la lista: ";gets(nom);
while(!feof(fd1)){

    k=fgetc(fd1);
    if(k==';'){c++;nombreLista[x]='0';descripcionLista[y]='\0';continue;}
    if(k=='|'){CategoriaLista[z]='\0';
    if (strcmp(nom,nombreLista)==0){
            cout<<"Introduzca la nueva categoria: ";gets(CategoriaLista);}
    fwrite(nombreLista,1,strlen(nombreLista),fd2);

   fwrite(Delimc,1,1,fd2);
   fwrite(descripcionLista,1,strlen(descripcionLista),fd2);
   fwrite(Delimc,1,1,fd2);
   fwrite(CategoriaLista,1,strlen(CategoriaLista),fd2);
   fwrite(DelimR,1,1,fd2);continue;
}
    if(c==0){nombreLista[x++]=k;}
    if(c==1){descripcionLista[y++]=k;}
    if(c==2){CategoriaLista[z++]=k;}
}
fclose(fd1);
fclose(fd2);

system("del rlv.txt");system("move tmp.txt rlv.txt");

}
*/

int main()
{
    int opc;

    do{

        cout<<"\n\n\t\t\t\t---------------------MENU----------------------\n\n";

        cout<<"\n1. Crear lista de peliculas";
        cout<<"\n2. Imprimir listas";
        cout<<"\n3. Buscar lista";
        //cout<<"\n4. Modificar Listas";
        cout<<"\n4. Salir";
        cout<<"\nOpcion: ";
        cin>>opc;
        cout<<"\n\n ";


        switch(opc){
            case 1: {CrearLista();break;}

            case 2: {
            cout<<"\n\t\t\t------------------------IMPRIMIR LISTAS---------------------\n\n";
                    ImprimirLista();break;}

            case 3: {BuscarLista();break;}

            //case 4:{ModificarListas();break;}
        }

    }while(opc!=4);

    system("pause");
    return 0;
}


