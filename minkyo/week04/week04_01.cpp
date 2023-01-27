#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int solution(vector<int> info, vector<vector<int>> edges) {
//    int answer = 0;
//    return answer;
//}

int solution(int info[], int edges[][2]) {
	int sheep = 1;
	int wolf = 0;
	int start = 0;
	int count = 0; ////
	while (1) {
		info[0] = 2;

		for (int i = 0; i < 12; i++) {
			if (i == start) {							//나아감
				if (info[edges[start][1]] == 0) {		//양이 있는 경우
					sheep++;
					start = edges[start][1];
					info[edges[start][1]] = 2;
					count++;
					break;

				}
				else if (info[edges[start][1]] == 1) {	//늑대가 있는 경우
					if ((i == start) && (sheep > wolf)) {		//나아갈 수 있음
						start = edges[start][1];
						wolf++;
						count++;
						info[edges[start][1]] = 2;
						break;

					}

					if ((i == start) && (sheep <= wolf)) {		//나아갈 수 없음
						start = 0;
						break;
					}

				}

				else if (info[edges[start][1]] == 2) {	//이미 지나갔던 길
					start = edges[start][1];
					count++;
					break;
				}


			}


			if (count >= 1000)
				break;
		}


		return sheep;
	}


}
int main() {
	int info[12] = { 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 };
	int edges[12][2] = { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5 },{4,6},{8,9} };

	/*cout << edges[2][1];*/

	cout << solution(info, edges);

}
