#define _CRT_SECURE_NO_WARNINGS 1




#include<stdio.h>

//��1!+2!+3!+4!+....




//��ѭ��
#if 0
int main() {
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//for���治Ҫϰ����дint i �����û��ѭ����
	for (i = 0; i <= 12; i++) {
		arr[i] = 0;
		printf("hehe\n");
	}
	return 0;
}
#endif




//const������
int main() {
	//int num = 10;
	//num = 20;
	//int* p = &num;
	//*p = 100;

	const int num = 10;
	//nums=20;
	int n = 100;
	int* const p = &num; 
	*p=200;
	//p = &n;

	//const��������ָ��
	//const����*�����(const int*p)
	//const���ε���*p����ʾpָ��Ķ�����ͨ��p���ı䣬����p�����еĵ�ַ�ǿ��Ըı��

	return 0;
}


//strcpy��ʵ��
//д��һ��������ʽ����õ�
#include<assert.h>
//����һ��char*�Ϳ���ʵ����ʽ������
char* my_strcpy(char* dest, const char* src) {
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++) { ; }
	return ret;
}
int main() {
	char arr1[] = "hello bit";
	char arr2[20] = "xxxxxxxxxxxxxxxxx";
	char* p = NULL;
	printf("%s\n", my_strcpy(arr2, arr1));

	return 0;
}