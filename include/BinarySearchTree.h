#ifndef BST
#define BST

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

/*
class bst_error : public std::logic_error {
public:
    explicit bst_error (const std::string& what_arg) : std::logic_error(what_arg) {};
    explicit bst_error (const char* what_arg)  : std::logic_error(what_arg) {};
};
*/

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
    std::shared_ptr<Node> root_;
    size_t size_;

    struct Node {
        T value_;
        std::shared_ptr<Node> left_;
        std::shared_ptr<Node> right_;

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

    auto low_level(std::shared_ptr<Node> nd, std::vector<T>& v) -> void;                             // найти все элемента ниже текущего
    auto remove_el(const T value) -> bool;                                                           // удаление элемента из дерева
    auto Insert_copy (std::shared_ptr<Node> nd) noexcept -> void;                                    // для конструктора копирования
    auto Clean (std::shared_ptr<Node>  nd) noexcept -> void;                                         // для деструктора
    auto Root() const noexcept -> std::shared_ptr<Node>;                                             // корень дерева
    auto Print (std::ostream & out,std::shared_ptr<Node> nd,int level) const noexcept -> void;       // распечатать дерево
    auto Print_file (std::ofstream & out,std::shared_ptr<Node> nd,int level) const noexcept -> void; // распечатать дерево
    auto size() noexcept -> size_t;                                                                  // определение размера
    auto size_const() const noexcept -> size_t;
    auto insert(const T & value) throw(std::logic_error) -> bool;                                                   // вставка нового звена
    auto find(const T& value) const throw(std::logic_error) -> T*;                                                  // поиск элемента
    auto find_node(const T& value) const noexcept -> std::shared_ptr<Node>;                          // поиск элемента
    auto operator = (const BinarySearchTree<T> & tree) -> BinarySearchTree<T> &;                     // оператор присваивания
    auto operator = (BinarySearchTree<T> && tree) -> BinarySearchTree<T> &;                          // оператор перемещения

    auto insert_rec(std::shared_ptr<Node> nd, const T& value) noexcept->void;
    auto is_equal(std::shared_ptr<Node> nd,const BinarySearchTree<T> & tree) const noexcept->bool;
    auto remove(const T& value) noexcept -> bool;
    auto remove_helper(const T& value) throw(std::logic_error) -> bool;


    friend auto operator >> <> (std::istream& in, BinarySearchTree<T>& tree)->std::istream&;
    friend auto operator << <> (std::ostream& out, const BinarySearchTree<T>& tree)->std::ostream&;
    friend auto operator >> <> (std::ifstream& in, BinarySearchTree<T> & tree)->std::ifstream&;
    friend auto operator << <> (std::ofstream& out, const BinarySearchTree<T> & tree)->std::ofstream&;

    auto operator == (const BinarySearchTree& tree) -> bool;
};

#endif BST

