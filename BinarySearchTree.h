#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
class BinarySearchTree
{
private:
    Node<T>* root;
    void destroy(Node<T>*);
    void insert(Node<T>*&, const T&);
    void inorder(Node<T>*, std::ostream&) const;
    void preorder(Node<T>*, std::ostream&) const;
    void postorder(Node<T>*, std::ostream&) const;
    T* search(Node<T>*, const T&) const;
    int height(Node<T>*) const;
    int max(int, int) const;
public:
    int val;
    BinarySearchTree();
    ~BinarySearchTree();
    void destroy();
    void deleteNode(const T&);
    void insert(const T& item);
    void inorder(std::ostream& os = std::cout) const;
    void preorder(std::ostream& os = std::cout) const;
    void postorder(std::ostream& os = std::cout) const;
    int height() const;
    T* search(const T&) const;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::destroy()
{
    destroy(root);
}

template <typename T>
void BinarySearchTree<T>::deleteNode(const T& item)
{
    using namespace std;
    bool found;
    Node<T>* current;
    Node<T>* parent;

    search(item, found, current, parent);

    if (!found)
    {
        cout << "Item could not be located.\n";
    }
    else if ((current->left != nullptr) && (current->right != nullptr))
    {
        Node<T>* currentSucc = current->right;
        parent = current;
        while (currentSucc->left != nullptr)
        {
            parent = currentSucc;
            currentSucc = currentSucc->left;
        }
        current->value = currentSucc->value;
        current = currentSucc;
    }

    Node<T>* subtree = current->left;
    if (subtree == nullptr)
    {
        subtree = current->right;
    }
    if (parent == nullptr)
    {
        root = subtree;
    }
    else if (parent->left == current)
    {
        parent->left = subtree;
    }
    else
    {
        parent->right = subtree;
    }
    delete current;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& item)
{
    insert(root, item);
}

template <typename T>
void BinarySearchTree<T>::inorder(std::ostream& os)const
{
    inorder(root, os);
}

template <typename T>
void BinarySearchTree<T>::preorder(std::ostream& os)const
{
    preorder(root, os);
}

template <typename T>
void BinarySearchTree<T>::postorder(std::ostream& os) const
{
    postorder(root, os);
}

template <typename T>
T* BinarySearchTree<T>::search(const T& item) const
{
    search(Node<T> *root, item);
}

template <typename T>
void BinarySearchTree<T>::destroy(Node<T>* r)
{
    if (r != nullptr)
    {
        destroy(r->left);
        destroy(r->right);
        delete r;
    }
}

template <typename T>
void BinarySearchTree<T>::insert(Node<T>*& r, const T& item)
{
    using namespace std;

    if (r == nullptr)
    {
        r = new Node<T>;
        r->value = item;
        r->left = nullptr;
        r->right = nullptr;
    }
    else if (item < r->value)
    {
        insert(r->left, item);
    }
    else if (r->value < item)
    {
        insert(r->right, item);
    }
    else
    {
        cout << "Node already exists." << endl;
    }
}

template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* r, std::ostream& os)const
{
    using namespace std;

    if (r != nullptr)
    {
        inorder(r->left, os);
        os << r->value << endl;
        inorder(r->right, os);
    }
}

template <typename T>
void BinarySearchTree<T>::preorder(Node<T>* r, std::ostream& os)const
{
    using namespace std;

    if (r != nullptr)
    {
        os << r->value << endl;
        preorder(r->left, os);
        preorder(r->right, os);
    }
}

template <typename T>
void BinarySearchTree<T>::postorder(Node<T>* r, std::ostream& os) const
{
    using namespace std;

    if (r != nullptr)
    {
        postorder(r->left, os);
        postorder(r->right, os);
        os << r->value << "\n";
    }
}

template <typename T>
int BinarySearchTree<T>::height()const
{
    return height(root);
}

template <typename T>
T* BinarySearchTree<T>::search(Node<T>* r, const T& item) const
{
    T* result;

    if (r == nullptr)
    {
        result = nullptr;
    }
    else if (item < r->value)
    {
        result = search(r->left, item);
    }
    else if (r->value < item)
    {
        result = search(r->right, item);
    }
    else
    {
        result = new T(r->value);
    }

    return result;
}

template <typename T>
int BinarySearchTree<T>::height(Node<T>* root) const
{
    int result;

    if (root == nullptr)
    {
        result = 0;
    }
    else
    {
        result = 1 + max(height(root->left),
            height(root->right));
    }

    return result;
}

template <typename T>
int BinarySearchTree<T>::max(int a, int b) const
{
    return(a > b) ? a : b;
}

#endif