#include "math.hpp"

using namespace boost::accumulators;


int add(int i, int j)
{
    return i + j;
}

int subtract(int i, int j)
{
    return i - j;
}

void average(double i, double j){
  accumulator_set<double, features<tag::mean, tag::variance>> acc;
  acc(i);
  acc(j);
  std::cout << mean(acc) << '\n';
  std::cout << variance(acc) << '\n';  
  }
