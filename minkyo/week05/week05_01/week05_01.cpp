//��ü �л��� �� n
//�������� �л��� �迭 lost
//���� ü���� ������ �л��� ��ȣ reserve

//ü������ ���� �� �ִ� �л� �ִ밪 return 


#include <iostream>
#include <string>
using namespace std;

int solution(int number, int* lost, int reserve[]) { //
	int answer = number;
	for (int i = 0; i < 20; i++) {					// ��ü �л��� ������ �������� �� �л� ����ŭ ����
		if ((lost[i] > 0) && (lost[i] <= 20)) {		// c++���� �迭�� �Ű������� ����� ��� �迭�� �����ͷ� �ν��ϱ⿡
													// size�� Ȯ���� �� ���� �̿� ���� ������� ü���� �����ִ� �л� �� count
			answer--;
		}
		else{
			break;
		}
	}

	for (int i = 0; i < 20; i++) {
		if (!((lost[i] > 0) && (lost[i] <= 20))) {  // 
			break;
		}

		for (int j = 0; j < 20; j++) {
			if (((lost[i]+1)==reserve[j])|| ((lost[i] + 1) == reserve[j])){
				answer++;
				reserve[j] = -1; //�̹� �����༭ ���̻� ������ �� ���� �� reserve�� -1�� �д�
			}

			else if (lost[i] == reserve[j]) {
				reserve[j] = -1; //���� �������� ������ ���� �ִ� �л��� �������� ��� ������ �� ���⿡ -1
			}
		}
	}
	return answer;
}

int main() {

	int lost[] = {2,4 };
	int reserve[] = {1,3,5};
\
	cout << solution(3, lost,reserve);


}