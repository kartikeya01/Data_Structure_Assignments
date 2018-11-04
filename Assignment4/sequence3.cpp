#include "sequence3.h"
#include "node1.h"
#include <cassert>

namespace data_structures_assignment3 {

    sequence::sequence() {
        // The empty list
        head_ptr = NULL;
        tail_ptr = NULL;
        precursor = NULL;
        cursor = NULL;
        many_nodes = 0;
    }

    sequence::sequence(const sequence& source) {

        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes; // Copies many_nodes
        // Also reinitialize the precursor and cursor. It can done through a simple while loop
        cursor = head_ptr; //Assume the cursor is the head pointer, then we can find where the current item is
        precursor = NULL; //Since cursor is head pointer, there is nothing before cursor
        node* temp = source.head_ptr;
        while(temp != NULL && temp != source.cursor) {
            temp = temp ->link();
            precursor = cursor;
            cursor = cursor ->link();
        }
    }

    sequence::~sequence() {
        // Resetting everything to the empty list and clearing the list
        head_ptr = NULL;
        tail_ptr = NULL;
        precursor = NULL;
        cursor = NULL;
        list_clear(head_ptr);
        many_nodes = 0;
    }

    void sequence::start() {

        cursor = head_ptr;
        precursor = NULL;
    }

    void sequence::advance() {
        // Advance cursor and precursor only if list is not empty
        assert(is_item());

        if (cursor == tail_ptr) { // When we are at the end
            precursor = cursor;
            cursor = NULL;
        } else {
            precursor = cursor;
            cursor = cursor->link();
        }
    }

    void sequence::insert(const value_type& entry) {

        if(cursor == NULL || cursor == head_ptr) { // If we want to insert at head (will need to reinitialize head)
            list_head_insert(head_ptr,entry);
            cursor = head_ptr;
            precursor = NULL;
        } else { // Using the list_insert function from the node class to insert anywhere else
            list_insert(precursor,entry);
            cursor = precursor->link();
        }
        many_nodes++; // Recalculate the length of the list (increases by one)
        tail_ptr = list_locate(head_ptr, many_nodes); // Reposition tail_ptr after inserting
    }

    void sequence::attach(const value_type &entry) {

        if (head_ptr == NULL) { // If we want to insert at head (will need to reinitialize head)
            list_head_insert(head_ptr,entry);
            cursor = head_ptr;
        }
        else if (cursor == NULL) { // When at end of the list
            list_insert(precursor,entry);
            cursor = precursor->link();
        } else { // Using the list_insert function from the node class to insert anywhere else
            list_insert(cursor,entry);
            precursor = cursor;
            cursor = cursor->link();
        }
        many_nodes++; // Recalculate the length of the list (increases by one)
        tail_ptr = list_locate(head_ptr, many_nodes); // Reposition tail_ptr after attaching
    }

    void sequence::operator =(const sequence& source) {

        if (this == &source) return; // If they are already equal
        // Otherwise, copy many_nodes from the source
        list_copy(source.head_ptr, head_ptr, tail_ptr); // Copies everything from source
        many_nodes = source.many_nodes; // Sets many_nodes equal to many_nodes of source
    }


    void sequence::remove_current() {

        assert(is_item());

        if (cursor == head_ptr && cursor->link() != NULL) { // If current is the first node
            cursor = head_ptr;
            precursor = NULL;
        }
        else if (cursor == head_ptr && cursor->link() == NULL) { // If the list is empty or has one element
            cursor = NULL;
            precursor = NULL;
        }
        else { // For all other cases
            cursor = precursor->link();
        }
        many_nodes--; // Recalculate the length of the list (reduces by one)
        tail_ptr = list_locate(head_ptr, many_nodes);
        return;
    }

    sequence::value_type sequence::current() const {
        // Precondition: is_item( ) returns true.
        // Postcondition: The item returned is the current item on the sequence.
        assert(is_item());
        return cursor->data();
    }

    size_t sequence::size() const {
        // Postcondition: The return value is the number of items on the sequence.
        return list_length (head_ptr);
    }

    bool sequence::is_item() const {
        // Postcondition: A true return value indicates that there is a valid
        // "current" item that may be retrieved by activating the current
        // member function (listed below). A false return value indicates that
        // there is no valid current item.
        if (cursor == NULL) return false;
        // If head_ptr is NULL, the list is empty, thus return false
        return true;
    }
}
