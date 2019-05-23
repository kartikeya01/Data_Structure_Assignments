#include <iostream>

#include "bintree.h"

using std::cout;
using std::endl;
using data_structures_assignment_extra::binary_tree_node;

bool test1()
{
    binary_tree_node<int>* node_ptr1;
    binary_tree_node<int>* node_ptr2;
    binary_tree_node<int>* node_ptr3;
    binary_tree_node<int>* node_ptr4;
    binary_tree_node<int>* node_ptr5;
    binary_tree_node<int>* node_ptr6;
    binary_tree_node<int>* node_ptr7;
    node_ptr1 = new binary_tree_node<int>(1, nullptr, nullptr);
    node_ptr3 = new binary_tree_node<int>(3, nullptr, nullptr);
    node_ptr2 = new binary_tree_node<int>(2, node_ptr1, node_ptr3);
    node_ptr4 = new binary_tree_node<int>(4, node_ptr2, nullptr);
    node_ptr5 = new binary_tree_node<int>(5, node_ptr4, nullptr);
    node_ptr7 = new binary_tree_node<int>(7, nullptr, nullptr);
    node_ptr6 = new binary_tree_node<int>(6, node_ptr5, node_ptr7);
    int max = search_tree_maximum(node_ptr6);
    int min = search_tree_minimum(node_ptr6);
    if (max != 7)
    {
        cout << "During test1, search_tree_maximum returned " << max << " but expected 7." << endl;
        return false;
    }
    if (min != 1)
    {
        cout << "During test1, search_tree_minimum returned " << max << " but expected 1." << endl;
        return false;
    }
    cout << "Manually check that the following lines contain the same values (order does not matter)." << endl;
    cout << "The first of the two lines is from your print function." << endl;
    int exclude[3] = {2,4,6};
//    tree_print_all_except(node_ptr6, exclude, 3);
    cout << endl;
    cout << "1 3 5 7 " << endl;
    return true;
}

bool test2()
{
    binary_tree_node<int>* node_ptr1;
    binary_tree_node<int>* node_ptr2;
    binary_tree_node<int>* node_ptr3;
    binary_tree_node<int>* node_ptr4;
    binary_tree_node<int>* node_ptr5;
    binary_tree_node<int>* node_ptr6;
    binary_tree_node<int>* node_ptr7;
    node_ptr6 = new binary_tree_node<int>(6, nullptr, nullptr);
    node_ptr7 = new binary_tree_node<int>(7, node_ptr6, nullptr);
    node_ptr4 = new binary_tree_node<int>(4, nullptr, nullptr);
    node_ptr3 = new binary_tree_node<int>(3, nullptr, node_ptr4);
    node_ptr2 = new binary_tree_node<int>(2, nullptr, node_ptr3);
    node_ptr1 = new binary_tree_node<int>(1, nullptr, node_ptr2);
    node_ptr5 = new binary_tree_node<int>(5, node_ptr1, node_ptr7);
    int max = search_tree_maximum(node_ptr5);
    int min = search_tree_minimum(node_ptr5);
    if (max != 7)
    {
        cout << "During test2, search_tree_maximum returned " << max << " but expected 7." << endl;
        return false;
    }
    if (min != 1)
    {
        cout << "During test2, search_tree_minimum returned " << max << " but expected 1." << endl;
        return false;
    }
    cout << "Manually check that the following lines contain the same values (order does not matter)." << endl;
    cout << "The first of the two lines is from your print function." << endl;
    int exclude[2] = {1,7};
//    tree_print_all_except(node_ptr5, exclude, 2);
    cout << endl;
    cout << "2 3 4 5 6 " << endl;
    return true;
}

//bool test3()
//{
//    binary_tree_node<int>* node_ptr1;
//    binary_tree_node<int>* node_ptr2;
//    binary_tree_node<int>* node_ptr3;
//    binary_tree_node<int>* node_ptr4;
//    binary_tree_node<int>* node_ptr5;
//    binary_tree_node<int>* node_ptr6;
//    binary_tree_node<int>* node_ptr7;
//    node_ptr7 = new binary_tree_node<int>(7, nullptr, nullptr);
//    node_ptr6 = new binary_tree_node<int>(6, nullptr, node_ptr7);
//    node_ptr5 = new binary_tree_node<int>(5, nullptr, node_ptr6);
//    node_ptr4 = new binary_tree_node<int>(4, nullptr, node_ptr5);
//    node_ptr3 = new binary_tree_node<int>(3, nullptr, node_ptr4);
//    node_ptr2 = new binary_tree_node<int>(2, nullptr, node_ptr3);
//    node_ptr1 = new binary_tree_node<int>(1, nullptr, node_ptr2);
//    int max = search_tree_maximum(node_ptr1);
//    int min = search_tree_minimum(node_ptr1);
//    if (max != 7)
//    {
//        cout << "During test3, search_tree_maximum returned " << max << " but expected 7." << endl;
//        return false;
//    }
//    if (min != 1)
//    {
//        cout << "During test3, search_tree_minimum returned " << max << " but expected 1." << endl;
//        return false;
//    }
//    cout << "Manually check that the following lines contain the same values (order does not matter)." << endl;
//    cout << "The first of the two lines is from your print function." << endl;
//    int exclude[0] = {};
//    tree_print_all_except(node_ptr1, exclude, 0);
//    cout << endl;
//    cout << "1 2 3 4 5 6 7 " << endl;
//    return true;
//}

int main()
{
    if (test1() && test2())
    {
        cout << "Tree tests passed (so long as you manually checked the printing)." << endl;
    }
    else
    {
        cout << "Tree tests failed." << endl;
    }

    return 0;
}