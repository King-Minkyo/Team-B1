//전체 학생의 수 n
//도난당한 학생들 배열 lost
//여벌 체육복 가져온 학생들 번호 reserve

//체육수업 들을 수 있는 학생 최대값 return 


#include <iostream>
#include <string>
using namespace std;

int solution(int number, int* lost, int reserve[]) { //
	int answer = number;
	for (int i = 0; i < 20; i++) {					// 전체 학생들 수에서 도난당한 온 학생 수만큼 빼줌
		if ((lost[i] > 0) && (lost[i] <= 20)) {		// c++에서 배열을 매개변수로 사용할 경우 배열을 포인터로 인식하기에
													// size를 확인할 수 없어 이와 같은 방식으로 체육복 갖고있는 학생 수 count
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
				reserve[j] = -1; //이미 빌려줘서 더이상 빌려줄 수 없을 때 reserve을 -1로 둔다
			}

			else if (lost[i] == reserve[j]) {
				reserve[j] = -1; //문제 조건으로 여벌을 갖고 있는 학생이 도난당한 경우 빌려줄 수 없기에 -1
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