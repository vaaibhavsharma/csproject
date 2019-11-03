/*

Project For CS project Class 12th Computer Science

Completly designed and Coded By Vaibhav Sharma and Vibhu Dawar

It is completly anonymous Platform where citizens can report crime without fear of being tracked by Someone......

*/
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>

// INTRO -----------------------------------------------------------------------------
void display_intro(char n[]="Citizen")
{
    
cout<<"******************************"<<endl;
cout<<"CrowdSourcing (BETA v1.1) PROTOTYPE"<<endl;
cout<<"******************************"<<endl;
cout<<endl;
cout<<"                               WELCOME! "<<n<<endl;
}
// INTRO CLOSED ----------------------------------------------------------------------


//This Class defines Citizen Parameters mainly responsile for all signin and login Functions
class citizen
{
	 char citizenID[20];
	char password[20];
    char name[20];
    char role[20];
    public:
     void citizen_signup()
	{
		cout<<"Please Enter Your CitizenID:  ";
		cin>>citizenID;
	    cout<<"\nPlease Enter Your Name:  ";
	    gets(name);
		cout<<"\nPlease Enter Password:  ";
		gets(password);
	    cout<<endl;
	strcpy(role, "citizen");
	}
    void citizen_modify(){
	  cout<<"\nPlease Enter New Name:  ";
	    gets(name);
		cout<<"\nPlease Enter New Password:  ";
		gets(password);
	    cout<<endl;
    }
    
char* retcitizenname(){
    return name;
}
    char* retrole(){
	return role;
    }

char* retcitizenpass(){
	return password;
    }
    char* retcitizenID(){
	return citizenID;
    }

};
citizen c,d,e,s;
// MAIN CLASS ENDS HERE
class crimereportanno
{
    char crimetype[20];
    char location[20];

    public:

    void report(){
       clrscr();
	   display_intro(c.retcitizenname());
	cout<<"-------Reporting Annonimously \n"<<endl;
	cout<<"\n Crime You want to Report:  ";
	gets(crimetype);
	cout<<"\n Location:  ";
	gets(location);
    }
       void see_report(){
       
	cout<<"\n Reported Crime:  ";
	puts(crimetype);
	cout<<"   Location:  ";
	puts(location);
           cout<<"\n ---------------------------------------------------";
    }
};
/* Global Things */
fstream fs;
ifstream fi;
crimereportanno crime;

void modify_citizen()
{
	clrscr();
    display_intro(c.retcitizenname());
    cout<<"-------Change Username And Password \n"<<endl;
	fs.open("citizens.dat",ios::in|ios::out|ios::binary);
	while(fs.read((char*)&e,sizeof(citizen)))
	{
		if(strcmpi(e.retcitizenID(),c.retcitizenID())==0)
		{
	    c.citizen_modify();
			int pos=-1*sizeof(c);
			fs.seekp(pos,ios::cur);
			fs.write((char*)&c,sizeof(citizen));
			cout<<"\n \t Record Updated";
            break;
		}
	}

	fs.close();
	getch();
}


void report_anno(){
    crime.report();
    fs.open("crimereport.dat",ios::out|ios::app|ios::binary);


		fs.write((char*)&crime,sizeof(crimereportanno));

	fs.close();
    cout<<"\n Crime Reported Succesfully! Redirecting To Main Menu!";
    delay(1000);
    return;
}
void see_anno(){
    clrscr();
	   display_intro(c.retcitizenname());
	cout<<"-------Reports \n"<<endl;
    fs.open("crimereport.dat",ios::in|ios::binary);
    while(fs.read((char*)&crime,sizeof(crime)))
	{
		crime.see_report();
	}

	fs.close();
    
    getch();
    return;
}

// Citizen MENU
void display_citizen_main(){
	clrscr();
	display_intro(c.retcitizenname());
	int citizen_selection;


	cout<<"\n ---------------------------------------";
	cout<<"\n  Enter 1 to send Crime Report ";
	cout<<"\n ---------------------------------------";
	cout<<endl;
	cout<<" ---------------------------------------";
	cout<<"\n  Enter 2 To change Name and password  ";
	cout<<"\n ---------------------------------------";
    cout<<"\n ---------------------------------------";
	cout<<"\n  Enter 3 to exit ";
	cout<<"\n ---------------------------------------";
	cout<<"\n \n YOUR SELECTION:  ";
	cin>>citizen_selection;
    switch(citizen_selection)
	{
		case 1:
			report_anno(); break;
	    case 2:
	    modify_citizen(); break;
	case 3:
	    return;
		default:cout<<"\a";
	}
    display_citizen_main();
}
void display_police_main(){
	clrscr();
	display_intro(c.retcitizenname());
	int citizen_selection;


	cout<<"\n ---------------------------------------";
	cout<<"\n  Enter 1 to see Crime Reports ";
	cout<<"\n ---------------------------------------";
	cout<<endl;
	cout<<" ---------------------------------------";
	cout<<"\n  Enter 2 To change Name and password  ";
	cout<<"\n ---------------------------------------";
    cout<<"\n ---------------------------------------";
	cout<<"\n  Enter 3 to exit ";
	cout<<"\n ---------------------------------------";
	cout<<"\n \n YOUR SELECTION:  ";
	cin>>citizen_selection;
    switch(citizen_selection)
	{
		case 1:
			see_anno(); break;
	    case 2:
	    modify_citizen(); break;
	case 3:
	    return;
		default:cout<<"\a";
	}
    display_police_main();
}

// FUNCTION FOR LOGIN ACTION
void login_citizen(){

	int flag=0;

     char citizeninputid[20];
	char citizeninputpass[20];
	cout<<"Enter Citizen ID:  ";
	cin>>citizeninputid;
	cout<<"\nEnter your password:  ";
	gets(citizeninputpass);

	fs.open("citizens.dat",ios::in);
	while(fs.read((char*)&c,sizeof(citizen)) && flag==0)
	{
		if((strcmpi(c.retcitizenID(),citizeninputid)==0))
		{
		      if((strcmpi(c.retcitizenpass(),citizeninputpass)==0)){
		flag = 1;
                  break;
	    }

		}
	}

	fs.close();
	if(flag==0){
		cout<<"\n\nINVALID";
	delay(1000);
    return;
    }
    else{
	 cout<<"Logging you In....";
    delay(1000);
	if(strcmpi(c.retrole(), "citizen")==0){
            display_citizen_main();
        }
        else
            display_police_main();
    
    }
}


//FUNCTION TO WRITE IN DATABASE (BINARYFILE)

void write_citizen()
{
    s.citizen_signup();
	int flag=0;
	char n[10];
	strcpy(n, s.retcitizenID());
	fs.open("citizens.dat",ios::in);
	while(fs.read((char*)&e,sizeof(citizen)))
	{
		if((strcmpi(e.retcitizenID(),n)==0))
		{
			flag=1;
		}
	}

	fs.close();

if(flag==0){

	fs.open("citizens.dat",ios::out|ios::app|ios::binary);


		fs.write((char*)&s,sizeof(citizen));

	fs.close();
	  cout<<"Account Created! You May Login Now!";
	  cout<<"\n3.";
	  delay(1000);
	  cout<<".2.";
	  delay(1000);
	  cout<<"..1";
    login_citizen();
    }
    else{
	cout<<"\n   ******************************* ";
	cout<<"\n      CITIZEN ID ALREADY IN USE";
	cout<<"\n   ******************************* ";
        cout<<"\t \t Redirecting To Home!";
	delay(2000);  return;
       }

	}



void main(){

    char ch=0;

    do {
        clrscr();
display_intro();
	cout<<"New User (y/n)?";
	ch = getche();
	switch(ch){
	    case 'y': clrscr();
		    display_intro();
		    cout<<"-------Sign Up \n"<<endl;
		    write_citizen();
			break;
	    case 'n': clrscr();
			display_intro();
			cout<<"-------Login \n"<<endl;
			    login_citizen();
                break;
        case 'e': exit(0);
	}
}while(ch!='e');

getch();
}
