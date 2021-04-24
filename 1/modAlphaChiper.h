#pragma once
#include <vector>
#include <string>
#include <map>
 
class modAlphaChiper
{
private:
	
	std::map <char,int> alphaNum;
	std::vector <int> key;
	std::vector <int> convert(const std::wstring& s);
	std::wstring convert(const std::vector<int>& v);
public:
	modAlphaChiper(const std::wstring& skey);
	std::wstring encrypt(const std::wstring& open_text);
	std::wstring decrypt(const std::wstring& cipher_text);
	modAlphaChiper() = delete;
	std::wstring numAlpha = L"ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	
};