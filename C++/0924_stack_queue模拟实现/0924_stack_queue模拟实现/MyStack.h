#pragma once
#include<vector>
#include<deque>
using namespace std;


namespace yufc {
	//template<class T> //���������������������Ϊ�ײ���д����
	template<class T, class Container = deque<T>>
	class stack {
	public:
		//����������������Ҫ��Ҫд -- ����
		void push(const T& x) {
			_con.push_back(x);
		}
		void pop() {
			_con.pop_back();
		}
		T& top() {
			return _con.back();
		}
		bool empty() const {
			return _con.empty();
		}
		size_t size() const {
			return _con.size();
		}
	private:
		//vector<T>_con;
		Container _con;
		//�ҵ�Container������ʲô����Ҫ��ֻ��Ҫ�����⼸������������
	};
}

//queue ˫�˶���
//1.֧������λ�õĲ���ɾ��
//2.�������
//vector��list�ĺ��� -- ����ʵû�к�ţ -- ��ǿ�и�

//���ƣ�3D��ͷβ����ɾ�����������
//���ȱ�ݣ�
//1.operator[]�������Ը��ӣ�����ʹ�������½�
//2.�м����ɾ��Ч�ʲ���
//3.��������ܸ��ӣ�


//���ȼ�����
//priority_queue