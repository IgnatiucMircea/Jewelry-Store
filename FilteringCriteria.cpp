#include "FilteringCriteria.h"
#include <math.h>

vector<Jewelry_Product> FilteringPrice::filter(vector<Jewelry_Product>& data)
{
    vector<Jewelry_Product> result;
    for (auto it : data) {
        if (it.get_price() <= this->price || fabs(it.get_price() - this->price) < 0.05)
            result.push_back(it);
    }
    return result;
}

vector<Jewelry_Product> FilteringWeight::filter(vector<Jewelry_Product>& data)
{
    vector<Jewelry_Product> result;
    for (auto it : data) {
        if (it.get_weight() <= this->weight || fabs(it.get_price() - this->weight) < 0.05)
            result.push_back(it);
    }
    return result;
}

vector<Jewelry_Product> FilteringNrJewels ::filter(vector<Jewelry_Product>& data)
{
    vector<Jewelry_Product> result;
    for (auto it : data) {
        if (it.get_nr_jewels() <= this->nr_jewels || fabs(it.get_nr_jewels() - this->nr_jewels) < 0.05)
            result.push_back(it);
    }
    return result;
}

vector<Jewelry_Product> FilteringCriteriaAnd::filter(vector<Jewelry_Product>& data)
{
    vector<Jewelry_Product> result;
    result = crt1->filter(data);
    result = crt2->filter(result);
    return result;
}
