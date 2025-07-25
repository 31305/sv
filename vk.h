#pragma once
#include"VocalTractModel5.h"
#include<stdlib.h>
#include<array>
#include<algorithm>
#include<thread>
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
	bool operator==(const v&)const=default;
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
	~ck(){delete[] k;}
	n *k;
	const size_t v(size_t a){a++;if(a==s)a=0;return a;}
	const size_t ak(size_t d,size_t u){if(u>=d)return u-d;else return u+s-d;}
};
const bool pp=0;
const double nv=0?0.1:GS_VTM5_MIN_RADIUS;
const double sgvv=0.1;
inline double vnv(const v &dv,bool db)
{
	return (!db&&(1||dv.sg||dv.n))?sgvv:nv;
}
inline double vm(const v& dv,short vk,bool db=0)
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
			if(dv.sd)return 1?vmk[0][vk]:vk==7-1?1.6:vmk[1][vk];
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
				else return vmk[2][vk];
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
				else return vmk[4][vk];
			}
		}
	}
	else if(dv.ns)return std::min(vmk[0][vk],std::min(vmk[2][vk],vmk[4][vk]));
	else if(dv.vs)return vmk[12][vk];
	else if(dv.vv==1)
	{
		if(vk==5-1)return vnv(dv,db);
		else return vmk[13][vk];
	}
	else if(dv.vv==2)
	{
		if(vk==6-1)return vnv(dv,db);
		else return vmk[14][vk];
	}
	else if(dv.vv==3)
	{
		if(vk==6-1)return 1;
		else return vmk[15][vk];
	}
	else if(dv.vv==4)
	{
		if(vk==7-1||vk==6-1)return vnv(dv,db);
		else return vmk[16][vk];
	}
	else if(dv.vv==5)
	{
		if(vk==8-1)return vnv(dv,db);
		else return vmk[11][vk];
	}
	else if(dv.nt)
	{
		if(dv.cs==v::csp::t)
			return vmk[17][vk];
		else if(dv.cs==v::csp::m)
		{
			if(vk==6-1)return 1?0:!db?0.2:0.0;
			else if(0&&vk==5-1)return 1; 
			else return vmk[15][vk];
		}
		else if(dv.cs==v::csp::d)
			return vmk[6][vk];
		else if(dv.cs==v::csp::od)
		{
			if(vk==8-1||vk==7-1)return 0.4;
			else return vmk[20][vk];
		}
	}
	else if(dv.sm)
	{
		if(dv.cs==v::csp::t)
		{
			if(vk==6-1)return 0.2;
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
inline double sdvm(const v &dv,bool db=0)
{
	if(dv.vv==3)return vnv(dv,db);
	else if(dv.nt&&dv.cs==v::csp::m)return 1.8;
	else return vm(dv,6-1,db);
}
inline double hgs(const v &dv)
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
		return m[(int)dv.vv-1];
	}
	else if(dv.nt&&dv.cs==v::csp::o)return 7;
	return 0;
}
inline double hgv(const v &dv)
{
	if(dv.sm)
	{
		if(dv.cs==v::csp::t)return 7000;
		else if(dv.cs==v::csp::m)return 2500;
		else if(dv.cs==v::csp::d)return 5500;
	}
	else if(dv.vv&&!dv.n)
	{
		double m[5]={2000,3800,4500,4500,2000};
		return m[(int)dv.vv-1];
	}
	else if(dv.nt&&dv.cs==v::csp::o)return 3300;
	return 0;
}
inline double hgd(const v &dv)
{
	if(dv.sm)
	{
		if(dv.cs==v::csp::t)return 1000;
		else if(dv.cs==v::csp::m)return 1700;
		else if(dv.cs==v::csp::d)return 500;
	}
	else if(dv.vv&&!dv.n)
	{
		double m[5]={2000,1000,2000,2000,700};
		return m[(int)dv.vv-1];
	}
	else if(dv.nt&&dv.cs==v::csp::o)return 1000;
	return 0;
}
inline const v vkvl(unsigned char k)
{
	if(k<=100)return vc[k];
	else
	{
		auto p=vc[k-100];
		p.n=1;
		return p;
	}
}
inline size_t vsks(v p)
{
	for(size_t k=0;k<200;k++)
		if(vkvl(k)==p)
			return k;
	return 0;
};
inline const std::vector<v> vs(const std::vector<unsigned char> &d)
{
	std::vector<v> vk;
	for(size_t k=0;k<d.size();k++)
		vk.push_back(vkvl(d[k]));	
	return vk;
};
struct stslp
{
	struct vyp
	{
		vyp(size_t kd):mc(kd){mc.k[0]=0;}
		::ck<float> mc;
		size_t d=0,u=1;
		bool v=0;
	};
	int sbs;
	vyp vy;
	stslp(int psbs):sbs(psbs),vy(psbs){};
	static void pc(void *vy,uint8_t *d,int s)
	{
		auto vyk=((vyp*)vy);
		for(int k=0;k<s;k+=sizeof(float))
		{
			if(vyk->mc.ak(vyk->d,vyk->u)==0)
			{
				if(vyk->v)fprintf(stderr,"<\n");
				*((float*)(d+k))=0;
			}
			else
			{
				*((float*)(d+k))=vyk->mc.k[vyk->d];
				vyk->d=vyk->mc.v(vyk->d);
			}
		}
	};
	static void p(void* bnd,float ls)
	{
		auto bn=(stslp*)bnd;
		vyp& vy=bn->vy;
		while(vy.mc.ak(vy.d,vy.u)>0.1*bn->sbs)
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
		vy.u=vy.mc.v(vy.u);
		vy.mc.k[vy.u]=ls;
	};
};
struct vks
{
	const bool smg=getenv("SMG");
	GS::VTM::VocalTractModel5<double,1> mt=GS::VTM::VocalTractModel5<double,1>();
	double mk=0.1;
	void pmb(std::vector<v> gv,void (*p)(void*,float),void* nv)
	{
		double ms[2][decltype(mt)::TOTAL_PARAMETERS];
		for(int k=0;k<2;k++)
			for(int pk=0;pk<mt.TOTAL_PARAMETERS;pk++)
				ms[k][pk]=0;
		if(1)for(size_t k=1;k+2<gv.size();k++)
		{
			if(gv[k].vs&&gv[k+1].sm&&!gv[k+2].sm)gv[k]=gv[k+1];
			if(gv[k].ns&&gv[k+1].vv)
			{
				v dv=gv[k+1];
				dv.n=1;dv.sg=0;dv.mp=0;
				gv[k]=dv;
			}
		}
		const double ctdm=6000;
		double ct=ctdm;
		auto vp=[this,&ct,&ctdm,&p,&nv]()
		{
			mt.execSynthesisStep();
			for(size_t k=0;k<mt.outputBuffer().size();k++)
			{
				double tp=mt.outputBuffer()[k];
				ct=std::max(ct,abs(tp));
				float ls=std::max(std::min(tp/ctdm,1.0),-1.0);
				p(nv,ls);
			}
			mt.outputBuffer().resize(0);
		};
		double vkg=0;
		for(size_t vk=0;vk<gv.size();vk++)
		{
			v pv0={},pv1={};
			bool dv=0,nv=0;
			if(vk==0)dv=1;else pv0=gv[vk-1];
			if(vk==gv.size()-1)nv=1;else pv1=gv[vk+1];
			const v pv=gv[vk];
			if(0)printf("%d",pv.sv);
			double dm=mk;
			double vvd=dm*0.75;
			double vd=pv.sv?(pv.vg?dm*2.5:pv.sd?dm*2:dm):vvd;
			if(0&&pv.sg&&!nv&&pv1.sv&&!(!dv&&!pv0.sv))vd*=1.2;
			if(!nv&&pv.sv&&pv1.sv)
				vd+=vvd;
			if(!dv&&pv0.sv&&!pv.sv&&!nv&&!pv1.sv)vd=dm;
			if(!dv&&pv0.sv&&!pv.sv)
			{	
				double mk=(pv0.sd?2.0*dm:dm)+vd;
				int vs=1;
				for(size_t k=vk+1;k<gv.size()&&k<vk+6;k++)
				{
					if(!gv[k].sv)
					{
						mk+=vvd;
						vs++;
					}
					else break;
				}
				if(vs>1)vd+=std::max(3.0*dm-mk,(double)0.0);
			}
			int gs=std::max(1,(int)(0.004*mt.internalSampleRate()));
			double nk=(double)gs/mt.internalSampleRate();
			int ks=vd/nk;
			for(int k=0;k<ks;k++)
			{
				double km=nk*k;
				[[maybe_unused]]auto ps=[k,&ms,nk](int s,double l,double lk,float g,double dk=0,bool ng=0,double vg=0)
				{
					int ls=floor(lk/nk);
					int ds=floor(dk/nk);
					if(k>ls||k<ds)return;
					if(k==ls)
					{
						ms[1][s]=l;
						return;
					}
					if(ng)
					{
						if(l>ms[0][s])
							ms[1][s]=ms[0][s]+nk*vg;
						else
						{
							double gg=2.0/(double)(ls-ds);
							if((ls-k)*gg<=ms[0][s]-l||(!pp&&ls-k==1))
								ms[1][s]=ms[0][s]+(pp?-gg:((l-ms[0][s])/(double)(ls-k)));
						}
						return;
					}
					if(g==1.0)
						ms[1][s]=ms[0][s]+(l-ms[0][s])/(double)(ls-k);
					else
					{
						double hs=pow(ms[0][s],g);
						double hl=pow(l,g);
						ms[1][s]=pow(hs+(hl-hs)/(double)(ls-k),1/g);
					}
				};
				const double m1=0.2,m2=0.35;
				const std::array<int,9> svk={7,8,9,10,11,12,13,14,mt.PARAM_R6A};
				const auto svm=[](const v &dv,int k,bool db=0)
				{
					if(k<8)
					{
						if(0&&dv.vv&&vm(dv,k)>sgvv)
							return 2.0;
						return vm(dv,k,db);
					}
					else return sdvm(dv,db);
				};
				double ds=-15,ns=-19,sts=-21,sds=ds;
				if(0){ds=-10;ns=-13;sts=-15;sds=ds;}
				if(smg){ds=-16;ns=-19;sts=-21;sds=ds;}
				const double ndv=1?0.1:vnv(vc[51],1),nnv=0.5;
				if(vk==0&&k==0)
				{
					mt.reset();
					ms[0][mt.PARAM_GLOT_PITCH]=ns;
					ms[0][mt.PARAM_GLOT_VOL]=0;
					ms[0][mt.PARAM_ASP_VOL]=0;
					ms[0][mt.PARAM_FRIC_VOL]=0;
					ms[0][mt.PARAM_FRIC_POS]=0;
					if(0)printf("%lf\n",ms[0][mt.PARAM_RR0]);
					for(size_t k=0;k<svk.size();k++)
						ms[0][svk[k]]=svm(pv,k);
					ms[0][mt.PARAM_VELUM]=pv.n?nnv:ndv;
					for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
					{
						ms[1][k]=ms[0][k];
						mt.setParameter(k,ms[0][k]);
					}
					if(1)for(int dk=0;dk<mk*mt.internalSampleRate();dk++)
						vp();
				}
				if(pv.ss==v::ssp::u)
					ps(mt.PARAM_GLOT_PITCH,ds,dm*m1,1);
				if(pv.ss==v::ssp::a)
				{
					bool st=0;
					for(size_t nk=vk+1;nk<gv.size();nk++)
						if(gv[nk].sv)
						{
							if(gv[nk].ss!=v::ssp::a)
								st=1;
							break;
						}
					if(st)ps(mt.PARAM_GLOT_PITCH,sts,dm*m1,1);
					else ps(mt.PARAM_GLOT_PITCH,ns,dm*m1,1);
				}
				if(pv.ss==v::ssp::s)
					ps(mt.PARAM_GLOT_PITCH,ns,dm,1);
				if(!nv&&pv1.ss==v::ssp::s)
					ps(mt.PARAM_GLOT_PITCH,sds,vd,1,vd-dm*m2);
				double nvm=0;
				if(!dv&&pv0.vv&&!pv0.n)nvm=ms[1][mt.PARAM_R1+(int)(hgs(pv0))];
				if(!pv.vs&&!dv)
					for(size_t k=0;k<svk.size();k++)
					{
						bool vdv=1;
						if(pp)vdv=1;
						if(vdv)
							ps(svk[k],svm(pv,k),pv.sd?dm:vd,1,0,1,1.0/dm/
								(km<dm*m1&&pv0.vv==5&&svk[k]==mt.PARAM_R8?0.4
								 :km<dm*m1&&pv0.vv==3&&svk[k]==mt.PARAM_R6A?0.5
								 :km<dm*m1&&pv0.vv==1&&svk[k]==mt.PARAM_R5?0.6
								 :km<dm*m1&&pv0.vv==4&&(svk[k]==mt.PARAM_R7||svk[k]==mt.PARAM_R6)?0.5
								 :km<dm*m1&&pv0.vv==2&&svk[k]==mt.PARAM_R6?0.5
								 :pv.vv?(km<dm*m1?0.5:0.2):(pv.nt&&pv.cs==v::csp::m)?(km<dm*m2?0.5:0.9):km<dm*m2?0.5:0.9));
						else ps(svk[k],svm(pv,k,(pv.nt&&pv.cs==v::csp::m)?1:0),vd,1,0,1,1.0/dm/
								(svk[k]==mt.PARAM_R8?0.4
								 :svk[k]==mt.PARAM_R6A?0.5
								 :svk[k]==mt.PARAM_R5?0.6
								 :(svk[k]==mt.PARAM_R7||svk[k]==mt.PARAM_R6)?(km<dm*m1?0.6:0.5)
								 :0.6));
						if(0)ps(svk[k],svm(pv,k),dm*m2,
								pv.vv==3?2
								:pv.vv==5?2
								:pv.vv==4?0.5
								:pv.vv==1?0.5
								:1);
					}
				[[maybe_unused]]auto gr=[](const v& dv)
				{
					v nv=dv;
					nv.sg=0;
					nv.n=0;
					return nv;
				};
				if(nv||(!nv&&!pv1.vs&&!(pv1.sm&&pv1.cs==v::csp::k)
						&&(1||!(pv.vv&&!pv.n&&pv1.nt&&pv1.cs==v::csp::m))))
					for(size_t k=0;k<svk.size();k++)
					{
						auto dnv=[k](double s1,double s2,bool pc)
						{
							if(k<4&&pc)return 0?(s1+s2)*0.5:std::max(s1,s2);
							else return std::min(s1,s2);
						};
						double vds=vd;
						if(!nv&&pv.sv&&pv1.sv)vds-=vvd;
						ps(svk[k],
								(nv||(pv.sv&&pv1.sv))?svm(pv,k,1)
								:(pv.vs||pv.ns||(pv.sm&&pv.cs==v::csp::k))?svm(pv1,k)
								:dnv(svm(pv,k,1),
									(pv.vv&&pv1.nt&&pv1.cs==v::csp::m
										&&svk[k]==mt.PARAM_R6A)?0.4
									:svm(pv1,k)
									,0)
								,vds,1,vds-dm*(pv.sv?m2:m1),1,1.0/dm/0.5);
					}
				if(pv.vg)
					for(size_t k=0;k<svk.size();k++)
					{
						double vds=vd;
						if(!nv&&pv.sv&&pv1.sv)vds-=vvd;
						if(0)ps(svk[k],0.5*(svm(pv,k),svm(pv,k,1)),dm,1,dm*m2);
						ps(svk[k],svm(pv,k,1),vds-dm*m2,1,vds-dm*m2*3);
					}
				if(!dv&&pv0.mp)
				{
					if(k==0)ms[0][mt.PARAM_ASP_VOL]=28;
					ps(mt.PARAM_ASP_VOL,0,std::min(vd,dm),1,std::min(vd,dm)-dm*m2);
				}
				if(!pv.vs&&!(!dv&&pv0.mp))
					ps(mt.PARAM_ASP_VOL,0,dm*m2,1,dm*m2*0.5);
				else
				{
					ps(mt.PARAM_ASP_VOL,25,dm*m2,1);
					ps(mt.PARAM_ASP_VOL,0,vd,1,vd-dm*m2);
				}
				if(pv.sm&&pv.cs==v::csp::k)
					ps(mt.PARAM_ASP_VOL,18,vd,1,vd-dm*m1);
				if(pv.sg&&!((!nv)&&pv1.sg))
					ps(mt.PARAM_GLOT_VOL,0,vd-dm*m1,1,vd-dm*m2);
				if(pv.sm||(pv.vv&&!pv.sg)||pv.vs)
					ps(mt.PARAM_GLOT_VOL,0,dm*m1,1);
				if(!nv)
				{
					if(pv1.n)
					{
						if(pv.sv||pv.nt)
							ps(mt.PARAM_VELUM,nnv,vd,1,vd-dm*m2);
					}
					else if(!pv.n)
						ps(mt.PARAM_VELUM,pv.n?nnv/2.0:ndv,vd-dm*m1,1,vd-dm*m2);
				}
				if(0&&!pv.n&&k==0&&!dv&&pv0.n)
				{
					ms[1][mt.PARAM_VELUM]=ndv;
					ms[1][mt.PARAM_GLOT_VOL]=20;
				}
				if(pv.n)
					ps(mt.PARAM_VELUM,nnv,dm*m1,1);
				else ps(mt.PARAM_VELUM,ndv,dm*m2,1);
				if(pv.sv||pv.nt||pv.n||pv.sg)
					ps(mt.PARAM_GLOT_VOL,pv.cs==v::csp::od?54:(pv.sg&&pv.vv==3)?50:60,(!dv&&pv0.mp)?dm*m2:dm*m1,1,(!dv&&pv0.mp)?dm*m1:0);
				if(nv)ps(mt.PARAM_GLOT_VOL,0,vd,1,vd-dm*m1);
				if(pv.vv&&pv.vv!=2&&!(!nv&&((pv1.vv==pv.vv)||(0&&pv1.vv==1&&pv.vv==4)))&&!nv)
					ps(mt.PARAM_VB,pv.n?1:5,vd,1,vd-dm*m1);
				ps(mt.PARAM_VB,0,dm*m1,1);
				if(pv.sm&&!(pv.cs==v::csp::k))
				{
					if(k==0)
					{
						ms[1][mt.PARAM_FRIC_POS]=hgs(pv);
						ms[1][mt.PARAM_FRIC_CF]=hgv(pv);
						ms[1][mt.PARAM_FRIC_BW]=hgd(pv);
					}
					const double gt=(pv.cs==v::csp::m)?35:30;
					if(!dv&&pv0.vv&&!pv.n)ms[1][mt.PARAM_FRIC_VOL]=gt;
					ps(mt.PARAM_FRIC_VOL,gt,dm*m1,1);
					if(!(!nv&&pv1.sm))
						ps(mt.PARAM_FRIC_VOL,0,vd,1,vd-dm*m1);
				}
				if(1&&!dv&&pv0.vv&&!pv0.n&&!pv.sm&&!pv.vv&&pv0.vv!=5)
				{
					if(k==0)
					{
						ms[1][mt.PARAM_FRIC_POS]=hgs(pv0);
						ms[1][mt.PARAM_FRIC_CF]=hgv(pv0);
						ms[1][mt.PARAM_FRIC_BW]=hgd(pv0);
					}
					double km=nk*k;
					double vk=dm*m2;
					double tt=0.05*std::min(std::max(8.0*(0.7-nvm),0.0),1.0)
						*std::min(std::max(36.0*(nvm-0.3),0.0),1.0)
						*std::max(std::min(1.0,(vk-km)/vk),0.0);
					ms[1][mt.PARAM_FRIC_VOL]=tt==0.0?0:(60.0+20.0*(log(tt)/log(10)));
				}
				if(pv.vv==2&&!pv.n)
				{
					if(k==0)
					{
						ms[1][mt.PARAM_FRIC_POS]=hgs(pv);
						ms[1][mt.PARAM_FRIC_CF]=hgv(pv);
						ms[1][mt.PARAM_FRIC_BW]=hgd(pv);
					}
					if(!(!nv&&pv1.vv==2&&!pv1.n))
					{
						ps(mt.PARAM_FRIC_VOL,30,dm*m2,1,dm*m1);
						ps(mt.PARAM_FRIC_VOL,0,vd,1,vd-dm*m1);
					}
				}
				if(!nv&&pv.sv&&pv1.sv)
				{
					for(size_t k=0;k<svk.size();k++)
						ps(svk[k],svm(pv1,k,0),vd-dm*m1,1,vd-dm*m2);
					ps(mt.PARAM_GLOT_VOL,0,vd-vvd+dm*m1,1,vd-vvd);
				}
				if(0&&pv.sv)
					ps(mt.PARAM_GLOT_VOL,57,dm,1,dm-dm*m2);
				if(1&&pv.nt&&pv.cs==v::csp::m&&(1||!(!dv&&pv0.vv==1)))
				{
					double dk=pv.sv?dm*m1:dm*m2;
					double g=km<dk?(km/dk):(vd-km<dk)?((vd-km)/dk):1;
					double rvm=0.9*g*(1.2+sin(2*M_PI*km/dm*2))*0.5;
					rvm=std::min(rvm,ms[1][mt.PARAM_R7]);
					bool br=1;
					if(0)printf("%lf\n",g);
					if(br)ms[1][mt.PARAM_RR0]=rvm;
					if(br)ms[1][mt.PARAM_RR1]=rvm;
					if(br)ps(mt.PARAM_R6,0,dk,1);
					if(!br)ms[1][mt.PARAM_R6]=rvm+(1.0-g)*svm(pv,mt.PARAM_R6);
				}
				if(!(pv.nt&&pv.cs==v::csp::m))
				{
					ps(mt.PARAM_RR0,0,dm*m1,1);
					ps(mt.PARAM_RR1,0,dm*m1,1);
				}
				if(1&&pv.sd)
				{
					ps(mt.PARAM_GLOT_VOL,53,dm,1,dm*m2);
					if(nv||!pv1.sv)ps(mt.PARAM_GLOT_VOL,60,vd-dm*m2,1,dm);
				}
				double ks[decltype(mt)::TOTAL_PARAMETERS];
				const double vsv=0.05;
				if(0)for(int k=0;k<(int)svk.size();k++)
					ms[1][svk[k]]*=(1.0-vsv+2.0*vsv*(double)rand()/(double)RAND_MAX);
				double ssv=0.2;
				if(0)ms[0][mt.PARAM_GLOT_PITCH]*=(1.0-ssv+2.0*ssv*(double)rand()/(double)RAND_MAX);
				double tvsv=0.011;
				if(0)ms[1][mt.PARAM_GLOT_VOL]*=(1.0-tvsv+2.0*tvsv*(double)rand()/(double)RAND_MAX);
				for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
					ks[k]=(ms[1][k]-ms[0][k])/(double)gs;
				if(0)ks[mt.PARAM_GLOT_PITCH]=(ms[1][mt.PARAM_GLOT_PITCH]-ms[0][mt.PARAM_GLOT_PITCH]+0.5*sin(6.28*vkg/0.2))/(double)gs;
				for(int dk=0;dk<gs;dk++)
				{
					for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
						mt.setParameter(k,ms[0][k]);
					vp();
					for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
						ms[0][k]+=ks[k];
				}
				if(0)printf("%d,%lf",k,vd);
				vkg+=nk;
			}
		}
		if(0)printf("\n");
		for(int k=0;k<mt.TOTAL_PARAMETERS;k++)
			mt.setParameter(k,ms[1][k]);
		for(int dk=0;dk<0.5*mk*mt.internalSampleRate();dk++)
			vp();
		static size_t vks;
		vks++;
		if(ct>ctdm)fprintf(stderr,"%lf > %lf @ %lu\n",ct,ctdm,vks);
	}
};
