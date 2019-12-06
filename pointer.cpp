#include <string>
#include <iostream>
using namespace std;
int main(){


int* pa;
pa = new int;
*pa = 2;
cout << *pa << endl;
return 0;
}