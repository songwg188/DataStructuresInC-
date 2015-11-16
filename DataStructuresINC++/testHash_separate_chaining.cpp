#include"HashTable_separate_chaining.h"

/**
* Internal method to test if a positive number is prime.
* Not an efficient algorithm.
*/
bool isPrime(int n)
{
	if (n == 2 || n == 3)
		return true;

	if (n == 1 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

/**
* Internal method to return a prime number at least as large as n.
* Assumes n > 0.
*/
int nextPrime(int n)
{
	if (n % 2 == 0)
		n++;

	for (; !isPrime(n); n += 2)
		;

	return n;
}

int Hash_myself(const string &key)     //É¢ÁÐº¯Êý
{
	int hashVal = 0;
	for (int i = 0; i < key.length(); i++)
		hashVal = 37 * hashVal + key[i];
	return hashVal;
}
int Hash_myself(const int key)
{
	return key;
}
void testHash_separate_chaining()
{
	HashTable<int> H;

	const int NUMS = 4000;
	const int GAP = 37;
	int i;

	cout << "Checking... (no more output means success)" << endl;

	for (i = GAP; i != 0; i = (i + GAP) % NUMS)
		H.insert(i);
	for (i = 1; i < NUMS; i += 2)
		H.remove(i);

	for (i = 2; i < NUMS; i += 2)
		if (!H.contains(i))
			cout << "Contains fails " << i << endl;

	for (i = 1; i < NUMS; i += 2)
	{
		if (H.contains(i))
			cout << "OOPS!!! " << i << endl;
	}

}
int main()
{
	testHash_separate_chaining();
}