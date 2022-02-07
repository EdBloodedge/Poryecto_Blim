#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Nodo{

friend class Lista;

protected:

  Nodo* pSig;
  string nombre, descripcion, categoria;

  virtual void Cargar();
  virtual void Guardar();

  void Set(string nombre, string descripcion, string categoria);

  void Agregar(string nombre, string descripcion, string categoria);
  void Imprimir(int Modo);
  void Buscar(string nombre);
  void Modificar(string nombre);
  void Eliminar(string nombre);

};

class Pelicula : public Nodo{

  friend class Lista;

protected:

  virtual void Cargar();
  virtual void Guardar();

};

class Serie : public Nodo{

  friend class Lista;

protected:

  virtual void Cargar();
  virtual void Guardar();

};

class Lista{

private:
  Nodo Inicio;

public:
  void Cargar();
  void Guardar();

  bool IsEmpty();

  void Agregar();
  void Imprimir();
  void Buscar(string nombre);
  void Modificar(string nombre);
  void Eliminar(string nombre);

  Lista();
  ~Lista();

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){

  int opc;
  int PelSer;

  string nombre;
  bool salir;

  Lista Peliculas;
  Lista Series;
  Lista* lista;

    do{

      system("cls");
      cout<<"\n\n\t\t\t\t---------------------MENU----------------------\n\n";
      cout << "\n1. Peliculas";
      cout << "\n2. Series";
      cout << "\n3. Salir";

      cout<<"\nOpcion: ";
      fflush(stdin);
      cin>>PelSer;
      cout<<"\n\n ";

      opc = 0;

      switch (PelSer) {
        case 1:
          lista = &Peliculas;
          break;

        case 2:
          lista = &Series;
          break;

        case 3:
          salir = true;
          opc = 6;
          break;

        default:
          "\n\nPor favor elija una opci\242n v\240lida.\n";
          system("pause");
      }

      while(opc != 6){

        system("cls");

          cout<<"\n\n\t\t\t\t---------------------MENU----------------------\n\n";

          cout<<"\n1. Agregar";
          cout<<"\n2. Imprimir";
          cout<<"\n3. Buscar";
          cout<<"\n4. Modificar";
          cout<<"\n5. Eliminar";
          cout<<"\n6. Regresar";
          cout<<"\nOpcion: ";
          fflush(stdin);
          cin>>opc;
          cout<<"\n\n ";


          switch(opc){
              case 1:
                  cout<<"\n\t\t\t------------------------AGREGAR-----------------------\n\n";
                  lista->Agregar();
                  break;

              case 2:
                  cout<<"\n\t\t\t------------------------IMPRIMIR-----------------------\n\n";
                  lista->Imprimir();
                  break;

              case 3:
                  cout<<"\n\t\t\t------------------------BUSCAR-----------------------\n\n";
                  cout << "Ingrese el nombre: ";
                  fflush(stdin);
                  getline(cin,nombre);
                  lista->Buscar(nombre);
                  break;

              case 4:
                  cout<<"\n\t\t\t------------------------MODIFICAR-----------------------\n\n";
                  cout << "Ingrese el nombre: ";
                  fflush(stdin);
                  getline(cin,nombre);
                  lista->Modificar(nombre);
                  break;

              case 5:
                  cout<<"\n\t\t\t------------------------ELIMINAR-----------------------\n\n";
                  cout << "Ingrese el nombre: ";
                  fflush(stdin);
                  getline(cin,nombre);
                  lista->Eliminar(nombre);
                  break;

              case 6:
                break;

              default:
                "\n\nPor favor elija una opci\242n v\240lida.\n";
                system("pause");
          }

          system("pause");

      }

    }while(!salir);

    system("pause");
    return 0;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Nodo

void Nodo::Cargar(){
  return;
}
void Nodo::Guardar(){
  return;
}

void Nodo::Set(string nombre, string descripcion, string categoria){

  this->pSig = NULL;

  this->nombre = nombre;
  this->descripcion = descripcion;
  this->categoria = categoria;

  return;

}

void Nodo::Agregar(string nombre, string descripcion, string categoria){

  if(this->pSig == NULL){

    this->pSig = new Nodo;
    this->pSig->Set(nombre, descripcion, categoria);

  }else{
    this->pSig->Agregar(nombre, descripcion, categoria);
  }

  return;

}
void Nodo::Imprimir(int Modo){

  cout << nombre << endl << categoria << endl << descripcion << endl << "----------------" << endl;

  if(this->pSig != NULL && Modo == 1)
    this->pSig->Imprimir(1);

  return;

}
void Nodo::Buscar(string nombre){

  if(this->pSig == NULL){
    cout << "No se ha encontrado el nombre especificado";
    return;
  }

  if(this->pSig->nombre == nombre)
    this->pSig->Imprimir(0);
  else
    this->pSig->Buscar(nombre);

}
void Nodo::Modificar(string nombre){

  if(this->pSig == NULL){
    cout << "No se ha encontrado el nombre especificado";
    return;
  }

  if(this->pSig->nombre == nombre){

    string nNombre, nDescripcion, nCategoria;

    cout << "\nIngrese los datos actualizados:\nNombre: ";
    fflush(stdin);
    getline(cin,nNombre);
    cout << "\nDescripcion: ";
    fflush(stdin);
    getline(cin,nDescripcion);
    cout << "\nCategoria: ";
    fflush(stdin);
    getline(cin,nCategoria);

    this->pSig->Set(nNombre, nDescripcion, nCategoria);

    cout << "\n\nDatos actualizados correctamente.\n";

  }else{
    this->pSig->Modificar(nombre);
  }

  return;

}
void Nodo::Eliminar(string nombre){

  if(this->pSig == NULL){
    cout << "No se ha encontrado el nombre especificado";
    return;
  }

  if(this->pSig->nombre == nombre){

    Nodo* aux = this->pSig;

    this->pSig = this->pSig->pSig;
    delete aux;

  }else{
    this->pSig->Eliminar(nombre);
  }

  return;

}

//Pelicula

//Serie

//Lista

void Lista::Cargar(){
  return;
}
void Lista::Guardar(){
  return;
}

bool Lista::IsEmpty(){

  if(Inicio.pSig == NULL)
    return true;

  return false;
}

void Lista::Agregar(){

  string nombre, descripcion, categoria;

  cout << "Ingrese los datos.\nNombre: ";
  fflush(stdin);
  getline(cin,nombre);
  cout << "\nDescripcion: ";
  fflush(stdin);
  getline(cin,descripcion);
  cout << "\nCategoria: ";
  fflush(stdin);
  getline(cin,categoria);

  Inicio.Agregar(nombre, descripcion, categoria);

  return;
}
void Lista::Imprimir(){

  if(this->IsEmpty()){
    cout << "No existen elementos.";
    return;
  }

  Inicio.pSig->Imprimir(1);

}
void Lista::Buscar(string nombre){

  if(this->IsEmpty()){
    cout << "No existen elementos.";
    return;
  }

  Inicio.Buscar(nombre);

}
void Lista::Modificar(string nombre){

  if(this->IsEmpty()){
    cout << "No existen elementos.";
    return;
  }

  Inicio.Modificar(nombre);

}
void Lista::Eliminar(string nombre){

  if(this->IsEmpty()){
    cout << "No existen elementos.";
    return;
  }

  Inicio.Eliminar(nombre);

}

Lista::Lista(){

  Inicio.pSig = NULL;

}
Lista::~Lista(){

  Inicio.Guardar();

}
