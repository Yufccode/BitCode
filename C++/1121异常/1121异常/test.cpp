
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<functional>
#include<unordered_map>
using namespace std;

#elif
#endif

//throw try catch

#if 0
double Division(int a, int b)
{
	//��b == 0��ʱ�����쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	else
	{
		return ((double)a / (double)b);
	}
}
void Func()
{
	int len = 0;
	int time = 0;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}
int main()
{
	try
	{
		Func();
	}
	catch (int err) //������Ͳ�ƥ��Ҳ������
	{
		cout << err << endl;
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	//catch (const char* errmsg)
	//{
	//	cout << errmsg << endl;
	//}//ͬһ���ط�����������һ����catch

	//��һ�����쳣��֪��ʲô���ͣ�ǰ�����˺ܶ���쳣 -- �����Լ�һ�����ո�
	catch (...) //���Բ����������͵��쳣 -- ��ֹ�������δ�����쳣ʱ�������
	{
		cout << "δ֪�쳣" << endl;
	}
	return 0;
}
#endif

//��Ȼ���ǿ������������͵��쳣 -- ���ǿ�����һ���Ǻܹ淶��
//һ����һ���� -- exception
//����������һ���Լ�д��
//һ�㶼������Щ��Ϣ
#if 0
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg), _errid(id) {}
	virtual string what() const
	{
		return _errmsg;
	}
protected:
	string _errmsg;
	int _errid;
};
double Division(int a, int b)
{
	//��b == 0��ʱ�����쳣
	if (b == 0)
	{
		Exception e("��0����", 1);
		throw e;
	}
	else
	{
		return ((double)a / (double)b);
	}
}
//1.���쳣��������������
//2.����ʱҪ������ƥ��
void Func1()
{
	int len = 0;
	int time = 0;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}
void Func2()
{
	//�������̫�� -- ��ô��
	//������� -- ��������
}
int main()
{
	while (true)
	{
		try
		{
			Func1();
		}
		catch (const Exception& e)
		{
			cout << e.what() << endl;
		}
	}
	return 0;
}
#endif


//������������ͨ��ʹ�õ��쳣�̳���ϵ
#if 0
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg), _id(id) {}
	virtual string what() const
	{
		return _errmsg;
	}
	virtual int getid() const
	{
		return this->_id;
	}
protected:
	string _errmsg;
	int _id;
};

//���ݿ���쳣 -- ���Ǿ�Ҫдһ��ר�ŵ����ݿ��쳣��
class SqlException :public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id), _sql(sql) {}
	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
	virtual int getid() const
	{
		return this->_id;
	}
protected:
	const string _sql;
};


//�����쳣
class CacheException :public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}
	virtual string what() const
	{
		string str = "CacheException";
		str += _errmsg;
		return str;
	}
	virtual int getid() const
	{
		return this->_id;
	}
};

//httpЭ��
#include<time.h>
class HttpServerException :public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id), _type(type) {}
	virtual string what() const
	{
		string str = "HttpServerException";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}
	virtual int getid() const 
	{
		return this->_id;
	}
protected:
	const string _type;
};
void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
	}
	cout << "����ɹ�" << endl;
}
void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("Ȩ�޲���", 200);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("���ݲ�����", 201);
	}
	SQLMgr();
}
#if 0
void HttpServer()
{
	//...
	srand(time(0));
	if (rand() % 3 == 0)
	{
#if 0
		throw HttpServerException("������Դ������", 100, "get");
#endif
		throw HttpServerException("�������", 102, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
	}
	CacheMgr();
}
#endif
void SendMsg(const string& s)
{
	//������Ҫʵ�� -- ������������ʱ�� -- ��������
	// --> �������һ��try-catch���������غ�
	srand(time(0));
	try
	{
		if (rand() % 3 == 0)
		{
			throw HttpServerException("�������", 102, "get");
		}
		else if (rand() % 4 == 0)
		{
			throw HttpServerException("Ȩ�޲���", 101, "post");
		}
		cout << "���ͳɹ�:" << s << endl;
	}
	catch (const std::exception&)
	{

	}
	CacheMgr();
}
void HttpServer()
{
	string str = "����һ��ȥɢ����";
	//cin >> str;
	int n = 3;//��ೢ������
	while (n--)
	{
		try
		{
			SendMsg(str);
			//û�з����쳣
			break;
		}
		catch (const Exception& e)
		{
			//�������
			if (e.getid() == 100 && n > 0)
			{
				continue;
			}
			else
			{
				throw e;//��������쳣�������׳�
			}
		}
	}
}
#include<thread>
int main()
{
	while(1)
	{
		this_thread::sleep_for(chrono::seconds(1));
		try
		{
			HttpServer();
		}
		catch (const Exception & e) //���ﲶ�������Ϳ���
		{
			//��̬
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}
	return 0;
}


//�쳣�������׳�
//�п��ܵ���catch������ȫ����һ���쳣���ڽ���һЩУ�������Ժ�
//ϣ���ٽ��������ĵ���������������
//catch�����ͨ�������׳����쳣���ݹ���ϲ�ĺ������д���
#endif


//�������쳣�����׳��ĵ�һ�ֳ���

//�������쳣�����׳��ĵڶ��ֳ���

double Division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	else
		return ((double)a / (double)b);
}
//һ����˵ -- �������û���쳣������Ƶ�ʱ��
//���ǿ���������delete[]���飨delete[]�򱨴���ֹ����
//�����������쳣������ -- ���������֮��
//ֱ������catch�ĵط��� -- delete[]��û���ü�ִ�� -- �ڴ�й©
void Func()
{
	int* array = new int[10];
	try
	{
		int len; int time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << " " << array << endl;
		delete[]array;
		throw;
	}
	//...
	cout << "delete[]" << " " << array << endl;
	delete[]array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unknown exception" << endl;
	}
	return 0;
}

/*
�쳣��ȫ��
1.���캯����ɶ���Ĺ���ͳ�ʼ������ò�Ҫ�ٹ��캯�����׳��쳣
	������ܵ��¶���������û����ȫ��ʼ��
2.����������Ҫ�����Դ��������ò�Ҫ�������������׳��쳣������
	���ܵ�����Դй¶���ڴ�й©�����δ�رյȣ�
3.C++���쳣�����ᵼ����Դй¶���⣬����new��delete���׳����쳣������û��delete
	��lock��unlock���׳����쳣����������C++����ʹ��RAII�������������
	����RAII����������ָ����ڽ��н���
*/