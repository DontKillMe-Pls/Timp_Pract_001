#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "chipping.h"
using namespace std;

int main()
{
	int mode, inputKey;
	std::locale::global( std::locale("") );
	wcout << L"Введите количество столбцов: ";
	wcin >> inputKey;
	wcin.ignore(32767,'\n');
	wcout << L"0-шифрует\n1-расшифровываем\nВыберете режим: ";
	Chiper chiper(inputKey);
	if(!(wcin >> mode)){
			wcout << L"Выбран неверный режим" << endl;
			return 1;
	}
	if(mode == 0){
	chiper.chipping();
	wcout << chiper.getChiperedMessage() << endl;
	}else if (mode == 1){
	chiper.deChipping();
	wcout << chiper.getMessage() << endl;
	}else{
		wcout << L"Выбран неверный режим" << endl;
	}
	return 0;
}