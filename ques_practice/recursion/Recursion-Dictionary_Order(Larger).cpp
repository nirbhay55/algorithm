#include <iostream>
using namespace std;

void larger(string str, string mod_str, string ans){

	if (mod_str.length()==0){
		if (ans>str){
			cout<<ans<<endl;
		}
		return;
	}

	for (int i = 0; i < mod_str.length(); ++i){
		char ch = mod_str[i];
		string ros = mod_str.substr(0,i) + mod_str.substr(i+1);
		larger(str,ros,ans+ch);
	}
	return;
}	

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;

	larger(str,str,"");

	return 0;
}