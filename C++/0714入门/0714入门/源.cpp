#define _CRT_SECURE_NO_WARNINGS 1

//����C���﷨
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//�����ռ�
//���������ͻ������
//���������һ������
#if 0
#include<stdlib.h>
//int rand=0;
//����rand��stdlib.h�����һ�������������ͻ��ض���
namespace bit {
	int rand = 0;
}
//�����Ͳ��ᱨ����
/*   using namespace bit;   */
int main() {
	printf("%p\n", rand);//����Ĵ�ӡ����ʵ��rand()�ĵ�ַ������bit�����Ǹ�rand����
	//��������� using namespace bit; �����ֻᱨ����
	return 0;
}
#endif


#if 0
int a = 0;
int main() {
	int a = 1;
	printf("%d\n", a);//1
	//  ::�����޶�����::����ǿհף���ʾȫ����
	printf("%d\n", ::a);//0
	return 0;
}
#endif

#if 0
#include<stdlib.h>
namespace bit {
	int rand = 0;
}
int main() {
	printf("%p\n", rand);
	printf("%p\n", &bit::rand);
	//�����ͺܺ�����ˣ��������ǲ�һ����
	return 0;
}
#endif


//�ռ����滹�ܶ��庯������������
#if 0
namespace bit {
	int rand = 0;
	void func() {
		printf("func()\n");
	}
	struct TreeNode {
		struct TreeNode* left;
		struct TreeNode* right;
		int val;
	};
}
int main() {
	printf("%p\n", rand);
	printf("%p\n", &bit::rand);
	//func();//ֱ�ӵ����ǵ��ò��˵�
	bit::func();
	struct bit::TreeNode node;
	return 0;
}
#endif



//�����ռ����Ƕ��
#if 0
namespace sql {
	int a = 0;

	namespace bit {
		int rand = 0;
		void func() {
			printf("func()\n");
		}
		struct TreeNode {
			struct TreeNode* left;
			struct TreeNode* right;
			int val;
		};
	}
}
int main() {
	printf("%p\n", rand);
	printf("%p\n", &sql::bit::rand);
	//func();//ֱ�ӵ����ǵ��ò��˵�
	sql::bit::func();
	struct sql::bit::TreeNode node;
	return 0;
}
#endif

//����ļ����������ͬһ�������ռ�������ʵֻ��һ��
//����������ϲ���
//���using namespace bit;
//����ȫ���ң�Ȼ�����bit����ȥ��
//std��C++��׼��������ռ�

int main() {
	// << ������
	cout << "hello world" << endl;
	// << �����Զ�ʶ������
	// >> ����ȡ
	return 0;
}

//�������using namespace std;  չ��̫����
//����ָ��һЩչ���������Ҿ���cin��cout�Ƚϳ���
using std::cout;
using std::cin;
//Ҳ��