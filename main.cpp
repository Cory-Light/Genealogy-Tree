#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "familyTree.h"
#include "RelateMatrix.h"


using namespace std;

int main() {
	string holder;
	string tempWord;
	stringstream strs;
	int num;
	int const maxFamilySize = 13;
	int intList[maxFamilySize];
	int z;
	FamilyTree familyTree;
	RelateMatrix matrix;

	ifstream infile;
	infile.open("test.txt");
	//infile.open("data.family.txt");

	while (getline(infile,holder))
	{
		z = 0;
		strs.str(""); // inialize the string to an empty string
		strs.clear();

		strs << holder;

		while(strs >> tempWord)
		{
			//cout << tempWord << endl;

			if(stringstream(tempWord) >> num)
			{
				intList[z] = num;
				z++;
			}
		}

		for(z = z; z< maxFamilySize; z++)
		{
			intList[z] = -10; // This is to identify when the list of children stop
		}

		/*for(int p = 0; p < maxFamilySize; p++)
		{
			if(intList[p] == -10){break;}
			cout << p << ". " << intList[p] << endl;
		}*/

		if(holder[0] == 'I')
		{
			familyTree.addPersonEdge(intList[0], intList[1], 1);
			familyTree.addPersonEdge(intList[0], intList[2], 2);
			cout << "Individual " << intList[0] << " has parents " << intList[1] << " and is married in family " << intList[2] << endl;
			matrix.addEdge(intList[0], intList[1]);
			matrix.addEdge(intList[0], intList[2]);
		}

		if(holder[0] == 'F')
        {
			familyTree.addFamilyEdge(intList[0], intList[1], 3);
			familyTree.addFamilyEdge(intList[0], intList[2], 4);
			matrix.addEdge(intList[0], intList[1]);
			matrix.addEdge(intList[0], intList[2]);
			for(int o = 3; o < maxFamilySize; o++)
			{
				if(intList[o] == -10){break;}
				familyTree.addChildEdge(intList[0], intList[o], 5, (o - 3));
				matrix.addEdge(intList[0], intList[o]);
				//cout << o << intList[o] << endl;
            }
			cout << "Family " << intList[0] << " has husband " << intList[1] << ", wife " << intList[2] << " and children ";
			// for(int o = 3; o < maxFamilySize; o++)
			// {
			// 	if(intList[o] == -10){break;}
			// 	cout << intList[o] << " ";
			// 	//cout << o << intList[o] << endl;
            // }
			cout << endl;
		}
		
		if(holder[0] == 'C')
        {
			familyTree.checkConsistency();
        }
		
		if(holder[0] == 'R')
        {
			matrix.relate(intList[0], intList[1]);
        }
	}	
	//familyTree.printFamilyArray();
	//familyTree.printPersonArray();
	//matrix.testPrint();
	return 0;
}
