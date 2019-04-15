#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include ""
using namespace std;

int main()
{
	string holder;
	string tempWord;
	stringstream strs;
	AdjMatrix familyMatrix;
	int num;
	int const maxFamilySize = 13;
	int intList[maxFamilySize];
	int z;
	string parent = "parent";// this is type 1
	string marriage = "marriage";// this is type 2
	string husband = "husband";// this is type 3
	string wife = "wife";// this is type 4
	string child = "child";// this is type 5

	cout << "parent = 1 " << endl;
	cout << "marriage = 2 " << endl;
	cout << "husband = 3 " << endl;
	cout << "wife = 4 " << endl;
	cout << "child = 5 " << endl;


	ifstream infile;

	infile.open("test.txt");
	//infile.open("data.family.txt");


	while (getline(infile, holder))
	{
		z = 0;

		strs.str(""); // initialize to an empty string
		strs.clear();

		strs << holder;

		while (strs >> tempWord)
		{
			//cout << tempWord << endl;

			if (stringstream(tempWord) >> num)
			{
				intList[z] = num;
				z++;
			}

		}

		for (z; z < maxFamilySize; z++)
		{
			intList[z] = -10; // set this to an array index that doesn't exist
		}
		/*for (int p = 0; p < maxFamilySize; p++)
		{
		if (intList[p] == -10) { break; }
		cout << p << ". " << intList[p] << endl;
		}*/


		if (holder[0] == 'I')
		{
			familyMatrix.addPersonEdge(intList[0], intList[1], 1);
			familyMatrix.addPersonEdge(intList[0], intList[2], 2);
		}

		if (holder[0] == 'F')
		{
			familyMatrix.addFamilyEdge(intList[0], intList[1], 3);
			familyMatrix.addFamilyEdge(intList[0], intList[2], 4);
			for (int o = 3; o < maxFamilySize; o++)
			{
				if (intList[o] == -10) { break; }
				familyMatrix.addFamilyEdge(intList[0], intList[o], 5);
			}
		}
		if (holder[0] == 'C')
		{
			//familyMatrix.checkAccuracy();
		}
	}

	familyMatrix.printRelation();

	//familyMatrix.print();

	system("pause");
	return 0;
}
