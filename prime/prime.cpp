#include <iostream>
#include <fstream>
#include <bitset>
#include <cmath>
#include <ctime>
using namespace std;

// sieving all prime numbers less than n
const long long n = (long long)1e10;
bitset<n / 2> is_prime;

int main()
{
	clock_t start, end;
	start = clock();

	is_prime.set();
	for (long long i = 3; i < sqrt(n); i += 2)
	{
		if (is_prime[i / 2])
		{
			for (long long j = i * i; j < n; j += i * 2)
			{
				is_prime[j / 2] = 0;
			}
		}
	}

	end = clock();
	cout << "time cost(s): " << (end - start) / 1000.0 << endl;

	//ofstream f("prime.txt");
	//f << 2 << "\n";
	long long cnt = 1;
	for (long long i = 3; i < n; i += 2)
	{
		if (is_prime[i / 2])
		{
			cnt += 1;
			//f << i << "\n";
		}
	}

	cout << "prime number counts: " << cnt << endl;
	//f.close();
	getchar();
	return 0;
}
