//����
//ĵ������ 7 * 7 ����� ���� �ǿ� ���� ������ ���� 3�� �̻��� �κ��� ã�� ��ġ�ϸ� �����鼭 ������ ��� �����̴�.�̶� ���ӵ� �κ��� ��, ��, ��, �츸 �Ǵ��Ѵ�.
//�� ĵ���� ȭ�鿡�� ��ġ�ϸ� ������ ������ �� 4���� �����Ѵ�.
//ĵ���� ���� ������ �־����� �� ��ġ�ϸ� ������ ������ ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//ĵ���� ������(7 * 7)�� ���� ����(1~5)�� �Էµȴ�.
//�� ��������
//���� = 1, ��� = 2, �Ķ� = 3, �ʷ� = 4, ���� = 5

#include<iostream>
using namespace std;
//���� ���� ����
const int max_row = 7; //�ִ� ����
const int max_col = 7; //�ִ� �ప
int candyBoard[max_row][max_col] = {0}; //ĵ���ο� ����(����)�� �Է��� �迭
int checkBoard[max_row][max_col] = {0}; //Ȯ�� �ߴ��� üũ�� �迭

//�ֺ� Ȯ�ο� �Լ�
int checkPoint(int row,int col) {
	int count = 1; //���� ���� �� Ȯ��
	int color = candyBoard[row][col]; //���� ����� ����
	checkBoard[row][col] = 1; //Ȯ���� Ÿ�� üũ

	//index�ϳ��� �÷����� ���� ���� �ִ� �� Ȯ��(����Լ� �̿�)
		if (color == candyBoard[row + 1][col] && row < max_row - 1) {
			if (color == candyBoard[row + 2][col] && row < max_row - 2 && checkBoard[row+2][col]==0) {
				count++;
				count += checkPoint(row + 1, col);
			}if (color == candyBoard[row + 1][col + 1] && col < max_col - 1 && checkBoard[row + 1][col + 1] == 0) {
				count++;
				count += checkPoint(row + 1, col);
			}if (color == candyBoard[row + 1][col - 1] && col > 0 && checkBoard[row + 1][col - 1] == 0) {
				count++;
				count += checkPoint(row + 1, col);
			}
		}
		if (color == candyBoard[row - 1][col] && row > 0) {
			if (color == candyBoard[row - 2][col] && row > 1 && checkBoard[row - 1][col] == 0) {
				count++;
				count += checkPoint(row - 1, col);
			}if (color == candyBoard[row - 1][col + 1] && col < max_col - 1 && checkBoard[row - 1][col + 1] == 0) {
				count++;
				count += checkPoint(row - 1, col);
			}if (color == candyBoard[row - 1][col - 1] && col > 0 && checkBoard[row - 1][col - 1] == 0) {
				count++;
				count += checkPoint(row - 1, col);
			}
		}
		if (color == candyBoard[row][col + 1] && col < max_col - 1) {
			if (color == candyBoard[row - 1][col + 1] && row > 0 && checkBoard[row - 1][col + 1] == 0) {
				count++;
				count += checkPoint(row, col + 1);
			}if (color == candyBoard[row + 1][col + 1] && row < max_row - 1 && checkBoard[row + 1][col + 1] == 0) {
				count++;
				count += checkPoint(row, col + 1);
			}if (color == candyBoard[row][col + 2] && col < max_col - 2 && checkBoard[row][col + 2] == 0) {
				count++;
				count += checkPoint(row, col + 1);
			}
		}
		if (color == candyBoard[row][col - 1] && col > 0) {
			if (color == candyBoard[row + 1][col - 1] && row < max_row - 1 && checkBoard[row + 1][col - 1] == 0) {
				count++;
				count += checkPoint(row, col - 1);
			}if (color == candyBoard[row - 1][col - 1] && row > 0 && checkBoard[row - 1][col - 1] == 0) {
				count++;
				count += checkPoint(row, col - 1);
			}if (color == candyBoard[row][col - 2] && col > 1 && checkBoard[row][col - 2] == 0) {
				count++;
				count += checkPoint(row, col - 1);
			}
		}
	return count;
}



int main() {
	int point = 0;
	//Ÿ�� ä���(�Է� �ޱ�)
	cout << "Ÿ�� �Է�" << "\n";
	for (int i = 0; i < max_row; i++)
		for (int j = 0; j < max_col; j++)
			cin >> candyBoard[i][j];
	//Ÿ�� Ȯ��
	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			if(checkPoint(i, j)>=3) //count(���� ����) ������ 3�� �̻��Ͻ� +1 point
				point++;
		}
	}
	//���
	cout << point;
	return 0;
}