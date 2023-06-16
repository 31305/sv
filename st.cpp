#include"st.h"
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
void lk()
{
	SDL_LockTexture(st.mc1,NULL,(void**)&st.cn,&st.cns);
	memset(st.cn,st.ks?255:0,st.s2*st.cns*8);
	if(!st.pms)
	{
		for(int pk=0;pk<st.lc->h;pk++)
		{
			int ms=st.lc->w%2;
			for(int dk=ms?-1:0;dk<st.lc->w;dk++)
				for(int tk=0;tk<3;tk++)
				{
					unsigned char l=*((unsigned char*)st.lc->pixels+st.lc->pitch*pk+(dk<0?0:dk)*st.lc->format->BytesPerPixel+tk);
					if(st.ks)l=255-l;
					*(st.cn+st.cns*((st.s2*st.sp2-(st.dn?6:4)*st.sp2-st.lc->h)/2+pk)+3*(ms+(st.s1*st.sp1-st.lc->w)/2+dk)+tk)=l;
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
			const unsigned char m=255;
			nl({.n=(i<5?i+11:i-5),.p1=mss<0>(i)-(float)0.5,.p2=mss<1>(i)-(float)0.5,
					.v=(i==0?false:!((st.tr.p==1||st.tr.p==2)&&st.tr.n==i)),.rm=m,.hm=m,.nm=m})();
		}
		if(0)for(int k=1;k<st.s1-1;k++)ns(10,k,st.s2-7);
		l2-=6;
		if(!st.dn)l2+=2;
	}
	st.l2=l2;
	SDL_UnlockTexture(st.mc1);
	SDL_SetRenderTarget(st.ck,st.mc2);
	SDL_RenderCopy(st.ck,st.mc1,NULL,NULL);
	SDL_SetRenderTarget(st.ck,NULL);
	Uint8 vn=st.ks?255:0;
    SDL_SetRenderDrawColor(st.ck,vn,vn,vn,255);
	SDL_RenderClear(st.ck);
    SDL_RenderCopy(st.ck,st.mc2,NULL,&st.pd);
	SDL_RenderPresent(st.ck);
}
void mk()
{
	st.tr.p=0;
	if(st.mc1)SDL_DestroyTexture(st.mc1);
	if(st.mc2)SDL_DestroyTexture(st.mc2);
	int x1,x2;
	SDL_GetWindowSize(st.cp,&x1,&x2);
	if(0)printf("%dx%d\n",x1,x2);
	if(x1>x2)
	{
		st.tp=0;
		st.s2=st.p2;
		float d1=((float)x2/(float)(st.s2)*(float)st.sp1/(float)st.sp2);
		st.s1=ceil((float)x1/d1);
		if(!jt)SDL_ShowCursor(SDL_DISABLE);
	}
	else
	{
		st.tp=1;
		st.s1=st.p1;
		float d2=((float)x1/(float)(st.s1)*(float)st.sp2/(float)st.sp1);
		st.s2=floor((float)x2/d2);
		SDL_ShowCursor(SDL_ENABLE);
	}
	st.tp=1;
	st.pd.w=x1;
	st.pd.h=st.s2*((float)x1/(float)(st.s1)*(float)st.sp2/(float)st.sp1);
	st.pd.y=x2-st.pd.h;
	st.pd.x=0;
	int t2=ceil((float)x1/(float)(st.s1*st.sp1));
	st.mc1=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,st.s1*st.sp1,st.s2*st.sp2);
	if(!getenv("NCTV"))SDL_SetTextureScaleMode(st.mc1,SDL_ScaleModeNearest);
	st.mc2=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_TARGET,st.s1*st.sp1*t2,st.s2*st.sp2*t2);
	if(!getenv("NCTV"))SDL_SetTextureScaleMode(st.mc2,SDL_ScaleModeLinear);
	st.plg=1;
}
#ifdef EMSCRIPTEN
extern "C"
{
void EMSCRIPTEN_KEEPALIVE pp(int x1,int x2)
{
	SDL_SetWindowSize(st.cp,x1,x2);
	EM_ASM({canvas.style.width='100vw';
			canvas.style.height='100vh';});
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
		pmk();
		sr=3;
	}
	if(1)
	{
		int x1,x2;
		SDL_GetWindowSize(st.cp,&x1,&x2);
		int nm1=EM_ASM_INT({return v1();});
		int nm2=EM_ASM_INT({return v2();});
		if(nm1!=x1||nm2!=x2)
			pp(nm1,nm2);
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
			if(g.key.keysym.sym==SDLK_ESCAPE)
			{
				st.cs=0;
				st.tr.p=0;
				st.plg=1;
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
				printf("n %d\n",n);
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
		st.plg=1;
		if(st.tr.s==0||(st.tr.k-dk)/0.05>st.tr.s-1)
		{
			st.tr.s++;
			if(npk)npk(st.tr.n);
		}
	}
	if(st.plg){st.plg=0;lk();}
}
int pmk()
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
#ifdef EMSCRIPTEN
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
	if(0)EM_ASM({window.addEventListener('resize',r,true);canvas.style.width='100%';});
	if(0)emscripten_set_main_loop(nk,0,0);
#endif
	if(!jt)
	{
		SDL_DestroyRenderer(st.ck);
		SDL_DestroyWindow(st.cp);
		SDL_DestroyTexture(st.mc1);
		SDL_DestroyTexture(st.mc2);
		SDL_FreeSurface(st.lc);
		SDL_Quit();
	}
	return 0;
}
