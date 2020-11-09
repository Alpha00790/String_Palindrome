#include<bits/stdc++.h>
using namespace std;

string removeSpaces(string line){
	line.erase(remove(line.begin(),line.end(),' '),line.end());
	return line;
}

bool isPalRec(string line,int s,int e)
{
	if(s==e){
		return true;
	}
	if(line[s]!=line[e]){
		return false;
	}
	if(s<e+1)
	return isPalRec(line,s+1,e-1);
	return true;
}
bool isPalindrome(string line)
{
	int n=line.size();
	if(n==0)
		return true;
	return isPalRec(line,0,n-1);
}

int main(){
int t;
cin>>t;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
while(t--){
		string line;
	getline(cin,line);
	line = removeSpaces(line);

	for(int i = 0,len =line.size();i<len;i++){
		if(ispunct(line[i])){
			line.erase(i--,1);
			len = line.size();
		}
	}
	transform(line.begin(),line.end(),line.begin(),::tolower);
	if (isPalindrome(line))
		cout<<"Y"<<" ";
	else
		cout<<"N"<<" ";
}
	
}
