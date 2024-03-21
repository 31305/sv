#include</usr/include/swephexp.h>
int main()
{
	double tp[20];
	char ps[1024];
	double sk=2460390.78194;
	swe_pheno_ut(sk+4,1,0,tp,ps);
	printf("cs %lf\n",tp[1]);
	return 0;
}
