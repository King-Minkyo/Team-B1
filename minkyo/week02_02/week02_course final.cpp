#include <iostream>
#include <string>

using namespace std;

int main() {

	int a[2];

	for (int i = 0; i < 2; i++) {
		cin >> a[i];
	}

	int col = a[0];  // �Է��ϴ� ���� ����
	int row = a[1];  // ���� �ڵ��� ����

	string* range = new string[col]; //�����Ҵ�

	cout << "�ڵ� �Է�" << endl;
	for (int i = 0; i < col; i++) {
		cin >> range[i];
	}


	//for (int i = 0; i < col; i++) {
	//	cout << range[i] << endl;
	//}

	int b[2];

	for (int i = 0; i < 2; i++) {
		cin >> b[i];
	}

	int start = b[0] - 1;  // ���� ����� �ڵ� ��ȣ, ù��° �ڵ�� 1��°�̳� �迭������ 0���� �޾Ƶ���
	int end = b[1] - 1;

	//�ع� ��� Ž��, �ع� ��δ� �ع� �Ÿ��� 1�� ���,
	//�� �ڵ��� ���ڸ� ���� �ٸ� ��� count++, count�� 1�� �� �ع� �Ÿ��� 1�̹Ƿ� ���;
	int sameCount = 0;
	int count = 0;

	int minus = 0; 
	while (1) {
		for (int i = 0; i < col; i++) {
			
			for (int j = 0; j < row; j++) {
				if ((start + i) > (col - 1)) { //���ϴ� �迭�� ũ�� �̻��� ��� ������ ���ƿͼ� Ž���� �� �ֵ��� minus ���
					minus = col;
				}
				else{
					minus = 0;
				}
				if (range[start][j] != range[start + i - minus][j]) {
					count++;
				}
			}
			if (count == 1) {
				if (sameCount == 0) {
					cout << b[0] << " "; //��ΰ� ���� ��� ���� �ڵ��ȣ �Է�
				}
				cout << start + i + 1 - minus << " " ;
				start = start + i - minus;
				count = 0;
				sameCount++;
				break;
			}
			count = 0;
		}
		if (start == (b[0] - 1)) { //start�� ���� ��ȭ�� ���ٸ�(��ΰ� ���ٸ�) -1 ��� �� �ݺ��� Ż��
			cout << -1;
			break;
		}

		else if (start == end) { //�ع� ��θ� ã�Ҵٸ� �ݺ��� Ż��
			break;
		}
	}






	delete[] range; // ���޸� ����

	return 0;
}