#pragma once
#include<vector>


using namespace std;
namespace yufc {
	template<class T, class Container = vector<T>, class Compare = std::less<T>>
													//Ĭ����less  Compare��һ�����бȽϵķº���
													//less -- С��
	class priority_queue {
	public:
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {
			while (first != last) {
				//��Ҫֱ��ȥpush��push���õ������ϵ����������ܶ�
				//��Ū�������ٽ��ѿ�һ�㣬�����µ���
				_con.push_back(*first);
				++first;
			}
			//����
			for (int i = ((_con.size() - 1 - 1) / 2); i >= 0; i--) {
				adjust_down(i);
			}
		}
		//���д���������������Ͳ��������������͹����ˣ�����Ҫ�Լ�д
		priority_queue() {}
		void adjust_up(size_t child) {
			Compare cmp;
			size_t parent = (child - 1) / 2;//�ҵ����׽ڵ���±�
			while (child > 0) { //logn
				//if (_con[child] > _con[parent]) {
				//if (_con[parent] < _con[child]) {
				if (cmp(_con[parent],_con[child])) {
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}
		void adjust_down(size_t parent) {
			Compare cmp;
			size_t child = parent * 2 + 1;
			while (child < _con.size()) {
				//ѡ�����Һ����д���Ǹ�
				if (child + 1 < _con.size() && cmp(_con[child], _con[child + 1])) {
					++child;
				}
				if (cmp(_con[parent], _con[child])) {
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;//�Ѿ����������ˣ������ٵ�����
			}
		}
		void push(const T& x) {
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
		void pop() {
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		const T& top() {
			//����ֵ�������޸� -- �޸��˾Ͳ��Ƕ���
			return _con[0];
		}
		bool empty() const {
			return _con.empty();
		}
		size_t size() const {
			return _con.size();
		}
	private:
		Container _con;
	};
}


//priority_queue
//stack
//queue 
//���Ǿ��� ����������