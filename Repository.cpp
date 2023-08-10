#include "Repository.h"

void Repository::add(const Jewelry_Product& j)
{
    list.push_back(j);
}

Repository::Repository()
{
    list = vector<Jewelry_Product>();
}

void Repository::remove_last()
{
    list.pop_back();
}

void Repository::update(int index, string i, string jt, float p, double w, double nj) {
    list.at(index).set_id(i);
    list.at(index).set_price(p);
    list.at(index).set_jewelry_type(jt);
    list.at(index).set_weight(w);
    list.at(index).set_nr_jewels(nj);
}

bool Repository::remove(string id)
{
    for (int i = 0;i < list.size();i++) {
        if (list.at(i).get_id() == id){
            list.erase(list.begin() + i);
            return 1;
        }
    }
    return 0;
}

vector<Jewelry_Product> Repository::filter( FilteringCriteria& f)
{
    return f.filter(this->list);
}

string Repository::to_string()
{
    string result = "";
    for (auto it : list) {
        result += it.to_string() + "\n";
    }
    return result;
}
