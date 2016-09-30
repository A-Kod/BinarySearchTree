#include "../include/BinarySearchTree.h"
#include "catch.hpp"

SCENARIO( "size of empty tree must be equal 0" ) {

    GIVEN( "empty tree" ) 
    {
        BinarySearchTree <int> tree1;

        WHEN( "decide size" ) 
        {

            THEN( "size of empty tree must be equal 0" ) 
            {
                REQUIRE( tree1.size() == 0 );
            }
        }
        WHEN( "new tree" ) 
        {
            BinarySearchTree <int> tree2 ({1,2,3,4,5});

            THEN( "the size changed" ) 
            {
                REQUIRE( tree2.size() != 0 );
            }
        }
        
    }
}


/*SCENARIO("size of empty tree must be equal 0") {
    GIVEN("empty tree") {
        BinarySearchTree<int> tree;
        WHEN("decide size") {
            THEN("size must be equal 0") {
                REQUIRE(tree.size() == 0);
            }
        }
    }
}
SCENARIO("size of non-empty tree must not be equal 0") {
    GIVEN("non-empty tree") {
        BinarySearchTree<int> tree({1, 2, 3, 4, 5});
        WHEN("decide size") {
            THEN("size must not be equal 0") {
                REQUIRE(tree.size() != 0);
            }
        }
    }
}
*/
SCENARIO("size of constant tree must be equal to size of non-constant tree") {
    GIVEN("constant and non-constant trees")
    {
        const BinarySearchTree<int> tree1({1, 2, 3, 4});
        BinarySearchTree<int> tree2({5, 6, 7, 8});
        WHEN("compare sizes")
        {
            THEN("sizes must be equal")
            {
                REQUIRE(tree1.size() == tree2.size());
            }
        }
    }
}
