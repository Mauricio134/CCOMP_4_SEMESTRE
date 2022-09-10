#include <iostream>
#include <ctime> 
 
unsigned t0, t1;

using namespace std;

class Ccomp
{
  public:
    virtual bool cmp(int a, int b) = 0;
};

class Cless: public Ccomp
{
  public:
    bool cmp(int a, int b){
      return a<b;
    }
};

class Cgreater: public Ccomp
{
  public:
    bool cmp(int a, int b){
      return a>b;
    }
};

class Cless1
{
  public:
    bool cmp(int a, int b){
      return a<b;
    }
};

class Cgreater1
{
  public:
    bool cmp(int a, int b){
      return a>b;
    }
};

class Cless2
{
  public:
    inline bool cmp(int a, int b){
      return a<b;
    }
};

class Cgreater2
{
  public:
    inline bool cmp(int a, int b){
      return a>b;
    }
};
  
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}


int partition (int arr[], int low, int high, double *cant) 
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1);
    double count = 0;// Index of smaller element and indicates the right position of pivot found so far
    t0 = clock();
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        }
    }
    t1 = clock(); 
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    *cant += time;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); 
}

void quickSort(int arr[], int low, int high, double *cant) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high, cant); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1, cant); 
        quickSort(arr, pi + 1, high, cant);
    } 
} 

int partition1 (int arr[], int low, int high, Ccomp *p, double *cant) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    t0 = clock();
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller than the pivot 
        if (p->cmp(arr[j], pivot)) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        }
    }
    t1 = clock(); 
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    *cant += time;
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort */
void quickSort1(int arr[], int low, int high, Ccomp *p, double *cant) 
{ 
    if (p->cmp(low, high)) 
    {
        int pi = partition1(arr, low, high, p, cant); 
  
        quickSort1(arr, low, pi - 1, p, cant); 
        quickSort1(arr, pi + 1, high, p, cant); 
    } 
}

template<class C>
int partition2 (int arr[], int low, int high, C c, double *cant) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1);
  // Index of smaller element and indicates the right position of pivot found so far
    t0=clock();
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller than the pivot 
        if (c.cmp(arr[j], pivot)) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        }
    }
    t1 = clock(); 
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    *cant += time;
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

template<class C>
/* The main function that implements QuickSort */
void quickSort2(int arr[], int low, int high, C c, double *cant) 
{ 
    if (c.cmp(low, high)) 
    {
        int pi = partition2(arr, low, high, c, cant); 
  
        quickSort2(arr, low, pi - 1, c,cant); 
        quickSort2(arr, pi + 1, high, c,cant); 
    } 
}

template<class C>
int partition3(int arr[], int low, int high, C c, double *cant) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    t0 = clock();
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller than the pivot 
        if (c.cmp(arr[j], pivot)) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        }
    }
    t1 = clock(); 
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    *cant += time;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); 
} 

template<class C>
/* The main function that implements QuickSort */
void quickSort3(int arr[], int low, int high, C c, double *cant) 
{ 
    if (c.cmp(low, high)) 
    {
        int pi = partition3(arr, low, high, c, cant); 
  
        quickSort3(arr, low, pi - 1, c, cant); 
        quickSort3(arr, pi + 1, high, c, cant); 
    } 
}
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
  
// Driver Code
int main() 
{ 
    int arr[100000];
    int arr1[100000];
    int arr2[100000];
    int arr3[100000];
    for(int i = 0; i<100000; i++)
    {
      int a = rand();
      arr[i] = a;
      arr1[i] = a;
      arr2[i] = a;
      arr3[i] = a;
    }
    double count = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    Cless l;
    Cgreater g;
    Cless1 i;
    Cgreater1 j;
    Cless2 k;
    Cgreater2 o;
    Ccomp *p = &l;
    quickSort(arr, 0, n - 1, &count);
    cout << count*1000 << endl;
    count = 0;
    quickSort1(arr1, 0, n - 1, p, &count);
    cout << count*1000 << endl;
    count = 0;
    quickSort2(arr2, 0, n - 1, i, &count);
    cout << count*1000 << endl;
    count = 0;
    quickSort3(arr3, 0, n - 1, k, &count);
    cout << count*1000 << endl;
    return 0;
}