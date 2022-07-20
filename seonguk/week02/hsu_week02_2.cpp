//���� (codeUP 4685)
//���̰� ���� �� ���� ������ �ڵ� A�� B�� �ִٰ� ����.�� �� �ڵ� ������ �ع� �Ÿ��� A�� B�� �� ��Ʈ�� ���ʺ��� ���������� ���ʴ�� ���� �� ���� �ٸ� ���� ���� ��Ʈ�� ���̴�.���� ���, A = 010010, B = 011011 �̶�� �ϸ�, �� ��° ��Ʈ�� ���� ��° ��Ʈ�� ���� �ٸ��Ƿ� �� �� �ڵ� ������ �ع� �Ÿ��� 2�̴�.
//�츮�� �� N���� ���� �ڵ带 ������ �ְ�, �� �ڵ��� ���̴� K�� ����.
//���� ���, ������ ���� ���̰� 3�� 5���� ���� �ڵ���� �ִ�.
//A = 000, B = 111, C = 010, D = 110, E = 001
//�� �ڵ� A�� B������ �ع� �Ÿ��� H(A, B)�� ǥ���Ѵ�.�׷���, H(A, B) = 3, H(A, C) = 1, H(A, D) = 2, H(A, E) = 1 �̴�.
//�츮�� ���� �ڵ�鿡 ���� �ع� ��θ� ã���� �Ѵ�.�ع� ��δ� ��� ������ �� �ڵ������ �ع� �Ÿ��� 1�� ����̴�.���� ������(A, C, D)�� �ڵ� �� �� �ع� �Ÿ��� 1�̰�, �ڵ� C�� D�� �ع� �Ÿ��� 1�̹Ƿ� �ع� ����̴�. (A, E, B)�� �ڵ� A�� E�� �ع� �Ÿ��� 1������, �ڵ� E�� B�� �ع� �Ÿ��� 2�̹Ƿ� �ع� ��ΰ� �ƴϴ�.
//�� ������ �־��� �� �ڵ� ���̿� ���� ª�� �ع� ��θ� ���ϴ� ���α׷��� �ۼ��ϴ� ���̴�.
//�Է�
//ù° �ٿ��� �� ���� ���� N�� K�� ��ĭ�� ���̿� �ΰ� �־�����(3��N��1, 000, 2��K��30).
//��° �ٺ��� N���� �ٿ��� �� �ٸ��� ���̰� K�� ���� �ڵ尡 �ϳ��� �־�����.�ϳ��� �ڵ�� ��ĭ�� ���� �־�����.�ڵ���� �־��� ������� 1���� N������ ��ȣ�� ���еȴ�.�ڵ尡 ���� ���� ����.
//�� ���� �ٿ��� �ع� ��θ� ã���� �ϴ� ���� �ٸ� �� ���� �ڵ� A�� B�� ������ �ڵ��ȣ�� �־�����.
//���
//�Է����� �־��� �� �ڵ� ���̿� �ع� ��ΰ� �����ϸ� �� ��� �� ���� ª�� ��θ� �ڵ� A���� �ڵ� B���� ��λ��� �ڵ� ��ȣ�� ����Ѵ�.�ڵ� ��ȣ�� ����� ��쿡�� �ڵ� ��ȣ ���̿� �ϳ��� ��ĭ�� ���̿� �ΰ� ����Ѵ�.���� ���� ���� �� ������ �� �߿� �ϳ��� ����ϰ�, ��ΰ� �������� ������ - 1�� ����Ѵ�.
#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;


vector<int> hamingCheck;
//�Ÿ�Ȯ���Ͽ� �̵��� �ε��� üũ

//�ε��� ũ�� Ȯ�� �� ���� �°� ���� ��Ű��
int checkSize(int &number, int &vectorSize) {
	number++;
	if (number >= vectorSize)
		number = number - vectorSize;

	return number;
}

//�ε����� �� Ȯ���ߴ��� Ȯ�� �� ������ �ݺ����� Ż�� �� �� �ִ� �Լ�(hamingCheck�̿�)
bool checkPrime(int number) {
	bool prime = true;
	for (int k = 0; k < number; k++) {
		if (hamingCheck[k]==1)
			prime = false;
		else {
			prime = true;
			break;
		}
	}
	return prime;
}
//���� Ȯ���ؼ� 1�� �͸� ���
int hamingDistance(vector<string> &haming,int &number,int &length,int &startNumber, int &endNumber,int end) {
	int distance = 0;
	bool vectorPrime = true;
	while (vectorPrime) {
		if (hamingCheck[startNumber]==1) {
			vectorPrime =checkPrime(number);
			if (vectorPrime)
				continue;
			checkSize(startNumber, number);
		}
		else if (hamingCheck[endNumber]==1)
			checkSize(endNumber, number);
		else {//�ع� �Ÿ� Ȯ��
			for (int i = 0; i < length; i++) {
				if (haming[startNumber][i] != haming[endNumber][i])
					distance++;
			}

			//�ع� �Ÿ��� 1�̵Ǹ�,
			if (distance == 1) {
				cout << startNumber+1 << " ";
				hamingCheck[startNumber] = 1;
				startNumber = endNumber;
				if (startNumber==end) {
					return end + 1; //���� �ε��� Ȯ�������� �Լ� Ż��
				}
				checkSize(endNumber, number);
				if (startNumber == endNumber)
					checkSize(endNumber, number);
				hamingDistance(haming, number, length, startNumber, endNumber,end);
				
			}//1�� �ƴϸ�,
			else  {
				checkSize(endNumber, number);
				if (startNumber == endNumber)
					checkSize(endNumber, number);
				hamingDistance(haming, number, length, startNumber, endNumber,end);
			}
		}
	}
	//�ݺ��� ���� �ȸ����� -1 ���
	return -1;
}


int main() {
	//���� ����
	int length;
	int number;
	vector<string> haming;
	string s;
	int startNumber, endNumber;
	//�� �Է¹ޱ�
	cin >> number >> length;

	for (int i = 0; i < number; i++) {
		cin >> s;
		haming.push_back(s); //�� ���� vector
		hamingCheck.push_back(0); //üũ���� Ȯ���ϱ� ���� vector
	}

	cin >> startNumber >> endNumber;
	startNumber--; //�Է½�, index +1�� ���ͼ� �����ϴ� �κ�
	endNumber-- ;

	//�Ÿ� ���ϱ�
	const int end = endNumber; //��ΰ� ������ �κ� ����
	cout <<hamingDistance(haming, number, length, startNumber, endNumber,end);
	
	return 0;
}