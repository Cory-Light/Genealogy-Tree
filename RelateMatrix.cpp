#include <iostream>
#include "queueList.h"
#include "RelateMatrix.h"
#include <vector>
using namespace std;

RelateMatrix::RelateMatrix()
{
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            relateMatrix[i][j] = 0;
        }
    }
}

void RelateMatrix::addEdge(int person, int family)
{
    relateMatrix[person][family] = 1;
}
bool RelateMatrix::hasEdge(int person, int family)
{
    if(relateMatrix[person][family])
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void RelateMatrix::relate(int person1, int person2)
{
    queue holderQ, path, goThrough; 
	vector<int> next;
    int print[arrSize], distanceToStart[arrSize], pathArr[arrSize], prev[arrSize];
    bool beenVisited[arrSize][arrSize];

    for(int a = 0; a < arrSize; a++)//set false variables to check off of 
    {
        for(int b = 0; b < arrSize; b++)
        {
            beenVisited[a][b] = false;
        }
        distanceToStart[a] = -10;
        pathArr[a] = -10;
        prev[a] = -10;
    }

    bool alternate = false;

    int curr = person1;

    holderQ.push(person1);

    distanceToStart[person1] = 0;

	goThrough.push(person1);

    while (!holderQ.empty())
	{
		curr = holderQ.front();
		holderQ.pop();

		for(int i = 0; i < arrSize; i++)
		{
			if(hasEdge(curr, i) && !beenVisited[curr][i])
			{
				beenVisited[curr][i] = 1;

				if(curr != person1){distanceToStart[i] = distanceToStart[curr] + 1;}
				else{	/*just skip over and ignore when this happens*/	}
				
			}
		}
	}
}
void RelateMatrix::testPrint()
{
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            cout << relateMatrix[i][j] << " ";
        }
        cout << endl;
    }
}