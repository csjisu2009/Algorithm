#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printAnswer(vector<string> answer) {
	int answerSize = answer.size();
	for (int i = 0; i < answerSize; i++) {
		int iAnswerLen = answer[i].length();
		for (int j = 0; j < iAnswerLen ; j++) {
			cout << answer[i].at(j);
			if (answer[i].at(j) == '.') {
				cout << "\n";
				break;
			}
		}
	}
}

string getIdFromRec(string iRecord) {
	int posSpacebar1 = -1, posSpacebar2 = -1;
	int idLen;
	
	int countSpacebar = 0;
	int iRecordLen = iRecord.length();
	for (int i = 0; i < iRecordLen ; i++) {
		if (iRecord.at(i) == ' ')
			countSpacebar++;
	}
	if (countSpacebar == 1)
		posSpacebar2 = iRecordLen;

	for (int i = 0; i < iRecordLen; i++) {
		if (iRecord.at(i) == ' ') {
			if (posSpacebar1 == -1) {
				posSpacebar1 = i;
				if (posSpacebar2 != -1)
					break;
			}
			if (posSpacebar1 != -1)
				posSpacebar2 = i;
		}
	}
	idLen = posSpacebar2 - posSpacebar1 - 1;

	return iRecord.substr(posSpacebar1+1, idLen);
}

string getNickFromRec(string iRecord) {
	int posSpaceBar2 = -1;
	int nickLen;

	int iRecordLen = iRecord.length();
	for (int i = iRecordLen - 1; 0 <= i; i--) {
		if (iRecord.at(i) == ' ') {
			posSpaceBar2 = i;
			break;
		}
	}
	nickLen = iRecordLen - posSpaceBar2 - 1;

	return iRecord.substr(posSpaceBar2+1, nickLen);
}

string getIdFromAns(string iAnswer) {
	int posIdStart;
	int idLen;
	int iAnswerLen = iAnswer.length();
	for (int i = iAnswerLen - 1; 0 <= i; i--) {
		if (iAnswer.at(i) == '.') {
			posIdStart = i + 1;
			idLen = iAnswerLen - posIdStart;
		}
	}
	return iAnswer.substr(posIdStart, idLen);
}

string getNickFromAns(string iAnswer) {
	int posNickEnd;
	int nickLen;
	int iAnswerLen = iAnswer.length();
	for (int i = 0; i < iAnswerLen ; i++) {
		if (iAnswer.at(i) == ' ') {
			posNickEnd = i - 3;
			nickLen = posNickEnd + 1;
		}
	}
	return iAnswer.substr(0, nickLen);
}

vector<string> solution(vector<string> record) {

	vector<string> answer;
	string rId, rNick;
	string aId, aNick;
	int recordSize = record.size();
	for (int r = 0; r < recordSize; r++) {
		//Enter
		if (record[r].compare(0, 5, "Enter") == 0) {
			rId = getIdFromRec(record[r]);
			rNick = getNickFromRec(record[r]);
			//if it's first time to Enter
			if(r == 0){
				answer.push_back(rNick + "님이 들어왔습니다." + rId);
				continue;
			}

			//find "id" in answer
			int answerSize = answer.size();
			for (int a = 0; a < answerSize ; a++) {
				aId = getIdFromAns(answer[a]);
				aNick = getNickFromAns(answer[a]);
				//if find success
				if (rId.compare(aId) == 0
					&& rNick.compare(aNick) != 0) {
					answer[a].replace(0, aNick.length(), rNick);
				}

				//if find fail
				if(a == answerSize -1)
					answer.push_back(rNick + "님이 들어왔습니다." + rId);
			}
		}
		//Leave
		else if (record[r].compare(0, 5, "Leave") == 0) {
			rId = getIdFromRec(record[r]);
			//find "id" in answer
			int answerSize = answer.size();
			for (int a = 0; a < answerSize; a++) {
				aId = getIdFromAns(answer[a]);
				aNick = getNickFromAns(answer[a]);
				if (rId.compare(aId) == 0) {
				answer.push_back(aNick + "님이 나갔습니다." + rId);
				break;
				}
			}
		}
		//Change
		else if (record[r].compare(0, 6, "Change") == 0) {

		}
	}

	return answer;
}

int main() {
	vector<string> record;
	vector<string> answer;
	string str;
	while (true) {
		std::getline(std::cin, str);//cin >> str;
		record.push_back(str);
		answer = solution(record);
		printAnswer(answer);
	}
	return 0;
}



//input
//[Enter uid1234 Muzi, Enter uid4567 Prodo,Leave uid1234,Enter uid1234 Prodo,Change uid4567 Ryan]

//output
//[Prodo님이 들어왔습니다., Ryan님이 들어왔습니다., Prodo님이 나갔습니다., Prodo님이 들어왔습니다.]