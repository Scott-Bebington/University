#include <vector>
#include <iostream>
using namespace std;
    
int main()
{ 
    // 1D:	
    vector<int> vect;
    for (int i = 0; i < 5; i++)
        vect.push_back(i); // insert at end of array
 
    for (int j = 0; j < vect.size(); j++)
        cout << vect[ j ] << " ";	
    cout << endl << endl;
	
    // 2D:	
    vector< vector<int> > vect2D;	
	
    for (int i = 0; i < 5; i++) {
	vector<int> row; // Create an empty row
	for (int j = 0; j < 5; j++) {
		row.push_back(i * j); // Add an element (column) to the row
	}
        vect2D.push_back(row); // insert at end of array
    }
 
    for (int i = 0; i < vect2D.size(); i++) {
	for (int j = 0; j < vect2D[ i ].size(); j++)  {
		cout << vect2D[ i ][ j ] << " ";	
	}
	cout << endl;
    }
    cout << endl;
    
    // Alternatively:
    // Create
    vector< vector<int> >  vec(4, vector<int>(4, 99)); 
    // Above: vec of size 4, every element is a vector<> of size 4
    
    // Write
    for (int i = 0; i < vec.size(); i++) {
	for (int j = 0; j < vec[ i ].size(); j++)  {
		vec[ i ][ j ] = 3;
	}
    }
    // Read    
    for (int i = 0; i < vec.size(); i++) {
	for (int j = 0; j < vec[ i ].size(); j++)  {
		cout << vec[ i ][ j ] << " ";	
	}
	cout << endl;
    }
    cout << endl;
} 
