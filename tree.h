#ifndef TREE_H
#define TREE_H
#include <iostream>

using namespace std;

template <typename T>
class tree_node{
    typedef tree_node<T>* ptr;
public:
    ptr left;
    ptr right;
    ptr parent;
    T data;

    tree_node(const T& value)
    :data(value), right(nullptr), left(nullptr), parent(nullptr)
    {}

    ~tree_node(){}
};

template <typename T>
class tree{

    typedef tree_node<T>* ptr;

private:
    
    ptr root;

public:

    tree(const T& value){
        ptr temp = new tree_node<T>(value);
        root = temp; 
        temp->parent = root;
    }

    ~tree(){}

    void insert(const T& value){
        ptr temp = root, prev = nullptr;
        while(temp){
            prev = temp;
            if(value < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(root == nullptr)
            root = new tree_node<T>(value);
        else if(value < prev->data){
            ptr x = new tree_node<T>(value);
            x->parent = prev;
            prev->left = x;
        }
        else{
            ptr x = new tree_node<T>(value);
            x->parent = prev;
            prev->right = x;
        }
    }

    void dele(ptr& node){
        ptr temp = node;
        if(node){
            if(node->right == nullptr)
                node = node->left;
            else if(node->left == nullptr)
                node = node->right;
            else{
                temp = node->left;
                while(temp->right)
                    temp = temp->right;
                temp ->right = node->right;
                temp = node;
                node = node->left;
            }
            delete temp;
        }
    }

    void del(const T& value){
        ptr node = root, prev = 0;
        while(node){
            if(node->data == value)
                break;
            prev = node;

            if(node->data < value)
                node = node->right;
            else
                node = node->left;
        }
        if(node && node->data == value)
            if(node == root)
                dele(root);
            else if(prev ->left == node)
                dele(prev->left);
            else
                dele(prev->right);
        else if(root)
            cout << "data: " << value << "is not in the tree" << endl;
        else
            cout << "the tree is empty";
    }

    ptr in_order(ptr root){
        if(root != nullptr){
            in_order(root->left);
            cout << root->data << endl;
            in_order(root->right);
        }
    }


    void print(){
        in_order(root);
    }
};

#endif  //TREE_H
