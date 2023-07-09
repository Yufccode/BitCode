#pragma once


namespace yufc {
	//���ã�������������
	template<class Iterator, class Ref, class Ptr>
	struct __reverse_iterator {
		Iterator cur;
		typedef __reverse_iterator<Iterator> RIterator;
		__reverse_iterator(Iterator it)
			:_cur(it) {}
		//Ϊ�˶Գƣ�stlԴ�������һЩ����
		Ref operator++() {
			--_cur;//���������++�����Ƿ�װ�����������--
			return *this;
		}
		Ref operator--() {
			++_cur;//���������++�����Ƿ�װ�����������--
			return *this;
		}
		Ref operator*() {
			//return *_cur;
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