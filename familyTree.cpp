#include "familyTree.h"
#include <iostream>

using namespace std;

FamilyTree::FamilyTree() {
	for(int i = 0; i < maxFamilies; i ++)
	{
		for(int j = 0; j < numChildren; j++)
		{
			familyArr[i].childPerson[j] = 0;
		}
		
	}
}

void FamilyTree::addPersonEdge(int person, int family, int type) {
        if(type == 1)
        {
                personArr[person].parentFamily = family;
        }
        if(type == 2)
        {
                personArr[person].marriageFamily = family;
        }
}
void FamilyTree::addFamilyEdge(int family, int person, int type){
        if(type == 3)
        {
                familyArr[family].husbandPerson = person;
	}
	if(type == 4)
	{
		familyArr[family].wifePerson = person;
	}
}
void FamilyTree::addChildEdge(int family, int person, int type, int childIndex)
{
	familyArr[family].childPerson[childIndex] = person;
}
void FamilyTree::printFamilyArray()
{
	for(int i = 1; i < maxFamilies; i++)
	{
		if(familyArr[i].husbandPerson != 0)
	       	{
			cout << "Family " << i << "'s husband is person " << familyArr[i].husbandPerson << endl;
		}
		if(familyArr[i].wifePerson != 0)
                {
                        cout << "Family " << i << "'s wife is person " << familyArr[i].wifePerson << endl;
		}
		for(int j = 0; j < numChildren; j++)
		{
			if(familyArr[i].childPerson[j] == 0){break;}
			cout << "Family " << i << "'s child is person " << familyArr[i].childPerson[j] << endl;
		}
	}
}
void FamilyTree::printPersonArray()
{
	for(int i = 1; i < maxPeople; i++)
        {
                if(personArr[i].parentFamily != 0)
                {
                        cout << "Person " << i << "'s parent family is family " << personArr[i].parentFamily << endl;
                }
                if(personArr[i].marriageFamily != 0)
                {
                        cout << "Person " << i << "'s marriage family is family " << personArr[i].marriageFamily << endl;
                }
        }
}
void FamilyTree::checkConsistency()
{
	for(int i = 1; i < maxFamilies; i++)
	{
		if(familyArr[i].husbandPerson == 1)
		{
		}
	}
}
