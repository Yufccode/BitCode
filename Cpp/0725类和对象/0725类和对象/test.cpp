#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"


void TestDate1() {
	Date d1(2022, 11, 1);
	d1 -= 100;
	d1.Print();
	Date d2 = d1 - 100;
	d2.Print();
}
void TestDate2() {
	Date d1(2022, 7, 25);
	Date d2(2023, 2, 15);
	//swap(d1, d2);
	cout << (d2 - d1) << endl;
}
void TestDate3() {
	Date d1(2022, 2, 29);
}
void TestDateIO() {
	Date d1(2022, 2, 10);
	Date d2(2022, 2, 13);
#if 0
	d1.operator<<(cout);//�������Գɹ����ã���Ϊʲôcout<<d1�����أ�
	//��Ϊd1Ӧ�������������coutӦ�����Ҳ������� -- ��Ϊthis��ռ�˵�һ������
	d1 << cout;//�����Ϳ�����������
	//����ô���������⣬���ǲ�����this��ռ��һ��������λ�ã�����Ҫ�ı�һ��
	//�������ǵ�<<���غ�������д�ɳ�Ա�����ˣ�д������ȥ�����Ǿ��ܸı�this��λ���ˣ���Ȼ��������Ļ�û��this�ˣ�
#endif
	//�Ѻ����ŵ�������֮�󣬵���һ�²���˳��Ȼ����һ����Ԫ
	cout << d1 << d2 << endl;
	cin >> d1;
	cout << d1 << endl;
}
int main() {
	//TestDate1();
	//TestDate2();
	//TestDate3();
	TestDateIO();
	return 0;
}

//д������Ҳ�������d1.Print()��Print()�ˣ�����ֱ����<<,>>!