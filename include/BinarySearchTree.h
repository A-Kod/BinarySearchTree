#ifndef BST
#define BST

#include <iostream>
#include <vector>
#include <fstream>



template <typename T>
class BinarySearchTree;

template <typename T>
auto operator >> (std::istream& in, BinarySearchTree<T>& tree) ->std::istream&;

template <typename T>
auto operator << (std::ostream& out, const BinarySearchTree<T>& tree) ->std::ostream&;

template <typename T>
auto operator >> (std::ifstream& in, BinarySearchTree<T>& tree) ->std::ifstream&;

template <typename T>
auto operator << (std::ofstream& out, const BinarySearchTree<T>& tree) ->std::ofstream&;

template <typename T>
class BinarySearchTree {

private:
    struct Node;
    Node * root_;
    size_t size_;

    struct Node {
        T value_;
        Node * left_;
        Node * right_;

        Node(T value) : value_(value), left_(nullptr), right_(nullptr) {}

        Node (const Node & nd)
        {
            this->value_ = nd.value_;
            this->right_ = nd.right_;
            this->left_ = nd.left_;
        }
    };

public:
    BinarySearchTree();                                                              // конструктор по умолчанию
    BinarySearchTree(const std::initializer_list<T> & list);                         // конструктор, использующий список инициализации
    BinarySearchTree(const BinarySearchTree<T> & tree);                              // конструктор копирования
    BinarySearchTree(BinarySearchTree<T> && tree);                                   // конструктор перемещения
    ~BinarySearchTree();                                                             // деструктор

    auto Insert_copy (Node *nd) noexcept -> void;                                    // для конструктора копирования
    auto Clean (Node *nd) const noexcept -> void;                                    // для деструктора
    auto Root() const noexcept -> Node*;                                             // корень дерева
    auto Print (std::ostream & out,Node* nd,int level) const noexcept -> void;       // распечатать дерево
    auto Print_file (std::ofstream & out,Node* nd,int level) const noexcept -> void; // распечатать дерево
    auto size() noexcept -> size_t;                                                  // определение размера
    auto size_const() const noexcept -> size_t;
    auto insert(const T & value) noexcept -> bool;                                   // вставка нового звена
    auto find(const T & value) const noexcept -> const T*;
    //auto find(const T & value) const noexcept -> Node*;                            // поиск элемента
    auto operator = (const BinarySearchTree<T> & tree) -> BinarySearchTree<T> &;     // оператор присваивания
    auto operator = (BinarySearchTree<T> && tree) -> BinarySearchTree<T> &;          // оператор перемещения

    auto insert_rec(Node*& nd, const T& value) noexcept->void;
    auto is_equal(Node* nd,const BinarySearchTree<T> & tree) const noexcept->bool;


    friend auto operator >> <> (std::istream& in, BinarySearchTree<T>& tree)->std::istream&;
    friend auto operator << <> (std::ostream& out, const BinarySearchTree<T>& tree)->std::ostream&;
    friend auto operator >> <> (std::ifstream& in, BinarySearchTree<T> & tree)->std::ifstream&;
    friend auto operator << <> (std::ofstream& out, const BinarySearchTree<T> & tree)->std::ofstream&;

    auto operator == (const BinarySearchTree& tree) -> bool;
};

#endif BST
