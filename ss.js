ph='p';
const nh='cs';
self.addEventListener('install',(p)=>{p.waitUntil(self.skipWaiting())});
self.addEventListener('activate',(p)=>{p.waitUntil(clients.claim())});
function mk()
{
	const hs=[ph,nh];
	caches.keys().then(p=>{return p.filter(p=>!hs.includes(p));}).
	then(p=>{return Promise.all(p.map(d=>{return caches.delete(d);}));})
}

function pk(m,kn)
{
	if(m.request.cache!=='reload')console.log('nnp',m.requset.url)
	return caches.open(kn).then(k=>{return k.match(m.request).then(p=>{
		if(p){return p;};
		return fetch(m.request).then(p=>{return k.put(m.request,p.clone()).then(()=>{return p;});});
	})})
}
self.addEventListener('fetch',m=>{
	if(m.request.url.startsWith(self.location.origin))
	{
		if(ph=='p'||m.request.url.length<=self.location.origin.length+1||m.request.url.includes('html'))
		{
			m.respondWith(fetch(new Request(self.location.origin+'/sks?'+Date.now().toString(),{method:"GET"}))
				.then(p=>{
					if(!p.ok)return caches.match(m.request);
					return p.text().then(p=>{ph=p;mk();return pk(m,ph)})
				})
				.catch(()=>ph=='p'?caches.match(m.request):pk(m,ph))
			)
		}
		else if(!m.request.url.endsWith('mp4'))m.respondWith(pk(m,ph));
		else m.respondWith(pk(m,nh));
	}
});
