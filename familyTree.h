 class FamilyTree
{
        public:
		FamilyTree();
                void addPersonEdge(int person, int family, int type);
                void addFamilyEdge(int family, int person, int type);
		void addChildEdge(int family, int person, int type, int childIndex);
		void printFamilyArray();
		void printPersonArray();

                void checkConsistency();
                void Dijkstras(int person1, int person2);

        private:
		struct Individual {
                        int parentFamily = -10;
                        int marriageFamily = -10;
                };
                struct Family {
                        int husbandPerson = -10;
                        int wifePerson = -10;
			int const static numChildrenMax = 10;
                        int childPerson[numChildrenMax];
                };
		int const static numChildren = 10;
                int const static maxPeople = 100;
                Individual personArr[maxPeople];
                int const static maxFamilies = 100;
                Family familyArr[maxFamilies];


};
