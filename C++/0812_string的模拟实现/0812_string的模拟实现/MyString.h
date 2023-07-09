#pragma once
#include<cstring>
#include<cassert>
#include<iostream>
using namespace std;


//Ϊ�����ֺͿ�����ģ������������ռ������
namespace MyString {
	class string {
	public:
		//������
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		//const������ -- ֻ����д
		const_iterator begin() const {
			return _str;
		}
		const_iterator end() const {
			return _str + _size;
		}
		//����
#if false
		string()//��ʼ����ʱ��һ�����ܸ�nullptr����Ϊ�������һ���ն����ʱ��ȥ��ӡ
			//�ͻ���ɿ�ָ��Ľ�����
			//���߸�ȫȴ��
			:_str(new char[1]),
			_size(0),
			_capacity(0)
		{
			_str[0] = '\0';//��һ���ռ��'\0'
		}
#endif
		string(const char* str = "\0")//д""�ǵȼ۵ģ���Ϊ""���Դ�'\0'
			//:_str(new char[strlen(str) + 1]),
			//_size(strlen(str)),
			//_capacity(strlen(str)) -- ������������strlen() -- ���ó�ʼ���б���
		{
			//��̬���ٿռ�
			size_t len = strlen(str);
			_str = new char[len + 1];
			_size = len;
			_capacity = len;
			strcpy(_str, str);
		}
		//����
		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//��������(ʵ��һ�����)		
		//д��1����ͳд��
#if 0
		string(const string& s) 
			:_str(new char[s._capacity+1]),
			_size(s._size),
			_capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}

		//��ֵ����
		string& operator=(const string& s) {
			if (this == &s)return *this;//�Լ����Լ���ֵ -- ֱ�ӱܿ�
			//����ʲô�������ѡ���ԭ���Ŀռ��ͷŵ�+���µĿռ�+����
			char*tmp = new char[s._capacity + 1];//һ��Ҫ�ǵ�+1
			//newʧ����ô�� -- �����ͻ���ɿ���ʧ�ܣ�����ԭ����string���ͷ��ˣ����������new��deleteԭ����
			strcpy(tmp, s._str);
			delete[] _str;

			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			return *this;
			//����д�Ļ����Լ����Լ���ֵ�ͻ������ -- ��Ϊ�Լ����Լ��ͷ��� -- �����Լ� -- �������ľ������ֵ��
		}
#endif
		//�ִ�д��
		//������������
		void swap(string& tmp) {
			std::swap(_str, tmp._str);
			std::swap(_size, tmp._size);
			std::swap(_capacity, tmp._capacity);
		}
		string(const string& s)
			: _str(nullptr),
			_size(0),
			_capacity(0)
		{
			//��Ϊs����Ķ������������ֵ
			//�������tmp֮��tmp�����������ǻ������� -- ��������Ķ����ͻ������
			//����0����null�ǲ��������ģ����Գ�ʼ��һ��
			//��ΪswapҪƵ�����ã����������Լ���дһ�����
			string tmp(s._str);
			swap(tmp);//this->swap(tmp)
		}
		//д��2��
#if 0
		string& operator=(const string& s) {
			if (this == &s)return *this;//�Լ����Լ���ֵ -- ֱ�ӱܿ�
			string tmp(s);
			swap(tmp);//this��swap��
			return *this;
			//��ԭ����s����tmp֮�� -- tmp����Ҫ��æ��ɨs�Ŀռ䣬��Ϊtmp��һ���ֲ�����
		}
#endif
		//д��3
		string& operator=(string s) {//s���Ƕ���tmp��s����ɿ����ˣ������Ǿֲ�����
			swap(s);
			return *this;
		}
		//���Ժ������ݽṹ��ѧϰ�� -- �ִ�д�������ƻ����
		
		
		//size
		size_t size()const {
			return _size;
		} 
		size_t capacity()const {
			return _capacity;
		}
		//[]����
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos) const { //����ǲ���д��
			assert(pos < _size);
			return _str[pos];
		}
		//����C�ַ����ӿ�
		const char* c_str() {
			return _str;
		}
		void reserve(size_t n) {
			if (n > _capacity) {
				//���ݲ�����
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}
		void resize(size_t n, char ch = '\0') {
			//���ռ�+��ʼ��
			if (n > _size) {
				//��������
				reserve(n);
				for (size_t i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else {
				//ɾ������
				_str[n] = '\0';
				_size = n;
			}
		}
		void push_back(char ch) {
			//����ȥдCheckCapacity������������дreserve������������ã�
#if 0
			if (_size==_capacity)
			{
				//ע�⣺���һ��ʼ�����˹����ȱʡֵ��Ҳ����0���Ͳ�����������
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';//һ��Ҫ�ǵ�'\0'
#endif
			insert(_size, ch);
		}
		void append(const char* str) {
#if 0
			size_t len = strlen(str);
			if (_size + len > _capacity)//ע�⣬��ʱ�������ݶ����ˣ���Ϊ���ܲ���
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);//�ĸ��ã�
			//strcat(_str, str);//���Ч���ǱȽϵ͵� -- ��ΪҪȥstrcatҪȥ��'\0',����׷�ӵ�ʱ��Ч�ʷǳ��ͣ�
			_size += len;
#endif
			insert(_size, str);
		}
		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}
		//insert
		string& insert(size_t pos, char ch) {
			assert(pos <= _size);
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			//pos==0�����һ�ִ�����
#if 0
			int end = _size;
			while (end >= (int)pos) {
				//ע�⣺pos==0��ʱ�������⣬end--֮�����-1->�������ֵ�����Ը�posǿתһ��,_size�ĳ�int����
				_str[end + 1] = _str[end];
				--end;
			}
#endif
			//�ڶ��ִ�����(�Ƚ��Ƽ�)
			size_t end = _size + 1;//��Щ����ģ�������uint
			while (end > pos)//����д�ɴ��ڣ�
			{
				_str[end] = _str[end - 1];//����ĳ�-1
				--end;
			}
			_str[pos] = ch;
			++_size;
			return * this;
		}
		//ʵ����Щ�ӿ�һ��Ҫ��ϸ�ĺ�ϸ�ģ�
		string& insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			//Ų������
			size_t end = _size + len;//��Щ����ģ�������uint
			while (end >= pos + len)//����д�ɴ��ڣ�
			{
				_str[end] = _str[end - len];//����ĳ�-1
				--end;
			}
			//������
			strncpy(_str + pos, str, len);//������ncpy����Ҫ��'\0'������ȥ
			_size += len;
			return *this;
		}
		//erase
		string& erase(size_t pos, size_t len = npos) {
			assert(pos < _size);
			if (len == npos || pos + len >= _size) {
				//�൱��pos�����ȫ��ɾ����
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				//ɾ������
				//��ҪŲ������
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		void clear() {
			_str[0] = '\0';
			_size = 0;
		}
		//findϵ��
#if true
		size_t find(char ch, size_t pos = 0) {
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++) {
				if (ch == _str[i]) {
					return i;
				}
				return npos;
			}
		}
		size_t find(const char* sub, size_t pos = 0) {
			//strstr -- ����
			//�ַ���ƥ���㷨 kmp/bm
			assert(pos < _size);
			assert(sub);
			const char* ptr = strstr(_str + pos, sub);
			if (ptr == nullptr) {
				return npos;
			}
			return ptr - _str;
		}
		//substr --  ��posλ�ÿ�ʼ��ȡlen���ַ�
		string substr(size_t pos = 0, size_t len = npos)const {
			//���øı��Լ���constҲ��
			assert(pos < _size);
			size_t realLen = len;
			if (len == npos || pos + len > _size) {
				//����Χ��
				//�ж���ȡ����
				realLen = _size - pos;
			}
			string sub;
			for (size_t i = 0; i < realLen; ++i) {
				sub += _str[pos + i];
			}
			return sub;
		}
#endif
		//��������رȽ�ϵ��
#if true
		bool operator>(const string& s)const {
			return strcmp(_str, s._str) > 0;
		}
		bool operator==(const string& s)const {
			return strcmp(_str, s._str) == 0;
		}
		bool operator>=(const string& s)const {
			return *this > s || *this == s;
		}
		bool operator<=(const string& s)const {
			return !(*this > s);
		}
		bool operator<(const string& s)const {
			return !(*this >= s);
		}
		bool operator!=(const string& s)const {
			return !(*this == s);
		}
#endif
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		//���npos������������Ҳ����ȡ���Ŷ�
		const static size_t npos = -1;
	};
	//����ȡ��������
	//���Ǳ�������Ԫ�ģ���Ϊ��һ��Ҫ����˽�У�����Ͳ���
	ostream& operator<<(ostream& out, const string& s) {
		for (size_t i = 0; i < s.size(); i++) {
			out << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s) {

		s.clear();

		//�����ַ����ܳ�������+=��Ƶ�����ݣ�Ч�ʺܵͣ���ҿ�����취�Ż�һ��
		//1.reserve() -- ȱ�ݣ��˷ѿռ�
		//2.��string�ȣ��ȷŵ�һ����ʱ�������棬��Ϊ�����ʱ��������ջ�ϵ� -- ����>>��������
		char ch;
		ch = in.get();

		const size_t N = 32;
		char buff[N];
		size_t i = 0;

		//s.reserve(128);
		while (ch != ' ' && ch != '\n') {
			buff[i++] = ch;
			if (i == N - 1) {//��ʾ����
				buff[i] = '\0';
				s += buff;//һ��һ���ӵ�string����
				i = 0;
			}
			ch = in.get();
		}
		//�����һ������ȥ
		//buff�൱�ڻ�����
		buff[i] = '\0';
		s += buff;
		return in;
		//�������ڻ���bug
		//����ַ�������ԭ���ж����Ļ���������
		//������Ҫ���һ��string
	}
	//size_t string::npos = -1;//�������涨��
	//����const static�����������������ȱʡ������Ͳ���д�ˣ�����C++������
}