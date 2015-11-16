#ifndef _BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<iostream>

//ͷ�ļ��а�����BinarySearchTree��Ľӿڣ�����ʵ����.cpp�ļ���
// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// T findMin( )  --> Return smallest item
// T findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template<typename T>
class BinarySearchTree{

public:
	BinarySearchTree(): root(NULL){}
	explicit BinarySearchTree(const BinarySearchTree &rhs):root(NULL){*this = rhs;}  //explicit  ��ֹ�����������class A =B;
	~BinarySearchTree(){ makeEmpty(); };

	const T &findMax() const	{ return findMax(root)->element; }
	const T &findMin() const { return findMin(root)->element; }
	bool contains(const T &x) const		{ return contains(x,this->root); }
	bool isEmpty() const	{ return root ==NULL ;}
	void printTree() const	{ 	
		if(isEmpty())
			cout<<"Empty Tree"<<endl;
		printTree(root);
	}

	void makeEmpty() { makeEmpty( root); }
	void insert(const T &x){ insert(x,root);}
	void remove(const T &x) { remove(x,root); }

	const BinarySearchTree &operator=(const BinarySearchTree &rhs)  //use clone()
	{
		if(this!= &rhs)    //�����ɾ��ԭ�ȵ����ݣ��ٽ��и���
		{
			makeEmpty( );
			root=clone(rhs.root);
		}

		return *this;
	}


private:
	struct BinaryNode{
		T element;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const T &theElement,BinaryNode *lt,BinaryNode *rt)
			:element(theElement),left(lt),right(rt)
		{}
	};

	BinaryNode *root;

	void insert(const T &x,BinaryNode * &t);
	void remove(const T &x,BinaryNode * &t);
	BinaryNode  *findMin(BinaryNode *t) const;
	BinaryNode *findMax(BinaryNode *t) const ;
	bool contains(const T &x,const BinaryNode *t) const;
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t)const;
	BinaryNode *clone(BinaryNode *t) const;

};//class




#endif