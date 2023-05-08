namespace ariel{};
#include <iostream>
#include <sstream>

class Fraction {
  public:
    int num1,num2;
    Fraction();
    Fraction(int n1, int n2);
    Fraction(float);
    int getNumerator() {return num1;};
    int getDenominator() {return num2;};
    Fraction const operator+ (Fraction);
    Fraction const operator+ (float);
   

    Fraction const operator- (Fraction);
    Fraction const operator- (float); 

    Fraction const operator/ (Fraction);
    Fraction const operator/ (float);

    Fraction const operator* (Fraction);
    Fraction const operator* (float);
//    double operator* (Fraction);
//    Fraction operator*(const double& left, const Fraction& right)


    Fraction operator++ (int);
    Fraction operator++ ();
    Fraction operator-- (int);
    Fraction operator-- ();

    bool const operator< (float);
    bool const operator< (Fraction);

    bool const operator> (float);
    bool const operator> (Fraction);

    void const operator= (Fraction);
    bool const operator== (float);
    bool const operator== (Fraction);

    bool const operator>= (float);
    bool const operator>= (Fraction);
    
    bool const operator<= (float);
    bool const operator<= (Fraction);
    int gcd(int a, int b);

  //  friend std::ostringstream& operator<<(std::ostringstream& os, const Fraction& f);
    friend std::ostream& operator<< (std::ostream& output, const Fraction& c);
    friend std::istream& operator>> (std::istream& input , Fraction& c);
};

Fraction floatToFraction(float);
  Fraction const operator* (float, Fraction);
 Fraction const operator/ (float, Fraction);
 Fraction const operator+ (float, Fraction);
 Fraction const operator- (float, Fraction);

 bool const operator== (float, Fraction);
 bool const operator< (float, Fraction);
 bool const operator> (float, Fraction);
 bool const operator>= (float, Fraction);
 bool const operator<= (float, Fraction);
 

