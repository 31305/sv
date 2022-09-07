#include"VocalTractModel5.h"
#include<SDL.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<unistd.h>
struct v
{
	enum csp{k,t,m,d,o,kt,od,ko};
	csp cs;
	bool n;
	bool vs,ns,nt,sv;
	bool sd;
	enum ssp{u,a,s};
	ssp ss;
	int vv;
	bool mp,sg;
};
struct ck
{
	int s;
	ck(int ds){s=ds;k=new double[s];}
	~ck(){delete k;}
	double *k;
	int u,d;
	int ak(){if(u>d)return u-d;else return u+s-d;}
};
struct b
{
	GS::VTM::VocalTractModel5<double,1> m;
};
void pc(void *,Uint8 *d,int s)
{
	for(int k=0;k<s;k++)
		d[k]=sin(2.0*M_PI*100.0*(double)k/1024.0)*127+128;
}
void es(void(*k)(int),bool n)
{
	const char* sn="/tmp/svs629";
	mkfifo(sn,S_IRWXU);
	int p=fork();
	if(p==0)
	{
		int ss=open(sn,O_RDONLY|O_NONBLOCK);
		if(!flock(ss,LOCK_EX|LOCK_NB))
			k(ss);
	}
	else if(p>0)
	{
		int ss=open(sn,O_WRONLY);
		char s='0';
		if(n)s='1';
		write(ss,&s,1);
	}
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
void k(int p)
{
	SDL_Init(SDL_INIT_AUDIO);
	SDL_AudioSpec sn;
	sn.freq=22000;
	sn.format=AUDIO_U8;
	sn.samples=1024;
	sn.callback=pc;
	sn.userdata=NULL;
	sn.channels=1;
	SDL_OpenAudio(&sn,NULL);
	SDL_PauseAudio(0);
	bool ck=1;
	while(ck)
	{
		ck=ssk(p);
		SDL_Delay(16);
	}
	SDL_Quit();
}
int main(int argc,char** argv)
{
	if(argc<2)
		printf("0|1?\n");
	else es(k,argv[1][0]!='0');
	return 0;
}
