#include "IntList.h"

//Ryan Yuzuki and Edward Zabrensky

using namespace std;

int main(){
    IntList temp;
    temp.push_front(66);
    
    temp.pop_front();
    cout << temp << endl;
    temp.push_front(55);
    
    temp.push_back(99);
    temp.pop_back();
    temp.push_back(1231);
    temp.push_front(12);
    temp.push_front(5);
    cout << temp << endl;
    temp.printReverse();
    cout << endl;
    
    return 0;
}