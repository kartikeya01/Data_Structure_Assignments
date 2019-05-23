#include <iostream>

#include "bag.h"

using std::cout;
using std::endl;
using data_structures_assignment_extra::bag;

bool test1()
{
    bag bag1;
    bag bag2;
    bag bag3;
    bag1.insert(1);
    bag3 = intersection(bag1, bag2);
    if (bag3.size() != 0)
    {
        cout << "Test 1 intersection failed." << endl;
        return false;
    }
    bag3 = disjunctive_union(bag1, bag2);
    if (bag3.size() != 1 || bag3.count(1) != 1)
    {
        cout << "Test 1 disjunctive union failed." << endl;
        return false;
    }
    return true;
}

bool test2()
{
    bag bag1;
    bag bag2;
    bag bag3;
    bag1.insert(1);
    bag1.insert(2);
    bag2.insert(2);
    bag3 = intersection(bag1, bag2);
    if (bag3.size() != 1 || bag3.count(2) != 1)
    {
        cout << "Test 2 intersection failed." << endl;
        return false;
    }
    bag3 = disjunctive_union(bag1, bag2);
    if (bag3.size() != 1 || bag3.count(1) != 1)
    {
        cout << "Test 2 disjunctive union failed." << endl;
        return false;
    }
    return true;
}

bool test3()
{
    bag bag1;
    bag bag2;
    bag bag3;
    bag1.insert(1);
    bag1.insert(2);
    bag1.insert(2);
    bag1.insert(4);
    bag2.insert(2);
    bag2.insert(2);
    bag2.insert(2);
    bag2.insert(3);
    bag2.insert(4);
    bag3 = intersection(bag1, bag2);
    if (bag3.size() != 3 || bag3.count(2) != 2 || bag3.count(4) != 1)
    {
        cout << "Test 3 intersection failed." << endl;
        return false;
    }
    bag3 = disjunctive_union(bag1, bag2);
    if (bag3.size() != 3 || bag3.count(1) != 1 || bag3.count(2) != 1 || bag3.count(3) != 1)
    {
        cout << "Test 3 disjunctive union failed." << endl;
        return false;
    }
    return true;
}

int main()
{
    if (test1() && test2() && test3())
    {
        cout << "Bag tests passed." << endl;
    }
    else
    {
        cout << "Bag tests failed." << endl;
    }

    return 0;
}