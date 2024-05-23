#include"st.h"
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<chrono>
#include<random>
#ifdef CP
#include<cairo.h>
#endif
#ifndef EMSCRIPTEN
bool jt=0;
#else
#include<emscripten.h>
bool jt=1;
#endif
void lck()
{
	int v1,v2;
	SDL_QueryTexture(st.lns,0,0,&v1,&v2);
	bool dp=!(st.tpp.v1>st.tpp.v2);
	for(int k=0;k<st.tl.size()+1;k++)
	{
		int ds1=dp?(st.tpp.s1-st.tpp.p1)/2:1;
		int v=st.tpp.s1-ds1*2;
		int dv=(st.tpp.s2-2)/2-(dp?8:0);
		int pk=k-fmax(0,(ceil((float)(st.tl.size()+1)/(float)v)-dv))*v;
		if(pk<0)continue;
		SDL_Rect ls,ss;
		ls=st.tpp.ps(ds1+pk%v,1+(pk/v)*2,1,2);
		if(0)printf("%d %d %d %d\n",ls.x,ls.y,ls.w,ls.h);
		ss=SDL_Rect({.x=((st.tl[k])*st.tpp.g)%v1,.y=(((st.tl[k])*st.tpp.g)/v1)*2*st.tpp.g,.w=st.tpp.g,.h=2*st.tpp.g});
		if(k<st.tl.size())SDL_RenderCopy(st.ck,st.lns,&ss,&ls);
		else 
		{
			SDL_SetRenderDrawColor(st.ck,255,255,255,255);
			SDL_RenderFillRect(st.ck,&ls);
		}
	}
}
stp st;
#ifdef EMSCRIPTEN
struct
{
	int operator()()
	{
		return EM_ASM_INT({return vkn();});
	}
	bool p()
	{
		if((*this)()!=st.s){st.s=(*this)();return 1;}
		return 0;
	}
}clk;
#endif
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
	bool ds=st.s1<21;
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
		if(0&&ms1>7)
		{
			printf("ms1 %f s1 %f d1*0.5 %f\n",ms1,s1,d1*0.5);
		}
		return s1>=ms1-d1*0.5&&s1<ms1+d1*0.5&&s2>=ms2-d2*0.5&&s2<ms2+d2*0.5;
	}
};
SDL_Rect smp(float d1,float d2,float v1,float v2)
{
	return SDL_Rect({.x=(int)(st.pd.x+d1*(float)st.sp1*(float)st.g),.y=(int)(st.pd.y+d2*(float)st.sp2*(float)st.g),.w=(int)(v1*(float)st.sp1*(float)st.g),.h=(int)(v2*(float)st.sp2*(float)st.g)});
}
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
	if(0)printf("ncpk\n");
	Uint8 vn=st.ks?255:0;
	SDL_SetRenderDrawColor(st.ck,vn,vn,vn,255);
	SDL_RenderClear(st.ck);
	if(st.clvp)
	{
		SDL_SetTextureBlendMode(st.lns,!st.ks?SDL_BLENDMODE_BLEND:SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_REV_SUBTRACT,SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_ADD));
		st.clvp=0;
	}
	if(st.cs&&sr>3)
	{
		SDL_RenderCopy(st.ck,st.nkk?st.mc1:st.mc2,NULL,&st.pd);
		if(!st.cc&&st.dp.d)
		{
			int v1,v2;
			SDL_QueryTexture(st.lns,0,0,&v1,&v2);
			int v=st.dp.v;
			int dv=st.dp.dv;
			std::string l;
			[[maybe_unused]]auto np=[&l,v]()
			{
				while(l.size()%v)l=l+' ';
			};
			const bool lns=1;
			[[maybe_unused]]auto lj=[&l,v,dv,&np](std::string j)
			{
				if(j.size()+(l.size()%v)<=v&&(l.size()+j.size()+lns)<=dv*v)
					l+=j;
				else if(l.size()<=(dv-1)*v){np();l+=j;}
			};
			[[maybe_unused]]auto k=std::chrono::system_clock::now();
			for(int k=0;k<v;k++)l+="-";
			if(0){lj("1:235|");lj("2:08|");lj("3:54|");lj("4:096|");}
			for(auto v:st.vs)
				lj(v);
			std::mt19937 spm;
			std::uniform_int_distribution<int> spd(0,150);
			if(0)for(int k=0;k<450;k++)lj(std::to_string(k+5)+":"+std::to_string(spd(spm))+"|");
			if(!st.ptc)for(int k=0;k<l.size()+1;k++)
			{
				int pk=k-fmax(0,(ceil((float)(l.size()+lns)/(float)v)-dv))*v;
				if(pk<0)continue;
				SDL_Rect ls,ss;
				ls=smp((mss<1>(14)>mss<1>(5)?(mss<0>(5)-0.5):1.0)+0.5*(pk%(int)v),1.0+floor(pk/v),0.5,1);
				ss=SDL_Rect({.x=((l[k])*4*st.g)%v1,.y=(((l[k])*4*st.g)/v1)*8*st.g,.w=4*st.g,.h=8*st.g});
				if(k<l.size())SDL_RenderCopy(st.ck,st.lns,&ss,&ls);
				else if(lns) 
				{
					SDL_SetRenderDrawColor(st.ck,st.ks?0:255,st.ks?0:255,st.ks?0:255,255);
					SDL_RenderFillRect(st.ck,&ls);
				}
			}
			else
			{
				auto dp=tmt_screen(st.dps);
				auto lss=tmt_cursor(st.dps);
				for(size_t k=0;k<dp->nline;k++)
					if(dp->lines[k]->dirty||1)
						for(size_t pk=0;pk<dp->ncol;pk++)
						{
							const auto g=st.dp.g;
							SDL_Rect ls=smp((mss<1>(14)>mss<1>(5)?(mss<0>(5)-0.5):1.0)+0.5*(pk)*g,1.0+k*g,0.5*g,g);
							char l=dp->lines[k]->chars[pk].c;
							SDL_Rect ss=SDL_Rect({.x=(l*4*st.g)%v1,.y=((l*4*st.g)/v1)*8*st.g,.w=4*st.g,.h=8*st.g});
							SDL_RenderCopy(st.ck,st.lns,&ss,&ls);
							if(k==lss->r&&pk==lss->c)
							{
								unsigned r=255,h=255,n=255;
								SDL_SetRenderDrawColor(st.ck,st.ks?255-r:r,st.ks?255-h:h,st.ks?255-n:n,255);
								SDL_SetRenderDrawBlendMode(st.ck,SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_SUBTRACT,SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_ADD));
								SDL_RenderFillRect(st.ck,&ls);
								SDL_SetRenderDrawBlendMode(st.ck,SDL_BLENDMODE_BLEND);
							}
						}
				tmt_clean(st.dps);
			}
		}
		if(st.vtp)lck();
		if(0)SDL_RenderCopy(st.ck,st.lns,NULL,NULL);
		if(0)printf("tl %s\n",SDL_GetError());
		if(!st.cc)
		{
			if(0)
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
			}
			if(0)
			{
				SDL_SetRenderDrawColor(st.ck,0,0,255,100);
				SDL_RenderDrawRect(st.ck,&st.pd);
			}
		}
		if(st.rrs1>=0)
		{
			SDL_SetRenderDrawColor(st.ck,255,0,0,100);
			SDL_RenderDrawLine(st.ck,st.rrs1,st.pd.y,st.rrs1,st.pd.h+st.pd.y);
			SDL_RenderDrawLine(st.ck,st.pd.x,st.rrs2,st.pd.w+st.pd.x,st.rrs2);
			std::array<int,3> s={2,-1,-3};
			if(0)for(auto n:s)
				SDL_RenderDrawLine(st.ck,st.rrs1+n,st.rrs2-st.g*3,st.rrs1+n,st.rrs2+st.g*3);
		}
	}
}
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
struct cbl
{
	int d1=0,d2=0,v1=0,v2=0;
	unsigned char rm=255,hm=255,nm=255;
	void operator()()
	{
		for(int k2=0;k2<v2;k2++)
		{
			for(int k1=0;k1<v1;k1++)
			{
				int s=(d2+k2)*st.cns+(d1+k1)*3;
				st.cn[s]=st.ks?255-rm:rm;
				st.cn[s+1]=st.ks?255-hm:hm;
				st.cn[s+2]=st.ks?255-nm:nm;
			}
		}
	}
};
int nspk(int n)
{
	if(n==5)
		return 14;
	else if(n>=6&&n<=14)
		return n-1;
	else return n;
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
	if(!st.cc&&st.ksns)
	{
		const int pns=9;
		size_t pn=st.ksn;
		for(int k=0;(k<pns)||k==0;k++,pn/=10)
		{
			float p1=float(st.s1)*(float)0.5+(float)pns*(float)0.5-(float)k-(float)1.0;
			float p2=mss<1>(5)-2.5;
			cbl({.d1=(int)(p1*st.sp1),.d2=(int)(p2*st.sp2),.v1=8,.v2=8,.rm=100,.hm=30,.nm=30})();
			cbl({.d1=(int)(p1*st.sp1)+1,.d2=(int)(p2*st.sp2)+7,.v1=6,.v2=1,.rm=180,.hm=120,.nm=50})();
			nl({.n=(int)(pn%10)+50,.p1=p1,.p2=p2})();
		}
	}
	if(0)for(int k=1;k<st.s1-1;k++)ns(10,k,2);
	int l2=st.s2-4;
	if(st.tp&&!st.vtp)
	{
		unsigned char prm=70,phm=70,pnm=90;
		int vk=0.5*st.sp1;
		if(0)cbl({.d1=(int)((mss<0>(5)-1.5)*st.sp1)+vk,.d2=(int)((mss<1>(5)-1.5)*st.sp2)+vk,
			.v1=(int)((mss<0>(14)-mss<0>(5)+3)*st.sp1)-vk*2,.v2=(int)((mss<1>(14)-mss<1>(5)+3)*st.sp2)-vk*2,
			.rm=prm,.hm=phm,.nm=pnm})();
		if(mss<1>(14)>mss<1>(5))
		{
			if(0)for(int k=0;k<4;k++)
				nl({.n=50,.p1=mss<0>(5)+(float)(0.5+2.0*k),.p2=mss<1>(5)+(float)0.5,.v=1})();
		}
		else if(0)
		{
			int ng=4;
			cbl({.d1=4,.d2=(int)(mss<1>(5)-0.5)*st.sp2+3,.v1=(int)((mss<0>(5)-1.5)*st.sp1)+ng-4,.v2=2,.rm=255,.hm=255,.nm=255})();
			cbl({.d1=(int)((mss<0>(14)+1.5)*st.sp1)-ng,.d2=(int)(mss<1>(5)-0.5)*st.sp2+3,.v1=(int)((mss<0>(5)-1.5)*st.sp1)+ng-4,.v2=2,.rm=255,.hm=255,.nm=255})();
		}
		for(int i=st.dn?0:5;i<15;i++)
		{
			const unsigned char m=st.cc?255:255;
			int ms1=(int)(mss<0>(nspk(i))*st.sp1);
			int ms2=(int)(mss<1>(nspk(i))*st.sp2);
			bool d=(i==0?false:!((st.tr.p==1||st.tr.p==2)&&st.tr.n==i));
			if(0&&!d)printf("!d %d\n",i);
			unsigned char cbv=d?255:0;
			const int vk=3;
			cbl({.d1=ms1-4-vk,.d2=ms2-4-vk,.v1=8+2*vk,.v2=8+2*vk,.rm=cbv,.hm=cbv,.nm=cbv})();
			if(d)cbl({.d1=ms1-4,.d2=ms2-4,.v1=8,.v2=8,.rm=0,.hm=0,.nm=0})();
			nl({.n=(i<5?i+11:i-5+50),.p1=mss<0>(nspk(i))-(float)0.5,.p2=mss<1>(nspk(i))-(float)0.5,
					.v=d,.rm=m,.hm=m,.nm=m})();
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
	if(0)
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
void lnss(int v1,int v2)
{
	TTF_Init();
	auto lns=TTF_OpenFont("kv.ttf",7);
	TTF_SetFontHinting(lns,4);
	TTF_SetFontKerning(lns,0);
	if(st.lns)SDL_DestroyTexture(st.lns);
	int n=-1,c=-1;
	int d1,d2,d3;
	while(n+1!=c)
	{
		int s=v2;
		if(n!=-1&&c!=-1)s=(n+c)/2;
		else if(n!=-1)s=n*2;
		else if(c!=-1)s=c/2;
		TTF_SetFontSize(lns,s);
		TTF_SizeUTF8(lns,"\xe2\x96\x88",&d1,&d2);
		d3=TTF_FontLineSkip(lns);
		if(0)printf("s %d d1 %d d2 %d ppn %d pn %d\n",s,d1,d2,TTF_FontHeight(lns),d3);
		d2=d3;
		if(0)printf("tl %s\n",SDL_GetError());
		if(d1<=v1&&d2<=v2)
			n=s;
		else c=s;
	}
	if(0)printf("d1 %d|%d d2 %d|%d\n",d1,v1,d2,v2);
	TTF_SetFontSize(lns,n);
	if(0)printf("n %d v2 %d sp %d\n",n,v2,TTF_FontHeight(lns));
	TTF_SetFontHinting(lns,3);
	int pv1,pv2,ptk;
	if(1)
	{
		int kp=st.ns*v1*v2;
		ptk=sqrt(kp)/v1;
		pv1=ptk*v1;
		int dtk=(st.ns+ptk-1)/ptk;
		pv2=dtk*v2;
	}
	auto sl=SDL_CreateRGBSurfaceWithFormat(0,pv1,pv2,24,SDL_PIXELFORMAT_RGB24);
	d1=0;d2=0;
	for(int k=1;k<st.ns;k++)
	{
		char l[2];
		l[1]=0;
		*(unsigned char*)(l)=k;
		auto vbl=TTF_RenderText_Blended(lns,l,SDL_Color({255,255,255}));
		SDL_Rect ms;
		ms.w=vbl->w;
		if(ms.w>v1)ms.w=v1;
		ms.h=vbl->h;
		if(ms.h>v2)ms.h=v2;
		ms.x=(v1-ms.w)/2;
		ms.y=(v2-ms.h)/2;
		SDL_Rect ss=ms;
		ss.x+=(k%ptk)*v1;
		ss.y+=(k/ptk)*v2;
		if(ss.w!=d1||ss.h!=d2)
		{
			d1=ss.w;
			d2=ss.h;
			if(0)printf("d1 %d d2 %d | %d,%d\n",d1,d2,v1,v2);
		}
		SDL_BlitSurface(vbl,&ms,sl,&ss);
		SDL_FreeSurface(vbl);
	}
	st.lns=SDL_CreateTextureFromSurface(st.ck,sl);
	SDL_FreeSurface(sl);
	TTF_CloseFont(lns);
	TTF_Quit();
}
void mk()
{
	int x1,x2;
	SDL_GetWindowSize(st.cp,&x1,&x2);
	st.clp.v1=x1;st.clp.v2=x2;
	if(0)printf("mk %d %d\n",x1,x2);
#ifdef EMSCRIPTEN
	if(clk()==1)
	{
		st.clp.ss(&st);
		return;
	}
#endif
	st.tr.p=0;
	if(st.mc1)SDL_DestroyTexture(st.mc1);
	if(st.mc2)SDL_DestroyTexture(st.mc2);
	if(st.vc)SDL_DestroyTexture(st.vc);
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
	st.tpp.v1=x1;st.tpp.v2=x2;
	st.tpp.ss();
	if(1)lnss(4*st.g,8*st.g);
	if(0)lnss(st.tpp.g,st.tpp.g*2);
	st.dp.v=(mss<1>(14)>mss<1>(5)?(mss<0>(14)-mss<0>(5)+1.0):st.s1-2)*2.0;
	st.dp.dv=mss<1>(5)-2.5-2*st.ksns;
	st.dp.g=1;
	if(mss<1>(14)>mss<1>(5))
	{
		st.dp.g=0.5;
		st.dp.v*=2;
		st.dp.dv*=2;
	}
	tmt_resize(st.dps,st.dp.dv,st.dp.v);
	if(0)printf("dp %dx%d\n",st.dp.v,st.dp.dv);
	st.plg=1;
}
#ifdef EMSCRIPTEN
extern "C"
{
void EMSCRIPTEN_KEEPALIVE dplk(int p)
{
	static int k;
	if(0)printf("p %d\n",p);
	char s=p;
	if(k<30||1)tmt_write(st.dps,&s,1);
	k++;
}
void EMSCRIPTEN_KEEPALIVE pp(int x1,int x2)
{
	SDL_SetWindowSize(st.cp,x1,x2);
	mk();
}
}
#endif
void (*npk)(int)=0;
int sr=0;
void kplt(int n)
{
	auto tk=[](int n)->char
	{
		if(0)printf("tk %d\n",n);
		if(n%10==9)return 0;
		else if(n/10==98)
		{
			return 32+81+7+n%10;
		}
		else if(n==97)
		{
			st.vtp=0;
			return 0;
		}
		else
		{
			return 32+(n/10)*9+n%10;
		}
		return 0;
	};
	if(n>4)
	{
		char p=0;
		if(0)printf("kplt %d\n",n);
		if(st.pt1==-1)
		{
			st.pt1=n-5;
			st.pt2=-1;
		}
		else if(st.pt1==9)
		{
			if(st.pt2==-1)
			{
				if(n-5==8)
					st.pt2=n-5;
				else
				{
					p=tk(st.pt1*10+n-5);
					st.pt1=-1;
				}
			}
			else
			{
				p=tk(st.pt1*100+st.pt2*10+n-5);
				st.pt1=-1;
			}
		}
		else	
		{
			p=tk(st.pt1*10+n-5);
			st.pt1=-1;
		}
		char dp[2];
		dp[0]=p;
		dp[1]=0;
		st.tl+=std::string(dp);
		if(0)printf("kplt %c %s\n",p,st.tl.c_str());
	}	
}
void nk()
{
#ifdef EMSCRIPTEN
	if(0)EM_ASM({let sk=Date.now();if(sk-kg>17)console.log(sk-kg);kg=sk;});
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
		if(st.clp.v1!=nm1||st.clp.v2!=nm2||x1!=nm1||x2!=nm2)
		{
			EM_ASM({cp.width=vpv1;cp.height=vpv2;});
			if(0)printf("kp %d %d\n",nm1,nm2);
			if(1)pp(nm1,nm2);
		}
	}
	if(clk.p())mk();
	if(clk()==1)
	{
		st.clp.nk(&st);
		return;
	}
#endif
	static double k;
	SDL_Event g;
	const int tpss=25;
	static char tps[tpss];
	auto tpm=[](){memset(tps,0,tpss);};
	bool nkn=0;
	if(st.tr.ptps)
	{
		if(st.tr.p==2)st.tr.p=0;
		st.plg=1;
		st.tr.ptps=0;
	}
	while(SDL_PollEvent(&g))
	{
		auto ss=[](int s1,int s2)->int
		{
			float ss1=(double)(s1-st.pd.x)/((double)st.pd.w/(double)(st.s1*st.sp1));
			float ss2=(double)(s2-st.pd.y)/((double)st.pd.h/(double)(st.s2*st.sp2));
			if(0)
			{
				if(0)printf("%d %d\n",(s1-st.pd.x)/st.g,(s2-st.pd.y)/st.g);
				st.rrs1=s1;
				st.rrs2=s2;
				st.plg=1;
				printf("%f %f g %d\n",ss1,ss2,st.g);
			}
			for(int k=st.dn?1:5;k<15;k++)
				if(nsk({.ms1=mss<0>(nspk(k)),.ms2=mss<1>(nspk(k)),.d1=(float)(st.sg?2:3),.d2=(float)(st.sg?2:2)})(ss1/st.sp1,ss2/st.sp2))return k;
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
			if(g.key.keysym.sym==SDLK_RETURN&&st.vtp)
			{
				char *p=0;
#ifdef EMSCRIPTEN
				if(st.tl.size()-st.tlv>0)p=(char*)EM_ASM_PTR({let p="";try{p=eval(UTF8ToString($0)).toString()}catch(v){p=v.toString()}return stringToNewUTF8(p)},st.tl.substr(st.tlv).c_str());
				if(0)printf("%s\n",p);
#endif
				st.tl+=std::string(" ")+std::string(p)+std::string(" ");
				st.tlv=st.tl.size();
				if(p)free(p);
				st.plg=1;
			}
			if(g.key.keysym.sym==SDLK_BACKSPACE&&st.vtp)
			{
				if(st.tl.size()>st.tlv)st.tl.pop_back();
				st.plg=1;
			}
			if(g.key.keysym.sym==SDLK_ESCAPE&&!jt)
			{
				st.cs=0;
				st.tr.p=0;
				st.plg=1;
				npk(5+10);
			}
			if(g.key.keysym.sym==SDLK_ESCAPE&&st.vtp)
			{
				st.tr.p=0;
				st.tr.n=0;
				st.tr.k=0;
				st.tr.s=0;
				st.vtp=0;
				st.plg=1;
			}
			int n=ts();
			if(st.dp.d&&st.ptc&&!(n>=15&&n<25))
			{
#ifdef EMSCRIPTEN
				char *s=(char*)"0";
				auto p=g.key.keysym.sym;
				s[0]=0;
				if(!(p&SDLK_SCANCODE_MASK)&&p<127)
					s[0]=p;
				if((tk==KMOD_LCTRL||tk==KMOD_RCTRL)&&s[0]>='a'&&s[0]<='z')
					s[0]=s[0]-'a'+1;
				else if(s[0]&&(tk==KMOD_LSHIFT||tk==KMOD_RSHIFT))
				{
					if(s[0]>='a'&&s[0]<='z')
						s[0]=s[0]-'a'+'A';
					else if(s[0]>='0'&&s[0]<='9')
					{
						const char pv[]=")!@#$%^&*(";
						s[0]=pv[s[0]-'0'];
					}
					else
					{
						std::string cs="`-=[]\\;',./";
						auto ss=cs.find(s[0]);
						if(ss!=std::string::npos)
						{
							const char pv[]="~_+{}|:\"<>?";
							s[0]=pv[ss];
						}
					}
				}
				else if(p==SDLK_DELETE)
					s=(char*)TMT_KEY_DELETE;
				else if(p==SDLK_TAB&&(tk==KMOD_LSHIFT||tk==KMOD_RSHIFT))
					s=(char*)TMT_KEY_BACK_TAB;
				else if(p==SDLK_UP)
					s=(char*)TMT_KEY_UP;
				else if(p==SDLK_DOWN)
					s=(char*)TMT_KEY_DOWN;
				else if(p==SDLK_LEFT)
					s=(char*)TMT_KEY_LEFT;
				else if(p==SDLK_RIGHT)
					s=(char*)TMT_KEY_RIGHT;
				EM_ASM({ptc.serial0_send(UTF8ToString($0));},s);
#endif
			}
			if(0&&n==0)printf("ktnj\n");
			if(tps[n]==0)
			{
				tps[n]=1;
				if(st.dp.d&&st.ptc&&n>=1&&n<15)n=0;
				if(n>14)n-=10;
				if(n>0&&n<15&&!st.vtp)
				{
					st.tr.p=1;
					st.tr.n=n;
					st.tr.k=0;
					st.tr.s=0;
				}
			}
		}
		if(g.type==SDL_MOUSEBUTTONUP)
		{
			if(0&&nkn)printf("plgp\n");
			if(st.tr.p==2)
			{
				if(!nkn)
				{
					st.tr.p=0;
					st.plg=1;
				}
				else
				{
					st.tr.ptps=1;
				}
			}
		}
		if(g.type==SDL_MOUSEBUTTONDOWN)
			if(st.tr.p!=1)
			{
				nkn=1;
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
			if(st.tr.p==2&&ss(g.motion.x,g.motion.y)!=st.tr.n)
			{
				st.tr.p=0;
				st.plg=1;
			}
		if(g.type==SDL_TEXTINPUT)
		{
			if(st.vtp)
			{
				st.tl+=std::string(g.edit.text);
				if(0)printf("ll %s\n",st.tl.c_str());
				st.plg=1;
			}
		}
	}
	if(0)if(nkn&&st.tr.p!=2)printf("nknns\n");
	if(st.plg)
	{
		const char *p=SDL_GetError();
		if(0&&p)printf("%s\n",p);
	}
	double sk=(double)SDL_GetTicks()/1000.0;
	if((unsigned int)sk!=st.ksn)
	{
		if(0)st.plg=1;
		st.ksn=sk;
	}
	st.tr.k+=sk-k;
	k=sk;
	if(st.tr.p==1||st.tr.p==2)
	{
		const double dk=.25;
		if(st.tr.s==0||(st.tr.n<5&&((st.tr.k-dk)/0.05>st.tr.s-1)))
		{
			st.plg=1;
			if(st.tr.s==0||st.tr.n<5)st.tr.s++;
			if(!st.vtp)npk(st.tr.n);
			else kplt(st.tr.n);
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
void dppk(tmt_msg_t d,TMT* dp,const void *pt,void*)
{
	if(d==TMT_MSG_UPDATE||d==TMT_MSG_MOVED)
	{
		st.plg=1;
		tmt_clean(st.dps);
		if(0)ncpk();
	}
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
	SDL_SetRenderDrawBlendMode(st.ck,SDL_BLENDMODE_BLEND);
	st.dps=tmt_open(8,8,dppk,0,0);
	if(0)
	{
		auto tkc=IMG_Load("pmc.jpg");
		st.lc=SDL_CreateRGBSurfaceWithFormat(0,tkc->w,tkc->h,24,SDL_PIXELFORMAT_RGB24);
		SDL_BlitSurface(tkc,NULL,st.lc,NULL);
		SDL_FreeSurface(tkc);
	}
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
		if(st.lns)SDL_DestroyTexture(st.lns);
		SDL_Quit();
		tmt_close(st.dps);
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
void clpp::ss(stp* tp)
{
	if(v1==0||v2==0)return;
	if(v1>v2){g=v2/p2;s1=p1;s2=p1;}
	else {g=std::min(v1/(p1+2),v2/(p1*4/3));s1=p1;s2=p1;}
	pps.w=s1*g;
	pps.h=s2*g;
	pps.x=(v1-pps.w)/2;
	pps.y=(v2-pps.h)/2;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
	p.s(SDL_CreateTexture(tp->ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_TARGET,tg*s1,tg*s2));
	SDL_SetRenderTarget(tp->ck,p.p());
	SDL_SetRenderDrawColor(tp->ck,200,200,150,255);
	SDL_Rect n;
	n.x=0;n.y=0;n.w=s1*tg;n.h=s2*tg;
	SDL_RenderFillRect(tp->ck,&n);
	SDL_SetRenderTarget(tp->ck,NULL);
	pk(tp);
	if(0)printf("clpss\n");
}
void clpp::nk(stp* tp,bool pl)
{
#ifdef EMSCRIPTEN
	int ns1=EM_ASM_INT({return svsg.s1});
	int ns2=EM_ASM_INT({return svsg.s2});
	bool nsk=EM_ASM_INT({return svsg.k});
	SDL_Point n;
	n.x=ns1;
	n.y=ns2;
	SDL_Point s;
	s.x=ss1;
	s.y=ss2;
	if(sk&&nsk)
	{
		SDL_SetRenderTarget(tp->ck,p.p());
		SDL_SetRenderDrawColor(tp->ck,0,0,0,255);
		SDL_RenderDrawLine(tp->ck,(ss1-pps.x)*tg/g,(ss2-pps.y)*tg/g,(ns1-pps.x)*tg/g,(ns2-pps.y)*tg/g);
		SDL_SetRenderTarget(tp->ck,NULL);
		pk(tp);
	}
	ss1=ns1;ss2=ns2;
	sk=nsk;
#endif
}
void clpp::pk(stp* tp)
{
	if(0)printf("clppp\n");
	SDL_SetRenderDrawColor(tp->ck,0,0,0,255);
	SDL_RenderClear(tp->ck);
	SDL_RenderCopy(tp->ck,p.p(),NULL,&pps);
	SDL_SetRenderDrawColor(tp->ck,255,0,0,255);
	if(0)SDL_RenderDrawRect(tp->ck,&pps);
	SDL_RenderPresent(tp->ck);
}
void pvvk::ksn::operator()()
{
	const int dc=2;
	for(int d=0;d<4;d++)
	{
		[[maybe_unused]]auto ds=[]()
		{
		};
		for(auto tk=0;tk<ts;tk++)
		{
			for(auto k=0;k<ppks;k++)
			{
				for(int bk=0;bk<(k==ppks-1?2:1);bk++)
					(*pk)(std::make_pair<std::array<int,3>,std::array<int,3>>({0,0,ts*(kc+1)+dc},{0,0,ts*(kc+1)+dc+kc}),nv);
			}
		}
	}
} 
