#pragma once
#include<SDL.h>
extern "C"
{
#include"libtmt/tmt.h"
}
#include"nc.xbm"
const int cls=nc_width;
#include<string>
#include<memory>
#include<vector>
#include<array>
#ifdef EMSCRIPTEN
#include<emscripten.h>
#endif
struct pp
{
	int v1=0,v2=0,g=1,s1=0,s2=0,p1=32,p2=64;
	SDL_Rect pps;
	void ss()
	{
		if(v1>v2)g=v2/p2;
		else g=v1/p1;
		s1=((v1/g)>>1)<<1;
		s2=v2/g;
		pps.w=s1*g;
		pps.h=s2*g;
		pps.x=(v1-pps.w)/2;
		pps.y=(v2-pps.h)/2;
	}
	SDL_Rect ps(int d1,int d2,int v1,int v2)
	{
		return SDL_Rect({.x=pps.x+d1*g,.y=pps.y+d2*g,.w=v1*g,.h=v2*g});
	}
};
struct cnp
{
	std::unique_ptr<SDL_Texture,void(*)(SDL_Texture*)> cpp;
	cnp():cpp(0,SDL_DestroyTexture){}
	SDL_Texture* p(){return cpp.get();};
	void s(SDL_Texture* p){cpp.reset(p);}
}; 
struct stp;
struct clpp
{
	cnp p;
	int v1=0,v2=0,p1=32,p2=64,tg=8,s1=0,s2=0,g=0;
	SDL_Rect pps;
	bool sk=0;
	int ss1=0,ss2=0;
	void ss(stp*);
	void pk(stp*);
	void nk(stp*,bool=0);
};
struct ddp
{
	struct ss
	{
		double pps,tds,kps;
		double sv,kpsv;
		double ds,gs;
		int64_t k;
	};
	struct sg
	{
		bool dsg=0;
		double pps[2],tds[2];
		union
		{
			std::vector<ss> ps;
			std::vector<sg> psg;
		};
	};
	ss ds;
	double vs;
};
struct stp
{
	SDL_Window* cp=0;
	SDL_Renderer* ck;
	SDL_Texture *mc1=NULL,*mc2=NULL,*vc=NULL;
	SDL_Surface *lc=NULL;
	bool cs=1;
	const int sp1=8,sp2=(nc_height>128)?16:8;
	int s1,s2,l2=1,ps=1;
	SDL_Rect pd,cdp;
	unsigned char *cn;
	int cns;
	SDL_RendererInfo j;
	bool tp=1;
	bool vtp=0;
	const bool dn=0;
	const bool sg=1;
	bool pms=0;
	bool nkk=1;
	bool nkd=0;
	int g=0;
	const int p1=sg?11:15,p2=sp2==8?32:24;
	bool plg=1;
	bool cc=0;
	bool ks=([](){char *d=getenv("KS");return !(!d||d[0]=='0');})();
	bool ksps=0;
	bool clvp=0;
	struct
	{
		double k=0;
		int s=0;
		int n=0;
		int p=0;
		bool ptps=0;
	}tr;
	int rrs1=-1,rrs2=-1;
	unsigned int ksn=0;
	bool ksns=0;
	SDL_Texture *lns;
	const int ns=128;
	std::string tl=1?"":[](){std::string s;for(int k=0;k<18*100-1;k++)s.push_back('0'+rand()%10);return s;}();
	std::vector<std::string> vs;
	size_t tlv=0,tps=100;
	int pt1=-1,pt2=-1;
	pp tpp;
	clpp clp;
	int s=0;
	struct
	{
		bool d=0;
		int v,dv;
		float g;	
	}dp;
	bool ptc=1;
	TMT* dps;
	bool ptpr=0;
	struct
	{
		bool ns=0;
	}pttk;
}; 
extern stp st;
extern bool jt;
extern int sr;
struct nl
{
	int n=0;
	float p1=0,p2=0;
	bool v=0;
	unsigned char rm=255,hm=255,nm=255;
	void operator()();
};
int pmk();
void nk();
int pmk();
extern void (*npk)(int);
struct pg
{
	int64_t(*tsm)(void*,int,int);
	void* nv;
	int v1[4],v2[4];
	int ts[4];
	float vk;
	void ss(int k)
	{
		v1[k]=v1[k-1]+v2[k-2]-v2[k-1];
		v2[k]=v2[k-1]+v1[k-1]-v1[k-2];
		ts[k]=tsm(nv,v1[k],v2[k]);
	};
	void bs(int l,int k)
	{
		v1[l]=v1[k];
		v2[l]=v2[k];
		ts[l]=ts[k];
	}
	float sk()
	{
		return (float)ts[0]/(float)(ts[0]-ts[1]);
	}
	void dk()
	{
		ts[0]=tsm(nv,v1[0],v2[0]);
		ts[1]=tsm(nv,v1[1],v2[1]);
		vk=sk();
	}
	float b;
	int bs1,bs2;
	void nk()
	{
		float nvk;
		ss(2);
		bs1=fmin(v1[0],fmin(v1[1],v1[2]));
		bs2=fmin(v2[0],fmin(v2[1],v2[2]));
		if(ts[2]<0)
		{
			bs(0,2);
			nvk=sk();
			b=1.0-0.5*(1.0-vk)*(1.0-nvk);
		}
		else
		{
			ss(3);
			if(ts[3]<0)
			{
				bs(0,3);
				bs(1,2);
				nvk=sk();
				b=0.5*(vk+nvk);
			}
			else
			{
				bs(1,3);
				nvk=sk();
				b=0.5*vk*nvk;
			}
		}
		vk=nvk;
	}
};
struct pvvk
{
	struct ksn
	{
		void(*pk)(std::pair<std::array<int,3>,std::array<int,3>>,void*nv);
		void*nv;
		int ts=4,ppks=3;
		int bkv=1,kv=4,dv=2,kc=4,dc=3,vv=2,vs=1;
		void operator()();
	};
};
