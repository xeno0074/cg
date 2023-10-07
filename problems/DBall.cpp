#include <vector>
#include <iostream>

using namespace std;

namespace g
{
	int n;
	vector<int> B, I, R;
}

class FT
{
	int n;
	vector<int> tree;
};

void readIO()
{
	cin >> g::n;
	g::B.resize(g::n);
	g::I.resize(g::n);
	g::R.resize(g::n);

	for (int &x : g::B)
		cin >> x;
	for (int &x : g::I)
		cin >> x;
	for (int &x : g::R)
		cin >> x;
}

int getSuicidesBF()
{
	int num_suicides = 0;
	for (int selected_lady = 0; selected_lady < g::n; ++selected_lady)
	{
		for (int other_lady = 0; other_lady < g::n; ++other_lady)
		{
			bool commit = (g::B[selected_lady] < g::B[other_lady]) &&
						  (g::I[selected_lady] < g::I[other_lady]) &&
						  (g::R[selected_lady] < g::R[other_lady]);

			if (commit)
				++num_suicides;
		}
	}
	return num_suicides;
}

int getSuicidesFT()
{
}

int main()
{
	readIO();

	cout << getSuicidesBF() << "\n";

	return 0;
}
