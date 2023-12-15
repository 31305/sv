#include"st.h"
#ifdef CP
#include<cairo.h>
#endif
#ifndef EMSCRIPTEN
bool jt=0;
#else
#include<emscripten.h>
bool jt=1;
#endif
stp st;
void nl::operator()()
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
template<int d>
float mss(int k)
{
	bool ds=st.s1<20;
	if(d==0)
	{
		float ps=(ds||k<5)?(st.s1-(st.sg?11:15))/2.0:(st.s1-19)/2.0;
		return (ds||k<5)?ps+1+(k%5)*(st.sg?2:3)+0.5:ps+(k-5)*2+0.5;
	}
	else
	{
		float psd=st.pms?(st.s2-7.0)/2.0:ds?st.s2-6:st.s2-4;
		return (ds||k<5)?(float)(psd+(int)((k)/5)*2)+0.5:st.s2-1.5;
	}
}
struct nsk
{
	float ms1,ms2,d1=1,d2=1;
	bool operator()(float s1,float s2)
	{
		return abs(ms1-s1)<=d1*0.5&&abs(ms2-s2)<=d2*0.5;
	}
};
void ns(int n,float p1,float p2,bool v=0)
{
	nl({.n=n,.p1=p1,.p2=p2,.v=v})();
}
void cnk(int k,int m1,int m2,float p1,float p2)
{
	for(int x1=0;x1<m1;x1++)
		for(int x2=0;x2<m2;x2++)
		{
			ns(k+x2*(cls/st.sp1)+x1,p1+x1,p2+x2);
		}
}
const int vdv=2;
void ncpk()
{
	Uint8 vn=st.ks?255:0;
	SDL_SetRenderDrawColor(st.ck,vn,vn,vn,255);
	SDL_RenderClear(st.ck);
	if(st.cs&&sr>3)
	{
		SDL_RenderCopy(st.ck,st.nkk?st.mc1:st.mc2,NULL,&st.pd);
		if(!st.cc)
		{
			SDL_Rect vcs;
			vcs.x=st.pd.x+(st.s1*st.sp1/2-vdv*st.sp1)*st.g;
			vcs.y=st.pd.y+((int)(mss<1>(st.dn?0:5)-0.5)*st.sp2/2-vdv*st.sp2)*st.g;
			vcs.w=vdv*st.sp1*st.g;
			vcs.h=vdv*st.sp2*st.g;
			if(st.clvp)
			{
				SDL_SetTextureBlendMode(st.vc,!st.ks?SDL_BLENDMODE_BLEND:SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_REV_SUBTRACT,SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_ADD));
				st.clvp=0;
			}
			SDL_RenderCopyEx(st.ck,st.vc,NULL,&vcs,0,0,(SDL_RendererFlip)(SDL_FLIP_HORIZONTAL|SDL_FLIP_VERTICAL));
			if(0)printf("%d %d %d %d\n",vcs.x,vcs.y,vcs.w,vcs.h);
			vcs.x=st.pd.x+st.s1*st.sp1/2*st.g;
			vcs.y=st.pd.y+((int)(mss<1>(st.dn?0:5)-0.5)*st.sp2/2-vdv*st.sp2)*st.g;
			SDL_RenderCopyEx(st.ck,st.vc,NULL,&vcs,0,0,SDL_FLIP_VERTICAL);
			vcs.x=st.pd.x+st.s1*st.sp1/2*st.g;
			vcs.y=st.pd.y+((int)(mss<1>(st.dn?0:5)-0.5)*st.sp2/2)*st.g;
			SDL_RenderCopyEx(st.ck,st.vc,NULL,&vcs,0,0,SDL_FLIP_NONE);
			vcs.x=st.pd.x+(st.s1*st.sp1/2-vdv*st.sp1)*st.g;
			vcs.y=st.pd.y+((int)(mss<1>(st.dn?0:5)-0.5)*st.sp2/2)*st.g;
			SDL_RenderCopyEx(st.ck,st.vc,NULL,&vcs,0,0,SDL_FLIP_HORIZONTAL);
			if(0)
			{
				SDL_SetRenderDrawColor(st.ck,255,0,0,100);
				SDL_RenderDrawRect(st.ck,&st.pd);
			}
		}
	}
}
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
void vlk(void* c,size_t d1,size_t d2,size_t d,size_t s1,size_t s2,size_t vd,uint8_t r,uint8_t h,uint8_t n)
{
	auto bk=[&](size_t s1,size_t s2,float ns)
	{
		size_t rs=s2*d+s1*3,hs=rs+1,ls=hs+1;
		((uint8_t*)c)[rs]=fmin((uint8_t)(ns*(float)r+(1.0-ns)*(float)(((uint8_t*)c)[rs])),255);
		((uint8_t*)c)[hs]=fmin((uint8_t)(ns*(float)h+(1.0-ns)*(float)(((uint8_t*)c)[hs])),255);
		((uint8_t*)c)[ls]=fmin((uint8_t)(ns*(float)n+(1.0-ns)*(float)(((uint8_t*)c)[ls])),255);
	};
	auto tsm=[&vd](int v1,int v2)->int64_t{return v1*v1+v2*v2-vd*vd;};
	pg tk;
	tk.nv=&tsm;
	tk.tsm=[](void* nv,int v1,int v2)->int64_t{return (*static_cast<decltype(tsm)*>(nv))(v1,v2);};
	tk.v1[0]=vd-1;
	tk.v2[0]=0;
	tk.v1[1]=vd;
	tk.v2[1]=0;
	tk.dk();
	do
	{
		tk.nk();
		for(int k=tk.bs2;k<=tk.bs1;k++)
		{
			bk(s1+k,s2+tk.bs2,k==tk.bs1?tk.b:1);
			bk(s1+tk.bs2,s2+k,k==tk.bs1?tk.b:1);
		}
	}
	while(tk.bs1>tk.bs2);
	return;
}
void lk()
{
	if(0)printf("lk st.tr.p %d st.tr.n %d\n",st.tr.p,st.tr.n);
	SDL_LockTexture(st.mc1,NULL,(void**)&st.cn,&st.cns);
	memset(st.cn,st.ks?255:0,st.s2*st.cns*8);
	if(0)printf("cc %d\n",st.cc);
	if(st.cc)
	{
#ifdef EMSCRIPTEN
		EM_ASM({cl($0,$1,$2,$3);},st.cdp.x,st.cdp.y,st.cdp.w,st.cdp.h);
#endif
	}
	if(0&&!st.pms&&!st.cc)
	{
		for(int pk=0;pk<st.lc->h;pk++)
		{
			int ms=st.lc->w%2;
			for(int dk=ms?-1:0;dk<st.lc->w;dk++)
				for(int tk=0;tk<3;tk++)
				{
					unsigned char l=*((unsigned char*)st.lc->pixels+st.lc->pitch*pk+(dk<0?0:dk)*st.lc->format->BytesPerPixel+tk);
					if(st.ks)l=255-l;
					*(st.cn+st.cns*(((int)(mss<1>(st.dn?0:5)-0.5)*st.sp2-st.lc->h)/2+pk)
							+3*(ms+(st.s1*st.sp1-st.lc->w)/2+dk)+tk)=l;
				}
			if(0)memcpy(st.cn+st.cns*((st.s2*st.sp2-st.lc->h)/2+pk)+3*((st.s1*st.sp1-st.lc->w)/2),
					(unsigned char*)st.lc->pixels+st.lc->pitch*pk,st.lc->w*3);
		}
	}
	if(0)for(int k=1;k<st.s1-1;k++)ns(10,k,2);
	int l2=st.s2-4;
	if(st.tp)
	{
		for(int i=st.dn?0:5;i<15;i++)
		{
			const unsigned char m=st.cc?255:255;
			nl({.n=(i<5?i+11:i-5),.p1=mss<0>(i)-(float)0.5,.p2=mss<1>(i)-(float)0.5,
					.v=(i==0?false:!((st.tr.p==1||st.tr.p==2)&&st.tr.n==i)),.rm=m,.hm=m,.nm=m})();
		}
		if(0)for(int k=1;k<st.s1-1;k++)ns(10,k,st.s2-7);
		l2-=6;
		if(!st.dn)l2+=2;
	}
	st.l2=l2;
	if(0)vlk(st.cn,st.s1*st.sp1,st.s2*st.sp2,st.cns,100,100,50,255,255,255);
	SDL_UnlockTexture(st.mc1);
	if(!st.nkk)
	{
		SDL_SetRenderTarget(st.ck,st.mc2);
		SDL_RenderCopy(st.ck,st.mc1,NULL,NULL);
		SDL_SetRenderTarget(st.ck,NULL);
	}
	ncpk();
#ifdef EMSCRIPTEN
	EM_ASM({tkccp=sk.getParameter(sk.TEXTURE_BINDING_2D)});
#endif
	if(st.cc&&0)
	{
		SDL_SetRenderDrawColor(st.ck,255,0,0,255);
		SDL_RenderDrawRect(st.ck,&st.cdp);
	}
	if(sr==3)
	{
		sr++;
		st.plg=1;
	}
}
void mk()
{
	st.tr.p=0;
	if(st.mc1)SDL_DestroyTexture(st.mc1);
	if(st.mc2)SDL_DestroyTexture(st.mc2);
	if(st.vc)SDL_DestroyTexture(st.vc);
	int x1,x2;
	SDL_GetWindowSize(st.cp,&x1,&x2);
	if(0)printf("mk %dx%d\n",x1,x2);
	int g=0;
	if(x1>x2)
	{
		st.tp=0;
		if(!st.nkk)
			st.s2=st.p2;
		else
		{
			g=st.nkd?ceil((float)x2/(float)(st.sp2*st.p2)):floor(x2/(st.sp2*st.p2));
			if(g<1)g=1;
			st.s2=x2/(g*st.sp2);
		}
		float d1=((float)x2/(float)(st.s2)*(float)st.sp1/(float)st.sp2);
		st.s1=st.nkk?floor(x1/(g*st.sp1)):ceil((float)x1/d1);
		if(!jt)SDL_ShowCursor(SDL_DISABLE);
	}
	else
	{
		st.tp=1;
		if(!st.nkk)
			st.s1=st.p1;
		else
		{
			g=st.nkd?ceil((float)x1/(float)(st.sp1*st.p1)):floor(x1/(st.sp1*st.p1));
			if(g<1)g=1;
			st.s1=x1/(g*st.sp1);
		}
		float d2=((float)x1/(float)(st.s1)*(float)st.sp2/(float)st.sp1);
		st.s2=st.nkk?floor(x2/(g*st.sp2)):floor((float)x2/d2);
		SDL_ShowCursor(SDL_ENABLE);
	}
	st.tp=1;
	st.g=g;
	if(!st.nkk)
	{
		st.pd.w=x1;
		st.pd.h=st.s2*((float)x1/(float)(st.s1)*(float)st.sp2/(float)st.sp1);
		st.pd.y=x2-st.pd.h;
		st.pd.x=0;
	}
	else
	{
		st.pd.w=st.s1*st.sp1*g;
		st.pd.h=st.s2*st.sp2*g;
		st.pd.x=(x1-st.pd.w)/2;
		st.pd.y=(x2-st.pd.h)/2;
	}
	st.cdp.x=st.pd.x+(mss<0>(5)-0.5)*st.sp1*st.g;
	st.cdp.y=st.pd.y+st.sp2*st.g;
	st.cdp.w=(mss<0>(14)-mss<0>(5)+1)*st.sp1*st.g;
	st.cdp.h=(mss<1>(5)-2.5)*st.sp2*st.g;
	int t2=ceil((float)x1/(float)(st.s1*st.sp1));
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"0");
	st.mc1=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,st.s1*st.sp1,st.s2*st.sp2);
	if(!getenv("NCTV"))SDL_SetTextureScaleMode(st.mc1,SDL_ScaleModeNearest);
	st.mc2=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_TARGET,st.s1*st.sp1*t2,st.s2*st.sp2*t2);
	if(!getenv("NCTV")&&!st.nkk)SDL_SetTextureScaleMode(st.mc2,SDL_ScaleModeLinear);
	st.vc=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,vdv*st.sp1*st.g,vdv*st.sp2*st.g);
	st.clvp=1;
	SDL_LockTexture(st.vc,NULL,(void**)&st.cn,&st.cns);
	memset(st.cn,255,vdv*st.sp1*st.g*st.cns);
	vlk(st.cn,vdv*st.sp1*st.g,vdv*st.sp2*st.g,st.cns,0,0,vdv*st.sp1*st.g/2,0,0,0);
	SDL_UnlockTexture(st.vc);
	st.plg=1;
}
#ifdef EMSCRIPTEN
extern "C"
{
void EMSCRIPTEN_KEEPALIVE pp(int x1,int x2)
{
	SDL_SetWindowSize(st.cp,x1,x2);
	mk();
}
}
#endif
void (*npk)(int)=0;
int sr=0;
void nk()
{
#ifdef EMSCRIPTEN
	if(sr<2)return;
	else if(sr==2)
	{
		if(EM_ASM_INT({return vpv1;})==0)return;
		pmk();
		sr++;
	}
	if(1)
	{
		int x1,x2;
		SDL_GetWindowSize(st.cp,&x1,&x2);
		int nm1=EM_ASM_INT({return vpv1;});
		int nm2=EM_ASM_INT({return vpv2;});
		if(x1!=nm1||x2!=nm2)
		{
			EM_ASM({cp.width=vpv1;cp.height=vpv2;});
			if(0)printf("kp %d %d\n",nm1,nm2);
			if(1)pp(nm1,nm2);
		}
	}
#endif
	static double k;
	SDL_Event g;
	const int tpss=25;
	static char tps[tpss];
	auto tpm=[](){memset(tps,0,tpss);};
	while(SDL_PollEvent(&g))
	{
		auto ss=[](int s1,int s2)->int
		{
			float ss1=((double)(s1-st.pd.x)/(double)st.pd.w*(double)st.s1);
			float ss2=((double)(s2-st.pd.y)/(double)st.pd.h*(double)st.s2);
			for(int k=st.dn?1:5;k<15;k++)
				if(nsk({.ms1=mss<0>(k),.ms2=mss<1>(k),.d1=(float)(st.sg?2:3),.d2=(float)(st.sg?2:2)})(ss1,ss2))return k;
			return -1;
		};
		auto ts=[&g]()
		{
			int n=0;
			if(g.key.keysym.sym==SDLK_DOWN)
				n=4;
			else if(g.key.keysym.sym==SDLK_RIGHT)
				n=2;
			else if(g.key.keysym.sym==SDLK_UP)
				n=3;
			else if(g.key.keysym.sym==SDLK_LEFT)
				n=1;
			else if(g.key.keysym.sym==SDLK_0)
				n=5;
			else if(g.key.keysym.sym==SDLK_1)
				n=6;
			else if(g.key.keysym.sym==SDLK_2)
				n=7;
			else if(g.key.keysym.sym==SDLK_3)
				n=8;
			else if(g.key.keysym.sym==SDLK_4)
				n=9;
			else if(g.key.keysym.sym==SDLK_5)
				n=10;
			else if(g.key.keysym.sym==SDLK_6)
				n=11;
			else if(g.key.keysym.sym==SDLK_7)
				n=12;
			else if(g.key.keysym.sym==SDLK_8)
				n=13;
			else if(g.key.keysym.sym==SDLK_9)
				n=14;
			else if(g.key.keysym.sym==SDLK_KP_0)
				n=15;
			else if(g.key.keysym.sym==SDLK_KP_1)
				n=16;
			else if(g.key.keysym.sym==SDLK_KP_2)
				n=17;
			else if(g.key.keysym.sym==SDLK_KP_3)
				n=18;
			else if(g.key.keysym.sym==SDLK_KP_4)
				n=19;
			else if(g.key.keysym.sym==SDLK_KP_5)
				n=20;
			else if(g.key.keysym.sym==SDLK_KP_6)
				n=21;
			else if(g.key.keysym.sym==SDLK_KP_7)
				n=22;
			else if(g.key.keysym.sym==SDLK_KP_8)
				n=23;
			else if(g.key.keysym.sym==SDLK_KP_9)
				n=24;
			return n;
		};
		if(g.type==SDL_QUIT)
			st.cs=0;
		else if(g.type==SDL_WINDOWEVENT_RESIZED)
			mk();
		else if(g.type==SDL_WINDOWEVENT_FOCUS_LOST)
		{
			tpm();
			st.tr.p=0;
			st.plg=1;
		}
		else if(g.type==SDL_KEYUP)
		{
			if((st.tr.p==1)&&(ts()==st.tr.n||(st.tr.n>4&&ts()==st.tr.n+10)))
			{
				if(0)printf("kpg\n");
				st.tr.p=0;
				st.plg=1;
			}
			tps[ts()]=0;
		}
		else if(g.type==SDL_KEYDOWN)
		{
#ifdef EMSCRIPTEN
			auto tk=SDL_GetModState();
			if((g.key.keysym.sym==SDLK_r&&(tk==KMOD_LCTRL||tk==KMOD_RCTRL))||(g.key.keysym.sym==SDLK_F5&&tk==KMOD_NONE))
					EM_ASM({window.location.reload()});
#endif
			if(g.key.keysym.sym==SDLK_ESCAPE&&!jt)
			{
				st.cs=0;
				st.tr.p=0;
				st.plg=1;
				npk(5+10);
			}
			int n=ts();
			if(tps[n]==0)
			{
				tps[n]=1;
				if(n>14)n-=10;
				if(n>0&&n<15)
				{
					st.tr.p=1;
					st.tr.n=n;
					st.tr.k=0;
					st.tr.s=0;
				}
			}
		}
		if(g.type==SDL_MOUSEBUTTONUP)
			if(st.tr.p==2)
			{
				st.tr.p=0;
				st.plg=1;
			}
		if(g.type==SDL_MOUSEBUTTONDOWN)
			if(st.tr.p==0)
			{
				int n=ss(g.button.x,g.button.y);
				if(0)printf("n %d\n",n);
				if(st.tp&&n>0&&n<15)
				{
					st.tr.p=2;
					st.tr.n=n;
					st.tr.k=0;
					st.tr.s=0;
				}
			}
		if(g.type==SDL_MOUSEMOTION)
			if(st.tr.p==2&&ss(g.button.x,g.button.y)!=st.tr.n)
			{
				st.tr.p=0;
				st.plg=1;
			}
	}
	double sk=(double)SDL_GetTicks()/1000.0;
	st.tr.k+=sk-k;
	k=sk;
	if(st.tr.p==1||st.tr.p==2)
	{
		const double dk=.25;
		if(st.tr.s==0||(st.tr.k-dk)/0.05>st.tr.s-1)
		{
			st.plg=1;
			st.tr.s++;
			npk(st.tr.n);
		}
	}
#ifdef EMSCRIPTEN
	bool cc=EM_ASM_INT({return cc;});
	if(st.cc!=cc){st.cc=cc;st.plg=1;}
	if(st.cc&&st.ks){st.ksps=1;st.ks=0;}
	if(st.ksps&&!st.cc){st.ksps=0;st.ks=1;st.clvp=1;}
	if(st.cc)
	{
		EM_ASM(cpdk());
	}
	bool ccp=EM_ASM_INT({return tvcp;})&&st.cc;
	static int ckg;
	ccp=ccp&&((!ckg&&!EM_ASM_INT({return ccpd.paused}))||st.plg);
	ckg++;
	if(ckg==2)ckg=0;
	bool pplg=st.plg;
	if(st.plg)
	{
		st.plg=0;lk();
		if(!ccp)
			SDL_RenderPresent(st.ck);
	}
	if(ccp)
	{
		if(1)if(!pplg)ncpk();
		SDL_RenderPresent(st.ck);
		SDL_Rect ccvs;
		ccvs.w=EM_ASM_INT({return ccpd.videoWidth;});
		ccvs.h=EM_ASM_INT({return ccpd.videoHeight;});
		if(ccvs.w*st.cdp.h>ccvs.h*st.cdp.w)
		{
			ccvs.h=st.cdp.w*ccvs.h/ccvs.w;
			ccvs.w=st.cdp.w;
		}
		else
		{
			ccvs.w=st.cdp.h*ccvs.w/ccvs.h;
			ccvs.h=st.cdp.h;
		}
		ccvs.x=st.cdp.x+(st.cdp.w-ccvs.w)*0.5;
		ccvs.y=st.cdp.y+(st.cdp.h-ccvs.h)*0.5;
		EM_ASM({ccvs($0,$1,$2,$3)},ccvs.x,ccvs.y,ccvs.w,ccvs.h);
		SDL_GL_SwapWindow(st.cp);
	}
#else
	if(st.plg){st.plg=0;lk();SDL_RenderPresent(st.ck);}
#endif
	npk(-1);
}
int pmk()
{
#ifdef EMSCRIPTEN
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
	jt=1;
	st.cp=SDL_CreateWindow(0,0,0,
			0,
			0,
			SDL_WINDOW_RESIZABLE);
#else
	SDL_ShowCursor(SDL_DISABLE);
	st.cp=SDL_CreateWindow(0,0,0,0,0,SDL_WINDOW_FULLSCREEN_DESKTOP);
#endif
	st.ck=SDL_CreateRenderer(st.cp,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE);
	auto tkc=SDL_LoadBMP("sc.bmp");
	st.lc=SDL_CreateRGBSurfaceWithFormat(0,tkc->w,tkc->h,24,SDL_PIXELFORMAT_RGB24);
	SDL_BlitSurface(tkc,NULL,st.lc,NULL);
#ifdef NKP
	if(0)EM_ASM({console.log('ss '+$0)},(int)st.lc->format->BytesPerPixel);
	if(0)EM_ASM({console.log('vnvkn '+$0)},(int)st.lc->format->Bmask);
	if(st.lc==0)EM_ASM({console.log('nlc')});
#endif
	if(0)
	{
		SDL_GetRenderDriverInfo(0,&st.j);
		for(unsigned int k=0;k<st.j.num_texture_formats;k++)
			printf("%d\n",st.j.texture_formats[k]);
	}
	srand(100);
	mk();
#ifndef EMSCRIPTEN
	while(st.cs)
	{
		nk();
		SDL_Delay(16);
	}
#else
	if(0)EM_ASM({window.addEventListener('resize',r,true);ccp.style.width='100%';});
	if(0)emscripten_set_main_loop(nk,0,0);
#endif
	if(!jt)
	{
		SDL_DestroyRenderer(st.ck);
		SDL_DestroyWindow(st.cp);
		SDL_DestroyTexture(st.mc1);
		SDL_DestroyTexture(st.mc2);
		SDL_DestroyTexture(st.vc);
		SDL_FreeSurface(st.lc);
	}
	return 0;
}
#ifdef CP
void lp()
{
	auto s=cairo_image_surface_create(CAIRO_FORMAT_RGB24,256,256);
	auto p=cairo_create(s);
	cairo_set_source_rgb(p,0,0,0);
	cairo_paint(p);
	cairo_set_source_rgb(p,1,1,1);
	cairo_move_to(p,0,0);
	cairo_line_to(p,50,0);
	cairo_curve_to(p,60,0,60,50,50,50);
	cairo_fill(p);
}
#endif
