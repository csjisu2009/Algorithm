//44m

#include <iostream>
using namespace std;

int main() {
	int N;
	int num[100], s[100], b[100];

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i] >> s[i] >> b[i];

	int countS, countB, NCorrectSB, result = 0;
	for (int h = 1; h <= 9; ++h) {
		
		for (int t = 1; t <= 9; ++t) {
			if (h == t) continue;
			
			for (int o = 1; o <= 9; ++o) {
				if (h == o || t == o) continue;
				
				NCorrectSB = 0;
				for (int i = 0; i < N; ++i) {
					countS = 0;
					countB = 0;

					//hundred's Strike, others Ball
					if ( h == num[i] / 100 )
						countS++;
					else if ( h == (num[i] % 100) / 10
						     || h == num[i] % 10 )
						countB++;
					//ten's Strike, others Ball
					if (t == (num[i] % 100) / 10)
						countS++;
					else if (t == num[i] / 100
						|| t == num[i] % 10)
						countB++;
 					//one's Strike, others Ball
					if (o == num[i] % 10)
						countS++;
					else if (o == num[i] / 100
						|| o == (num[i] % 100) / 10 )
						countB++;
					
					if (countS == s[i] && countB == b[i])
						NCorrectSB++;
				}
				if (NCorrectSB == N)
					result++;
			}
		}
	}

	cout << result << endl;
	
	return 0;
}