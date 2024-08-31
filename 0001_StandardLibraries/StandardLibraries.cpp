#include <string> // std::string
#include <vector> // std::vector
#include <list>   // std::list
#include <iostream>

using namespace std;

int main()
{
	// �ڷᱸ�������� �������� �ڷᱸ������ ������ ���α׷��� ������ �����߽��ϴ�.
	// ���⿡�����ʹ� �ڷᱸ���� ǥ�ض��̺귯���� Ȱ���ϰ� 
	// ��ſ� ���� �� ���� �������� �˰��뿡 �����ϰڽ��ϴ�.
	// �⺻���� ��������� �Ʒ��� �����صξ����ϱ� �� �Ⱦ����.

	// ���ϰ� ����� �� �ִ� ���ڿ� std::string
	// #include <string>
	{
		std::string my_string = "Hello, World"; // ������ using namespace�� �����߱� ������ std:: ���� ����
		// string my_string("Hello, World"); // �����ڷ� �ʱⰪ ����

		cout << my_string << endl;

		// int i = my_string.size(); // ��� �߻�: conversion from 'size_t' to 'int', possible loss of data
		// size_t�� ��ȣ ���� �����Դϴ�. x86������ 32bit, x64������ 64bit �Դϴ�.
		// ���⼭�� ���ǻ� size_t ��ſ� int�� ����ϰ� ���� �����մϴ�.

		for (int i = 0; i < my_string.size(); i++) // size()�� ���� ��
			cout << my_string[i]; // �迭ó�� �ε��� ����
		cout << endl;

		for (int i = 0; i < my_string.size(); i++)
		{
			char c = my_string[i]; // �� ���ڴ� char �ڷ���
			cout << c;
		}
		cout << endl;

		// for-each ������ ����ϸ� ���մϴ�. my_string���� �� ���ھ� c�� ���ϴ�.
		for (char c : my_string)
			cout << c;
		cout << endl;

		// �ڷ��� �߷�(type inference)
		// auto i = 123; // ��Ȯ�� �ڷ��� ��ſ� auto�� ����ϸ� ��ȣ �������� ���� �ڷ����� �߷��ؼ� �������ݴϴ�.
		// auto i = my_string.begin(); // ���⼭ i�� ���ͷ�����(std::string::iterator) �ڷ����Դϴ�. 
		// std::string::iterator�� �Ź� Ÿ�����ϴ� ���� ���ŷӰ� �������� �������µ� auto�� ����ϸ� ���������ϴ�.

		// iterator ���� (���������δ� ���̽� �߿��ڽ��� ������ ���ͷ����Ϳ� ���� �����Դϴ�.)
		for (auto i = my_string.begin(); i != my_string.end(); i++)
		{
			char c = *i;
			cout << c;
		}
		cout << endl;
	}

	// ���ڿ��� �Ϻ�(substring)�� �������� ���� �� substr()
	{
		string temp("1234567890");
		int mid = 5; // �ٲ㰡�鼭 �׽�Ʈ �غ�����.
		string a = temp.substr(0, temp.size() - mid);
		string b = temp.substr(temp.size() - mid, mid);

		cout << a << " " << b << endl; // 12345 67890
	}

	// stoi ���ڿ��� ������ ��ȯ�� �� ���
	{
		auto i = stoi(string("123")); // stoi("123") ����
		cout << i * stoi("456") << endl; // 56088
	}

	// std::vector (���� �迭)
	{
		vector<int> my_vector = { 1, 2, 3, 4, 5 }; // ������ �迭ó�� ����� �� �ֽ��ϴ�. ���������� ���� �޸𸮸� ����մϴ�.

		for (int i = 0; i < my_vector.size(); i++)
		{
			int a = my_vector[i];
			cout << a << " ";
		}
		cout << endl;

		for (int a : my_vector)
			cout << a << " ";
		cout << endl;

		for (int& a : my_vector) // <- int�� reference ���
			a *= 10;

		for (int a : my_vector)
			cout << a << " "; // <- ����� ���� ���
		cout << endl;

		for (auto a : my_vector) // auto�� �ڵ����� �ڷ����� �����ϱ� ������ ���մϴ�. auto ���� ���콺�� ���� ���� int�� ���ɴϴ�.
			cout << a << " ";
		cout << endl;

		my_vector.push_back(1000); // �� �ڿ� �� �߰�
		for (auto a : my_vector)
			cout << a << " ";
		cout << endl;
	}

	// std::list (linked list)
	// #include <list>
	{
		list<double> my_list; // double �ڷ������� ���� �� �ִ� linked list
		my_list.push_back(1);
		my_list.push_back(2);
		my_list.push_front(0);

		for (auto v : my_list)
			cout << v << " ";
		cout << endl;
	}

	// �� �ܿ� stack, queue, priority_queue ���� �ִµ� ������ �������ϱ� ������ �ڿ� ���ö����� �ȳ��ص帮�ڽ��ϴ�.

	return 0;
}