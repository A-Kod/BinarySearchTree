#include <iostream>
#include <vector>
#include <fstream>
//#include "../include/BinarySearchTree.h"
#include "../source/BinarySearchTree.cpp"

int main() {

    // создаем дерево с помощью списка инициализации
    BinarySearchTree <int> tree ({1,2,3,4,5});

    // читаем новый элемент дерева
    std::cin >> tree;

    // выводим дерево на печать
    std::cout << tree << std::endl;

    // количество узлов дерева
    std::cout << "Range of first tree - " << tree.size() << std::endl;

    // читаем дерево из файла
    BinarySearchTree <int> second;
    std::ifstream in("D:\\input.txt");

    in >> second;
    std::cout << second << std::endl;

    if(tree==second)
        std::cout<<"Trees are equal"<<std::endl;

    else std::cout<<"Trees are not equal" <<std::endl;


    // использование контструктора перемещения
    BinarySearchTree <int> third (std::move(second));
    std::cout << third << std::endl;

    // количество узлов 2 дерева после использования конструктора перемещения
    std::cout << "Range of second tree - " << second.size() << std::endl;

    std::getchar();
    std::getchar();

    return 0;
}
