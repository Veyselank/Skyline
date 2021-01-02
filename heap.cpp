#include <iostream>
#include <string>
#include "heap.h"

using namespace std;

void heap::drawSkyline()
{
	if(xArray[1].x_c != 0) // skyline starts from the 0
	{
		cout << "0 " << max << endl;
	}	

	for (int i = 1; i < xArray.size(); i++)
	{
		if (xArray[i].Pos == "L") // adding height to heap if x coor is at the left
		{
			insert(xArray[i].building,xArray[i].height);

			for (; (i < xArray.size() -1 && xArray[i].x_c == xArray[i + 1].x_c);i++) // more than one building shares sam x coor
			{
				if (xArray[i + 1].Pos == "R") // remove the height if x coordinate is at the right
				{
					remove(xArray[i + 1].building);
				}
				if (xArray[i + 1].Pos == "L") // add  height if x coordinate is at the left
				{
					insert(xArray[i + 1].building,xArray[i + 1].height);
				}
			}

			if (yArray[1].heightY != max) // check if the max has changed
			{
				max = yArray[1].heightY;
				cout << xArray[i].x_c << " " << max << endl;
			}
		}
		else if (xArray[i].Pos == "R") // remove the height, when x is at the left
		{
			remove(xArray[i].building);

			for (; (i < xArray.size() - 1 && xArray[i].x_c == xArray[i + 1].x_c); i++)
			{
				if (xArray[i + 1].Pos == "R") // remove the height if x coordinate is at the right
				{
					remove(xArray[i + 1].building);
				}
				if (xArray[i + 1].Pos == "L") // add  height if x coordinate is at the left
				{
					insert(xArray[i + 1].building,xArray[i + 1].height);
				}
			}

			if (yArray[1].heightY != max) // check if the max has changed
			{
				max = yArray[1].heightY;
				cout << xArray[i].x_c << " " << max << endl;
			}
		}
	}
}

void heap::insert(int l, int h)
{
	size += 1;
	int empytSlot = size;

	while (h > yArray[empytSlot / 2 ].heightY && empytSlot > 1)
	{
		yArray[empytSlot] = move(yArray[empytSlot / 2]);
		PosArr[yArray[empytSlot].buildingY] = empytSlot;
		empytSlot /= 2;
	}
	yArray[empytSlot].heightY = h;
	yArray[empytSlot].buildingY = l;
	PosArr[yArray[empytSlot].buildingY] = empytSlot;
}

void heap::heapSort(vector <x> & temp)
{
	for (int i = temp.size() / 2; i>=0; i--)
	{
		downX(temp,i,temp.size());
	}

	for (int k = temp.size() - 1; k > 0; k--)
	{
		swap(temp[0], temp[k]);
		downX(temp, 0, k);
	}
}

void heap::insertX(int label, string pos, int x_coor, int h)
{
	if (pos == "L")
	{
		xArray[label].building = (label +1) /2;
	}

	if (pos == "R")
	{
		xArray[label].building = label / 2;
	}
	xArray[label].Pos = pos;
	xArray[label].x_c = x_coor;
	xArray[label].height = h;
}

bool heap::isEmpty() 
{
	return (yArray[1].buildingY == 0);
}

void heap::remove(int label)
{
	if (!isEmpty())
	{
		yArray[PosArr[label]] = yArray[size];
		yArray[size].buildingY = 0;
		yArray[size--].heightY = 0;
		downY(PosArr[label]);
	}
}

void heap::sort()
{
	heapSort(xArray);
}

void heap::downX(vector <x> & vec, int i, int j)
{
	int sub; x temp;

	for (temp = vec[i]; (2 * i) + 1 < j; i = sub)
	{
		sub = (2 * i) + 1;
		if(sub != j - 1 && vec[sub].x_c < vec[sub +1].x_c)
		{
			sub++;
		}
		if (vec[sub].x_c > temp.x_c)
		{
			vec[i] = vec[sub];
		}
		else
			break;
	}

	vec[i] = temp;
}

void heap::downY(int emptySlot)
{
	int sub; y temp = yArray[emptySlot];

	for (; emptySlot * 2 <= size; emptySlot = sub)
	{
		sub = emptySlot * 2;
		if(sub != size && yArray[sub + 1].heightY > yArray[sub].heightY)
		{
			sub++;
		}
		if (yArray[sub].heightY > temp.heightY)
		{
			yArray[emptySlot] = yArray[sub];
		}
		else
			break;
	}
	yArray[emptySlot] = temp;
}