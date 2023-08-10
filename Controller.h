#pragma once
#include "Jewelry_Product.h"
#include "Repository.h"
#include <vector>

using std::vector;
class Controller
{
private:
    Repository* repo;
    undo_q undo_stack;
    undo_q redo_stack;
    vector<Jewelry_Product> list;

public:
    /**
     * default constructor for Controller class.
     */
    Controller();
    /**
     * .parametrized constructor for controller
     *
     * \param rep obj of type repository
     */
    Controller(Repository& rep);

    /**
     * .adds p to te repo, after verifying input
     *
     * \param p Jewlery_Product object
     * \return true if operation was succesfull, false otherwise
     */
    bool add( Jewelry_Product& p);

    /**
     * .removes the last elem of the repo, if non-empty
     *
     * \return true if operation was succesful, false otherwise
     */
    bool pop_back();

    /**
     * .removes the elem based on id, if it exists
     *
     * \param id represents the id of an elem in the repo
     * \return true if operation was successful, false otherwise
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
    bool update(int index, string id, string jt, float price, double weight, double nj);

    /**
     * .undoes the last operation
     *
     * \return true if operation was succesful/ no otherwise
     */

    bool index_ctrl(int index);
    /**
    * .tests index
    *
    * \param index: index of the element
    */

    bool UNDO();

    /**
     * redoes the last operation
     *
     * \return true if operation was succesful/ no otherwise.
     */
    bool REDO();

    /**
    * filters the repo based on the criteria c
    *
    * param c object of type filteringcriteria
    *
    *
     * .\return a vector with the desired filters applied
     */
    vector < Jewelry_Product > filter(FilteringCriteria&);

    /**
    * returns the string rep of the repo
     * .\return the string representation of the entire repo
     */
    string to_string();

};

