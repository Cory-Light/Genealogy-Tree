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
                        int parentFamily = 0;
                        int marriageFamily = 0;
                };
                struct Family {
                        int husbandPerson = 0;
                        int wifePerson = 0;
			int const static numChildrenMax = 10;
                        int childPerson[numChildrenMax];
                };
		int const static numChildren = 10;
                int const static maxPeople = 100;
                Individual personArr[maxPeople];
                int const static maxFamilies = 100;
                Family familyArr[maxFamilies];


};
