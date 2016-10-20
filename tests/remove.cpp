#include "../include/BinarySearchTree.h"
#include "../source/BinarySearchTree.cpp"
#include "catch.hpp"

SCENARIO("size decrease")
{
    GIVEN("tree")
    {
        BinarySearchTree<int> tree({1, 2, 3, 4, 5});
        WHEN("delete element")
        {
            tree.remove_helper(1);
            THEN("")
            {
                REQUIRE((tree.size()) == 4);
            }
        }
    }
}

SCENARIO("we must get two same trees_1")
{
    GIVEN("two trees")
    {
        BinarySearchTree<int> tree1({1, 2, 3, 4, 5});
        BinarySearchTree<int> tree2({1, 2, 3, 4});
        WHEN("node without children")
        {
            tree1.remove_helper(5);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
        }
     }
}     

SCENARIO("we must get two same trees_2")
{
    GIVEN("two trees")
    {
        BinarySearchTree<int>tree1({5, 2, 1});
        BinarySearchTree<int>tree2({5, 1});
        WHEN("node with only left child")
        {
            tree1.remove_helper(2);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
        }
    }    
}

SCENARIO("we must get two same trees_3")
{
    GIVEN("two trees")
    {
        BinarySearchTree<int>tree1({5, 2, 1, 3});
        BinarySearchTree<int>tree2({5, 2, 3});
        WHEN("node with only right child")
        {
            tree1.remove_helper(1);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
        }
    }
}

SCENARIO("we must get two same trees_4")
{
      GIVEN("two trees")
      {
        BinarySearchTree<int>tree1({5, 2, 1, 3, 6, 7});
        BinarySearchTree<int>tree2({5, 1, 3, 6, 7});
        WHEN("node with both children")
        {
            tree1.remove_helper(2);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
        }
      }
}

SCENARIO("we must get two same trees_5")
{
      GIVEN("two trees")
      {
        BinarySearchTree<int>tree1({5,1,3});
        BinarySearchTree<int>tree2({1,3});
        WHEN("remove root")
        {
            tree1.remove_helper(5);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
        }
      }
}
/*
SCENARIO("we must get two same trees_6")
{
        GIVEN("two trees")
        {
        BinarySearchTree<int>tree1({1, 2, 3, 4, 5});
        BinarySearchTree<int>tree2({1, 2, 3, 4, 5});
        WHEN("remove node that doesn't exist")
          {
            tree1.remove_helper(0);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
          }
        }
}
*/
