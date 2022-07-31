#include<fstream> 
#include<iostream> 
#include<stdlib.h> 
#include<string.h> 
 
using namespace std; 
 
char * strrev(char *str1) 
{ 
	            int i=0; 
 	int len=strlen(str1);  	
  char *str2=new char[20]; 
	 	while(len>0) 
	 	{ 
	 	str2[i]=str1[--len]; 
	 	i++; 
	 	} 
 	str2[i]='\0';  	
return str2; 
} 
 
main() { 
int choice,i,num_name;
fstream fp,fp1; 
char name[20][20],filename[20],str[10],filename1[20]; for(;;) { 
cout<<"1 : standard input to standard output\n"; cout<<"2 : file to standard output\n"; 
cout<<"3 : file to file\n"; 
cout<<"4 : exit\n"; 
cout<<"enter your choice:\n"; 
cin>>choice; 
switch(choice) 
{ 
	 	case 1:cout<<"enter the number of names to read :\n"; 
	 	 	cin>>num_name; 
	 	 	for(i=1;i<=num_name;i++) 
	 	 	cin>>name[i]; 
cout<<"\nreversed names are :\n";  	                    	                         for(i=1;i<=num_name;i++)  	 	
cout<<strrev(name[i])<<"\n";  	 	
break; 
	 	case 2:cout<<"enter the input file name\n"; 
	 	 	cin>>filename; 
	 	 	fp.open(filename,ios::in); 
	 	 	if(fp.fail()) 
	 	 	{ 
	 	 	cout<<"cannot open the file\n"; 
	 	 	} 
	 	 	else 
	 	 	{ 
	 	 	cout<<"reversed names from the file:\n"; 
	 	 	while(1) 
	 	 	{ 
	 	 	fp>>str; 
	 	 	if(fp.fail()) 
	 	 	break; 
	 	 	cout<<strrev(str)<<endl; 
	 	 	} 
	 	 	fp.close(); 
	 	 	} 
	 	 	break; 
	 	case 3:cout<<"enter the input file name\n"; 
	 	 	cin>>filename; 
 	 		cout<<"enter the output file name\n";  	               			cin>>filename1; 
 	 		fp.open(filename,ios::in);  	 						fp1.open(filename1,ios::out); 
	 	 	if(fp.fail()||fp1.fail()) 
	 	 	{ 
	 	 	cout<<"cannot open the file\n"; 
	 	 	exit(0); 
	 	 	} 
	 	 	while(1) 
	 	 	{ 
	 	 	fp>>str; 
	 	 	if(fp.fail()) 
	 	 	break; 
	 	 	fp1<<strrev(str)<<"\n"; 
	 	 	} 
 	 	fp.close();  	 			fp1.close();  	 			break; 
	 	default:exit(0); 
	 	} 
	 	} 
} 

