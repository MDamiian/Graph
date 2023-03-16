#ifndef GRAFO_HPP_INCLUDED
#define GRAFO_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <exception>

template <class T>
class Grafo {
    class Arista;
  private:
    class Vertice {
      private:
        T dato;
        Vertice* prevVer;
        Vertice* nextVer;
        Arista* adya;

      public:
        Vertice();
        Vertice(const T&);

        Vertice* getPrevVer() const;
        Vertice* getNextVer() const;
        T getDato() const;
        Arista* getArco() const;

        void setDato(const T&);
        void setPrevVer(Vertice*);
        void setNextVer(Vertice*);
        void setArco(Arista*);
      };

    class Arista {
      private:
        std::string peso;
        Arista* prevAri;
        Arista* nextAri;
        Vertice* destino;

      public:
        Arista();
        Arista(Vertice*, const std::string&);

        std::string getPeso() const;
        Arista* getPrevAri() const;
        Arista* getNextAri() const;
        Vertice* getDestino() const;

        void setPeso(const std::string&);
        void setPrevAri(Arista*);
        void setNextAri(Arista*);
        void setDestino(Vertice*);
      };

  public:

    class Exception : public std::exception {
      private:
        std::string msg;

      public:
        explicit Exception(const char* message) : msg(message) { }

        explicit Exception(const std::string& message) : msg(message) { }

        virtual ~Exception() throw () { }

        virtual const char* what() const throw () {
          return msg.c_str();
          }
      };

///\Grafo***
  private:
    Vertice* anchor;
    void deleteAllAri(Arista*);

  public:
    typedef Vertice* nodoVer;
    typedef Arista* nodoAri;

  public:
    Grafo();
    ~Grafo();

    bool isEmpty() const;

    void insertVer(const T&);
    void insertAri(Vertice*, Vertice*, const std::string&); ///origen, destino, peso

    Vertice* findData(const T&) const;
    T retrieve(Vertice*) const;

    void deleteVer(Vertice*);
    void deleteAri(Vertice*, Vertice*);
    void deleteAll();

    std::string toString() const;

    void writeToDisk();
    void readFromDisk();
  };

///\VERTICE*********************************************************
template <class T>
Grafo<T>::Vertice::Vertice() : dato(), prevVer(nullptr), nextVer(nullptr), adya(nullptr) { }

template <class T>
Grafo<T>::Vertice::Vertice(const T& d) : dato(d), prevVer(nullptr), nextVer(nullptr), adya(nullptr) { }

template <class T>
T Grafo<T>::Vertice::getDato() const {
  return dato;
  }

template <class T>
typename Grafo<T>::Vertice* Grafo<T>::Vertice::getPrevVer() const {
  return prevVer;
  }

template <class T>
typename Grafo<T>::Vertice* Grafo<T>::Vertice::getNextVer() const {
  return nextVer;
  }

template <class T>
typename Grafo<T>::Arista* Grafo<T>::Vertice::getArco() const {
  return adya;
  }

template <class T>
void Grafo<T>::Vertice::setDato(const T& d) {
  dato = d;
  }

template <class T>
void Grafo<T>::Vertice::setPrevVer(Vertice* v) {
  prevVer= v;
  }

template <class T>
void Grafo<T>::Vertice::setNextVer(Vertice* v) {
  nextVer = v;
  }

template <class T>
void Grafo<T>::Vertice::setArco(Arista* a) {
  adya = a;
  }

///\ARISTA********************************************************
template <class T>
Grafo<T>::Arista::Arista() : peso(), nextAri(nullptr), destino(nullptr) { }

template <class T>
Grafo<T>::Arista::Arista(Vertice* d, const std::string& p) : peso(p), nextAri(nullptr), destino(d) { }

template <class T>
std::string Grafo<T>::Arista::getPeso() const {
  return peso;
  }

template <class T>
typename Grafo<T>::Arista* Grafo<T>::Arista::getPrevAri() const {
  return prevAri;
  }

template <class T>
typename Grafo<T>::Arista* Grafo<T>::Arista::getNextAri() const {
  return nextAri;
  }

template <class T>
typename Grafo<T>::Vertice* Grafo<T>::Arista::getDestino() const {
  return destino;
  }

template <class T>
void Grafo<T>::Arista::setPeso(const std::string& p) {
  peso = p;
  }

template <class T>
void Grafo<T>::Arista::setPrevAri(Arista* a) {
  prevAri = a;
  }

template <class T>
void Grafo<T>::Arista::setNextAri(Arista* a) {
  nextAri = a;
  }

template <class T>
void Grafo<T>::Arista::setDestino(Vertice* v) {
  destino = v;
  }

///\GRAFO***************************************************************
template <class T>
Grafo<T>::Grafo() : anchor(nullptr) { }

template <class T>
Grafo<T>::~Grafo() {
  deleteAll();
  }

template <class T>
bool Grafo<T>::isEmpty() const {
  return anchor == nullptr;
  }

template <class T>
void Grafo<T>::insertVer(const T& data) {
  Vertice* aux(new Vertice(data));
  if(aux == nullptr) {
    throw Exception("Memoria no disponible, Grafo<T>::insertVer()");
    }

  aux->setNextVer(anchor);
  if(anchor != nullptr) {
    anchor->setPrevVer(aux);
    }
  anchor = aux;
  }

template <class T>
void Grafo<T>::insertAri(Vertice* origen, Vertice* destino, const std::string& peso) {
  Arista* aux(new Arista(destino, peso));
  if(aux == nullptr) {
    throw Exception("Memoria no disponible, Grafo<T>::insertAri()");
    }

  aux->setNextAri(origen->getArco());
  if(origen->getArco() != nullptr) {
    origen->getArco()->setPrevAri(aux);
    }
  origen->setArco(aux);
  }

template <class T>
typename Grafo<T>::Vertice* Grafo<T>::findData(const T& data) const {
  Vertice* aux(anchor);
  while(aux != nullptr and aux->getDato() != data) {
    aux = aux->getNextVer();
    }

  return aux;
  }

template <class T>
T Grafo<T>::retrieve(Vertice* v) const {
  if(v == nullptr) {
    throw Exception("La posicion es invalida, Grafo<T>::retrieve()");
    }

  return v->getDato();
  }

template <class T>
void Grafo<T>::deleteVer(Vertice* p) {
  if(p == nullptr) {
    throw Exception("La posicion es invalida, Grafo<T>::deleteVer()");
    }

  if(p->getPrevVer() != nullptr) {
    p->getPrevVer()->setNextVer(p->getNextVer());
    }

  if(p->getNextVer() != nullptr) {
    p->getNextVer()->setPrevVer(p->getPrevVer());
    }

  if(p == anchor) {
    anchor = anchor->getNextVer();
    }

  deleteAllAri(p->getArco());

  delete p;
  }

template <class T>
void Grafo<T>::deleteAri(Vertice* origen, Vertice* destino) {
  if(origen == nullptr or destino == nullptr) {
    throw Exception("La posicion es invalida, Grafo<T>::deleteAri()");
    }

  Arista* aux(origen->getArco());
  while(aux != nullptr and aux->getDestino() != destino) {
    aux = aux->getNextAri();
    }

  if(aux == nullptr) {
    std::cerr << "Error: No se encontro la arista" << std::endl;
    return;
    }

  if(aux->getPrevAri() != nullptr) {
    aux->getPrevAri()->setNextAri(aux->getNextAri());
    }

  if(aux->getNextAri() != nullptr) {
    aux->getNextAri()->setPrevAri(aux->getPrevAri());
    }

  if(aux == origen->getArco()) {
    aux = aux->getNextAri();
    }

  delete aux;
  }

template <class T>
void Grafo<T>::deleteAllAri(Arista* arco) {
  Arista* aux;

  while(arco != nullptr) {
    aux = arco;
    arco = arco->getNextAri();

    delete aux;
    }
  }

template <class T>
void Grafo<T>::deleteAll() {
  Vertice* aux;
  while(anchor != nullptr) {
    aux = anchor;
    deleteAllAri(anchor->getArco());
    anchor = anchor->getNextVer();

    delete aux;
    }
  }

template <class T>
std::string Grafo<T>::toString() const {
  std::string result;
  Vertice* aux(anchor);
  Arista* tmp;

  while(aux != nullptr) {
    tmp = aux->getArco();

    result+= aux->getDato().toString();
    while(tmp != nullptr) {
      result+= "  ---";
      result+= tmp->getPeso();
      result+= "-->  ";
      result+= tmp->getDestino()->getDato().toString();
      tmp = tmp->getNextAri();
      if(tmp != nullptr) {
        result+= "\n";
        result+= aux->getDato().toString();
        }
      }
    result+= "\n";
    aux = aux->getNextVer();
    }
  return result;
  }

template <class T>
void Grafo<T>::writeToDisk() {
  std::ofstream myFileV("file01.txt", std::ios_base::trunc);
  std::ofstream myFileA("file02.txt", std::ios_base::trunc);

  if(!myFileV) {
    throw Exception("No se pudo abrir file01.txt para escritura, Grafo<T>::writeToDisk()");
    }

  if(!myFileA) {
    throw Exception("No se pudo abrir file02.txt para escritura, Grafo<T>::writeToDisk()");
    }

  Vertice* aux(anchor);
  Arista* tmp;

  while(aux != nullptr) {
    myFileV << aux->getDato();

    tmp = aux->getArco();
    while(tmp) {
      myFileA << aux->getDato()
              << tmp->getDestino()->getDato()
              << tmp->getPeso()
              << '$';
      tmp = tmp->getNextAri();
      }

    aux = aux->getNextVer();
    }

  myFileV.close();
  myFileA.close();
  }

template <class T>
void Grafo<T>::readFromDisk() {
  std::ifstream myFileV("file01.txt", std::ios::in);
  std::ifstream myFileA("file02.txt", std::ios::in);

  if(!myFileV) {
    throw Exception("No se pudo abrir file01.txt para lectura, Grafo<T>::readFromDisk()");
    }

  if(!myFileA) {
    throw Exception("No se pudo abrir file01.txt para lectura, Grafo<T>::readFromDisk()");
    }

  T myObjet;
  T myObjet2;
  std::string myString;
  Vertice* a;
  Vertice* b;
  deleteAll();

  while((myFileV >> myObjet)) {
    insertVer(myObjet);
    }

  while((myFileA >> myObjet)) {
    myFileA >> myObjet2;
    std::getline(myFileA, myString, '$');

    a = findData(myObjet);
    b = findData(myObjet2);
    insertAri(a, b, myString);
    }

  myFileV.close();
  myFileA.close();
  }

#endif // GRAFO_HPP_INCLUDED
