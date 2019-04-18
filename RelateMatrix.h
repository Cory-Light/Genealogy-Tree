#pragma once

class RelateMatrix
{
    public:
        RelateMatrix();
        void addEdge(int person, int family);
        bool hasEdge(int person, int family);
        void relate(int person1, int person2);
        void testPrint();
        
    private:
        int const static arrSize = 100; //max number of potential people and families

        bool relateMatrix[arrSize][arrSize];



};