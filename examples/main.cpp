#include <iostream>
#include <vector>
#include <fstream>

#include "BinarySearchTree.cpp"

int main() {

    // создаем дерево с помощью списка инициализации
    BinarySearchTree <int> tree ({1,2,3,4,5});

    // читаем новый элемент дерева
    std::cin >> tree;

    // выводим дерево на печать
    std::cout << tree << std::endl;

    // использование контструктора копирования
    BinarySearchTree <int> second = tree;
    std::cout << second << std::endl;

    // выводим дерево в файл
    std::ofstream out("D:\\output.txt");
    out << second;

    std::getchar();
    std::getchar();

    return 0;
}
