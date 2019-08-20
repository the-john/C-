// one-dimensional_robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#include "one-dimensional_robot.h"

int main()
{
    //cout << "Hello World!\n";

	vector <float> p(5, 0.2);
	vector <string> world;
	vector <string> measurements;
	vector <int> motions(2, 1);

	world.push_back("green");
	world.push_back("red");
	world.push_back("red");
	world.push_back("green");
	world.push_back("green");

	measurements.push_back("red");
	measurements.push_back("green");

	float pHit = 0.6;
	float pMiss = 0.2;
	float pExact = 0.8;
	float pOvershoot = 0.1;
	float pUndershoot = 0.1;
	
	for (int i = 0; i < measurements.size(); ++i)
	{
		p = sense(p, measurements[i], world, pHit, pMiss);
		p = move(p, motions[i], pExact, pOvershoot, pUndershoot);
	}
	
	for (int j = 0; j < world.size(); ++j)
	{
		cout << p[j] << ", ";
	}
	cout << endl;

	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
