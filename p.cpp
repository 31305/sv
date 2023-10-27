#include<thread>
#include<cstdio>
#include<mutex>
std::mutex s;
int ss=1;
void k()
{
	while(ss)
	{
		s.lock();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		s.unlock();
	}
}
int main()
{
	std::thread ck(k);
	while(ss)
	{
		scanf("%d",&ss);
		s.lock();
		s.unlock();
		printf(">\n");
	}
	ck.join();
	return 0;
}
