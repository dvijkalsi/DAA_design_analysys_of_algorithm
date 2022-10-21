#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter a sentence:";
    string line;
    getline(cin,line);
    stringstream check1(line);
    string intermediate;
    int c_wrd=0;
    int len_sum=0;
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        len_sum+=intermediate.length();
        cout<<intermediate.length()<<endl;
        c_wrd++;
    }
    float avg=len_sum*1.0/c_wrd;
    printf("Avg length:%.5f",avg);

}