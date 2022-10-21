//wap to find total number of duplicate elements in the vector, and find out the most repeating element in the vector.
#include<bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> v;
    int n;
    cout<<"Enter the number of elements in the vector: ";
    cin>>n;
    cout<<"Enter the elements of the vector: ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int max_count=0;
    int max_element=0;
    int repeat_count=0;
    for(int i=0;i<v.size();i++)
    {
        int count=1;
        int flag=0;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i]==v[j])
            {
                count++;
                flag=1;

            }
            else
            {
                break;
            }
            i=j;
        }
        if(flag)
        {
            repeat_count++;
        }
        if(count>max_count)
        {
            max_count=count;
            max_element=v[i];
        }
    }
    cout<<"Total number of duplicate elements in the vector is: "<<repeat_count<<endl;
    cout<<"Most repeating element in the vector is: "<<max_element<<endl;



}