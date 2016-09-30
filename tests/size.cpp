SCENARIO( "size of empty tree must be equal 0" ) {

    GIVEN( "empty tree" ) 
    {
        BinarySearchTree <int> tree;

        WHEN( "decide size" ) 
        {

            THEN( "size of empty tree must be equal 0" ) 
            {
                REQUIRE( tree.size() == 0 );
            }
        }
        WHEN( "new tree" ) 
        {
            tree ({1,2,3,4,5});

            THEN( "the size changed" ) 
            {
                REQUIRE( v.size() != 0 );
            }
        }
        
    }
}
