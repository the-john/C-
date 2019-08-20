#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector <float> sense(vector <float> p, string measurement, vector <string> world, float pHit, float pMiss)
{
	vector <float> q;
	float sum = 0.0;
	int hit = 0;
	
	//cout << "test sense" << endl;

	for (int i = 0; i < p.size(); ++i)
	{
		if (measurement == world[i])
		{
			hit = 1;
		}
		q.push_back(p[i] * (hit * pHit + (1 - hit) * pMiss));
		hit = 0;
	}

	for (int j = 0; j < q.size(); ++j)
	{
		sum += q[j];
	}

	for (int k = 0; k < q.size(); ++k)
	{
		q[k] = q[k] / sum;
	}

	return q;
}
