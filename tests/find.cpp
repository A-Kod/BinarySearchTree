#include "../include/BinarySearchTree.h"
#include "../source/BinarySearchTree.cpp"
#include "catch.hpp"

SCENARIO("if obj is in tree") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree({1, 2, 3, 4, 5});
        WHEN("find") 
        {
            THEN("return pointer to element must not be nullptr") 
            {
                REQUIRE(*(tree.find(3)) == 3);
            }
        }
    }
    GIVEN("tree")
    {
        BinarySearchTree<int> tree({1, 2, 3, 4, 5});
        WHEN("find") 
        {
            THEN("must throw error")
            {
                REQUIRE_THROWS_AS( tree.find(7), bst_error );
            }
        }
    }    
    GIVEN("constant tree") 
    {
        const BinarySearchTree<int> tree1({1, 2, 3});
        WHEN("find") 
        {
            THEN("return element for constant tree") 
            {
                REQUIRE(tree1.find(1));
            }
        }
    }    
}

