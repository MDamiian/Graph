#include <iostream>
#include "menu.hpp"

using namespace std;
void Menu::mainMenu(Grafo<Estado>& myGrafo) {
  char myChar;
  string myString;
  Estado myEstado;
  Grafo<Estado>::nodoVer vertice;
  Grafo<Estado>::nodoVer verticeAux;


  do {
    system("cls");
    cout << "[a] Insertar vertice" << endl
         << "[b] Insertar arista" << endl
         << "[c] Buscar vertice" << endl
         << "[d] Eliminar vertice" << endl
         << "[e] Eliminar arista" << endl
         << "[f] Mostrar grafo" << endl
         << "[g] Borrar grafo" <<  endl
         << "[h] Guardar" << endl
         << "[i] Cargar" << endl
         << "[j] Salir" << endl
         << "Selecciona una opcion: ";
    cin >> myChar;
    cin.ignore();

    system("cls");
    switch(myChar) {
      case 'a':
        cout << "Nombre del estado: ";
        getline(cin, myString);
        myEstado.setEstado(myString);

        cout << "Capital: ";
        getline(cin, myString);
        myEstado.setCapital(myString);

        cout << "Gobernador: ";
        getline(cin, myString);
        myEstado.setGobernador(myString);

        myGrafo.insertVer(myEstado);
        break;

      case 'b':
        cout << "Vertice origen(Estado): ";
        getline(cin, myString);
        myEstado.setEstado(myString);
        vertice = myGrafo.findData(myEstado);

        cout << "Vertice destino(Estado): ";
        getline(cin, myString);
        myEstado.setEstado(myString);
        verticeAux = myGrafo.findData(myEstado);

        cout << "Peso: ";
        getline(cin, myString);

        if(!vertice or !verticeAux) {
          cout << "Vuelve a intentarolo" << endl;
          }
        else {
          myGrafo.insertAri(vertice, verticeAux, myString);
          }
        break;

      case 'c':
        cout << "Nombre del estado a buscar: ";
        getline(cin, myString);
        myEstado.setEstado(myString);

        vertice = myGrafo.findData(myEstado);
        cout << "El estado " << myString << " ";
        if(vertice == nullptr) {
          cout << "NO SE ENCUENTRA EN EL GRAFO" << endl << endl;
          }

        else {
          cout << "se encuentra en el grafo" << endl
               << "Registro encontrado: " << myGrafo.retrieve(vertice).toString()
               << endl << endl;
          }
        break;

      case 'd':
        cout << "Nombre del estado a eliminar: ";
        getline(cin, myString);
        myEstado.setEstado(myString);
        vertice = myGrafo.findData(myEstado);

        myGrafo.deleteVer(vertice);
        break;

      case 'e':
        cout << "Vertice origen(Estado): ";
        getline(cin, myString);
        myEstado.setEstado(myString);
        vertice = myGrafo.findData(myEstado);

        cout << "Vertice destino(Estado): ";
        getline(cin, myString);
        myEstado.setEstado(myString);
        verticeAux = myGrafo.findData(myEstado);

        myGrafo.deleteAri(vertice, verticeAux);
        break;

      case 'f':
        cout << myGrafo.toString() << endl << endl;
        break;

      case 'g':
        myGrafo.deleteAll();
        break;

      case 'h':
        myGrafo.writeToDisk();
        break;

      case 'i':
        myGrafo.readFromDisk();
        break;
      }
    system("pause");
    }
  while(myChar != 'j');
  }
