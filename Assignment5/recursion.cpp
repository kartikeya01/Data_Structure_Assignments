#include <iostream>
#include <cassert>
#include "maze.h"

using std::ostream;
using data_structures_assignment_5::maze;
using data_structures_assignment_5::maze_node;

void triangle(ostream& outs, unsigned int m, unsigned int n)
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/
{
    if (m <= n) {
        std::string asterisks = std::string(m, '*'); // Populates the asterisks string with * (m times)
        std::cout << asterisks << std::endl; // Prints it out and ends line
        triangle(std::cout, m + 1, n); // increases m by 1 so we can print a bigger string (n long)
        std::cout << asterisks << std::endl; // completes the reverse order
    }
}

int count_ways_to_step(int number_of_stepping_stones)
// Precondition: number_of_stepping_stones > 0
// Postcondition: The number of ways to reach the final stepping stone using
// either a small step (moving 1 stepping stone) or a large step (moving 2 stepping
// stones) in any combination is returned.
// For 3 stepping stones there are 3 ways. For 4 stepping stones, there are 5 ways.
{
    // Similar to Fibonacci Sequence

    assert(number_of_stepping_stones > 0);

    if (number_of_stepping_stones == 1) return 1;
    if (number_of_stepping_stones == 2) return 2;


    return count_ways_to_step(number_of_stepping_stones - 2) + count_ways_to_step(number_of_stepping_stones - 1);

// ITERATIVE
//    int one = 1;
//    int two = 2;
//    int next;
//
//    if (number_of_stepping_stones == 1) return one;
//    if (number_of_stepping_stones == 2) return two;
//
//    for ( int i = 2 ; i < number_of_stepping_stones ; i++ ) {
//
//        next = one + two;
//        one = two;
//        two = next;
//    }
//
//    return next;

}

bool print_path_through_maze(const maze_node* maze_position)
// Postcondition: Prints the path through the maze, with 0s representing right
// turns and 1s representing left turns.
// You may print the path in reverse order (this will be easier).
// Hint: Use the return boolean to signify that the current path is the correct path.
{
    maze a;
    maze_node b;
    // creating objects of the maze and maze_node class

    maze_node* cursor = a.get_start();

    // Base case
    if (cursor == NULL) return false; // If the tree has no paths

    // Base case
    if (cursor == maze_position) return true; // If maze_position is already the root node, no need to traverse. Return true

    // I believe I have the basic idea down but i can't get it to work.
    // If maze_position is present in either left or right subtree of this node,
    // then print this node.
    if (print_path_through_maze(cursor->left()) || print_path_through_maze(cursor->right())) {
        return true;
    }
    // if the left node is the maze_position, then print 0
    // if the right node is the maze_position, then print 1
    if (cursor->left() == maze_position) std::cout << "0";
    if (cursor->right() == maze_position) std::cout << "1";

    std::cout << "Check comments!" << std::endl;

    return false;
}

int main()
{
    // You can test your code by adding it here.
    //triangle(std::cout, 1, 6);
    std::cout << count_ways_to_step(4);

//    maze m1(0);
//    print_path_through_maze(m1.get_start());

    return 0;
}
