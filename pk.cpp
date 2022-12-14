#include"VocalTractModel5.h"
#include<thread>
void k1()
{
	GS::VTM::VocalTractModel5<double,1> mt;
	const double kk=16;
	while(1)
	{
		for(int k=0;k<kk*0.001*mt.internalSampleRate();k++)
		{
			mt.execSynthesisStep();	
			if(mt.outputBuffer().size()>0)mt.outputBuffer().resize(0);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds((int)kk));
	}
}
void k2()
{
	GS::VTM::VocalTractModel5<double,1> mt;
	for(int k=0;k<100.0*mt.internalSampleRate();k++)
	{
		mt.execSynthesisStep();	
		if(mt.outputBuffer().size()>0)mt.outputBuffer().resize(0);
	}
}
void k3()
{
	const double kk=16;
	while(1)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds((int)kk));
	}

}
int main()
{
	k1();
	return 0;
}
