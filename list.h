#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <typename T>
class list_node {
typedef list_node<T>* ptr;
public:
    ptr next;
    ptr prev;
    T data;

    list_node(const T& value){
        data = value;
        next = nullptr ;
        prev = nullptr;
    }
};

template <typename T>
class list{
typedef list_node<T>* ptr;
private:
    ptr head;
    ptr tail;

public:
    list(const T& value){
        ptr temp = new list_node<T>(value);
        head = temp;
        tail = temp;
    }

    ~list(){

    }

    void insert(const T& value){
        ptr temp = new list_node<T>(value);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    void del(const T& value){
        ptr temp = head;
        while(temp->next != nullptr){
            if(temp->data != value)
                temp = temp->next;
            else{
                ptr d = temp;
                temp = temp->next;

                d->prev->next = temp;
                temp->prev = d->prev;
                delete d;
            }
        }
        // while((temp = find(value)) != nullptr){
        //     delete temp;
        // }
    }

    ptr find(const T& value){
        ptr temp = head;
        while(temp->data != value){
            if(temp == nullptr)
                return nullptr;
            temp = temp->next;
        }
        return temp;
    }

    void print(){
        ptr temp = head;
        while(temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

#endif //LIST_H
