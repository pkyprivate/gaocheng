//2151753 彭坤宇 计科
#include<iostream>
using namespace std;
double line(double x1, double y1, double x2, double y2, double x3, double y3) {
	double t = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
	return t;
}

int result(int n, double a[]) {
	if (n == 4) {
		double t1, t2, t3, t4;
		t1 = line(a[1], a[2], a[3], a[4], a[5], a[6]);
		t2 = line(a[3], a[4], a[5], a[6], a[7], a[8]);
		t3 = line(a[5], a[6], a[7], a[8], a[1], a[2]);
		t4 = line(a[7], a[8], a[1], a[2], a[3], a[4]);
		if (t1 * t2 * t3 * t4 == 0 || t1 * t2 < 0 || t2 * t3 < 0 || t3 * t4 < 0 || t4 * t1 < 0) {
			cout << "不是凸4边形" << endl;
			return 0;
		}
	}
	if (n == 5) {
		double t1, t2, t3, t4, t5;
		t1 = line(a[1], a[2], a[3], a[4], a[5], a[6]);
		t2 = line(a[3], a[4], a[5], a[6], a[7], a[8]);
		t3 = line(a[5], a[6], a[7], a[8], a[9], a[10]);
		t4 = line(a[7], a[8], a[9], a[10], a[1], a[2]);
		t5 = line(a[9], a[10], a[1], a[2], a[3], a[4]);
		if (t1 * t2 * t3 * t4 * t5 == 0 || t1 * t2 < 0 || t2 * t3 < 0 || t3 * t4 < 0 || t4 * t5 < 0 || t5 * t1 < 0) {
			cout << "不是凸5边形" << endl;
			return 0;
		}
	}
	if (n == 6) {
		double t1, t2, t3, t4, t5, t6;
		t1 = line(a[1], a[2], a[3], a[4], a[5], a[6]);
		t2 = line(a[3], a[4], a[5], a[6], a[7], a[8]);
		t3 = line(a[5], a[6], a[7], a[8], a[9], a[10]);
		t4 = line(a[7], a[8], a[9], a[10], a[11], a[12]);
		t5 = line(a[9], a[10], a[11], a[12], a[1], a[2]);
		t6 = line(a[11], a[12], a[1], a[2], a[3], a[4]);
		if (t1 * t2 * t3 * t4 * t5 * t6 == 0 || t1 * t2 < 0 || t2 * t3 < 0 || t3 * t4 < 0 || t4 * t5 < 0 || t5 * t6 < 0 || t6 * t1 < 0) {
			cout << "不是凸6边形" << endl;
			return 0;
		}
	}
	if (n == 7) {
		double t1, t2, t3, t4, t5, t6, t7;
		t1 = line(a[1], a[2], a[3], a[4], a[5], a[6]);
		t2 = line(a[3], a[4], a[5], a[6], a[7], a[8]);
		t3 = line(a[5], a[6], a[7], a[8], a[9], a[10]);
		t4 = line(a[7], a[8], a[9], a[10], a[11], a[12]);
		t5 = line(a[9], a[10], a[11], a[12], a[13], a[14]);
		t6 = line(a[11], a[12], a[13], a[14], a[1], a[2]);
		t7 = line(a[13], a[14], a[1], a[2], a[3], a[4]);
		if (t1 * t2 * t3 * t4 * t5 * t6 * t7 == 0 || t1 * t2 < 0 || t2 * t3 < 0 || t3 * t4 < 0 || t4 * t5 < 0 || t5 * t6 < 0 || t6 * t1 < 0 || t7 * t1 < 0) {
			cout << "不是凸7边形" << endl;
			return 0;
		}
	}
	return 1;
}

double square(int n, double a[]) {
	if (n == 4) {
		double s1, s2;
		s1 = fabs(line(a[1], a[2], a[3], a[4], a[5], a[6]) / 2);
		s2 = fabs(line(a[5], a[6], a[7], a[8], a[1], a[2]) / 2);
		return s1 + s2;
	}
	if (n == 5) {
		double s1, s2, s3;
		s1 = fabs(line(a[1], a[2], a[3], a[4], a[5], a[6]) / 2);
		s2 = fabs(line(a[1], a[2], a[7], a[8], a[5], a[6]) / 2);
		s3 = fabs(line(a[1], a[2], a[7], a[8], a[9], a[10]) / 2);
		return s1 + s2 + s3;
	}
	if (n == 6) {
		double s1, s2, s3, s4;
		s1 = fabs(line(a[1], a[2], a[3], a[4], a[5], a[6]) / 2);
		s2 = fabs(line(a[1], a[2], a[7], a[8], a[5], a[6]) / 2);
		s3 = fabs(line(a[1], a[2], a[7], a[8], a[9], a[10]) / 2);
		s4 = fabs(line(a[1], a[2], a[11], a[12], a[9], a[10]) / 2);
		return s1 + s2 + s3 + s4;
	}
	if (n == 7) {
		double s1, s2, s3, s4, s5;
		s1 = fabs(line(a[1], a[2], a[3], a[4], a[5], a[6]) / 2);
		s2 = fabs(line(a[1], a[2], a[7], a[8], a[5], a[6]) / 2);
		s3 = fabs(line(a[1], a[2], a[7], a[8], a[9], a[10]) / 2);
		s4 = fabs(line(a[1], a[2], a[11], a[12], a[9], a[10]) / 2);
		s5 = fabs(line(a[1], a[2], a[11], a[12], a[13], a[14]) / 2);
		return s1 + s2 + s3 + s4 + s5;
	}
	else {
		return 0;
	}
}

int main() 
{
	int n, jieguo;
	double a[15], s;
	while (1) {
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		if (n < 8 && n>3)
			break;
	}
	cout << "请按顺时针/逆时针方向输入4个顶点的x,y坐标：" << endl;
	while (1) {
		cout << "请输入第1个顶点的坐标：" << endl;
		cin >> a[1] >> a[2];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else {
			break;
		}
	}
	while (1) {
		cout << "请输入第2个顶点的坐标：" << endl;
		cin >> a[3] >> a[4];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else {
			break;
		}
	}
	while (1) {
		cout << "请输入第3个顶点的坐标：" << endl;
		cin >> a[5] >> a[6];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else {
			break;
		}
	}
	while (1) {
		cout << "请输入第4个顶点的坐标：" << endl;
		cin >> a[7] >> a[8];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else {
			break;
		}
	}
	if (n == 5) {
		while (1) {
			cout << "请输入第5个顶点的坐标：" << endl;
			cin >> a[9] >> a[10];
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				break;
			}
		}
	}
	if (n == 6) {
		while (1) {
			cout << "请输入第5个顶点的坐标：" << endl;
			cin >> a[9] >> a[10];
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				break;
			}
		}
		while (1) {
			cout << "请输入第6个顶点的坐标：" << endl;
			cin >> a[11] >> a[12];
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				break;
			}
		}
	}
	if (n == 7) {
		while (1) {
			cout << "请输入第5个顶点的坐标：" << endl;
			cin >> a[9] >> a[10];
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				break;
			}
		}
		while (1) {
			cout << "请输入第6个顶点的坐标：" << endl;
			cin >> a[11] >> a[12];
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				break;
			}
		}
		while (1) {
			cout << "请输入第7个顶点的坐标：" << endl;
			cin >> a[13] >> a[14];
			if (cin.fail()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				break;
			}
		}
	}
	jieguo = result(n, a);
	if (jieguo == 0) {
		return 0;
	}
	s = square(n, a);
	cout << "凸" << n << "边形的面积=" << s << endl;
	return 0;
}