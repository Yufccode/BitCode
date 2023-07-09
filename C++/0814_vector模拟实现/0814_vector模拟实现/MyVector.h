#pragma once
#include<cassert>
#include<string.h>
#include<algorithm>
#include<functional>
#include<initializer_list>
namespace yufc {
	template<class T>
	class vector {
	public:
		typedef T* iterator;//���Ҫ�ųɹ��У���Ȼ������������ʲ��� -- ���������������ָ������
		typedef const T* const_iterator;
		//vector�ĵ���������ԭ��ָ��
		iterator begin() {
			return _start;
		}
		iterator end() {
			return _finish;
		}
		//������ṩconst������ -- �������const��vector�Ǳ������˵ģ���ΪȨ�޲��ܷŴ�
		const_iterator begin()const { //���ܷ�����ͨ��������Ҫ����const������
			return _start;
		}
		const_iterator end()const {
			return _finish;
		}
		vector() :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
		~vector() {
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		//�ó�ʼ���б��ʼ��
		vector(initializer_list<T>& list)
		{
			//��n��ֵȥ����
			reserve(list.size());
			for (size_t i = 0; i < n; i++) {
				push_back(list[i]);
			}
		}
		//stl��vector��֧��ʹ�õ���������ȥ����
		//Ϊʲô��Ҫһ���������͵ĵ�������
		//��Ϊ��Ҫ֧�������������ĵ����������乹��
		template<class InputIterator>
		vector(InputIterator first, InputIterator last) 
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			while (first != last) {
				//����ֱ��push_back()��ֱ��push_back()����� -- ��Ϊû�г�ʼ�� -- Ұָ��
				push_back(*first);
				++first;
			}
		}
		vector(size_t n, const T& val = T()) 
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			//��n��ֵȥ����
			reserve(n);
			for (size_t i = 0; i < n; i++) {
				push_back(val);
			}
		}
		//��ͳ��������
#if 0
		vector(const vector<T>& v) {
			_start = new T[v.size()];//�����Ǹ�size����capacity�أ�STLû��Ҫ��
			//memcpy(_start, v._start, sizeof(T) * v.size());
			//���vector<vector<int>>��������,memcpy���ܰ����ڲ���Զ�����������������ֵ���ԣ�����д�����Զ������͵ĸ�ֵ��
			for (size_t i = 0; i < v.size(); i++) {
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();//��ΪT[]�������size(),��������ҲӦ����v.size()
		}
#endif
		//д��2
#if 0
		vector(const vector<T>& v) 
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(v.size());
			for (const auto& e : v) { //ע�⣺��������ȥһ��Ҫ���ã���Ȼ��Ҫ������
												//д����Լ���Ҫ����� -- �϶��ǻ�������
				push_back(e);
			}
			//����Ҫȥ����_finish,��Ϊpush_back()�Ѿ��㶨��
		}
#endif

		//�ִ�д���������� -- ���õ��������乹�캯��
		void swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
#if 1
		vector(const vector<T>& v) 
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			vector<T>tmp(v.begin(), v.end());
			swap(tmp);//��Ȼ�Զ��������Լ�д��swap����Ч -- �����Լ�ʵ��һ��
		}
#endif
		vector<T>& operator=(vector<T> v) { //v1=v2
			//v��v2�Ŀ����������Ǿֲ��ģ�swap��֮�����v1��v�����Զ���������Ϊ�Ǿֲ�����
			swap(v);
			return *this;
		}
		size_t capacity()const {
			return _end_of_storage - _start;
		}
		size_t size()const {
			return _finish - _start;
		}
		void reserve(size_t n) {
			if (n > capacity()) {
				T* tmp = new T[n];
				size_t sz = size();
				if (_start) {
					//memcpy(tmp, _start, sizeof(T) * sz);//����size()���ֽڹ�ȥ���ȷŵ�tmp����
					//ͬ�������
					//vector<�Զ�������>������
					for (size_t i = 0; i < sz; i++) {
						tmp[i] = _start[i];//��T���Զ�������ʱ������T���͵�operator=
					}
					delete[] _start;
				}
				_start = tmp;
				//_finish = _start + size();//���ﲻҪ�ֳ�ȥ��size()
				//��Ϊsize()����start�������ģ�������һ��start�Ѿ�����
				//������ǰ��������ñ���һ��size��
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const T& val = T()) {
			//1.����+��ʼ��
			//2.��ʼ��
			//3.ɾ������
			if (n > capacity()) {
				reserve(n);
			}
			if (n > size()) {
				//��ʼ����ֵ
				while (_finish < _start+n) {
					*_finish = val;
					++_finish;
				}
			}
			else {
				_finish = _start + n;
			}
		}
		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}
		void push_back(const T& x) {
			//����const��֤��ʲô���Ͷ��У���Ϊ��ʽ����ת����ʱ�������г���
			if (_finish == _end_of_storage) {
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back() {
			assert(_finish > _start);//Ϊ���ǲ���ɾ��
			--_finish;
		}
		void insert(iterator pos, const T& x) {
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_storage) {//����
				//��סpos��start�����λ��
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;//����pos��λ�� -- ���������ʧЧ
			}
			//Ų������
			iterator end = _finish - 1;
			while (end >= pos) { // insertҪ���ݵ�ʱ�����ѭ����ʧЧ�ˣ�ͣ�������ˣ�Ϊʲô��
				*(end + 1) = *end;
				end--;
			}
			//����֮�󣬾ɿռ�����ݿ������¿ռ�
			//�ɿռ��Ѿ����ͷ��� -- pos��ָ��ɿռ��һ�����ֵ�λ�õ�
			//pos����Ұָ�룡 -- ������ʧЧ
			//��������Ҫ��pos����һ��
			// -- �޸����ڲ���pos֮����ʵ���⻹û�и����Ľ��
			*pos = x;
			++_finish;
		}
		iterator erase(iterator pos) {
			assert(pos >= _start);
			assert(pos < _finish);
			//Ų������ɾ��
			iterator begin = pos + 1;
			while (begin < _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			//ɾ����λ�õ���һ��λ�� -- ����pos
			return pos;
		}
		T& front() {
			assert(size() > 0);
			return *_start;
		}
		T& back() {
			assert(size() > 0);
			return *(_finish - 1);
		}
	private:
		iterator _start;//start�൱����������Ŀ�ʼλ��
		iterator _finish;//[_start,_finish)
		iterator _end_of_storage;
	};
}