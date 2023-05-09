namespace ariel{};
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "sources/Fraction.hpp"
#include "doctest.h"

Fraction a(3,5), b(6,10), c(6,5), d(0,2), e(0,3), f(1,2), g(4,16);


TEST_CASE("Arithmetic")
{
    Fraction aPlusb = a + b;
    Fraction aMinusb = a - b, aMinusc = a - c;
    Fraction aDivb = a/b, cDivc = c/c;
    Fraction ad = a * d, de = d * e, ff = f * f;
    
    CHECK(a == b);
    CHECK(a < c);
    CHECK(d == 0);
    CHECK(d == e);
    CHECK_FALSE(d > e);

    CHECK(aPlusb == 1.2);
    CHECK(aPlusb == c);
    CHECK(aPlusb > a);

    CHECK(aMinusc < 0);
    CHECK(aMinusb == e);

    CHECK(aDivb == 1);
    CHECK(aDivb == cDivc);

    CHECK(ff == g);
    CHECK(de == 0);
    CHECK(ad == d);
    CHECK(ad == e);
    

}

TEST_CASE("exceptions")
{
   CHECK_THROWS(Fraction(1,0)); 
   CHECK_THROWS(a/d);
   CHECK_THROWS(d/d);
   CHECK_THROWS(d/e);
   CHECK_THROWS((a + b) / d);
   CHECK_THROWS((a + b) / (d * 2));
}