#include"BinarySearchTree.h"
using namespace std;
//������  ���䶨����ʵ����ȫ����
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
		//MY CODE  ����������
		BinaryNode *minNode=findMin(t->right);  //�ҵ���������С�Ľ��
		t->element=minNode->element;    //��ֵ�����t
		BinaryNode *oldNode=minNode;		//�޸��鱾Դ���룬���removeMin()����������ɾ����������С���
		minNode=(minNode->left!=NULL )? minNode->left : minNode ->right;
		delete oldNode;
		//minNode=NULL;
		//code in book
	/*	t->element=findMin(t->right)->element;
		remove(t->element,t->right);*/    //�ݹ�ɾ����Ч�ʽϵ�
			
	}


	else   //one Child
	{
		BinaryNode *oldNode=t;
		t=( t->left!=NULL) ? t->left : t->right;
		delete oldNode;
	}
}


template<typename T>//�����������Ʋ�����Ϊ���Ϳ�������������ǰ���һ���ؼ��֣�typename
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
				