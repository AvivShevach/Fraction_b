#include "Fraction.hpp"

const int max_limit = std::numeric_limits<int>::max();
const int min_limit = std::numeric_limits<int>::min();

Fraction::Fraction() : num1(0), num2(1) {}
Fraction::Fraction(int number1, int number2) // -10/3
{
    if(number2 == 0)
        throw std::invalid_argument("Denominator cannot be zero");
    int tmp = gcd(number1,number2);
    num1 = number1/tmp;
    num2 = number2/tmp;
    if((num2 <0) && (num1 >= 0))
    {
        num1 *=(-1);
        num2 *=(-1);
    }

}

Fraction::Fraction(float d)
{
    num1 = floatToFraction(d).num1;
    num2 = floatToFraction(d).num2;
}


void check_overflow(long num1 , long num2){
    if(num1 > max_limit || num2 > max_limit){
        throw std::overflow_error("Number passes the limit");
    }
    if(num1 < min_limit || num2 < min_limit){
        throw std::overflow_error("Number passes the limit");
    }
} 
int Fraction::gcd(int a, int b) const {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

Fraction floatToFraction(float n) {
    int i = 1000;
    n = 1000*n;
    Fraction tmp(n,i);
    return tmp;
}
Fraction Fraction::operator+ (const Fraction& frac) const
{
     

    long tmp1 = static_cast<long>(num1) * frac.num2 + num2 * frac.num1;
    long tmp2 = static_cast<long>(num2) * frac.num2;
    check_overflow(tmp1 , tmp2);
    int tmp = gcd (tmp1, tmp2);
    Fraction f2(tmp1/tmp, tmp2/tmp );

    return f2;
}

Fraction operator+ (float d,Fraction f)
{
    return f + d;
}

Fraction Fraction::operator+ (float n)
{
    return *this + floatToFraction(n);
}

Fraction Fraction::operator- (const Fraction& frac) const
{
    long tmp1 = static_cast<long>(num1) * frac.num2 - num2 * frac.num1;
    long tmp2 = static_cast<long>(num2) * frac.num2;
    check_overflow(tmp1 , tmp2);
    Fraction tmp(tmp1,tmp2);
    return tmp;
}

Fraction operator- (float d, const Fraction f)
{
    return floatToFraction(d) - f;
     
}

Fraction Fraction::operator- (float d)
{
    return *this - floatToFraction(d);
}

Fraction Fraction::operator* (const Fraction& frac) const
{

   long tmp1 = static_cast<long>(num1)*frac.num1;
   long tmp2 = static_cast<long>(num2)*frac.num2;
   check_overflow(tmp1 , tmp2);
   Fraction tmp(num1*frac.num1 , num2*frac.num2);
   return tmp;
}
Fraction operator* (float d,Fraction f)
{
    return f * d;
     
}
Fraction Fraction::operator* (float n)
{
    return *this * floatToFraction(n);
}

Fraction Fraction::operator/ (const Fraction& frac) const
{
    if(frac.num1 == 0)
        throw std::runtime_error("Denominator cannot be zero");
    Fraction tmp(frac.num2,frac.num1);
    
    if (num1 > 0 && frac.num1 > max_limit - num1)
        {
            throw std::overflow_error("Number passes the limit");
        }
        if (num2 > 0 && num2 - 1 > max_limit - frac.num2)
        {
            throw std::overflow_error("Number passes the limit");
        }
    return *this * tmp;
}

Fraction operator/ (float d,Fraction f)
{
    return floatToFraction(d)/f;
}

Fraction Fraction::operator/ (float d)
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
    return tmp;
}

Fraction Fraction::operator-- ()
{
    num1 = (*this - 1).num1;

    num2 = (*this).num2;
    return *this;
}


  std::ostream &operator<<(std::ostream &output, const Fraction &frac)
    {

        if (frac.num2 < 0)
        { 
            output << -1 * frac.num1 << "/" << -1 * frac.num2;
        }
        else
        {
            output << frac.num1 << "/" << frac.num2;
        }
        return output;
    }
    std::istream &operator>>(std::istream &input, Fraction &frac)
    {
        if (!(input >> frac.num1 >> frac.num2))
        {
            throw std::runtime_error("Invalid input");
        }
        else if (frac.num2 == 0)
        {
            throw std::runtime_error("invalid input");
        }

        return input;
    }




bool Fraction::operator==(const Fraction& f) const {

    return ((num1 == f.num1) && (num2 == f.num2)) || ((num1 == 0) && (f.num1==0)) || ((num1 == -f.num1) && (num2 == -f.num2)) ;
}

bool operator== (float d, Fraction f)
{
    return floatToFraction(d) == f;
}

bool Fraction::operator== (float d)
{
    return *this == floatToFraction(d);
}

bool Fraction::operator>= (const Fraction& f) const
{
    if((*this - f).num1 < 0 || (*this - f).num2 < 0)
        return false;
    return true;
}
bool operator>= (float d, Fraction f)
{
    return f <= d;
}

bool Fraction::operator>= (float d)
{
    return *this >= floatToFraction(d);
}

bool Fraction::operator<= (const Fraction& f) const
{
    return f >= *this;
}
bool operator<= (float d, Fraction f)
{
    return f >= d;
}

bool Fraction::operator<= (float d)
{
    return floatToFraction(d) >= *this ;
}

bool Fraction::operator> (const Fraction& f) const
{
    if((*this - f).num1 <= 0 || (*this - f).num2 <= 0)
        return false;
    return true;
}
bool operator> (float d, Fraction f)
{
    return f < d;
}


bool Fraction::operator> (float d)
{
    return *this > floatToFraction(d);
}

bool Fraction::operator< (const Fraction& f) const
{
    return f > *this;
}
bool operator< (float d, Fraction f)
{
    return f > d;
}

bool Fraction::operator< (float d)
{
    return floatToFraction(d) > *this ;
}




