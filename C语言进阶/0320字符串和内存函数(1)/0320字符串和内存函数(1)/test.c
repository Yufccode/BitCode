#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

//strlen
#if 0
int main() {
	char arr[] = "abcdef";
	//char arr[] = { 'a','b','c','d','e','f' };
	int len = strlen(arr);
	printf("%d\n", len);
	return 0;
}
#endif
//ע��strlen�ķ���ֵ��size_t
//���Բ�ע���ʱ������д��bug
#if 0
int main() {
	if (strlen("abc") - strlen("qwertyu") > 0) {
		printf(">\n");
	}
	else {
		printf("<\n");
	}

	return 0;
}
//�õ�ʱ��ע��һ�¾Ϳ�����
#endif

//strlen��ʵ��
//�������ⷨ ��Ȼ���еݹ鷨��ָ��-ָ��ķ���
#if 0
size_t my_strlen(const char* str) {
	assert(str);
	int count = 0;
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}
int main() {
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
#endif 


//strcpy�ַ�������
#if 0
int main() {
	char arr1[20] = { 0 };
	char arr2[] = "abcdef";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
#endif
//ע�⣬ԭ�ַ���������'\0'��β
//������ʱ����ԭ�ַ�����\0Ҳ������ȥ
//Ŀ��ռ�һ��Ҫ�㹻��
//Ŀ��ռ����ɱ�
#if 0
char* my_strcpy(char* dest, const char* src) {
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++) {
		;
	}
	return ret;
}
int main() {
	char arr1[20] ="xxxxxxxxxxxxxxxxx";
	char arr2[] = "abcdef";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
#endif



//strcat �ַ���׷��
#if 0
int main() {
	char arr1[20] = "hello ";
	char arr2[] = "bit";
	strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
#endif
//ԭ�ַ���Ҫ��\0,Ŀ��ռ�ҲҪ\0�������Ҳ�����ʼ׷�ӵı�־
//������Ҳ���������Խ����ʣ�֪���ҵ�\0Ϊֹ
#if 0
char* my_strcat(char* dest, const char* src) {
	assert(dest && src);
	//1.��ԭ�ַ����е�\0
	char* start = dest;
	while (*start) {
		start++;
	}
	//��ʼ����
	while (*start++ = *src++) {
		;
	}
	return dest;
}
int main() {
	char arr1[20] = "hello ";
	char arr2[] = "bit";
	//my_strcat(arr1, arr2);
	printf("%s\n", my_strcat(arr1, arr2));
	return 0;
}
#endif
//���⣺���Լ����Լ�׷������Ҫ������ʵ�֣�����д������汾�ǲ��е�

//strcmp
//���ǱȽϳ��ȣ����ǱȽ����Ӧλ�õ�ֵ�Ĵ�С
#if 0
int my_strcmp(const char* str1, const char* str2) {
	assert(str1 && str2);
	while (*str1 == *str2) {
		if (*str1 == '\0')return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main() {
	char arr1[] = "abcdef";
	char arr2[] = "abq";
	int ret = strcmp(arr1, arr2);
	//int ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}
#endif

//���涼�ǳ��Ȳ������Ƶ��ַ�����������
//
//strncpy
//strncat
//strncmp
//���������Ƶ��ַ�������
#if 0
int main() {
	char arr1[] = "abcdef";
	char arr2[] = "qwertyuiop";
	strncpy(arr1, arr2, 3);
	printf("%s\n", arr1);
	return 0;
}
#endif

//strncat
#if 0
int main() {
	//char arr1[20] = "abcdef";
	char arr1[20] = "abcdef\0xxxxxxxx";
	char arr2[] = "qwertyuiop";
	strncat(arr1, arr2, 5);
	printf("%s\n", arr1);
	return 0;
}
#endif
//׷�ӽ���֮�󣬻���������һ��\0��ȥ


//strncmp
#if 0
int main() {
	char arr1[] = "abcdef";
	char arr2[] = "abcdefqwert";
	int ret = strncmp(arr1, arr2, 4);
	printf("%d\n", ret);
	return 0;
}
#endif


//�����ȽϱȽϵĶ��������ַ����ĵ�ַ�������ڱȽ��ַ���
//Ҫ�ȽϾ���strcmp��strncmp�Ϳ�����
#if 0
int main() {
	char arr1[] = "abcdef";
	char arr2[] = "abc";
	if (arr1 > arr2) {//����ȵ��ǵ�ַ
		printf("arr1>arr2\n");
	}
	if ("abcdef" > "abc") {
		;//����ȵ�Ҳ�ǵ�ַ
	}

	return 0;
}
#endif


//strstr
//�ж�һ���ַ����ǲ�����һ���ַ������ִ�
//�ҵ���-�����ִ���������ֵĵ�ַ
//�Ҳ���-���ؿ�
#if 0
int main() {
	char arr1[] = "abcdefg";
	char arr2[] = "cdef";
	char* ret = strstr(arr1, arr2);
	if (ret == NULL) { printf("�Ҳ����Ӵ�\n"); }
	else {
		printf("%s\n", ret);
	}
	return 0;
}
#endif


//strstrʵ��
//˫ָ��ʵ��
#if 0
char* my_strstr(const char* str1, const char* str2) {
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* cur = str1;
	while (*cur) {
		s1 = cur;
		s2 = str2;//���ƥ�䲻�ɹ����ص�ԭλ���¿�ʼƥ��
		while (*s1 && *s2 && *s1 == *s2) {
			s1++;
			s2++;
		}
		if (*s2 == '\0') {//���ƥ��ɹ���
			return (char*)cur;
		}
		cur++;//ƥ��ʧ�ܣ�˵����cur��ʼƥ�䲻��
	}
	return NULL;
}
int main() {
	char arr1[] = "abcdefg";
	char arr2[] = "cdef";
	char* ret = my_strstr(arr1, arr2);
	if (ret == NULL) { printf("�Ҳ����Ӵ�\n"); }
	else {
		printf("%s\n", ret);
	}
	return 0;
}
#endif
//�����ִ�
//KMP�㷨 - Bվ���ش󲩸�