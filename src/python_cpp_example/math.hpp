#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

/*! Add two integers
    \param i an integer
    \param j another integer
*/
int add(int i, int j);
/*! Subtract one integer from another 
    \param i an integer
    \param j an integer to subtract from \p i
*/
int subtract(int i, int j);

void average(double i, double j);