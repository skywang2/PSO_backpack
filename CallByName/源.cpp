#include<iostream>
using namespace std;

//void swap1(int *, int*);
//void swap2(int &, int &);
//void main() {
//	int a = 10, b = 20;
//	cout << a << "   " << b << endl;
//	swap1(&a, &b);
//	cout << a << "   " << b << endl;
//	swap2(a, b);
//	cout << a << "   " << b << endl;
//
//	cin.get();
//}
//
//void swap1(int *x, int *y) {
//	int z = *x;
//	*x = *y;
//	*y = z;
//}
//
//void swap2(int &x, int&y) {
//	int z;
//	z = x;
//	x = y;
//	y = z;
//}
#define NUM 5	// 物品个数
int rand_drop() {
	int number;
	number = rand() % NUM;
	return number;	// 随机数0~4
}

int main() {
	float a;
	a = 4.8;
	cout << (int)a << endl;
	cin.get();
	return 0;
}