/* -----------------------------------------------------------------------------
FILE:              poly_class.cpp
DESCRIPTION:       This function is the main driver program for the program
COMPILER:          Linux g++ compiler
NOTES:             Uses overloading operators
MODIFICATION HISTORY:
Author                  Date               Version
---------------         ----------         --------------
Shawn Ray       		2017-03-12         Version 1.0 started Project
Shawn Ray       		2017-03-19         Version 1.1
Shawn Ray       		2017-03-20         Version 1.2
Shawn Ray       		2017-03-21         Version 1.3
Shawn Ray       		2017-03-22         Version 1.4
Shawn Ray       		2017-03-23         Version 1.5 added extra operations
Shawn Ray       		2017-03-24         Version 1.6 output/input
Shawn Ray       		2017-03-25         Version 1.7 output/ input
Shawn Ray       		2017-03-26         Version 1.8
Shawn Ray               2017-03-30         Version 1.9
Shawn Ray               2017-03-31         Version 2.0
Shawn Ray               2017-04-01         Version 2.1
Shawn Ray               2017-04-02         Version 2.2
Shawn Ray               2017-04-03         Version 2.3
Shawn Ray               2017-04-03         Version 2.3
Shawn Ray               2017-04-04         Version 2.4
Shawn Ray               2017-04-05         Version 2.5 bug fixes
Shawn Ray               2017-04-06         Version 2.6 bug fixes
Shawn Ray               2017-04-07         Version 2.7 bug fixes
----------------------------------------------------------------------------- */


#include "Polynomial.h"     // header file


/* -----------------------------------------------------------------------------
FUNCTION:          int main(int argc, char * argv[])
DESCRIPTION:       Main function
RETURNS:           returns a 0
NOTES:             calls sub_main
----------------------------------------------------------------------------- */

int main(int argc, char * argv[])
{
    Polynomial poly[3];

    sub_main(poly);

    return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          void sub_main(Polynomial poly[])
DESCRIPTION:       This function prints all the overloading done in the class
RETURNS:           Nothing (Void Function)
NOTES:             Passed poly[] to this function
----------------------------------------------------------------------------- */

void sub_main(Polynomial poly[]){

    //Polynomial copypoly(poly[0]);

    for (int n=0; n < 2; n++)
    {
        std::cin >> poly[n];
        std::cout << poly[n];
    }

    std::cout << "\tFirst Polynomial: " << poly[0];
    std::cout << "\tSecond Polynomial: " << poly[1];
    std::cout << poly[0] + poly[1]; // adding poly
    std::cout << poly[0] - poly[1];  // subtracting poly
    std::cout << poly[0] * poly[1];  // Multiplying poly

    if(poly[0] == poly[1])
        std::cout << " Yes " << std::endl;
    else
        std::cout << " No " << std::endl;

    for(int i = 0; i < 2; ++i){
        // function of x
        std::cout << "\tEvaluating Poly " << i + 1 << " at f(" << poly[i].x << ") = " << poly[i](poly[i].x) << "\n";

        std::cout << --poly[i]; // derivative
        std::cout << "\tEvaluating the Indefinite Integral of Poly " << i + 1 << " : ";
        std::cout << ++poly[i]; // indefinite integral
        std::cout << "\tEvaluating the Definite Integral of Poly " << i + 1 << " : ";
        double result = poly[i]++; // definite integral
        std::cout << " : " << result;
        if(i == 0)std::cout << "\n";
    }

    poly[0] = poly[1];  // Assigning poly
    std::cout << "\tFirst Polynomial: " << poly[0];
    std::cout << "\tSecond Polynomial: " << poly[1];



}
