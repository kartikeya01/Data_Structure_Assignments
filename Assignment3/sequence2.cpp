#include "sequence2.h" // Provides sequence2 class definition
#include <algorithm>   // Provides copy function
#include <cassert>     // Provides assert function
using namespace std;

namespace data_structures_assignment_3
{
    sequence::sequence(size_type initial_capacity) {

        data = new value_type[initial_capacity]; // Since the sequence class is dynamically
        // implemented, data is stored in the heap
        // Initialize all the private variables

        capacity = initial_capacity;
        used = 0;
        current_index = 0;


    }

    sequence::sequence(const sequence &source) {
        // The copy constructor. It makes a copy of the capacity, used, current_index, and data
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        copy(source.data, source.data + used, data); // From the <algorithm> library

    }

    sequence::~sequence() {
        delete [] data; // Deallocate data - which is stored in the heap
    }

    void sequence::resize(size_type new_capacity) {

        assert(new_capacity > 0);

        if (new_capacity == used) return; // Handle the redundant cases

        else if (new_capacity > used) {                                          // Sequence should only resize if it has less
                                                        // items than current, or used
            value_type *new_data;                       // Declare a new array: new_data
            new_data = new value_type[new_capacity];    // Point new_data to the heap and allocate
                                                        // it the same size as the resize parameter
            copy(data, data + used, new_data);          // Copy the contents of data into new_data
            delete[] data;                              // Delete or clear data from the heap
            data = new_data;                            // Re-initialize data as new_data
            capacity = new_capacity;                    // Give data the capacity of new_capacity
        }
    }

    void sequence::insert(const value_type& entry) {

        if( size() >= capacity )
            resize(capacity * 1.1);     // Resize the array by 10% if capacity is too small

        if (is_item()) {                                            // If there is a valid size_type in the next
            for (size_type i = used; i > current_index; i--) {      // iteration, go backwards from the array
                data[i] = data[i-1];                                // so the next value isn't affected by the
            }                                                       // previous value. All the data is shifted up one
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

        if( size() >= capacity )
            resize(capacity * 1.1);     // Resize the array by 10% if capacity is too small

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


    void sequence::start() {
        if (used >= 0) current_index = 0; // First item on the non-empty sequence
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

    void sequence::operator=(const sequence& source) {


        if (capacity != source.capacity) {       // Make a new array on heap to copy contents
            value_type *new_data;                // to source
            new_data = new value_type[source.capacity];
            delete[] data;
            data = new_data;
            capacity = source.capacity;
        }
        // Similar to the copy constructor
        used = source.used;
        current_index = source.current_index;
        copy(source.data, source.data + source.used, data); // From the <algorithm> library
    }

}
