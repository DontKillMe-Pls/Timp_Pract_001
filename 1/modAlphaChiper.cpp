#include "modAlphaChiper.h"
#include <vector>
#include <string>
#include <map>

modAlphaChiper::modAlphaChiper(const std::wstring& skey)
{
	for (unsigned i=0; i<numAlpha.size();i++){
		alphaNum[numAlpha[i]]=i;
	}
	key = convert(skey);
}
std::wstring modAlphaChiper::encrypt(const std::wstring& open_text)
{
	std::vector<int> work = convert(open_text);
	for(unsigned i=0; i< work.size();i++){
		work[i] = (work[i] + key[i%key.size()])% alphaNum.size();
	}
	return convert(work);
}
std::wstring modAlphaChiper::decrypt(const std::wstring& cipher_text)
{
	std::vector<int> work = convert(cipher_text);
	for(unsigned i=0;i<work.size();i++){
		work[i] = (work[i]+alphaNum.size()- key[i%key.size()]) % alphaNum.size();
	}
	return convert(work);
}
inline std::vector<int> modAlphaChiper::convert(const std::wstring& s)
{
	std::vector<int> result;
	for(auto c:s){
		result.push_back(alphaNum[c]);
	}
	return result;
}
inline std::wstring modAlphaChiper::convert(const std::vector<int>& v)
{
	std::wstring result;
	for(auto i:v){
		result.push_back(numAlpha[i]);
	}
	return result;
}
