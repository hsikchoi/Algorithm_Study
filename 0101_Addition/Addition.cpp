#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 알고리즘 공부의 checkpoint : 정확성, 속도, 개선점(좋다? 나쁘다? 기준은 속도/메모리 등 상황에 따라 다름)
// 실행 시간 측정은 현실적으로 어렵다. -> 정확한 실험을 위해서는 여러번 수행 후 결과를 비교해야한다.
// 코드를 수정할 때마다 실험을 하기는 어렵고 실행 환경에 따라서도 다름 -> 코드를 보고 실행시간을 가늠해볼 수 있어야 한다
// 한번 실행되는 부분, 반복문 등 여러번 수행되는 부분으로 나눈다 -> 문제의 크기가 커질수록 속도가 변하는 부분은 어디인지 살펴본다

string Add(string str1, string str2)
{
	// TODO:
	int min_size = min(str1.size(), str2.size());
	int max_size = max(str1.size(), str2.size());    // max_size에 따라서 실행시간이 달라진다

	int temp = 0;
	int num1, num2 = 0;
	string ans_str("");      // 대입, 크기, 비교, 메모리할당, 더하기, 빼기 등은 문자열의 전체 길이인 min_size, max_size와 무관 -> 상수 시간(길이에 상관없이 일정 시간)

	for (int i = 0; i < max_size; i++)                  // 반복문 전체로 보면 길이가 커지면 실행시간이 증가
	{
		if ((int)(str1.size() - i - 1) >= 0)
			num1 = str1[str1.size() - i - 1] - '0';
		else
			num1 = 0;


		if ((int)(str2.size() - i - 1) >= 0)
			num2 = str2[str2.size() - i - 1] - '0';
		else
			num2 = 0;


		int sub_sum = num1 + num2 + temp;         // 연산은 실행시간 상수 -> 길이가 커져도 실행시간은 변하지 않음
		temp = sub_sum / 10;
		int cont = sub_sum % 10;

		ans_str.insert(0, to_string(cont));     // insert는 내부적으로 문자열 복사 -> 문자열 길이 길수록 오랜 시간이 걸림(N에 의존)
	}

	if(temp>0)                              // 입력으로 들어오는 값에 따라서 실행될 수도, 안될 수도 있는 경우 -> 최악의 경우를 따지기 -> 실행된다면 길이에 따라 insert 실행시간 증가
		ans_str.insert(0, to_string(temp));

	return ans_str;
}

// 결론 : 더하기 알고리즘은 실행시간이 문자열의 길이의 함수이고, 단순화하면 직선 형태의 실행시간을 보일 것

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