#include <iostream>
#include <vector>
#include <fstream>
//#include "../include/BinarySearchTree.h"
#include "../source/BinarySearchTree.cpp"

int main() {


        // создаем дерево с помощью списка инициализации
        BinarySearchTree<int> tree({5, 2, 1, 3, 6, 7});

        // выводим дерево на печать
        std::cout << tree << std::endl;


        // количество узлов дерева
        std::cout << "Range of tree - " << tree.size() << std::endl;

        try {
        tree.find(1);
        }
        catch (std::logic_error &e) {
            std::cout << e.what();
        }

        try {
        tree.insert(9);
        }

        catch (std::logic_error &e) {
        std::cout << e.what();
        }

        int del;
        std::cout << "Input deleting element: ";
        std::cin >> del;

        try {
        if (tree.remove_helper(del)) {
            std::cout << "The element is deleted" << std::endl;
        }
        }

        catch (std::logic_error &e) {
        std::cout << e.what();
        }

        // выводим дерево на печать
        std::cout << tree << std::endl;
        std::cout << "Range of tree - " << tree.size() << std::endl;

        std::getchar();



    return 0;
}




