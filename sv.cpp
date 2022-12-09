#include"VocalTractModel5.h"
#include<SDL.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<unistd.h>
#include<array>
#include<thread>
#include<X11/Xlib.h>
#include<X11/XKBlib.h>
#define XK_MISCELLANY
#include<X11/keysymdef.h>
struct v
{
	enum csp{k=1,t,m,d,o,kt,od,ko};
	csp cs;
	bool n;
	bool vs,ns,nt,sv;
	bool sd,vg;
	enum ssp{u=1,a,s};
	ssp ss;
	char vv;
	bool mp,sg;
	bool sm;
};
constexpr v vc[]=
{
	{},
	{v::csp::k,0,0,0,0,1,0,0,v::ssp::a,0,0,0},
	{v::csp::k,0,0,0,0,1,0,0,v::ssp::u,0,0,0},
	{v::csp::k,0,0,0,0,1,0,0,v::ssp::s,0,0,0},
	{v::csp::k,0,0,0,0,1,1,0,v::ssp::a,0,0,0},
	{v::csp::k,0,0,0,0,1,1,0,v::ssp::u,0,0,0},
	{v::csp::k,0,0,0,0,1,1,0,v::ssp::s,0,0,0},
	{v::csp::t,0,0,0,0,1,0,0,v::ssp::a,0,0,0},
	{v::csp::t,0,0,0,0,1,0,0,v::ssp::u,0,0,0},
	{v::csp::t,0,0,0,0,1,0,0,v::ssp::s,0,0,0},
	{v::csp::t,0,0,0,0,1,1,0,v::ssp::a,0,0,0},
	{v::csp::t,0,0,0,0,1,1,0,v::ssp::u,0,0,0},
	{v::csp::t,0,0,0,0,1,1,0,v::ssp::s,0,0,0},
	{v::csp::o,0,0,0,0,1,0,0,v::ssp::a,0,0,0},
	{v::csp::o,0,0,0,0,1,0,0,v::ssp::u,0,0,0},
	{v::csp::o,0,0,0,0,1,0,0,v::ssp::s,0,0,0},
	{v::csp::o,0,0,0,0,1,1,0,v::ssp::a,0,0,0},
	{v::csp::o,0,0,0,0,1,1,0,v::ssp::u,0,0,0},
	{v::csp::o,0,0,0,0,1,1,0,v::ssp::s,0,0,0},
	{v::csp::m,0,0,0,0,1,0,0,v::ssp::a,0,0,0},
	{v::csp::m,0,0,0,0,1,0,0,v::ssp::u,0,0,0},
	{v::csp::m,0,0,0,0,1,0,0,v::ssp::s,0,0,0},
	{v::csp::m,0,0,0,0,1,1,0,v::ssp::a,0,0,0},
	{v::csp::m,0,0,0,0,1,1,0,v::ssp::u,0,0,0},
	{v::csp::m,0,0,0,0,1,1,0,v::ssp::s,0,0,0},
	{v::csp::d,0,0,0,0,1,0,0,v::ssp::a,0,0,0},
	{v::csp::d,0,0,0,0,1,0,0,v::ssp::u,0,0,0},
	{v::csp::d,0,0,0,0,1,0,0,v::ssp::s,0,0,0},
	{v::csp::d,0,0,0,0,1,1,0,v::ssp::a,0,0,0},
	{v::csp::d,0,0,0,0,1,1,0,v::ssp::u,0,0,0},
	{v::csp::d,0,0,0,0,1,1,0,v::ssp::s,0,0,0},
	{v::csp::kt,0,0,0,0,1,1,0,v::ssp::a,0,0,0},
	{v::csp::kt,0,0,0,0,1,1,0,v::ssp::u,0,0,0},
	{v::csp::kt,0,0,0,0,1,1,0,v::ssp::s,0,0,0},
	{v::csp::kt,0,0,0,0,1,1,1,v::ssp::a,0,0,0},
	{v::csp::kt,0,0,0,0,1,1,1,v::ssp::u,0,0,0},
	{v::csp::kt,0,0,0,0,1,1,1,v::ssp::s,0,0,0},
	{v::csp::ko,0,0,0,0,1,1,0,v::ssp::a,0,0,0},
	{v::csp::ko,0,0,0,0,1,1,0,v::ssp::u,0,0,0},
	{v::csp::ko,0,0,0,0,1,1,0,v::ssp::s,0,0,0},
	{v::csp::ko,0,0,0,0,1,1,1,v::ssp::a,0,0,0},
	{v::csp::ko,0,0,0,0,1,1,1,v::ssp::u,0,0,0},
	{v::csp::ko,0,0,0,0,1,1,1,v::ssp::s,0,0,0},
	{v::csp::t,0,0,0,1},
	{v::csp::m,0,0,0,1},
	{v::csp::d,0,0,0,1},
	{v::csp::od,0,0,0,1},
	{v::csp::t,0,0,0,0,0,0,0,(v::ssp)0,0,0,0,1},
	{v::csp::m,0,0,0,0,0,0,0,(v::ssp)0,0,0,0,1},
	{v::csp::d,0,0,0,0,0,0,0,(v::ssp)0,0,0,0,1},
	{v::csp::k,0,0,0,0,0,0,0,(v::ssp)0,0,0,0,1},
	{v::csp::k,0,0,0,0,0,0,0,(v::ssp)0,1,0,0},
	{v::csp::k,0,0,0,0,0,0,0,(v::ssp)0,1,1,0},
	{v::csp::k,0,0,0,0,0,0,0,(v::ssp)0,1,0,1},
	{v::csp::k,0,0,0,0,0,0,0,(v::ssp)0,1,1,1},
	{v::csp::k,1,0,0,0,0,0,0,(v::ssp)0,1,0,0},
	{v::csp::t,0,0,0,0,0,0,0,(v::ssp)0,2,0,0},
	{v::csp::t,0,0,0,0,0,0,0,(v::ssp)0,2,1,0},
	{v::csp::t,0,0,0,0,0,0,0,(v::ssp)0,2,0,1},
	{v::csp::t,0,0,0,0,0,0,0,(v::ssp)0,2,1,1},
	{v::csp::t,1,0,0,0,0,0,0,(v::ssp)0,2,0,0},
	{v::csp::m,0,0,0,0,0,0,0,(v::ssp)0,3,0,0},
	{v::csp::m,0,0,0,0,0,0,0,(v::ssp)0,3,1,0},
	{v::csp::m,0,0,0,0,0,0,0,(v::ssp)0,3,0,1},
	{v::csp::m,0,0,0,0,0,0,0,(v::ssp)0,3,1,1},
	{v::csp::m,1,0,0,0,0,0,0,(v::ssp)0,3,0,0},
	{v::csp::d,0,0,0,0,0,0,0,(v::ssp)0,4,0,0},
	{v::csp::d,0,0,0,0,0,0,0,(v::ssp)0,4,1,0},
	{v::csp::d,0,0,0,0,0,0,0,(v::ssp)0,4,0,1},
	{v::csp::d,0,0,0,0,0,0,0,(v::ssp)0,4,1,1},
	{v::csp::d,1,0,0,0,0,0,0,(v::ssp)0,4,0,0},
	{v::csp::o,0,0,0,0,0,0,0,(v::ssp)0,5,0,0},
	{v::csp::o,0,0,0,0,0,0,0,(v::ssp)0,5,1,0},
	{v::csp::o,0,0,0,0,0,0,0,(v::ssp)0,5,0,1},
	{v::csp::o,0,0,0,0,0,0,0,(v::ssp)0,5,1,1},
	{v::csp::o,1,0,0,0,0,0,0,(v::ssp)0,5,0,0},
	{(v::csp)0,1,0,1},
	{v::csp::k,0,1},
};
template<typename n>
struct ck
{
	size_t s;
	ck(size_t ds):s(ds){k=new n[s];}
	~ck(){delete k;}
	n *k;
	const size_t v(size_t a){a++;if(a==s)a=0;return a;}
	const size_t ak(size_t d,size_t u){if(u>=d)return u-d;else return u+s-d;}
};
template<typename n>
struct bck
{
	size_t s,cs;
	bck(size_t ds,size_t dcs):s(ds),cs(dcs){k=new n[cs*s];}
	~bck(){delete k;}
	n *k;
	n& d(size_t c,size_t ks){return k[c*s+ks];}
	const size_t v(size_t a){a++;if(a==s)a=0;return a;}
	const size_t ak(size_t d,size_t u){if(u>=d)return u-d;else return u+s-d;}
	const size_t cv(size_t a){a++;if(a==s)a=0;return a;}
	const size_t cak(size_t d,size_t u){if(u>=d)return u-d;else return u+s-d;}
};
struct b
{
	GS::VTM::VocalTractModel5<double,1> m;
};
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
const double nv=GS_VTM5_MIN_RADIUS;
double vm(const v& dv,short vk,bool db=0)
{
	double vmk[][8]=
		{{0.8,0.65,0.65,0.65,1.31,1.23,1.31,1.67},
		{0.8,0.52,0.45,0.79,1.49,1.67,1.02,1.59},
		{0.8,1.045,1.565,1.75,0.94,0.68,0.785,1.12},
		{0.8,1.67,1.905,1.985,0.81,0.495,0.73,1.485},
		{0.8,1.91,1.44,0.6,1.02,1.33,1.56,0.55},
		{0.8,1.31,0.73,1.31,2.12,0.63,1.78,0.65},
		{0.8,0.89,1.1,0.97,0.89,0.34,0.29,1.12},
		{0.8,0.68,1.12,1.695,1.385,1.07,1.045,2.06},
		{0.8,0.885,0.99,0.81,0.755,1.045,1.225,1.12},
		{0.8,1,0.925,0.6,1.27,1.83,1.97,1.12},
		{0.8,1.1,0.94,0.42,1.49,1.67,1.78,1.05},
		{0.8,0.89,0.76,1.28,1.8,0.99,0.84,0.1,},
		{0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8},
		{0.8,1.7,1.3,0.99,0.1,1.07,0.73,1.49},
		{0.8,1.36,1.74,1.87,0.94,0,0.79,0.79},
		{0.8,1.31,1.49,1.25,0.76,0.1,1.44,1.31},
		{0.8,1.2,1.5,1.35,1.2,1.2,0.4,1},
		{0.8,1.67,1.91,1.99,0.63,0.29,0.58,1.49},
		{0.8,1.36,1.74,1.87,0.94,0.37,0.79,0.79},
		{0.8,1.31,1.49,1.25,0.9,0.2,0.4,1.31},
		{0.8,0.89,0.99,0.81,0.76,0.89,0.84,0.5}};
	if(dv.sv)
	{
		if(dv.cs==v::csp::k)
		{
			if(dv.sd)return vmk[1][vk];
			else return vmk[0][vk];
		}
		else if(dv.cs==v::csp::t)
		{
			if(dv.sd)return vmk[3][vk];
			else return vmk[2][vk];
		}
		else if(dv.cs==v::csp::o)
			return vmk[4][vk];
		else if(dv.cs==v::csp::m)
			return vmk[5][vk];
		else if(dv.cs==v::csp::d)
			return vmk[6][vk];
		else if(dv.cs==v::csp::kt)
		{
			if(!dv.vg)
				return vmk[7][vk];
			else
			{
				if(!db)
					return vmk[0][vk];
				else return vmk[8][vk];
			}
		}
		else if(dv.cs==v::csp::ko)
		{
			if(!dv.vg)
				return vmk[9][vk];
			else
			{
				if(!db)
					return vmk[0][vk];
				else return vmk[10][vk];
			}
		}
	}
	else if(dv.ns)return std::min(vmk[0][vk],std::min(vmk[2][vk],vmk[4][vk]));
	else if(dv.vs)return vmk[12][vk];
	else if(dv.vv==1)
	{
		if(vk==5-1)return nv;
		else return vmk[13][vk];
	}
	else if(dv.vv==2)
	{
		if(vk==6-1)return nv;
		else return vmk[14][vk];
	}
	else if(dv.vv==3)
	{
		if(vk==6-1)return 1;
		else return vmk[15][vk];
	}
	else if(dv.vv==4)
	{
		if(vk==7-1)return nv;
		else return vmk[16][vk];
	}
	else if(dv.vv==5)
	{
		if(vk==8-1)return nv;
		else return vmk[11][vk];
	}
	else if(dv.nt)
	{
		if(dv.cs==v::csp::t)
			return vmk[17][vk];
		else if(dv.cs==v::csp::m)
		{
			if(vk==6-1)return 0.47;
			else return vmk[15][vk];
		}
		else if(dv.cs==v::csp::d)
			return vmk[6][vk];
		else if(dv.cs==v::csp::o)
		{
			if(vk==8-1)return 0.4;
			else return vmk[4][vk];
		}
	}
	else if(dv.sm)
	{
		if(dv.cs==v::csp::t)
		{
			if(vk==6-1)return 0.13;
			else return vmk[14][vk];
		}
		else if(dv.cs==v::csp::m)
			return vmk[18][vk];
		else if(dv.cs==v::csp::d)
			return vmk[19][vk];
		else if(dv.cs==v::csp::k)
			return vmk[12][vk];
	}
	return 0;
}
double sdvm(const v &dv)
{
	if(dv.vv==3)return nv;
	else if(dv.nt&&dv.cs==v::csp::m)return 1.8;
	else return vm(dv,6-1);
}
double hgs(const v &dv)
{
	if(dv.sm)
	{
		if(dv.cs==v::csp::t)return 5.6;
		else if(dv.cs==v::csp::m)return 5.6;
		else if(dv.cs==v::csp::d)return 5.8;
	}
	else if(dv.vv&&!dv.n)
	{
		double m[5]={4.7,5.6,5.6,6.5,7};
		return m[(int)dv.vv];
	}
	else if(dv.nt&&dv.cs==v::csp::o)return 7;
	return 0;
}
double hgv(const v &dv)
{
	if(dv.sm)
	{
		if(dv.cs==v::csp::t)return 4400;
		else if(dv.cs==v::csp::m)return 2500;
		else if(dv.cs==v::csp::d)return 5500;
	}
	else if(dv.vv&&!dv.n)
	{
		double m[5]={2000,3800,4500,4500,2000};
		return m[(int)dv.vv];
	}
	else if(dv.nt&&dv.cs==v::csp::o)return 3300;
	return 0;
}
double hgd(const v &dv)
{
	if(dv.sm)
	{
		if(dv.cs==v::csp::t)return 2300;
		else if(dv.cs==v::csp::m)return 1700;
		else if(dv.cs==v::csp::d)return 500;
	}
	else if(dv.vv&&!dv.n)
	{
		double m[5]={2000,1000,2000,2000,700};
		return m[(int)dv.vv];
	}
	else if(dv.nt&&dv.cs==v::csp::o)return 1000;
	return 0;
}
std::vector<std::basic_string<unsigned char>> ss={{1,1,1,1},{}};
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
		write(ss,&s,1);
	}
}
void k(int p)
{
	SDL_Init(SDL_INIT_AUDIO);
	bool ck=1;
	int yk=0;
	std::vector<unsigned char> nv;
	auto vk=[&ck,&yk,&nv]()
	{
		struct vyp
		{
			vyp(size_t kd):mc(kd){mc.k[0]=0;}
			::ck<float> mc;
			size_t d=0,u=1;
			bool v=0;
		};
		auto pc=[](void *vy,Uint8 *d,int s)
		{
			auto vyk=((vyp*)vy);
			for(int k=0;k<s;k+=sizeof(float))
			{
				if(vyk->mc.ak(vyk->d,vyk->u)==0)
				{
					if(vyk->v)printf("<");
					*((float*)(d+k))=0;
				}
				else
				{
					*((float*)(d+k))=vyk->mc.k[vyk->d];
					vyk->d=vyk->mc.v(vyk->d);
				}
			}
		};
		GS::VTM::VocalTractModel5<double,1> mt;
		vyp vy(mt.outputSampleRate());
		SDL_AudioSpec sn;
		sn.freq=mt.outputSampleRate();
		sn.format=AUDIO_F32;
		sn.samples=1024;
		sn.callback=pc;
		sn.userdata=&vy;
		sn.channels=1;
		auto ys=SDL_OpenAudioDevice(NULL,0,&sn,NULL,0);
		SDL_PauseAudioDevice(ys,0);
		bool ssv=0;
		{char* p=getenv("SSV");if(p)if(p[0]=='1')ssv=1;}
		double ct=0;
		double ms[2][mt.TOTAL_PARAMETERS];
		for(int k=0;k<2;k++)
			for(int pk=0;pk<mt.TOTAL_PARAMETERS;pk++)
				ms[k][pk]=0;
		while(ssv)
		{
			double mk=0.1;
			for(size_t sssk=0;sssk<ss.size();sssk++)
			{
				auto &s=ss[sssk];
				for(size_t vk=0;vk<s.size();vk++)
				{
					const v pv=vc[s[vk]];
					double dm=mk;
					double vd=pv.sv?(pv.sd?dm*2:dm):dm*0.75;
					int gs=std::max(1,(int)(0.004*mt.internalSampleRate()));
					double nk=(double)gs/mt.internalSampleRate();
					int ks=vd/nk;
					for(int k=0;k<ks;k++)
					{
						[[maybe_unused]]auto ps=[k,&ms,nk](int s,double l,double lk,float g)
						{
							int ls=floor(lk/nk);
							if(k>=ls)return;
							if(g==1.0)
								ms[1][s]=ms[0][s]+(l-ms[0][s])/(double)(ls-k);
							else
							{
								double hs=pow(ms[0][s],g);
								double hl=pow(l,g);
								ms[1][s]=pow(hs+(hl-hs)/(double)(ls-k),1/g);
							}
						};
						ms[1][mt.PARAM_GLOT_PITCH]=-7;
						ms[1][mt.PARAM_GLOT_VOL]=60;
						for(int i=mt.PARAM_R1;i<=mt.PARAM_R8;i++)
							ms[1][i]=vm(vc[1],i-mt.PARAM_R1);
						ms[1][mt.PARAM_R6A]=sdvm(vc[1]);
						double ks[mt.TOTAL_PARAMETERS];
						for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
							ks[k]=(ms[1][k]-ms[0][k])/(double)gs;
						for(int dk=0;dk<gs;dk++)
						{
							for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
								mt.setParameter(k,ms[0][k]);
							mt.execSynthesisStep();
							for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
								ms[0][k]+=ks[k];
							for(size_t k=0;k<mt.outputBuffer().size();k++)
							{
								while(vy.mc.ak(vy.d,vy.u)>mk*mt.outputSampleRate())
									std::this_thread::sleep_for(std::chrono::milliseconds(16));
								double tp=mt.outputBuffer()[k];
								ct=std::max(ct,abs(tp));
								vy.mc.k[vy.u]=std::max(std::min(tp/ct,1.0),-1.0);
								vy.u=vy.mc.v(vy.u);
							}
							mt.outputBuffer().resize(0);
						}
						if(0)printf("%d,%lf",k,vd);
					}
				}
			}
			if(!ck)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds((int)(mk*1000.0)));
				break;
			}
			if(0)std::cout<<ct<<std::endl;
		}
		unsigned long k=0;
		while(!ssv)
		{
			while(vy.mc.ak(vy.d,vy.u)<vy.mc.s-1)
			{
				vy.mc.k[vy.u]=sin(2.0*M_PI*100.0*(double)k/1024.0)*0.5;
				vy.u=vy.mc.v(vy.u);
				k++;
			};
			vy.v=1;
			if(ck==0)break;
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
		}
		vy.v=0;
		SDL_PauseAudioDevice(ys,1);
		SDL_CloseAudioDevice(ys);
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
	std::thread vkk(vk); 
	while(ck)
	{
		while(XCheckMaskEvent(d,-1,&g))
		{
			if(g.type==KeyPress)
			{
				auto t=tns(XLookupKeysym(&(g.xkey),1));
				if(yk==0)
				{
					if(t==0)ck=0;
					else if(t==1)
					{
						yk=1;
						nv.resize(0);
					}
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
			}
		}
		ck=ck&ssk(p);
		const int kn=40;
		std::this_thread::sleep_for(std::chrono::milliseconds(kn));
		if(tk>0)tk-=kn;
	}
	vkk.join();
	XUngrabKey(d,AnyKey,AnyModifier,DefaultRootWindow(d));
	SDL_Quit();
}
int main(int argc,char** argv)
{
	if(argc<2)
		printf("0|1?\n");
	else if(argv[1][0]=='3')
		k(0);
	else if(argv[1][0]=='2')
	{
		GS::VTM::VocalTractModel5<double,1> mt;
		while(mt.outputBuffer().size()==0)
			mt.execSynthesisStep();
		printf("%lf,%lf,%lu\n",mt.internalSampleRate(),mt.outputSampleRate(),mt.outputBuffer().size());
		bck<int> k(2,3);
		k.d(0,0)=1;
		for(int i=0;i<2*3;i++)
			printf("%d,",k.k[i]);
		printf("\n");
	}
	else es(k,argv[1][0]!='0');
	return 0;
}
