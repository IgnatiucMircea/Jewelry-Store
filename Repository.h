#pragma once
#include "Jewelry_Product.h"
#include <vector>
#include "FilteringCriteria.h"
#include <stack>

using std::vector;
class Controller;
typedef std::stack<vector<Jewelry_Product>> undo_q;
class Repository
{
private:
    friend class Controller;
    undo_q undo_stack;
    undo_q redo_stack;
    vector<Jewelry_Product> list;
    vector<Jewelry_Product>& get_list() { return list; }
public:

    /**
     * default constructor for Repository class.
     */
    Repository();

    /**
     * parametrized constructor for Repository class
     *
     * param v vector of jewlery products.
     */
    Repository(vector<Jewelry_Product>& v) { list = v; }

    /**
     * adds j to the list.
     *
     * param j object of type Jewlery_Product
     */
    void add(const Jewelry_Product& j);

    /**
     * removes the last element from the list.
     */
    void remove_last();

    /**
     * removes the element with id
     *
     * param id string representing the id of an element in the list.
     * \return true if opperation succeded/ false otherwise
     */
    bool remove(string id);

    /**
     * .updates an elem based on its index, if lower than the length
     *
     * \param index: index of the element
     * \param i:  id of the product
     * \param jt: the jewelry type
     * \param p:  price of the product
     * \param w:  weight of the product
     * \param nj: number of jewels
     * \return true if operation was successful,false otherwise
     */
    void update(int index,string i,string jt,float p,double w,double nj);

    /**
    * returns the string rep of the repo
     * .\return the string representation of the entire repo
     */
    string to_string();

    /**
    * filters the repo based on the criteria c
    *
    * param c object of type filteringcriteria
    *
    *
     * .\return a vector with the desired filters applied
     */
    vector<Jewelry_Product> filter( FilteringCriteria& c);
};

