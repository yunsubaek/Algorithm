//stl����
//vector�� ���
#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

// ���� ���� ����
struct RoomUser
{
	int CharCd; // ĳ���� �ڵ�
	int Level; // ����
};

void main()
{
   // ����1
	RoomUser RoomUser1;
	RoomUser1.CharCd = 1;
	RoomUser1.Level = 10;
	// ����2
	RoomUser RoomUser2;
	RoomUser2.CharCd = 2;
	RoomUser2.Level = 5;
	// ����3
	RoomUser RoomUser3;
	RoomUser3.CharCd = 3;
	RoomUser3.Level = 12;
	// ���� �������� ������ vector
	vector< RoomUser > RoomUsers;
	// �߰�
	RoomUsers.push_back(RoomUser1);
	RoomUsers.push_back(RoomUser2);
	RoomUsers.push_back(RoomUser3);
	// �濡 �ִ� ���� ��
	int UserCount = RoomUsers.size();
	// �濡 �ִ� ���� ���� ���
	// ������ ����
	for (auto IterPos = RoomUsers.begin(); IterPos != RoomUsers.end(); IterPos++) {
		cout << "�����ڵ� : " << IterPos->CharCd << endl;
		cout << "�������� : " << IterPos->Level << endl;
	}
	cout << endl;
	// ������ ����
	for (auto IterPos = RoomUsers.rbegin(); IterPos != RoomUsers.rend(); IterPos++) {
		cout << "�����ڵ� : " << IterPos->CharCd << endl;
		cout << "�������� : " << IterPos->Level << endl;
	}
	cout << endl;
	// �迭 ������� ����
	for (int i = 0; i < UserCount; ++i)
	{
		cout << "���� �ڵ� : " << RoomUsers[i].CharCd << endl;
		cout << "���� ���� : " << RoomUsers[i].Level << endl;
	}
	cout << endl;
	// ù ��° ���� ������ ����
	RoomUser& FirstRoomUser = RoomUsers.front();
	cout << "ù ��° ������ ���� : " << FirstRoomUser.Level << endl << endl;
	RoomUser& LastRoomUser = RoomUsers.back();
	cout << "������ ��° ������ ����: " << LastRoomUser.Level << endl << endl;
	// at�� ����Ͽ� �� ��° ������ ������ ���
	RoomUser& RoomUserAt = RoomUsers.at(1);
	cout << "�� ��° ������ ����: " << RoomUserAt.Level << endl << endl;
	// ����
	RoomUsers.pop_back();
	UserCount = RoomUsers.size();
	cout << "���� �濡 �ִ� ���� ��: " << UserCount << endl << endl;
	// ���� �濡 ������ �ִٸ� ��� �����Ѵ�.
	if (false == RoomUsers.empty())
	{
		RoomUsers.clear();
	}
	UserCount = RoomUsers.size();
	cout << "���� �濡 �ִ� ���� ��: " << UserCount << endl;
}