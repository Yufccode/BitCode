#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//�ַ������ڴ溯��(2)



//strtok �ַ����и�
//char* strtok(char* str, char* sep);
//sep�����Ǹ��ַ����������������ָ������ַ�����
//��һ������ָ��һ���ַ�������������0��������sep�ַ�����һ�������ָ����ָ�ı��

/*
* strtok�����ҵ�str�е���һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ��
* (ע��strtok������ı䱻�������ַ�����������ʹ�õ�ʱ��һ�㶼����ʱ����������)
* strtok�����ĵ�һ��������ΪNULL���������ҵ�str�еĵ�һ����ǣ�strtok���������������ַ����е�λ��
* strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ�����
* ����ַ����в����ڸ���ı�ǣ��򷵻�NULL
*/
#if 0
int main() {
	char arr[] = "xiaoxiaoprogrammer@yeah.net";
	char buf[30] = { 0 };
	strcpy(buf, arr);
	const char* sep = "@.";
	//"@."--sep
#if 0
	printf("%s\n",strtok(buf, sep));//ֻ�ҵ���һ�����
	printf("%s\n",strtok(NULL, sep));//�ӱ���õ�λ�ü���������
	printf("%s\n", strtok(NULL, sep));//�ӱ���õ�λ�ü���������
#endif
	//���Ƿ��ִ�bufֻ��Ҫ��һ�Σ�������������forѭ����forѭ����ʼ��ִֻ��һ��
	char* str = NULL;
	for (str = strtok(buf, sep); str != NULL; str = strtok(NULL, sep)) {//������Ҫ��ֵ
		printf("%s\n", str);
	}
	return 0;
}
//����strtokΪʲô�ǵã������Ȳ��ù��ģ����ǿ϶�����һ����ָ̬������¼��
#endif


//strerror��perror
//���ش�����Ĵ�����Ϣ
//������е�ʱ����ִ���
//���Զ�����һ��ȫ�ֱ�����errno�������룩
#include<errno.h>
#include<limits.h>
#include<stdlib.h>
#if 0
int main() {
#if 0
	printf("%s\n", strerror(0));
	printf("%s\n", strerror(1));
	printf("%s\n", strerror(2));
	printf("%s\n", strerror(3));
#endif
	//ÿ���������Ӧ���д�����Ϣ
	//malloc����������ڴ�ռ�
	int* p = (int*)malloc(INT_MAX);
	//�������ʧ�ܣ��ͻ᷵��һ����ָ��
	if (p == NULL) {
		printf("%s\n", strerror(errno));
		perror("malloc");//���ں����һ��ð�ţ��ټ�һ���ո��ټӴ�����Ϣ
		                 //��������ַ����Ļ��Ͳ����ð�źͿո�
		return 1;
	}
	return 0;
}
#endif




//�ַ����ຯ��
/*
iscntrl �κο����ַ�
isspace �հ��ַ����ո� ������ҳ��\f��������'\n'���س���\r�����Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
isdigit ʮ�������� 0~9
isxdigit ʮ���������֣���������ʮ�������֣�Сд��ĸa~f����д��ĸA~F
islower Сд��ĸa~z
isupper ��д��ĸA~Z
isalpha ��ĸa~z��A~Z
isalnum ��ĸ�������֣�a~z,A~Z,0~9
ispunct �����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
isgraph �κ�ͼ���ַ�
isprint �κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�
*/
#include<ctype.h>
#if 0
int main() {
	int ret = isdigit('q');
	//...
	printf("%d\n", ret);
	char ch = 'a';
	putchar(toupper(ch));
	return 0;
}
#endif
//�ַ�ת��
//tolower
//toupper


//�ڴ��������
//memcpy
//memmove
//memcmp
//memset


//memcpy
//void* memcpy(void* dest, const void* src, size_t count);
#include<assert.h>
#if 0
void* my_memcpy(void* dest, const void* src, size_t count) {
	assert(dest && src);
	void* ret = dest;
	while (count--) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;//һ��Ҫ�����Ͳ��ܼ�
		src = (char*)src + 1;
	}
	return ret;
}
int main() {
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[5] = { 0 };
	//memcpy(arr2, arr1, 20);
	my_memcpy(arr2, arr1, 20);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr2[i]);
	}
	return 0;
}
#endif


//�����ֻ��һ�ֳ�������
//�����Ҫ�Լ��������Լ�����ĵ�ַ���أ����磺
#if 0
void* my_memcpy(void* dest, const void* src, size_t count) {
	assert(dest && src);
	void* ret = dest;
	while (count--) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;//һ��Ҫ�����Ͳ��ܼ�
		src = (char*)src + 1;
	}
	return ret;
}
void* my_memmove(void* dest, const void* src, size_t count) {
	//�����ǴӺ���ǰ�����ʹ�ǰ���󿽱�������
	//1 2 3 4 5 6 7 8 9 10
	//���dest<src ��ǰ��󿽱�
	//���dest>src �Ӻ���ǰ����
	//���û�ص���������
	assert(dest && src);
	void* ret = dest;
	if (dest < src) {
		//ǰ->��
		while (count--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else {
		//��->ǰ
		while (count--) {
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main() {
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//my_memcpy(arr1 + 2, arr1, 20);//���ֲ��������ǵ�Ԥ�ڣ���Ϊ����ʵ�ֵ�memcpy�ǲ��������������ص��ڴ��
	//�����������������memmove����
	//memmove(arr1 + 2, arr1, 20);//����ʵ���ص��ڴ濽��
	my_memmove(arr1 + 2, arr1, 20);
	return 0;
}
#endif 

//memcmp
#if 0
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,0x1122334405 };
	int ret1 = memcmp(arr1, arr2, 16);
	int ret2 = memcmp(arr1, arr2, 17);//17Ҳ��һ����
	int ret3 = memcmp(arr1, arr2, 18);
	printf("%d %d %d", ret1,ret2,ret3);

	return 0;
}
#endif




//memset-�ڴ�����
#if 0
int main() {
	int arr[] = { 1,2,3,4,5 };
	memset(arr, 0, 20);
	memset(arr, 6, 20);//���ﲢ���ǰ����ݸĳ�6�����ǰ�ÿ���ֽڶ��ĳ�6
	return 0;
}
#endif



//ģ��ʵ��atoi
//���ַ���ת��������
#if 1
#include<assert.h>
enum Status {
	VALID,INVALID
}status=INVALID;//��һ��ʼ���óɷǷ�
int my_atoi(const char* str) {
	//��ָ��
	assert(str);
	int flag = 1;//��ʾ������
	//���ַ���
	if (*str == '\0') {
		//���������������������������ʣ�������������һ������
		//�жϵ�ǰ����ֵ�Ƿ���Ч���Ϸ����ǷǷ�
		//ʹ��ö��
		return 0;
	}
	//����հ��ַ�
	while (isspace(*str)) {
		//����ǿհ��ַ���������ȥ��
		str++;
	}
	//������
	if (*str == '-') {
		flag = -flag;//��һ��'-'��һ�κ�
		str++;
	}
	//������
	long long n = 0;
	while (*str) {
		if (isdigit(*str)) {
			n = n * 10 + (flag) * (*str - '0');
			if (n<INT_MIN || n>INT_MAX) {//˵��Խ����
				//���ǣ�����浽n����ȥ���ǿ϶�����Խ��ģ���Ϊ�ᷢ���ض�
				//���ԣ����ó�long long����õ�
				n = 0;
				break;
			}
		}
		else {
			n = 0;
			break;
		}
		str++;
	}
	if (*str == '\0') {
		status = VALID;
	}
	return (int)n;
}
//1.��ָ������
//2.���ַ�������
//3.�������ַ�
//4.�հ��ַ��ȣ������ַ�
//5.������
int main() {
	while (1) {//�ظ�����
		char arr[100] = { 0 };
		gets(arr);
		int ret = my_atoi(arr);
		if (status == VALID)
			printf("%d\n", ret);
		else
			printf("%d err\n", ret);
	}
	return 0;
}
#endif



