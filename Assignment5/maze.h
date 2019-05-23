// CLASS: maze_node
//
// CONSTRUCTOR for the maze_node class:
//   maze_node(maze_node* right = nullptr, maze_node* left = nullptr, bool init_finish = false)
//     Postcondition: A maze node has been constructed with the links and flag for if it is the end of the maze.
//
// DECONSTRUCTOR for the maze_node class:
//   ~maze_node()
//     Postcondition: Deletes the node's children.
//
// MEMBER FUNCTIONS for the maze_node class:
//   const maze_node* left() const
//     Postcondition: Returns the node following the left path from this node.
//
//   const maze_node* right() const
//     Postcondition: Returns the node following the right path from this node.
//
//   bool is_finish() const
//     Postcondition: Returns whether or not this node is the end of maze.
//
//
// CLASS: maze
//
// CONSTRUCTOR for the maze class:
//   maze(int maze_number)
//     Precondition: Must be an available maze number (only 0 and 1 are provided by default).
//     Postcondition: Builds the maze for the maze number specified.
//
// DECONSTRUCTOR for the maze class:
//   ~maze()
//     Postcondition: Deletes the maze nodes.
//
// MEMBER FUNCTIONS for the maze class:
//   const maze_node* get_start() const
//     Postcondition: Gets the first node in the maze.
//

#ifndef DATA_STRUCTURES_ASSIGNMENT_5_MAZE_H
#define DATA_STRUCTURES_ASSIGNMENT_5_MAZE_H

namespace data_structures_assignment_5
{
    class maze_node
    {
    public:
        maze_node(maze_node* right = nullptr, maze_node* left = nullptr, bool init_finish = false);
        ~maze_node();
        const maze_node* left() const { return left_ptr; };
        const maze_node* right() const { return right_ptr; };
        bool is_finish() const { return finish; };
    private:
        maze_node* left_ptr;
        maze_node* right_ptr;
        bool finish;
    };

    class maze
    {
    public:
        maze(int maze_number = 0);
        ~maze();
        maze_node* get_start();
    private:
        maze_node* start_node_ptr;
        void build_maze0();
        void build_maze1();
    };
}

#endif //DATA_STRUCTURES_ASSIGNMENT_5_MAZE_H
