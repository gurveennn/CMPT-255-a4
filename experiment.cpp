#include "quicksort.h"

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <ratio>
using namespace std; 


// Gurveen Nanua
// 301546459
// experiment for quicksort

int main(){

    using namespace chrono; 

    // testing an array of size 1,000 / 10,000 / 100,000 / 500,000
    int SIZE = 1000;
    cout << "\nThe size is " << SIZE << endl;

    //testing quikcsort on four different algorithms 
    int A[SIZE];
    int B[SIZE];
    int C[SIZE];
    int D[SIZE];

    cout << "\nCreating arrays A,B,C,D to test the 4 cases:" << endl; 
    
    for(int i=0; i<SIZE; i++){
        int num = rand() % SIZE;
        A[i] = num;
        B[i] = num;
        C[i] = num;
        D[i] = num;
    }
       
    // 1.
    cout << "\n1. Quicksort using the median of A[lo], A[(lo+hi)/2] and A[hi] as the pivot: \narray A" << endl;
    steady_clock::time_point a1 = steady_clock::now();

    quickSort1(A, 0, SIZE-1);

    steady_clock::time_point a2 = steady_clock::now();
    duration<double> aTime = duration_cast<duration<double> >(a2 - a1); 


    cout << "\nChecking the first 100 elements in the array to see if sorted" << endl;
    cout << "{ ";
    for(int k=0; k<100; k++){
        cout << A[k] << ", ";
    }
    cout << "}\n" << endl;


    // 2.
    cout << "\n2. Quicksort using an element chosen uniformly at random as the pivot: \narray B" << endl;
    steady_clock::time_point b1 = steady_clock::now();

    quickSort2(B, 0, SIZE-1);

    steady_clock::time_point b2 = steady_clock::now();
    duration<double> bTime = duration_cast<duration<double> >(b2 - b1); 


    cout << "\nChecking the first 100 elements in the array to see if sorted" << endl;
    cout << "{ ";
    for(int k=0; k<100; k++){
        cout << B[k] << ", ";
    }
    cout << "}\n" << endl;

    // 3. 
    cout << "\n3. Special handlings on small sequences, otherwise it will run as a quicksort";
    cout << " algorithm used for array A: \narray C" << endl;
    steady_clock::time_point c1 = steady_clock::now();

    quickSort3(C, 0, SIZE-1);

    steady_clock::time_point c2 = steady_clock::now();
    duration<double> cTime = duration_cast<duration<double> >(c2 - c1); 


    cout << "\nChecking the first 100 elements in the array to see if sorted" << endl;
    cout << "{ ";
    for(int k=0; k<100; k++){
        cout << C[k] << ", ";
    }
    cout << "}\n" << endl; 

    // 4.
    cout << "\n4. Using std::sort: \narray D" << endl;
    steady_clock::time_point d1 = steady_clock::now();

    usingSort(D, SIZE-1);

    steady_clock::time_point d2 = steady_clock::now();
    duration<double> dTime = duration_cast<duration<double> >(d2 - d1); 


    cout << "\nChecking the first 100 elements in the array to see if sorted" << endl;
    cout << "{ ";
    for(int k=0; k<100; k++){
        cout << D[k] << ", ";
    }
    cout << "}\n" << endl; 

    // output the times
    cout << "\nThe time for A is: " << aTime.count() << endl; 
    cout << "\nThe time for B is: " << bTime.count() << endl; 
    cout << "\nThe time for C is: " << cTime.count() << endl; 
    cout << "\nThe time for D is: " << dTime.count() << endl; 

    return 0; 

}