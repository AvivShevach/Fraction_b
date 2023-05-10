namespace ariel{};
#include <iostream>
#include <sstream>
#include <limits>
#include <stdexcept>
class Fraction {
  public:
    int num1,num2;
    Fraction();
    Fraction(int, int);
    Fraction(float);
    
    int getNumerator() const {return num1;};
    int getDenominator() const {return num2;};
    Fraction operator+ (const Fraction&) const;
    Fraction operator+ (float);
   
    Fraction operator- (const Fraction&) const;
    Fraction operator- (float); 

    Fraction operator/ (const Fraction&) const;
    Fraction operator/ (float);

    Fraction operator* (const Fraction&) const;
    Fraction operator* (float);

    Fraction operator++ (int);
    Fraction operator++ ();
    Fraction operator-- (int);
    Fraction operator-- ();

    bool operator< (float);
    bool operator< (const Fraction&) const;

    bool operator> (float);
    bool operator> (const Fraction&) const;

    bool operator== (float);
    bool operator== (const Fraction&) const;

    bool operator>= (float);
    bool operator>= (const Fraction&) const;
    
    bool operator<= (float);
    bool operator<= (const Fraction&) const;
    int gcd(int, int) const;

    friend std::ostream& operator<< (std::ostream&, const Fraction&);
    friend std::istream& operator>> (std::istream&, Fraction&);
};

Fraction floatToFraction(float);
Fraction  operator* (float, Fraction);
Fraction  operator/ (float, Fraction);
Fraction operator+ (float, Fraction);
Fraction  operator- (float, Fraction);

bool operator== (float, Fraction);
bool operator< (float, Fraction);
bool operator> (float, Fraction);
bool operator>= (float, Fraction);
bool operator<= (float, Fraction);
 

