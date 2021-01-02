#include <iostream>
#include <vector>

using namespace std;

struct x // x coordinate of the buiding 
{
	int height; 
	int x_c;
	int building;
	string Pos;
	x()
	{
		// Initialization
		height = 0;
		x_c = -1;
		Pos = "";
		building = 0;
	}
};
struct y
{
	int buildingY;
	int heightY;
	y()
	{
		buildingY = 0;
		heightY = 0;
	}
};	

class heap
{
private:
	int max; // store the max
	int size; // store the size

	vector <int> PosArr; // locations array
	vector <x> xArray; // x coordinates array
	vector <y> yArray; // y coordinates array

	void remove(int);
	void downY(int);
	void downX(vector<x>&, int, int);
	bool isEmpty();
	void insert(int,int);
	y getMax();
	void heapSort(vector <x>&);

public:
	heap(int i)
		:max(0), size(0), yArray(i + 1), xArray( 2 * i + 1), PosArr(i +1) {}
	
	void drawSkyline();
	void sort();
	void insertX(int, string, int, int);
};