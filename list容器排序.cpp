#include<iostream>
#include<string>
#include<list>
using namespace std;
class person
{
	public:
		person(string name,int age,int height)
		{
			this->name=name;
			this->age=age;
			this->height=height;
		}
		string name;
		int age;
		int height;
};
bool comparePerson(person &p1,person &p2)
{
	if(p1.age==p2.age)
	{
		return p1.height>p2.height;
	}
	else
	{
	return p1.age<p2.age;	
	}
}
void test01()
{
	list<person>L;
	person p1("刘备",35,175); 
	person p2("曹操",45,180);
	person p3("孙权",40,170);
	person p4("赵云",25,190);
	person p5("张飞",35,160);
	person p6("关羽",35,200);

	L.push_back(p1); 
	L.push_back(p2); 
	L.push_back(p3); 
	L.push_back(p4); 
	L.push_back(p5); 
	L.push_back(p6); 

	
	for(list<person>::iterator it=L.begin();it!=L.end();it++)
	{
		cout<<"姓名"<<(*it).name<<"年龄"<<it->age<<"身高"<<it->height<<endl; 
	}
	L.sort(comparePerson);
	
	for(list<person>::iterator it=L.begin();it!=L.end();it++)
	{
		cout<<"姓名"<<(*it).name<<"年龄"<<it->age<<"身高"<<it->height<<endl; 
	}
}
int main()
{
    test01();
	
 } 
