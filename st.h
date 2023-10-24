#pragma once
#include<SDL.h>
#include"nc.xbm"
const int cls=nc_width;
struct stp
{
	SDL_Window* cp=0;
	SDL_Renderer* ck;
	SDL_Texture *mc1=NULL,*mc2=NULL;
	SDL_Surface *lc=NULL;
	bool cs=1;
	const int sp1=8,sp2=(nc_height>128)?16:8;
	int s1,s2,l2=1,ps=1;
	SDL_Rect pd;
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
