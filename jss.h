#include<emscripten/webaudio.h>
#include<cstdio>
#include<functional>
struct jvn
{
	uint8_t vs[4096];
	std::function<void()> pk;
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
			fprintf(stderr,"0 ppk\n");
			return;
		}
		WebAudioWorkletProcessorCreateOptions vk={.name="svjs",};
		emscripten_create_wasm_audio_worklet_processor_async(pv,&vk,dpk,sg);
	}
	static void dpk(EMSCRIPTEN_WEBAUDIO_T pv,EM_BOOL ss,void* sg)
	{
		if(!ss)
		{
			fprintf(stderr,"0 dpk\n");
			return;
		}
		int ns[1]={1};
		EmscriptenAudioWorkletNodeCreateOptions vk={.numberOfInputs=1,.numberOfOutputs=1,.outputChannelCounts=ns};
		[[maybe_unused]]EMSCRIPTEN_AUDIO_WORKLET_NODE_T vkk=emscripten_create_wasm_audio_worklet_node(pv,"svjs",&vk,&tpk,sg);
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
		((jvn*)sg)->pk();
	}
	static EM_BOOL tpk(int,const AudioSampleFrame*,int nds,AudioSampleFrame* nd,int,const AudioParamFrame*,void* sg)
	{
		auto pg=((jvn*)sg)->ng;
		float d[128];
		pg.pc(pg.vy,(uint8_t*)d,sizeof(d));
		for(int k=0;k<nds;k++)
			for(int ppk=0;ppk<nd[k].numberOfChannels;ppk++)
				memcpy(&nd[k].data[ppk*128],d,sizeof(d));
		return EM_TRUE;
	}
	jvn(int dns,void(*dpc)(void*,unsigned char*,int),void* dvy,std::function<void()> dpk)
	:pk(dpk),ng({dpc,dvy})
	{
		EmscriptenWebAudioCreateAttributes vv={.latencyHint="interactive",.sampleRate=(uint32_t)dns};
		EMSCRIPTEN_WEBAUDIO_T pv=emscripten_create_audio_context(&vv);
		emscripten_start_wasm_audio_worklet_thread_async(pv,vs,sizeof(vs),ppk,this);
		if(0)printf("jvn\n");
	}
};
