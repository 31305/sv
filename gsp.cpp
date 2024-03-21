#include<chrono>
#include</usr/include/swephexp.h>
int main()
{
	double tp[20];
	char ps[1024];
	std::time_t k=std::time(0);
	std::tm* tk=std::gmtime(&k);
	swe_utc_to_jd(1900+tk->tm_year,1+tk->tm_mon,tk->tm_mday,tk->tm_hour,tk->tm_min,tk->tm_sec,1,tp,ps);
	swe_pheno_ut(tp[1],1,0,tp,ps);
	printf("cs %lf\n",tp[1]);
	return 0;
}
