#include"BinarySearchTree.h"
using namespace std;
//查找树  ，其定义与实现完全分离
template<typename T>
void BinarySearchTree<T>:: insert(const T &x,BinaryNode * &t)
{
	if(t==NULL)
		t=new BinaryNode(x,NULL,NULL);
	if(x < t->element)
		insert(x,t->left);
	else if(x> t->element)
		insert(x,t->right);
	else
		;

}
template<typename T>
void BinarySearchTree<T> :: remove(const T &x,BinaryNode * &t)
{
	if(t==NULL) return;
	if( x<t->element ) remove(x,t->left);
	else if(x > t->element) remove(x,t->right);
	else if(t->left!=NULL && t->right!=NULL) //two Child
	{
		//MY CODE  代码有问题
		BinaryNode *minNode=findMin(t->right);  //找到右子树最小的结点
		t->element=minNode->element;    //赋值给结点t
		BinaryNode *oldNode=minNode;		//修改书本源代码，添加removeMin()方法，用于删除右子树最小结点
		minNode=(minNode->left!=NULL )? minNode->left : minNode ->right;
		delete oldNode;
		//minNode=NULL;
		//code in book
	/*	t->element=findMin(t->right)->element;
		remove(t->element,t->right);*/    //递归删除，效率较低
			
	}


	else   //one Child
	{
		BinaryNode *oldNode=t;
		t=( t->left!=NULL) ? t->left : t->right;
		delete oldNode;
	}
}


template<typename T>//依赖受限名称不能作为类型看待，除非在它前面加一个关键字：typename
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>:: findMax(BinaryNode *t) const 
{
	if(t==NULL) return t;
	while(t->right)
		t=t->right;
	return t;
}


template<typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>:: findMin(BinaryNode *t) const 
{
	if(t==NULL) return t;
	while(t->left)
		t=t->left;
	return t;
}
template<typename T>
bool BinarySearchTree<T>::contains(const T &x,const BinaryNode *t)const
{
	if(t==NULL)	return false;
	else if( x< t->element)
		return contains(x,t->left);
	else if(x > t->element)
		return contains(x,t->right);
	else
		return true;
}
template<typename T>
void BinarySearchTree<T>::makeEmpty(BinaryNode	* & t)
{
	if(t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t=NULL;
}


template<typename T>
void BinarySearchTree<T> ::printTree(BinaryNode *t)const
{
	if(t)
	{
		printTree(t->left);
		cout<<t->element<<" ";
		printTree(t->right);
	}

}


template<typename T>
typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>:: clone(BinaryNode *t) const
{
	if(t==NULL)	return NULL;
	else
		return new BinaryNode(t->element,clone(t->left), clone(t->right));
}


void test_BinarySerachTree()
{ 
	 BinarySearchTree<int> bst;
	 bst.insert(2);
	 bst.insert(1);
	 bst.insert(3);
	 bst.insert(-1);
	 bst.printTree();
	 	 if(bst.contains(2))
		 cout<<"true"<<endl;
	 else
		 cout<<"false"<<endl;

	cout<<"Max:"<<bst.findMax()<<endl;
	cout<<"Min:"<<bst.findMin()<<endl;

	cout<<"Clone:";
	BinarySearchTree<int> bst_clone;
	bst_clone=bst;
	bst_clone.printTree();
	cout<<endl;
	bst.remove(1);
	bst.printTree();

	
}

 ////int main() 
 ////{
	////test_BinarySerachTree();
	////
 ////}
				