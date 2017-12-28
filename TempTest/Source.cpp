#include <iostream>
using namespace std;

template <typename T>
T GetMax(T a, T b) {
	T result;
	result = (a > b) ? a : b;
	return (result);
}

template <class T>
class mypair {
	T a, b;
public:
	mypair(T first, T second) {
		a = first; b = second;
	}

	T getmax();
};

template <class T>
T mypair<T>::getmax() {
	T retval;
	retval = a > b ? a : b;
	return retval;
}

template int GetMax<int>(int a, int b);

template <bool Predicate, typename Result = void>
class TEnableIf;

template <typename Result>
class TEnableIf<true, Result>
{
public:
	typedef Result Type;
};

template <typename Result>
class TEnableIf<false, Result>
{ };

typename TEnableIf<true, int>::Type testS() {
	cout << "hello" << endl;
	return 0;
}

int main() {
	int i = 5, j = 6, k;
	long l = 10, m = 10, n;
	k = GetMax<int>( i, j );
	// n = GetMax<long>( l, m );
	n = GetMax(l, m);
	cout << k << endl;
	cout << n << endl;

	mypair <int> myobject(100, 75);
	cout << myobject.getmax();

	testS();

	getchar();
	return 0;
}