#ifndef HASHFUNCTIONSTEST_H
#define HASHFUNCTIONSTEST_H

#include <cstddef>
#include <cassert>

namespace data_structures_assignment_extra
{
    template<class HashFunction>
    double hash_function_collision_test(HashFunction hash_function, int key_array[], std::size_t table_size)
    {
        bool* table_occupied;
        std::size_t collisions = 0;
        table_occupied = new bool[table_size];
        for (std::size_t i = 0; i < table_size; ++i)
        {
            table_occupied[i] = false;
        }
        for (std::size_t i = 0; i < table_size; ++i)
        {
            int hash_value = hash_function(key_array[i]);
            assert(hash_value < table_size);
            assert(hash_value >= 0);
            if (table_occupied[hash_value])
            {
                collisions++;
            }
            while (table_occupied[hash_value])
            {
                hash_value++;
                if (hash_value >= table_size)
                {
                    hash_value = 0;
                }
            }
            table_occupied[hash_value] = true;
        }
        return (double)collisions / (double)table_size;
    }
}

#endif