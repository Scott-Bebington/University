#include <string>
#include <iostream>

using namespace std;
 
template <class T>
void bubbleSort(T * array, int length);

//template <class Type>
//void swap(Type& x, Type& y); // this one is already provided for you by C++

template <class T>
void printArray(T * arr, int size);

int main() {
	
	double arrayOfDoubles[5] = {2.4, 4.2, 1.6, 7.9, 2.3};
	int arrayOfInts[6] = {5, 1, 7, 3, 8, 2};
	string arrayOfNames[5] = {"Susanna", "Bob", "James", "Emily", "Margaret"};
	
	cout << "Unsorted doubles: ";
	printArray(arrayOfDoubles, 5);	
	bubbleSort(arrayOfDoubles, 5);	
	cout << "Sorted doubles: ";
	printArray(arrayOfDoubles, 5);
		
	cout << "\nUnsorted integers: ";
	printArray(arrayOfInts, 6);	
	bubbleSort(arrayOfInts, 6);	
	cout << "Sorted integers: ";
	printArray(arrayOfInts, 6);
	
	cout << "\nUnsorted names: ";
	printArray(arrayOfNames, 5);	
	bubbleSort(arrayOfNames, 5);	
	cout << "Sorted names: ";
	printArray(arrayOfNames, 5);
	
	
	return 0;
}

/*
template <class Type>
void swap(Type& x, Type& y)
{
	Type temp = x;             // swap elements
	x = y;
        y = temp;
}
*/

// Bubble Sort Function for Ascending Order 
template <class T>
void bubbleSort(T * array, int length)
{
      bool swapped = true;   // set flag to 1 to start first pass
	
      for(int i = 1; (i <= length) && swapped; i++)
     {
          swapped = false;
          for (int j=0; j < (length - 1); j++)
         {
               if (array[j+1] < array[j])     
              { 
                    swap(array[j+1], array[j]); // swap elements
                    swapped = true;                // indicates that a swap occurred.
               }
          }
     }
}

template <typename SOMETYPE>
void printArray(SOMETYPE * arr, int size)
{
	cout << "[ ";
	for(int i  = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}
