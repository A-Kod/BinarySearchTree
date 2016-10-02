#include "../include/BinarySearchTree.h"

#include <iostream>
#include <vector>
#include <fstream>


// конструктор по умолчанию
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root_ = nullptr;
    size_ = 0;
}

// конструктор, использующий список инициализации
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const std::initializer_list<T> & list)
{
    root_ = nullptr;
    size_ = 0;

    // проходим по всему списку инициализации, используя функцию вставки в дерево
    for (auto x : list){
        insert(x);
    }
}

// конструктор копирования
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> & tree)
{
    delete root_;
    root_ = nullptr;
    size_ = 0;

    Insert_copy (tree.Root());
}

// конструктор перемещения
template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> && tree) : size_(tree.size_), root_(tree.root_)
{
    tree.root_ = nullptr;
    tree.size_ = 0;
}

// деструктор
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    Clean(root_);
}

template <typename T>
auto BinarySearchTree<T>::Insert_copy (Node *nd) noexcept -> void
{
    if(nd == nullptr)
        return ;

    insert(nd->value_);

    if(nd->left_)
    {
        Insert_copy(nd->left_);
    }

    if(nd->right_)
    {
        Insert_copy(nd->right_);
    }

}

template <typename T>
auto BinarySearchTree<T>::Clean (Node *nd) const noexcept -> void
{
    if(nd == nullptr)
        return ;

    if(nd->left_)
    {
        Clean(nd->left_);
        nd->left_ = nullptr;
    }

    if(nd->right_)
    {
        Clean(nd->right_);
        nd->right_ = nullptr;
    }
    delete nd;
}

// корень дерева
template <typename T>
auto BinarySearchTree<T>::Root() const noexcept -> Node*
{
    return root_;
}

template <typename T>
auto BinarySearchTree<T>::Print (std::ostream & out,Node* nd,int level) const noexcept -> void
{
    // если дерево пустое, то выходим
    if (nd== nullptr)
        return ;
    else
    {
        // левое поддерево
        Print(out,nd->right_,++level); // правое поддерево

        for (int i=0; i<level; ++i)
            out << "|";
        out << nd->value_<< "\n";
        level--;

        Print(out,nd->left_,++level);

    }

}

template <typename T>
auto BinarySearchTree<T>::Print_file(std::ofstream & out,Node* nd,int level) const noexcept -> void
{
    // если дерево пустое, то выходим
    if (nd== nullptr)
        return;
    else
    {
        out << nd->value_<< "\n";

        // левое поддерево
        Print_file(out,nd->left_,++level);
        level--;
    }
    Print_file(out,nd->right_,++level); // правое поддерево
}


// количество узлов дерева
template <typename T>
auto BinarySearchTree<T>::size() noexcept -> size_t
{
    return size_;
}


template <typename T>
auto BinarySearchTree<T>::size_const() const noexcept -> size_t
{
    return size_;
}

// вставка элемента в дерево
template <typename T>
auto BinarySearchTree<T>:: insert(const T & value) noexcept -> bool
{

    // если дерево пустое - создаем корень
    if (root_== nullptr)
    {
        root_ = new Node (value);
        size_ = 1;
        return true;
    }

    // создаем указатель, который будет двигаться по дереву
    Node* current (root_);

    while (1)
    {
        if(value==current->value_)
        {
            return false;
        }

        if(value>current->value_)
        {
            // если дошли до необходимого места вставки - создаем новый узел дерева
            if (current->right_== nullptr)
            {
                Node* new_node = new Node (value);
                current->right_ = new_node;
                size_++;
                return true;
            }

            // иначе - двигаемся дальше по дереву, в правый узел
            current = current->right_;
        }
        else
        {
            // если дошли до необходимого места вставки - создаем новый узел дерева
            if (current->left_== nullptr)
            {
                Node* new_node = new Node (value);
                current->left_ = new_node;
                size_++;
                return true;
            }

            // иначе - двигаемся дальше по дереву, в левый узел
            current = current->left_;       }
    }
}

// поиск элемента в дереве
template<typename T>
auto BinarySearchTree<T>::find(const T& value) const noexcept -> const T*
{
    Node * current (root_);

    while (current)
    {
        if (value < current->value_)
            current = current->left_;
        else if (value > current->value_)
            current = current->right_;
        else
            return &current->value_;
    }

    return nullptr;
}
/*template <typename T>
auto BinarySearchTree<T>::find(const T & value) const noexcept -> Node* //bool
{
    // создаем указатель, который будет двигаться по дереву
    Node* current (root_);
    while (1)
    {
        if(value < current->value_)
        {
            // если двигаться влево уже не получится - элемент отсутствует в дереве
            if (current->left_== nullptr)
                return nullptr;//false;
            // иначе - двигаемся дальше по дереву, в левый узел
            current = current->left_;
        }
        else {
            if (value > current->value_) {
                // если двигаться вправо уже не получится - элемент отсутствует в дереве
                if (current->right_ == nullptr)
                    return nullptr;//false;
                // иначе - двигаемся дальше по дереву, в правый узел
                current = current->right_;
            }
            else
                return current; //true;
        }
    }
}
*/
// оператор присваивания
template <typename T>
auto BinarySearchTree<T>::operator = (const BinarySearchTree<T> & tree) -> BinarySearchTree<T> &
{
    delete this->root_;

    this->root_ = new Node(tree.root_);
    this->root_ = tree.root_;
    this->size_ = tree.size_;
}

template <typename T>
auto BinarySearchTree<T>::insert_rec(Node*& nd, const T& value) noexcept -> void
{
    // добавление узла в дерево
    if (nd == nullptr)
    {
        nd = new Node (value);
        size_++;
        return ;
    }

        // если узел уже существует - ищем место для вставки
    else
    {
        if(value < nd->value_)
        {
            if(nd->left_)
                insert_rec(nd->left_, value);
            else
            {
                nd->left_ = new Node (value);
                size_++;
                return ;
            }
        }

        else
        if(value == nd->value_)
            return ;
        else
        {
            if(nd->right_)
                insert_rec(nd->right_, value);
            else
            {
                nd->right_ = new Node (value);
                size_++;
                return ;
            }
        }
    }
}


template <typename T>
auto BinarySearchTree<T>::is_equal(Node* nd,const BinarySearchTree<T> & tree) const noexcept->bool
{

    if(tree.find(nd->value_))
    {
        if(nd->left_)
        {
            if(!is_equal(nd->left_,tree))
                {return false;}
            else
                {return true;}
        }

        if(nd->right_)
        {
            if(!is_equal(nd->right_,tree))
               { return false;}
            else
               { return true;}
         }
        return true;
    }
    else
        return false;
}



// оператор перемещения
template <typename T>
auto BinarySearchTree<T>::operator = (BinarySearchTree<T> && tree) -> BinarySearchTree<T> &
{
    this->root_ = tree.root_;
    this->size_ = tree.size_;

    // освобождаем память временного объекта
    tree.root_ = nullptr;
    tree.size_ = 0;
}


// вывод в файловый поток
template <typename T>
auto operator << (std::ofstream& out, const BinarySearchTree<T>& tree) ->std::ofstream&
{
    tree.Print_file(out,tree.Root(),0);
    return out;
}

// вывод на консоль
template <typename T>
auto operator << (std::ostream& out, const BinarySearchTree<T>& tree) ->std::ostream&
{
    tree.Print(out,tree.Root(),0);
    return out;
}

// ввод с консоли
template <typename T>
auto operator >> (std::istream& in, BinarySearchTree<T>& tree) ->std::istream&
{
    T a;
    in >> a;
    tree.insert_rec(tree.root_,a);
    return in;
}

template <typename T>
auto operator >> (std::ifstream& in, BinarySearchTree<T>& tree) ->std::ifstream&
{
    T a;

    while(!in.eof())
    {
        in >> a;
        tree.insert_rec(tree.root_,a);
    }
    return in;
}

template <typename T>
auto BinarySearchTree<T>::operator == (const BinarySearchTree& tree) -> bool
{
    if(tree.size_==this->size_)
    {
        if(is_equal(this->root_,tree))
            return true;
        else
            return false;

    }
    else
        return false;
}
