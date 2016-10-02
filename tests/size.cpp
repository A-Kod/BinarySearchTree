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

