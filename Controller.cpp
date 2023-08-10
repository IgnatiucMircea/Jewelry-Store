#include "Controller.h"

Controller::Controller()
{
    undo_stack = undo_q();
    redo_stack = undo_q();
}
Controller::Controller(Repository& rep)
{
    repo = &rep;
}

bool Controller::add(Jewelry_Product& p)
{
    bool ok = true;
    if (p.get_price() <= 0 || p.get_weight() < 0 || p.get_nr_jewels() < 0)
        ok = false;
    for (auto it : repo->list) {
        if (it.get_id() == p.get_id()) {
            ok = false;
            break;
        }
    }
    if(ok)
    {
        repo->add(p);
        undo_stack.push(repo->list);
    }
    return ok;
}

bool Controller::pop_back()
{
    if (!this->repo->list.empty()) {
        this->repo->remove_last();
        undo_stack.push(repo->list);
        return 1;
    }
    return 0;
}

bool Controller::remove(string id)
{
    for (auto it : repo->list) {
        if (it.get_id() == id) {
            this->repo->remove(id);
            undo_stack.push(repo->list);
            return 1;
            break;
        }
    }
    return 0;
}

bool Controller::update(int index, string i, string jt, float p, double w, double nj) {
    if (index < this->repo->list.size() )
    {
        if (p <= 0 || w < 0 || nj < 0)
            return 0;
        this->repo->update(index, i, jt, p, w, nj);
        undo_stack.push(list);
        return 1;
    }
    return 0;
}

bool Controller::index_ctrl(int index)
{
    if (index < this->repo->list.size() )
    {
        undo_stack.push(repo->list);
        return 1;
    }
    return 0;
}

bool Controller::UNDO()
{
    if (!undo_stack.empty()) {
            redo_stack.push(undo_stack.top());
            undo_stack.pop();
            repo->list = undo_stack.top();
            return 1;
        }
     return 0;
}

bool Controller::REDO()
{
    if (!redo_stack.empty()) {
            undo_stack.push(redo_stack.top());
            repo->list = redo_stack.top();
            redo_stack.pop();
            return 1;
        }
    return 0;
}

vector<Jewelry_Product> Controller::filter(FilteringCriteria& f)
{
    return f.filter(this->repo->list);
}

string Controller::to_string()
{
    return repo->to_string();
}
