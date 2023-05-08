#include "Fraction.hpp"

Fraction::Fraction(int n1, int n2) // -10/3
{
    if(n2 == 0)
        throw std::invalid_argument("Denominator cannot be zero");
    int tmp = gcd(n1,n2);
    if(n2 < 0)
    {
        n2*=-1;
        n1*=-1;
    }
    num1 = n1/tmp;
    num2 = n2/tmp;

}

// Fraction::Fraction (Fraction f)
// {
//    num1 = f.num1;
//    num2 = f.num2;
// }
Fraction::Fraction(float d)
{
    num1 = floatToFraction(d).num1;
    num2 = floatToFraction(d).num2;
}

int Fraction::gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

Fraction floatToFraction(float n) {
     int i = 1;
    while (n != (int)n && i!= 1000)
    {
        i *= 10;
        n *= 10;
    }
    Fraction tmp(n,i);
    return tmp;
}
Fraction const Fraction::operator+ (Fraction f)
{
    int tmp1 = num1 * f.num2 + num2 * f.num1;
    int tmp2 = num2 * f.num2;
    int tmp = gcd (tmp1, tmp2);

    Fraction f2(tmp1/tmp, tmp2/tmp );
    return f2;
}

Fraction const operator+ (float d,Fraction f)
{
    return f + d;
}

Fraction const Fraction::operator+ (float n)
{
    return *this + floatToFraction(n);
}

Fraction const Fraction::operator- (Fraction f)
{
    Fraction tmp(-f.num1,f.num2);
    return *this + tmp;
}

Fraction const operator- (float d,Fraction f)
{
    return floatToFraction(d) - f;
     
}

Fraction const Fraction::operator- (float n)
{
    return *this + -1*n;
}

Fraction const Fraction::operator* (Fraction f)
{
   Fraction tmp(num1*f.num1 , num2*f.num2);
   return tmp;
}
Fraction const operator* (float d,Fraction f)
{
    return f * d;
     
}
Fraction const Fraction::operator* (float n)
{
    return *this * floatToFraction(n);
}

Fraction const Fraction::operator/ (Fraction f)
{
    Fraction tmp(f.num2,f.num1);
    return *this * tmp;
}

Fraction const operator/ (float d,Fraction f)
{
    Fraction a((f/d).num2, (f/d).num1);
    return a; 

}

Fraction const Fraction::operator/ (float d)
{
    return *this / floatToFraction(d);
}

Fraction Fraction::operator++ (int n)
{
    int n1 = (*this).num1;
    int n2 = (*this).num2;
    Fraction tmp(n1,n2);
    num1 = (*this + 1).num1;
    num2 = (*this).num2;
  //  printf(" num1 = %d, num2 = %d", num1, num2);
    return tmp;
}

Fraction Fraction::operator++ ()
{
    
    num1 = (*this + 1).num1;
    num2 = (*this).num2;
    return *this;
}

Fraction Fraction::operator-- (int n)
{
    int n1 = (*this).num1;
    int n2 = (*this).num2;
    Fraction tmp(n1,n2);
    num1 = (*this - 1).num1;
    num2 = (*this).num2;
  //  printf(" num1 = %d, num2 = %d", num1, num2);
    return tmp;
}

Fraction Fraction::operator-- ()
{
    //Fraction tmp()
    num1 = (*this - 1).num1;
 //   printf(" num1 = %d, num2 = %d", num1, num2);
    num2 = (*this).num2;
  //  printf(" num1 = %d, num2 = %d", num1, num2);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << " " << f.num1 << "/" << f.num2;
    return os;
}

// std::ostringstream& operator<<(std::ostringstream& os, const Fraction& f) {
//     os << f.num1 << "/" << f.num2;
//     return os;
// }

std::istream& operator>>(std::istream& input, Fraction& c) {
    int n, d;
    char sep;
    input >> n >> sep >> d;
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
   //if(sep != " ")
    c = Fraction(n, d);
    return input;
}





void const Fraction::operator= (Fraction f)
{
    num1 = f.num1;
    num2 = f.num2;

}
bool const Fraction::operator== (Fraction f)
{
    if((*this - f).num1 == 0)
        return true;
    return false;
}

bool const operator== (float d, Fraction f)
{
    return f == d;
}

bool const Fraction::operator== (float d)
{
    return *this == floatToFraction(d);
}

bool const Fraction::operator>= (Fraction f)
{
    if((*this - f).num1 < 0 || (*this - f).num2 < 0)
        return false;
    return true;
}
bool const operator>= (float d, Fraction f)
{
    return f <= d;
}

bool const Fraction::operator>= (float d)
{
    return *this >= floatToFraction(d);
}

bool const Fraction::operator<= (Fraction f)
{
    return f >= *this;
}
bool const operator<= (float d, Fraction f)
{
    return f >= d;
}

bool const Fraction::operator<= (float d)
{
    return floatToFraction(d) >= *this ;
}

bool const Fraction::operator> (Fraction f)
{
    if((*this - f).num1 <= 0 || (*this - f).num2 <= 0)
        return false;
    return true;
}
bool const operator> (float d, Fraction f)
{
    return f < d;
}


bool const Fraction::operator> (float d)
{
    return *this > floatToFraction(d);
}

bool const Fraction::operator< (Fraction f)
{
    return f > *this;
}
bool const operator< (float d, Fraction f)
{
    return f > d;
}

bool const Fraction::operator< (float d)
{
    return floatToFraction(d) > *this ;
}




