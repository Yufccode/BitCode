#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//#define
//1.�����ʶ������
//2.�����

#if 0
#define NUM 100
#define STR "abcdef"
int main() {
	int num = NUM;
	char name[] = STR;

	return 0;
}
#endif
//����Ŀ���� Ԥ���� Ԥ�����ļ��򿪸�Ϊ�ǣ�����ͻ����һ��test.i�ļ��ں�̨
//�򿪣��Ϳ��Է��֣���ȫ�滻��


//��Ϊ����ȫ�滻
//���Ի������滻�Ƚϳ��Ĺؼ���
#if 0
#define reg register
int main() {
	int reg num = 100;
	return 0;
}



// �������� stuff���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)��
#define DEBUG_PRINT printf("file:%s\tline:%d\t \
                          date:%s\ttime:%s\n" ,\
__FILE__,__LINE__ ,       \
__DATE__,__TIME__ )  
#endif



//#define �����
/*#define ���ư�����һ���涨������Ѳ����滻���ı��У�����ʵ��ͨ����Ϊ�꣨macro������
�꣨define macro����
*/


#if 0
#define MAX(x,y) (x>y?x:y)
int main() {
	int a = 10;
	int b = 20;
	printf("%d\n", MAX(a, b));
	return 0;
}
#endif


//д���ʱ��Ҫע��
#if 0
#define SQUARE(x) x*x
#define SQUARE2(x) ((x)*(x))
//�����������Ŵ���
int main() {
	int a = 9;
	int r = SQUARE(a+1);
	int r2 = SQUARE2(a + 1);
	//int r=a+1*a+1
	printf("%d %d", r,r2);
	return 0;
}
#endif


//#define�滻����
/*�ڳ�������չ#define������źͺ�ʱ����Ҫ�漰�������衣
1. �ڵ��ú�ʱ�����ȶԲ������м�飬�����Ƿ�����κ���#define����ķ��š�����ǣ���������
���滻��
2. �滻�ı���󱻲��뵽������ԭ���ı���λ�á����ں꣬�����������ǵ�ֵ���滻��
3. ����ٴζԽ���ļ�����ɨ�裬�������Ƿ�����κ���#define����ķ��š�����ǣ����ظ���
��������̡�
ע�⣺
1. �������#define �����п��Գ�������#define����ķ��š�
   ���Ƕ��ں꣬���ܳ��ֵݹ顣
2. ��Ԥ����������#define����ķ��ŵ�ʱ���ַ������������ݲ�����������
*/
#if 0
#define M 100
int main() {
	printf("M is %d\n", M);
	//�������M�ǲ����滻��
	return 0;
}
#endif


//#��##
#if 0
#define PRINT(N) printf("the value of "#N" is %d\n",N)
//                ���a�����κ��滻��ֱ��ת�����ַ����������ȥ
int main() {
	/*
	int a = 10;
	printf("the value of a is %d\n", a);
	int b = 10;
	printf("the value of b is %d\n", b);
	*/
	//��Щ�������ظ���
	//���װ�ɺ����Ǻ��ѵ�
	//���ǿ���������
	int a = 10;
	PRINT(a);
	int b = 20;
	PRINT(b);
	return 0;
}

#endif
#if 0
int main() {
	printf("hello bit\n");
	printf("hello ""bit\n");
	//����һ����
	return 0;
}
#endif

#if 0
#define PRINT(N,format) \
printf("the value of "#N" is "format"\n",N)
int main() {
	int a = 20;
	double pai = 3.14;
	PRINT(a, "%d");
	PRINT(pai, "%lf");
	return 0;
}
#endif


//##������
/*##���԰�λ�������ߵķ��źϳ�һ�����š�
������궨��ӷ�����ı�Ƭ�δ�����ʶ��*/
#if 0
#define CAT(name,num) name##num
int main() {
	int _class105 = 105;
	printf("%d\n", CAT(_class, 105));
	return 0;
}
#endif


//���и����õĺ����
//x+1;//����������
//x++;//���и�����
/*��������ں�Ķ����г��ֳ���һ�ε�ʱ������������и����ã���ô����ʹ��������ʱ��Ϳ���
����Σ�գ����²���Ԥ��ĺ���������þ��Ǳ��ʽ��ֵ��ʱ����ֵ�������Ч����
*/
#if 0
int main() {
	int a = 2;
	//int b = a + 1;
	int b = ++a;//��a�����˸�����
	return 0;
}
#endif


#if 0
#define MAX(x,y) ((x)>(y)?(x):(y))
int main() {
	int a = 5;
	int b = 8;
	int c = MAX(a++, b++);
	//int c=((a++)>(b++)?(a++):(b++))
	printf("%d\n", c);//9
	printf("%d\n", a);//6
	printf("%d\n", b);//10
	return 0;
}
#endif


//��ͺ����ĶԱ�
/*
��ͨ����Ӧ����ִ�м򵥵����㡣
���������������ҳ��ϴ��һ����
��Ϊʲô���ú���������������
ԭ���ж���
1. ���ڵ��ú����ʹӺ������صĴ�����ܱ�ʵ��ִ�����С�ͼ��㹤������Ҫ��ʱ����ࡣ
���Ժ�Ⱥ����ڳ���Ĺ�ģ���ٶȷ����ʤһ�
2. ��Ϊ��Ҫ���Ǻ����Ĳ�����������Ϊ�ض������͡�
���Ժ���ֻ�������ͺ��ʵı��ʽ��ʹ�á���֮��������������������Ρ������͡������͵ȿ���
����>���Ƚϵ����͡�
���������޹صġ�
���ȱ�㣺��Ȼ�ͺ�����Ⱥ�Ҳ�����Ƶĵط���
1. ÿ��ʹ�ú��ʱ��һ�ݺ궨��Ĵ��뽫���뵽�����С����Ǻ�Ƚ϶̣�������ܴ�������ӳ���
�ĳ��ȡ�
2. ����û�����Եġ�
3. �����������޹أ�Ҳ�Ͳ����Ͻ���
4. ����ܻ������������ȼ������⣬���³����׳��ִ�
����ʱ����������������������顣���磺��Ĳ������Գ������ͣ����Ǻ�����������
*/

#if 0
#include<stdlib.h>
#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
int main() {
	int* p = (int*)malloc(10 * sizeof(int));
	//�������д���鷳
	//���������д�ͺ���--�ú�
	int* p2 = MALLOC(10, int);
	return 0;
}
#endif

//C99 inline ����
//�������� - ����˺������ŵ�ͺ���ŵ�



/*����Լ��
һ�����������ĺ��ʹ���﷨�����ơ��������Ա���û�����������ֶ��ߡ�
������ƽʱ��һ��ϰ���ǣ�
�Ѻ���ȫ����д
��������Ҫȫ����д
*/
//��ȻҲ������ - offsetof��


//#undef - �Ƴ�һ���궨��
#if 0
#include<stdlib.h>
#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
int main() {
	int* p = (int*)malloc(10 * sizeof(int));
	//�������д���鷳
	//���������д�ͺ���--�ú�
	int* p2 = MALLOC(10, int);
#undef MALLOC
	//MALLOC
	return 0;
}
#endif


//�����ж���
//��������vs���޷���ʾ
/*
���C �ı������ṩ��һ���������������������ж�����š���������������̡�
���磺�����Ǹ���ͬһ��Դ�ļ�Ҫ�������ͬ��һ������Ĳ�ͬ�汾��ʱ����������е��ô�������
��ĳ��������������һ��ĳ�����ȵ����飬��������ڴ����ޣ�������Ҫһ����С�����飬��������һ
�������ڴ��д��������Ҫһ�������ܹ���д����
*/
//��linux����ʾ
#if 0
#include <stdio.h>
int main()
{
	int array[ARRAY_SIZE];
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		array[i] = i;
	}
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
#endif
//һ��Դ�ļ�Ū����ͬ�İ汾���Ϳ���������



//��������
#if 0
int main() {
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = i;
#if 0
		printf("%d ", arr[i]);
#endif
	}
	return 0;
}
#endif
//#if ����һ���ǳ������ʽ
//���֧Ҳһ�����������������Ƶ�
#if 0
#define NUM 3
int main() {
#if NUM==1
	printf("hehe\n");
#elif NUM==2
	printf("haha\n");
#else 
	printf("heihei\n");
#endif
	return 0;
}
#endif



#if 0
#define MAX 1
int main() {
#if defined MAX
	printf("hehe\n");
#endif
	//����
#ifdef MAX
	printf("heihei\n");
#endif
	//������д����һ����


	//д����Ҳ��һ����
#if !defined MAX
	printf("hehe\n");
#endif
#ifndef MAX
	printf("hehe\n");
#endif
	//������Ҳ��һ����

	//��������Ƕ��Ҳ�ǿ��Ե�
	return 0;
}
#endif



//�ļ�����
//#include<>
//#include""
/*���Ҳ��ԣ�����Դ�ļ�����Ŀ¼�²��ң�
�����ͷ�ļ�δ�ҵ���������������ҿ⺯��ͷ�ļ�һ���ڱ�
׼λ�ò���ͷ�ļ���
����Ҳ�������ʾ�������
*/
//Linux /usr/include


//��������������Σ��ͻ��ظ���
//���Ƕ�װ�����ʱ�򣬾ͻ����׳����ظ������������������linux���Կ�����
//���������ַ�ʽ
//ͷ�ļ���������д
#ifndef _TEST_H_
#define _TEST_H_
//...
#endif
//���û���һ�ַ�ʽ
//ֱ��д���ִ�һ���д��
#pragma once
//Ҳ����


#if 0
//����Ԥ����ָ�C������Ƚ��ʡ�
#line
#error
//�ȵ�
#endif