//Remember to add more test cases
//This main as-is does not test for everything

#include <iostream>
#include "Controller.h"

using namespace std;

int main()
{

	cout<<"-----Testing Cargo-----"<<endl<<endl;
	Plane<Cargo>* plane = new Plane<Cargo>(200); // max weight of 200kg
	Controller<Cargo> cc(plane); // controller controls plane "plane"
	cout << cc.loadOnPlane(new Cargo(50, 5))<<endl; // Total Value = 250
	cout << cc.loadOnPlane(new Cargo(0.2, 500))<<endl; // Total Value = 100
	cout << cc.loadOnPlane(new Cargo(30, 5))<<endl; // Total Value = 150
	cout << cc.loadOnPlane(new Cargo(80.4, 1))<<endl; // Total Value = 80.4
	cout << cc.loadOnPlane(new Cargo(50, 5))<<endl; // Total Value = 250
/*
	cout<<"Total value: "<<cc.getTotalValue()<<endl;
	cout<<"Contents:\n"<<cc.getPlaneContents()<<endl<<endl;

	cout<<"-----Testing Passenger-----"<<endl<<endl;

	Plane<Passenger>* pplane = new Plane<Passenger>(2000);
	Controller<Passenger> pc(pplane);
	cout<<pc.loadOnPlane(new Passenger("ID0", 80.0, 1500))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID1", 70, 1000))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID2", 50, 1000))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID3", 100, 2000))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID4", 80, 1500))<<endl;

	cout<<"Total value: "<<pc.getTotalValue()<<endl;
	cout<<"Contents:\n"<<pc.getPlaneContents()<<endl;

	cout<<endl<<"-----Testing Secret Cargo-----"<<endl<<endl;

	Plane<SecretCargo>* splane = new Plane<SecretCargo>(100);
	Controller<SecretCargo> sc(splane);
	cout<<sc.loadOnPlane(new SecretCargo(20))<<endl;
	cout<<sc.loadOnPlane(new SecretCargo(10))<<endl;
	cout<<sc.loadOnPlane(new SecretCargo(50))<<endl;
	cout<<sc.loadOnPlane(new SecretCargo(5))<<endl;

	cout<<"Total value: "<<sc.getTotalValue()<<endl;
	cout<<"Contents:\n"<<sc.getPlaneContents()<<endl;
	//cplane

*/
	return 0;
}

//Expected output below
/*
-----Testing Cargo-----

Success
Success
Success
Success
Could not load item, above max weight by 10.6
Total value: 580.4
Contents:
Generic cargo <250> (50)
Generic cargo <100> (0.2)
Generic cargo <150> (30)
Generic cargo <80.4> (80.4)

-----Testing Passenger-----

Success
Success
Success
Success
Success
Total value: 7000
Contents:
ID0 <1500> (80)
ID1 <1000> (70)
ID2 <1000> (50)
ID3 <2000> (100)
ID4 <1500> (80)

-----Testing Secret Cargo-----

Success
Success
Success
Success
Total value: 0
Contents:
Not permitted
*/
