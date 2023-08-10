#pragma once
#include <string>
#include "Controller.h"
#include "Repository.h"
#include "FilteringCriteria.h"
using std::string;
class CLI
{
private:
    Controller* cont;
public:
    CLI(Controller& c) { cont = &c; }
    void display_menu();
    void run_ui();
    void run_add();
    Jewelry_Product read_jewelry_product();
    void run_remove();
    void run_pop_back();
    int choose_crit();
    void run_filter_one();
    void run_filter_both();
    void run_update();
    void display();
};

