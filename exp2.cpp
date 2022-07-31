#include<iostream> 
#include<fstream> 
#include<stdlib.h> 
#include<string.h> 
#include<stdio.h> 
#define SIZE 50 
using namespace std; 
fstream file; 
class fixedlen_student 
{ 
struct student 
{ 
char usn[11],name[15],sem[2],dept[5]; 
}; 
public: void pack(); 
void unpack(); 
void search(); 
void modify(); 
}; 

void fixedlen_student::pack() 
{ 
char buf[SIZE+1]; 
student s; 
cout<<"\nEnter usn,name,sem,dept:"; 
cin>>s.usn>>s.name>>s.sem>>s.dept; 
file.open("student.txt",ios::out|ios::app); 
sprintf(buf,"%s|%s|%s|%s|",s.usn,s.name,s.sem,s.dept); 
int len=strlen(buf); 
while(len<(SIZE)) 
{ 
strcat(buf,"-"); 
len++; 
} 
strcat(buf,"$"); 
file<<buf; 
file.close(); 
} 

void fixedlen_student::unpack() 
{ 
char buf[SIZE+1]; 
student s; 
fstream file; 
file.open("student.txt",ios::in); 
while(!file.eof()) 
{ 
file.getline(buf,100,'$'); 
if(file.eof()) 
break; 
sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]",s.usn,s.name,s.sem,s.dept); 
cout<<s.usn<<" "<<s.name<<" "<<s.sem<<" "<<s.dept<<endl; 
} 
file.close(); 
} 

void fixedlen_student::search() 
{ 
char buf[SIZE+1],usn[11]; 
student s; 
int found=0; 
file.open("student.txt",ios::in); 
cout<<"\nEnter usn to be searched: "; 
cin>>usn; 
while(!file.eof() && found==0) 
{ 
file.getline(buf,100,'$'); 
sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]",s.usn,s.name,s.sem,s.dept); 
if(strcmp(s.usn,usn)==0) 
{ 
found=1; 
cout<<"\nRecord found\n"; 
cout<<s.usn<<" "<<s.name<<" "<<s.sem<<" "<<s.dept<<endl; 
break; 
} 
} 
if(found==0) 
cout<<"Record not found\n"; 
file.close(); 
} 

void fixedlen_student::modify() 
{ 
char buf[SIZE+1],usn[11]; 
student s; 
int n=0,found=0,ch; 
file.open("student.txt",ios::in|ios::out); 
cout<<"\nEnter usn to be modified:"; 
cin>>usn; 
while(!file.eof()) 
{ 
file.getline(buf,100,'$'); 
sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]",s.usn,s.name,s.sem,s.dept); 
if(strcmp(s.usn,usn)==0) 
{ 
found=1; 
cout<<"\nKeyfound\n1:Modifyname\n2:modifysem\n3:MOdifyDept\nEnter your choice:"; 
cin>>ch; 
switch(ch) 
{ 
case 1:cout<<"\nENter name:";cin>>s.name; break; 
case 2:cout<<"\nENter sem:";cin>>s.sem; break; 
case 3:cout<<"\nEnter dept:";cin>>s.dept; break; 
default:break; 
} 
sprintf(buf,"%s|%s|%s|%s|",s.usn,s.name,s.sem,s.dept); 
int len=strlen(buf); 
while(len<(SIZE)) 
{ 
strcat(buf,"-"); 
len++; 
} 
strcat(buf,"$"); 
file.seekp((n*(SIZE+1)),ios::beg); 
file<<buf; 
break; 
} 
n++; 
} 
if(found==0) 
cout<<"Record not found\n"; 
file.close(); 
} 

main() 
{ 
fixedlen_student R; 
int ch; 
for(;;) 
{ 
cout<<"\n1:pack\t2:unpack\t3:search\t4:modify\t5:Exit\nEnteryourchoice:"; 
cin>>ch; 
switch(ch) 
{ 
case 1: R.pack(); 
break; 
case 2: R.unpack(); 
break; 
case 3: R.search(); 
break; 
case 4: R.modify(); 
break; 
default:exit(0); 
} 
} 
}

