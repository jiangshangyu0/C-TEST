#include<iostream>
#include<thread>
#include<list>
#include<vector>
#include<mutex>
using namespace std;
class A
{
public:
	void inMsgRecvQueue()
	{
		for(int i=0;i<100000;++i)
		{
			cout<<"inMsgRecvQueue()执行，插入一个元素"<<i<<endl;
			my_mutex.lock();
			msgRecvQueue.push_back(i);
			my_mutex.unlock();
		}
		return;
	}
	bool outMsgLULProc(int &command)
	{
		my_mutex.lock(); 
			if(!msgRecvQueue.empty())
			{
				int command=msgRecvQueue.front();
				msgRecvQueue.pop_front();
				my_mutex.unlock();
				return true;
			}
			my_mutex.unlock();
			return false;
	}
	void outMsgRecvQueue()
	{
		int command=0;
		for(int i=0;i<100000;++i)
		{
		    bool result=outMsgLULProc(command);
		if(result==true)
		{
			cout<<"outMsgRecvQueue()执行,取出一个元素"<<command<<endl; 
		}
		else
		{
			cout<<"outMsgRecvQueue()执行，但目前消息队列中为空"<<i<<endl; 
		}
		}
		cout<<"end"<<endl;
	}
private:
	list<int>msgRecvQueue;
	mutex my_mutex;
	
 } ;
 
 int main()
 {
 	A myobja;
 	thread myInMsgObj(&A::inMsgRecvQueue,&myobja);
 	thread myOutnMsgObj(&A::outMsgRecvQueue,&myobja);
 	myInMsgObj.join();
 	myOutnMsgObj.join();
 	
 	return 0;	
 }
