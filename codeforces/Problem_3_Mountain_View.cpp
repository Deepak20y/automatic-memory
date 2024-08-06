#include <bits/stdc++.h>
using namespace std;

struct Mountain {
	int start, end;
};

bool operator<(const Mountain &m1, const Mountain &m2) {
	// sort by start and tiebreak by putting the larger mountains first
	if (m1.start == m2.start) { return m1.end > m2.end; }
	return m1.start < m2.start;
}

int main() {
	std::ifstream read("mountains.in");
	int mountain_num;
	read >> mountain_num;

	vector<Mountain> mountains;
	for (int m = 0; m < mountain_num; m++) {
		int x, y;
		read >> x >> y;
		// store the mountains by the interval they cover
		mountains.push_back({x - y, x + y});
	}
	sort(mountains.begin(), mountains.end());

	int rightmost = -1;
	int visible_num = 0;
	for (const Mountain &m : mountains) {
		if (m.end > rightmost) {
			visible_num++;
			rightmost = m.end;
		}
	}

	std::ofstream("mountains.out") << visible_num << endl;
}