#include"VocalTractModel5.h"
#include<stdlib.h>
#include<climits>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<unistd.h>
#include<array>
#include<algorithm>
#include<thread>
#include<SDL.h>
#ifdef KG
#include<X11/Xlib.h>
#include<X11/XKBlib.h>
#define XK_MISCELLANY
#include<X11/keysymdef.h>
#endif
#ifdef EMSCRIPTEN
#include<emscripten.h>
#include<emscripten/webaudio.h>
#else
#include<termios.h>
#include<sys/ioctl.h>
#endif
#include"st.h"
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
const std::vector<v> vs(const std::vector<unsigned char>&);
struct sksp
{
	enum lp{d,gg};
	std::vector<sksp> pss;
	std::vector<lp> ls;
	bool ps(const lp& t)
	{
		return std::find(ls.begin(),ls.end(),t)!=ls.end();
	}
	std::vector<std::vector<v>> ngs()
	{
		if(ps(gg))return {vs({53,1,75,126})};
		return std::vector<std::vector<v>>();
	}
	sksp vv();
	std::vector<v> ln(lp l)
	{
		return
			l==d?vs({69,4,66,14,77})
			:l==gg?vs({53,2,75,3,70,1,75})
			:std::vector<v>();
	}
};
struct svp
{
	enum snp
	{
		s1,//14,65,6,68,1,43,37,73,1,50,13,45,2,75
		s2,//46,8
		s3,//5,55
		s4,//54,44,4,54,44,4,65,32
		s5,//53,1,44,58,101,47,2,73,68,33
		s6,//46,2,44,66,3,75,4,70,1,77
		s7,//31,51,1,46,1,56,1,70,2,75
		s8,//51,1,44,66,5
		s9,//46,2,44,66,3,75,4,70,31,45,102,61
		s10,//49,2,76,50,9,66,4
		s11,//13,68,5,66,66,3,77
		s12,//2,70,15,68,4,66,66,1,77
		s13,//49,46,1,44,7,66,2,77
		v0,
		v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,
		v11,v12,v13,v14,v15,v16,v17,v18,v19,v20,
		v21,v22,v23,v24,v25,v26,v27,v28,v29,v30,
		v31,v32,v33,v34,v35,v36,v37,v38,v39,v40,
		v41,v42,v43,v44,v45,v46,v47,v48,v49,v50,
		v51,v52,v53,v54,v55,v56,v57,v58,v59,v60,
		v61,v62,v63,v64,v65,v66,v67,v68,v69,v70,
		v71,v72,v73,v74,v75,v76,v77,v78,v79,v80,
		v81,v82,v83,v84,v85,v86,v87,v88,v89,v90,
		v91,v92,v93,v94,v95,v96,v97,v98,v99,v100,
		v101,v102,v103,v104,v105,v106,v107,v108,v109,v110,
		v111,v112,v113,v114,v115,v116,v117,v118,v119,v120,
		v121,v122,v123,v124,v125,v126,v127,v128,v129,v130,
		v131,v132,v133,v134,v135,v136,v137,v138,v139,v140,
		v141,v142,v143,v144,v145,v146,
	};
	struct pks
	{
		void k(svp& s)
		{
		}
	};
	std::vector<snp> vc;
	std::vector<svp> ps;
	static std::vector<pks> pksk;
	bool pv=0;
	void pk()
	{
		while(1)
		{
			bool ppv=0;
			for(auto p=pksk.begin();p!=pksk.end();p++)
			{
				pv=0;
				p->k(*this);
				if(pv)ppv=1;
			}
			if(!ppv)break;
		}
	}
};
struct vgk:svp
{
	svp p
	{
		{s10,s7,s8},
		{
			{
				{s1},
				{{{s2}},{{s3}},{{s4}}}
			},
			{
				{s9},
				{{{s5}}}
			}
		}
	};
};
size_t vsks(v p)
{
	for(size_t k=0;k<100;k++)
		if(vc[k]==p)
			return k;
	return 0;
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
template<typename n>
struct bck
{
	size_t s,cs;
	n *k;
	bck(size_t ds,size_t dcs):s(ds),cs(dcs){k=new n[cs*s];}
	~bck(){delete k;}
	n& d(size_t c,size_t ks){return k[c*s+ks];}
	const size_t v(size_t a){a++;if(a==s)a=0;return a;}
	const size_t ak(size_t d,size_t u){if(u>=d)return u-d;else return u+s-d;}
	const size_t cv(size_t a){a++;if(a==s)a=0;return a;}
	const size_t cak(size_t d,size_t u){if(u>=d)return u-d;else return u+s-d;}
};
struct b
{
	GS::VTM::VocalTractModel5<double,1> m;
};
#ifdef KG
unsigned char tns(KeySym t)
{
	if(t==XK_KP_0)return 0;
	if(t==XK_KP_1)return 1;
	if(t==XK_KP_2)return 2;
	if(t==XK_KP_3)return 3;
	if(t==XK_KP_4)return 4;
	if(t==XK_KP_5)return 5;
	if(t==XK_KP_6)return 6;
	if(t==XK_KP_7)return 7;
	if(t==XK_KP_8)return 8;
	if(t==XK_KP_9)return 9;
	return 0;
}
#endif
const bool pp=0;
const double nv=0?0.1:GS_VTM5_MIN_RADIUS;
const double sgvv=0.1;
double vnv(const v &dv,bool db)
{
	return (!db&&(1||dv.sg||dv.n))?sgvv:nv;
}
double vm(const v& dv,short vk,bool db=0)
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
double sdvm(const v &dv,bool db=0)
{
	if(dv.vv==3)return vnv(dv,db);
	else if(dv.nt&&dv.cs==v::csp::m)return 1.8;
	else return vm(dv,6-1,db);
}
double hgs(const v &dv)
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
double hgv(const v &dv)
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
double hgd(const v &dv)
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
const v vkvl(unsigned char k)
{
	if(k<=100)return vc[k];
	else
	{
		auto p=vc[k-100];
		p.n=1;
		return p;
	}
}
const std::vector<v> vs(const std::vector<unsigned char> &d)
{
	std::vector<v> vk;
	for(size_t k=0;k<d.size();k++)
		vk.push_back(vkvl(d[k]));	
	return vk;
};
struct vv
{
	std::vector<vv> ps;
	std::vector<v> vm;
	size_t nv=0;
	size_t vpv=0;
	bool nsv=0;
	size_t pv=0;
	bool sv=0;
	std::string cc;
	std::vector<size_t> vv;
	std::vector<size_t> pbs;
	bool rv=0;
	bool s=1;
	struct
	{
		bool s;
		bool m;
		double mk;
		double pk;
		std::function<std::tuple<double,double,bool>(size_t,double,double)> ss;
	}sg;
};
std::vector<v> sdk(const std::vector<std::vector<v>> vn)
{
	return {};
}
std::vector<v> dn(int32_t k)
{
	if(k==150)
		return vs({71,1,60,56,4,47,1,68,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==151)
		return vs({31,51,1,71,1,60,56,4,47,1,68,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==156)
		return vs({48,1,61,71,1,60,56,4,47,1,68,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==157)
		return vs({49,1,71,66,1,71,1,60,56,4,47,1,68,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==158)
		return vs({1,48,61,1,71,1,60,56,4,47,1,68,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==159)
		return vs({70,1,46,1,71,1,60,56,4,47,1,68,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==160)
		return vs({48,1,48,61,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==163)
		return vs({66,44,7,48,1,48,61,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==164)
		return vs({56,1,66,13,48,48,1,48,61,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==165)
		return vs({71,1,60,56,1,48,1,48,61,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==166)
		return vs({48,1,61,48,1,48,61,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==167)
		return vs({50,1,71,66,1,48,1,48,61,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==170)
		return vs({49,1,71,66,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==171)
		return vs({31,51,1,49,1,71,66,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==172)
		return vs({68,46,7,49,1,71,66,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==173)
		return vs({66,44,7,49,1,71,66,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==174)
		return vs({56,1,66,13,77,49,1,71,66,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==191)
		return vs({31,51,1,70,1,46,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==192)
		return vs({68,46,7,70,1,46,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==195)
		return vs({71,1,60,56,1,70,1,46,1,66,43,1,69,7,51,34,51,1,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==201)
		return vs({31,51,4,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==202)
		return vs({68,46,43,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==204)
		return vs({56,1,66,13,44,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==205)
		return vs({71,1,60,56,4,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==206)
		return vs({48,1,63,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==207)
		return vs({49,1,71,66,4,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==208)
		return vs({1,48,61,4,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==209)
		return vs({70,1,46,4,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==235)
		return vs({71,1,60,56,1,66,44,7,76,47,1,68,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==242)
		return vs({68,46,7,56,1,66,44,4,44,7,76,47,1,68,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==249)
		return vs({16,70,1,71,1,60,56,4,47,1,68,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==265)
		return vs({71,1,60,56,1,48,1,48,61,43,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	if(k==271)
		return vs({31,51,1,49,1,71,66,1,66,43,1,69,7,51,1,68,46,7,47,1,66,2,66,3,75,31,53,36,44,37,66,66,1,44,32,50,3,70,7});
	return vs({51,2,68,6,56,7,66});
};
std::vector<vv> ls=
{{.nsv=1},
	{.vm=vs({47,1,73,68,1,58,2,70,3,70,1,75,51,44,7,43,1,66,31}),.nv=18},
	{.vm=vs({43,1,70,66,44,1,71,44,1,48,61,2,44,9}),.nv=18,.nsv=1},
	{.vm=vs({71,4,44,7,68,4,44,47,1,70,7,51,43,6,68,43,5,49,67,8,66,9,77}),.nv=2,.pv=5},
	{.vm=vs({71,4,44,7,68,4,44,47,1,70,7,51,43,6,75}),.nv=2,.nsv=1,.vv={3}},
	{.vm=vs({31,51,4,55,51,32,70,3,49,4,55,52,43,4,55,51,1,70,7,51,43,4,71,66,8,77}),.nv=4,.pv=6},
	{.vm=vs({68,46,43,1,55,51,32,70,1,71,1,44,11,51,48,3,65,1,75}),.nv=4,.pv=8},
	{.vm=vs({49,4,55,52,43,4,55,51,1,70,7,51,43,6,75}),.nv=2,.nsv=1},
	{.vm=vs({66,5,31,46,2,49,1,55,52,43,5,77,71,2,44,9,46,1,44,66,1,43,7,66,13,76,47,1,51,43,1,70,66,31,43,5,49,6,76,49,67,4,70,1,49,1,55,52,43,5,56,1,66,13,44,67,1,49,1,55,52,43,5,43,6,1,69,7,51,5,71,1,60,56,1,75,43,6,47,56,1,70,43,18,70,4}),.nv=7,.pv=9},
	{.vm=vs({43,2,68,8,71,44,1,67,1,75,5,49,1,55,52,43,35,51,4,49,43,5,66,66,2,44,50,9,66,44,43,1,55,51,32,70,39,66,66,1,44,1,71,44,1,47,70,4,71,66,8,77}),.nv=4,.pv=11},
	{.vm=vs({71,1,44,11,51,48,3,65,31}),.nv=2,.nsv=1},
	{.vm=vs({43,5,46,3,68,68,46,7,66,11,43,6,49,1,55,52,43,5,66,19,66,11,43,3,43,4,70,43,18,70,4}),.nv=10,.pv=12,.sv=1},
	{.vm=vs({66,5,46,3,56,56,1,51,44,1,51,44,7,43,5,43,6,4,46,2,44,66,66,3,70,1,75}),.nv=11,.pv=14},
	{.vm=vs({74,4,44,1,66,10,43,4,70,66,1,44,7,51,48,1,46,7,58,60,4,70,1,49,1,76,49,67,4,70,32}),.nsv=1},
	{.vm=vs({43,1,70,66,44,1,71,44,1,48,61,44,5,53,3,65,1,70,1,71,44,1,47,70,5,77,71,21,56,57,43,1,70,66,31}),.pv=15},
	{.vm=vs({31,46,2,76,51,2,49,43,3,56,7,68,2,71,7,71,44,1,47,70,2,49,43,38,66,66,3,44,1,76,71,2,44,36,77,51,4,44,1,43,7,48,43,1,66,31}),.nv=14,.pv=16},
	{.vm=vs({51,1,44,66,44,32,71,4,44,7,66,37,48,7,51,2,76,68,31,43,2,75}),.nv=15},
	{.vm=vs({2,71,10,68,2,76,49,2,44,46,3,76,51,4,45,71,1,70,7,51,2,75}),.rv=1},
	{.vm=vs({75,4,70,66,1,46,7,51,32}),.nsv=1},
	{.vm=vs({51,2,45,71,3,70,4,43,4,75}),.nv=18,.nsv=1},
	{.vm=vs({50,7,75,4,45,1,43,1,49,67,5,51,5,56,9,56,57,4,45,5}),.nv=19,.pv=21,.sv=1},
	{.vm=vs({46,7,46,7,69,35,44,43,1,70,66,44,35,44,14,71,33,66,4}),.nv=20,.pv=22},
	{.vm=vs({2,67,3,46,4,68,4,70,66,1,46,1,51,44,1,49,67,35,46,2,74,3,46,31,66}),.nv=21,.pv=23},
	{.vm=vs({51,2,49,43,3,56,7,68,53,19,50,32,49,67,5,71,3,70,1,76,49,13,51,2,44,3,76,74,1,46,31,66}),.nv=22,.pv=28},
	{.vm=vs({51,4,56,1,75,2,43,39,75,1,66,49,43,1,51,37,48,38,74,3,46,31,66}),.nv=30,.vpv=29,.pv=25},
	{.vm=vs({43,1,70,66,44,35,77,51,8,76,49,33,66,49,43,1,66,7}),.nv=24,.vpv=29,.pv=26},
	{.vm=vs({66,2,56,56,9,70,66,1,70,11,43,3,75}),.nv=25},
	{.vm=vs({47,4,45,5,43,6,75}),.nsv=1},
	{.vm=vs({49,5,75,6,70,66,1,46,7,51,11,47,4,45,5}),.nv=22,.pv=30},
	{.vm=vs({75,4,70,66,1,46,7,51,43,6,76,47,4,45,5,43,6,75}),.nv=19,.nsv=1},
	{.vm=vs({66,2,49,43,6,75}),.nv=23,.pv=24,.sv=1},
	{.vm=vs({46,4,51,43,6,70,4,76,68,13,48,71,44,4,71,2,66,4,76,51,2,45,3,43,7,66,13,76,46,7,69,8,77,51,3,45,71,43,31,66,1}),.nv=18},
	{.vm=vs({}),.nv=31,.nsv=1},
	{.vm=vs({45,31,52,1,49,1,55,53,44,1,50,32,68,46,41,46,9,74,4,53,41}),.nv=18,.pv=34,.pbs={3,20}},
	{.vm=vs({43,4,70,66,44,1,71,44,4,48,61,19,51,2,76,51,6,45,71,1,70,7,51,2,76,56,3}),.nv=33},
	{.vm=vs({49,1,68,5,49,75,9,66,1,49,43,1,49,1,50,2,49,44,3,71,1,68,37,76,47,13,45,31,52,2,77,}),.nv=18,.cc="kc.mp4"},
	{.vm=vs({70,1,46,1,71,44,1,47,70,1,43,1,70,66,44,2,49,43,3,70,7,44,75,5,65,3,76,51,44,7,43,31,66,1}),.nv=18,.pv=37},
	{.vm=vs({4,68,8,75,3,77,71,44,1,47,70,2,77,51,2,49,43,6,66}),.nv=18,.pv=38},
	{.vm=vs({49,1,44,46,1,71,44,1,67,1,75,2,76,51,3,44,1,43,1,70,66,44,2,76,51,44,33,66,1,46,43,3,75}),.nv=18,.pv=39},
	{.vm=vs({2,67,3,46,4,70,7,44,75,4,66,1,46,43,3,75}),.nv=38,.pv=40},
	{.vm=vs({66,32,70,3,49,1,75,71,1,44,51,2,77,51,1,67,2,76,51,3,44,7,48,43,1,66,31}),.nv=39},
	{.vm=vs({2,65,18,70,4,76,58,5,66,3,43,37,68,46,7,47,1,66,2,76,48,2,61,71,3,60,56,4,47,1,56,56,1}),.nv=18,.pv=42},
	{.vm=vs({46,7,69,41,73,1,50,2,46,38,65,3,46,1,77}),.nv=41,.pv=43},
	{.vm=vs({13,66,71,4,68,32,71,9}),.nv=42,.pv=44},
	{.vm=vs({1,70,66,7,75,5,58,5,66,9,77,47,16,70,43,38,70,5,75,3}),.nv=41},
	{.vm=vs({70,4,43,11,74,3,46,1,66,7,47,46,5,70})},
	{.vm=vs({47,1,73,68,1,43,1,70,66,44,2,76,51,1,67,2,76,51,44,9,43,31,66,32,66,9,71,44,1,47,70,2,77}),.pv=47},
	{.vm=vs({2,71,9,49,46,1,43,2,75,31,46,2,66,2,49,43,3,46,7,69,8,44,45,9,52,43,31,66,1}),.nv=46,.pv=48},
	{.vm=vs({2,67,3,46,4,70,43,35,44,58,2,70,36,77,51,44,7,43,31,66,1}),.nv=47,.pv=49},
	{.vm=vs({13,74,1,43,2,67,6,51,44,7,43,1,75,4,65,31,51,2,47,56,9,68,46,7,69,8,44,9,48,43,1,66,31,43,32,70,3,51,19,66,2,49,43,3,43,1,70,66,44,2,49,43,3,49,4,55,52,43,4,66,75,1,51,2,76,53,15,65,1,46,1,66,66,4,70,7,44,69,4,44,1,65,2,76,51,44,7,43,32,66,3}),.nv=48,.pv=50},
	{.vm=vs({49,2,43,6,70,66,44,7,51,38,46,6,74,1,46,32,70,75,6,70,1,46,10,43,38,46,6}),.nv=49},
	{.vm=vs({68,46,10,71,2,77,49,43,5,68,46,43,4,54,44,1,49,31,46,7,66,2,77}),.pv=52},
	{.vm=vs({51,7,76,46,6,46,43,4,45,1,49,31,46,7,66,2,77}),.nv=51,.pv=53},
	{.vm=vs({43,1,70,66,44,32,65,1,70,7,43,3,70,66,44,7,66,37,74,1,46,31,70,70,16,70,2,75}),.nv=52},
	{.vm=vs({58,1,45,2,76,71,9,73,1,66,7}),.nv=57,.pv=55,.rv=1},
	{.vm=vs({66,2,66,1,77,47,8,44,3,77,51,1,65,63,16,43,1,66,7}),.nv=54,.rv=1},
	{.vm=dn(150),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=56,.nsv=1,.rv=1},
	{.vm=dn(151),.nsv=1,.rv=1},
	{.vm=vs({71,17,44,46,4,50,65,32}),.nv=58,.nsv=1,.rv=1},
	{.vm=vs({14,71,3,50,1,49,1,66,7,51,2,49,43,6,47,56,7,66,51,2,45,71,3,70,4,43,4,77,49,75,2,44,3,65,31,70,1}),.nv=59,.pv=65,.rv=1},
	{.vm=dn(156),.nsv=1,.rv=1},
	{.vm=vs({71,17,44,46,4,50,65,32}),.nv=61,.nsv=1,.rv=1},
	{.vm=vs({1,55,53,14,48,62,33,70,1,58,43,32,48,62,6,76,73,4,69,7,66,46,5,47,2,73,68,33,70,1,49,1,50,2,50,3,49,66,1,66,1,45,32,71,6,66,1,43,1,66,7}),.nv=62,.pv=64,.rv=1},
	{.vm=vs({51,2,44,65,1,75,2,71,3,75,4,44,48,61,7}),.nv=62,.rv=1},
	{.vm=vs({66,2,49,43,4,76,51,2,45,71,3,70,4,43,4,76,51,2,49,43,3,56,7,68,46,19,51,51,2,4,49,43,6,68,73,1,50,8,44,53,3,56,57,31,66}),.nv=60,.rv=1},
	{.vm=dn(157),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=66,.nsv=1,.rv=1},
	{.vm=vs({47,32,66,33}),.nv=67,.rv=1},
	{.vm=vs({71,4,68,1,66,1,45,2,75,13,66,67,5,71,43,3,71,4,66,1,43,1,66,7,75,14,50,15,44,75,13,50,13,77}),.nv=67,.rv=1},
	{.vm=vs({71,4,68,2,76,58,5,70,6,46,4,44,38,71,43,1,51,38,65,33,71,13,49,66,1,51,2,76,49,67,6,71,1,43,1,66,7,}),.nv=67,.rv=1},
	{.vm=vs({70,5,49,9,51,4,75,14,66,52,3,70,1,66,7}),.nv=67,.rv=1},
	{.vm=vs({51,8,76,51,3,44,37,48,7,46,4,44,66,66,7,51,2,75,8,66,9,71,19,56,57,1,66,7}),.nv=67,.rv=1},
	{.vm=dn(158),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=73,.nsv=1,.rv=1},
	{.vm=vs({56,1,70,68,44,1,43,4,70,2,53,3,66,4,70,4,76,51,4,44,17,65,6,76,46,7,48,1,43,32,46,3,68,1,66,7,46,34,58,60,4,70,7,51,2,77}),.nv=74},
	{.vm=vs({66,2,66,44,1,53,2,75,3,70,1,75,7,70,68,44,4,43,1,66,66,2,75}),.nv=75},
	{.vm=vs({75,40,70,2,76,69,3,44,1,66,7}),.nv=74,.rv=1},
	{.vm=vs({70,8,44,53,3,56,57,1,66,7}),.nv=74,.rv=1},
	{.vm=dn(159),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=79,.nsv=1,.rv=1},
	{.vm=vs({50,2,49,66,1,76,68,37,45,1,43,1,66,7}),.nv=80,.rv=1},
	{.vm=vs({49,38,71,6,70,1,49,43,37,71,2,44,43,6,49,66,31}),.nv=80,.rv=1},
	{.vm=dn(160),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=83,.nsv=1,.rv=1},
	{.vm=dn(163),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=85,.nsv=1,.rv=1},
	{.vm=vs({72,17,66,51,3,44,37,66,7}),.nv=86,.rv=1},
	{.vm=dn(164),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=88,.nsv=1,.rv=1},
	{.vm=vs({1,55,53,13,45,7,49,72,37,61,2,76,51,3,44,37,66,7}),.nv=89,.rv=1},
	{.vm=vs({49,4,55,53,1,65,1,51,32}),.nv=88,.nsv=1},
	{.vm=vs({49,1,71,66,2,49,3,68,1,49,43,6,77,71,44,4,43,32,65,3}),.nv=91,.pv=93},
	{.vm=vs({32,51,1,76,68,46,5,44,3,75}),.nv=91},
	{.vm=dn(170),.nsv=1},
	{.vm=vs({71,44,1,49,31,70,1,58,8,66,39,70,13,56,1,44,5,77}),.nv=94,.nsv=1,.rv=1},
	{.vm=vs({13,66,51,1,44,48,2,47,56,3,68,33,46,1,71,44,1,51,4,47,2,47,56,1,70,8,46,33,68,7,66,4,56,1}),.nv=95,.pv=97,.sv=1,.rv=1},
	{.vm=vs({2,60,58,3,70,4,56,1,49,1,50,1,71,4,62,11,56,3}),.nv=96,.pv=98,.sv=1,.rv=1},
	{.vm=vs({1,47,46,8,70,12,56,1,49,1,50,2,49,3,52,10}),.nv=97,.pv=99,.sv=1,.rv=1},
	{.vm=vs({2,75,9,66,1,47,56,1,71,10,43,17,48,3,47,56,1}),.nv=98,.pv=116,.rv=1},
	{.vm=dn(166),.nsv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=100,.nsv=1,.rv=1},
	{.vm=vs({71,7,48,61,1,51,2,76,68,3,68,4,66,7}),.nv=101,.rv=1},
	{.vm=vs({51,2,49,43,3,56,7,68,2,71,9,45,31,52,1,49,1,55,53,44,1,50,2,49,43,3,46,19,66,66,7,75,5,44,53,3,65,4,43,1,66,2,70,66,44,3,76,49,43,4,66}),.nv=18,.pv=104},
	{.vm=vs({51,5,70,5,75,1,46,20,66,66,9,77,49,43,4,66}),.nv=103},
	{.vm=dn(167),.nsv=1,.rv=1},
	{.vm=vs({71,17,44,46,4,50,65,32}),.nv=105,.nsv=1,.rv=1},
	{.vm=vs({13,71,5,49,3,70,1,76,70,8,53,21,50,10,66,1,76,66,2,44,15,60,31,70,1}),.nv=106,.rv=1},
	{.vm=vs({70,7,48,61,1,44,51,43,33,60,1,73,1,45,1,71,1,44,10,51,48,5}),.nv=106,.rv=1},
	{.vm=vs({66,5,76,49,2,44,46,38,71,43,2,70,15,66,66,10,44,60,37,58,2,70,3,77}),.nv=108,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=105,.nsv=1,.rv=1},
	{.vm=vs({53,2,75,3,70,4,43,38,66,51,3,60,62,4,74,1,46,1,66,7}),.nv=110,.rv=1},
	{.vm=vs({46,4,51,47,4,45,5,74,3,46,31,66}),.nv=18,.pv=114},
	{.vm=vs({46,4,51,47,4,45,5,43,6,75}),.nv=18,.nsv=1},
	{.vm=vs({51,2,47,56,9,56,57,44,13,66,2,77,47,2,73,68,39,75,4,70,1,46,10,43,38,46,6,43,4,70,66,44,7,51,38,46,32,66,7,46,8,46,9,57,43,13,44,45,37,51,5,77}),.nv=113,.pv=115},
	{.vm=vs({66,2,66,3,77,49,2,46,7,69,8,77,51,3,45,71,49,43,1,66,31,43,38,45,39,51,1,46,7,46,31,56,1,70,2,75,2,70,15,51,13,44,43,4,66}),.nv=114},
	{.vm=vs({51,2,45,71,3,70,4,56,1}),.nv=99,.rv=1},
	{.vm=dn(172),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=117,.nsv=1,.rv=1},
	{.vm=vs({71,44,4,66,1,77,47,1,43,1,70,2,76,51,3,44,37,66,7}),.nv=118,.rv=1},
	{.vm=dn(173),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=120,.nsv=1,.rv=1},
	{.vm=vs({75,1,44,51,1,61,1,58,4,45,2,76,68,3,44,47,1,43,1,66,7}),.nv=121,.rv=1},
	{.vm=dn(174),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=123,.nsv=1,.rv=1},
	{.vm=vs({51,5,49,3,66,31}),.nv=124,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=123,.nsv=1,.rv=1},
	{.vm=vs({75,7,66,43,2,75,1,74,8,47,39,56,1,66,31}),.nv=126,.rv=1},
	{.vm=dn(191),.nsv=1,.rv=1},
	{.vm=vs({47,10,66,1,66,44,2,76,68,3,69,4,66,7}),.nv=128,.rv=1},
	{.vm=dn(192),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=130,.nsv=1,.rv=1},
	{.vm=vs({70,5,75,1,46,1,68,1,66,7}),.nv=131,.rv=1},
	{.vm=dn(195),.nsv=1,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=133,.nsv=1,.rv=1},
	{.vm=vs({70,8,77,47,46,1,49,1,66,7}),.nv=134,.rv=1},
	{.vm=dn(202),.nsv=1,.rv=1},
	{.vm=vs({75,19,53,4,45,1,43,2,76,58,9,53,1,75,7,48,1,66,7}),.nv=136,.rv=1},
	{.vm=dn(205),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=138,.nsv=1,.rv=1},
	{.vm=vs({70,1,46,1,46,1,49,66,44,2,76,68,3,69,4,66,7}),.nv=138,.rv=1},
	{.vm=vs({1,71,1,44,4,50,65,32}),.nv=138,.nsv=1,.rv=1},
	{.vm=vs({75,4,44,53,2,43,3,66,7}),.nv=141,.rv=1},
	{.vm=dn(235),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=143,.nsv=1,.rv=1},
	{.vm=vs({53,1,65,7,66,1,46,7,74,4,53,2,75,3,53,1,56,57,1,75}),.nv=144,.rv=1},
	{.vm=dn(249),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=146,.nsv=1,.rv=1},
	{.vm=vs({53,1,65,7,66,2,76,71,21,55,56,1,66,7}),.nv=147,.rv=1},
	{.vm=vs({70,41,44,74,2,46,31,66,50,1,75,15,68,44,1,53,5})},
	{.vm=dn(265),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=150,.nsv=1,.rv=1},
	{.vm=vs({71,44,4,66,7,51,16,45,43,2,76,45,3,51,48,43,1,66,31}),.nv=151,.rv=1},
	{.vm=vs({58,1,45,1,66,1,70,66,44,2,76,51,44,9,43,1,66,4,75})},
	{.vm=dn(271),.nsv=1,.rv=1},
	{.vm=vs({71,16,44,46,4,50,65,32}),.nv=154,.nsv=1,.rv=1},
	{.vm=vs({46,2,68,3,70,1,76,68,1,44,47,1,43,1,66,7}),.nv=155,.rv=1},
	{.vm=vs({46,1,70,43,4,46,7,48,1,43,32,48,15}),.nsv=1,.rv=1},
	{.vm=vs({51,5,49,8,68,69,7,44,8,66,9}),.nv=157,.pv=159},
	{.vm=vs({75,2,70,3,49,7,51,2,45,71,3,70,1,75}),.nv=157,.pv=159},
	{.vm=vs({13,71,1,66,1,70,66,44,2,75}),.nv=18,.cc="pts"},
	{.vm=vs({43,2,70,66,44,3,65,1,75}),.nv=18,.cc="nts"},
	{.vm=vs({45,31,52,1,71,1,61,61,1,51,2,77}),.nv=18,.cc="cls"},
	{.vm=vs({53,2,65,3,70,4}),.nv=18,.cc="kgs"},
	{.vm=vs({51,4,45,1,70,7,44,65,1,43,2,77}),.nv=18,.nsv=1,.cc="knn"},
	{.vm=vs({51,1,44,66,19,68,1,44,47,2,77}),.nv=18,.cc="sc.mp4"},
	{.vm=vs({}),.nsv=1},
};//lsn
std::vector<size_t> nvk(ls.size());
std::vector<v> sk()
{
	return {};
}
int ssk(int p)
{
	char s;
	while(read(p,&s,1)>0)
	{
		if(s=='0')return 0;
	}
	return 1;
}
struct vp
{
	size_t v=0,s=0,n=0;
};
std::vector<vp> ns=
{{},
	{},
	{},
	{0,1,2},
	{},
	{2,1,4},
};//nsss
bool pn(const std::vector<vp> &ns)
{
	return 0;
}
#ifdef KG
void es(void(*k)(int),bool n)
{
	const char* sn="/tmp/svs629";
	mkfifo(sn,S_IRWXU);
	int p=fork();
	if(p==0)
	{
		int ss=open(sn,O_RDONLY|O_NONBLOCK);
		if(!flock(ss,LOCK_EX|LOCK_NB))
		{
			if(n)k(ss);
			else
			{
				bool ck=1;
				while(ck)
				{
					ck=ssk(ss);
					std::this_thread::sleep_for(std::chrono::milliseconds(16));
				}
			}
		}
	}
	else if(p>0)
	{
		int ss=open(sn,O_WRONLY);
		char s='0';
		if(n)s='1';
		if(write(ss,&s,1)==-1){};
	}
}
#endif
unsigned long ks()
{
	return SDL_GetTicks();
};
size_t snsp(char* n)
{
	size_t s=0;
	while(*n)
	{
		s=(s<<3)+((*n)-'0');
		n++;
	}
	return s;
}
const size_t vms=33;
void vksk(bool l=0,bool knp=0);
size_t bkp(char* n)
{
	size_t k=vms;
	while(*n)
	{
		if(k>=ls.size())return 0;
		else if((unsigned char)((*n)-'1')>=ls[k].pbs.size())
			return 0;
		else k=ls[k].pbs[(*n)-'1'];
		n++;
	}
	return k;
}
struct vks
{
	bool knp=0;
	const bool lp=0,sl=0,svk=1,smg=getenv("SMG"),dvnn=getenv("DVNN"),sknl=getenv("SKNL");
	size_t sknlk=0,vsnsl=0;
	bool ck=1;
	int yk=0;
	std::string ccs;
	size_t vs=0,nvkk=1;
	const bool jt=0;
	void (*dk)()=0;
	GS::VTM::VocalTractModel5<double,1> mt=GS::VTM::VocalTractModel5<double,1>();
	struct vyp
	{
		vyp(size_t kd):mc(kd){mc.k[0]=0;}
		::ck<float> mc;
		size_t d=0,u=1;
		bool v=0;
	};
	vyp vy=vyp(48000);
	std::ifstream sskg=std::ifstream("nstp",std::ios::binary);
	void vk()
	{
		if(dk)dk();
		bool ssv=1;
		{char* p=getenv("SSV");if(p)if(p[0]=='0')ssv=0;}
		double ms[2][mt.TOTAL_PARAMETERS];
		for(int k=0;k<2;k++)
			for(int pk=0;pk<mt.TOTAL_PARAMETERS;pk++)
				ms[k][pk]=0;
		std::vector<size_t> kps;	
		std::ofstream sknls;
		if(sknl)sknls=std::ofstream("sknl");
		while(ssv)
		{
			double mk=0.1;
			std::vector<size_t> pv;
			size_t kp=0;
			double vss=0;
			std::vector<v> gv;
			vv gvm;
			bool bn=0;
			while(ck)
			{
				size_t pvss=0;
				while(1)
				{
					pvss=vs;
					if(!(!sl&&!ls[kp].sv&&yk!=12&&yk!=3&&yk!=6&&yk!=22&&yk!=8&&ck&&pv.size()==0&&st.dpv.size()==0))break;
					double ks=0.016;
					std::this_thread::sleep_for(std::chrono::milliseconds
							((int)(ks*1000.0)));
				}
				if(pvss!=vs){yk=0;continue;}
				if(0)printf("yk %d\n",yk);
				if(!ck)break;
				auto vsk=[&knp=knp,&pv,&kp,&vss,&bn,&ccs=ccs](size_t vs)
				{
					if(vs>=ls.size())return;
					if(ls[vs].nsv)return;
					if(!knp&&ls[vs].rv)return;
					double ss=0.001*(double)ks();
					size_t vk=vs;
					pv.push_back(vs);
					if(ccs!=ls[vs].cc)
						st.pspp=ls[vs].cc=="sc.mp4"?2:1;
					ccs=ls[vs].cc;
					auto pnv=[&kp](size_t k)
					{
						auto kpn=kp; 
						while(kpn)
						{
							if(k==kpn)return 1;
							kpn=ls[kpn].nv;
						}
						return 0;
					};
					while(!(ls[vk].nv==0||((ls[vk].nv==ls[kp].nv||ls[vk].nv==kp||(pnv(ls[vk].nv)&&ls[vk].nsv))&&ss-vss<10&&!bn)))
					{
						if(ls[vk].vpv)
							vk=ls[vk].vpv;
						else vk=ls[vk].nv;
						pv.push_back(vk);
					}
				};
				auto kgss=[&bn,&gv,this]()
				{
					bn=1;
					sskg.seekg((st.kgs-1)*64);
					char p[64];
					sskg.read(p,64);
					gv={};
					for(size_t k=0;k<64;k++)
						if(p[k]!=0)
							gv.push_back(vkvl((unsigned char)p[k]));
				};
				if(lp)
				{
					if(yk==3||sl)
					{
						gv.resize(0);
						std::string l;
						if(std::cin.eof())
						{
							ck=0;break;
						}
						getline(std::cin,l);
						if(!l.size())
							continue;
						int v;
						std::istringstream g(l);
						while(g>>v)
							gv.push_back(vkvl(v));
						yk=0;
					}
					else if(yk==6)
					{
						yk=0;
					}
					else {yk=0;continue;}
				}
				else if(yk==6)
				{
					yk=0;
					if(0)printf("16 %ld\n",vs);
					if(pv.size()>0);
					else if(ccs=="kgs"&&st.kgs>0)
						kgss();
					else
					{
						if(pvss==1)vsk(kp);
						else if(pvss-1<=kps.size())
							vsk(kps[kps.size()-pvss+1]);
						continue;
					}
				}
				else if(pv.size()>0)
				{
					if(!sl)
					{
						if(0)printf("ls %ld\n",pv[pv.size()-1]);
						if(0)printf("lss %ld\n",ls[pv[pv.size()-1]].vm.size());
					}
					gvm=ls[pv[pv.size()-1]];
					gv=gvm.vm;
					kps.push_back(kp);
					kp=pv[pv.size()-1];
					if(0)printf("k %lu\n",kp);
					bn=0;
					pv.pop_back();
				}
				else if(st.dpv.size()>0)
				{
					bn=1;
					gv={};
					auto p=st.dpv.front();
					for(size_t k=0;k<p.size();k++)
						gv.push_back(vkvl((unsigned char)p[k]));
					st.dpv.pop();
				}
				else if(yk==3||ls[kp].sv)
				{
					if(yk==3)yk=0;
					size_t s=1<<(pvss-1);
					size_t gs=kp;
					if(kp==0&&st.s==5)
						gs=0;
					else for(size_t k=0;k<s;k++)
						if(ls[gs].pv)gs=ls[gs].pv;
						else break;
					if(ccs=="kgs")
					{
						st.kgs++;
						if(st.kgs>10000)st.kgs-=10000;
						kgss();
					}
					else
					{
						if(gs!=kp)vsk(gs);
						continue;
					}
				}
				else if(yk==8)
				{
					yk=0;
					vsk(nvkk?nvk[nvkk-1]:vms);
					if(0)printf("nvkk %lu %lu\n",nvkk,nvk[nvkk-1]);
					if(nvkk<nvk.size())nvkk++;
					else nvkk=1;
					continue;
				}
				else if(yk==12)
				{
					if(0)printf("vs %lu\n",vs);
					yk=0;
					vsk(pvss);
					continue;
				}
				else if(yk==22)
				{
					yk=0;
					bn=1;
					gv=1?::vs({73,4,69,7,66,2,75,2,55,51,3,70,1,75}): ::vs({45,13,71,66,2,75,2,55,51,3,70,1,75});
					gvm={};
				}
				else if(yk!=0)
				{
					printf("yk %d\n",yk);
					yk=0;
					continue;
				}
				else continue;
				if(0&&!sl)printf("gvs %ld\n",gv.size());
				auto vvl=getenv("VVL");
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
				if(vvl)
					for(size_t k=0;k<gv.size();k++)
						printf("%lu ",vsks(gv[k]));
				if(vvl)printf("\n");
				const double ctdm=6000;
				double ct=ctdm;
				auto vp=[this,&ct,&ctdm,&mk]()
				{
					mt.execSynthesisStep();
					vsnsl++;
					auto p=[&](float ls)
					{
						while(svk&&vy.mc.ak(vy.d,vy.u)>mk*mt.outputSampleRate())
							std::this_thread::sleep_for(std::chrono::milliseconds(16));
						if(sl&&!svk)fwrite(&ls,sizeof(ls),1,stdout);
						if(svk)
						{
							vy.u=vy.mc.v(vy.u);
							vy.mc.k[vy.u]=ls;
						}
					};
					for(size_t k=0;k<mt.outputBuffer().size();k++)
					{
						double tp=mt.outputBuffer()[k];
						ct=std::max(ct,abs(tp));
						float ls=std::max(std::min(tp/ctdm,1.0),-1.0);
						p(ls);
					}
					if(mt.outputBuffer().size()>0)
					{
						sknlk+=mt.outputBuffer().size();
						vsnsl=0;
						mt.outputBuffer().resize(0);
					}
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
							sknls<<(sknlk+(size_t)((vsnsl*mt.outputSampleRate())/mt.internalSampleRate()))<<"\n";
							sknls.flush();
							vy.v=1;
						}
						if(pv.ss==v::ssp::u)
							ps(mt.PARAM_GLOT_PITCH,ds,dm*m1,1);
						if(pv.ss==v::ssp::a)
						{
							bool st=0;
							for(int nk=vk+1;nk<gv.size();nk++)
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
						double ks[mt.TOTAL_PARAMETERS];
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
				for(int dk=0;dk<(dvnn?4.0:0.5)*mk*mt.internalSampleRate();dk++)
					vp();
				vy.v=0;
				if(ct>ctdm)fprintf(stderr,"%lf > %lf @ %lu\n",ct,ctdm,sknlk);
				vss=0.001*(double)ks();
			}
			vy.v=0;
			if(!ck)
			{
				if(1)std::this_thread::sleep_for(std::chrono::milliseconds((int)(mk*1000.0)));
				break;
			}
		}
		unsigned long k=0;
		while(!ssv)
		{
			while(vy.mc.ak(vy.d,vy.u)<vy.mc.s-1)
			{
				vy.mc.k[vy.u]=sin(2.0*M_PI*100.0*(double)k/1024.0)*0.5;
				vy.u=vy.mc.v(vy.u);
				k++;
			};
			vy.v=1;
			if(ck==0)break;
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
		}
		vy.v=0;
	}
	size_t tk=0;
	int pt=0;
	static const int sks=32;
	char sk[sks+1];
	int skk=0;
	const size_t pgtv=300,dpgt=2000;
	void(*cvp)()=0;
	void nt(int t)
	{
		sk[sks]=0;
		if(0)printf("yk %d t %d\n",yk,t);
		if(t==10)
		{
			yk=0;
			ck=0;
			skk=0;
		}
		auto tn=[&sk=sk,&skk=skk](int k,unsigned char s)->bool
		{
			if(k<skk)return s==sk[k]-'0';
			else return 0;
		};
		if(t>-1)
		{
			tk=ks();
			if(skk<sks)
			{
				sk[skk]='0'+t;
				skk++;
				sk[skk]=0;
			}
			else if(yk==0){yk=22;skk=0;}
		}
		const size_t kk=::ks();
		if(0)printf("kk-tk %lu\n",kk-tk);
		if(kk-tk>pgtv&&(tn(0,6)||tn(0,3)))
		{
			if(yk==0)
			{
				vs=skk;
				yk=tn(0,6)?6:3;
			}
			skk=0;
			st.plg=1;
		}
		if((kk-tk>dpgt)&&(1?skk>0:tn(0,2)||tn(0,4)))
		{
			skk=0;
			st.plg=1;
			if(yk==0)yk=22;
		}
		if(t<0)return;
		if(tn(0,9)){if(!jt){ck=0;st.cs=0;}skk=0;}
		else if(tn(0,0))
		{
			if(0)st.vtp=1;
			skk=0;
			if(yk==0)
			{
			 	vs=165;
				yk=12;	
			}
		}
		else if(tn(0,8)){if(yk==0)yk=8;skk=0;}
		else if(tn(0,7))
		{
			skk=0;
			if(0)printf("ccs %s\n",ccs.c_str());
			if(jt&&(ccs.size()>0||st.cc))
			{
#ifdef EMSCRIPTEN
				if(ccs.ends_with(".mp4")||ccs.ends_with(".webm")||st.cc)
					EM_ASM({if(ccpd.psp==2||cc)
					{
						if(!cc)
						{
							pcpck=$0;
							cc=1;
							ccpd.currentTime=0;
							setTimeout(()=>ccpd.play(),pcpck);
						}
						else if(ccpd.paused){if(ccpd.currentTime<ccpd.duration)ccpd.play();}
						else if(0)ccpd.pause()
					}},ccs=="sc.mp4"?0:0);
				else if(ccs=="pts")EM_ASM({location.hash='pt';});
				else if(ccs=="nts")EM_ASM({location.hash='nt';});
				else if(ccs=="cls")EM_ASM({location.hash='cl';});
#endif
			}
		}
		else if(tn(0,1))
		{
			skk=0;
#ifdef EMSCRIPTEN
			if(!st.cc)EM_ASM({location.hash="ml";});
#endif
			if(cvp&&!jt)cvp();
		}
		else if(tn(0,5))
		{
			if(jt&&(ccs.ends_with(".mp4")||ccs.ends_with(".webm"))&&!st.cc)
			{
#ifdef EMSCRIPTEN
				EM_ASM({cdss($0);},ccs.c_str());
#endif
				skk=0;
			}
			else skk=0;
		}
		else if(tn(0,2))
		{
			if(t==8)
			{
				sk[skk-1]=0;
				size_t nvs=snsp(sk+1);
				skk=0;
				if(nvs==151*151){knp=1;vksk(0,1);}
				else if(yk==0)
				{
					if(nvs-1<nvk.size()&&nvs!=0)
					{
						nvkk=nvs+1;
						if(nvkk>nvk.size())nvkk=0;
						vs=nvk[nvs-1];
						if(0)printf("2...8 %lu\n",vs);
						yk=12;
					}
				}
			}
			else if(t==9)
				skk=0;
		}
		else if(tn(0,4))
		{
			skk=0;
			if(0&&t==0)
			{
				sk[skk-1]=0;
				if(yk==0)
				{
					vs=bkp(sk+1);
					yk=12;
				}
				skk=0;
			}
			else if(t==9)
				skk=0;
		}
	}
	static void pc(void *vy,Uint8 *d,int s)
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
};
struct sdvn
{
	void bvp(GS::VTM::VocalTractModel5<double,1> &mt,SDL_AudioSpec &sn,SDL_AudioDeviceID &ys,double ng)
	{
		mt.tgp(ng);
		SDL_PauseAudioDevice(ys,1);
		SDL_CloseAudioDevice(ys);
		sn.freq=ng;
		ys=SDL_OpenAudioDevice(NULL,0,&sn,NULL,0);
		SDL_PauseAudioDevice(ys,0);
	};
	SDL_AudioDeviceID ys;
	sdvn(int dns,void(*pc)(void*,unsigned char*,int),void* vy)
	{
		SDL_AudioSpec sn;
		sn.freq=dns;
		sn.format=AUDIO_F32;
		sn.samples=256;
		sn.callback=pc;
		sn.userdata=vy;
		sn.channels=1;
		ys=SDL_OpenAudioDevice(NULL,0,&sn,NULL,0);
		SDL_PauseAudioDevice(ys,0);
	}
	~sdvn()
	{
		SDL_PauseAudioDevice(ys,1);
		SDL_CloseAudioDevice(ys);
	}
};
#ifdef EMSCRIPTEN
struct jvn
{
	uint8_t vs[4096];
	struct ngp
	{
		void(*pc)(void*,unsigned char*,int);
		void* vy;
	};
	ngp ng;
	static void ppk(EMSCRIPTEN_WEBAUDIO_T pv,EM_BOOL ss,void* sg)
	{
		if(!ss)
		{
			printf("0 ppk\n");
			return;
		}
		WebAudioWorkletProcessorCreateOptions vk={.name="sv",};
		emscripten_create_wasm_audio_worklet_processor_async(pv,&vk,dpk,sg);
	}
	static void dpk(EMSCRIPTEN_WEBAUDIO_T pv,EM_BOOL ss,void* sg)
	{
		if(!ss)
		{
			printf("0 dpk\n");
			return;
		}
		int ns[1]={1};
		EmscriptenAudioWorkletNodeCreateOptions vk={.numberOfInputs=1,.numberOfOutputs=1,.outputChannelCounts=ns};
		[[maybe_unused]]EMSCRIPTEN_AUDIO_WORKLET_NODE_T vkk=emscripten_create_wasm_audio_worklet_node(pv,"sv",&vk,&tpk,sg);
		EM_ASM({window.pv=emscriptenGetAudioObject($0);
			window.vkk=emscriptenGetAudioObject($1);
			if(0)navigator.mediaDevices.getUserMedia({audio:true}).then(p=>{window.smss=p;window.smssk=pv.createMediaStreamSource(p);smssk.connect(vkk)});
			window.drk=(sk=0)=>{
			if(pv.state!='running'||sk)
			{
				pv.resume();
				vkk.connect(pv.destination);
			}
			else if(0)
			{
				pv.suspend();
			}};
			window.drk(1)
			},pv,vkk);
		sr++;
	}
	static EM_BOOL tpk(int,const AudioSampleFrame*,int nds,AudioSampleFrame* nd,int,const AudioParamFrame*,void* sg)
	{
		auto pg=(ngp*)sg;
		float d[128];
		pg->pc(pg->vy,(uint8_t*)d,sizeof(d));
		for(int k=0;k<nds;k++)
			for(int ppk=0;ppk<nd[k].numberOfChannels;ppk++)
				memcpy(&nd[k].data[ppk*128],d,sizeof(d));
		return EM_TRUE;
	}
	jvn(int dns,void(*dpc)(void*,unsigned char*,int),void* dvy)
	:ng({dpc,dvy})
	{
		EmscriptenWebAudioCreateAttributes vv={.latencyHint="interactive",.sampleRate=(uint32_t)dns};
		EMSCRIPTEN_WEBAUDIO_T pv=emscripten_create_audio_context(&vv);
		emscripten_start_wasm_audio_worklet_thread_async(pv,vs,sizeof(vs),ppk,&ng);
		if(0)printf("jvn\n");
	}
};
#endif
struct ntv
{

};
int nps(int n)
{
	if(n>4)
		return n-5;
	else if(n==-1||n==-2)
		return n;
	else return -1;
}
void dk()
{
	vksk();
	SDL_Init(SDL_INIT_EVERYTHING);
	static vks v;
	sdvn dn(v.mt.outputSampleRate(),v.pc,(void*)&v.vy);
	sr++;
	v.cvp=[](){st.ks=!st.ks;};
	v.dk=[](){sr++;};
	std::thread vkk([](){v.vk();});
	npk=[](int n)
	{
		v.nt(nps(n));
	};
	sr++;
	pmk();
	vkk.join();
	SDL_Quit();
}
void k(int p,bool lp=0,bool sl=0,bool svk=1)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	vksk();
	vks v={.lp=lp,.sl=sl,.svk=svk};
#ifdef EMSCRIPTEN
	typedef jvn dnp;
#else
	typedef sdvn dnp;
#endif
	dnp dn(v.mt.outputSampleRate(),v.pc,(void*)&v.vy);
	std::thread vkk([&v](){v.vk();});
	if(p>=0||(lp&&!sl))
	{
#ifdef KG
		Display *d=XOpenDisplay(0);
		for(int i=XK_KP_0;i<=XK_KP_9;i++)
		{
			XGrabKey(d,XKeysymToKeycode(d,i),16,DefaultRootWindow(d),0,GrabModeAsync,GrabModeAsync);
			XGrabKey(d,XKeysymToKeycode(d,i),16|LockMask,DefaultRootWindow(d),0,GrabModeAsync,GrabModeAsync);
		}
		XEvent g;
		while(v.ck)
		{
			while(XCheckMaskEvent(d,-1,&g))
			{
				if(g.type==KeyPress)
				{
					auto t=tns(XLookupKeysym(&(g.xkey),1));
					v.nt(t);
				}
			}
			v.nt(-1);
			v.ck=v.ck&ssk(p);
			const int kn=16;
			std::this_thread::sleep_for(std::chrono::milliseconds(kn));
		}
		XUngrabKey(d,AnyKey,AnyModifier,DefaultRootWindow(d));
#endif
	}
	else
	{
#ifndef EMSCRIPTEN
		if(!svk)SDL_PauseAudioDevice(dn.ys,1);
		while(v.ck&&!sl)
		{
			int t=0;
			std::cin>>t;
			v.nt(t);
		}
#endif
	}
#ifndef EMSCRIPTEN
	vkk.join();
	SDL_Quit();
#endif
}
void sln()
{
	std::ofstream s;
	s.open("sl",std::ios_base::app|std::ios_base::binary);
	char l='0';
	s.write(&l,1);
	s.close();
}
std::u8string vkk(const std::u8string pv,const std::u8string &k)
{
	std::u8string sk=pv+k;
	size_t ks=0;
	size_t ss=0;
	while(ks<sk.size())
	{
		char8_t n=sk[ks];
		if(n==1)sk[ss]++;
		else if(n==2)sk[ss]--;
		else if(n==3)ss++;
		else if(n==4)ss--;
		else if(n==5&&sk[0]==0)
		{
			ks=ss;
			continue;
		}
		ks++;
		if(ss>=sk.size())
		{
			size_t p=sk.size();
			sk.resize(ss+1);
			memset(&sk[p],0,sk.size()-p);
		}
	}
	return sk;
}
bool vg(const std::u8string &pv,const std::vector<std::pair<std::u8string,std::u8string>> &nds)
{
	bool ss=1;
	for(size_t k=0;k<nds.size();k++)
	{
		auto sk=vkk(pv,nds[k].first),d=nds[k].second;
		auto p=sk.substr(pv.size(),sk.size()-pv.size());
		if(1)
		{
			printf("\nv");
			for(size_t k=0;k<pv.size();k++)printf(" %d",(int)sk[k]);
			printf("\np");
			for(size_t k=0;k<p.size();k++)printf(" %d",(int)p[k]);
			printf("\nd");
			for(size_t k=0;k<d.size();k++)printf(" %d",(int)d[k]);
			printf("\n");
		}
		if(p!=d){ss=0;break;}
	}
	return ss;
}
uint8_t vts(const std::vector<uint8_t> &c,size_t v1,size_t v2,const std::vector<std::vector<std::vector<std::tuple<size_t,size_t>>>> &ks)
{
	uint8_t s=0;
	size_t cs=c.size()/(v1*v2*3);
	s=*std::max_element(std::begin(c),std::begin(c)+v1*v2*3);
	if(cs>0)s=fmax(s,*std::max_element(std::end(c)-v1*v2*3,std::end(c)));
	for(size_t k=1;k<fmax(cs-1,ks.size());k++)
	{
		for(size_t pk=0;pk<ks[k].size();pk++)
		{
			for(size_t ppk=0;ppk<ks[k][pk].size();ppk++)
			{
				size_t dk=ppk+1;
				if(dk==ks[k][pk].size())dk=0;

			}
		}
	}
	return s;
}
void vksk(bool l,bool knp)
{
	struct pp{bool p;size_t d;};
	std::vector<pp> p(ls.size());
	std::vector<bool> kcp(ls.size());
	for(size_t k=0;k<p.size();k++)
	{
		p[k].p=0;
		kcp[k]=0;
	}
	auto pl=[&p](size_t k,auto&& pl)->void
	{
		p[k].p=1;
		p[k].d=0;
		for(size_t pk=0;pk<ls[k].pbs.size();pk++)
			pl(ls[k].pbs[pk],pl);
	};
	pl(vms,pl);
	for(size_t k=0;k<ls.size();k++)
	{
		size_t pk=k;
		while(ls[pk].pv)
		{
			size_t nk=ls[pk].pv;
			kcp[nk]=1;
			if(!p[nk].p)
			{
				p[nk].p=1;
				p[nk].d=p[pk].d+1;
			}
			else if(p[nk].d>p[pk].d+1)
				p[nk].d=p[pk].d+1;
			else break;
			pk=nk;
		}
	}
	size_t nvks=0;
	nvk.resize(ls.size());
	for(size_t k=0;k<ls.size();k++)
	{
		if(!ls[k].nsv)
		{
				if(l)printf("%lu: ",k);
				if(p[k].p){if(l)printf("%lu",p[k].d);}
				else if(kcp[k]){if(l)printf("kcp");}
				else if(ls[k].cc.size()||knp)
				{
					nvk[nvks]=k;
					nvks++;
					if(l)printf("nvk %lu",nvks);
				}
				if(l)printf("\n");
		}
	}
	nvk.resize(nvks);
	if(l)for(size_t k=0;k<ls.size();k++)
	{
		if(ls[k].pv&&ls[k].nsv)
			printf("nsvpvk %lu\n",k);
		if(ls[k].pv&&ls[ls[k].pv].nsv)
			printf("pvnsvk %lu %lu\n",k,ls[k].pv);
	}
	if(l)
	{
		std::vector<bool> nv(ls.size());
		for(size_t k=0;k<ls.size();k++)
		{
			if(ls[k].nv)nv[ls[k].nv]=1;
			if(ls[k].vpv)nv[ls[k].vpv]=1;
		}
		for(size_t k=0;k<ls.size();k++)
			if(ls[k].nsv&&!nv[k])
				printf("nkv %lu\n",k);
	}
	for(size_t k=0;k<ls.size();k++)
		if(ls[k].nv&&ls[ls[k].nv].nv==ls[k].nv)
			printf("pb %lu %lu\n",k,ls[k].nv);
}

#ifndef EMSCRIPTEN
void spn(std::string sn)
{
	vksk();
	SDL_Init(SDL_INIT_EVERYTHING);
	static vks v;
	sdvn dn(v.mt.outputSampleRate(),v.pc,(void*)&v.vy);
	sr++;
	v.dk=[](){sr++;};
	std::thread vkk([](){v.vk();});
	sr++;
	printf("\033[1m");
	printf("\033[?1049h");
	fflush(stdout);
	struct termios p,n;
	tcgetattr(STDIN_FILENO,&p);
	n=p;
	n.c_lflag&=~(ECHO|ICANON|ISIG);
	n.c_iflag&=~(IXON|ICRNL);
	n.c_oflag&=~OPOST;
	n.c_cc[VMIN]=1;
	n.c_cc[VTIME]=0;
	tcsetattr(STDIN_FILENO,TCSANOW,&n);
	struct winsize vd;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&vd);
	st.dp.v=vd.ws_col;
	st.dp.dv=vd.ws_row;
	mlk.lvs=1;
	mlk.sn=sn;
	mlk.pk();
	int nd=0;
	while(st.cs)
	{
		nd=getchar();
		mlk.nk(nd);
	}
	printf("\033[?1049l");
	printf("\033[0m");
	fflush(stdout);
	tcsetattr(STDIN_FILENO,TCSANOW,&p);
	v.ck=0;
	st.cs=0;
	vkk.join();
	SDL_Quit();
}
int main(int argc,char** argv)
{
	if(argc<2)
	{
		printf("0|1?\n");
		return 0;
	}
	int dn=atoi(argv[1]);
	if(!dn)return 0;
	else if(dn==3)
		k(-1,1);
	else if(dn==6)
		k(-1,1,1,0);
	else if(dn==13)
		k(-1,1,1,1);
	else if(dn==14)
	{
		if(argc>2)
			spn(argv[2]);
	}
	else if(dn==2)
	{
		GS::VTM::VocalTractModel5<double,1> mt;
		while(mt.outputBuffer().size()==0)
			mt.execSynthesisStep();
		printf("%lf,%lf,%lu\n",mt.internalSampleRate(),mt.outputSampleRate(),mt.outputBuffer().size());
		bck<int> k(2,3);
		k.d(0,0)=1;
		for(int i=0;i<2*3;i++)
			printf("%d,",k.k[i]);
		printf("\n");
	}
	else if(dn==5)
	{
		vksk(1);	
	}
	else if(dn==4)
	{
		std::array<size_t,27> pv={1,4,7,10,13,19,25,31,37,43,44,45,46,47,48,49,53,55,58,60,63,65,68,70,73,75,76};
		size_t vk=atoi(argv[2]);
		GS::VTM::VocalTractModel5<double,1> mt;
		mt.setParameter(mt.PARAM_GLOT_PITCH,-12);
		mt.setParameter(mt.PARAM_GLOT_VOL,60);
		mt.setParameter(mt.PARAM_ASP_VOL,0);
		mt.setParameter(mt.PARAM_FRIC_VOL,0);
		mt.setParameter(mt.PARAM_FRIC_POS,0);
		mt.setParameter(mt.PARAM_VELUM,0);
		mt.setParameter(mt.PARAM_RR0,0);
		mt.setParameter(mt.PARAM_RR1,0);
		for(int k=0;k<8;k++)
			mt.setParameter(mt.PARAM_R1+k,vm(vc[pv[vk]],k));
		mt.setParameter(mt.PARAM_R6A,sdvm(vc[pv[vk]]));
		mt.setParameter(mt.PARAM_VELUM,vc[pv[vk]].n);
		while(mt.outputBuffer().size()<mt.outputSampleRate()*0.03)
			mt.execSynthesisStep();
		auto vs=std::ofstream("/tmp/v",std::ios::binary);
		double ct=12000;
		for(size_t k=0;k<mt.outputBuffer().size();k++)
		{
			double s=mt.outputBuffer()[k];
			if(abs(s)>ct)ct=abs(s);
			s/=ct;
			vs.write(reinterpret_cast<char*>(&s),sizeof(double));
		}
		vs.close();
	}
	else if(dn==7)
		k(-1);
	else if(dn==8)
	{
		dk();
	}
	else if(dn==9)
	{
		auto p=[](const std::u8string &p,const std::u8string &d){return std::make_pair(p,d);};
		printf("%d\n",vg({0},{p({1},{1})}));
	}
	else if(dn==10)
	{
		sln();
	}
	else if(dn==11)
	{
		if(argc<3)return 0;
		auto s=atoi(argv[2]);
		while(s>0)
		{
			printf("%d",s%8);
			s/=8;
		}
		printf("\n");
	}
	else if(dn==12)
	{
		int vd=5;
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
			printf("%d %d %f\n",tk.bs1,tk.bs2,tk.b);
		}
		while(!(tk.bs1==vd-1&&tk.bs2==-1));
	}
#ifdef KG
	else if(dn==1||dn==0)
	{
		es([](int p){k(p);},dn==1);
	}
#endif
	return 0;
}
#else
struct
{
	vks v={.jt=1};
	jvn *dp;
	std::thread vkk;
}sl;
extern "C"
{
EMSCRIPTEN_KEEPALIVE
int rk()
{
	vksk();
	sl.dp=new jvn(sl.v.mt.outputSampleRate(),sl.v.pc,(void*)&sl.v.vy);
	if(0)printf("rk\n");
	sl.v.dk=[](){sr++;};
	sl.v.cvp=[]()
	{
		st.ks=!st.ks;
		st.clvp=1;
	};
	sl.vkk=std::thread([](){sl.v.vk();});
	if(0)pmk();
	emscripten_set_main_loop(nk,0,0);
	return 0;
}
EMSCRIPTEN_KEEPALIVE 
void nt(int n)
{
	static bool dsr=0;
	if(n!=-1||!dsr)
	{
		dsr=1;
		EM_ASM({drk()});
	}
	sl.v.nt(n);
}
EMSCRIPTEN_KEEPALIVE 
void sn(int n)
{
	if(0)printf("yk %d\n",sl.v.yk);
	if(sl.v.yk==0)
	{
		sl.v.vs=n;
		sl.v.yk=12;	
	}
}
void npks(int n)
{
	if(0)printf("n %d\n",n);
	nt(nps(n));
}
int main()
{
	npk=npks;
	st.svsb.skk=&sl.v.skk;
	st.svsb.ccs=&sl.v.ccs;
	st.svsb.yk=&sl.v.yk;
	rk();
	return 0;
}
}
#endif
