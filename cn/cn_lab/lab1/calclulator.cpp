#include<iostream>
using namespace std;
void test()
{
    cout<<"Enter two numbers\n";
    int a,b;
    cin>>a>>b;
    cout<<"+:add\n-:subtract\n*:multiply\n/:divide\nEnter your choice:\n";
    char op;
    cin>>op;
    switch(op)
    {
        case '+':cout<<a+b<<endl;
                break;
        case '-':cout<<a-b<<endl;
                break;
        case '*':cout<<a*b<<endl;
                break;
        case '/':cout<<a/b<<endl;
                break;
        default:cout<<"Invalid operator"<<endl;
    }
}


int main()
{
    
    test();
    return 0;
    

}