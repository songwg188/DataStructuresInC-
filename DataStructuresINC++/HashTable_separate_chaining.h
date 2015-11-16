#ifndef  _HASHTABLE_SEPARATE_CHANNING_H_
#define _HASHTABLE_SEPARATE_CHANNING_H_
#include<vector>
#include<string>
#include<list>
#include<iostream>
#include<algorithm>
using namespace std;
//��ϣ��--��������
int Hash_myself(const string &key);     //ɢ�к���
int Hash_myself( const int key);
int nextPrime(int n);

template<typename T>
class HashTable
{
public:
	explicit HashTable(int size = 101) 
		:currentSize (0)
	{	
		theLists.resize(size);
	}

	bool contains(const T & x ) const 
	{
		 const list<T> & obj = theLists[myhash(x)];  //�õ����ܻ���������
		 return find(obj.begin(),obj.end(),x)!=obj.end() ;
	}
	bool insert(const T &x) 
	{
		list<T> &obj = theLists[myhash(x)];  //�õ����ܻ���������
		if (find(obj.begin(), obj.end(), x) != obj.end())
			return false;
		obj.push_back(x);
		if (++currentSize > theLists.size())
			rehash();

		return true;
	}
	bool remove(const T&x) 
	{
		list<T> &obj = theLists[myhash(x)]; 
		auto pos = find(obj.begin(), obj.end(), x);
		if(pos==obj.end())
			return false;
		obj.erase(pos);
		--currentSize;
		return true;
	}
	void makeEmpty() 
	{
		for (int i = 0; i < theLists.size(); i++)
		{
			theLists[i].clear();
		}
	}

private:
	vector<list<T>> theLists;  //the array of Lists
	int currentSize;

	void rehash() 
	{
		vector<list<T> > oldLists = theLists;

		// Create new double-sized, empty table
		theLists.resize(nextPrime(2 * theLists.size()));
		for (int j = 0; j < theLists.size(); j++)
			theLists[j].clear();

		// Copy table over
		currentSize = 0;
		for (int i = 0; i < oldLists.size(); i++)
		{
			list<T>::iterator itr = oldLists[i].begin();
			while (itr != oldLists[i].end())
				insert(*itr++);
		}
	}
	int myhash(const T & x) const   //���ش�������X ����vector�����е��ĸ�λ��
	{
		int hashVal = Hash_myself(x);
		hashVal %= theLists.size();
		if (hashVal < 0)
			hashVal += theLists.size();
		return hashVal;
	}
};




#endif
