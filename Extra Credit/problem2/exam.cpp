#include <iostream>

#include "node.h"

using std::cout;
using std::endl;
using data_structures_assignment_extra::node;
using data_structures_assignment_extra::list_head_insert;
using data_structures_assignment_extra::list_insert;


bool test1()
{
    node* head_ptr1;
    node* head_ptr2;
    head_ptr1 = nullptr;
    head_ptr2 = nullptr;
    list_head_insert(head_ptr1, 10);
    list_every_other(head_ptr1, head_ptr2);
    if (head_ptr1->data() != 10) { return false; }
    if (head_ptr1->link() != nullptr) { return false; }
    return head_ptr2 == nullptr;
}

bool test2()
{
    node* head_ptr1;
    node* head_ptr2;
    head_ptr1 = nullptr;
    head_ptr2 = nullptr;
    list_head_insert(head_ptr1, 10);
    list_insert(head_ptr1, 20);
    list_every_other(head_ptr1, head_ptr2);
    if (head_ptr1->data() != 10) { return false; }
    if (head_ptr1->link() != nullptr) { return false; }
    if (head_ptr2->data() != 20) { return false; }
    return head_ptr2->link() == nullptr;
}

bool test3()
{
    node* head_ptr1;
    node* head_ptr2;
    node* next;
    head_ptr1 = nullptr;
    head_ptr2 = nullptr;
    list_head_insert(head_ptr1, 10);
    next = head_ptr1;
    list_insert(next, 20);
    next = next->link();
    list_insert(next, 30);
    list_every_other(head_ptr1, head_ptr2);
    if (head_ptr1->data() != 10) { return false; }
    next = head_ptr1->link();
    if (next->data() != 30) { return false; }
    next = next->link();
    if (next != nullptr) { return false; }
    if (head_ptr2->data() != 20) { return false; }
    return head_ptr2->link() == nullptr;
}

bool test4()
{
    node* head_ptr1;
    node* head_ptr2;
    node* next;
    head_ptr1 = nullptr;
    head_ptr2 = nullptr;
    list_head_insert(head_ptr1, 10);
    next = head_ptr1;
    list_insert(next, 20);
    next = next->link();
    list_insert(next, 30);
    next = next->link();
    list_insert(next, 40);
    next = next->link();
    list_insert(next, 50);
    next = next->link();
    list_insert(next, 60);
    next = next->link();
    list_insert(next, 70);
    next = next->link();
    list_insert(next, 80);
    next = next->link();
    list_insert(next, 90);
    list_every_other(head_ptr1, head_ptr2);
    if (head_ptr1->data() != 10) { return false; }
    next = head_ptr1->link();
    if (next->data() != 30) { return false; }
    next = next->link();
    if (next->data() != 50) { return false; }
    next = next->link();
    if (next->data() != 70) { return false; }
    next = next->link();
    if (next->data() != 90) { return false; }
    next = next->link();
    if (next != nullptr) { return false; }
    if (head_ptr2->data() != 20) { return false; }
    next = head_ptr2->link();
    if (next->data() != 40) { return false; }
    next = next->link();
    if (next->data() != 60) { return false; }
    next = next->link();
    if (next->data() != 80) { return false; }
    next = next->link();
    return next == nullptr;
}

int main()
{
    if (!test1())
    {
        cout << "Linked list test 1 failed." << endl;
    }
    else if (!test2())
    {
        cout << "Linked list test 2 failed." << endl;
    }
    else if (!test3())
    {
        cout << "Linked list test 3 failed." << endl;
    }
    else if (!test4())
    {
        cout << "Linked list test 3 failed." << endl;
    }
    else
    {
        cout << "Linked list tests passed." << endl;
    }

    return 0;
}