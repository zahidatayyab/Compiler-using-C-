#include<iostream>
#include<fstream>
using namespace std;

ifstream fin;

int main(){
	fin.open("input.txt");
	int r=18,c=100;
	char ch[18][100];
	char str[500];
	int ind[10]= {-1},count=0;
	for(int i=0;i<18;i++){
		fin.getline(ch[i],99);
		cout<<ch[i]<<endl;
	}
	fin.close();
	ifstream first,follow,op,ter,xyz;
	xyz.open("....txt");
	bool flag=0;
	for(int i=0;i<r;i++){
		for(int j=1;j<strlen(ch[i]);j++){
			flag=0;
			if(ch[i][j]=='>'||ch[i][j]=='|'){
				j+=2;
				if(ch[i][0]==ch[i][j]){
					for(int k=1;ch[i][k]!=' ';k++){
						j++;
						if(ch[i][k]==ch[i][j])
							flag=1;
						else {
							flag=0;
							j--;
							break;
						}
					}
				}
				if(flag){
					if(ind[count-1]==i)
						cout<<"Left Factoring at line # :"<<i+1<<endl;
					else{
						cout<<"Left Recursion at line # :"<<i+1<<endl;
						ind[count]=i;
											count++;
					}
					
				}
			}
		}
	}
	cout<<endl<<"LL(1) Parsed Gramer (N= NUmber of the production that have not been calculated)"<<endl;


	cout<<endl<<endl;
	count=0;
	for(int i=0;i<r;i++){
		if(i==ind[count]){
			xyz.getline(str,49);
			cout<<str<<endl;
			xyz.getline(str,49);
			cout<<str<<endl;
			count++;
		}
		else
		cout<<ch[i]<<endl;
	}
	cout<<endl<<endl;
	count=-1;
	first.open("first.txt");
	follow.open("follow.txt");
	op.open("operators.txt");
	ter.open("terminals.txt");

	char opt[10]="\0";
	cout<<"        ";
	while(!op.eof()){
		op>>opt;
		cout<<opt<<"    ";
	}
	cout<<endl;
	while(!ter.eof()){
		ter>>opt;
		xyz.getline(str,499);
		cout<<opt<<str<<endl;
	}

	while(!first.eof()){
		first>>opt;

		if(opt=="|"){
			first>>str;
			follow.open("follow.txt");		
			while(!op.eof()){
				op>>opt;
				for(int i=0;i<r;i++){
		for(int j=1;j<strlen(str);j++){
			flag=0;
			if(str[0]==opt[0]){
				j+=2;
				if(str[j]==ch[i][0]){
					for(int k=1;ch[i][k]!=' ';k++){
						j++;
						if(str[k]==opt[j])
							flag=1;
						else {
							flag=0;
							j--;
							break;
							count++;
						}
				}
				if(flag&&count>0)
						cout<<"N"<<i+1<<endl;
				else if(!flag&&count>0){
						cout<<"scan"<<i+1<<endl;
				}
				else
					cout<<"pop";
					
				}
			}
		}
	}
			}
		}

	}


}