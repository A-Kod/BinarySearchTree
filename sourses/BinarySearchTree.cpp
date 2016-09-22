#include <iostream>

template <typename T>
class BinarySearchTree;

template <typename T>
std::ofstream & operator << (std::ofstream & out, const BinarySearchTree<T> & tree);

template <typename T>
std::ostream & operator << (std::ostream & out, const BinarySearchTree<T> & tree);

template <typename T>
std::istream & operator >> (std::istream & in, BinarySearchTree<T> & tree);

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

    auto Root() const noexcept -> Node*;                                             // корень дерева
    auto Print (std::ostream & out,Node* nd,int level) const noexcept -> void;       // распечатать дерево
    auto Print_file (std::ofstream & out,Node* nd,int level) const noexcept -> void; // распечатать дерево
  //  auto size() noexcept -> size_t;                                                  // определение размера
    auto insert(const T & value) noexcept -> bool;                                   // вставка нового звена
    auto find(const T & value) noexcept -> bool;                                     // поиск элемента
    auto operator = (const BinarySearchTree<T> & tree) -> BinarySearchTree<T> &;     // оператор присваивания
    auto operator = (BinarySearchTree<T> && tree) -> BinarySearchTree<T> &;          // оператор перемещения
};

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
    // копируем корень дерева и количество элементов
    this->root_ = tree.root_;
    this->size_ = tree.size_;
}

// конструктор перемещения
template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> && tree)
{

}

// деструктор
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{

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
        return;
    else
    {
        // левое поддерево
        Print(out,nd->left_,++level);

        for (int i=0; i<level; ++i)
            out << "|";
        out << nd->value_<< "\n";
        level--;
    }
    Print(out,nd->right_,++level); // правое поддерево
}

template <typename T>
auto BinarySearchTree<T>::Print_file(std::ofstream & out,Node* nd,int level) const noexcept -> void
{
    // если дерево пустое, то выходим
    if (nd== nullptr)
        return;
    else
    {
        // левое поддерево
        Print_file(out,nd->left_,++level);
        out << nd->value_<< "\n";
        level--;
    }
    Print_file(out,nd->right_,++level); // правое поддерево
}


// количество узлов дерева
//template <typename T>
//auto BinarySearchTree<T>::size() noexcept -> size_t
//{
 //   return size_;
//}

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
       if(value>=current->value_)
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
template <typename T>
auto BinarySearchTree<T>::find(const T & value) noexcept -> bool
{
    // создаем указатель, который будет двигаться по дереву
    Node* current (root_);

    while (1)
    {
        if(value < current->value_)
        {
            // если двигаться влево уже не получится - элемент отсутствует в дереве
            if (current->left_== nullptr)
              return false;

            // иначе - двигаемся дальше по дереву, в левый узел
            current = current->left_;
        }
        else {
            if (value > current->value_) {
                // если двигаться вправо уже не получится - элемент отсутствует в дереве
                if (current->right_ == nullptr)
                    return false;

                // иначе - двигаемся дальше по дереву, в правый узел
                current = current->right_;
            } else
                return true;
        }
    }
}

// оператор присваивания
template <typename T>
auto BinarySearchTree<T>::operator = (const BinarySearchTree<T> & tree) -> BinarySearchTree<T> &
{
    delete this->root_;

    this->root_ = new Node(tree.root_);
    this->root_ = tree.root_;
    this->size_ = tree.size_;
}

// оператор перемещения
template <typename T>
auto BinarySearchTree<T>::operator = (BinarySearchTree<T> && tree) -> BinarySearchTree<T> &
{

}


// вывод в файловый поток
template <typename T>
std::ofstream & operator << (std::ofstream & out, const BinarySearchTree<T> & tree)
{
    tree.Print_file(out,tree.Root(),0);
}

// вывод на консоль
template <typename T>
std::ostream & operator << (std::ostream & out, const BinarySearchTree<T> & tree)
{
    tree.Print(out,tree.Root(),0);
}

// ввод с консоли
template <typename T>
std::istream & operator >> (std::istream & in, BinarySearchTree<T> & tree)
{
   T a;
   in >> a;
   tree.insert(a);
}
