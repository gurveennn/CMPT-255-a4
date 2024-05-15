#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std; 

//Gurveen Nanua
//301546459
//4 different variantions of qicksort including the C++ implementation std::sort

const int K = 100; //for special case

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp; 
}

// 1. quicksort using the median of A[lo], A[(lo+hi)/2] and A[hi] as the pivot

// median function
int medianIndex(int A[], int lo, int hi){
    int mid = (lo + hi) /2; 
    
    //sort values to find median
    int a[3] = {A[lo], A[mid], A[hi]};
    int size = 3;
    std::sort(a, a+size);
    int median = a[1];  //median is middle value 

    //return index of median value 
    if(median == A[lo]){
        return lo;
    }
    if(median == A[mid]){
        return mid;
    }
    if(median == A[hi]){
        return hi;
    }
    else return -1; 
}


int partition1(int A[], int lo, int hi){
    //pivot is median
    int pivotindex = medianIndex(A, lo, hi);
    swap(A[pivotindex], A[hi]);
    int pivot = A[hi];

    int i=lo;
    for(int j=lo; j<hi; j++){
        if(A[j] <= pivot){
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[hi]); //move pivot where it belongs
    return i; //pivot position
}

void quickSort1(int A[], int lo, int hi){
    if(lo < hi){
        int pivotpos = partition1(A, lo, hi);
        quickSort1(A, lo,  pivotpos-1);
        quickSort1(A, pivotpos+1, hi);
    }
}

// 2. quicksort using an element chosen uniformly at random as the pivot
int partition2(int A[], int lo, int hi){
    //pivot is a random element
    //range from lo to hi
    int pivotindex = lo + rand() % (hi - lo + 1);
    swap(A[pivotindex], A[hi]);
    int pivot = A[hi];

    int i=lo;
    for(int j=lo; j<hi; j++){
        if(A[j] <= pivot){
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[hi]); //move pivot where it belongs
    return i; //pivot position
}

void quickSort2(int A[], int lo, int hi){
    if(lo < hi){
        int pivotpos = partition2(A, lo, hi);
        quickSort2(A, lo,  pivotpos-1);
        quickSort2(A, pivotpos+1, hi);
    }
}

// 3. special handlings on small sequences, otherwise it will run as a quicksort algorithm like the first one
void quickSort3(int A[], int lo, int hi){ // Quick sort with "introspection" 
    int j, k;
    if( hi - lo < K ){ // K is some constant chosen empirically.
      //selection sort
      for(int i=1; i < hi; i++){
        j = i-1;
        k = i;
        //find min element
        while(k<hi){
            if(A[k]<A[j]){
                j = k;
            }
            k++;
        }
        //j is the index of the min element
        swap(A[i-1], A[j]);
      }
   } else {
      // do the normal thing
        int pivotpos = partition1(A, lo, hi);
        quickSort3(A, lo,  pivotpos-1);
        quickSort3(A, pivotpos+1, hi);
   }
}

// 4. using std::sort
void usingSort(int A[], int size){
    int n = size; 
    std::sort(A, A+n);
}
