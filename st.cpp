#include"st.h"
#include<termios.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_opengles2.h>
#include<chrono>
#include<random>
#include<thread>
#include<csignal>
#include<unistd.h>
#include<iostream>
#include"glm/glm/mat4x4.hpp"
#include"glm/glm/ext/matrix_transform.hpp"
#include"glm/glm/ext/matrix_clip_space.hpp"
#ifdef CP
#include<cairo.h>
#endif
#ifndef EMSCRIPTEN
bool jt=0;
#else
#include<emscripten.h>
#include<emscripten/console.h>
bool jt=1;
#endif
#include<sstream>
#include<fstream>
std::vector<std::string> spl(std::ifstream s)
{
	std::vector<std::string> tp;
	while(!s.eof())
	{
		std::string n;
		std::getline(s,n);
		if(n.size()>0)tp.push_back(n);
	}
	return tp;
}
struct
{
	GLuint vpvv;
	GLuint sgss,tss;
	GLint kss,npss,ts;
	GLint p=0;
	bool rs;
	const GLchar* kck=R"(
precision mediump float;
varying vec2 dts;
varying vec3 dv;
void main()
{
	gl_FragColor=vec4(dts.x*0.1,dts.y*0.1,0,1);
}
)";
	const GLchar* cck=R"(
precision mediump float;
varying vec2 dts;
#define dv 3.14159
float cm(vec3 p,vec3 d,vec3 t)
{
	return abs(atan(dot(cross(d,t),p)/(length(p)*length(d)*length(t)+dot(p,d)*length(t)+dot(p,t)*length(d)+dot(d,t)*length(p))))/dv;
}
void main()
{
	vec3 ms=vec3(dts.x,dts.y,0.0);
	float dg=0.1;
	vec3 p=vec3(0,1,0)-ms;
	vec3 d=vec3(1,1,0)-ms;
	vec3 t=vec3(0,1,dg)-ms;
	float s=cm(p,d,t);
	p=vec3(1,1,dg)-ms;
	s+=cm(p,d,t);
	t=vec3(1,0,dg)-ms;
	s+=cm(p,d,t);
	p=vec3(1,0,0)-ms;
	s+=cm(p,d,t);
	d=vec3(0,0,0)-ms;
	s+=cm(p,d,t);
	p=vec3(0,0,dg)-ms;
	s+=cm(p,d,t);
	t=vec3(0,1,0)-ms;
	s+=cm(p,d,t);
	d=vec3(0,1,dg)-ms;
	s+=cm(p,d,t);
	s=1.0-s;
	gl_FragColor=vec4(s,s,s,1.0);
}
)";
	void rk()
	{
		GLuint bv=glCreateShader(GL_VERTEX_SHADER);
		const GLchar* bvm=R"(
attribute vec3 s;
attribute vec2 ts;
attribute vec3 v;
varying vec3 dv;
varying vec2 dts;
uniform mat4 p;
void main()
{
	dv=v;dts=ts;gl_Position=p*vec4(s,1.0);
})";
		glShaderSource(bv,1,&bvm,0);
		glCompileShader(bv);
		GLuint vv=glCreateShader(GL_FRAGMENT_SHADER);
		[[maybe_unused]]const GLchar* pck="precision mediump float;varying vec2 dts;void main(){float bs=8.0;gl_FragColor=vec4(0.0,0.5*floor(mod(floor(mod((dts.x)*bs,2.0))+floor(mod(1.0+(dts.y)*bs,2.0)),2.0)),0.2,1.0);}";
		glShaderSource(vv,1,&kck,0);
		glCompileShader(vv);
		vpvv=glCreateProgram();
		glAttachShader(vpvv,bv);
		glAttachShader(vpvv,vv);
		glLinkProgram(vpvv);
		kss=glGetAttribLocation(vpvv,"s");
		ts=glGetAttribLocation(vpvv,"ts");
		if(1)npss=glGetUniformLocation(vpvv,"p");
		glGenBuffers(1,&sgss);
		glGenBuffers(1,&tss);
		glBindBuffer(GL_ARRAY_BUFFER,sgss);
		GLfloat ks[]={-1,-1,-1, -1,1,-1, 1,-1,-1, 1,1,-1};
		glBufferData(GL_ARRAY_BUFFER,sizeof(ks),ks,GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER,tss);
		GLfloat tks[]={0,0, 1,0, 0,1, 1,1};
		glBufferData(GL_ARRAY_BUFFER,sizeof(tks),tks,GL_STATIC_DRAW);
		rs=1;
	}
	void pk(int s1,int s2,int v1, int v2)
	{
		if(!rs)rk();
		glGetIntegerv(GL_CURRENT_PROGRAM,&p);
		glViewport(s1,st.clp.v2-s2-v2,v1,v2);
		glUseProgram(vpvv);
		glEnableVertexAttribArray(kss);
		glEnableVertexAttribArray(ts);
		glBindBuffer(GL_ARRAY_BUFFER,sgss);
		glVertexAttribPointer(kss,3,GL_FLOAT,false,0,0);
		glBindBuffer(GL_ARRAY_BUFFER,tss);
		glVertexAttribPointer(ts,2,GL_FLOAT,false,0,0);
		auto pmd=glm::perspective(3.14159f*0.5f,(float)v1/(float)v2,0.5f,100.0f);
		if(1)glUniformMatrix4fv(npss,1,false,&pmd[0][0]);
		glDrawArrays(GL_TRIANGLE_STRIP,0,4);
		glViewport(0,0,st.clp.v1,st.clp.v2);
		glUseProgram(p);
		SDL_GL_SwapWindow(st.cp);
	}
}ckkn;
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
int vdv=2;
void mlkp::dpl(const char *l,...)
{
	va_list ps;
	va_start(ps,l);
	plss+=vsnprintf(&pl[plss],sizeof(pl)-plss,l,ps);
}
void mlkp::cp()
{
	if(!lvs)tmt_write(st.dps[dpk],pl,0);
	else
	{
		printf("%s",pl);
		fflush(stdout);
	}
	plss=0;
	pl[0]=0;
}
void mlkp::slm(){dpl("\033[2J");};
void mlkp::pk()
{
	slm();
	if(vkvl==3){cp();return;}
	if(ml.size()==0)
	{
#ifdef EMSCRIPTEN
		mls=EM_ASM_INT({return mls;})-1;
		tmls=EM_ASM_INT({return tmls;})-1;
#endif
		ml=spl(std::ifstream(sn));
		if(ml[0][0]==';')psv=1;
		if(mls<0||mls>=ml.size()){mls=psv?0:ml.size()-1;vsn=psv?0:2;}
		if(tmls<0||tmls>=ml.size())
			tmls=-1;
		if(tmls!=-1)
			dmls=mls;
	}
	vdss=(st.dp.v-17)/2,vdsd=(st.dp.dv-5+1)/2;
	dpl("\33[%d;%dH",vdsd+1,vdss+1);
	dpl("ML-%ld\r",ml.size());
	dpl("\033[%dC\033[1B",vdss);
	if(mls!=-1)
	{
		auto p=std::to_string(ml.size()).size();
		auto n=std::to_string(mls+1);
		std::string l=std::string("[");
		for(int k=n.size();k<p;k++)
		{
			l.resize(l.size()+1);
			l[l.size()-1]='0';
		}
		l+=n+std::string("] ");
		dpl("%s\r",l.c_str());
		dpl("\033[%dC\033[1B",vdss);
		auto ksl=ml[mls].substr(0,ml[mls].find(";"));
		std::string kl(100,0);
		if(ksl.size())
		{
			time_t ks=std::stol(ksl);
			if(ks<256)st.cs=0;
			auto nj=*std::localtime(&ks);
			kl.resize(std::strftime(&kl[0],kl.size(),"%Y-%m-%d\r\n%H:%M:%S %Z",&nj));
		}
		else kl=std::string(15,' ');
		dpl("%s\r\033[%dC\033[1B%s\r",kl.substr(0,10).c_str(),vdss,kl.substr(12).c_str());
	}
	else dpl("?\r\033[2B");
	dpl("\033[%dC\033[1B",vdss);
	if(ss)dpl("%c",ss);
	ck=-1;
	if(mls!=-1)
	{
		auto ps=ml[mls];
		size_t ssp=ps.find('c');
		if(ssp!=std::string::npos)
		{
			int k=std::stoi(ps.substr(ssp+1,ps.substr(ssp+1).find(';')));
#ifdef EMSCRIPTEN
			if(st.csg.find(k)==st.csg.end())
			{
				EM_ASM({kcsk($0)},k);
				vkvl=1;
			}
			else {ck=k;vkvl=2;}
#endif
		}
		else vkvl=0;
	}
	if(vkvl==1)dpl("... ");
	cp();
}
void mlkp::vs()
{
	auto ps=ml[mls];
	size_t ssp=ps.find(';')+1;
	if(!((psv||ps.find("nv")!=std::string::npos)&&mls==kpls+1)&&vsn!=1)
	{
		if(psv)st.dpv.push({71,44,4,49,1,55,53,7,51,2,75});
		else st.dpv.push({51,4,45,7,51,2,75});
	}
	kpls=mls;
	vsn=1;
	while(1)
	{
		auto nsp=std::string::npos;
		if(ssp<ps.size())nsp=ps.substr(ssp,std::string::npos).find(';');
		if(nsp==std::string::npos)break;
		auto vs=ps.substr(ssp,nsp);
		ssp+=nsp+1;
		if(vs[0]>'9'||vs[0]<'0')continue;
		std::vector<unsigned char> v;
		while(vs.size())
		{
			size_t pnsp=vs.find(',');
			if(pnsp==std::string::npos)
				pnsp=vs.size();
			v.push_back(std::stoi(vs.substr(0,pnsp)));
			if(pnsp<vs.size())vs=vs.substr(pnsp+1,std::string::npos);
			else vs={};
		}
		st.dpv.push(v);
	}
}
void mlkp::nk(char p)
{	
	auto pmls=mls;
	if(st.dpv.size())return;
	if(vkvl==3)
	{
		if(p!='1'&&p!='0')return;
		vkvl=0;
		if(p=='0')pk();
	}
	if(!ss)
	{
		if(p=='1'&&vkvl==1)return;
		if(p=='1'&&vkvl==2){vkvl=3;pk();return;}
		if(vsn==0&&p=='1')p='0';
		if(p=='n')
		{
#ifdef EMSCRIPTEN
			EM_ASM({location.hash="";});
#endif
			if(lvs)st.cs=0;
		}
		else if(p>='0'&&p<='1')mls+=p-'0';
		else if(p=='-'||p=='+'||p=='@')
		{
			ss=p;
			dpl("%c",p);
			cp();
			tp=0;
			ks=mks;
		}
	}
	else
	{
		if(p>='0'&&p<='9'&&ks)
		{
			tp=tp*10+(p-'0');
			dpl("%c",p);
			cp();
			ks--;
		}
		else if(p==127)
		{
			ks++;
			dpl("\b \b");
			tp/=10;
			cp();
		}
		else if(p=='\n'||p=='\r'||p=='.')
		{
			if(ss=='-')mls-=tp;
			else if(ss=='+')mls+=tp;
			else if(ss=='@')mls=tp-1;
			ss=0;
		}
		if(ks>mks||p=='n')
		{
			ss=0;
		}	
		if(!ss)
		{
			dpl("\r");
			dpl("\033[%dC",vdss);
			for(int ks=0;ks<mks+1;ks++)
				dpl(" ");
			dpl("\r");
			dpl("\033[%dC",vdss);
			cp();
		}
		p=0;
	}
	if(!ss)
	{
		mls=std::min(mls,(int)ml.size()-1);
		mls=std::max(mls,0);
		if(p=='1'&&dmls!=-1&&mls==tmls+1)mls=dmls;
		if(mls<dmls||mls>tmls)
		{
			tmls=-1;
			dmls=-1;
		}
	}
	if(pmls!=mls)
	{
		pk();
		vsn=0;
	}
	if(p=='0'||(p=='1'&&(mls!=pmls||(tmls==dmls&&tmls!=-1))))vs();
}
mlkp mlk;
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
				auto dp=tmt_screen(st.dps[st.ptc-1]);
				auto lss=tmt_cursor(st.dps[st.ptc-1]);
				auto pds=[](int pk,int k,int pv=1,int v=1)
				{
					const auto g=st.dp.g;
					return smp(((mss<1>(14)>mss<1>(5)&&st.tp)?(mss<0>(5)-0.75):1.0)+0.5*(pk)*g,1.0+k*g,0.5*g*pv,g*v);
				};
				for(size_t k=0;k<dp->nline;k++)
					if(dp->lines[k]->dirty||1)
						for(size_t pk=0;pk<dp->ncol;pk++)
						{
							SDL_Rect ls=pds(pk,k);
							char l=dp->lines[k]->chars[pk].c;
							SDL_Rect ss=SDL_Rect({.x=(int)(st.dp.g*l*4*st.g)%v1,.y=((int)(st.dp.g*l*4*st.g)/v1)*(int)(st.dp.g*8*st.g),
									.w=(int)(st.dp.g*4*st.g),.h=(int)(st.dp.g*8*st.g)});
							if(0)SDL_SetTextureBlendMode(st.lns,dp->lines[k]->chars[pk].a.reverse?SDL_BLENDMODE_BLEND:SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_REV_SUBTRACT,SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_ADD));
							SDL_RenderCopy(st.ck,st.lns,&ss,&ls);
							if(0)SDL_SetTextureBlendMode(st.lns,SDL_BLENDMODE_BLEND);
							if(k==lss->r&&pk==lss->c&&!(st.ptpr==1&&st.ptc==1)&&!(st.ptc==3&&mlk.ck!=-1&&mlk.vkvl==3))
							{
								unsigned r=255,h=255,n=255;
								SDL_SetRenderDrawColor(st.ck,st.ks?255-r:r,st.ks?255-h:h,st.ks?255-n:n,255);
								SDL_SetRenderDrawBlendMode(st.ck,SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_SUBTRACT,SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_ADD));
								SDL_RenderFillRect(st.ck,&ls);
								SDL_SetRenderDrawBlendMode(st.ck,SDL_BLENDMODE_BLEND);
							}
						}
				tmt_clean(st.dps[st.ptc-1]);
				if(mlk.ck!=-1&&mlk.vkvl==3&&st.ptc==3)
				{
					SDL_Rect s=pds(0,0,st.dp.v,st.dp.dv);
					int v=st.sp1*st.g*10;
					if(v>s.w)v=s.w;
					if(v>s.h)v=s.h;
					s.x+=(s.w-v)/2;
					s.y+=(s.h-v)/2;
					s.w=v;
					s.h=v;
					if(0)s=pds((int)((st.dp.v-8)/2),mlk.vdsd-4,8,4);
					SDL_RenderCopy(st.ck,st.csg[mlk.ck],0,&s);
				}
			}
			if(st.dp.d&&st.tp&&st.pskt.s)
			{
				for(size_t k=0;k<10;k++)
				{
					const auto g=st.dp.g;
					if(1)
					{
						if(st.pskt.ps==-1)
						{
							if(!(k<st.pskt.jm.pj.size()))continue;
						}
						else if(!(k<st.pskt.jm.pj[st.pskt.ps-1].pj.size()))continue;
					}
					auto lm=(st.pskt.ps==-1)?st.pskt.jm.pj[k].dn:st.pskt.jm.pj[st.pskt.ps-1].pj[k].dn;
					SDL_SetTextureBlendMode(st.lns,st.ks||1?SDL_BLENDMODE_BLEND:SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_REV_SUBTRACT,SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ONE,SDL_BLENDOPERATION_ADD));
					for(int pk=0;pk<lm.size();pk++)
					{
						SDL_Rect ls=smp(mss<0>(5)-0.125*lm.size()+0.25*pk+0.5*(k%5)*g*8,mss<1>(5)-0.25+(int)(k/5)*g*4,0.5*g,g);
						char l=lm[pk];
						if(st.pskt.sn&&l>='a'&&l<='z')l+='A'-'a';
						SDL_Rect ss=SDL_Rect({.x=(int)(st.dp.g*l*4*st.g)%v1,.y=((int)(st.dp.g*l*4*st.g)/v1)*(int)(st.dp.g*8*st.g),
								.w=(int)(st.dp.g*4*st.g),.h=(int)(st.dp.g*8*st.g)});
						SDL_RenderCopy(st.ck,st.lns,&ss,&ls);
					}
					SDL_SetTextureBlendMode(st.lns,SDL_BLENDMODE_BLEND);
				}
			}
		}
		if(st.vtp)lck();
		if(0)SDL_RenderCopy(st.ck,st.lns,NULL,NULL);
		if(0)printf("tl %s\n",SDL_GetError());
		if(!st.cc&&!st.dp.d&&!(st.s==6))
		{
			if(1)
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
				SDL_SetRenderDrawColor(st.ck,0,0,255,255);
				SDL_RenderDrawRect(st.ck,&st.pd);
				SDL_SetRenderDrawColor(st.ck,255,0,0,255);
				SDL_RenderDrawRect(st.ck,&st.cdp);
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
void tlk(void* c,size_t d1,size_t d2,size_t d,size_t l,size_t td,uint8_t r,uint8_t h,uint8_t n)
{
	auto bk=[&](size_t s1,size_t s2,float ns)
	{
		size_t rs=s2*d+s1*3,hs=rs+1,ls=hs+1;
		((uint8_t*)c)[rs]=fmin((uint8_t)(ns*(float)r+(1.0-ns)*(float)(((uint8_t*)c)[rs])),255);
		((uint8_t*)c)[hs]=fmin((uint8_t)(ns*(float)h+(1.0-ns)*(float)(((uint8_t*)c)[hs])),255);
		((uint8_t*)c)[ls]=fmin((uint8_t)(ns*(float)n+(1.0-ns)*(float)(((uint8_t*)c)[ls])),255);
	};
	for(size_t k1=0;k1<l;k1++)
	{
		size_t dk2=std::min(k1+td,l*2-td-k1-1);
		int nk2=k1-td;
		bk(k1,dk2,0.5);
		if(nk2>=0)bk(k1,nk2,0.5);
		for(size_t k=std::max(nk2+1,0);k<dk2;k++)
			bk(k1,k,1);
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
			unsigned char m=st.cc?255:255;
			int ms1=(int)(mss<0>(nspk(i))*st.sp1);
			int ms2=(int)(mss<1>(nspk(i))*st.sp2);
			bool d=(i==0?false:!((st.tr.p==1||st.tr.p==2)&&st.tr.n==i));
			if(0&&!d)printf("!d %d\n",i);
			unsigned char cbv=44;
			int vk=3;
#ifdef EMSCRIPTEN
			auto npnv=[&](){vk--;cbl({.d1=ms1-4-(vk+1),.d2=ms2-4-(vk+1),.v1=8+2*(vk+1),.v2=8+2*(vk+1),.rm=0,.hm=120,.nm=255})();};
			if(1)if(i==12&&!*(st.svsb.skk)&&!st.dp.d)switch(EM_ASM_INT({return ccpd.psp}))
			{
				case 1:
					if(d)
					{
						vk--;
						cbl({.d1=ms1-4-(vk+1),.d2=ms2-4-(vk+1),.v1=8+2*(vk+1),.v2=8+2*(vk+1),.rm=150,.hm=150,.nm=150})();
					}
					break;
				case 2:
					if(!st.cc&&d)npnv();
					break;
				default:
					break;
			}
			if(0)if(i==5&&!st.dp.d&&!*(st.svsb.skk)&&!EM_ASM_INT({return ccpd.psp})&&!st.cc&&d)npnv();
			if(0)if(i==6&&!st.dp.d&&!*(st.svsb.skk)&&!st.cc&&d)npnv();
			if(st.ptc==3&&st.dp.d&&mlk.dmls!=-1&&((st.pskt.ps==-1&&i==11)||(st.pskt.ps==6&&i==6)))npnv();
#endif
			if(1)if(!d)cbl({.d1=ms1-4-(vk+1),.d2=ms2-4-(vk+1),.v1=8+2*(vk+1),.v2=8+2*(vk+1),.rm=255,.hm=255,.nm=255})();
			cbl({.d1=ms1-4-vk,.d2=ms2-4-vk,.v1=8+2*vk,.v2=8+2*vk,.rm=cbv,.hm=cbv,.nm=cbv})();
			if(1)cbl({.d1=ms1-4,.d2=ms2-4,.v1=8,.v2=8,.rm=0,.hm=0,.nm=0})();
			if(!(st.dp.d&&st.pskt.s))nl({.n=(i<5?i+11:i-5+50),.p1=mss<0>(nspk(i))-(float)0.5,.p2=mss<1>(nspk(i))-(float)0.5,
					.v=0,.rm=m,.hm=m,.nm=m})();
			else
			{
				unsigned char rm=0,hm=0,nm=0;
				if(st.pskt.ps==-1&&(i==14||i==5))
				{
					rm=100;hm=100;nm=100;
					if((i==14&&st.pskt.sn)||(i==5&&st.pskt.nn))
					{
						nm=0;
						rm=150;
						hm=190;
					}
				}
				cbl({.d1=ms1-4,.d2=ms2-4,.v1=8,.v2=8,.rm=rm,.hm=hm,.nm=nm})();
			}
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
	if(0)
	{
		SDL_ClearError();
		if(IMG_SavePNG(sl,"sl.png")!=0)
		{
#ifdef EMSCRIPTEN
			emscripten_console_log("slb");
			emscripten_console_log(IMG_GetError());
#endif
		}
	}
	SDL_FreeSurface(sl);
	TTF_CloseFont(lns);
	TTF_Quit();
}
void ptdps()
{
#ifdef EMSCRIPTEN
	EM_ASM({if(typeof ptc!=='undefined')ptc.create_file("dps",new TextEncoder().encode('stty cols '+$0+' && stty rows '+$1));},st.dp.v,st.dp.dv);
#endif
}
void mk()
{
	int x1,x2;
	SDL_GetWindowSize(st.cp,&x1,&x2);
	st.clp.v1=x1;st.clp.v2=x2;
	if(0)printf("mk %d %d\n",x1,x2);
#ifdef EMSCRIPTEN
	if(st.s==1)
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
		if(0)st.tp=0;
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
		if(0)st.tp=1;
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
	if(0)st.tp=1;
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
	st.cdp.y=st.pd.y+st.sp2*st.g;
	st.cdp.w=(mss<0>(14)-mss<0>(5)+1.5)*st.sp1*st.g;
	st.cdp.x=st.pd.x+(st.pd.w-st.cdp.w)/2;
	st.cdp.h=(mss<1>(5)-2.5)*st.sp2*st.g;
	int t2=ceil((float)x1/(float)(st.s1*st.sp1));
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2");
	st.mc1=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,st.s1*st.sp1,st.s2*st.sp2);
	if(!getenv("NCTV"))SDL_SetTextureScaleMode(st.mc1,SDL_ScaleModeNearest);
	st.mc2=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_TARGET,st.s1*st.sp1*t2,st.s2*st.sp2*t2);
	if(!getenv("NCTV")&&!st.nkk)SDL_SetTextureScaleMode(st.mc2,SDL_ScaleModeLinear);
	vdv=mss<1>(14)>mss<1>(5)?2:4;
	st.vc=SDL_CreateTexture(st.ck,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,vdv*st.sp1*st.g,vdv*st.sp2*st.g);
	st.clvp=1;
	SDL_LockTexture(st.vc,NULL,(void**)&st.cn,&st.cns);
	if(0)
	{
		memset(st.cn,255,vdv*st.sp1*st.g*st.cns);
		vlk(st.cn,vdv*st.sp1*st.g,vdv*st.sp2*st.g,st.cns,0,0,vdv*st.sp1*st.g/2,0,0,0);
	}
	else
	{
		tlk(st.cn,vdv*st.sp1*st.g,vdv*st.sp2*st.g,st.cns,vdv*st.sp1*st.g,vdv*st.sp1*st.g/4,255,194,0);
	}
	SDL_UnlockTexture(st.vc);
	st.tpp.v1=x1;st.tpp.v2=x2;
	st.tpp.ss();
	st.tp=!st.dp.d||mss<1>(14)>mss<1>(5);
	if(mss<1>(14)>mss<1>(5))
	{
		st.dp.g=0.5;
		st.dp.v=(mss<0>(14)-mss<0>(5)+1.0)*4.0+2;
		st.dp.dv=(mss<1>(5)-2.5)*2.0;
	}
	else
	{
		st.dp.g=1;
		st.dp.v=(st.s1-2)*2.0;
		st.dp.dv=st.s2-2;
	}
	if(1)lnss(st.dp.g*4*st.g,st.dp.g*8*st.g);
	if(0)lnss(st.tpp.g,st.tpp.g*2);
	for(int k=0;k<st.dps.size();k++)
		tmt_resize(st.dps[k],st.dp.dv,st.dp.v);
	mlk.pk();
	ptdps();
#ifdef EMSCRIPTEN
	EM_ASM({});
#endif
	if(0)printf("dp %dx%d\n",st.dp.v,st.dp.dv);
	st.plg=1;
}
#ifdef EMSCRIPTEN
extern "C"
{
void EMSCRIPTEN_KEEPALIVE lkp()
{
	printf("lkp\n");
};
void EMSCRIPTEN_KEEPALIVE plkp(const char* l)
{
	printf("plkp %s\n",l);
};
void EMSCRIPTEN_KEEPALIVE dplk(int p)
{
	static int ss;
	static std::string pl="dl";
	if(ss<2)
	{
		if(p)pl.push_back(p);
		if(0)printf("pl %s\n",pl.c_str());
		if(ss<1&&pl.ends_with("~% "))
		{
			ss=1;
			const char l[]="source /mnt/dk && clear\n";
			ptdps();
			EM_ASM({ptc.create_file("dk",new TextEncoder().encode(dkl));ptc.serial0_send(UTF8ToString($0));},l);
		}
		else if(pl.ends_with("~# ")||pl.ends_with("~$ "))
		{
			ss=2;
			tmt_write(st.dps[0],"\rroot:~# ",0);
			st.ptpr=2;
		}
		return;
	}
	static int k;
	if(0)printf("p %d\n",p);
	char s=p;
	if(k<30||1)tmt_write(st.dps[0],&s,1);
	k++;
}
void EMSCRIPTEN_KEEPALIVE dptlk(const char* p)
{
	tmt_write(st.dps[1],p,0);
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
void ptlk(char *l)
{
	npk(-2);
#ifdef EMSCRIPTEN
	if(l[1]==0&&l[0]==3&&st.ptc==2)EM_ASM({location.hash="";});
	else if(st.ptc==1)
		EM_ASM({if(typeof ptc!=='undefined')ptc.serial0_send(UTF8ToString($0));},l);
	else if(st.ptc==3)mlk.nk(l[0]);
	else EM_ASM({ptsc.master.ldisc.writeFromLower(UTF8ToString($0));},l);
#endif
}
void pskt(int n,bool s)
{
	if(n==0)n=10;
	if(st.pskt.ps==-1&&!s)
	{
		if(n==9)
			st.pskt.sn=!st.pskt.sn;
		else if(n==10)
			st.pskt.nn=!st.pskt.nn;
		else st.pskt.ps=n;
	}
	else if(!s&&n-1<st.pskt.jm.pj[st.pskt.ps-1].pj.size()) 
	{
		char l[2]={};
		l[0]=st.pskt.jm.pj[st.pskt.ps-1].pj[n-1].dn[0];
		if(st.pskt.sn&&l[0]>='a'&&l[0]<='z')l[0]+='A'-'a';
		if(st.pskt.nn)
		{
			if(l[0]>='a'&&l[0]<='z')
				l[0]-=96;
			else if(l[0]=='[')l[0]=27;
			else if(l[0]=='\\')l[0]=28;
			else if(l[0]==']')l[0]=29;
			else if(l[0]=='^')l[0]=30;
			else if(l[0]=='_')l[0]=31;
			else if(l[0]=='?')l[0]=127;
		}
		ptlk(l);
		if(st.pskt.ps!=6)st.pskt.ps=-1;
		st.pskt.nn=0;
	}
}
void pttk(int n,bool s)
{
	if(n<5)return;
	else n-=5;
	if(st.dp.d&&st.pskt.s){pskt(n,s);return;}
	static int ts,p;
	static char l[2];
	l[1]=0;
	if(!s)
	{
		if(ts==3||st.pttk.ns)
		{
			ts=0;
			p=0;
			st.pttk.ns=0;
		}
		p=p*10+n;
		ts++;
		if(p*10>127)
			ts=3;
		l[0]=p;
	}
	if(ts==3&&p<128)ptlk(l);
#ifdef EMSCRIPTEN
	if(0&&ts==3&&p==128)
		EM_ASM({location.hash="";});
#endif
}
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
bool skkk(SDL_Event &g)
{

#ifdef EMSCRIPTEN
			auto tk=SDL_GetModState();
			if((g.key.keysym.sym==SDLK_r&&(tk==KMOD_LCTRL||tk==KMOD_RCTRL))||(g.key.keysym.sym==SDLK_F5&&tk==KMOD_NONE))
			{
					EM_ASM({if(navigator.userAgent.toLowerCase().indexOf('electron')<0)window.location.reload()});
					return 1;
			}
			if(g.key.keysym.sym==SDLK_LEFT&&tk==KMOD_LALT)
			{
				EM_ASM({history.back();});
				return 1;
			}
			if(g.key.keysym.sym==SDLK_RIGHT&&tk==KMOD_LALT)
			{
				EM_ASM({history.forward();});
				return 1;
			}
			return 0;
#endif
}
struct
{
	std::vector<char> l;
	int d=0;
}lvss;
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
	bool tkps=clk.p();
	switch(st.s)
	{
		case 2:
			st.dp.d=1;
			st.ptc=1;
			if(!st.ptpr)
			{
				st.ptpr=1;
				st.ptrk=SDL_GetTicks();
				EM_ASM({
					var ptcv=document.createElement('script');
					ptcv.onload = function()
					{
						var ptc=window.ptc= new V86({
							wasm_path: "v86.wasm",
							memory_size: 32 * 1024 * 1024,
							bios: {
								url: "seabios.bin",
							},
							cdrom: {
								url: "linux4.iso",
							},
							filesystem:{},
							autostart: true,
						});
						if(1)ptc.add_listener("serial0-output-byte",function(p)
								{
									Module.ccall('dplk',null,['number'],[p])
								});
					};
					ccss('libv86.js',p=>
					{
						let ps=new Blob([p.target.response],{type:"application/javascript"});
						ptcv.src=URL.createObjectURL(ps);
						document.head.appendChild(ptcv);
					})
				});
			}
			else if(tkps)EM_ASM({if(typeof ptc!=='undefined')ptc.run();});
			break;
		case 4:
			st.dp.d=1;
			st.ptc=2;
			break;
		case 7:
			st.dp.d=1;
			st.ptc=3;
			break;
		default:
			st.dp.d=0;
			break;
	}
	if(tkps&&!(st.ptc==1&&st.dp.d))EM_ASM({if(typeof ptc!=='undefined')ptc.stop();});
	if(tkps)mk();
	if(st.s==1)
	{
		st.clp.nk(&st);
		return;
	}
	if(lvss.d==1)
	{
		if(1)EM_ASM({
				let s=document.createElement("a");
				if(1)s.href=window.URL.createObjectURL(new Blob([Module.HEAP8.slice($0,$0+$1)]));
				if(1)s.click();
			},lvss.l.data(),lvss.l.size());
		lvss.d=0;
	}
	if(lvss.d==2)
	{
		EM_ASM({
			let t=document.createElement('input');
			t.type='file';
			t.onchange=p=>
			{
				let pk=new FileReader();
				pk.onload=p=>{
					let l=new Uint8Array(p.target.result);
					let s=Module._malloc(l.length);
					Module.HEAPU8.set(l,s);
					Module.ccall('lvs','number',['number','number','number'],[s,l.length,4]);
					Module._free(s);
				};
				pk.readAsArrayBuffer(p.target.files[0]);
			};
			t.click();
		});
		lvss.d=3;
	}
	if(lvss.d==8)
	{
		EM_ASM({
			let p="";
			try{p=eval(new TextDecoder().decode(Module.HEAP8.slice($0,$0+$1)));if(typeof(p)!=='undefined')p=p.toString();else p="";}
			catch(v){p=v.toString()}
			let l=new TextEncoder().encode(p);
			let s=Module._malloc(l.length);
			Module.HEAPU8.set(l,s);
			Module.ccall('lvs','number',['number','number','number'],[s,l.length,4]);
			Module._free(s);
		},lvss.l.data(),lvss.l.size());
	}
#endif
	static double k;
	SDL_Event g;
	const int tpss=25;
	static char tps[tpss];
	auto tpm=[](){memset(tps,0,tpss);};
	bool dndsk=1;
	while(dndsk||SDL_PollEvent(&g))
	{
#ifdef EMSCRIPTEN
		if(dndsk)
		{
			dndsk=0;
			int ns1=EM_ASM_INT({return svsg.s1});
			int ns2=EM_ASM_INT({return svsg.s2});
			[[maybe_unused]]bool nsk=EM_ASM_INT({return svsg.k});
			int kp=EM_ASM_INT({return svsg.kp});
			if(kp)
			{
				g.type=kp==1?SDL_MOUSEBUTTONDOWN:kp==2?SDL_MOUSEMOTION:SDL_MOUSEBUTTONUP;
				g.button.x=ns1;
				g.button.y=ns2;
				g.motion.x=ns1;
				g.motion.y=ns2;
				EM_ASM({svsg.kp=0;});
			}
			else continue;
		}
		else if(g.type==SDL_MOUSEBUTTONDOWN||g.type==SDL_MOUSEBUTTONUP||g.type==SDL_MOUSEMOTION)continue;
#endif
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
			if(skkk(g))continue;
			auto tk=SDL_GetModState();
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
			if(st.dp.d&&st.ptc&&!(st.tp&&n>=15&&n<25))
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
				else if(p==SDLK_BACKSPACE)
					s=(char*)TMT_KEY_BACKSPACE;
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
				ptlk(s);
#endif
			}
			if(0&&n==0)printf("ktnj\n");
			if(tps[n]==0)
			{
				tps[n]=1;
				if(st.dp.d&&st.ptc&&n>=1&&n<15)n=0;
				if(n>14)n-=10;
				if(n>0&&n<15&&!st.vtp&&st.tp)
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
			if(st.tr.p==2)
			{
				st.tr.p=0;
				st.plg=1;
			}
		}
		if(g.type==SDL_MOUSEBUTTONDOWN)
			if(st.tr.p!=1)
			{
				int n=ss(g.button.x,g.button.y);
				if(0)printf("n %d\n",n);
				if(!(n>4&&n<15))
				{
					st.pttk.ns=1;
					if(st.pskt.ps==-1)
					{
						if(st.dp.d&&st.tp)
						{
							char ls[2];
							ls[0]=10;ls[1]=0;
							ptlk(ls);
						}
					}
					else st.pskt.ps=-1;
					st.plg=1;
				}
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
	if(st.plg)
	{
		const char *p=SDL_GetError();
		if(0&&p)printf("%s\n",p);
	}
	double sk=(double)SDL_GetTicks()/1000.0;
	if((unsigned int)sk!=st.ksn)
	{
		if(st.ksns)st.plg=1;
		st.ksn=sk;
	}
	if(st.ptc==1&&st.ptpr==1)
	{
		unsigned int sk=SDL_GetTicks();
		const int vk=500;
		if(sk-st.ptrk>vk)
		{
			st.plg=1;
			if(tmt_cursor(st.dps[0])->c==3)
				tmt_write(st.dps[0],"\b \b\b \b\b \b",0);
			else tmt_write(st.dps[0],".",0);
			st.ptrk+=vk;
		}
	}
	st.tr.k+=sk-k;
	k=sk;
	if(st.tr.p==1||st.tr.p==2)
	{
		const double dk=.25;
		if(st.tr.s==0||((st.tr.n<5||st.dp.d)&&((st.tr.k-dk)/0.05>st.tr.s-1)))
		{
			st.plg=1;
			if(st.vtp)kplt(st.tr.n);
			else if(st.dp.d&&st.tp)pttk(st.tr.n,st.tr.s);
			else npk(st.tr.n);
			if(st.tr.s==0||st.tr.n<5)st.tr.s++;
		}
	}
#ifdef EMSCRIPTEN
	if(st.pspp)
	{
		EM_ASM({ccpd.psp=0;plg=1;});
		if(st.pspp==2&&!st.cc)
			EM_ASM({cdss($0);},st.svsb.ccs->c_str());
		st.pspp=0;
	}
	if(EM_ASM_INT({let pplg=plg;plg=0;return pplg;}))st.plg=1;
	bool cc=EM_ASM_INT({return cc;});
	if(st.cc!=cc){st.cc=cc;st.plg=1;}
	if(st.cc&&st.ks){st.ksps=1;st.ks=0;}
	if(st.ksps&&!st.cc){st.ksps=0;st.ks=1;st.clvp=1;}
	if(st.cc)
	{
		EM_ASM(cpdk());
	}
	bool ccp=EM_ASM_INT({return tvcp&&ccpd.videoHeight>0;})&&st.cc;
	static int ckg;
	ccp=ccp&&((!ckg&&!EM_ASM_INT({return ccpd.paused}))||st.plg);
	ckg++;
	if(ckg==2)ckg=0;
	bool pplg=st.plg;
	if(st.plg)
	{
		st.plg=0;lk();
		if(!ccp)
		{
			SDL_RenderPresent(st.ck);
			if(st.s==6)
			{
				SDL_Rect ccvs;
				if(st.cdp.h>st.cdp.w)
				{
					ccvs.h=st.cdp.w;
					ccvs.w=st.cdp.w;
				}
				else
				{
					ccvs.w=st.cdp.h;
					ccvs.h=st.cdp.h;
				}
				ccvs.x=st.cdp.x+(st.cdp.w-ccvs.w)*0.5;
				ccvs.y=st.cdp.y+(st.cdp.h-ccvs.h)*0.5;
				ckkn.pk(ccvs.x,ccvs.y,ccvs.w,ccvs.h);
			}
		}
	}
	if(ccp)
	{
		if(1)if(!pplg)ncpk();
		SDL_RenderPresent(st.ck);
		SDL_Rect ccvs;
		ccvs.w=EM_ASM_INT({return ccpd.videoWidth;});
		ccvs.h=EM_ASM_INT({return ccpd.videoHeight;});
		if(ccvs.w==0||ccvs.h==0);
		else if(ccvs.w*st.cdp.h>ccvs.h*st.cdp.w)
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
void dppk(tmt_msg_t d,TMT* dp,const void *pt,void* k)
{
	if(d==TMT_MSG_UPDATE||d==TMT_MSG_MOVED)
	{
		st.plg=1;
		tmt_clean(*(TMT**)k);
	}
}
#ifdef EMSCRIPTEN
extern "C"
{
void EMSCRIPTEN_KEEPALIVE kcsk(size_t s,int v,int d,int k)
{
	auto sl=SDL_CreateRGBSurfaceWithFormat(0,v,d,24,SDL_PIXELFORMAT_RGBA32);
	memcpy(sl->pixels,(void*)s,v*d*4);
	st.csg[k]=SDL_CreateTextureFromSurface(st.ck,sl);
	SDL_FreeSurface(sl);
	st.plg=1;
	if(mlk.vkvl==1)
	{
		mlk.pk();
	}
}
size_t EMSCRIPTEN_KEEPALIVE lvs(size_t s,size_t l,int d)
{
	if(d==5){std::this_thread::sleep_for(std::chrono::milliseconds(50));return lvss.d==4;}
	if(d==6)return (size_t)lvss.l.data();
	if(d==7){lvss.d=0;return lvss.l.size();}
	if(s)lvss.l.assign((char*)s,(char*)s+l);
	lvss.d=d;
	return 0;
};
}
#endif
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
	st.dps.resize(3);
	for(int k=0;k<st.dps.size();k++)
		st.dps[k]=tmt_open(8,8,dppk,&(st.dps[k]),0);
	mlk.pk();
#ifdef EMSCRIPTEN
	std::signal(SIGINT,[](int){});
	st.vkk=std::thread([](){
			EM_ASM({ss=()=>{
					tts=33;
					ms=1000000000000;
					f1=(l)=>l<ms&&pk(l)==0?f5(l+ms*100):0;
					f2=(l)=>l%10n;
					};
					pk=(x)=>x%1;
					dk=(x)=>x-pk(x)+pk(x)*pk(x);
					tk=(x)=>dk(x)-3.25;
					lvs=(l)=>{
						if(typeof(l)==='string')
							l=(new TextEncoder()).encode(l);
						let s=Module._malloc(l.length);
						Module.HEAPU8.set(l,s);
						Module.ccall('lvs','number',['number','number','number'],[s,l.length,1]);
						Module._free(s);
					};
					lts=()=>{
						Module.ccall('lvs','number',['number','number','number'],[0,0,2]);
						while(!Module.ccall('lvs','number',['number','number','number'],[0,0,5])){}
						let s=Module.ccall('lvs','number',['number','number','number'],[0,0,6]);
						let l=Module.ccall('lvs','number',['number','number','number'],[0,0,7]);
						if(0)console.log(s,l);
						return Module.HEAP8.slice(s,s+l);
					};
					sss=(l)=>{
						l=(new TextEncoder()).encode(l);
						let s=Module._malloc(l.length);
						Module.HEAPU8.set(l,s);
						Module.ccall('lvs','number',['number','number','number'],[s,l.length,8]);
						Module._free(s);
						while(!Module.ccall('lvs','number',['number','number','number'],[0,0,5])){}
						let ns=Module.ccall('lvs','number',['number','number','number'],[0,0,6]);
						let nl=Module.ccall('lvs','number',['number','number','number'],[0,0,7]);
						return new TextDecoder().decode(Module.HEAP8.slice(ns,ns+nl));
					};
				});
			while(1)
			{
				while(st.s!=4)std::this_thread::sleep_for(std::chrono::milliseconds(50));
				printf("> ");
				fflush(stdout);
				std::string l;
				std::getline(std::cin,l);
				if(1)
				{
					auto p=(char*)EM_ASM_PTR({let p="";try{p=eval(UTF8ToString($0));if(typeof(p)!=='undefined')p=p.toString();else p="";}catch(v){p=v.toString()}return stringToNewUTF8(p)},l.c_str());
					if(p[0]!=0)
					{
						auto pp=p;
						while(*pp)
						{
							fwrite(pp,1,1,stdout);
							pp++;
						}
						printf("\n");
					}
					if(p)free(p);
				}
			}
		});
	EM_ASM({ptsc.master.onWrite(([p,d])=>{
				let tkl=(new TextDecoder().decode(p));
				if(dplpl)console.log(tkl,p);
				Module.ccall('dptlk',null,['string'],[tkl]);
				d();
			});});
#endif
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
		for(int k=0;k<st.dps.size();k++)
			tmt_close(st.dps[k]);
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
	SDL_Event gd;
	while(SDL_PollEvent(&gd))
	{
		if(gd.type==SDL_KEYDOWN)
			if(skkk(gd))continue;
	};
	int ns1=EM_ASM_INT({return svsg.s1});
	int ns2=EM_ASM_INT({return svsg.s2});
	bool nsk=EM_ASM_INT({return svsg.k});
	EM_ASM({svsg.kp=0;});
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
void pj::c()
{
}
struct mvm
{

};
