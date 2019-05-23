// Note: This is a template file. Do not include it in your compile list.
// FILE: bintree.cpp
// IMPLEMENTS: The binary_tree node class (see bintree.h for documentation). 
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout
#include "bintree.h"

namespace data_structures_assignment_extra
{
    template<class Process, class BTNode>
    void inorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != nullptr)
        {
            inorder(f, node_ptr->left());
            f(node_ptr->data());
            inorder(f, node_ptr->right());
        }
    }

    template<class Process, class BTNode>
    void postorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != nullptr)
        {
            postorder(f, node_ptr->left());
            postorder(f, node_ptr->right());
            f(node_ptr->data());
        }
    }

    template<class Process, class BTNode>
    void preorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != nullptr)
        {
            f(node_ptr->data());
            preorder(f, node_ptr->left());
            preorder(f, node_ptr->right());
        }
    }

    template<class Item, class SizeType>
    void print(const binary_tree_node <Item>* node_ptr, SizeType depth)
    // Library facilities used: iomanip, iostream, stdlib
    {
        if (node_ptr != nullptr)
        {
            print(node_ptr->right(), depth + 1);
            std::cout << std::setw(4 * depth) << ""; // Indent 4*depth spaces.
            std::cout << node_ptr->data() << std::endl;
            print(node_ptr->left(), depth + 1);
        }
    }

    template<class Item>
    void tree_clear(binary_tree_node <Item>*& root_ptr)
    // Library facilities used: cstdlib
    {
        if (root_ptr != nullptr)
        {
            tree_clear(root_ptr->left());
            tree_clear(root_ptr->right());
            delete root_ptr;
            root_ptr = nullptr;
        }
    }

    template<class Item>
    binary_tree_node <Item>* tree_copy(const binary_tree_node <Item>* root_ptr)
    // Library facilities used: cstdlib
    {
        binary_tree_node<Item>* l_ptr;
        binary_tree_node<Item>* r_ptr;

        if (root_ptr == nullptr)
            return nullptr;
        else
        {
            l_ptr = tree_copy(root_ptr->left());
            r_ptr = tree_copy(root_ptr->right());
            return new binary_tree_node<Item>(root_ptr->data(), l_ptr, r_ptr);
        }
    }

    template<class Item>
    size_t tree_size(const binary_tree_node <Item>* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr == nullptr)
            return 0;
        else
            return 1 + tree_size(node_ptr->left()) + tree_size(node_ptr->right());
    }

    template<class Item>
    Item search_tree_minimum(const binary_tree_node<Item>* root_ptr)
    {
        // Base case
        if (root_ptr == NULL) return -1;

        // Return minimum of 3 values:
        // 1) Root's data 2) Max in Left Subtree
        // 3) Max in right subtree
        int res = root_ptr->data();
        int lres = search_tree_minimum(root_ptr->left());
        int rres = search_tree_minimum(root_ptr->right());
        if (lres < res)
            res = lres;
        if (rres < res)
            res = rres;
        return res;
    }

    template<class Item>
    Item search_tree_maximum(const binary_tree_node<Item>* root_ptr)
    {
        // Base case
        if (root_ptr == NULL) return -1;

        // Return maximum of 3 values:
        // 1) Root's data 2) Max in Left Subtree
        // 3) Max in right subtree
        int res = root_ptr->data();
        int lres = search_tree_maximum(root_ptr->left());
        int rres = search_tree_maximum(root_ptr->right());
        if (lres > res)
            res = lres;
        if (rres > res)
            res = rres;
        return res;
    }

//    template<class Item>
//    void tree_print_all_except(const binary_tree_node<Item>* root_ptr, Item* exception_values, std::size_t exception_values_size)
//    {
//        if (root_ptr != NULL){
//            tree_print_all_except(root_ptr->left(), exception_values, exception_values_size);
//
//            for (int i = 0; i < exception_values_size; i++) {
//
//                if( exception_values[i] == root_ptr->data()){
//                    root_ptr->data() = 0;
//                }
//            }
//            tree_print_all_except(root_ptr->right(), exception_values, exception_values_size);
//            std::cout << root_ptr->data() << std::endl; // STUDENT WORK.
//        }
//    }
}