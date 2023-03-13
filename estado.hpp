#ifndef CIUDADES_HPP_INCLUDED
#define CIUDADES_HPP_INCLUDED

#include <string>
#include <iostream>

class Estado {
  private:
    std::string estado;
    std::string capital;
    std::string gobernador;

  public:
    Estado();

    std::string getEstado() const;
    std::string getCapital() const;
    std::string getGobernador() const;

    std::string toString() const;

    void setEstado(const std::string&);
    void setCapital(const std::string&);
    void setGobernador(const std::string&);

    bool operator == (const Estado&) const;
    bool operator != (const Estado&) const;
    bool operator > (const Estado&) const;
    bool operator >= (const Estado&) const;
    bool operator < (const Estado&) const;
    bool operator <= (const Estado&) const;

    friend std::ostream& operator << (std::ostream&, const Estado&);
    friend std::istream& operator >> (std::istream&, Estado&);
  };

#endif // CIUDADES_HPP_INCLUDED
