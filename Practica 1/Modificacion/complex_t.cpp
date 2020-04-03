#include "complex_t.hpp"

complex_t::complex_t(void)
{
  real_ = 0, imag_ = 0;
}

complex_t::complex_t(const int n, const int d, const char x)
{
  real_ = n, imag_ = d, oper_ = x;
}

void complex_t::write(ostream& os) const
{
  os << get_real() << get_oper() << get_imag() << "i";
}

complex_t complex_t::add(const complex_t& r)
{
   complex_t add;
   add.set_real(get_real() + r.get_real());
   if(r.get_oper() == '+')
   {
      add.set_imag(get_imag() + r.get_imag());
   }else
   {
      add.set_imag(get_imag() - r.get_imag());
   }

   if(add.get_imag() < 0)
   {
      add.set_oper('-');
   }else
   {
      add.set_oper('+');
   }

   return add;
}
