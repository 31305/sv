#pragma once
#include<SDL.h>
#include"nc.xbm"
const int cls=nc_width;
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
	bool tp=0;
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
