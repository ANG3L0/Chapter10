#include "Intset.h"

//union
IntSet IntSet::operator+(IntSet b){
	//c=a+b
	IntSet c; c.copy(*this); //not necessary because no private pointers,
	//but easier to maintain this way if shit gets changed
	set<int>::iterator it;
	for (it=b.s.begin(); it!=b.s.end(); ++it){
		c.s.insert(*it);
	}
	return c;
}
//symmetric set difference
IntSet IntSet::operator-(IntSet b){
	//c = a tri b
	IntSet c; c.copy(*this);
	set<int>::iterator it;
	set<int>::iterator found;
	for (it=b.s.begin(); it!=b.s.end(); ++it){
		found = this->s.find(*it);
		if (found==this->s.end())
			c.s.insert(*it);
		else
			c.s.erase(*it);
	}
	return c;
}
//set intersection 
IntSet IntSet::operator&(IntSet b){
	//c = a and b
	IntSet c;
	set<int>::iterator it;
	set<int>::iterator found;
	for (it=b.s.begin();it!=b.s.end();++it){
		found=this->s.find(*it);
		if (found!=this->s.end()) //common el betw a and b
			c.insert(*it);
	}
	return c;

}
IntSet IntSet::array2IntSet(vector <int> vec){
	this->s.clear();
	for (int i = 0; i < vec.size(); ++i){
		this->s.insert(vec[i]);
	}
	return *this;
}
void IntSet::insert(int x){
	this->s.insert(x);
}
IntSet IntSet::copy(IntSet a){
	this->s = a.s;
	return *this;
}
void IntSet::printSet(){
	set<int>::iterator it;
	cout << "Set contains: ";
	for (it=this->s.begin(); it!=this->s.end(); ++it){
		cout << ' ' << *it;
	}
	cout << endl;
}