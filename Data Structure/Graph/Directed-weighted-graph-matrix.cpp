#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
	vector<vector<int>> matrix;

public:

	Graph(int Count)
	{
		matrix.resize(Count);
		for (int i = 0; i < Count; i++)
		{
			matrix[i].resize(Count);
			for (int q = 0; q < Count; q++)
			{
				matrix[i][q] = 0;
			}
		}
	}

	void print()const
	{
		for (auto neighbours : matrix) {
			for (auto neighbour : neighbours) {
				cout << neighbour << " ";
			}
			cout << "\n";
		}
	}

	void connect(int col, int row, int weight = 1)
	{
		matrix[col][row] = weight;
	}
};

int main ()
{

	Graph G(4);

	G.connect(0,2);
	G.connect(1, 2);
	G.connect(3, 2);
	G.connect(2, 3);
	G.connect(2, 0);

	G.print();


	int bra;
	cin >> bra;
	return 0;
}
