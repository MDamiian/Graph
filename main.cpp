#include "estado.hpp"
#include "grafo.hpp"
#include "menu.hpp"

int main() {
  Menu myMenu;
  Grafo<Estado> myGrafo;
  myMenu.mainMenu(myGrafo);

  return 0;
  }
