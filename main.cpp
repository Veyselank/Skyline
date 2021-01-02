#include <iostream>
#include <fstream>
#include <sstream>
#include "heap.h"

using namespace std;

int main()
{
	ifstream file;
	string line, height, xR, xL;
	file.open("input4.txt");
	getline(file,line);
	istringstream iss(line);

	heap myHeap(stoi(line));

	
	for (int i = 1; getline(file, line); i++) //Construct the cordinate array
	{
		istringstream iss2(line); //reading from the file 
		iss2 >> xL;
		iss2 >> height;
		iss2 >> xR;

		myHeap.insertX(2 * i - 1, "L", stoi(xL), stoi(height));
		myHeap.insertX(2 * i, "R", stoi(xR), stoi(height));
	}

	myHeap.sort(); //sorts the heap 
	myHeap.drawSkyline(); 

	cin.ignore(); //for debugging
	cin.get(); //for debugging
	return 0;
}