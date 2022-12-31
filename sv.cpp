#include<sys/types.h>
#include<iostream>
#include<fstream>
#include<SDL.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<unistd.h>
#include<array>
#include<vector>
#include<thread>
#include<X11/Xlib.h>
#include<X11/XKBlib.h>
#define XK_MISCELLANY
#include<X11/keysymdef.h>
unsigned char tns(KeySym t)
{
	if(t==XK_KP_0)return 0;
	if(t==XK_KP_1)return 1;
	if(t==XK_KP_2)return 2;
	if(t==XK_KP_3)return 3;
	if(t==XK_KP_4)return 4;
	if(t==XK_KP_5)return 5;
	if(t==XK_KP_6)return 6;
	if(t==XK_KP_7)return 7;
	if(t==XK_KP_8)return 8;
	if(t==XK_KP_9)return 9;
	return 0;
}
int ssk(int p)
{
	char s;
	while(read(p,&s,1)>0)
	{
		if(s=='0')return 0;
	}
	return 1;
}
void es(void(*k)(int),bool n)
{
	const char* sn="/tmp/svs629";
	mkfifo(sn,S_IRWXU);
	int p=fork();
	if(p==0)
	{
		int ss=open(sn,O_RDONLY|O_NONBLOCK);
		if(!flock(ss,LOCK_EX|LOCK_NB))
		{
			if(n)k(ss);
			else
			{
				bool ck=1;
				while(ck)
				{
					ck=ssk(ss);
					std::this_thread::sleep_for(std::chrono::milliseconds(16));
				}
			}
		}
	}
	else if(p>0)
	{
		int ss=open(sn,O_WRONLY);
		char s='0';
		if(n)s='1';
		if(write(ss,&s,1)==-1){};
	}
}
std::string tsn;
struct vv
{
	size_t pv0=0;
	bool snv=0;
	bool vpv=0;
	size_t pv=0;
};
struct lsp
{
	size_t s=0;
	vv operator[](size_t s)
	{
		vv dv;
		char sn[256];
		sprintf(sn,"%s/vvs/%ld",tsn.c_str(),s);
		auto sp=std::ifstream(sn);
		sp>>dv.pv0;
		sp>>dv.snv;
		sp>>dv.vpv;
		sp>>dv.pv;
		sp.close();
		return dv;
	}
	size_t ss()
	{	
		if(!s)
		{
			auto sd=std::ifstream(tsn+std::string("/ss"));
			sd>>s;
			sd.close();
		}
		return s;
	}
};
lsp ls;
void svk(size_t vk)
{
	char sn[256];
	sprintf(sn,"c2dec 2400 %s/kls/%ld - | aplay -fS16_LE -c1 -r8000 2>/dev/null",tsn.c_str(),vk);
	system(sn);	
}
void k(int p)
{
	bool ck=1;
	int yk=0;
	size_t vs=0;
	auto vk=[&ck,&yk,&vs]()
	{
		bool ssv=1;
		std::vector<size_t> kps;
		while(ssv)
		{
			std::vector<size_t> pv;
			size_t kp=0;
			double vss=0;
			while(ck)	
			{
				while(yk!=12&&yk!=3&&yk!=16&&ck&&pv.size()==0)
				{
					double ks=0.016;
					std::this_thread::sleep_for(std::chrono::milliseconds((int)(ks*1000.0)));
				}
				if(!ck)break;
				auto vsk=[&pv,&kp,&vss](size_t vs)
				{
					if(vs>ls.ss())return;
					double ss=0.001*(double)SDL_GetTicks();
					size_t vk=vs;
					pv.push_back(vs);
					auto pnv=[&kp](size_t k)
					{
						auto kpn=kp; 
						while(kpn)
						{
							if(k==kpn)return 1;
							kpn=ls[kpn].pv0;
						}
						return 0;
					};	
					while(!(ls[vk].pv0==0||(ls[vk].pv0==kp&&ss-vss<10)||(!ls[vk].snv&&pnv(ls[vk].pv0))))
					{
						vk=ls[vk].pv0;
						pv.push_back(vk);
					}
				};
				if(yk==16)
				{
					yk=0;
					if(0)printf("16 %ld\n",vs);
					vsk(kp);
					continue;
				}
				else if(pv.size()>0)
				{
					kp=pv[pv.size()-1];
					pv.pop_back();
				}
				else if(yk==3)
				{
					yk=0;
					if(ls[kp].pv)
						vsk(ls[kp].pv);
					continue;
				}
				else if(yk==12)
				{
					yk=0;
					vsk(vs);
					if(0)printf("%ld\n",kp);
					continue;
				}
				else if(yk!=0)
				{
					yk=0;
					continue;
				}
				else continue;
				svk(kp);
				vss=0.001*(double)SDL_GetTicks();
			}
			if(!ck)
				break;
		}
	};
	Display *d=XOpenDisplay(0);
	for(int i=XK_KP_0;i<=XK_KP_9;i++)
	{
		XGrabKey(d,XKeysymToKeycode(d,i),16,DefaultRootWindow(d),0,GrabModeAsync,GrabModeAsync);
		XGrabKey(d,XKeysymToKeycode(d,i),16|LockMask,DefaultRootWindow(d),0,GrabModeAsync,GrabModeAsync);
	}
	XEvent g;
	int tk=0;
	const int sks=2;
	char sk[sks+1];
	sk[sks]=0;
	int skk=0;
	std::thread vkk(vk);
	const size_t pgtv=300;
	while(ck)
	{
		while(XCheckMaskEvent(d,-1,&g))
		{
			if(g.type==KeyPress)
			{
				auto t=tns(XLookupKeysym(&(g.xkey),1));
				if(yk==0)
				{
					if(t==9)ck=0;
					else if(t==2)
					{
						yk=2;
						skk=0;
					}
					else if(t==3)
						yk=3;
					else if(t==6)
					{
						yk=6;
						tk=pgtv;
						vs=0;
					}
				}
				else if(yk==6)
				{
					vs++;
					tk=pgtv;
				}
				else if(yk==2)
				{
					sk[skk]='0'+t;
					skk++;
					if(skk==sks)
					{
						vs=atoi(sk);
						yk=12;
					}
				}
			}
		}
		if(p)ck=ck&ssk(p);
		const int kn=40;
		std::this_thread::sleep_for(std::chrono::milliseconds(kn));
		if(tk>0)tk-=kn;
		if(tk<=0&&yk==6)
			yk=16;
	}
	vkk.join();
	XUngrabKey(d,AnyKey,AnyModifier,DefaultRootWindow(d));
	SDL_Quit();
}
int main(int argc,char** argv)
{
	char *sn=getenv("SSSS");
	if(sn)
		tsn=std::string(sn);
	else
	{
		std::string s=std::string(argv[0]);
		tsn=s.substr(0,s.find_last_of("/"));
	}
	if(argc<2)
		printf("0|1?\n");
	else if(argv[1][0]=='3')
	{
		char sn[256];
		sprintf(sn,"arecord -c 1 -f S16_LE -r 8000 | ffmpeg -f s16le -ar 8000 -i pipe: -filter:a loudnorm -f s16le -ar 8000 pipe: | c2enc 2400 - - | tee %s/kls/%s| c2dec 2400 - - | aplay -c 1 -r 8000 -f S16_LE",tsn.c_str(),argv[2]);
		system(sn);	
	}
	else if(argv[1][0]=='5')
	{
		std::vector<bool> p(ls.ss());
		for(size_t k=0;k<p.size();k++)
			p[k]=0;
		for(size_t k=0;k<ls.ss();k++)
			if(ls[k+1].pv)p[ls[k+1].pv-1]=1;
		for(size_t k=0;k<ls.ss();k++)
			if(!p[k])
				printf("%ld\n",k+1);
	}
	else es([](int p){k(p);},argv[1][0]!='0');
	return 0;
}
