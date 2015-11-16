#ifndef _MYVECTOR_H
#define _MYVECTOR_H
#include<iostream>
#include<iterator>
using namespace std;

namespace MyVector {
	//实现自己的vector,动态增长的数组
	template <typename Object>
	class Vector
	{
	private:
		int theSize;
		int theCapacity;
		Object *objects;
	public:
		explicit Vector(int initSize = 0)			//构造函数
			:theSize(initSize), theCapacity(initSize + 2)
		{
			objects = new Object[theCapacity];
		}

		Vector(const Vector &rhs) :object(NULL)   //复制拷贝构造函数
		{
			operator=(rhs);
		}
		~Vector()
		{
			delete[] objects;
		}

		const Vector &operator=(const Vector &rhs)   //=运算符重载
		{
			if (this != rhs)		//不是复制自身的话，则开辟新的空间
			{
				delete[] objects;  //释放掉原有数据
				theSize = rhs.size();
				theCapacity = rhs.theCapacity;
				objects = new Object[capacity];
				for (int k = 0; k<size(); k++)
					objects[k] = rhs.objects[k];
			}
			return *this;
		}
		void resize(int newSize)
		{
			if (newSize>ttheCapacity)
				reserve(newSize * 2 + 1);
			theSize = newSize;
		}
		void reserve(int newCapacity)	//需要动态增加数组空间
		{
			if (newCapacity<theSize)
				return;
			Object *oldArray = objects;

			objects = new Object[newCapacity];
			for (int k = 0; k<theSize; k++)
				objects[k] = oldArray[k];
			theCapacity = newCapacity;
			delete[] oldArray;
		}

		Object &operator[](int index)  //[]运算符重载
		{
			return	objects[index];
		}
		const Object &operator[](int index)	const
		{
			return objects[index];
		}

		bool empty()const
		{
			return size() == 0;
		}
		int size() const
		{
			return theSize;
		}
		int capacity() const
		{
			return theCapacity;
		}

		void push_back(const Object &x)   //push_back
		{
			if (theSize == theCapacity)
				reserve(2 * theCapacity + 1);
			objects[theSize++] = x;
		}

		void pop_back()
		{
			theSize--;
		}
		const Object &back() const
		{
			return objects[theSize - 1];
		}

		typedef Object* iterator;   //内置的迭代器iterator
		typedef const Object * const_iterator;
		iterator begin()
		{
			return &objects[0];
		}
		const_iterator begin()	const
		{
			return *objects[0];
		}
		iterator end()
		{
			return &objects[size()];
		}
		const_iterator end()	const
		{
			return &objects[size()];
		}

	};
}
void test_Vector()
{
	MyVector::Vector<int> vec(2);
	cout << vec.capacity() << endl;
	vec[0] = 1;
	vec[1] = 2;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	cout << vec.capacity() << endl;
	cout << vec[0] << vec[1] << vec[2] << vec[3] << vec[4] << endl;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
	}
}

#endif
