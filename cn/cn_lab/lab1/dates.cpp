#include<bits/stdc++.h>
using namespace std;
int month[13];

void value_month()
{
    month[1]=31;
    month[2]=28;
    month[3]=31;
    month[4]=30;
    month[5]=31;
    month[6]=30;
    month[7]=31;
    month[8]=31;
    month[9]=30;
    month[10]=31;
    month[11]=30;
    month[12]=31;

}
bool isleap(int year)
{
    
    // leap year if perfectly divisible by 400
    if (year % 400 == 0) {
        return true;
    }
    // not a leap year if divisible by 100
    // but not divisible by 400
    else if (year % 100 == 0) {
        return false;
    }
    // leap year if not divisible by 100
    // but divisible by 4
    else if (year % 4 == 0) {
        return true;
    }
    // all other years are not leap years
    else {
        return false;
    }
}
int main()
{
    value_month();
    cout<<"Enter date in dd mm yyyy format:";
    int dd,mm,yyyy;
    cin>>dd>>mm>>yyyy;
    if(dd<=0||dd>31||mm<=0||mm>12||yyyy<=0)
    {
        cout<<"Invalid date";
        return 0;
    }
    if(isleap(yyyy)&&mm==2&&dd>29)
    {
        cout<<"Invalid date";
        return 0;
    }
    else if(!isleap(yyyy)&&mm==2&&dd>28)
    {
        cout<<"Invalid date";
        return 0;
    }
    else if(month[mm]<dd)
    {
        cout<<"Invalid date";
        return 0;
    }
    else
    {
        cout<<"Valid date";
    }

    cout<<"Enter days to add:";
    int d;
    cin>>d;

    if(isleap(yyyy))
    {
        month[2]=29;
    }
    else
    {
        month[2]=28;
    }
    dd+=d;
    while(dd>month[mm])
    {

        if(isleap(yyyy))
        {
            month[2]=29;
        }
        else
        {
            month[2]=28;
        }
        dd-=month[mm];
        mm++;
        if(mm>12)
        {
            yyyy++;
            mm-=12;
        }
    }


    cout<<dd<<" "<<mm<<" "<<yyyy<<endl;




    return 0;
}