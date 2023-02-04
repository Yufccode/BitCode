#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>



//�ļ��������д
#if 0
int main() {
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("fopen");
		exit(-1);
	}
	//�����ȡ
#if 0
	int ch = 0;
	ch = fgetc(pf);
	printf("%c\n", ch);
#endif
	//�������������ȡ�����Ǿ�Ҫ�����ļ�ָ���λ��
	//fseek
	//ԭ��
	//int fseek(FILE*stream,long offset,int origin);
	// SEEK_CUR-�ļ�ָ�뵱ǰ��λ��
	// SEEK_END-�ļ�ĩβ��λ��
	// SEEK_SET-�ļ���ʼ��λ��
	int ch = 0;
	ch = fgetc(pf);
	printf("%c\n", ch);

	ch = fgetc(pf);
	printf("%c\n", ch);

	fseek(pf, 2, SEEK_CUR);

	ch = fgetc(pf);
	printf("%c\n", ch);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#endif

#if 0
int main() {
	//���ļ�
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror("fopen");
		exit(-1);
	}
	//�����ȡ

	fputc('a', pf);
	fputc('b', pf);
	fputc('c', pf);
	fputc('d', pf);
	fseek(pf, -3, SEEK_CUR);
	fputc('w', pf);
	//awcd

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#endif

//ftell�����ļ�ָ���������ʼλ�õ�ƫ����
//rewind���ļ�ָ���λ�÷��ص���ʼλ��
#if 0
int main() {
	//���ļ�
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror("fopen");
		exit(-1);
	}
	//�����ȡ

	fputc('a', pf);
	fputc('b', pf);
	fputc('c', pf);
	fputc('d', pf);
	fseek(pf, -3, SEEK_CUR);
	fputc('w', pf);
	//awcd

	long pos = ftell(pf);
	printf("%d\n", pos);

	rewind(pf);
	pos = ftell(pf);
	printf("%d\n", pos);


	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#endif


//�ı��ļ��Ͷ������ļ�
#if 0
int main() {
	int a = 10000;
	FILE* pf = fopen("test3.txt", "wb");
	if (pf == NULL) {
		perror("fopen");
		return 1;
	}
	fwrite(&a, 4, 1, pf);
	fclose(pf);
	pf = NULL;
	//�ö����Ʊ�������test3.txt
	//10 27 00 00
	return 0;
}
#endif




//�ļ���ȡ�������ж�
//������ʹ�õ�feof
/*
* �μǣ����ļ���ȡ�����У�������feof�����ķ���ֱֵ�������ж��ļ��Ƿ��ȡ����
* ���������ļ���ȡ����֮���ж��Ƕ�ȡʧ�ܽ��������������ļ�β����
*/
//
/*
* 1. �ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�Ϊ EOF �� fgetc �������� NULL �� fgets ��
���磺
fgetc �ж��Ƿ�Ϊ EOF .
fgets �жϷ���ֵ�Ƿ�Ϊ NULL .
2. �������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
���磺
fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
*/
#include<stdlib.h>
#if 0
int main(){
	int c; // ע�⣺int����char��Ҫ����EOF
	FILE* fp = fopen("test.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return EXIT_FAILURE;
	}
	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
	while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
	{
		putchar(c);
	}
		//�ж���ʲôԭ�������
		if (ferror(fp))
			puts("I/O error when reading");
		else if (feof(fp))
			puts("End of file reached successfully");
	fclose(fp);
}
#endif

#if 0
enum { SIZE = 5 };
int main(void)
{
	double a[SIZE] = { 1.,2.,3.,4.,5. };
	FILE* fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
	fwrite(a, sizeof * a, SIZE, fp); // д double ������
	fclose(fp);
	double b[SIZE];
	fp = fopen("test.bin", "rb");
	size_t ret_code = fread(b, sizeof * b, SIZE, fp); // �� double ������
	if (ret_code == SIZE) {
		puts("Array read successfully, contents: ");
		for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
		putchar('\n');
	}
	else { // error handling
		if (feof(fp))
			printf("Error reading test.bin: unexpected end of file\n");
		else if (ferror(fp)) {
			perror("Error reading test.bin");
		}
	}
	fclose(fp);
}
#endif



//�ļ�������
/*
ANSIC ��׼���á������ļ�ϵͳ������������ļ��ģ���ν�����ļ�ϵͳ��ָϵͳ�Զ������ڴ���Ϊ����
��ÿһ������ʹ�õ��ļ�����һ�顰�ļ��������������ڴ������������ݻ����͵��ڴ��еĻ�������װ
�����������һ���͵������ϡ�����Ӵ����������������ݣ���Ӵ����ļ��ж�ȡ�������뵽�ڴ滺
��������������������Ȼ���ٴӻ���������ؽ������͵���������������������ȣ���
�������Ĵ�С����C����ϵͳ�����ġ�
*/

#include <windows.h>
//VS2013 WIN10��������
int main()
{
	FILE* pf = fopen("test.txt", "w");
	fputs("abcdef", pf);//�Ƚ�����������������
	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
	Sleep(10000);
	printf("ˢ�»�����\n");
	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
	Sleep(10000);
	fclose(pf);
	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
	pf = NULL;
	return 0;
}
