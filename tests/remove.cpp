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
            tree.remove(1);
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
        BinarySearchTree<int> tree2({1, 2, 3, 4, 5});
        WHEN("node without children")
        {
            tree1.remove(5);
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
        BinarySearchTree<int>({5, 2, 1}) tree1;
        BinarySearchTree<int>({5, 2}) tree2;
        WHEN("node with only left child")
        {
            tree1.remove(2);
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
        BinarySearchTree<int>({5, 2, 1, 3}) tree1;
        BinarySearchTree<int>({5, 2, 3}) tree2;
        WHEN("node with only right child")
        {
            tree1.remove(1);
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
        BinarySearchTree<int>({5, 2, 1, 3, 6, 7}) tree1;
        BinarySearchTree<int>({5, 1, 3, 6, 7}) tree2;
        WHEN("node with both children")
        {
            tree1.remove(2);
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
        BinarySearchTree<int>({5}) tree1;
        BinarySearchTree<int>() tree2;
        WHEN("remove root")
        {
            tree1.remove(8);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
        }
      }
}

SCENARIO("we must get two same trees_6")
{
        GIVEN("two trees")
        {
        BinarySearchTree<int>({1, 2, 3, 4, 5}) tree1;
        BinarySearchTree<int>({1, 2, 3, 4, 5}) tree2;
        WHEN("remove node that doesn't exist")
          {
            tree1.remove(-1);
            THEN("trees must be equal")
            {
                REQUIRE(tree1 == tree2);
            }
          }
        }
}