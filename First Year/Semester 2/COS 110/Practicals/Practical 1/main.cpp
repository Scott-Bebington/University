#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*
	stringToInt is a helper function that will 
	take a string called line and return the integer value
*/
int stringToInt(string line)
{
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}

int countnames(string line)
{
	int count = 1;
	int len = line.length();
	for (int x = 0; x < len; x++)
	{
		if(line[x] == ',')
		{
			count ++;
		}
	}
	return count;
}

int main() 
{
    string floorline;
    string floorcount;
    string floornumber;
    string floormembers;
    string membername;
    string temp;
    int floor = 0;
    int count = 0;
    int membercount = 0;
    int countouptfloors = 0;
	fstream myfile;
    myfile.open("building.data");

    while(getline(myfile, floorcount))
    {
        count++;
    }
    count = (count - 1) / 2; // 11

    string** arr = new string*[count]; // array for all the floor numbers
    int *intarr = new int[count];

    myfile.close();
    myfile.open("building.data");

    getline(myfile, floorline); // gets "1,10,3,7,6,5,0,9"
	stringstream floorlinesplit(floorline); // stores the floor numbers in floorlinesplit 
    countouptfloors = countnames(floorline);
    int *floorarr = new int[countouptfloors];
    int *arrfloors = new int[countouptfloors];
    for (int x = 0; x < count; x++)
    {
        getline(myfile, floornumber); // gets floorID
        stringstream number(floornumber); // Stores FloodID in number
        for (int y = 0; y < 2; y++)
        {
            getline(number, floornumber, ':'); // contains floor number as a string
        }

        floor = stringToInt(floornumber); // converts floor number into an int

        getline(myfile, floormembers); // stores names

        membercount = countnames(floormembers);
        intarr[x] = membercount;

        string *ptr = new string[membercount];
        stringstream members(floormembers); // stores names in members
        for (int z = 0; z < membercount; z++)
        {
            getline(members, membername, ',');
            ptr[z] = membername;
        }
        arr[floor] = ptr;
    }
    for (int i = 0; i < countouptfloors; i++)
    {
        getline(floorlinesplit, temp, ',');
        arrfloors[i] = stringToInt(temp);
        cout << *arr[arrfloors[i]] << endl;
    }
    delete (arr);
    delete (intarr);
    delete (floorarr);
    delete (arrfloors);
    return 0;
}

/*
Expected output with the given building.txt:

Sunil,Alok,Kamilah,Pratik
Tamera,Zanetta,Keyundra,Alexzander,Nickalaus,Nathania,Annamaria,Ransen,Thuy,Yousef       
Jeffry,Shira,Sereena
Janna,Shaleen,Josi,Ndidi,Indalecio,Charlotta
Kejuan,Matricia,Takiya,Karalyn,Charls
Rebbecca
Kailyn,Kenda
Katheryne,Coury,Timithy,Melisssa,Clara,Lucus,Brittony,Makoto,Latona,Rudolph
*/