#include <iostream>
#include <cassert>
#include <cmath>

#define EPSILON 1e-7

using namespace std;


class rational_t
{
  int num_, den_;

  public:

    rational_t(void); // Constructor por defecto
    rational_t(const int n, const int d);      // Constructor parametrizado


    ~rational_t(){}                           // Destructor

    int get_num() const                       // Getters
    { return num_; }

    int get_den() const
    { return den_; }

    void set_num(const int n)                 // Setters
    { num_ = n; }

    void set_den(const int d)
    { assert(d != 0), den_ = d; }

    double value(void) const;

    bool operator == (const rational_t& r) const;
    bool operator < (const rational_t& r) const;
    bool operator > (const rational_t& r) const;
    rational_t operator +(const rational_t& r);
    rational_t operator -(const rational_t& r);
    rational_t operator *(const rational_t& r);
    rational_t operator /(const rational_t& r);

    void Fichero_E_S(char* fich1, char* fich2, const rational_t& r);

    bool equal(const rational_t& r, const double precision = EPSILON) const;
    bool greater(const rational_t& r, const double precision = EPSILON) const;
    bool less(const rational_t& r, const double precision = EPSILON) const;


    rational_t add(const rational_t&);
    rational_t substract(const rational_t&);
    rational_t multiply(const rational_t&);
    rational_t divide(const rational_t&);



    void write(ostream& os = cout) const;
    void writ(ostream& os = cout) const;
    void read(istream& is = cin);

};


