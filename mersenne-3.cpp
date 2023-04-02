#include <iostream>
#include <chrono>
using namespace std;
#define int long long
int mod;//지금 체크하는 소인수 후보
int mul2(int p)
{
	int v = 1LL << p;
	v %= mod;
	//2^p를 소인수 후보로 나눴을 때 나머지
	return v - 1;//이 값이 0이면 소수가 아님
}
signed main()
{
	while (1)
	{
		int p;
		cout << "체크할 p를 입력하세요 : ";
		cin >> p;
		auto start = chrono::high_resolution_clock::now();//chrono=나노초 단위의 시간 계산
		int i;
		int isp = 1;
		for (i = 1; 2*p*i+1 <= sqrt((1LL << p) - 1); i++)
		{
			mod = 2*p*i+1;//현재 i를 체크하도록 설정
			if (mul2(p) == 0)
			{
				if (isp)
					cout << mod << "로 나누어떨어짐\n";
				isp = 0;
			}
		}
		if (isp)
		{
			cout << (1LL << p) - 1 << "는 소수\n";
		}
		auto finish = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() / (1000000.0) << "밀리초\n";
	}

}//t