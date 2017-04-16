#include <iostream>
#include "vector.h"

using namespace std;

int main(void)
{
    vector<int> v(0);
    
    for(int i = 1; i < 20; ++i)
    	v.push_back(i); 
    v.print();

    for(int i = 5; i < 10; ++i)
        v.pop_back();
    v.print();

    return 0;
}
