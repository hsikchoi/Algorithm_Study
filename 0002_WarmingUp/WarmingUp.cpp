#include <iostream>
#include <string>
using namespace std;

int main()
{
	// ���� 1. 10���� -> 2����
	{
		int decimal = 105;
		string binary;

		//TODO:
		int cnt = 1;
		while (1)
		{
			int res = decimal % 2;
			decimal = decimal / 2;
			
			binary.insert(0, to_string(res));

			if (decimal == 0)break;
		}

		cout << binary << endl; // 1101001
	}

	// ���� 2. ���ڿ� ������
	{
		string input = "Hello, World!";

		// TODO:
		//reverse(input.begin(), input.end());
		int last_idx = (int)input.size() - 1;
		
		for (int i = 0; i <= last_idx / 2; i++)
		{
			swap(input[i], input[last_idx - i]);
		}

		cout << input << endl; // !dlroW ,olleH
	}
	
	// ���� 3. ��� �ڸ� �� ���ϱ�
	{
		string n = "789789";

		// TODO:
		int temp = 0;
		do 
		{
			temp = 0;
			for (int i = 0; i < n.size(); i++)
			{
				temp += n[i] - '0';
			}

			n = to_string(temp);

		} while (temp / 10 != 0);


		n = to_string(temp);

		cout << n << endl;
	}

	return 0;
}