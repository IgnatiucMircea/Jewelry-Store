#include "CLI.h"
#include <iostream>
#include "FilteringCriteria.h"
#include <algorithm>

using std::cin;
using std::cout;
using std::getline;
using std::endl;

void CLI::display_menu()
{
    cout << "    Select a command:\n";
    cout << "\t 1 --- Add a product\n";
    cout << "\t 2 --- Show all products\n";
    cout << "\t 3 --- Delete last product\n";
    cout << "\t 4 --- Delete element by id\n";
    cout << "\t 5 --- FIlter offers by price/weight/number of jewels\n";
    cout << "\t 6 --- FIlter offers by 2 conditions\n";
    cout << "\t 7 --- Update offer by index\n";
    cout << "\t 8 --- Undo last operation\n";
    cout << "\t 9 --- Redo last undo operation\n";
    cout << "\t 0 --- Quit" << endl;
}

void CLI::run_ui()
{
    string input;
    display_menu();
    while(true)
    {
        cout << " >>> ";
        cin >> input;
        if (input == "0") {
            cout << "Exiting...";
            break;
        }
        else if (input == "1") {
            this->run_add();
        }
        else if (input == "2") {
            cout << cont->to_string() << endl;
        }
        else if (input == "3") {
            this->run_pop_back();
        }
        else if (input == "4") {
            this->run_remove();
        }
        else if (input == "5") {
            this->run_filter_one();
        }
        else if (input == "6") {
            this->run_filter_both();
        }
        else if (input == "7") {
            this->run_update();
        }
        else if (input == "8") {
            bool res = this->cont->UNDO();
            if (res)
                cout << "Undo Successfuly" << endl;
            else
                cout << "No operation to undo" << endl;
        }
        else if (input == "9") {
            bool res = this->cont->REDO();
            if (res)
                cout << "Redo Successfuly" << endl;
            else
                cout << "No operation to redo" << endl;
        }
        else cout << "Command doesn't exist!\n";
    }
}

void CLI::run_add()
{
    auto bp = read_jewelry_product();
    while (!cont->add(bp)) {
        cout << "Invalid Product\n";
        bp = read_jewelry_product();
    }
    cout << "Product added successfully!" << endl;
}

Jewelry_Product CLI::read_jewelry_product()
{
    string id;
    string type;
    float price;
    double weight, nr_jewels;
    cout << "Input properties:";
    cout << "\n\tId:";
    cin >> id;
    cout << "\n\tJewelry type:";
    cin >> type;
    cout << "\n\tPrice:";
    cin >> price;
    cout << "\n\tWeight (grams):";
    cin >> weight;
    cout << "\n\tNumber of Jewels:";
    cin >> nr_jewels;
    return Jewelry_Product{ id,type,price,weight,nr_jewels };
}

void CLI::run_remove()
{
    bool ok = 1;
    string id;
    cout << "Input the id of the product you wish to remove\n";
    cout << "\tId:";
    cin >> id;
    if(!cont->remove(id)) {
        cout << "Id does not exist\n";
        ok = 0;
    }
    if (ok) {
        cout << "Product removed successfully!" << endl;
    }
}

void CLI::run_pop_back()
{
    bool ok = cont->pop_back();
    if (ok)
        cout << "Product removed successfully!" << endl;
    else
        cout << "Repo is empty"<<endl;
}

int CLI::choose_crit()
{
    cout << "Input the criteria you wish to filter by:\n";
    cout << "\t 1 : Price\n";
    cout << "\t 2 : Weight\n";
    cout << "\t 3 : Number of jewels\n";
    int input;
    cout << " >>> ";
    cin >> input;
    bool ok = 0;
    while(!ok) {

        switch (input)
        {
        case 1: {
            ok = 1;
            break;
        }
        case 2: {
            ok = 1;
            break;
        }
        case 3: {
            ok = 1;
            break;
        }
        default: {
            cout << "Invalid input" << endl;
            cout << " >>> ";
            cin >> input;
            break;
        }
        }
    }
    return input;
}

void CLI::run_filter_one()
{
    int c1;
    c1 = choose_crit();
    bool ok = 0;

    vector<Jewelry_Product> res;
    while (!ok) {
        switch (c1)
        {
        case 1: {
            ok = 1;
            cout << "Input Price:\n";
            float price;
            cout << " >>> ";
            cin >> price;
            cout << endl;
            FilteringPrice fp{ price };
            res = this->cont->filter(fp);
            break;
        }
        case 2: {
            ok = 1;
            cout << "Input Weight:\n";
            double weight;
            cout << " >>> ";
            cin >> weight;
            cout << endl;
            FilteringWeight fc{ weight };
            res = this->cont->filter(fc);
            break;
        }
        case 3: {
            ok = 1;
            cout << "Input Number of Jewels:\n";
            double i;
            cout << " >>> ";
            cin >> i;
            cout << endl;
            FilteringNrJewels fs{ i };
            res = this->cont->filter(fs);
            break;
        }
        default: {
            cout << "Invalid input" << endl;
            break;
        }
        }
    }
    Repository repo{ res };
    if (repo.to_string() == "")
        cout << "There are no products for the given criteria.\n";
    else
        cout << repo.to_string() << endl;

}

void CLI::run_filter_both()
{
    int c1, c2;
    c1 = choose_crit();
    c2 = choose_crit();
    bool ok = 0;

    vector<Jewelry_Product> res;
    while (!ok) {
        switch (c1)
        {
        case 1: {
            ok = 1;
            cout << "Input Price:\n";
            float price;
            cout << " >>> ";
            cin >> price;
            cout << endl;
            FilteringPrice fp{ price };
            res = this->cont->filter(fp);
            break;
        }
        case 2: {
            ok = 1;
            cout << "Input Weight:\n";
            double weight;
            cout << " >>> ";
            cin >> weight;
            cout << endl;
            FilteringWeight fc{ weight };
            res = this->cont->filter(fc);
            break;
        }
        case 3: {
            ok = 1;
            cout << "Input Number of Jewels:\n";
            double nrj;
            cout << " >>> ";
            cin >> nrj;
            cout << endl;
            FilteringNrJewels fs{ nrj };
            res = this->cont->filter(fs);
            break;
        }
        default: {
            cout << "Invalid input" << endl;
            break;
        }
        }
    }
    Repository repo{ res };
    vector<Jewelry_Product> res1;
    ok = 0;
    while (!ok) {
        switch (c2)
        {
        case 1: {
            ok = 1;
            cout << "Input price:\n";
            float price;
            cout << " >>> ";
            cin >> price;
            cout << endl;
            FilteringPrice fp{ price };
            res1 = repo.filter(fp);
            break;
        }
        case 2: {
            ok = 1;
            cout << "Input Weight:\n";
            double weight;
            cout << " >>> ";
            cin >> weight;
            cout << endl;
            FilteringWeight fc{ weight };
            res1 = repo.filter(fc);

            break;
        }
        case 3: {
            ok = 1;
            cout << "Input Number of Jewels:\n";
            double nrj;
            cout << " >>> ";
            cin >> nrj;
            cout << endl;
            FilteringNrJewels fs{ nrj };
            res1 = repo.filter(fs);

            break;
        }
        default: {
            cout << "Invalid input" << endl;
            break;
        }
        }
    }
    Repository result{ res1 };
    if (result.to_string() == "")
        cout << "There are no products for the given criteria.\n";
    else
        cout << result.to_string() << endl;
}

void CLI::run_update()
{
    int index;
    float price;
    string id, type;
    double weight, nr_jewels;
    cout << "\n\tIndex:";
    cin >> index;
    cout << "Input properties:";
    cout << "\n\tId:";
    cin >> id;
    cout << "\n\tJewelry type:";
    cin >> type;
    cout << "\n\tPrice:";
    cin >> price;
    cout << "\n\tWeight (grams):";
    cin >> weight;
    cout << "\n\tNumber of Jewels:";
    cin >> nr_jewels;
    if (cont->update(index, id, type, price, weight, nr_jewels) == 1)
        cout << "\n\tUpdated successfully!\n";
    else cout << "\n\tInvalid index\n";
}

void CLI::display()
{
    cout << cont->to_string();
}
