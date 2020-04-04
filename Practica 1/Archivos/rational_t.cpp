#include "rational_t.hpp"
#define precition 1e-6

rational_t::rational_t(void)  // Constructor
{
  num_ = 0, den_ = 1;
}

rational_t::rational_t(const int n, const int d)  // Constructor
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// Metodo Ficheros

// Resultado de la Fraccion

double rational_t::value() const { return double(get_num()) / get_den(); }

// Comparadores de la Fraccion

bool rational_t::equal(const rational_t& r, const double precision) const {
  return (fabs(value() - r.value()) < precision);
}

bool rational_t::greater(const rational_t& r, const double precision) const {
  return (value() - r.value() > precision);
}

bool rational_t::less(const rational_t& r, const double precision) const {
  int precision2 = precision * -1;
  return (value() - r.value() < precision2 && r.value() - value() > precision);
}

// Sobrecarga de operadores

bool rational_t::operator == (const rational_t& r) const {
	return(fabs(value()-r.value())< precition);
}

bool rational_t:: operator < (const rational_t& r) const {
	return((r.value()-value())>precition);
}

bool rational_t:: operator > (const rational_t& r) const {
	return((value()-r.value())>precition);
}

rational_t rational_t::operator +(const rational_t& r) {
	rational_t b;
	b.num_=(get_num()*r.get_den()+r.get_num()*get_den());
	b.den_=(get_den()*r.get_den());
	return b;
}

rational_t rational_t::operator -(const rational_t& r) {
	rational_t b;
	b.num_=(get_num()*r.get_den()-r.get_num()*get_den());
	b.den_=(get_den()*r.get_den());
	return b;
}

rational_t rational_t::operator *(const rational_t& r) {
	rational_t b;
	b.num_=(get_num()*r.get_num());
	b.den_=(get_den()*r.get_den());
	return b;
}

rational_t rational_t::operator /(const rational_t& r) {
	rational_t b;
	b.num_=(get_num()*r.get_den());
	b.den_=(get_den()*r.get_num());
	return b;
}

// Operaciones con Fraccion

rational_t rational_t::add(const rational_t& r) {
  rational_t add;
  add.set_num(r.get_den() * get_num() + r.get_num() * get_den());
  add.set_den(get_den() * r.get_den());
  return add;
}

rational_t rational_t::substract(const rational_t& r) {
  rational_t sub;
  sub.set_num(r.get_den() * get_num() - r.get_num() * get_den());
  sub.set_den(get_den() * r.get_den());
  return sub;
}

rational_t rational_t::multiply(const rational_t& r) {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

rational_t rational_t::divide(const rational_t& r) {
  rational_t div;
  div.set_num(get_num() * r.get_den());
  div.set_den(get_den() * r.get_num());
  return div;
}

// Writes y Reads

void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << " = " << value() << endl;
}

void rational_t::writ(ostream& os) const {
  os << get_num() << "/" << get_den();
}

void rational_t::read(istream& is) {
  cout << "Numerador: ";
  is >> num_;
  cout << "Denominador: ";
  is >> den_;
  assert(den_ != 0);
}
