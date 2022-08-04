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
			cout << "(例)に倣って入力してください \n\n";
			cin >> bd;
		}
	}


	string year = bd.substr(0, 4); //打ち込まれた文字列から年を切り出す
	string month = bd.substr(5, 2); //打ち込まれた文字列から月を切り出す
	string day = bd.substr(8, 2); //打ち込まれた文字列から日を切り出す
		
	int year1 = stoi(year);
	int month1 = stoi(month);
	int day1 = stoi(day);
	
	vector<int> vy{ 0,1,2,3,4,5,6,7,8,9,10,11 };

	int targetani = year1 % 12; 

	const int posye = *(find(vy.cbegin(), vy.cend(), targetani));//余りについて場合分けして格納しておいたものから探索


	vector<string> Etos = {
		"酉年", "戌年", "亥年", "子年", "丑年", "寅年", "卯年", "辰年", "巳年", "午年", "未年", "申年" //干支
	};

	vector<string> Stars = {
		"射手座", "山羊座", "水瓶座", "魚座", "牡羊座", "牡牛座", "双子座", "蟹座", "獅子座", "乙女座", "天秤座", "蠍座", "射手座", "山羊座" //星座
	};
	
	//星座の境界となり，次の月と同じ星座を持つ方の日にち（12月，1月，2月，・・・，12月）
	vector<int> fDays = { 22, 20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22 }; 

	//各月の最終日（12月，1月，2月，・・・，12月）
	vector<int> lDays = { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//星座の境界となり，前の月と同じ星座を持つ方の日にち（12月，1月，2月，・・・，12月）
	vector<int> eDays;
	for (int g = 0; g < fDays.size(); ++g) {
		eDays.push_back(fDays[g] - 1);
	}


	string Star;

	//各月の日にちによる場合分け
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

	cout << "あなたの干支は" << rmation.getEto() << "，" << "星座は" << rmation.getConste() << "です．\n";


	cout << "\n\n" << "<参考>" << "\n";



	//星座の情報を1月から12月の順にし重複のある部分を削除
	Stars.erase(Stars.begin());
	Stars.pop_back();
	

	vector <int> vm{ 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	
	int e = 0;
	for (auto it = Stars.begin(); it != Stars.end(); ++it) {		
		cout << *it << ":" << vm[e] << "/" << fDays[e] << "～" << vm[e + 1] << "/" << eDays[e + 1] << endl;
		e++;		
	};
}

int main() {
	string mybd;
	cout << "生年月日を西暦で入力し，Enterを押してください．\n （例）2000/01/01　\n\n";

	cin >> mybd;

	check(mybd);
}