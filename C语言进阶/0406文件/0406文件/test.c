#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//�����ص�
/*
* 1.Ϊʲôʹ���ļ�
* 2.ʲô���ļ�
* 3.�ļ��Ĵ򿪺͹ر�
* 4.�ļ���˳���д
* 5.�ļ��������д
* 6.�ı��ļ��Ͷ������ļ�
* 7.�ļ���ȡ�������ж�
* 8.�ļ�������
*/


//�ļ�һ�������֣������ļ��������ļ�
/*
* �����ļ���
* Դ�����ļ�(��׺Ϊ.c)��Ŀ���ļ�(windows������׺Ϊ.obj)����ִ�г���(window������׺Ϊ.exe)
*/
/*
* �����ļ���
* �ļ������ݲ�һ���ǳ��򣬶��ǳ�������ʱ��д�����ݣ��������������Ҫ���ж�ȡ���ݵ��ļ�������������ݵ��ļ�
*/


//�ļ��Ĵ򿪺͹ر�
#if 0
int main() {
	//д����·����ʱ��\�ǵ�Ҫ��дһ��
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("fopen");
		exit(-1);
	}
	//���ļ�
	///...

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;;
}
#endif


///д�ļ�
#if 0
int main() {
	FILE* pf = fopen("test.txt","w");
	if (pf == NULL) {
		perror("fopen");
		return 1;
	}
#if 0
	fputc('a', pf);
	fputc('b', pf);
	fputc('c', pf);
	fputc('d', pf);
	fputc('e', pf);
	fputc('f', pf);
	fputc('g', pf);
	fputc('h', pf);
	fputc('i', pf);
	fputc('j', pf);
#endif
	char ch = 'a';
	/// ����ǰ���һ����˳��д��
	for (ch = 'a'; ch <= 'z'; ch++) {
		fputc(ch, pf);
	}
	fclose(pf);
	return 0;
}
#endif



//���ļ�
#if 0
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("fopen");
		exit(-1);
	}
	//���ļ�
	int ch = 0;
	while ((ch = fgetc(pf))!= EOF) {
		printf("%c\n", ch);
	}
	printf("\n");
	fclose(pf);
	return 0;
}
#endif





///��
///
/// �ļ���
/// ��׼������ stdin
/// ��׼������ stdout
/// ��׼������ stderr
/// �����������Ͷ���FILE*
/// ֻҪc��������������������������Ĭ�ϴ򿪵�
#if 0
int main() {
	//stream
	int ch = fgetc(stdin);
	printf("%c\n", ch);
	fputc(ch, stdout);
	return 0;
}
#endif


#if 0
int main() {
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		exit(-1);
	}
	//д�ļ�
	//fputs,fgets
	//��д����ʽ�򿪣�����ԭ���ľ�û��
	fputs("qwertyuiop",pf);
	fputs("xxxxxxxxxx", pf);
	//�����ַ����ǲ��ỻ�е�
	// //�������\n���л�����

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#endif


#if 0
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		exit(-1);
	}
	//���ļ�-��һ��
	char arr[256] = { 0 };
	//fgets(arr, 255, pf);
	//printf("%s", arr);
	//fgets(arr, 255, pf);
	//printf("%s", arr);

	fgets(arr, 4, pf);//��ʵ����ֻ�������ַ�����һ����\0��
	printf("%s", arr);
	//��ʵfgets�ķ���ֵ���н����ģ�������������᷵��string�ĵ�ַ
	//����������󣬾ͻ᷵�ؿ�ָ��
	//����������ǲ�֪�������м��е�ʱ����ô����
	while (fgets(arr, 256, pf) != NULL) {
		printf("%s", arr);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#endif

//fprintf
#if 0
struct S {
	char name[20];
	int age;
	double d;
};
int main() {
	struct S s = { "����",20,5.5 };
	//д���ļ���
	FILE* pf = fopen("test2.txt", "w");
	if (pf == NULL) {
		exit(-1);
	}
	//д�ļ�
	fprintf(pf, "%s %d %lf", s.name, s.age, s.d);
	//�ر��ļ�
	fclose(pf);
	return 0;
}
#endif


//fscanf
#if 0
struct S {
	char name[20];
	int age;
	double d;
};
int main() {
	struct S s = { 0 };
	//д���ļ���
	FILE* pf = fopen("test2.txt", "r");
	if (pf == NULL) {
		exit(-1);
	}
	//���ļ�
	fscanf(pf, "%s %d %lf", s.name, &(s.age), &(s.d));
	fprintf(stdout,"%s %d %lf", s.name, s.age, s.d);
	
	//�ر��ļ�
	fclose(pf);
	return 0;
}
#endif

//scanf-��ʽ�������뺯��
//printf-��ʽ�����������
//fscanf-��������������ĸ�ʽ�������뺯��
//fprintf-�������������ĸ�ʽ�����������

//sprintf��sscanf
#if 0
struct S {
	char name[20];
	int age;
	double d;
};
int main() {
	struct S s = { "zhangsan",20,95.5 };
	struct S tmp = { 0 };
	char buf[256] = { 0 };
	sprintf(buf, "%s %d %lf", s.name, s.age, s.d);
	printf("%s\n", buf);
	//��buf������ȡ�ṹ�������
	sscanf(buf, "%s %d %lf", tmp.name, &(tmp.age), &(tmp.d));
	printf("%s %d %lf", tmp.name, tmp.age, tmp.d);
	return 0;
}
#endif
//sprintf-��һ����ʽ��������ת�����ַ���
//sscanf-��һ���ַ�������ת���ɸ�ʽ������



//�ļ��Ķ����ƶ�д
//fread fwrite -ֻ����ļ�
//������д�ļ�
#if 0
struct S {
	char name[20];
	int age;
	double d;
};
int main() {
	struct S s = { "����",20,95.5 };
	FILE* pf = fopen("test3.txt", "wb");//�����Ƶķ�ʽд
	if (pf == NULL) {
		exit(-1);
	}
	//�����Ƶķ�ʽд
	fwrite(&s, sizeof(struct S), 1, pf);

	//
	fclose(pf);
	pf = NULL;

	return 0;
}
#endif

struct S {
	char name[20];
	int age;
	double d;
};
int main() {
	struct S s = { 0 };
	FILE* pf = fopen("test3.txt", "rb");//�����Ƶķ�ʽд
	if (pf == NULL) {
		exit(-1);
	}
	//�����Ƶķ�ʽ��
	fread(&s, sizeof(struct S), 1, pf);
	printf("%s %d %lf", s.name, s.age, s.d);

	//
	fclose(pf);
	pf = NULL;

	return 0;
}
//��ô�Ž�ȥ��ô������