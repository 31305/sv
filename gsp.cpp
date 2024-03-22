#include<chrono>
#include</usr/include/swephexp.h>
int main()
{
	double tp[20];
	char ps[1024];
	std::time_t k=std::time(0);
	std::tm* tk=std::gmtime(&k);
	swe_set_ephe_path(0);
	swe_utc_to_jd(1900+tk->tm_year,1+tk->tm_mon,tk->tm_mday,tk->tm_hour,tk->tm_min,tk->tm_sec,1,tp,ps);
	double ks=tp[1];
	swe_pheno_ut(ks,SE_MOON,SEFLG_SWIEPH,tp,ps);
	[[maybe_unused]]double cd=tp[1];
	auto kks=swe_calc_ut(ks,SE_SUN,SEFLG_SWIEPH,tp,ps);
	if(!(kks&SEFLG_SWIEPH))printf("ns %d\n",kks);
	double ss=tp[0];
	swe_calc_ut(ks,SE_MOON,0,tp,ps);
	double cs=tp[0];
	printf("cs %lf \n",std::fmod(swe_difdegn(cs,ss)*30/360+15,30.0));
	printf("ss %dm+%lfd\n",(int)(ss/30),fmod(ss,30));
	return 0;
}
