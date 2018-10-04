#include <cassert> //Provides assert
#include <cstdio>
#include "sequence1.h" //Provides the sequence1 class definition

namespace data_structures_assignment_2
{
    sequence::sequence() {
        used = 0; // Tells us that the sequence is empty
        current_index = 0; // Initializes the value for the
    }

    void sequence::start() {
        if (used > 0) current_index = 0; // First item on the non-empty sequence
                                         // becomes the current item
    }

    void sequence::advance() {
        assert(is_item()); // Precondition: is_item() returns true

        if (current_index == used) current_index = 0; // If the current item was already
                                                      // the last item in the sequence,
                                                      // then there is no longer
                                                      // any current item

        else current_index++; // Otherwise, the new current item is the item
                              // immediately after the original current item
    }

    void sequence::insert(const value_type& entry) {
        // Postcondition: A new copy of entry has been inserted in the sequence
        // before the current item. If there was no current item, then the new entry
        // has been inserted at the front of the sequence. In either case, the newly
        // inserted item is now the current item of the sequence.

        assert(size() < CAPACITY); // Precondition: size() < CAPACITY

        if (is_item()) {                                            // If there is a valid size_type in the next iteration
            for (size_type i = used; i > current_index; i--) {      // Go backwards from the array so the next value isn't
                data[i] = data[i-1];                                // affected by the previous value
            }                                                       // All the data is shifted up one
            used++;
            data[current_index] = entry;
        }
        else {
            for (size_type j = used; j > 0; j--) {
                data[j] = data[j-1];                // the new entry has been inserted at the front of the sequence
            }
            // In either case, the newly inserted item is now the current item of the sequence
            used++;
            current_index = 0;
            data[current_index] = entry;
        }
    }

    void sequence::attach(const value_type& entry) {

        assert(size() < CAPACITY); // Precondition: size() < CAPACITY

        if (is_item()) {                                                // If there is a valid size_type in the next iteration
            for (size_type i = used; i > current_index + 1; i--) {      // Go backwards from the array so the next value isn't
                data[i] = data[i-1];                                    // affected by the previous value
            }                                                           // All the data is shifted up one
            used++; // Value of used is increased by one since we have inserted "entry"
            current_index++;
            data[current_index] = entry; // The newly inserted item is now the current item of the sequence
        }
        else {
            // If there was no current item, then the new entry has been
            // attached to the end of the sequence
            used++;
            current_index = used - 1;
            data[current_index] = entry; // The newly inserted item is now the current item of the sequence
        }
    }

    void sequence::remove_current() {
        assert(is_item()); // Precondition: is_item() returns true

        for (size_type i = current_index; i < used - 1; i++) { // Shifting data left by one iteration,
            data[i] = data[i + 1];                             // starting at current_index and ending
        }                                                      // at the second last index of data

        used--; // Decrease the used size of the array by one
                // since you are removing the current_index
    }

    sequence::size_type sequence::size() const {
        return used; // # of items in the sequence
    }

    bool sequence::is_item() const {
        if (current_index < used) return true; // If the current_index is smaller
                                               // than the size of the sequence,
                                               // we know that there is a valid
                                               // size_type in the next iteration

        else return false; // A false return value indicates that
                           // there is no valid current item
    }

    sequence::value_type sequence::current() const {
        assert(is_item()); // Precondition: is_item() returns true
        return data[current_index]; // Looks at the current_index value in the array: data
    }

}
