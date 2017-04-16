#include <iostream>

using namespace std;

template <typename T>
class vector
{
private:
	T* arr = new T[2];
    int end = 0;    //已使用的大小
    int finish = 2; //容量

    void my_copy(T* arr, T* arr1, int size)
    {
        for(int i = 0; i < size; ++i)
            arr1[i] = arr[i];
    }

    void add()
    {
        T* temp = new T[finish*2];
        my_copy(arr, temp, finish);
        finish *= 2;
        
        T* t = arr;
        arr = temp;
        delete[] t;
    }
    
public:
    vector(const T& value)
    {
        arr[0] = value;
        end ++;
    }

    ~vector()
    {
        delete[] arr;
    }

    void push_back(const T& value)
    {
        if(end == finish)
        {
            add();
            arr[end++] = value;
        }
        else
        {
            arr[end++] = value;
        }
    }

    void pop_back()
    {
        --end;
    }

    void print()
    {
        for(int i = 0; i < end; ++i)
            cout << arr[i] << endl;
    }
};