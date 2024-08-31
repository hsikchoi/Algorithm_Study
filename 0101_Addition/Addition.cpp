#include <string>
#include <vector>
#include <iostream>

using namespace std;

// �˰��� ������ checkpoint : ��Ȯ��, �ӵ�, ������(����? ���ڴ�? ������ �ӵ�/�޸� �� ��Ȳ�� ���� �ٸ�)
// ���� �ð� ������ ���������� ��ƴ�. -> ��Ȯ�� ������ ���ؼ��� ������ ���� �� ����� ���ؾ��Ѵ�.
// �ڵ带 ������ ������ ������ �ϱ�� ��ư� ���� ȯ�濡 ���󼭵� �ٸ� -> �ڵ带 ���� ����ð��� �����غ� �� �־�� �Ѵ�
// �ѹ� ����Ǵ� �κ�, �ݺ��� �� ������ ����Ǵ� �κ����� ������ -> ������ ũ�Ⱑ Ŀ������ �ӵ��� ���ϴ� �κ��� ������� ���캻��

string Add(string str1, string str2)
{
	// TODO:
	int min_size = min(str1.size(), str2.size());
	int max_size = max(str1.size(), str2.size());    // max_size�� ���� ����ð��� �޶�����

	int temp = 0;
	int num1, num2 = 0;
	string ans_str("");      // ����, ũ��, ��, �޸��Ҵ�, ���ϱ�, ���� ���� ���ڿ��� ��ü ������ min_size, max_size�� ���� -> ��� �ð�(���̿� ������� ���� �ð�)

	for (int i = 0; i < max_size; i++)                  // �ݺ��� ��ü�� ���� ���̰� Ŀ���� ����ð��� ����
	{
		if ((int)(str1.size() - i - 1) >= 0)
			num1 = str1[str1.size() - i - 1] - '0';
		else
			num1 = 0;


		if ((int)(str2.size() - i - 1) >= 0)
			num2 = str2[str2.size() - i - 1] - '0';
		else
			num2 = 0;


		int sub_sum = num1 + num2 + temp;         // ������ ����ð� ��� -> ���̰� Ŀ���� ����ð��� ������ ����
		temp = sub_sum / 10;
		int cont = sub_sum % 10;

		ans_str.insert(0, to_string(cont));     // insert�� ���������� ���ڿ� ���� -> ���ڿ� ���� ����� ���� �ð��� �ɸ�(N�� ����)
	}

	if(temp>0)                              // �Է����� ������ ���� ���� ����� ����, �ȵ� ���� �ִ� ��� -> �־��� ��츦 ������ -> ����ȴٸ� ���̿� ���� insert ����ð� ����
		ans_str.insert(0, to_string(temp));

	return ans_str;
}

// ��� : ���ϱ� �˰����� ����ð��� ���ڿ��� ������ �Լ��̰�, �ܼ�ȭ�ϸ� ���� ������ ����ð��� ���� ��

int main()
{
	vector<vector<string>> tests = {
		{"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		, {"54544", "44545", to_string(54544 + 44545)}
		, {"5555", "55", to_string(5555 + 55)}
		, {"5555", "5555", to_string(5555 + 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];     // "12"
		const string str2 = t[1];     // "34"
		const string expected = t[2]; // "46"

		cout << str1 << " + " << str2 << " = " << expected << endl;

		const string result = Add(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK" << endl;
		else {
			cout << "Not OK" << endl;
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
	

}