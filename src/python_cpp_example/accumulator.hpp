#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/accumulators/statistics/weighted_variance.hpp>
#include <boost/accumulators/statistics/weighted_mean.hpp>
#include <boost/accumulators/statistics/weighted_sum.hpp>
#include <boost/accumulators/statistics/weighted_covariance.hpp>

using namespace boost::accumulators;
using namespace std;

#define WEIGHT_TYPE double

class Accumulator{
public:
    Accumulator(int index, int x=0, int y=0, int z=0):index(index), x(x), y(y), z(z){}
    ~Accumulator(){}
    void test() {
        acc(1, weight = 1);
        acc(2, weight = 1);
        acc(3, weight = 1);
    }

    void append(double value, WEIGHT_TYPE w){
        acc(value, weight = w);
    }

    double get_mean() {return weighted_mean(acc);}
    double get_variance() {return weighted_variance(acc);}
    void reset(){acc = {};}
private:
    int index;
    int x;
    int y;
    int z;
    accumulator_set<double, features<tag::weighted_mean, tag::weighted_variance>, WEIGHT_TYPE> acc;
};

class CovarianceAccumulator{
public:
    CovarianceAccumulator(int index, int x=0, int y=0, int z=0):index(index), x(x), y(y), z(z){}
    ~CovarianceAccumulator(){}

    void append(double value, WEIGHT_TYPE w, double covariate){
        acc(value, weight = w, covariate1 = covariate);
    }

    double get_mean() {return weighted_mean(acc);}

    double get_covariance() {return weighted_covariance(acc);}
    void reset() {acc = {};}

private:
    int index;
    int x;
    int y;
    int z;
    accumulator_set< double, features<tag::weighted_mean, tag::weighted_covariance<double, tag::covariate1> >, WEIGHT_TYPE > acc;
};