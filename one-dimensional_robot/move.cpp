#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector <float> move(vector <float> p, int motion, float pExact, float pOvershoot, float pUndershoot)
{
	vector <float> r (p.size());
	float sum = 0.0;

	//cout << "test move" << endl;

	for (int i = 0; i < p.size(); ++i)
	{
		// I learned that the module operator acts differently in C++ than in Python.  It behaves differently with negatives.
		//sum = pExact * p[(i - motion) % p.size()];
		//sum = sum + pOvershoot * p[(i - motion - 1) % p.size()];
		//sum = sum + pUndershoot * p[(i - motion + 1) % p.size()];
		//r.push_back(sum);
		//sum = 0.0;

		if ((i - motion) < 0)
		{
			sum = pExact * p[(i - motion) + p.size()];
		}
		else
		{
			sum = pExact * p[(i - motion) % p.size()];
		}

		if ((i - motion - 1) < 0)
		{
			sum = sum + pOvershoot * p[(i - motion - 1) + p.size()];
		}
		else
		{
			sum = sum + pOvershoot * p[(i - motion - 1) % p.size()];
		}

		if ((i - motion + 1) < 0)
		{
			sum = sum + pUndershoot * p[(i - motion + 1) + p.size()];
		}
		else
		{
			sum = sum + pUndershoot * p[(i - motion + 1) % p.size()];
		}

		r[i] = sum;
	}
	
	return r;

}