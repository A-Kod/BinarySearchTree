#include "catch.hpp"
#include "BinarySearchTree"
SCENARIO ("If object exists")
{
    GIVEN ("object")
    {
        BinarySearchTree <int> tree={1,2,3,4,5,6};
        int object=1;
        WHEN ("find it")
        {
            tree.find(object);
            THEN ("if it exists")
            {
                REQUIRE(tree.find(object)!= nullptr );
            }
        };

    }
}
SCENARIO ("If object doesn't exist")
{

    GIVEN("object")
    {
        BinarySearchTree <int> tree={1,2,3,4,5,6};
        int object=10;
            WHEN ("find it") {
                tree.find(object);
                THEN ("if doesn't exist")
                {
                    REQUIRE(tree.find(object)==nullptr);
                }
            }
    }
}

SCENARIO ("If const or non-const")
{
    GIVEN("object")
    {
        BinarySearchTree <int> t1={1,2,3,4,5};
        const BinarySearchTree <int> t2={1,2,3,4,5,6};
        int object=5;
        WHEN ("find it") {
            t1.find(object);
            t2.find(object);
            THEN ("if it exists")
            {
                REQUIRE(t1.find(object)!=nullptr);
                REQUIRE(t2.find(object)!= nullptr);
            }
            THEN ("if doesn't exist")
            {
                REQUIRE(t1.find(object)==nullptr);
                REQUIRE(t2.find(object)==nullptr);
            }
        }
    }
}
