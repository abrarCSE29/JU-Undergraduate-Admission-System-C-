#include<bits/stdc++.h>

using namespace std;

long aroll=100;
long broll=200;
long croll=300;
long droll=400;
long eroll=500;
typedef struct payment_info
{
    long phone;
    double amount=0;
};

void delay(int n)
{

    n=n*400000;
    while(n--)
    {

    }
}
class HSC_info
{
protected :

    int roll;
    long registration;
    char board[20];
    int passing_year;

public :
    double result;
    int grp;
    void get()
    {
        cout<<"\nHigher Secondary Examination info "<<endl;
        cout<<"---------------------------------\n"<<endl;
        cout<<"Enter your HSC roll : ";
        cin>>roll;
        cout<<"Enter your HSC Registration Number : ";
        cin>>registration;
        cout<<"Enter your RESULT : ";
        cin>>result;
        cout<<"Enter Board (All in Capital Letter): ";
        cin>>board;
        cout<<"Enter Passing Year  : ";
        cin>>passing_year;
        cout<<"GROUP        : 1.Science  2.Commerce  3.Arts"<<endl;
        cout<<"Enter Choice : ";
        cin>>grp;
    }

    void display()
    {
        cout<<"\nHigher Secondary Examination info "<<endl;
        cout<<"---------------------------------\n"<<endl;
        cout<<"ROLL         : "<<roll<<endl;
        cout<<"REGISTRATION : "<<registration<<endl;
        cout<<"Board        : "<<board<<endl;
        cout<<"Result       : "<<setprecision(2)<<result<<endl;
        cout<<"Passing Year : "<<passing_year<<endl;

    }
};

class SSC_info
{
protected :

    int roll;
    long registration;
    char board[20];

    int passing_year;

public :
    double result;
    void get()
    {
        cout<<"\nSecondary School Examination info "<<endl;
        cout<<"---------------------------------\n"<<endl;
        cout<<"Enter your SSC roll : ";
        cin>>roll;
        cout<<"Enter your SSC Registration Number :";
        cin>>registration;
        cout<<"Enter your RESULT : ";
        cin>>result;
        cout<<"Enter Board (All in Capital Letter) : ";
        cin>>board;
        cout<<"Enter Passing Year : ";
        cin>>passing_year;
    }

    void display() const
    {
        cout<<"\nSecondary School Examination info "<<endl;
        cout<<"---------------------------------\n"<<endl;
        cout<<"ROLL         : "<<roll<<endl;
        cout<<"REGISTRATION : "<<registration<<endl;
        cout<<"Board        : "<<board<<endl;
        cout<<"Result       : "<<setprecision(2)<<result<<endl;
        cout<<"Passing Year : "<<passing_year<<endl;
    }
};

class personal_info : public HSC_info, public SSC_info
{
public :
    char name[100],n_father[100],n_mother[100],dob[100];
    char present_address[1000],permanent_address[1000];

    long student_mobile, aux_contact;


     char nick_name[100];
    void get()
    {
        HSC_info::get();
        SSC_info::get();
        system("cls");
        cout<<"\nPersonal Information\n"<<endl;
        cout<<"--------------------"<<endl;
        getchar();
        cout<<"Name of the applicant : ";
        scanf("%[^\n]",name);
        getchar();
        cout<<"Nick name of the applicant : ";
        cin>>nick_name;
        cout<<"Enter Student Mobile No : ";
        cin>>student_mobile;
        getchar();
        cout<<"Name of applicant's father : ";
        scanf("%[^\n]",n_father);
        getchar();
        cout<<"Name of applicant's mother : ";
        scanf("%[^\n]",n_mother);
        getchar();
        cout<<"Enter Date of Birth (dd/mm/yyyy) : ";
        scanf("%[^\n]",dob);
        getchar();
        cout<<"Enter Present Address : ";
        scanf("%[^\n]",present_address);
        getchar();
        cout<<"Enter Permanent address : ";
        scanf("%[^\n]",permanent_address);
        cout<<"Auxiliary Contact No : ";
        cin>>aux_contact;
    }


    void display()
    {
        cout<<"\nPersonal Info"<<endl;
        cout<<"-------------\n"<<endl;
        cout<<"Name of applicant : "<<name<<endl;
        cout<<"Nick Name         : "<<nick_name<<endl;
        cout<<"Mobile No         : 0"<<student_mobile<<endl;
        cout<<"Father's Name     : "<<n_father<<endl;
        cout<<"Mother's Name     : "<<n_mother<<endl;
        cout<<"Date of Birth     : "<<dob<<endl;
        cout<<"Present Address   : "<<present_address<<endl;
        cout<<"Permanent Address : "<<permanent_address<<endl;
        cout<<"Auxiliary Contact : 0"<<aux_contact<<endl;
        cout<<endl;
        HSC_info::display();
        cout<<endl;
        SSC_info::display();
        cout<<endl;
    }
};


class undergraduate : public personal_info
{

public :

    long phone_number;
    int password;
    double payment;
    int unit[6];
    int k=0;

    payment_info payslip;
    void getlogin()
    {
        cout<<"Enter Mobile Number          : ";
        cin>>phone_number;
        cout<<"Enter Password (Only digits) : ";
        cin>>password;
    }

    void get()
    {
        system("cls");
        personal_info :: get();
    }

    void edit()
    {
        personal_info :: get();
    }

    void displayunit()
    {

        if(k>0)
        {
            cout<<"Applied Units : ";
            cout<<k<<endl;
            for(int i=0; i<k; i++)
            {
                cout<<char('A'+unit[i]-1)<<", ";
            }
            cout<<"\n"<<endl;
        }

    }

    void display()
    {
        personal_info::display();
    }

    double hsc_res()
    {
        return HSC_info::result;
    }

    double ssc_res()
    {
        return SSC_info::result;
    }
    int hsc_grp()
    {
        return HSC_info::grp;
    }
    void pb(int c)
    {
        unit[k++]=c;
    }

    int srch(int c)
    {
        for(int i=0; i<k; i++)
        {
            if(unit[i]==c)
            {
                return 1;
            }
        }
        return 0;
    }

    friend int getpass(undergraduate *obj);
    friend void getpayment (undergraduate *obj);

};



void getpayment(undergraduate *obj)
{
    int c;
    cout<<"\nPAYMENT GATEWAY"<<endl;
    cout<<"===============\n"<<endl;
    cout<<"Payment Options"<<endl;
    cout<<"---------------"<<endl;
    cout<<"1.bKash\n2.Rocket\n3.Nagad\n"<<endl;
    cin>>c;

    if(c==1)
    {
        cout<<"\nbKash GATEWAY\n"<<endl;
    }
    else if(c==2)
    {
        cout<<"\nRocket GATEWAY\n"<<endl;
    }
    else if (c==3)
    {
        cout<<"\nNagad GATEWAY\n"<<endl;
    }

    cout<<"Enter Mobile No : ";
    cin>>obj->payslip.phone;
    cout<<"Enter Amount : ";
    double w;
    cin>>w;
    obj->payslip.amount+=w;
}

void eligibility(undergraduate *obj)
{
    cout<<"APPLY FOR UNITS"<<endl;
    cout<<"***************\n"<<endl;

    while(1)
    {

        cout<<"\nEnter options for corresponding Units"<<endl;
        cout<<"1. A\n2. B\n3. C\n4. D\n5. E\n0. To exit selection\n"<<endl;
        int c;
        cin>>c;

        if(c==1)
        {
            if(obj->srch(c))
            {
                cout<<"You already applied for UNIT "<<char('A'+c-1)<<endl;
            }
            else if(obj->hsc_res()>=4.00 && obj->ssc_res()>=4.00 && obj->hsc_grp()==1)
            {
                obj->pb(c);
                obj->payment+=600.00;
                cout<<"UNIT SELECTION SUCCESSFUL"<<endl;
            }
            else
            {
                cout<<"\nYou are not eligible for UNIT "<<char('A'+c-1)<<endl;
            }
        }

        else if(c==2)
        {

            if(obj->srch(c))
            {
                cout<<"You already applied for UNIT "<<char('A'+c-1)<<endl;
            }
            else if(obj->hsc_res()>=3.50 && obj->ssc_res()>=3.50)
            {
                obj->pb(c);
                obj->payment+=600.00;
                cout<<"UNIT SELECTION SUCCESSFUL"<<endl;
            }
            else
            {
                cout<<"You are not eligible for UNIT "<<char('A'+c-1)<<endl;
            }
        }

        else if(c==3)
        {

            if(obj->srch(c))
            {
                cout<<"You already applied for UNIT "<<char('A'+c-1)<<endl;
            }
            else if(obj->hsc_res()>=3.50 && obj->ssc_res()>=3.50)
            {
                obj->pb(c);
                obj->payment+=600.00;
                cout<<"UNIT SELECTION SUCCESSFUL"<<endl;
            }
            else
            {
                cout<<"You are not eligible for UNIT "<<char('A'+c-1)<<endl;
            }
        }

        else if(c==4)
        {
            if(obj->srch(c))
            {
                cout<<"You already applied for UNIT "<<char('A'+c-1)<<endl;
            }

            else if(obj->hsc_res()>=4.00 && obj->ssc_res()>=4.00 && obj->hsc_grp()==1)
            {
                obj->pb(c);
                obj->payment+=600.00;
                cout<<"UNIT SELECTION SUCCESSFUL"<<endl;
            }
            else
            {
                cout<<"You are not eligible for UNIT "<<char('A'+c-1)<<endl;
            }
        }

        else if(c==5)
        {
            if(obj->srch(c))
            {
                cout<<"You already applied for UNIT "<<char('A'+c-1)<<endl;
            }

            else if(obj->hsc_res()>=4.00 && obj->ssc_res()>=4.00 && (obj->hsc_grp()==2 || obj->hsc_grp()==3))
            {
                obj->pb(c);
                obj->payment+=600.00;
                cout<<"UNIT SELECTION SUCCESSFUL"<<endl;
            }
            else
            {
                cout<<"You are not eligible for UNIT "<<char('A'+c-1)<<endl;
            }
        }

        else if(c==0)
            break;
    }
}


int main()
{
    long n=0,cnt,num,pass,f=-1;

    undergraduate *applicant[100];

    fstream infile;

    infile.open("info.txt",ios :: in|ios::out|ios::binary|ios ::app);
    infile.seekg(0,ios::end);
    n=infile.tellg()/sizeof(undergraduate);
    cout<<"Number of pre existing accounts : "<<n<<endl;
    infile.seekg(0);
    for(int i=0;i<n;i++)
    {
        applicant[i]=new undergraduate;
        infile.read(reinterpret_cast<char*>(applicant[i]),sizeof(*applicant[i]));
    }
    infile.close();


start1 :
    cout<<"WELCOME TO UNDERGRADUATE UNIVERSITY ADMISSION PORTAL (Prototype) "<<endl;

    cout<<"\nSelect Option : "<<endl;
    cout<<"\t1. Log In"<<endl;
    cout<<"\t2. Apply for admission"<<endl;
    cout<<"\t3. Admission Notices."<<endl;
    int choice;

    cin>>choice;

    system("cls");

    if(choice==1)
    {

        cout<<"LOG IN PORTAL"<<endl;
        cout<<"-------------\n"<<endl;

        cout<<"Enter Phone Number : ";
        cin>>num;
        cout<<"\nEnter Password     : ";
        cin>>pass;
        for(int i=0; i<n; i++)
        {

            int x=applicant[i]->phone_number;
            int y=applicant[i]->password;
            cout<<x<<" "<<y<<endl;
            if(x==num && y==pass)
            {
                f=i;
                break;
            }
        }


        if(f==-1)
        {
            cout<<"\t\nWrong Credentials...\n"<<endl;
            delay(1500);
            system("cls");
            goto start1;
        }


        else
        {
start2:
            system("cls");
            cout<<"****** WELCOME "<<applicant[f]->personal_info::nick_name<<" ******"<<endl;
            applicant[f]->displayunit();
            cout<<"Payable amount : ";
            cout<<fixed;
            cout<<setprecision(2)<<applicant[f]->payment-applicant[f]->payslip.amount<<endl;

            cout<<"Payment Status : ";

            if(applicant[f]->payment==0)
            {
                cout<<"You have not applied for any unit"<<endl;
            }

            else if(applicant[f]->payslip.amount==applicant[f]->payment)cout<<"Paid"<<endl;
            else cout<<"Not Paid"<<endl;
            cout<<"\nSelect Options :"<<endl;
            cout<<"\t1. Complete Payment"<<endl;
            cout<<"\t2. Download Admit Card"<<endl;
            cout<<"\t3. See Detailed info"<<endl;
            cout<<"\t4. Apply for units"<<endl;
            cout<<"\t5. Edit Personal Info\n\t\t***Doing this will replace previous info with current info"<<endl;
            cout<<"\t6. Log Out.\n"<<endl;

            int d;
            cin>>d;

            if(d==1)
            {
                cout<<"Please wait..."<<endl;
                delay(1500);
                system("cls");
                getpayment(applicant[f]);
                cout<<"Please wait..."<<endl;
                delay(1500);
                cout<<"Successful payment...\n"<<endl;
                cout<<"Redirecting to previous page..."<<endl;
                delay(1500);
                system("cls");
                goto start2;
            }
            else if(d==2)
            {
                ofstream file("Admit.txt");
                file<<"ADMIT CARD"<<endl;
                file<<"----------"<<endl;

                if(applicant[f]->srch(1))
                {
                    file<<"Unit :"<<char('A')<<endl;
                    file<<"ROLL :"<<aroll+f<<endl;
                }
                if(applicant[f]->srch(2))
                {
                    file<<"Unit :"<<char('B')<<endl;
                    file<<"ROLL :"<<broll+f<<endl;
                }

                if(applicant[f]->srch(3))
                {
                    file<<"Unit :"<<char('C')<<endl;;
                    file<<"ROLL :"<<croll+f<<endl;
                }
                if(applicant[f]->srch(4))
                {
                    file<<"Unit :"<<char('D')<<endl;
                    file<<"ROLL :"<<droll+f<<endl;
                }
                if(applicant[f]->srch(5))
                {
                    file<<"Unit :"<<char('E')<<endl;
                    file<<"ROLL :"<<droll+f<<endl;
                }

                file<<"----------------------------"<<endl;

                file<<"Name         : "<<applicant[f]->name<<endl;
                file<<"Father Name  : "<<applicant[f]->n_father<<endl;
                file<<"Mother Name  : "<<applicant[f]->n_mother<<endl;

                file.close();
                goto start2;
            }
            else if(d==3)
            {
                system("cls");
                applicant[f]->display();
                cout<<"\nPress any key to go to previous page "<<endl;
                getchar();
                getchar();
                system("cls");
                goto start2;
            }

            else if (d==4)
            {
                system("cls");
                eligibility(applicant[f]);
                goto start2;
            }
            else if(d==5)
            {
                system("cls");
                applicant[f]->edit();
                system("cls");
                goto start2;
            }

            else if(d==6)
            {
                system("cls");
                goto start1;
            }
        }
    }


    else if(choice==2)
    {
        cout<<"Undergraduate Admission"<<endl;
        cout<<"=======================\n"<<endl;

        applicant[n]= new undergraduate;
        applicant[n]->getlogin();
        applicant[n]->get();
        system("cls");
        //eligibility(applicant[n]);
        //applicant[n]->display();
        cout<<"\n\nAPPLICATION SUCCESSFULL!!!\n"<<endl;

        cout<<"Redirecting to log in page..."<<endl;
        n++;
        delay(1500);
        system("cls");
        goto start1;
    }

    else if(choice==3)
    {
        cout<<"Contents are Coming...."<<endl;
        cout<<"\nPress any key to return to previous page..."<<endl;
        getchar();
        getchar();
        system("cls");
        goto start1;
    }
    infile.open("info.txt",ios::out|ios::trunc);
    infile.close();
    infile.open("info.txt",ios :: in|ios::out|ios::binary|ios ::app);
    for(int i=0;i<n;i++)
    {
        infile.write(reinterpret_cast<char*>(applicant[i]),sizeof(*applicant[i]));
    }

    infile.close();


    return 0;


}
