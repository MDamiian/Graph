#include "estado.hpp"

using namespace std;

Estado::Estado() {

  }

string Estado::getEstado() const {
  return estado;
  }

string Estado::getCapital() const {
  return capital;
  }

string Estado::getGobernador() const {
  return gobernador;
  }

string Estado::toString() const {
  string result;

  result+= estado;
  result.resize(10, ' ');
  result+= "| ";
  result+= capital;
  result.resize(25, ' ');
  result+= "| ";
  result+= gobernador;

  return result;
  }

void Estado::setEstado(const std::string& e) {
  estado = e;
  }

void Estado::setCapital(const std::string& c) {
  capital = c;
  }

void Estado::setGobernador(const std::string& g) {
  gobernador = g;
  }

bool Estado::operator == (const Estado& c) const {
  return estado == c.estado;
  }

bool Estado::operator != (const Estado& c) const {
  return !(*this == c);
  }

bool Estado::operator > (const Estado& c) const {
  return !(*this <= c);
  }

bool Estado::operator >= (const Estado& c) const {
  return !(*this < c);
  }

bool Estado::operator < (const Estado& c) const {
  return estado < c.estado;
  }

bool Estado::operator <= (const Estado& c) const {
  return *this < c or *this == c;
  }

std::ostream& operator << (std::ostream& os, const Estado& e) {
  os << e.estado << '|'
     << e.capital << '|'
     << e.gobernador << '*' << endl;
  return os;
  }

std::istream& operator >> (std::istream& is, Estado& e) {
  getline(is, e.estado, '|');
  getline(is, e.capital, '|');
  getline(is, e.gobernador, '*');
  return is;
  }
