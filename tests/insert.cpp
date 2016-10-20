#include "../include/BinarySearchTree.h"
#include "../source/BinarySearchTree.cpp"
#include "catch.hpp"

SCENARIO("if obj is in tree, insert must return false") 
{
    GIVEN("tree")
    {
        BinarySearchTree<int> tree({1, 2, 3, 4});
        WHEN("insert element")
        {
            THEN("must throw error")
            {
                REQUIRE_THROWS_AS( tree.insert(1), std::logic_error );
            }
        }
    }

    GIVEN("tree, its size")
    {
        BinarySearchTree<int> tree({1, 2, 3, 4});
        size_t size = tree.size();
        WHEN("insert neue obj")
        {
            tree.insert(5);
            THEN("size must increase")
            {
                REQUIRE(tree.size() == (size + 1));
            }
        }


    }    
}
