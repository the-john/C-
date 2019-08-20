#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector <float> move(vector <float> p, int motion, vector <string> world, float pExact, float pOvershoot, float pUndershoot)
{
	vector <float> q;
	float sum = 0.0;

	//cout << "test move" << endl;

	for (int i = 0; i < p.size(); ++i)
	{
		sum = pExact * p[(i - motion) % p.size()];
		sum = sum + pOvershoot * p[(i - motion) % p.size()];
		sum = sum + pUndershoot * p[(i - motion) % p.size()];
		q.push_back(sum);
	}
	
	return q;

}