#include <iostream>
#include "String.h"
#include "Window.h"
using namespace std;

int main() {
	setlocale(0, "ukr");
	String sortString;
	ASD::Window wind;
	sortString.setString("71D523CE8"); 
	//cout<<sortString.sortNumbers();
	int num = -1;
	while(num!=0){
		wind.Clear();
		wind.DrawMenu();
		cin >> num;
	switch (num) {
		case 1: {
			string str = "";
			wind.Clear();
			cin >> str;

			sortString.setString(str);
			cout << "\n Все встановлено\n\n\n";
			system("pause");
			break;
		}
		case 2:{
			wind.Clear();
			sortString.sortNumbers();
			cout << "\n\n\n"<<sortString.getString()<< "\n\n\n";
			system("pause");
			break;
		}
		case 0: {
			return 0;
			break;
		}
		}
	}


	return 0;
}