#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
constexpr double PI = 3.14159265358979323846;
void test2() {
	int x = 0, y = 0;//记录每一步的坐标
	double R = 0;//距离原点位置
	int r;//决定行走方向
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 50; i++) {
		int r = rand() % 4;
		//0右,1左,3上,4下
		switch (r)
		{
			case 0:
				x++;
				break;
			case 1:
				x--;
				break;
			case 2:
				y++;
				break;
			case 3:
				y--;
				break;
		}
		R = sqrt(x*x + y * y);
		cout <<"step"<<i<< ":  (" << x << "," << y << ")" << "  R=" << R<<endl;
	}
}


vector<double> expectR(int K) {
	srand((unsigned)time(NULL));
	//expect 储存期望值
	//expect[i]对应第i步的期望值
	vector<double> expect;
	for (int i = 0; i <= 100; i++) {
		expect.push_back(0);
	}
	//进行K次随机行走
	for (int k = 1; k <=K; k++) {
		double x = 0, y = 0;//记录每一步的坐标
		double R = 0;//距离原点位置
		//i代表第stepi
		for (int i = 1; i <= 100; i++) {
			//决定行走方向
			double r = 2*PI * ((double)rand() / RAND_MAX);
			x += cos(r);
			y += sin(r);
			R = sqrt(x*x + y * y);
			//更新期望值
			expect[i] = (expect[i] * (k - 1) + R) / (double)k;
		}
	}
	return expect;
}

void test3() {
	fstream os;
	os.open("temp.txt");
	vector<double> expect = expectR(100000);
	for (int i = 1;  i<= 100; i++) {
		os <<setprecision(10)<<i<<"  "<< expect[i] << endl;
	}
}

void testexp() {
	//srand((unsigned)time(NULL));
	cout << rand()%4;
}



int main() {
	test3();
	system("pause");
}