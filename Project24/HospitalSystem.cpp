#include <stdio.h>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <string.h>
#include <time.h>
#include<windows.h>
 COORD coord = {0,0};
	void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
using namespace std;

class Person
{
	protected:
    char Name[50],Gender[10];
    int Age,Date,Month,Year;
    long int PhoneNum;
    int ZipCode,PersonID;
    char City[50],Country[50],State[50],blood_g[5];
public:
	Person(){
		
	}
    virtual void Info()//over riding
    {
        cout<<"Enter Name :";
        cin.clear();
        cin.ignore();
        cin.getline(Name,50);
        cout<<"Enter Gender :";
        cin>>Gender;
        cout<<"Enter Age :";
        cin>>Age;
        cout<<"Enter Address :";
        cin>>Country;
        cout<<"Enter Blood group:";
        cin>>blood_g;
    }

    void Display_info()
    {
        cout<<"Name: "<<Name<<endl;
        cout<<"Gender: "<<Gender<<endl;
        cout<<"Age: "<<Age<<endl;
        cout<<"Address: "<<this->Country<<endl;
        cout<<"Blood Group:"<<blood_g<<endl;
    }
};

class Staff:public Person
           {
           int salary;
           char time_from[30],time_to[30];

    public:
		Staff(){
		}
          virtual void Info()//overiding
          {
              cout<<"Enter Name :";
		        cin.clear();
		        cin.ignore();
		        cin.getline(Name,50);
		        cout<<"Enter Gender :";
		        cin>>Gender;
		        cout<<"Enter Age :";
		        cin>>Age;
		        cout<<"Enter Address :";
		        cin>>Country;
		        cout<<"Enter Blood group:";
		        cin>>blood_g;
    
              cout<<"Enter salary:";cin>>salary;
              cout<<"Enter Duty time:"; cout<<"From:";cin>>time_from;cout<<"To:";cin>>time_to;
          }

           void show_staff()
           {
                cout<<"\nSalary: "<<salary;
                cout<<"\nDuty Time:(24 hour format) "<<time_from<<"-"<<time_to<<endl;
                Display_info();
           }
};


class patient: public Person
{
	protected:
int reg_no;
char occupation[30];
char date_admit[30];
char date_discharge[30];
int bill,total;

public:
	patient(){
	}
    	char medicine[100];
		void patient_bill();
		void getdata(); 
		void showdata(); 
		int retidno();
		void modify_medicine(int n);
  		void write_patient(); 
	    void display_all(); //read all records of patients from file
   		void display_p(int n); //accept reg_no and check reg_no and read record from file
    	void modify_patient(int n); //accept reg_no and update record of file
    	void delete_patient(int n); //accept reg_no and delete selected records from file
};


void patient::patient_bill()  
{
    system("CLS");
	cout << "---------------------------------------------------------------------------------";
	cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
	cout << "====================================================================================";
	cout << "\nHospital Care Charges                      :\t  50";
	cout << "\nHospital Maintaince Charges                :\t  50";
	cout << "\nPatient Individual  Charges                :\t " << bill;
	total = 50 + 50 + bill;
	cout << "\nTotal Fee Charge                           :\t"  << total<<"\n";
	cout << "------------------------------------------------------------------------------------------";
}

void patient::getdata()
{
	Info();
	cout<<"\nEnter The registration number of the patient: ";
	cin>>reg_no;
	cout<<"\nEnter The occupation of the patient: ";
	cin>>occupation;
	cout<<"\nEnter The bill of the patient:";
	cin>>bill;
	cout<<"\nEnter The date admitted(dd/mm/yyyy):";
	cin>>date_admit;
	cout<<"\nEnter The date discharged(dd/mm/yyyy):";
	cin>>date_discharge;
	patient_bill();
	strncpy(medicine, "null", sizeof(medicine) - 1);
	medicine[sizeof(medicine) - 1] = 0;
}

void patient::showdata()
{
	cout<<"\nRegistration number of patient: "<<reg_no<<"\n";
	Display_info();
	cout<<"\nOccupation : "<<occupation;
	cout<<"\nAdmit date : "<<date_admit;
	cout<<"\nDischarhge date :"<<date_discharge;
	cout<<"\nBill :"<<total;
	cout<<"\nPrescribed Medicine: "<<medicine;

}

int  patient::retidno()
{
	return reg_no;
}

void patient::modify_medicine(int n)
{
	bool found=false;
	patient p;
	fstream File;
	File.open("patient.dat",ios::binary|ios::in|ios::out);
	if(!File)
		{
			cout<<"File could not be open !! Press any Key...";
			cin.ignore();
			cin.get();
			return;
}
	    while(!File.eof() && found==false)
			{	
				File.read(reinterpret_cast<char *> (&p), sizeof(patient));
				if(p.retidno()==n){
				cout<<"\n\nPlease Enter the Medicine of patient"<<endl;
				cin>>p.medicine;
				p.showdata();
				int pos=(-1)*static_cast<int> (sizeof(p));
				File.seekp(pos,ios::cur);
				File.write(reinterpret_cast<char *>(&p),sizeof(patient));
				cout<<"\n\n\tRecord updated!";	
}

	File.close();
		if(found==false)
			cout<<"\n\n Record Not Found ";

		cin.ignore();
		cin.get();
}

}
void patient::write_patient()  
{
		patient p;
		ofstream outFile;
		outFile.open("patient.dat",ios::binary|ios::app);
		p.getdata();
		outFile.write(reinterpret_cast<char *> (&p), sizeof(patient));
		outFile.close();
    	cout<<"\n\nPatient record Has Been Created ";
		cin.ignore();
		cin.get();
}

void patient::display_all()  
{
	patient p;
	ifstream inFile;
	inFile.open("patient.dat",ios::binary);
	if(!inFile)
		{
			cout<<"File could not be open !! Press any Key...";
			cin.ignore();
			cin.get();
			return;
}
		cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
			while(inFile.read(reinterpret_cast<char *> (&p), sizeof(patient))){
				p.showdata();
				cout<<"\n\n=======================================================================================\n";
}
inFile.close();
cin.ignore();
cin.get();
}

void patient::display_p(int n) 
{
		patient p;
		ifstream inFile;
		inFile.open("patient.dat",ios::binary);
		if(!inFile)
		{
			cout<<"File could not be open !! Press any Key...";
			cin.ignore();
			cin.get();
			return;
}
bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&p), sizeof(patient)))
	{
		if(p.retidno()==n)
			{
 				p.showdata();
				flag=true;
	}
}
inFile.close();
if(flag==false)
	cout<<"\n\nrecord not exist";
cin.ignore();
cin.get();
}


void patient:: modify_patient(int n)   
{
	bool found=false;
	patient p;
	fstream File;
	File.open("patient.dat",ios::binary|ios::in|ios::out);
	if(!File)
		{
			cout<<"File could not be open !! Press any Key...";
			cin.ignore();
			cin.get();
			return;
}
    while(!File.eof() && found==false)
		{
			File.read(reinterpret_cast<char *> (&p), sizeof(patient));
			if(p.retidno()==n)
				{
					p.showdata();
					cout<<"\n\nPlease Enter The New Details of patient"<<endl;
                	p.getdata();
    				int pos=(-1)*static_cast<int>(sizeof(p));
    				File.seekp(pos,ios::cur);
    				File.write(reinterpret_cast<char *> (&p), sizeof(patient));
    				cout<<"\n\n\t Record Updated";
    				found=true;
}
}
File.close();

	if(found==false)
	cout<<"\n\n Record Not Found ";

cin.ignore();
cin.get();
}


void patient:: delete_patient(int n) 
{
	patient p;
	ifstream inFile;
	inFile.open("patient.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
}
		ofstream outFile;
		outFile.open("Temp.dat",ios::out);
		inFile.seekg(0,ios::beg);
		while(inFile.read(reinterpret_cast<char *> (&p), sizeof(patient)))
{
		if(p.retidno()!=n)
{
		outFile.write(reinterpret_cast<char *> (&p), sizeof(patient));
}
}
outFile.close();
inFile.close();
		remove("patient.dat");
		rename("Temp.dat","patient.dat");
		cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}


class Doctor: public Staff
{
    int DocID;
    patient p;
    char Spz[500];

	public:
   	  bool CheckRegNo(int n)
      {
		bool found=false;
		Doctor d;
		fstream File;
		File.open("Doctor.dat",ios::binary|ios::in);
	 if(!File)
		 {
			cout<<"File can not be open ! Press any Key...";
cin.ignore();
cin.get();
	}
    	while(!File.eof() && found==false)
       		 {
				File.read(reinterpret_cast<char *> (&d), sizeof(Doctor));
				if(d.DocID==n)
					{
    					found=true;
}
        }
        	File.close();
        	return found;
        	cin.ignore();
        	cin.get();
      }


    void DoctorInfo()
    {
        Info();
        id:
        cout<<"Enter Doctor ID(1200-1299):";
        int m;
        cin>>m;
        if(CheckRegNo(m)==false)
        {
            DocID=m;
        }
        else
        {
            cout<<"ID already taken\n";
            goto id;
        }

        cout<<"Enter Doctor Specialize :";
        cin>>Spz;
        system("pause");
    }

    void show_doctor()
    {
        cout<<"Doctor ID: "<<DocID;
        show_staff();
        cout<<"\nDoctor Specialize: "<<Spz;
    }

    int  retDid()
   	{
		return DocID;
}

    void Prescribe_Medicine()
    {
        int n;
        cout<<"\n\n\tEnter Reg Number Of patient : "; cin>>n;
        p.modify_medicine(n);
    }


    void write_doctor()
   {
		Doctor d;
		ofstream outFile;
		outFile.open("Doctor.dat",ios::binary|ios::app);
		d.DoctorInfo();
		outFile.write(reinterpret_cast<char *> (&d), sizeof(Doctor));
	    cout<<"\n\nDoctor record Has Been Created ";
		outFile.close();
		cin.ignore();
}

   void show_doctor(int n)
		{
			Doctor d;
			ifstream inFile;
			inFile.open("Doctor.dat",ios::binary);
			if(!inFile)
				{
					cout<<"File could not be open !! Press any Key...";
					cin.ignore();
					cin.get();
					return;
}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Doctor)))
		{
			d.show_doctor();
			cout<<"\n\n=======================================================================================\n";
}
	inFile.close();
	cin.ignore();
	cin.get();
}


void display_d(int n)
	{
		Doctor d;
		ifstream inFile;
		inFile.open("Doctor.dat",ios::binary);
		if(!inFile)
		{
			cout<<"File could not be open !! Press any Key...";
			cin.ignore();
			cin.get();
			return;
}
		bool flag=false;
		while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Doctor)))
			{
				if(d.DocID==n)
					{
						d.show_doctor();
						flag=true;
				}
}
inFile.close();
if(flag==false)
	cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

void modify_doctor(int n)
{
	bool found=false;
	Doctor d;
	fstream File;
	File.open("Doctor.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
	cout<<"File could not be open !! Press any Key...";
	cin.ignore();
	cin.get();
	return;
}
	    while(!File.eof() && found==false)
			{
				File.read(reinterpret_cast<char *> (&d), sizeof(Doctor));
				if(d.DocID==n)
					{
   						d.show_doctor();
   						cout<<"\n\nPlease Enter The New Details:"<<endl;
                		d.DoctorInfo();
    					int pos=(-1)*static_cast<int>(sizeof(d));
    					File.seekp(pos,ios::cur);
    					File.write(reinterpret_cast<char *> (&d), sizeof(Doctor));
    					cout<<"\n\n\t Record Updated";
    					found=true;
}
}
File.close();

if(found==false)
	cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}


void Doctor_choice()
{
    char ch;
    do
	{
		int n;
		system("cls");
	    cout<<"\n\n\t01. Prescribe Medicine for patient ";
		cout<<"\n\n\t02. Search DOCTOR ";
		cout<<"\n\n\t03. To exit.....";
        cout<<"\n\n\tPlease Select Your Option (1-3) ";
        cin>>ch;
switch(ch)
{
	case '1': 
		system("cls");
		Prescribe_Medicine();
     	break;
		case '2':
		system("cls");
        cout<<"Enter Doctor ID :";cin>>n;
        display_d(n);
		break;
        case '3':
		system("cls");
		break;
      	default :cout<<"\b";
}
    }while(ch!='3');

}

   void Doctor_menu()
	{
	    char ch;
		do
		{
			int n;
			system("cls");
			gotoxy(30,11);
			cout<<"01. INSERT DOCTOR DATA";
			gotoxy(30,13);
			cout<<"02. Search DOCTOR ";
			gotoxy(30,15);
			cout<<"03. ALL DOCTOR ";
			gotoxy(30,17);
			cout<<"04. MODIFY DOCTOR DATA";
			gotoxy(30,19);
			cout<<"05. TO EXIT............";
			gotoxy(30,21);
			cout<<"Please Select Your Option (1-5) ";
			gotoxy(30,23);
			cout<<"choice->";
			cin>>ch;
        	system("cls");
			switch(ch)
				{
					case '1':
					write_doctor();
    				break;
					case '2':
         			cout<<"Enter Doctor ID :";cin>>n;
                    display_d(n);
                    break;
					case '3':
        			show_doctor(1);
    				break;
					case '4':
        			cout<<"Enter Doctor ID :";cin>>n;
        			modify_doctor(n);
        			break;
}
    }while(ch!='5');

}

};

class Nurse: public Staff
{
    int NurseID;
    char ChargeRoom [50];
    patient p;
public:
       void GetNurseInfo()
	    {
	    	system("cls");
       		cout<<"--------------------------------"<<endl;
       		Info();
      		cout<<"Enter Nurse ID:";
      		cin>>NurseID;
       		cout<<"Enter Nurse Duty Room :";
       		cin>>ChargeRoom;
    }
    void Display_NurseInfo()
    {
        cout<<"--------------------------------"<<endl;
        cout<<"Nurse ID :"<<NurseID;
        show_staff();
        cout<<"\n"<<"Nurse in charge Room :"<<ChargeRoom;
        cout<<endl;
}
    void Write_NurseInfo()
		{
			Nurse n;
			ofstream outFile;
			outFile.open("NurseInfo.dat",ios::binary|ios::app);
			n.GetNurseInfo();
			outFile.write(reinterpret_cast<char *> (&n), sizeof(Nurse));
			outFile.close();
    		cout<<"\n\nrecord Has Been Created ";
			cin.ignore();
			cin.get();
}
    void display_n(int m)
	{
		Nurse n;
		ifstream inFile;
		inFile.open("NurseInfo.dat",ios::binary);
		if(!inFile)
		{
			cout<<"File could not be open !! Press any Key...";
			cin.ignore();
			cin.get();
			return;
}
		bool flag=false;
		while(inFile.read(reinterpret_cast<char *> (&n), sizeof(Nurse)))
		{
			if(n.NurseID==m)
				{
					n.Display_NurseInfo();
					flag=true;
	}
}
inFile.close();
if(flag==false)
	cout<<"\n\nrecord does not exist";
	cin.ignore();
	cin.get();
}

  void modify_Nurse(int m)
{
	bool found=false;
	Nurse n;
	fstream File;
	File.open("NurseInfo.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
}
    while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&n), sizeof(Nurse));
		if(n.NurseID==m)
		{
			n.Display_NurseInfo();
			cout<<"\n\nPlease Enter The New Details of nurse"<<endl;
            n.GetNurseInfo();
    		int pos=(-1)*static_cast<int>(sizeof(n));
    		File.seekp(pos,ios::cur);
    		File.write(reinterpret_cast<char *> (&n), sizeof(Nurse));
    		cout<<"\n\n\t Record Updated";
    		found=true;
}
}
File.close();
if(found==false)
	cout<<"\n\n Record does Not Found ";
	cin.ignore();
	cin.get();
}

void display_all_Nurse()
{
	Nurse n;
	ifstream inFile;
	inFile.open("NurseInfo.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
}
cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
		while(inFile.read(reinterpret_cast<char *> (&n), sizeof(Nurse)))
		{
			n.Display_NurseInfo();
			cout<<"\n\n=======================================================================================\n";
}
inFile.close();
cin.ignore();
cin.get();
}

void Nurse_menu()
{
    char ch;
	do
	{
		int n;
		system("cls");
		gotoxy(30,9);
		cout<<"01. INSERT NURSE DATA";
		gotoxy(30,11);
		cout<<"02. Search NURSE ";
		gotoxy(30,13);
		cout<<"03. ALL NURSE ";
		gotoxy(30,15);
		cout<<"04. MODIFY NURSE DATA";
		gotoxy(30,17);
		cout<<"05. To EXIT..........";
		gotoxy(30,19);
		cout<<"Please Select Your Option (1-5) ";
		gotoxy(30,21);
		cout<<"choice->";
		cin>>ch;
		switch(ch)
		{
		case '1':
		Write_NurseInfo();
    	break;
		case '2':
        cout<<"Enter NURSE ID :";cin>>n;
        display_n(n);
        break;
		case '3':
        display_all_Nurse();
   		break;
		case '4':
        cout<<"Enter Nurse ID :";cin>>n;
        modify_Nurse(n);
        break;
}
    }while(ch!='5');

}

};


class Receptionist:public Staff
{
    patient p;
    int RecID;

public:
	Receptionist(){
	}
  void RecInfo()
    {
        Info();
        cout<<"Enter Receptionist ID :";
        cin>>RecID;
}

    void show_receptionist()
    {
        show_staff();
        cout<<"Receptionist ID: "<<RecID;
}

void entry_Patient()
{
	char ch;
	int num;
	do{
		system("cls");
		cout<<"\n\n\n\tENTRY MENU";
		cout<<"\n\n\t1.CREATE PATIENT RECORD";
		cout<<"\n\n\t2.DISPLAY ALL PATIENTS RECORDS";
		cout<<"\n\n\t3.SEARCH PATIENT RECORD ";
		cout<<"\n\n\t4.MODIFY PATIENT RECORD";
		cout<<"\n\n\t5.DELETE PATIENT RECORD";
		cout<<"\n\n\t6.TO EXIT";
		cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1': 
		p.write_patient();
		break;
		case '2': 
		p.display_all(); 
		break;
		case '3': 
		cout<<"\n\n\tPlease Enter The reg  number "; 
		cin>>num;
   		p.display_p(num);
		break;
		case '4': 
		cout<<"\n\n\tPlease Enter The reg number "; 
		cin>>num;
   		p.modify_patient(num);
		break;
		case '5': 
		cout<<"\n\n\tPlease Enter The reg number "; 	
		cin>>num;
   		p.delete_patient(num);break;
			}
		}while(ch!='6');
}
 void write_receptionist()
   {
	Receptionist r;
	ofstream outFile;
	outFile.open("Receptionist.dat",ios::binary|ios::app);
	r.RecInfo();
	outFile.write(reinterpret_cast<char *> (&r), sizeof(Receptionist));
	outFile.close();
    cout<<"\n\nReceptionist record Has Been Created ";
	cin.ignore();
	cin.get();
 }
   void display_all_Receptionist()
{
	Receptionist r;
	ifstream inFile;
	inFile.open("Receptionist.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
}
cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&r), sizeof(Receptionist)))
	{
		r.show_receptionist();
		cout<<"\n\n=======================================================================================\n";
}
		inFile.close();
		cin.ignore();
		cin.get();
}


void display_r(int n)
{
	Receptionist r;
	ifstream inFile;
	inFile.open("Receptionist.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&r), sizeof(Receptionist)))
	{
		if(r.RecID==n)
		{
  			r.show_receptionist();
			flag=true;
}
}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
		cin.ignore();
		cin.get();
}

void modify_receptionist(int n)
{
	bool found=false;
	Receptionist r;
	fstream File;
	File.open("Receptionist.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
}
    while(!File.eof() && found==false)
	{
	File.read(reinterpret_cast<char *> (&r), sizeof(Receptionist));
	if(r.RecID==n)
	{
	  	r.show_receptionist();
	   	cout<<"\n\nPlease Enter The New Details "<<endl;
		r.RecInfo();
	    int pos=(-1)*static_cast<int>(sizeof(r));
	    File.seekp(pos,ios::cur);	
	    File.write(reinterpret_cast<char *> (&r), sizeof(Receptionist));
	    cout<<"\n\n\t Record Updated";
	    found=true;
	    system("cls");
}
}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
		cin.ignore();
		cin.get();
}


void Receptionist_menu()
{
    char ch;
		do
		{
			int n;
			system("cls");
			cout<<"\n\n\t01. INSERT Receptionist DATA";
			cout<<"\n\n\t02. Search Receptionist ";
			cout<<"\n\n\t03. ALL Receptionist ";
			cout<<"\n\n\t04. MODIFY Receptionist DATA";
			cout<<"\n\n\t05. To EXIT..........";
			cout<<"\n\n\tPlease Select Your Option (1-5) ";
			cin>>ch;
			switch(ch)
			{
			case '1': 
				write_receptionist();
  		  		break;
			case '2':
    		    cout<<"Enter Receptionist ID :";
				cin>>n;
                display_r(n);
                break;
			case '3':
        		display_all_Receptionist();
    			break;
			case '4':
        		cout<<"Enter Receptionist ID :";
				cin>>n;
        		modify_receptionist(n);
        		break;
}
    }while(ch!='5');

}
};

class store_manager:public Staff
{

    private:
        string productName;
        string supplierName;
        int unit;
        int bill;
        int SID;

    public:

       void SInfo()
    {
        Info();
        cout<<"Enter Receptionist ID :";
        cin>>SID;
    }

    void show_StoreManager()
    {
        show_staff();
        cout<<"Store Manager ID: "<<SID;
    }

       void orderproducts()
       {
         cout<<"\n\n|----------- ORDER Products & SUPPLIES ----------|"<<endl<<endl;
         cout<<"Enter Product Name: ";
         cin>>productName;
         cout<<"\nEnter Supplier's Name: ";
         cin>>supplierName;
         cout<<"\nEnter Number of Unit: ";
         cin>>unit;
         cout<<"\nEnter Total bill: ";
         cin>>bill;
         ofstream fout;
         fout.open("Products&Supplies.txt",ios::app);
         fout<<"Product Name: "<< productName<<endl;
         fout<<"Supplier's Name: "<< supplierName<<endl;
         fout<<"Number of Unit: "<< unit<<endl;
         fout<<"Total Bill: "<< bill<<endl<<endl;
         fout.close();
         cout<<"\n\nPRODUCT ORDERED SUCCESSFULLY!!"<<endl<<endl;
         int choice;
         cout<<"Do you want to order more?"<<endl;
         cout<<"(1) Yes"<<endl;
         cout<<"(2) No"<<endl<<endl<<endl;
         cin>>choice;
   		 if(choice==1)
    		{
        		system("cls");
        		orderproducts();
    }
    	else
    		{
    	    return;
    	}

}

  void readFromFile()
{
    ifstream fin;
    fin.open("Products&Supplies.txt");
    string str;
    if(!fin)
    {
        cout<<"\nERROR LOADING FILE!!"<<endl;
        return;
    }
    else
    {
        while(!fin.eof())
        {
            getline(fin,str);
            cout<<str;
            cout<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    fin.close();
    cin.get();
    system("pause");
}


void write_store_manager()
   {
		store_manager s;
		ofstream outFile;
		outFile.open("StoreManager.dat",ios::binary|ios::app);
		s.SInfo();
		outFile.write(reinterpret_cast<char *> (&s), sizeof(store_manager));
		outFile.close();
	    cout<<"\n\nrecord Has Been Created ";
		cin.ignore();
		cin.get();
		
   }

   void display_all_storeManager()
{
	store_manager s;
	ifstream inFile;
	inFile.open("StoreManager.dat",ios::binary);
	if(!inFile)
{
	cout<<"File could not be open !! Press any Key...";
	cin.ignore();
	cin.get();
	return;
}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(store_manager)))
	{
		s.show_StoreManager();
		cout<<"\n\n=======================================================================================\n";
}
	inFile.close();
	cin.ignore();
	cin.get();
}

	void display_s(int n)
	{
		store_manager s;
		ifstream inFile;
		inFile.open("StoreManager.dat",ios::binary);
		if(!inFile)
		{
			cout<<"File could not be open !! Press any Key...";
			cin.ignore();
			cin.get();
			return;
}
		bool flag=false;
		while(inFile.read(reinterpret_cast<char *> (&s), sizeof(store_manager)))
		{
			if(s.SID==n)
			{
  				s.show_StoreManager();
				flag=true;
	}
}
	inFile.close();
	if(flag==false)
	cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

	void store_manager_choice()
	{
    char ch;
    do
	{
		int n;
		system("cls");
        cout<<"\n\n\t01. Order Products ";
		cout<<"\n\n\t02. Show Order Products & Bills ";
		cout<<"\n\n\t03. To exit.....";
        cout<<"\n\n\tPlease Select Your Option (1-3) ";
        cin>>ch;
		switch(ch)
		{
			case '1':
        		orderproducts();
     			break;
			case '2':
        		readFromFile();
            	break;
            case '3':
            	system("cls");
			break;
			default :
				cout<<"\b";
}
    }while(ch!='3');


}

void store_manager_menu()
{
    char ch;
	do
	{
		int n;
		system("cls");
		cout<<"\n\n\t01. INSERT STORE MANAGER DATA";
		cout<<"\n\n\t02. Search STORE MANAGER ";
		cout<<"\n\n\t03. ALL STORE MANAGER ";
		cout<<"\n\n\t04. To exit this menu";
		cout<<"\n\n\tPlease Select Your Option (1-4) ";
		cin>>ch;
		switch(ch)
		{
			case '1': 
				write_store_manager();
     			break;
			case '2':
        		 cout<<"Enter STORE MANAGER ID :";
				 cin>>n;
                 display_s(n);
                 break;
			case '3':
        		display_all_storeManager();
   				break;
			case '4':
				break;
				default :
				cout<<"\b";
}
    }while(ch!='4');

}

};


class admin
{
	protected:
		Doctor d;
		patient p;
		Receptionist r;
		store_manager s;
		Nurse n;
  public:
  	admin(){
	  }
   	virtual void staff_menu()=0;
};

class Access:public admin{
	public:
	Access(){}
  void staff_menu()
    {
        char ch;
        do{
		system("cls");
		gotoxy(30,7);
		cout<<"Staff Menu";
		gotoxy(30,11);
		cout<<"1.Doctor";
		gotoxy(30,13);
		cout<<"2.Nurse";
		gotoxy(30,15);
		cout<<"3.Receptionist";
		gotoxy(30,17);
		cout<<"4.Store Manger";
		gotoxy(30,19);
		cout<<"5.TO EXIT";
		gotoxy(30,21);
		cout<<"Please Enter Your Choice (1-5) ";
		gotoxy(30,23);
		cout<<"choice->";
		cin>>ch;
		system("cls");

		switch(ch)
 		{
  			case '1': 
				d.Doctor_menu();break;
  			case '2':
				n.Nurse_menu(); break;
			case '3':  
    			r.Receptionist_menu();break;
			case '4':   
   				s.store_manager_menu();break;
 }
}while(ch!='5');
}
};

int main()
{
    Access a;
    Receptionist r;
    Doctor d;
    store_manager s;
    int ch;
    char pass[15];
    gotoxy(30,9);
    cout<<"WELCOME TO HOSPITAL MANAGEMENT SYSTEM";
    for(int i=0;i<=20000;i++)
	{
		gotoxy(30,18);		
		cout<<"loading :"<<i/200<<"%";
		
	}
		system("cls");
    	do{
    		gotoxy(30,11);
    		cout<<"1.Admin\n";
    		gotoxy(30,13);
    		cout<<"2.Receptionist\n";
    		gotoxy(30,15);
    		cout<<"3.Doctor\n";
    		gotoxy(30,17);
    		cout<<"4.Store Manager\n";
    		gotoxy(30,19);
    		cout<<"5.Exit From The SYSTEM\n";
    		gotoxy(30,21);
    		cout<<"choice->";
    		cin>>ch;
			switch(ch){
       				 case 1:
        		         login1:
        		         cout<<"Enter ADMIN password: ";
                 		 cin>>pass;

                 		if(strcmp(pass,"admin")==0)
                 		{
                  			 a.staff_menu();
                 }
            	     	else
                	 {
                	    cout<<"WRONG PASSWORD!!!\n";
                	    goto login1;
            		 }
                		 break;
       				 case 2:
            		     login2:
                		 cout<<"Enter Receptionist password: ";
                		 cin>>pass;
                		 if(strcmp(pass,"receptionist")==0)
                		 {
                   			r.entry_Patient();
                 }
                 		else
                 		{
                   			 cout<<"WRONG PASSWORD!!!\n";
                   			 goto login2;
                 }
                		break;
        			case 3:
						login3:
                 		cout<<"Enter Doctor password: ";
                 		cin>>pass;
                 		if(strcmp(pass,"doctor")==0)
                 		{		
                   			d.Doctor_choice();
                 }
                	 	else
                		 {
                		    cout<<"WRONG PASSWORD!!!\n";
                		    goto login3;
                 	}
                 			break;
        			case 4:
                		login4:
                 		cout<<"Enter STORE MANAGER password: ";
                 		cin>>pass;
                 		if(strcmp(pass,"store")==0)
                		 {
                   			s.store_manager_choice();
                 }
                 		else
                 		{
                    		cout<<"WRONG PASSWORD!!!\n";
                    		goto login4;
                 	}
                 		break;
            }
    }	while(ch!=5);
}
