#include <iostream>
#include "tree.h"

using namespace std;

int main(void){
    tree<int> t(10);
	for(int i = 0; i < 20; ++i)
		t.insert(i); 
	
	t.print();

    for(int i = 11; i < 16; ++i)
        t.del(i);
	
	t.print();  
	    return 0;
}
