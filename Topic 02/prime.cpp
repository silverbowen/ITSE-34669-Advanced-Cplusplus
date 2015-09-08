#include "prime.h"

using namespace std;

bool IsPrime(int n)
{
	for (int divisor=2; divisor < n; ++divisor)
		if ((n%divisor)==0) return false;
	return true;
}

vector<int> FindPrimes(int start, int end)
{
	vector<int> Primes;
	while (start <= end)
	{
		if (start > 1 && IsPrime(start))
			Primes.push_back(start);
		start++;
	}
	return Primes;
}
