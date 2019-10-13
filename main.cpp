#include "gc_pointer.h"
#include "LeakTester.h"
#include <iostream>


using namespace std;



int main()
{
    

    Pointer<int> p1 = new int{5};
    Pointer<int> p2 = p1;
    Pointer<int> p3;

    cout <<"Now we show the list of pointers (p3 is not initialized):"<< endl;
    p3.showlist();

    cout << "-----------------------------------------\n\n" << endl;

    //look at p3 as a pointer and value
    cout << "Now show p3 and its value; notice it was not initialized" << endl;
    cout << p3 << endl;
    cout << *p3 << endl;


    cout << "-----------------------------------------\n\n" << endl;
    //Dangerous: don't create old pointer
    //however it will be engulfed by my garbage collector [my smart pointer]
    int* x = new int(78787);

    p3 = x;
    cout <<"Now we show the list of pointers (p3 is initialized) :"<< endl;

    p3.showlist();
    cout << "-----------------------------------------\n\n" << endl;



    //pointers to string
    Pointer<string> p4;
    Pointer<string> p5 = new string{"This is a text"};
    cout <<"Now we show the list of string pointers :"<< endl;

    p5.showlist();

    p4 = p5;

    cout << "-----------------------------------------\n\n" << endl;

    cout << "Now we show the list of string pointers after assigine p5 to p4:"<< endl;
    p5.showlist();



    cout << "-----------------------------------------\n\n" << endl;

    //Now let us try array pointers
    Pointer<int, 7> pArr = new int[7]{2,3,4,5,6,7,9};
    cout << "Now show the list for the array pointer" << endl;
    pArr.showlist();

    cout << "-----------------------------------------\n\n" << endl;
    Pointer<int,7> pArr2;
    cout << "Now show the list for the 2nd array pointer" << endl;
    pArr2.showlist();

    cout << "-----------------------------------------\n\n" << endl;
    //assign first array into the second
    pArr2 = pArr;
    cout << "Now show the list for the 2nd array pointer after assigning it to the 1st array" << endl;
    pArr2.showlist();

    return 0;
}
