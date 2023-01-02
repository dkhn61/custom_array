#include "Array.h"
#include <iostream>
using namespace std;


int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
  Array a1;
  Array a2(25);
  Array a3(15,'k');

    a1.printArray();
    a2.printArray();
    a3.printArray();

    Array a4(a3);
    cout << "Copy constructor " << " ";
    a4.printArray();
    a2.resize(50);
    cout << "Resized a2:-  " << a2.size() << " , max size of a2:- " << a2.max_size();

    cout << "Contents of a2 after resizing \n" ;
    a2.printArray();

    cout << "Copied contents after destructed " << " ";

    a4.printArray();
    cout << "Reverse array " << " ";
    a1.reverse();
    a1.printArray();


    cout << "Assignment of array " << " ";

    Array a = a2;
    a.printArray();

    cout << "check array index operator [] " << a2[40] <<endl;
    a1[9];
    const char k = a2[40];
    cout << "Value of char : " <<  k << endl;

    cout << "check array getter method : " << a1.get(9) << endl;

    cout << "check array setter method : " ;
    a1.set(8,'L');
    a1.printArray();

    cout << "check array resize method : " ;
    a3.resize(60);
    cout << a3.size();
    a3.printArray();

    cout << "Index of character : "<<a1.find('c') << endl;
    cout << "Index of character using start index : "<<a1.find('b',0) <<endl;
    cout << "Equality of array : " << " ";
    if(a4 == a2) cout << "Equal " << " ";
    else cout << "Not Equal " << " ";
    cout << endl;
    cout << "Inequality of array : " << " ";
    if(a3 != a2) cout << "Not Equal " << " ";
    else cout << "Equal " << " ";
    cout << endl;
    cout << "Fill array : ";
    a2.fill('w'+1);
    a2.printArray();

    cout << "Array current size : " << a2.size() << " and max size: " << a2.max_size() <<endl;
    a2.shrink();
    cout << "After shrinking curren size : " << a2.size() << " and max size: " << a2.max_size() <<endl;
    a2.printArray();
    Array a5 = a1.slice(4);
    Array a6 = a1.slice(4,7);

    cout << "After slicing array size: " << a5.size() << " and max size: " <<a5.max_size() <<endl;
    a1.printArray();
    a5.printArray();
    cout << "After slicing with end index array size: " << a6.size() << " and max size: " <<a6.max_size() <<endl;
    a6.shrink();
    cout << "After shrinking curren size : " << a6.size() << " and max size: " << a6.max_size() <<endl;

    a1.printArray();
    a6.printArray();
    return 0;
}


