#include <iostream>
#include <vector>
#include <fstream>
//#include "../include/BinarySearchTree.h"
#include "../source/BinarySearchTree.cpp"

int main() {

    // создаем дерево с помощью списка инициализации
    BinarySearchTree <int> tree ({1,2,3,4,5});

    // выводим дерево на печать
     std::cout << tree << std::endl;


    // количество узлов дерева
    std::cout << "Range of tree - " << tree.size() << std::endl;

    int del;
    std::cout << "Input deleting element: ";
    std::cin >> del;


    if(tree.remove_el(del))
    {
        std::cout << "The element is deleted" << std::endl;
    }

    // выводим дерево на печать
    std::cout << tree << std::endl;
    std::cout << "Range of tree - " << tree.size() << std::endl;

    std::getchar();

    return 0;
}
