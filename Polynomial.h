#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
/* -----------------------------------------------------------------------------
FILE:              Polynomial.h
DESCRIPTION:       This is the header file for poly_class.cpp
COMPILER:          Linux g++ compiler
NOTES:             Class objects declared here
MODIFICATION HISTORY:
Author                  Date               Version
---------------         ----------         --------------
Shawn Ray       		2017-03-12         Version 1.0 started Project
Shawn Ray       		2017-03-19         Version 1.1
Shawn Ray       		2017-03-20         Version 1.2
Shawn Ray       		2017-03-21         Version 1.3 overloading
Shawn Ray       		2017-03-22         Version 1.4 added extra functions
Shawn Ray       		2017-03-23         Version 1.5 modified input and output
Shawn Ray       		2017-03-24         Version 1.6
Shawn Ray       		2017-03-25         Version 1.7 Friends of classes
Shawn Ray       		2017-03-26         Version 1.8
Shawn Ray               2017-03-30         Version 1.9
Shawn Ray               2017-03-31         Version 2.0
Shawn Ray               2017-04-01         Version 2.1
Shawn Ray               2017-04-02         Version 2.2 Dynamic, destructor
Shawn Ray               2017-04-03         Version 2.3
Shawn Ray               2017-04-04         Version 2.4 Dynamic/Double coef
Shawn Ray               2017-04-05         Version 2.5 bug fixes
Shawn Ray               2017-04-06         Version 2.6 bug fixes
Shawn Ray               2017-04-07         Version 2.7 bug fixes
----------------------------------------------------------------------------- */


#include <iostream>
#include <cmath>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

/* -----------------------------------------------------------------------------
CLASS:             Polynomial
DESCRIPTION:       This class declares the ground work for polynomials with degree and coeficiants
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */

class Polynomial
{
private:
    int degree; 		// Degree of the polynomial
    double* coef = nullptr;
public:

    double top;
    double bottom;
    double x;

    bool trigger_integral = false;
    const char* super[10] = {
            "\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074",
            "\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};

    Polynomial();		//constructor
    Polynomial(const int &);    // overloaded constructor for dynamic allocation
    Polynomial(const Polynomial &); // copy constructor

    friend std::istream& operator >> (std::istream &instream, Polynomial &p1); // overload >> operator
    friend std::ostream& operator << (std::ostream &outstream, const Polynomial &p1); //overload << operator

    Polynomial operator + (const Polynomial &) const; // overload + operator
    Polynomial operator - (const Polynomial &) const; // overload - operator
    Polynomial operator * (const Polynomial &) const; // overload * operator
    Polynomial operator = (const Polynomial &); // overload = operator
    bool operator == (const Polynomial &) const; // overload == operator declared const so no modification
    double operator () (const double &) const;

    Polynomial operator -- () const;
    Polynomial operator ++ () const;
    double operator ++ (int) const;

    ~Polynomial();      //destructor
};

//Function declarations

void sub_main(Polynomial []);

#endif //_POLYNOMIAL_H
