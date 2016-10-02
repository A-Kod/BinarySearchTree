#include "../include/BinarySearchTree.h"
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
}

SCENARIO("if obj is not in tree") 
{
    GIVEN("tree") 
    {
        BinarySearchTree<int> tree({1, 2, 3, 4, 5});
        WHEN("find") 
        {
            THEN("return pointer to element must be nullptr") 
            {
                REQUIRE(tree.find(7) == nullptr);
            }
        }
    }
}

SCENARIO("find method must work for constant tree and non-constant tree") 
{
    GIVEN("constant and non-constant tree") 
    {
        const BinarySearchTree<int> tree1({1, 2, 3});
        BinarySearchTree<int> tree2{4, 5, 6};
        WHEN("find") 
        {
            THEN("return element for constant and non-constant tree") 
            {
                REQUIRE((tree1.find(1)) && (tree2.find(4)));
            }
        }
    }
}
