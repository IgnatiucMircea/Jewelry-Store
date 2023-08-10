#pragma once
#include "Jewelry_Product.h"
#include <vector>
using std::vector;
class FilteringCriteria
{
public:
    virtual vector<Jewelry_Product> filter(vector<Jewelry_Product>& data) = 0;

};

class FilteringPrice :virtual public FilteringCriteria {
private:
    float price;
public:
    vector<Jewelry_Product> filter(vector<Jewelry_Product>& data) override;
    FilteringPrice(float p) { price = p; }
};

class FilteringWeight :virtual public FilteringCriteria{
private:
    double weight;
public:
    vector<Jewelry_Product> filter(vector<Jewelry_Product>& data) override;
    FilteringWeight(double w) { weight = w; }
};


class FilteringNrJewels :virtual public FilteringCriteria {
private:
    double nr_jewels;
public:
    vector<Jewelry_Product> filter(vector<Jewelry_Product>& data) override;
    FilteringNrJewels(double n_j) { nr_jewels = n_j; }
};

class FilteringCriteriaAnd :virtual public FilteringCriteria {

private:
    FilteringCriteria* crt1;
    FilteringCriteria* crt2;
public:
    FilteringCriteriaAnd(FilteringCriteria& c1, FilteringCriteria& c2);
    vector<Jewelry_Product> filter(vector<Jewelry_Product>& data);
};
