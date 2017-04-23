#include <iostream>

using namespace std;

template <typename T>
class vector
{
  public:
    typedef vector<T> &self;

  private:
    T *arr = new T[2];
    int end = 0;    //已使用的大小
    int finish = 2; //容量

    void my_copy(T *&arr, T *&arr1, int size)
    {
        for (int i = 0; i < size; ++i)
            arr1[i] = arr[i];
    }

    void resize(int capacity)
    {
        T *temp = new T[capacity];
        my_copy(arr, temp, end);
        finish = capacity;

        delete[] arr;
        arr = temp;
    }

  public:
    vector(const T &value)
    {
        arr[0] = value;
        end++;
    }

    ~vector()
    {
        delete[] arr;
    }

    void push_back(const T &value)
    {
        if (end == finish)
        {
            resize(finsih*2);
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
        if(end == finish/2)
            resize(finish/2);
    }

    void print()
    {
        for (int i = 0; i < end; ++i)
            cout << arr[i] << endl;
    }

    self operator++();

    self operator--();

    bool operator<(const self );

    bool operator>(const self );
};

self operator++()
{
    ++this.end;
    return this;
}

self operator--()
{
    --this.end;
    return this;
}

bool operator<(const self vt)
{
    this.end < vt.end ? return true : return false;
}

bool operator>(const self vt)
{
    this.end > vt.end ? return true : return false;
}

T operator[](int pos)
{
    return this[pos];
}

T operator[](const T& value)
{

}