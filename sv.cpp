#include"VocalTractModel5.h"
#include<SDL.h>
#include<ncurses.h>
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
int main()
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
	initscr();
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	while(1)
	{
		char g=getch();
		if(g=='0'||1)break;
	}
	endwin();
	SDL_Quit();
	return 0;
}
