#include<cairo.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
constexpr int v=389;
constexpr int dk=359,nk=3618;
constexpr int kcs=15;
void css()
{
	for(int k=dk;k<=nk;k++)
	{
		char sn[100];
		sprintf(sn,"cs/1/%4d.png",k);
		for(int k=0;sn[k]!=0;k++)
			if(sn[k]==' ')
				sn[k]='0';
		printf("\r%s",sn);
		fflush(stdout);
		cairo_surface_t* c[2];
		c[0]=cairo_image_surface_create_from_png(sn);
		c[1]=cairo_image_surface_create(cairo_image_surface_get_format(c[0]),v*2,v*2);
		int gs[2];
		gs[0]=cairo_image_surface_get_stride(c[0]);
		gs[1]=cairo_image_surface_get_stride(c[1]);
		unsigned char *ls[2];
		ls[0]=cairo_image_surface_get_data(c[0]);
		ls[1]=cairo_image_surface_get_data(c[1]);
		for(int pd=0;pd<v*2;pd++)
		{
			for(int dd=0;dd<v*2;dd++)
			{
				double d=(pd-v)*(pd-v)+(dd-v)*(dd-v);
				if(d>=v*v)continue;
				double svs=(double)v*0.9;
				bool sv=d>svs*svs;
				double gm=1.0/((double)(v*v)-svs*svs);
				for(int vk=0;vk<3;vk++)
				{
					unsigned char m=ls[0][(pd+189)*gs[0]+(dd+603)*4+vk];
					if(sv)m=(unsigned char)fmin(fmax((double)m*((double)(v*v)-d)*gm,0.0),255.0);
					ls[1][pd*gs[1]+dd*4+vk]=m;
					if(0)ls[1][pd*gs[1]+dd*4+3]=255;
				}
			}
		}
		sprintf(sn,"cs/2/%4d.png",k);
		for(int k=0;sn[k]!=0;k++)
			if(sn[k]==' ')
				sn[k]='0';
		cairo_surface_write_to_png(c[1],sn);
		cairo_surface_destroy(c[0]);
		cairo_surface_destroy(c[1]);
	}
	printf("\n");
}
int main(int ls,char** lss)
{
	if(ls<2)return 0;
	int d=atoi(lss[1]);
	if(d==1)
	{
		system("mkdir -p cs/1");
		system("mkdir -p cs/2");
		system("ffmpeg -i VID_20231023_113544.mp4 cs/1/%4d.png");
	}
	else if(d==2)
		css();
	else if(d==3)
	{
		auto c=cairo_image_surface_create(CAIRO_FORMAT_RGB24,v*2,v*2);
		char sn[100];
		sprintf(sn,"kc.png");
		cairo_surface_write_to_png(c,sn);
		for(int k=1;k<=kcs;k++)
		{
			char d[1024];
			char sn[100];
			sprintf(sn,"cs/2/%4d.png",dk-k);
			for(int k=0;sn[k]!=0;k++)
				if(sn[k]==' ')
					sn[k]='0';
			sprintf(d,"cp kc.png %s",sn);
			system(d);
			sprintf(sn,"cs/2/%4d.png",nk+k);
			for(int k=0;sn[k]!=0;k++)
				if(sn[k]==' ')
					sn[k]='0';
			sprintf(d,"cp kc.png %s",sn);
			system(d);
		}

	}
	else if(d==4)
	{
		char d[1024];
		sprintf(d,"ffmpeg -start_number %d -framerate 30 -i cs/2/%%4d.png -crf:v 20 -pix_fmt yuv420p pc.mp4",dk-kcs);
		system(d);
		system("ffmpeg -i pc.mp4 -c:v copy kc.mp4");
		system("mv kc.mp4 pc.mp4");
	}
	return 0;
}
