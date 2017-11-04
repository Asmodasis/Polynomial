/* -----------------------------------------------------------------------------
FILE:              Polynomial.cpp
DESCRIPTION:       This is the implemetation file for the classes objects
COMPILER:          Linux g++ compiler
NOTES:             Put other information here ...
MODIFICATION HISTORY:
Author                  Date               Version
---------------         ----------         --------------
Shawn Ray       		2017-03-12         Version 1.0 started Project
Shawn Ray       		2017-03-19         Version 1.1
Shawn Ray       		2017-03-20         Version 1.2
Shawn Ray       		2017-03-21         Version 1.3 constructor
Shawn Ray       		2017-03-22         Version 1.4 overloaded + - *
Shawn Ray       		2017-03-23         Version 1.5 overloaded << >>
Shawn Ray       		2017-03-24         Version 1.6 added vectors
Shawn Ray       		2017-03-25         Version 1.7 changed overloading
Shawn Ray       		2017-03-26         Version 1.8
Shawn Ray               2017-03-30         Version 1.9 vectors
Shawn Ray               2017-03-31         Version 2.0
Shawn Ray               2017-04-01         Version 2.1 overloaded ==
Shawn Ray               2017-04-02         Version 2.2 overloaded ()
Shawn Ray               2017-04-03         Version 2.3 constructors
Shawn Ray               2017-04-04         Version 2.4 Dynamic/ integral
Shawn Ray               2017-04-05         Version 2.5 bug fixes
Shawn Ray               2017-04-06         Version 2.6 bug fixes
Shawn Ray               2017-04-07         Version 2.7 bug fixes
----------------------------------------------------------------------------- */

#include "Polynomial.h"

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::Polynomial()
DESCRIPTION:       This is the default constructor
RETURNS:           Nothing (Void Function)
----------------------------------------------------------------------------- */

Polynomial::Polynomial(){

    degree = 0;

}


/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::Polynomial(const int &size)
DESCRIPTION:       Overloaded Constructor
RETURNS:           Nothing (Void Function)
NOTES:             constructs polynomials for dynamic allocation
----------------------------------------------------------------------------- */

Polynomial::Polynomial(const int &size){

            coef = new double [size + 1];
            degree = size;

            for(int i = 0; i < size + 1; i++){
                coef[i] = 0;
            }

            
    
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::Polynomial(const Polynomial &p1) : Polynomial::Polynomial(p1.degree)
DESCRIPTION:       Copy contructor
RETURNS:           Nothing (Void Function)
NOTES:             Copies one poly to another, uses function inheretance
----------------------------------------------------------------------------- */

Polynomial::Polynomial(const Polynomial &p1) : Polynomial::Polynomial(p1.degree){

    degree = p1.degree;
    for(int i = p1.degree; i >= 0; --i)
    {
        coef[i] = p1.coef[i];
    }

}


/* -----------------------------------------------------------------------------
FUNCTION:          std::istream& operator >> (std::istream& instream, Polynomial &p1)
DESCRIPTION:       this function takes input from the user
RETURNS:           returns an istream operator (std::cin)
----------------------------------------------------------------------------- */

std::istream& operator >> (std::istream& instream, Polynomial &p1){

    bool test = true;

    do {        // input validation


        std::cout << "\n\tEnter degree of polynomial: ";
        instream >> p1.degree;

        if(instream.fail()){
            instream.clear();
            instream.ignore(256, '\n');
        } else test = false;  // test degree

                p1.coef = new double [p1.degree + 1];

        std::cout << "\tPlease enter the coefficients of the polynomial: ";

        for (int i = p1.degree; i >= 0; --i) {
            instream >> p1.coef[i];
            if(instream.fail()){
                instream.clear();
                instream.ignore(256, '\n');
            } else test = false;  // test coef
        }

        std::cout << "\tPlease specify x values to evaluate polynomials at: ";

        instream >> p1.x;

        if(instream.fail()){
            instream.clear();
            instream.ignore(256, '\n');
        } else test = false;  // test x values

        std::cout << "\tPlease specify bottom limit for definite integration: ";
        instream >> p1.bottom;

        if(instream.fail()){
            instream.clear();
            instream.ignore(256, '\n');
        } else test = false;  // test x values

        std::cout << "\tPlease specify top limit for definite integration: ";
        instream >> p1.top;

        if(instream.fail()){
            instream.clear();
            instream.ignore(256, '\n');
        } else test = false;  // test x values


        if(test) std::cout << "\n\tYou have entered an invalid selection, please try again.\n"; // print an invalid mes
    }while(test);





    return instream;
}

/* -----------------------------------------------------------------------------
FUNCTION:          std::ostream& operator << (std::ostream& outstream, const Polynomial &p1)
DESCRIPTION:       This function overloaded the ostream operator
RETURNS:           returns ostream type (std::cout)
NOTES:             tests for integral
----------------------------------------------------------------------------- */

std::ostream& operator << (std::ostream& outstream, const Polynomial &p1){


            for(int i = p1.degree; i >= 0; i--){

                if(i < p1.degree)
                {
                    if(p1.coef[i] >= 0) outstream << " + ";
                    else outstream << " ";
                }
                if((p1.trigger_integral) && (i == 0)){
                    outstream << (char)p1.coef[0];
                }else  outstream << p1.coef[i];


                if(i > 1)
                    outstream << "x^" << i;
                else if (i == 1)
                    outstream << "x";

            }

            outstream << std::endl;


    return outstream;

}


/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator + (const Polynomial &p1) const
DESCRIPTION:       Overloaded + operator
RETURNS:           returns the polynymial p2
NOTES:             declared const so no modification to this
----------------------------------------------------------------------------- */

Polynomial Polynomial::operator + (const Polynomial &p1) const{



    std::cout << "\tAdding the 2 Polynomials : ";

    int size = MAX(degree, p1.degree);
    Polynomial p2(size);
    Polynomial Temp1(size);
    Polynomial Temp2(size);
    // temp polynomial class objects to account for varying sizes of objects
    for(int y = degree; y >= 0; --y) Temp1.coef[y] = coef[y];
    for(int w = p1.degree; w >= 0; --w) Temp2.coef[w] = p1.coef[w];

    for(int i = p2.degree; i >= 0; i--){
        p2.coef[i] = Temp1.coef[i] + Temp2.coef[i];
    }

    return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator - (const Polynomial &p1) const
DESCRIPTION:       This function overloads the - operator
RETURNS:           returns the p2 polynomial
NOTES:             declared const so no modification to this
----------------------------------------------------------------------------- */

Polynomial Polynomial::operator - (const Polynomial &p1) const{

    std::cout << "\tSubtracting the 2 Polynomials : ";

    int size = MAX(degree, p1.degree);
    Polynomial p2(size);
    Polynomial Temp1(size);
    Polynomial Temp2(size);
    // temp polynomial class objects to account for varying sizes of objects
    for(int y = degree; y >= 0; --y) Temp1.coef[y] = coef[y];
    for(int w = p1.degree; w >= 0; --w) Temp2.coef[w] = p1.coef[w];

    for(int i = p2.degree; i >= 0; i--){
        p2.coef[i] = Temp1.coef[i] - Temp2.coef[i];
    }

    return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator * (const Polynomial &p1) const
DESCRIPTION:       This overloades the * operator
RETURNS:           returns the polynomial p2
NOTES:             declared const so no modification to this
----------------------------------------------------------------------------- */

Polynomial Polynomial::operator * (const Polynomial &p1) const{



    int size = degree + p1.degree;
    Polynomial p2(size);

    std::cout << "\tMultiplying the 2 Polynomials : ";


    for(int i = degree; i >= 0; --i){

        for(int j = p1.degree; j >= 0; --j){
            p2.coef[i + j] += (coef[i] * p1.coef[j]);
        }

    }


    return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator = (const Polynomial &p1)
DESCRIPTION:       This function overloaded the = operator
RETURNS:           returns the polynomial p2
----------------------------------------------------------------------------- */

Polynomial Polynomial::operator = (const Polynomial &p1){

     
    std::cout << "\n\tAssigning polynomial two to one : \n";
    int size = MAX(degree, p1.degree);
    Polynomial Temp1(size);
    Polynomial Temp2(size);

    // temp polynomial class objects to account for varying sizes of objects
    for(int y = degree; y >= 0; --y) Temp1.coef[y] = coef[y];
    for(int y = p1.degree; y >= 0; --y) Temp2.coef[y] = p1.coef[y];

    delete coef;
    coef = new double[size + 1];
    degree = size;

    for(int i = size; i >= 0; i--) {
        coef[i] = Temp2.coef[i];

    }

    return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          bool Polynomial::operator == (const Polynomial &p1) const
DESCRIPTION:       this function tests if two poly's are equal
RETURNS:           returns a boolean for testing equality
NOTES:             declared const, bool type for testing
----------------------------------------------------------------------------- */

bool Polynomial::operator == (const Polynomial &p1) const{

    std::cout << "\tTesting if the Polynomials are equal : ";

    if(degree == p1.degree){
        for(int i = p1.degree; i >= 0; --i) {

            if(coef[i] == p1.coef[i]){

            }else return false;
        }
        return true;

    }else return false;

}


/* -----------------------------------------------------------------------------
FUNCTION:          void Polynomial::operator () (const int &x) const
DESCRIPTION:       This function overloaded the () operator
RETURNS:           Nothing (Void Function)
NOTES:             declared const so not modification to this
----------------------------------------------------------------------------- */

double Polynomial::operator () (const double &x) const{

    double sum  = 0.0;


    for(int i = degree; i >= 0; --i){

        sum += (coef[i] * ((pow(x,i))));

    }
    return sum;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator -- () const
DESCRIPTION:       This function overloads the -- operator
RETURNS:           returns the polynomial p2
NOTES:             declared const so not modification to this
----------------------------------------------------------------------------- */

Polynomial Polynomial::operator -- () const{

    int size = degree - 1;
    Polynomial p2(size);


    std::cout << "\tEvaluating the Derivative : ";

    for(int i = degree; i >= 0; i--) {
        if (i) p2.coef[i - 1] = coef[i] * i;
    }
    return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator ++ () const
DESCRIPTION:       This function overloads the ++ operator
RETURNS:           returns the polynomial p2
NOTES:             declared const so not modification to this
----------------------------------------------------------------------------- */

Polynomial Polynomial::operator ++ () const{

    int size = degree + 1;
    Polynomial p2(size);

    for(int i = size; i >= 0; --i) {
        if(i > 0){
            p2.coef[i] = ((coef[i - 1]) / i);
        }
        else{
            p2.coef[0] = 67;
        }

    }

    p2.trigger_integral = true;

    return p2;

}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator ++ (int) const
DESCRIPTION:       This function overloads the ++ operator for definite integration
RETURNS:           This function returns the polynomial p2
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */

double Polynomial::operator ++ (int) const{ // definite

    Polynomial p2(++(*this));
    double result =  p2(top) - p2(bottom) ;

    return result;

}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::~Polynomial(){
DESCRIPTION:       This is the destructor
RETURNS:           Nothing (Void Function)
NOTES:             destructs my dynamic allocated memory
----------------------------------------------------------------------------- */

Polynomial::~Polynomial(){
    delete coef;
    delete [] coef;
    coef = nullptr;
}
