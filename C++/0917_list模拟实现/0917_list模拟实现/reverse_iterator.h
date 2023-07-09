#pragma once

//������������ -- list������ vectorҲ�����ã�
//ʲô�����ķ����������䲻������
//map set�ǿ��Եģ�ʲô��������
//ֻҪ���������֧�� ++ ,-- �������������
//++һ���������У�--��һ����
//���絥���� -- forward_list��û��--
//1.forward_list ������
//2.unordered_map
//3.unordered_set
//
//�������ӽǶȷ��ࣺ
//forward_iterator ++
//bidirectional_iterator ++ --
//random_access_iterator ++ -- + -  ���λ�õ�����
//
//deque vector ���������
//map set list ˫�������
//forward_list ���������
//
//forward_iterator
//bidirectional_iterator
//random_access_iterator
//��ʵ������һ�ּ̳еĹ�ϵ
//˫��������ĵ�������������˫��

namespace yufc {
	//���ã�������������
	template<class Iterator, class Ref, class Ptr>
	struct __reverse_iterator {
		Iterator _cur;
		typedef __reverse_iterator<Iterator, Ref, Ptr> RIterator;
		__reverse_iterator(Iterator it)
			:_cur(it) {}
		//Ϊ�˶Գƣ�stlԴ�������һЩ����
		RIterator operator++() { //������++�����صĻ��ǵ�����
			--_cur;//���������++�����Ƿ�װ�����������--
			return *this;
		}
		RIterator operator--() {
			++_cur;//���������++�����Ƿ�װ�����������--
			return *this;
		}
		Ref operator*() {
			//return *_cur;
			//Ϊʲô������Ҫ����һ�¶����أ�
			//��Ϊ������ֻ��ȡһ�����ݣ�������λ�ÿ϶��ǲ��ܱ�� -- ���˿϶���������
			auto tmp = _cur;
			--tmp;
			return *tmp;
		}
		Ptr operator->() {
			return &(operator*());
		}
		bool operator!=(const RIterator& it) {
			return _cur != it._cur;
		}
	};
}