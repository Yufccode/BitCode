#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//ͨѶ¼
//1.����1000���˵���Ϣ
//2.����+�Ա�+����+�绰+סַ
//3.��ɾ��� �����
void menu() {
	printf("----------------------------\n");
	printf("*          THE MENU        *\n");
	printf("----------------------------\n");
	printf("*          1.add           *\n");
	printf("*          2.del           *\n");
	printf("*          3.search        *\n");
	printf("*          4.modify        *\n");
	printf("*          5.sort          *\n");
	printf("*          6.print         *\n");
	printf("*          0.exit          *\n");
	printf("----------------------------\n");
}
void _test() {
	int _input = 0;
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	_initContact(&con);
	do {
		system("cls");
		menu();
		printf("there is %d PeoInfos in the Contact\n", con.sz);
		printf("----------------------------\n");
		printf("please choose:>");
		scanf("%d", &_input);
		switch (_input)
		{
		case ADD:
			_addContact(&con);
			break;
		case DEL:
			_delContact(&con);
			break;
		case SEARCH:
			_searchContact(&con);
			break;
		case MODIFY:
			_modifyContact(&con);
			break;
		case SORT:
			_sortByAge(&con);//������������
			break;
		case PRINT:
			_printContact(&con);
			break;
		case EXIT:
			printf("exit contact\n");
			system("pause");
			exit(-1);
			break;
		default:
			printf("err\n");
			system("pause");
			break;
		}
	} while (_input);
}
int main() {
	_test();
	return 0;
}