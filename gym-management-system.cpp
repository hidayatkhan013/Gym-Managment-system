#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
int main();
void new_person();
void update_record();
void search_record();
int count=0;
int a=0;
string persons[100];
int timings[100];
int fees[100];
int main(){
	int n;
	cout<<setw(70)<<"Welome to Gym Management System \n";
	while(1){
		cout<<"\n   0-exit   1-Add new person     2-Update Record   3-Search for particular person\n ";
		cin>>n;
		if(n==0){
			break;
		}
	switch(n){
		case 1:
			new_person();
			break;
		case 2:
			update_record();
			break;
		case 3:
			search_record();
			break;
		deafult:
			cout<<"Option doesn't exist'\n";
				
		}		
	}
}
void new_person(){
	int s,k;
	cout<<"\n Enter the number of persons you want to add\n";
	cin>>a;
	a=a+count;
	char name[100];
	for(int i=count;i<a;i++){
			ofstream outfile;
			outfile.open("attendance.txt",ios::app);
		cout<<"\n"<<i+1<<":";
		cout<<endl<<"Enter the person's name. End the name with a '.': ";
		cin.getline(name,100,'.');
		persons[i]=name;
		again2:
		cout<<endl<<"Enter timings for the person.(Between 800 to 2000): ";
		cin>>timings[i];
		if(timings[i]<800||timings[i]>2000||timings[i]%100>60){
		cout<<endl<<"Wrong time entered, choose again: ";
		goto again2;
		}
		cout<<endl<<"Enter the fees entered by the person: ";
		cin>>fees[i];
		outfile<<name<<" "<<timings[i]<<" "<<fees[i]<<endl;
		outfile.close();
		count++;
	}
}
void update_record(){
	int s;
	cout<<endl<<"Select the person you want to edit record of.";
	for(int i=0; i<count; i++){
		cout<<endl<<i+1<<" : "<<persons[i];
	}
	cin>>s;
	s++;
	again:
	cout<<endl<<"Enter timings for the person.(Between 800 to 2000): ";
	cin>>timings[s];
	if(timings[s]<800||timings[s]>2000||timings[s]%100>60){
		cout<<endl<<"Wrong time entered, choose again: ";
		goto again;
	}
	cout<<endl<<"Enter the fees entered by the person: ";
	cin>>fees[s];
}
void search_record(){
	char s[100];
	cout<<endl<<"Enter the name of the person, you want to search in the list (end the name with '.'): ";
	cin.getline(s,100,'.');
	int found=0;
	int position=0;
	for(int i=0; i<count; i++){
		if(persons[i]==s){
			found++;
			position=i;
			break;
		}
	}
	if(found==0){
		cout<<endl<<"Sorry person not found in the list.";
	}else{
		cout<<endl<<"Person found: ";
		cout<<endl<<"Name: "<<persons[position];
		cout<<endl<<"Timings: \t"<<timings[position];
		cout<<endl<<"Fee submitted: \t"<<fees[position];
	}
}

	

	

	

