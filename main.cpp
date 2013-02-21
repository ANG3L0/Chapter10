#include "Intset.h"

int main(){
	IntSet a;
	IntSet b;
	IntSet c;
	int aa[] = {1,2,3,4,5,6};
	vector <int> aaset(aa,aa+sizeof(aa)/sizeof(int));
	a.array2IntSet(aaset);
	int bb[] = {4,5,6,7,8};
	vector <int> bbset(bb,bb+sizeof(bb)/sizeof(int));
	b.array2IntSet(bbset);
	a.printSet();
	b.printSet();
	cout << endl << endl;
	//test union
	c=a+b;
	cout << "Set union:\n";
	c.printSet();
	//test difference
	c=a-b;
	cout << "Set symmetric difference:\n";
	c.printSet();
	//test intersection
	c=a&b;
	cout << "Set intersection:\n";
	c.printSet();
	return 0;
}