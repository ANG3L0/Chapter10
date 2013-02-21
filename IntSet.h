#ifndef INTSET_H
#define INTSET_H

#include <iostream>;
using namespace std;
#include <vector>;
#include <set>;

class IntSet{
	set<int> s;
public:
	IntSet operator+(IntSet); //set union
	IntSet operator-(IntSet); //set difference
	IntSet operator&(IntSet); //set intersection
	IntSet array2IntSet(vector <int>);
	void insert(int);
	IntSet copy(IntSet);
	void printSet();
};

#endif