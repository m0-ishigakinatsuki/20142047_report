#include <string>
#include <iostream>
#include <vector>
#include <regex>
using namespace std;


class info {
private:
	string  Eto, Conste;
public:
	void setEto(const string& newEto) { Eto = newEto; }
	string getEto() { return Eto; }
	void setConste(const string& newConste) { Conste = newConste; }
	string getConste() { return Conste; }
};


void check( string bd ) {

	regex rx(R"(\d{4}\/\d{2}\/\d{2})");

	while (!regex_match(bd,rx)){ 


		if (regex_match(bd,rx)){ 
			//OK
		}
		else {
			cout << "(��)�ɕ���ē��͂��Ă������� \n\n";
			cin >> bd;
		}
	}


	string year = bd.substr(0, 4); //�ł����܂ꂽ�����񂩂�N��؂�o��
	string month = bd.substr(5, 2); //�ł����܂ꂽ�����񂩂猎��؂�o��
	string day = bd.substr(8, 2); //�ł����܂ꂽ�����񂩂����؂�o��
		
	int year1 = stoi(year);
	int month1 = stoi(month);
	int day1 = stoi(day);
	
	vector<int> vy{ 0,1,2,3,4,5,6,7,8,9,10,11 };

	int targetani = year1 % 12; 

	const int posye = *(find(vy.cbegin(), vy.cend(), targetani));//�]��ɂ��ďꍇ�������Ċi�[���Ă��������̂���T��


	vector<string> Etos = {
		"�єN", "���N", "��N", "�q�N", "�N�N", "�ДN", "�K�N", "�C�N", "���N", "�ߔN", "���N", "�\�N" //���x
	};

	vector<string> Stars = {
		"�ˎ��", "�R�r��", "���r��", "����", "���r��", "������", "�o�q��", "�I��", "���q��", "������", "�V����", "嶍�", "�ˎ��", "�R�r��" //����
	};
	
	//�����̋��E�ƂȂ�C���̌��Ɠ��������������̓��ɂ��i12���C1���C2���C�E�E�E�C12���j
	vector<int> fDays = { 22, 20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22 }; 

	//�e���̍ŏI���i12���C1���C2���C�E�E�E�C12���j
	vector<int> lDays = { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//�����̋��E�ƂȂ�C�O�̌��Ɠ��������������̓��ɂ��i12���C1���C2���C�E�E�E�C12���j
	vector<int> eDays;
	for (int g = 0; g < fDays.size(); ++g) {
		eDays.push_back(fDays[g] - 1);
	}


	string Star;

	//�e���̓��ɂ��ɂ��ꍇ����
	if (int i = month1) {
		if (day1 < fDays[i]) {
			Star = Stars[i];
		}
		else if (day1 <= lDays[i]) {
			Star = Stars[i + 1];
		}
	}

	info rmation;
	rmation.setEto(Etos[posye - 1]);
	rmation.setConste(Star);

	cout << "���Ȃ��̊��x��" << rmation.getEto() << "�C" << "������" << rmation.getConste() << "�ł��D\n";


	cout << "\n\n" << "<�Q�l>" << "\n";



	//�����̏���1������12���̏��ɂ��d���̂��镔�����폜
	Stars.erase(Stars.begin());
	Stars.pop_back();
	

	vector <int> vm{ 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	
	int e = 0;
	for (auto it = Stars.begin(); it != Stars.end(); ++it) {		
		cout << *it << ":" << vm[e] << "/" << fDays[e] << "�`" << vm[e + 1] << "/" << eDays[e + 1] << endl;
		e++;		
	};
}

int main() {
	string mybd;
	cout << "���N�����𐼗�œ��͂��CEnter�������Ă��������D\n �i��j2000/01/01�@\n\n";

	cin >> mybd;

	check(mybd);
}