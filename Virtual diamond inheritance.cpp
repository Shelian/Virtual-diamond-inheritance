#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	int ia;
	char ca;
public:
	A()
	:ia(0)
	, ca('A')
	{}

	virtual void f()
	{
		cout << "A::f()" << endl;
	}

	virtual void Bf()
	{
		cout << "A::Af()" << endl;
	}
};

class B1:virtual public A
{
public:
	int ib1;
	char cb1;
public:
	B1()
	:ib1(1)
	, cb1('1')
	{}
	virtual void f()
	{
		cout << "B1::f()" << endl;
	}

	virtual void f1()
	{
		cout << "B1::f1()" << endl;
	}

	virtual void B1f()
	{
		cout << "B1::B1f()" << endl;
	}

};

class B2:virtual public A
{
public:
	int ib2;
	char cb2;
public:
	B2()
	:ib2(2)
	, cb2('2')
	{}

	virtual void f()
	{
		cout << "B2::f()" << endl;
	}

	virtual void f2()
	{
		cout << "B2::f2()" << endl;
	}

	virtual void B2f()
	{
		cout << "B2::B2f()" << endl;
	}

};

class D :public B1,public B2
{
public:
	int id;
	char cd;
public:
	D()
		:id(3)
		, cd('D')
	{}

	virtual void f()
	{
		cout << "D::f()" << endl;
	}

	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "D::f2()" << endl;
	}

	virtual void Df()
	{
		cout << "D::Df()" << endl;
	}

};

typedef void(*Fun)();
void PrintVTable(int* VTable)
{
	cout << " ����ַ>" << VTable << endl;

	for (int i = 0; VTable[i] != 0; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, VTable[i]);
		Fun f = (Fun)VTable[i];
		f();
	}
}



void test()
{
	A a;
	B1 b1;
	B2 b2;
	D d1;

	cout << "sizeof(A)::" << sizeof(a) << endl;
	cout << "sizeof(B1)::" << sizeof(b1) << endl;
	cout << "sizeof(B2)::" << sizeof(b2) << endl;
	cout << "sizeof(D)::" << sizeof(d1) << endl;

	int* VTable = (int*)(*(int*)&d1);
	PrintVTable(VTable);
	cout << "		�����ָ��->: " << (int*)((int*)&d1 + 1) << endl;
	cout << "		 B1::ib1 = " << *(int*)((int*)&d1 + 2) << endl;
	cout << "		 B1::cb1 =" << (char)*((int*)&d1 + 3) << endl;

	VTable = (int*)*((int*)&d1 + 4);
	PrintVTable(VTable);
	cout << "		�����ָ��->:" << (int*)((int*)&d1 + 5) << endl;
	cout << "		 B2::ib2 =" << *(int*)((int*)&d1 + 6) << endl;
	cout << "		 B2::cb2 =" << (char)*((int*)&d1 + 7) << endl;

	cout << "		 D::ID =" << *((int*)&d1 + 8) << endl;
	cout << "		 D::cd =" << (char)*((int*)&d1 + 9) << endl;
	cout << " ������ƫ�Ƶ�ַ->:"<<(int*)((int*)&d1 + 10) << endl;
	VTable = (int*)*((int*)&d1 + 11);
	PrintVTable(VTable);
	cout << "		 A::ia =" << *(int*)((int*)&d1 + 12) << endl;
	cout << "		 A::ca =" << (char)*((int*)&d1 + 13) << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}
