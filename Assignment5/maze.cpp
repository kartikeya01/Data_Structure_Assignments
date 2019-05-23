#include "maze.h"
#include <cassert>

namespace data_structures_assignment_5
{
    maze_node::maze_node(maze_node* left, maze_node* right, bool init_finish)
    {
        left_ptr = left;
        right_ptr = right;
        finish = init_finish;
    }
    maze_node::~maze_node()
    {
        delete right_ptr;
        delete left_ptr;
    }

    maze::maze(int maze_number)
    {
        assert(maze_number == 0 || maze_number == 1);
        if(maze_number == 0)
        {
            build_maze0();
        }
        else if(maze_number == 1)
        {
            build_maze1();
        }
    }

    maze_node* maze::get_start()
    {
        return start_node_ptr;
    }

    void maze::build_maze0()
    {
        maze_node* node_ptr0;
        maze_node* node_ptr1;
        maze_node* node_ptr2;
        maze_node* node_ptr3;
        maze_node* node_ptr4;
        maze_node* node_ptr5;
        maze_node* node_ptr6;
        maze_node* node_ptr7;
        maze_node* node_ptr8;
        node_ptr8 = new maze_node(nullptr, nullptr, true);
        node_ptr7 = new maze_node(nullptr, nullptr);
        node_ptr6 = new maze_node(nullptr, node_ptr7);
        node_ptr5 = new maze_node(nullptr, nullptr);
        node_ptr4 = new maze_node(node_ptr8, nullptr);
        node_ptr3 = new maze_node(nullptr, nullptr);
        node_ptr2 = new maze_node(node_ptr6, node_ptr5);
        node_ptr1 = new maze_node(node_ptr4, node_ptr3);
        node_ptr0 = new maze_node(node_ptr2, node_ptr1);
        start_node_ptr = node_ptr0;
    }

    void maze::build_maze1()
    {
        maze_node* node_ptr0;
        maze_node* node_ptr1;
        maze_node* node_ptr2;
        maze_node* node_ptr3;
        maze_node* node_ptr4;
        maze_node* node_ptr5;
        maze_node* node_ptr6;
        node_ptr6 = new maze_node(nullptr, nullptr, true);
        node_ptr5 = new maze_node(node_ptr6, nullptr);
        node_ptr4 = new maze_node(nullptr, nullptr);
        node_ptr3 = new maze_node(nullptr, nullptr);
        node_ptr2 = new maze_node(node_ptr4, node_ptr5);
        node_ptr1 = new maze_node(nullptr, node_ptr3);
        node_ptr0 = new maze_node(node_ptr2, node_ptr1);
        start_node_ptr = node_ptr0;
    }

    maze::~maze()
    {
        delete start_node_ptr;
    }
}
