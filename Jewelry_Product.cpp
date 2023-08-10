#include "Jewelry_Product.h"

Jewelry_Product::Jewelry_Product( string i, string n, float p, double c, double s)
{
    price = p;
    id = i;
    jewelry_type = n;
    weight = c;
    nr_jewels = s;
}

string Jewelry_Product::to_string()
{
    string result = "";
    result += "Product id: " + id;
    result += "\n\tJewlery type: " + jewelry_type;
    result += "\n\tProduct weight: " + std::to_string(weight) + "g";
    result += "\n\tNumber of jewels " + std::to_string(nr_jewels)+"\n";
    result += "\tProduct price: " + std::to_string(price)+"\n";
    return result;
}


