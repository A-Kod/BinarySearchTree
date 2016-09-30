SCENARIO("if element is (or not) in tree, insert method must return false (or true)") 
{
    GIVEN("tree")
    {
        BinarySearchTree<int> tree({1, 2, 3, 4});
        WHEN("insert element")
        {
            THEN("sizes must be equal")
            {
                REQUIRE(!tree.insert(1));
                REQUIRE(tree.insert(0));
            }
        }
    }
}

SCENARIO("if element is (or not) in tree, size must increase by one (or not change)") 
{
    GIVEN("tree, its size")
    {
        BinarySearchTree<int> tree({1, 2, 3, 4});
        size_t size = tree.size();
        WHEN("insert element that is not in the tree")
        {
            tree.insert(5);
            THEN("sizes must increase by one")
            {
                REQUIRE(tree.size() == size + 1);
            }
        }
        WHEN("insert element that is in the tree")
        {
            tree.insert(3);
            THEN("sizes must be equal")
            {
                REQUIRE(tree.size() == size);
            }
        }
    }
}
