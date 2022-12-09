#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstdio>
#include<fstream>
#include<string>

using namespace std;

void patient();
void doctor();
void disease();
void info();
class patientc
{
      public:
        int z,x,y,reg,pcode,res;
        char a;
        string phoneno,fname,lname,email;
        string se,des,hno,street,city;
        void addp();
        void searchp();
        void deletep();
        void viewp();
        void modifyp();
};
void patientc::addp()
{
    int i=1;
    lable:
    system("cls");
    fstream patientf("patient.txt",ios::app);
    cout <<"\t\tENTER THE DETAILS OF THE PATIENT"<<endl;
    cout <<"\n\tENTER THE REGISTRATION NUMBER OF THE PATIENT:";
    cin >> reg;
    patientf  <<reg <<"  ";
        cout <<"\n\tFIRST NAME:";
        cin >> fname;
        patientf  << fname <<"  ";
        cout <<"\n\tLAST NAME:";
        cin >> lname;
        patientf  << lname << "  ";
        cout <<"\n\tENTER THE ADDRESS OF THE PATIENT"<<endl;
        cout <<"\n\tHOUSE NUMBER:";
        cin >> hno;
        patientf  << hno <<"  ";
        cout <<"\n\tSTREET OR BLOCK:";
        cin >> street;
        patientf  << street <<"  ";
        cout <<"\n\tCITY:";
        cin >> city;
        patientf  << city <<"  ";
        cout <<"\n\tPINCODE:";
        cin >> pcode;
        patientf  << pcode <<"  ";
        cout <<"\n\tENTER THE MOBILE NUMBER OF THE PATIENT:";
        cin >> phoneno;
        patientf  << phoneno << "  ";
        cout <<"\n\tENTER THE EMAIL ADDRESS OF THE PATIENT:";
        cin >> email;
        patientf  << email;
        cout <<"\n\tENTER THE SEX OF THE PATIENT";
        cout <<"\n\n\t1.MALE \t2.FEMALE:";
        cin >> x;
        if(x==1)
           patientf  << "  MALE"<<"  ";
        else
           patientf  << "  FEMALE"<<"  ";
        cout <<"\n\tTHE PATIENT REASON OR DISEASE:";
        cin >> des;
        patientf  << des <<endl;
        patientf.close();
        cout <<"\n\tDO YOU WANT TO ADD MORE PATIENT (Y/N)";
        cin >>a;
        if(a=='n'||a=='N')
            {
                cout << "\n\tYOU HAVE SUCCESSFULLY REGESTERED "<<i<<" ENTRIES"<<endl;
                getchar();
                system("pause");
                patient();
            }
         else if(a=='y'||a=='Y')
            {
                i++;
                goto lable;
            }
}
void patientc::viewp()
{
    system("cls");
    ifstream patientf;
    patientf.open("patient.txt",ios::in);
    while(patientf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des)
    {
        cout <<"\n\n\t\tTHE DETAILS OF THE PATIENT"<<endl;
        cout <<"\n\n\tTHE REGISTRATION NUMBER:"<<reg;
        cout <<"\n\n\tFIRST NAME:"<<fname;
        cout <<"\n\n\tLAST NAME:"<<lname;
        cout <<"\n\n\tTHE ADDRESS OF THE PATIENT";
        cout <<"\n\n\tHOUSE NUMBER:"<<hno;
        cout <<"\n\n\tSTREET OR BLOCK:"<<street;
        cout <<"\n\n\tCITY:"<<city;
        cout <<"\n\n\tPINCODE:"<<pcode;
        cout <<"\n\n\tTHE MOBILE NUMBER OF THE PATIENT:" << phoneno;
        cout <<"\n\n\tTHE EMAIL ADDRESS OF THE PATIENT:" << email;
        cout <<"\n\n\tTHE PATIENT IS:" <<se;
        cout <<"\n\n\tTHE PATIENT REASON OR DISEASE:"<< des<<"\n\n\t";
        system("pause");
    }
    patient();
}
void patientc::searchp()
{
    z=0;
    lable:
    system("cls");
    ifstream patientf("patient.txt");
    cout << "\n\t\tENTER THE REGISTRATION NUMBER OF REQUIRED PATIENT:";
    cin >> x;
    while(patientf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des)
    {
        if(x==reg)
        {
            cout <<"\n\t\tTHE DETAILS OF THE PATIENT"<<endl;
            cout <<"\n\n\tTHE REGISTRATION NUMBER:"<<reg;
            cout <<"\n\n\tFIRST NAME:"<<fname;
            cout <<"\n\n\tLAST NAME:"<<lname;
            cout <<"\n\n\tTHE ADDRESS OF THE PATIENT";
            cout <<"\n\n\tHOUSE NUMBER:"<<hno;
            cout <<"\n\n\tSTREET OR BLOCK:"<<street;
            cout <<"\n\n\tCITY:"<<city;
            cout <<"\n\n\tPINCODE:"<<pcode;
            cout <<"\n\n\tTHE MOBILE NUMBER OF THE PATIENT:" << phoneno;
            cout <<"\n\n\tTHE EMAIL ADDRESS OF THE PATIENT:" << email;
            cout <<"\n\n\tTHE PATIENT IS:" <<se;
            cout <<"\n\n\tTHE PATIENT REASON OR DISEASE:"<< des;
            z=1;
         }
     }
     if(z!=1)
        cout <<"THE PATIENT DOESN'T EXIT";
    cout <<"\n\n\tDO YOU WANT TO SEARCH MORE PATIENT (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
        {
            cin.get(); system("pause");
            patientf.close();
            patient();
        }
    else if(a=='y'||a=='Y')
        {
            patientf.close();
            goto lable;
        }
}
void patientc::modifyp()
{
    lable:
    system("cls");
    ifstream patientf("patient.txt",ios::in);
    ofstream tempf("xy.txt",ios::out);
    cout << "\n\n\t\tMODIFY RECORD\n";
    cout << "\n\t\tENTER THE REGISTRATION NUMBER OF PATIENT:";
    cin >> z;
    while(patientf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des)
    {
        if(z==reg)
        {
             tempf  <<reg <<"  ";
             cout <<"\n\tFIRST NAME:";
             cin >> fname;
             tempf  << fname <<"  ";
             cout <<"\n\tLAST NAME:";
             cin >> lname;
             tempf  << lname << "  ";
             cout <<"\n\tENTER THE ADDRESS OF THE PATIENT"<<endl;
             cout <<"\n\tHOUSE NUMBER:";
             cin >> hno;
             tempf  << hno <<"  ";
             cout <<"\n\tSTREET OR BLOCK:";
             cin >> street;
             tempf  << street <<"  ";
             cout <<"\n\tCITY:";
             cin >> city;
             tempf  << city <<"  ";
             cout <<"\n\tPINCODE:";
             cin >> pcode;
             tempf  << pcode <<"  ";
             cout <<"\n\tENTER THE MOBILE NUMBER OF THE PATIENT:";
             cin >> phoneno;
             tempf  << phoneno << "  ";
             cout <<"\n\tENTER THE EMAIL ADDRESS OF THE PATIENT:";
             cin >> email;
             tempf  << email;
             cout <<"\n\tENTER THE SEX OF THE PATIENT";
             cout <<"\n\n\t1.MALE \t2.FEMALE:";
             cin >> x;
             if(x==1)
             tempf  << "  MALE"<<"  ";
             else
             tempf  << "  FEMALE"<<"  ";
             cout <<"\n\tTHE PATIENT REASON OR DISEASE:";
             cin >> des;
             tempf  << des <<endl;
             cout << "\n\n\t\tTHE RECORD IS FOUND AND MODIFIED";
        }
        else
         tempf<<reg<<"  "<<fname<<"  "<<lname<<"  "<<hno<<"  "<<street<<"  "<<city<<"  "<<pcode<<"  "<<phoneno<<"  "<<email<<"  "<<se<<"  "<<des<<endl;
    }
    patientf.close();
    tempf.close();
    remove("patient.txt");
    rename("xy.txt","patient.txt");
    cout <<"\n\n\tDO YOU WANT TO MODIFY MORE PATIENT (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
        {
            system("pause");
            patient();
        }
    else if(a=='y'||a=='Y')
            goto lable;
}

void patientc::deletep()
{
    lable:
    char ch;
    system("cls");
    fstream patientf,tempf;
    patientf.open("patient.txt",ios::in);
    tempf.open("tem.txt",ios::out);
    cout << "\n\n\t\tDELETE RECORD\n";
    cout << "\n\n  ENTER THE REGESTRATION NUMBER PARTIENT :";
    cin >> x;
    while(patientf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des)
    {
        if(x==reg)
        {
            cout<<"\n "<<reg<<"  "<<fname<<"  "<<lname<<"  "<<hno<<"  "<<street<<"  "<<city<<"  "<<pcode<<"  "<<phoneno<<"  "<<email<<"  "<<se<<"  "<<des<<"  "<<endl;
            cout << "\n\n\tTHE RECORD IS FOUND AND DELETED";
        }
        else
        tempf<<reg<<"  "<<fname<<"  "<<lname<<"  "<<hno<<"  "<<street<<"  "<<city<<"  "<<pcode<<"  "<<phoneno<<"  "<<email<<"  "<<se<<"  "<<des<<endl;
    }
 //   remove("patient.txt");
    // rename("tem.txt","patient.txt");
    patientf.close();
    tempf.close();
    patientf.open("patient.txt",ios::out);
    tempf.open("tem.txt",ios::in);
    while(tempf.eof())
    {
        tempf>>ch;
        patientf<<ch;
    }
    patientf.close();
    tempf.close();
    remove("tem.txt");


    cout << "\n\n\tDO YOU WANT TO DELETE MORE RECORDS(Y/N) :";
    cin >> a;
    if(a=='y'||a=='Y')
        goto lable;
    else
        patient();
}

class doctorc
{
    public:
        int sal,z,x,y,reg,pcode,res;
        char a;
        string phoneno,fname,lname,email;
        string se,des,hno,street,city;
        void addd();
        void searchd();
        void deleted();
        void viewd();
        void modifyd();
};
void doctorc::addd()
{
    char a;
    int i=1,x;
    lable:
    system("cls");
    cout <<"\t\tENTER THE DETAILS OF THE DOCTOR"<<endl;
    fstream doctorf("doc.txt",ios::app);
    cout <<"\n\tENTER THE IDENTIFICATION NUMBER OF THE DOCTOR:";
    cin >> reg;
    doctorf << reg << "  ";
    cout <<"\n\tFIRST NAME:";
    cin >> fname;
    doctorf << fname << "  ";
    cout <<"\n\tLAST NAME:";
    cin >> lname;
    cout <<"\n\tENTER THE ADDRESS"<<endl;
    cout <<"\n\tHOUSE NUMBER:";
    cin >> hno;
    doctorf << hno <<"  ";
    cout <<"\n\tSTREET OR BLOCK:";
    cin >> street;
    doctorf << street <<"  ";
    cout <<"\n\tCITY:";
    cin >> city;
    doctorf << city <<"  ";
    cout <<"\n\tPINCODE:";
    cin >> pcode;
    doctorf << pcode <<"  ";
    cout <<"\n\tENTER THE MOBILE NUMBER:";
    cin >> phoneno;
    doctorf << phoneno << "  ";
    cout <<"\n\tENTER THE EMAIL ADDRESS:";
    cin >> email;
    doctorf << email;
    cout <<"\n\tENTER THE SEX";
    cout <<"\n\n\t1.MALE \t2.FEMALE:";
    cin >> x;
    if(x==1)
    doctorf << "  MALE"<<"  ";
    else
    doctorf << "  FEMALE"<<"  ";
    cout <<"\n\tSPECIALTY OR DESIGNATION:";
    cin >> des;
    doctorf << des;
    cout <<"\n\tTHE DOCTOR SALARY:";
    cin >> sal;
    doctorf << sal;
    cout <<"\n\tDO YOU WANT TO ADD MORE DOCTORS (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
            {
                cout << "\n\tYOU HAVE SUCCESSFULLY REGESTERED "<<i<<" ENTRIES";
                system("pause");
                doctorf.close();
                doctor();
            }
    else if(a=='y'||a=='Y')
            {
                doctorf << endl;
                i++;
                doctorf.close();
                goto lable;
            }
}
void doctorc::viewd()
{
    system("cls");
    ifstream doctorf("doctor.txt",ios::out);
    while(doctorf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des>>sal)
    {
        cout <<"\n\n\t\tTHE DETAILS OF THE DOCTOR"<<endl;
        cout <<"\n\n\tTHE REGISTRATION NUMBER:"<<reg;
        cout <<"\n\n\tFIRST NAME:"<<fname;
        cout <<"\n\n\tLAST NAME:"<<lname;
        cout <<"\n\n\tTHE ADDRESS OF THE DOCTOR";
        cout <<"\n\n\tHOUSE NUMBER:"<<hno;
        cout <<"\n\n\tSTREET OR BLOCK:"<<street;
        cout <<"\n\n\tCITY:"<<city;
        cout <<"\n\n\tPINCODE:"<<pcode;
        cout <<"\n\n\tTHE MOBILE NUMBER OF THE DOCTOR:" << phoneno;
        cout <<"\n\n\tTHE EMAIL ADDRESS OF THE DOCTOR:" << email;
        cout <<"\n\n\tTHE DOCTOR IS:" <<se;
        cout <<"\n\n\tTHE DOCTOR DESIGNATION:"<< des;
        cout <<"\n\n\tSALARY OF THE DOCTOR:"<< sal<<"\n\n\t";
        system("pause");
    }
    doctor();
}
void doctorc::searchd()
{
    z=0;
    lable:
    system("cls");
    fstream doctorf("doctor.txt",ios::out);
    cout << "\n\t\tENTER THE REGISTRATION NUMBER OF REQUIRED DOCTOR:";
    cin >> x;
    while(doctorf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des>>sal)
    {
        if(x==reg)
        {
            cout <<"\n\t\tTHE DETAILS OF THE DOCTOR"<<endl;
            cout <<"\n\n\tTHE REGISTRATION NUMBER:"<<reg;
            cout <<"\n\n\tFIRST NAME:"<<fname;
            cout <<"\n\n\tLAST NAME:"<<lname;
            cout <<"\n\n\tTHE ADDRESS OF THE DOCTOR";
            cout <<"\n\n\tHOUSE NUMBER:"<<hno;
            cout <<"\n\n\tSTREET OR BLOCK:"<<street;
            cout <<"\n\n\tCITY:"<<city;
            cout <<"\n\n\tPINCODE:"<<pcode;
            cout <<"\n\n\tTHE MOBILE NUMBER OF THE DOCTOR:" << phoneno;
            cout <<"\n\n\tTHE EMAIL ADDRESS OF THE DOCTOR:" << email;
            cout <<"\n\n\tTHE DOCTOR IS:" <<se;
            cout <<"\n\n\tTHE DOCTOR DESIGNATION:"<< des;
            cout <<"\n\n\tTHE DOCTOR SALARY:"<< sal;
            z=1;
         }
     }
     if(z!=1)
        cout <<"THE DOCTOR DOESN'T EXIT";
    cout <<"\n\n\tDO YOU WANT TO SEARCH MORE DOCTOR (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
        {system("pause");
            cin.get(); system("pause");
            doctorf.close();
            doctor();
        }
    else if(a=='y'||a=='Y')
        {
            doctorf.close();
            goto lable;
        }

}
void doctorc::modifyd()
{
    lable:
    system("cls");
    ifstream doctorf("doctor.txt",ios::in|ios::binary);
    ofstream tempf("xyz.txt",ios::out|ios::binary);
    cout << "\n\n\t\tMODIFY RECORD\n";
    cout << "\n\t\tENTER THE REGISTRATION NUMBER OF DOCTOR:";
    cin >> z;
    while(doctorf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des>>sal)
    {
        if(z==reg)
        {
             tempf  <<reg <<"  ";
             cout <<"\n\tFIRST NAME:";
             cin >> fname;
            class diseasec
{
    public:
        int z,x,y,reg;
        char a;
        string name,des,type;
        void adddd();
        void searchdd();
        void deletedd();
        void viewdd();
        void modifydd();
};  cout<< fname <<"  ";
             cout <<"\n\tLAST NAME:";
             cin >> lname;
             tempf  << lname << "  ";
             cout <<"\n\tENTER THE ADDRESS OF THE DOCTOR"<<endl;
             cout <<"\n\tHOUSE NUMBER:";
             cin >> hno;
             tempf  << hno <<"  ";
             cout <<"\n\tSTREET OR BLOCK:";
             cin >> street;
             tempf  << street <<"  ";
             cout <<"\n\tCITY:";
             cin >> city;
             tempf  << city <<"  ";
             cout <<"\n\tPINCODE:";
             cin >> pcode;
             tempf  << pcode <<"  ";
             cout <<"\n\tENTER THE MOBILE NUMBER OF THE DOCTOR:";
             cin >> phoneno;
             tempf  << phoneno << "  ";
             cout <<"\n\tENTER THE EMAIL ADDRESS OF THE DOCTOR:";
             cin >> email;
             tempf  << email;
             cout <<"\n\tENTER THE SEX OF THE DOCTOR";
             cout <<"\n\n\t1.MALE \t2.FEMALE:";
             cin >> x;
             if(x==1)
             tempf  << "  MALE"<<"  ";
             else
             tempf  << "  FEMALE"<<"  ";
             cout <<"\n\tTHE DOCTOR DESIGNATION:";
             cin >> des;
             tempf  << des <<endl;
             cout <<"\n\tTHE SALARY OF DOCTOR:";
             cin >> sal;
             tempf  << sal <<endl;
             cout << "\n\n\t\tTHE RECORD IS FOUND AND MODIFIED";
        }
        else
         tempf<<reg<<"  "<<fname<<"  "<<lname<<"  "<<hno<<"  "<<street<<"  "<<city<<"  "<<pcode<<"  "<<phoneno<<"  "<<email<<"  "<<se<<"  "<<des<<"  "<<sal<<endl;
    }
    doctorf.close();
    tempf.close();
    remove("doctor.txt");
    rename("xyz.txt","doctor.txt");
    cout <<"\n\n\tDO YOU WANT TO MODIFY MORE DOCTOR (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
        {
            system("pause");
            doctor();
        }
    else if(a=='y'||a=='Y')
            goto lable;
}
void doctorc::deleted()
{
    lable:
    system("cls");
    ifstream doctorf("doctor.txt",ios::in|ios::binary);
    ofstream tempf("temp.txt",ios::out|ios::binary);
    cout << "\n\n\t\tDELETE RECORD\n";
    cout << "\n\n  ENTER THE REGESTRATION NUMBER DOCTOR :";
    cin >> x;
    while(doctorf>>reg>>fname>>lname>>hno>>street>>city>>pcode>>phoneno>>email>>se>>des>>sal)
    {
        if(x==reg)
        {
            cout<<"\n "<<reg<<"  "<<fname<<"  "<<lname<<"  "<<hno<<"  "<<street<<"  "<<city<<"  "<<pcode<<"  "<<phoneno<<"  "<<email<<"  "<<se<<"  "<<des<<"  "<<sal<<endl;
            cout << "\n\n\tTHE RECORD IS FOUND AND DELETED";
        }
        else
          tempf<<reg<<"  "<<fname<<"  "<<lname<<"  "<<hno<<"  "<<street<<"  "<<city<<"  "<<pcode<<"  "<<phoneno<<"  "<<email<<"  "<<se<<"  "<<des<<"  "<<sal<<endl;
    }
    doctorf.close();
    tempf.close();
    remove("doctor.txt");
    rename("temp.txt","doctor.txt");
    cout << "\n\n\tDO YOU WANT TO DELETE MORE RECORDS(Y/N) :";
    cin >> a;
    if(a=='y'||a=='Y')
        goto lable;
    else
        doctor();
}
class diseasec
{
    public:
        int z,x,y,reg;
        char a;
        string name,des,type;
        void adddd();
        void searchdd();
        void deletedd();
        void viewdd();
        void modifydd();
};
void diseasec::adddd()
{
    int i=1;
    system("cls");
    lable:
    cout <<"\t\tENTER THE DETAILS OF THE DISEASE:"<<endl;
    fstream diseasef;
    diseasef.open("disease.txt");
    cout <<"\n\tENTER THE IDENTIFICATION NUMBER OF THE DISEASE:";
    cin >> reg;
    diseasef << reg << "  ";
    cout <<"\n\tNAME OF THE DISEASE:";
    cin >> name;
    diseasef << name << "  ";
    cout <<"\n\tENTER THE TYPE OF THE DISEASE";
    cout <<"\n\n\t1.COMMON \t2.INFECTIOUS \t3.SERIOUS:";
    cin >> x;
    if(x==1)
    diseasef << "  COMMON"<<"  ";
    else if(x==2)
    diseasef << "  INFECTIOUS"<<"  ";
    else if(x==3)
    diseasef << "  SERIOUS"<<"  ";
    cout <<"\n\tMEDICINE FOR DISEASE:";
    cin >> des;
    diseasef << des;
    cout <<"\n\tDO YOU WANT TO ADD MORE DISEASE (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
            {
                cout << "\n\tYOU HAVE SUCCESSFULLY REGESTERED "<<i<<" ENTRIES";
                system("pause");
                disease();
            }
    else if(a=='y'||a=='Y')
            {
                diseasef << endl;
                i++;
                goto lable;
            }
}
void diseasec::viewdd()
{
    system("cls");
    ifstream diseasef("disease.txt",ios::out);
    while(diseasef>>reg>>name>>type>>des)
    {
        cout <<"\n\n\t\tTHE DETAILS OF THE PATIENT"<<endl;
        cout <<"\n\n\tTHE REGISTRATION NUMBER:"<<reg;
        cout <<"\n\n\tFIRST NAME:"<<name;
        cout <<"\n\n\tTYPE OF DISEASE:"<<type;
        cout <<"\n\n\tMEDICINE FOR DISEASE:"<< des<<"\n\n\t";
        system("pause");
    }
    disease();
}
void diseasec::searchdd()
{
    z=0;
    lable:
    system("cls");
    ifstream diseasef("dis.txt",ios::in);
    cout << "\n\t\tENTER THE REGISTRATION NUMBER OF REQUIRED PATIENT:";
    cin >> x;
    while(diseasef>>reg>>name>>type>>des)
    {
        if(x==reg)
        {
            cout <<"\n\t\tTHE DETAILS OF THE PATIENT"<<endl;
            cout <<"\n\n\tTHE REGISTRATION NUMBER:"<<reg;
            cout <<"\n\n\tFIRST NAME:"<<name;
            cout <<"\n\n\tTYPE OF DISEASE:"<<type;
            cout <<"\n\n\tMEDICINE FOR DISEASE:"<< des;
            z=1;
         }
     }
     if(z!=1)
        cout <<"THE DISEASE DOESN'T EXIT";
    cout <<"\n\n\tDO YOU WANT TO SEARCH MORE PATIENT (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
        {
            cin.get(); system("pause");
            diseasef.close();
            disease();
        }
    else if(a=='y'||a=='Y')
        {
            diseasef.close();
            goto lable;
        }
}

void diseasec::modifydd()
{
    lable:
    system("cls");
    ifstream diseasef("dis.txt",ios::in| ios::binary);
    ofstream tempf("xyz.txt",ios::out| ios::binary);
    cout << "\n\n\t\tMODIFY RECORD\n";
    cout << "\n\t\tENTER THE REGISTRATION NUMBER OF DISEASE:";
    cin >> z;
    while(diseasef>>reg>>name>>type>>des)
    {
        if(z==reg)
        {
             tempf  <<reg <<"  ";
             cout <<"\n\tNAME OF DISEASE:";
             cin >> name;
             tempf  << name <<"  ";
             cout <<"\n\tTYPE OF DISEASE:";
             cin >> type;
             tempf  << type << "  ";
             cout <<"\n\tTHE PATIENT REASON OR DISEASE:";
             cin >> des;
             tempf  << des <<endl;
             cout << "\n\n\t\tTHE RECORD IS FOUND AND MODIFIED";
        }
       else
            tempf<<reg<<"  "<<name<<"  "<<type<<"  "<<des;
}
    diseasef.close();
    tempf.close();
    remove("dis.txt");
    rename("xyz.txt","dis.txt");
    cout <<"\n\n\tDO YOU WANT TO MODIFY MORE PATIENT (Y/N)";
    cin >>a;
    if(a=='n'||a=='N')
        {
            system("pause");
            disease();
        }
    else if(a=='y'||a=='Y')
            goto lable;
}
void diseasec::deletedd()
{
    lable:
    system("cls");
    ifstream diseasef("dis.txt",ios::in);
    ofstream tempf("temp.txt",ios::out);
    cout << "\n\n\t\tDELETE RECORD\n";
    cout << "\n\n  ENTER THE REGESTRATION NUMBER PARTIENT :";
    cin >> x;
    while(diseasef>>reg>>name>>type>>des)
    {
        if(x==reg)
        {
            cout<<"\n "<<reg<<"  "<<name<<"  "<<type<<"  "<<des<<"  "<<endl;
            cout << "\n\n\tTHE RECORD IS FOUND AND DELETED";
        }
        else
        tempf<<reg<<"  "<<name<<"  "<<type<<"  "<<des<<endl;
    }
    diseasef.close();
    tempf.close();
    remove("dis.txt");
    rename("temp.txt","dis.txt");
    cout << "\n\n\tDO YOU WANT TO DELETE MORE RECORDS(Y/N) :";
    cin >> a;
    if(a=='y'||a=='Y')
        goto lable;
    else
        disease();
}

int main()
{
    string usr,pass;
    start:
    system("cls");
    system("COLOR 03");
    void menu();
    cout << "\n\t\tASR HOSPITAL MANAGEMENT SYSTEM\n\n" << endl;
    cout <<"\n\n\n\n\n\t\tENTER YOUR USER NAME :";
    cin >>usr;
    cout <<"\n\t\tENTER YOUR PASSWORD :";
    cin >>pass;
    if(usr=="amit"&&pass=="168244000"||usr=="AMIT"&&pass=="168244000")
    menu();
    else
    {
        cout << "\n\t\tPLEASE ENTER VALID USER NAME AND PASSWORD\n\n" << endl;
        system("pause");
        goto start;
    }
    return 0;
}
void menu()
{
    int x;
    lable1:
    system("cls");
    cout << "\t\tPLEASE SELECT ANY OF THESE OPTION\n\n" << endl;
    cout << "\t\t1. PATIENTS\n" << endl;
    cout << "\t\t2. DOCTORS\n" << endl;
    cout << "\t\t3. DISEASES\n" << endl;
    cout << "\t\t4. INFORMATION OF THE HOSPITAL\n" << endl;
    cout <<"\t\t";  cin>>x;
    switch(x)
    {
        case 1: patient();
                break;
        case 2: doctor();
                break;
        case 3: disease();
                break;
        case 4: info();
        default:
        {     cout <<"PLEASE ENTER VALID CHOISE";
              system("pause");
              goto lable1;
        }
    }
}
void patient()
{
    int x;
    patientc p;
    lable2:
    system("cls");
    void patient();
    void doctor();
    void deasies();
    cout << "\t\tPLEASE SELECT ANY OF THESE OPTION\n\n" << endl;
    cout << "\t\t1. ADD NEW PATIENT\n" << endl;
    cout << "\t\t2. VIEW EXISTING PATIENT\n" << endl;
    cout << "\t\t3. DELETE EXISTING PATIENT\n" << endl;
    cout << "\t\t4. MODIFY EXISTING PATIENT\n" << endl;
    cout << "\t\t5. SEARCH EXISTING PATIENT\n" << endl;
    cout << "\t\t6. GO TO MAIN MENU\n" << endl;
    cout <<"\t\t";  cin>>x;
    switch(x)
    {
        case 1: p.addp();
                break;
        case 2: p.viewp();
                break;
        case 3: p.deletep();
                break;
        case 4: p.modifyp();
                break;
        case 5: p.searchp();
                break;
        case 6: menu();
                break;
        default:
        {     cout <<"PLEASE ENTER VALID CHOISE";
              system("pause");
              goto lable2;
        }
    }
}
void doctor()
{
    int x;
    doctorc d;
    lable:
    system("cls");
    cout << "\t\tPLEASE SELECT ANY OF THESE OPTION\n\n" << endl;
    cout << "\t\t1. ADD NEW DOCTOR\n" << endl;
    cout << "\t\t2. VIEW EXISTING DOCTOR\n" << endl;
    cout << "\t\t3. DELETE EXISTING DOCTOR\n" << endl;
    cout << "\t\t4. MODIFY EXISTING DOCTOR\n" << endl;
    cout << "\t\t5. SEARCH EXISTING DOCTOR\n" << endl;
    cout << "\t\t6. GO TO MAIN MENU\n" << endl;
    cout <<"\t\t";  cin>>x;
    switch(x)
    {
        case 1: d.addd();
                break;
        case 2: d.viewd();
                break;
        case 3: d.deleted();
                break;
        case 4: d.modifyd();
                break;
        case 5: d.searchd();
                break;
        case 6: menu();
                break;
        default:
        {     cout <<"PLEASE ENTER VALID CHOISE";
              system("pause");
              goto lable;
        }
    }
}
void disease()
{
    int x;
    diseasec dis;
    lable:
    system("cls");
    cout << "\t\tPLEASE SELECT ANY OF THESE OPTION\n\n" << endl;
    cout << "\t\t1. ADD NEW DEASIES\n" << endl;
    cout << "\t\t2. VIEW EXISTING DEASIES\n" << endl;
    cout << "\t\t3. DELETE EXISTING DEASIES\n" << endl;
    cout << "\t\t4. MODIFY EXISTING DEASIES\n" << endl;
    cout << "\t\t5. SEARCH EXISTING DEASIES\n" << endl;
    cout << "\t\t6. GO TO MAIN MENU\n" << endl;
    cout <<"\t\t";  cin>>x;
    switch(x)
    {
        case 1: dis.adddd();
                break;
        case 2: dis.viewdd();
                break;
        case 3: dis.deletedd();
                break;
        case 4: dis.modifydd();
                break;
        case 5:dis.searchdd();
                break;
        case 6: menu();
                break;
        default:
        {     cout <<"PLEASE ENTER VALID CHOISE";
              system("pause");
              goto lable;
        }
    }
}
void info()
{
    system("cls");
    cout << "\n Information and software details \n\n";
    cout << "\n1.ASR hospital management hospital management system is an application which is used to record details of patient , doctor and diseases and it also store information about hospital and software.";
    cout << "\n2.This software can also manipulate these three  entities in different ways like using adding record , deleting records , viewing record , modifying record and searching a record in the database.";
    cout << "\n3.it is also secure with user login name and password but still user login name and password are static for this project .";
    cout << "\n4.This software use single entity at a time of input and strings are not allowed because it create denormalization in the database.";
    cout << "\n5.programming language used for this project is C++ and file system is used as database.";
    cout << "\n6.This software is built on the software called code block 17.12 and Windows 7 is used as operating system environment for this software.";
    cout<<"\n\n"; system("pause");
}
