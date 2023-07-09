
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;


//explicit��ֹ������ʽ����ת����ǿת����



//�ı���д�Ͷ����ƶ�д
//�����ƶ�д���ڴ�����δ洢������������ȥ
// �ŵ㣺�� ȱ�㣺д��ȥ���ݿ�����
// 
//�ı���д�����л����ַ������������Ҳ���ַ����������л��ɶ�������
// �ŵ㣺���Կ���д��ȥ��ʲô ȱ�㣺����һ��ת�����̣�Ҫ��һЩ


struct Date
{
	friend ostream& operator<<(ostream& out, const Date& d)
	{
		out << d._year << " " << d._month << " " << d._day;
		return out;
	}
	friend istream& operator>>(istream& in, Date& d)
	{
		in >> d._year >> d._month >> d._day;
		return in;
	}
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day) {}
	operator bool()
	{
		//��������д�ģ���������_yearΪ0�������
		if (_year == 0)return false;
		else return true;
	}
protected:
	int _year; int _month; int _day;
};

//����
struct ServerInfo
{
	//char _address[32];
	//ע�⣬�����char[]�ĳ�string���ͻ������
	//�ĳ�string֮��д��ȥ�Ľṹ�ᷢ��һЩ�ı䣬Ȼ���������ʱ�򣬳������ڴ����⣨���������������У�
	//��Ϊ������������ָ��ĵ�ַ�ͶԲ�����
	string _address;
	int _port;
	Date _date;
	friend ostream& operator<<(ostream& out, const ServerInfo& si)
	{
		cout << "address: " << si._address << endl;
		cout << "port: " << si._port << endl;
		cout << "Date: " << si._date << endl;
		return out;
	}
	ServerInfo(const string& s = " ", const int& port = 0, const Date& d = { 0,0,0 })
		:_address(s), _port(port), _date(d) {}
};
struct ConfigManager
{
public:
	ConfigManager(const char* filename = "server.txt")
		:_filename(filename) {}

	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out | ios_base::binary);//�ڶ��������Ǵ򿪷�ʽ�����Բ�д
		//���Ҫ�ö��״̬���� | ��һ��
		//Ĭ�ϵ�д�����Ǹ���д ����ȻҲ��һ��׷��д��Ҫ�ÿ��Բ��ĵ�
		ofs.write((char*)&info, sizeof(info));
	}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}
#if 0
	void WriteText1(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out);
		ofs.write(info._address.c_str(), info._address.size());
		ofs.put('\n');//�м任һ����
		const string str = to_string(info._port);
		ofs.write(str.c_str(), str.size());
	}
	void ReadText1(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in);
		char buff[128];
		ifs.getline(buff, 128);
		info._address = buff;
		ifs.getline(buff, 128);
		info._port = stoi(buff);
	}
#endif
	//�������������ȡ��������
	void WriteText2(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out);
		ofs << info._address << endl;
		ofs << info._port << endl;
		ofs << info._date << endl;
	}
	void ReadText2(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in);
		ifs >> info._address >> info._port >> info._date;
	}
	//�������ַ������鷳������ṹ���������ݸ��ӣ��ͺ��Ѹ��ˣ����磬ServerInfo�����и�������
protected:
	string _filename;
};

#if 0
int main()
{
	//Date d1(2022, 11, 28);
	//ServerInfo winfo = { "127.0.0.1",888, {2022,11,28} };
	ConfigManager cm;
	////////cm.WriteBin(winfo);//д��ȥ
	//////cm.WriteText1(winfo);
	//cm.WriteText2(winfo);

	//������Ҫ������
	ServerInfo rinfo;
	//cm.ReadBin(rinfo);
	//cm.ReadText1(rinfo);
	cm.ReadText2(rinfo);
	cout << rinfo << endl;
	return 0;
}
#endif

//���������Ϊ�������ƶ�д����Ҫд�ж�̬�ڴ�Ķ���
//��Ҳ��һ��������
//����������[]��������string




//�ַ�����
//stringstream
#include<sstream>
//C���� sprintf sscanf

struct ChatInfo
{
	string _name;
	int _id;
	Date _date;
	string _msg;
	friend ostream& operator<<(ostream& out, const ChatInfo& cif)
	{
		out << "name: " << cif._name << endl;
		out << "id: " << cif._id << endl;
		out << "date: " << cif._date << endl;
		out << "msg: " << cif._msg << endl;
		return out;
	}
};
int main()
{
	ChatInfo winfo = { "����",135246,{2022,4,10},"����һ�𿴵�Ӱ��" };
	ostringstream oss;
	oss << winfo._name << endl;
	oss << winfo._id << endl;
	oss << winfo._date << endl;
	oss << winfo._msg << endl;
	string info_str = oss.str();
	cout << info_str << endl;

	ChatInfo rinfo;
	//����Ҫ��info_str��������
	istringstream iss(info_str);
	iss >> rinfo._name >> rinfo._id >> rinfo._date >> rinfo._msg;
	cout << rinfo << endl;
	return 0;
	//��Ȼistringstream/ostringstreamֱ����һ��stringstream����
}