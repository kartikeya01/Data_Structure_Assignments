#include <iostream>

#include "hashfunctions.h"
#include "hashfunctiontest.h"

using std::cout;
using std::endl;
using data_structures_assignment_extra::all_collisions_hash_function;
using data_structures_assignment_extra::half_collisions_hash_function;
using data_structures_assignment_extra::no_collisions_hash_function;
using data_structures_assignment_extra::hash_function_collision_test;

bool test1()
{
    int keys[100];
    for (int i = 0; i < 100; ++i)
    {
        keys[i] = 50 * i;
    }
    // Keys is now an array of multiples of 50. That is [0, 50, 100, 150, 200, 250, ...]
    double ratio_collisions;
    double expected_collisions = 1.0;
    ratio_collisions = hash_function_collision_test(all_collisions_hash_function, keys, 100);
    if (abs(ratio_collisions - expected_collisions) > 0.03)
    {
        cout << "Found " << ratio_collisions << " ratio of collisions, expected " << expected_collisions << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool test2()
{
    int keys[100];
    for (int i = 0; i < 100; ++i)
    {
        keys[i] = 50 * i;
    }
    // Keys is now an array of multiples of 50. That is [0, 50, 100, 150, 200, 250, ...]
    double ratio_collisions;
    double expected_collisions = 0.5;
    ratio_collisions = hash_function_collision_test(half_collisions_hash_function, keys, 100);
    if (abs(ratio_collisions - expected_collisions) > 0.03)
    {
        cout << "Found " << ratio_collisions << " ratio of collisions, expected " << expected_collisions << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool test3()
{
    int keys[100];
    for (int i = 0; i < 100; ++i)
    {
        keys[i] = 50 * i;
    }
    // Keys is now an array of multiples of 50. That is [0, 50, 100, 150, 200, 250, ...]
    double ratio_collisions;
    double expected_collisions = 0.0;
    ratio_collisions = hash_function_collision_test(no_collisions_hash_function, keys, 100);
    if (abs(ratio_collisions - expected_collisions) > 0.03)
    {
        cout << "Found " << ratio_collisions << " ratio of collisions, expected " << expected_collisions << endl;
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    if (!test1())
    {
        cout << "Hash table test 1 failed." << endl;
    }
    else if (!test2())
    {
        cout << "Hash table test 2 failed." << endl;
    }
    else if (!test3())
    {
        cout << "Hash table test 3 failed." << endl;
    }
    else
    {
        cout << "Hash table tests passed." << endl;
    }

    return 0;
}