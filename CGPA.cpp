//cgpa
#include<iostream>

using namespace std;

string lower_case_converter(string);
void gpa_calculator();
void cgpa_calculator();

int main()
{
    string choice;
    cout<<"Would you like to calculate you cgpa or gpa? ";
    cin>>choice;
    /*Converting user's choice to lower case*/
    choice=lower_case_converter(choice);

    if(choice=="gpa")
    {
        gpa_calculator();
    }
    else if(choice=="cgpa")
    {
        cgpa_calculator();
    }

    return 0;
}

void gpa_calculator()
{
    int no_of_sub;
    cout<<"Enter number of subjects: ";
    cin>>no_of_sub;

    int marks[no_of_sub];
    float credits[no_of_sub];
    for(int i=0;i<no_of_sub;i++)
    {
        cout<<"Enter mark of subject "<<i+1<<": ";
        cin>>marks[i];
        cout<<"Enter number of credits for subject "<<i+1<<": ";
        cin>>credits[i];
    }

    int grade=0;
    float grade_point[no_of_sub];
    
    for(int i=0;i<no_of_sub;i++)
    {
        if(marks[i]>=90 && marks[i]<=100)
        {
            grade=10;
        }
        else if(marks[i]>=80 && marks[i]<90)
        {
            grade=9;
        }
        else if(marks[i]>=70 && marks[i]<80)
        {
            grade=8;
        }
        else if(marks[i]>=60 && marks[i]<70)
        {
            grade=7;
        }
        else if(marks[i]>=55 && marks[i]<60)
        {
            grade=6;
        }
        else if(marks[i]>=50 && marks[i]<55)
        {
            grade=5;
        }
        else 
        {
            grade=0;
        }
        grade_point[i]=grade*credits[i];
   }

    float total_grade_points=0.0;
    float total_credits=0.0;
    for(int i=0;i<no_of_sub;i++)
    {
        total_grade_points+=grade_point[i];
        total_credits+=credits[i];
    }

    float gpa=total_grade_points/total_credits;
    cout<<"Your gpa is "<<gpa<<endl;
}

void cgpa_calculator()
{
    /*CGPA*/
    int no_of_sems;
    cout<<"Enter number of semesters: ";
    cin>>no_of_sems;

    float credits_per_sem[no_of_sems];
    float gpa_per_sem[no_of_sems];
    float product[no_of_sems];
    for(int i=0;i<no_of_sems;i++)
    {
        cout<<"Enter GPA in semester "<<i+1<<": ";
        cin>>gpa_per_sem[i];
        cout<<"Enter number of credits in semester "<<i+1<<": ";
        cin>>credits_per_sem[i];
    
        product[i]=credits_per_sem[i]*gpa_per_sem[i];
    }

    float sum_of_product=0.0;
    float total_credits_sem=0.0;
    for(int i=0;i<no_of_sems;i++)
    {
        sum_of_product+=product[i];
        total_credits_sem+=credits_per_sem[i];
    }

    float cgpa=sum_of_product/total_credits_sem;

    cout<<"Your CGPA is "<<cgpa<<"."<<endl;
}

string lower_case_converter(string s)
{
    for(int i=0;s[i]!='\0';i++)
    {
        if (s[i]>='A' && s[i]<='Z')
        {
            s[i]+=32;
        }
    }
    return s;
}
