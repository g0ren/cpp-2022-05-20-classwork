#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Unit {
public:
	int a, b;

	Unit(int _a, int _b) {
		a = _a;
		b = _b;
	}
	void show() {
		cout << a << ' ' << b << endl;
	}
	bool operator<(const Unit &left) {
		return this->a < left.a;
	}

	/*bool operator<(const Unit& left) {
	 return this->b < left.b;
	 }*/
};

void show(vector<Unit> tmp) {
	for (auto x : tmp) {
		x.show();
	}
}

bool unitLess_forA(const Unit &left, const Unit &right) {
	return left.a < right.a;
}

bool unitLess_forB(const Unit &left, const Unit &right) {
	return left.b < right.b;
}

typedef int* (*fPtrInt)(int, int);

//template <typename T>
void for_each_no_stl(vector<int>::iterator start, vector<int>::iterator end,
		void (*func)(int&)) {
	for (; start != end; ++start) {
		func(*start);
	}
}

void for_each_no_stl(vector<float>::iterator start, vector<float>::iterator end,
		void (*func)(float&)) {
	for (; start != end; ++start) {
		func(*start);
	}
}

template<class ITER, class FUNC>
int count_if_no_stl(ITER start, ITER end, FUNC f) {
	int count { 0 };
	for (; start != end; ++start) {
		if (f(*start))
			++count;
	}
	return count;
}

int main() {
	vector<Unit> tmp;
	int size { 10 };
	//vector<Unit*> tmp1;
	for (int i = 0; i < size; ++i) {
		tmp.push_back(Unit((2 * i - 10) % (7 + i / 2), rand() % 3 + i / 2));
		//tmp1.push_back(new Unit((2 * i - 10) % (7 + i / 2), i - i / 2));
	}
	show(tmp);
	/*sort(tmp.begin(), tmp.end(), unitLess_forA); cout << "after sort for A___________\n";
	 show(tmp);
	 sort(tmp.begin(), tmp.end(), unitLess_forB); cout << "after sort for B___________\n";
	 show(tmp);*/

	//первую половину вектора отсортировать по А, вторую по Б
//	sort(tmp.begin(), tmp.begin() + size / 2,
//			[](const Unit &left, const Unit &right) {
//				return left.a < right.a;
//			});
//	sort(tmp.begin() + size / 2, tmp.end(),
//			[](const Unit &left, const Unit &right) {
//				return left.b < right.b;
//			});
//	show(tmp);
	int count = count_if_no_stl(tmp.begin(), tmp.end(), [](Unit value) {
		return (value.a + value.b >= 5);
	});
	cout << count << endl;

	vector<int> veci { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for_each_no_stl(veci.begin(), veci.end(), [](int &x) {
		x %= 2;
	});

	for (auto x : veci) {
		cout << x << " ";
	}
	cout << endl;

	vector<float> vecf { 3 / 2, 15 / 3, 7 / 4, 19 / 5, 11 / 6, 113 / 7, 115 / 8,
			17 / 9, 198 / 20 };
	for_each_no_stl(veci.begin(), veci.end(), [](int &x) {
		if (x - (int) x >= 0.5) {
			x -= (int) x;
			x += 1;
		} else {
			x -= (int) x;
		}
	});
	for (auto x : vecf) {
		cout << x << " ";
	}
	cout << endl;

	vector<int> veci2 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for_each_no_stl(veci2.begin(), veci2.end(), [](int &x) {
		int p = 1;
		for (int i = 0; i < x; i++) {
			p *= 2;
		}
		x = p;
	});

	for (auto x : veci2) {
		cout << x << " ";
	}
	cout << endl;
}

