#define _CRT_SECURE_NO_WARNINGS 1


//�ṹ��
#if 0
struct tag {
	member - list;
}variable-list;
#endif



#if 0
struct Stu {
	char name[20];
	int age;
	double score;
};


//���������
//�����ṹ��
struct {
	char name[20];
	float price;
	char id[12];
}ss;//ֻ����һ��


//�������������һ��
struct {
	int a;
	char b;
	float c;
}x;
struct {
	int a;
	char b;
	float c;
}a[20], * p;
//�����ṹ��ĳ�Ա���һ�����ڱ����������������ǲ�ͬ����������
#endif

//�ṹ���������
#if 0
#if 0
struct Node {
	int data;
	struct Node next;
};//���з�
#endif
//������ԣ���sizeof(struct Node)�Ƕ���
//�����Ǵ����
//��������ֻ�ܴ��ַ
//�������ָ����
struct ListNode {
	int data;
	struct ListNode* next;
};
#endif

//��ʼ��
struct Book {
	char name[20];
	float price;
	char id[12];
}s = { "����C����",55.5f,"PGC001" };
int main() {
	struct Book s2 = { "�������ݽṹ",66.6f,"HG001" };
	return 0;
}