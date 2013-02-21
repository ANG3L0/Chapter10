Wrapper for stl set class.  Exercise in Bjarne:
make set class to do union, symmetric set difference, and intersection

Didn't implement set class and instead did a wrapper instead.
Reason being didn't wanna deal with memory leaks.

Consider the following:
	class Set{
		struct Node{
		int value;
		Node* left;
		Node* right;
	};
	Node* root;
	public: /* junk here*/
	}

If I had a method insert(Node), in the method I'd have to
dynamically allocate nodes (it is a tree, it can't be helped).

I can't just instantiate a copy of Node with some value and then point
to it with left or right, because it would be created in 
insert(), which means it would be created on a stack.
Once insert() is out of scope, the memory for whatever
left or right is pointing to will no longer be allocated,
which means it can be overwritten.

So no big deal, just a new keyword in insert.

But then deleting it will be a pain also.  I cannot just do:
delete root or delete[] root, because it is a tree structure.
So for the destructor, I'd have to write a while loop to
BFS down the tree structure and delete each node "manually."

TL;DR I am a pussy and do not want to deal with memory leaks
on my computer so I wrote a wrapper with trusty STL set instead.
I think they should have a site called GitJournal so I can 
do more stuff like this and justify why I didn't do work.
