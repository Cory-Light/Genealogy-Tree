#pragma once

class FamilyTree
{
public:
	void addPersonEdge(int person, int family, int type);
	void addFamilyEdge(int family, int person, int type);

	void checkConsistency();
	void Dijkstras(int person1, int person2);

private:
	struct Individual {
		int parentFamily = 0;
		int marriageFamily = 0;
	};
	struct Family {
		int husbandFamily = 0;
		int wifeFamily = 0;
		int child1Family = 0;
		int child2Family = 0;
		int child3Family = 0;
		int child4Family = 0;
		int child5Family = 0;
		int child6Family = 0;
		int child7Family = 0;
		int child8Family = 0;
		int child9Family = 0;
		int child10Family = 0;
	};
	int const static maxPeople = 100;

	Individual personArr[maxPeople];

	int const static maxFamilies = 100;

	Family familyArr[maxFamilies];



};