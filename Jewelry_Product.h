#pragma once
#include <string>
#include <iostream>

using std::string;

class Jewelry_Product
{
private:
    float price;
    string id;
    string jewelry_type;
    double weight;
    double nr_jewels;
public:
    /**
     * .Constructor for Bakery product
     *
     * \param i:  id of the product
     * \param jt: the jewelry type
     * \param p:  price of the product
     * \param w:  weight of the product
     * \param nj: number of jewels
     */
    Jewelry_Product( string i, string jt, float p, double w, double nj);

    /**
     * .getter method for the id
     *
     * \return the id of the object
     */
    string get_id() { return id; }

    /**
     * .getter method for the jewelry type
     *
     * \return the jewlery of the object
     */
    string get_jewelry_type() { return jewelry_type; }

    /**
     * .getter method for the price
     *
     * \return the price of the object
     */
    float get_price() { return price; }

    /**
     * .getter method for the weight
     *
     * \return the weight of the object
     */
    double get_weight() { return weight; }

    /**
     * .getter method for the number of jewels
     *
     * \return the number of jewels of the object
     */
    double get_nr_jewels() { return nr_jewels; }

    /**
     * .setter method for the id
     *
     * \param i new id
     */
    void set_id(string i) { id=i; }

    /**
     * .setter method for the price
     *
     * \param p new price
     */
    void set_price(float p) { price=p; }

    /**
     * .setter method for the jewlery type
     *
     * \param jt new jewlery type
     */
    void set_jewelry_type(string jt) { jewelry_type=jt; }

    /**
     * .setter method for the weight
     *
     * \param w new weight
     */
    void set_weight(double w) { weight=w; }

    /**
     * .setter method for the number of jewels
     *
     * \param nj new number of jewels
     */
    void set_nr_jewels(double nj) { nr_jewels=nj; }
    string to_string();
};

