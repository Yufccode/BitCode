#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>

//������ջ֡�Ĵ���������


//��Ҫʹ��̫�߼��ı�������Խ�߼��ı��룬Խ������ѧϰ�͹۲졣
//ͬʱ�ڲ�ͬ�ı������£��������ù�����ջ֡�Ĵ��������в���ģ�����ϸ��ȡ���ڱ�������ʵ��


//�Ĵ���
//eax ebx ecx edx
//ebp esp


//Ҫ��⺯��ջ֡�ͱ�������ebp��esp�������Ĵ���
//�������Ĵ����д�ŵ��ǵ�ַ
//��������ַ������ά������ջ֡��

//ÿһ������������Ҫ����һ���ռ�

//stack�� heap��(��̬����)


int Add(int x, int y) {
	int z = 0;
	z = x + y;
	return z;
}
int main() {
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b);
	printf("%d\n", c);
	return 0;
}


//����main()����һ��ջ֡
//��ôά����
//ebp����main()�ĸߵ�ַ--ջ��ָ��
//esp����main()�ĵ͵�ַ--ջ��ָ��

//��vs2013��
//main()Ҳ�Ǳ����˵��õ�
//mainCRTStartup()����__tmainCRTStartup()
//�ٵ���main(argc,argv,envp)
//���return��ֵ�Ż�mainret����ȥ��


//Add()��ʱ����ջ�������ٷ���ռ�


//lea
//load effective address

//Ϊa,b,c���ٺ�֮��
//��ʼ����
//�����ȴ�b



//��ʽ���������Ͳ���Add��ջ֡����
//����Add������
//Ҳ���Ǹߵ�ַ�ĵط�
//����4���ֽ�