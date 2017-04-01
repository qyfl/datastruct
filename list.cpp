#include <iostream>
#include "list.h"

using namespace std;

int main(void){
	list<int> a(0);

	for(int i = 1; i < 100; ++i)
		a.insert(i);
	
	a.print();

	for(int i = 50; i < 100; ++i)
		a.del(i);

	a.print();
	return 0;
}
