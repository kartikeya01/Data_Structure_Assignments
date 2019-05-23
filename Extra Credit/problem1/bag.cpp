#include <algorithm>
#include <cassert>
#include "bag.h"

using std::copy;

namespace data_structures_assignment_extra
{
    bag::size_type bag::erase(const value_type& target)
    {
        size_type index = 0;
        size_type many_removed = 0;

        while (index < used)
        {
            if (data[index] == target)
            {
                --used;
                data[index] = data[used];
                ++many_removed;
            }
            else
                ++index;
        }

        return many_removed;
    }

    bool bag::erase_one(const value_type& target)
    {
        size_type index;
        index = 0;
        while ((index < used) && (data[index] != target))
            ++index;

        if (index == used)
            return false;
        --used;
        data[index] = data[used];
        return true;
    }

    void bag::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        data[used] = entry;
        ++used;
    }

    void bag::operator+=(const bag& addend)
    {
        assert(size() + addend.size() <= CAPACITY);

        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;
    }

    bag::size_type bag::count(const value_type& target) const
    {
        size_type answer;
        size_type i;

        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }

    bag operator+(const bag& b1, const bag& b2)
    {
        bag answer;

        assert(b1.size() + b2.size() <= bag::CAPACITY);

        answer += b1;
        answer += b2;
        return answer;
    }

    bag intersection(bag b1, bag b2)
    // Intersection should return a bag which contains the items which are in
    // both parameter bags. If there is a repeat, to be included in the new
    // bag, the repeat must be included in both parameter bags. This means the
    // intersection of a bag containing [1,2,2,3] and [2,2,2,3,4] should be [2,2,3]
    {
        bag intersection_bag;

        for (int i =0; i < b1.size(); i++) {
            for (int j = 0; j < b2.size(); j++) {

            }
        }

        return bag(); // This line is incorrect, but allows compiling. Delete it and write your own.
    }

    bag disjunctive_union(bag b1, bag b2)
    // Disjunctive_union should create a new bag which contains the items that
    // are in one bag but not both. If there is a repeat, and one bag contains more
    // than one copy that the other bag does not, this should be included in the
    // disjunctive union. This means the disjunctive union of a bag containing
    // [1,2,2,3] and [2,2,2,3,4] should be [1,2,4]
    {
        bag disjunctive_union_bag;

        return bag(); // This line is incorrect, but allows compiling. Delete it and write your own.
    }
}
