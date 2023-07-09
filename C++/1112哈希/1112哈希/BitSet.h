#pragma once

#include<vector>
#include<iostream>
using namespace std;

//λͼ�ص�
//1.�졢��ʡ�ռ�
//2.��Ծ��ޣ�ֻ��ӳ�䴦������



//��char -- һ��charλ�ô�8λ
//��ô��λ�ã�����20
//20/8=2��ʾ���ڵڼ���char��
//20%8=4��ʾ�������char�ĵڼ���λ��
namespace yfc
{
	template<size_t N>
	class bit_set
	{
	public:
		bit_set()
		{
			_bits.resize(N / 8 + 1, 0);//+1���Ա�֤�ռ�һ����
		}
		void set(size_t x)
		{
			//��x��λ�����ó�1
			size_t i = x / 8;
			size_t j = x % 8;
			//��ô��_bit[i]�ĵ�jλŪ��1��
			//��һ�������㣡
			_bits[i] |= (1 << j);
		}
		void reset(size_t x)
		{
			//��x��λ�����ó�0
			size_t i = x / 8;
			size_t j = x % 8;
			_bits[i] &= ~(1 << j);
		}
		bool test(size_t x)
		{
			//����һλ��0����1
			size_t i = x / 8;
			size_t j = x % 8;
			return _bits[i] & (1 << j);
		}
	private:
		vector<char> _bits;
	};
	void test_bit_set1()
	{
		bit_set<100>bs1;
		bs1.set(8);
		bs1.set(9);
		bs1.set(20);

		cout << bs1.test(8) << endl;
		cout << bs1.test(9) << endl;
		cout << bs1.test(20) << endl;

		bs1.reset(8);
		bs1.reset(9);
		bs1.reset(20);

		cout << bs1.test(8) << endl;
		cout << bs1.test(9) << endl;
		cout << bs1.test(20) << endl;
	}
	void test_bit_set2()
	{
		//������д��������
		bit_set<-1>bs1;//-1��д������õ� -- -1��Ӧ��size_t����ȫ1
#if 0
		bit_set<0xffffffff>bs2;
		bit_set < 1024 * 1024 * 1024 * 4 - 1> bs3;
#endif
		//���Ǵ򿪿���������� -- �ǿ��Կ�����512MB���ҵ�
	}




	//������2
	//����������λͼ���� -- ����λͼ��Ӧλ��һ���ʾ״̬
	template<size_t N>
	class twobitset
	{
	private:
		bit_set<N>_bs1;
		bit_set<N>_bs2;
	public:
		void set(size_t x)
		{
			//Ҫ���ж�һ��
			bool inSet1 = _bs1.test(x);
			bool inSet2 = _bs2.test(x);
			if (inSet1 == false && inSet2 == false)
			{
				//00->01
				_bs2.set(x);
			}
			else if (inSet1 == false && inSet2 == true)
			{
				//01->10
				_bs1.set(x);
				_bs2.reset(x);
			}
		}
		void print_once_num()
		{
			for (size_t i = 0; i < N; i++)
			{
				if (_bs1.test(i) == false && _bs2.test(i) == true)
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	};
	void test_bit_set3()
	{
		int a[] = { 1,2,3,4,5,6,7,8,9,10,12,10,9,8,6,5,3,2,1 };
		twobitset<100>bs;
		for (auto e : a)
		{
			bs.set(e);
		}
		bs.print_once_num();
	}
	//������3
	//Ҳ��������λͼ
	//��һ�����ļ�1��ӳ��
	//�ڶ������ļ�2��ӳ��
	//ӳ��λ����1��ֵ���ǽ���

	//������4
	//��ʵ��2��һ���ģ�00/01/10/11����
}