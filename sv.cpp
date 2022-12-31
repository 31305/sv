#include<sys/types.h>
#include<iostream>
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
struct vv
{
	size_t pv0=0;
	bool snv=0;
	bool vpv=0;
	size_t pv=0;
};
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
//std::vector<vv> ls;
struct lsp
{
	vv operator[](size_t s)
	{
		return {};
	}
	static size_t ss()
	{
		return 0;
	}
};
lsp ls;
void svk(size_t vk)
{
	char sn[256];
	sprintf(sn,"c2dec 2400 kls/%ld - | aplay -fS16_LE -c1 -r8000",vk);
	system(sn);	
}
void k(int p)
{
	bool ck=1;
	int yk=0;
	size_t vs=0;
	std::vector<unsigned char> nv;
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
					if(vs>=ls.ss())return;
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
					while(!(ls[vk].pv0==0||((ls[vk].pv0==ls[kp].pv0||ls[vk].pv0==kp||(pnv(ls[vk].pv0)&&ls[vk].pv0))&&ss-vss<10)))
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
					continue;
				}
				else if(yk!=0)
				{
					yk=0;
					continue;
				}
				else continue;
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
	int pt=0;
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
					else if(t==1)
					{
						if(0)yk=1;
						nv.resize(0);
					}
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
				else if(yk==1)
				{
					if(tk>0)
					{
						tk=0;
						if(t==0&&pt==0)
						{
							yk=0;
						}
						else nv.push_back(pt*10+t);
					}
					else
					{
						tk=1000;
						pt=t;
					}
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
	if(argc<2)
		printf("0|1?\n");
	else if(argv[1][0]=='5')
	{
		std::vector<bool> p(ls.ss());
		for(size_t k=0;k<p.size();k++)
			p[k]=0;
		for(size_t k=0;k<ls.ss();k++)
			p[ls[k].pv]=1;
		for(size_t k=0;k<ls.ss();k++)
			if(!p[k])
				printf("%ld\n",k);
	}
	else es([](int p){k(p);},argv[1][0]!='0');
	return 0;
}
