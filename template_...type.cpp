#include<iostream>
using namespace std;
void printX()
{
	cout<<"�ұ���ֵΪ�յ�ʱ�������"<<endl; 
 } 
template<typename T,typename...Types>
void printX(const T&firstArg,const Types&...args)
{
	cout<<firstArg<<endl;
	printX(args...);
}
int main()
{
	printX(7.5,"hello world",49,90);
	return 0;
}
