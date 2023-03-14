#pragma once
#include<SDL.h>
#include"nc.xbm"
const int cls=nc_width;
struct st
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
struct nl
{
	st& st;
	int n=0;
	float p1=0,p2=0;
	bool v=0;
	unsigned char rm=255,hm=255,nm=255;
	void operator()()
	{
		int s1=round(p1*st.sp1);
		int s2=round(p2*st.sp2);
		for(int x2=0;x2<st.sp2;x2++)
		{
			unsigned char c=nc_bits[(n/(cls/st.sp1))*(cls/st.sp1)*st.sp2+x2*(cls/st.sp1)+(n%(cls/st.sp1))];
			if(nc_bits[0]==255)c=255-c;
			if(v)c=255-c;
			for(int x1=0;x1<st.sp1;x1++)
			{
				if(c&(1<<x1))
				{
					int s=(s2+x2)*st.cns+(s1+x1)*3;
					st.cn[s]=st.ks?255-rm:rm;
					st.cn[s+1]=st.ks?255-hm:hm;
					st.cn[s+2]=st.ks?255-nm:nm;
				}
			}
		}
	}
};
