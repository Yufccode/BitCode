#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����ѭ�����ٴ�
#if 0
int main() {
	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++) {
		k++;
	}
	return 0;
}
//0�Σ���Ϊk=0��Ϊ��
#endif

//����
#if 0
int main() {
	//1~10
	int i = 1;
	do {
		if (i == 5)
			continue;
		printf("%d ", i);
		i++;
	} while (i <= 10);
	return 0;
}
//��ѭ�� 1 2 3 4
#endif



//�ַ����м���
#if 0
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main() {
	char arr1[] = "welcome to bit!!!!!!";
	char arr2[] = "####################";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right) {
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);//˯��һ��(��λ�Ǻ���)
		system("cls");//(����)
		left++;
		right--;
	}
	return 0;
}
#endif

#if 0
//��������Ϸ
//1.�����������һ������(1~100)
//2.��Ҳ�����
//  ��Ҳ�С�ˣ��͸�֪��С��
//  ��Ҳ´��ˣ��͸�֪�´���
//  ֱ���¶�λ��
//3.��Ϸ����һֱ��
#include<stdlib.h>
#include<time.h>
void menu() {
	printf("******************************\n");
	printf("*******    1.play   **********\n");
	printf("*******    2.exit   **********\n");
	printf("******************************\n");
}
//RAND_MAX;
//ʱ���
//C�����ṩ��һ������time�����Է���һ��ʱ���
void game() {
	int guess = 0;
	//1.����һ�������
	// ����rand()����
	int ret = rand() % 100 + 1;//�������������1-100֮��
	//2.������
	while (1) {
		printf("������:>");
		scanf("%d", &guess);
		if (guess < ret)
			printf("��С��\n");
		else if (guess > ret)
			printf("�´���\n");
		else {
			printf("��ϲ��¶���\n");
			break;
		}
	}
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));//�˴�����Ҫ��time�����ķ���ֵ��������ֻ��Ҫ���ص��Ǹ���������
	//���srand()������������ֻ��Ҫ����һ�μ���
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case 1:			
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			printf("------------------------------\n");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			printf("------------------------------\n");
			break;
		}
	} while (input);

	return 0;
}
#endif


//time����
#include<windows.h>
#include<time.h>
#if 0
int main() {
	//��ȡʱ���
	time_t t1 = time(NULL);
	//��
	Sleep(10000);
	time_t t2;
	time(&t2);
	printf("%d\n", t1);
	printf("%d\n", t2);
	return 0;
}
#endif

//goto���
//������ǩ
//���ǲ��ܿ纯����
//���ã���ʱ��Ҫ�������ѭ����ʱ���ã�����д̫��break��



//�ػ�����
//ֻҪ�����������������Ծ���1�����ڹػ���������룺��������ȡ���ػ���
//�ڵ����������������� shutdown -s -t 60
//����60s�ػ�
//shut -a ȡ���ػ�
//��system()��������ִ���������windows����������ִ��������һ����
int main() {
	char input[20] = { 0 };
	system("shutdown  -s -t 60");//system��һ���⺯����������ִ��ϵͳ�����
again:
	printf("��ע�⣬��ĵ�����һ�����ڹػ���������룺��������ȡ���ػ�\n");
	scanf("%s", input);
	if (strcmp(input, "������") == 0) {
		system("shutdown -a");//ȡ���ػ�
	}
	else {
		goto again;
	}
	return 0;
}