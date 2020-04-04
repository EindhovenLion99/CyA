#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>

using namespace std;

class complex_t
{
   int real_, imag_;
   char oper_;

   public:

     complex_t(void);
     complex_t(const int n, const int d, const char x);

     ~complex_t(){}

     int get_real() const
     { return real_; }

     int get_imag() const
     { return imag_; }

     char get_oper() const
     { return oper_; }

     void set_real(const int n)
     { real_ = n; }

     void set_imag(const int d)
     { imag_ = d; }

     void set_oper(const char x)
     { oper_ = x; }

     complex_t add(const complex_t&);
     complex_t operator +(const complex_t& r);

     void write(ostream& os = cout) const;
};
