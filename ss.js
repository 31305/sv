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
			m.respondWith(fetch(new Request(self.location.origin+'/sks',{method:"GET"}))
				.then(p=>{
					if(p.status==404)return caches.match(m.request);
					mk();
					return p.text().then(p=>{ph=p;return pk(m,ph)})
				})
				.catch(()=>ph=='p'?caches.match(m.request):pk(m,ph))
			)
		}
		else if(!m.request.url.endsWith('mp4'))m.respondWith(pk(m,ph));
		else m.respondWith(pk(m,nh));
	}
});
