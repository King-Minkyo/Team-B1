// ĵ���� ���α�
// ������ �������� �ߺ��ؼ� ������ ������ �ֳ׿�

#include <iostream>
#include <string>
using namespace std;


int main() {


	int grid[7][7]; // 7*7 ĵ���� ������ �Է��ϴ� �迭 ���� 
	int gid[7];
	for (int i = 0; i < 7; i++) { //�迭�� ĵ���� ���� �Է� 
		for (int j = 0; j < 7; j++) {
			//	cout << "�Է�" << j << " : ";
			cin >> gid[j];
			grid[i][j] = gid[j];
		}
	}

	//for (int i = 0; i < 7; i++) {		 // �迭�� �� �ԷµǾ����� Ȯ��
	//	for (int j = 0; j < 7; j++) {

	//		cout << grid[i][j];
	//	}
	//	cout << endl;
	//}

	int count = 0;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if((grid[i][j] != grid[i - 1][j]) && ((j==0)||(grid[i][j] != grid[i][j-1]))) // ��ġ�� �κ��� ������ �ϴܸ� ���ϹǷ� ��� �� ���� �� ����


				if (grid[i][j] == grid[i + 1][j]) // ���η� ������ ���� ���� ������ �� �� 
				{
					if (grid[i + 1][j] == grid[i + 2][j] // �Ʒ�
						|| (grid[i + 1][j] == grid[i][j - 1] && (i != 0))      // ���� ��
						|| (grid[i + 1][j] == grid[i + 1][j - 1] && (i != 0))  // ���� �Ʒ�
						|| (grid[i + 1][j] == grid[i + 1][j + 1] && (i != 6))  // ���� �Ʒ�
						|| (grid[i + 1][j] == grid[i][j + 1] && (i != 6)))     // ���� ��
					{
						cout << "1���� " << i << " " << j << endl;
						count++;
					}
				}

				else if ((grid[i][j] == grid[i][j + 1])) // ���η� ������ ������ �� ��
				{
					if ((grid[i][j + 1] == grid[i][j + 2]) && (j != 5) && (j != 6))  // ������ �� �ѤѤѸ�� 
					{
						cout << "2���� " << i << " " << j << endl;
						count++;
					}

				}
			
		}

	}
		cout << "���� �� �ִ� ���� : " << count;
	
}
