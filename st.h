#pragma once
#include<SDL.h>
#include"nc.xbm"
const int cls=nc_width;
struct stp
{
	SDL_Window* cp;
	SDL_Renderer* ck;
	SDL_Texture *mc1=NULL,*mc2=NULL;
	bool cs=1;
	const int sp1=8,sp2=(nc_height>128)?16:8;
	int s1,s2,l2=1,ps=1;
	const int p1=15,p2=sp2==8?32:24;
	SDL_Rect pd;
	unsigned char *cn;
	int cns;
	SDL_RendererInfo j;
	bool tp=0;
	bool dn=0;
	bool plg=1;
	bool ks=([](){char *d=getenv("KS");return !(!d||d[0]=='0');})();
	struct
	{
		double k=0;
		int s=0;
		int n=0;
		int p=0;
	}tr;
};
extern stp st;
extern bool jt;
extern bool sr;
struct nl
{
	int n=0;
	float p1=0,p2=0;
	bool v=0;
	unsigned char rm=255,hm=255,nm=255;
	void operator()();
};
int pmk();
extern void (*npk)(int);
