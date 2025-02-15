ph='p11';
const nh='n5';

if(0)
{
	phs=['/','5.html','sv.js','sv.data','sv.wasm','sv.aw.js','sv.ww.js'];
	self.addEventListener('install',p=>{p.waitUntil(caches.open(ph).then(p=>p.addAll(phs)).then(self.skipWaiting()))});
}

if(0)self.addEventListener('activate',p=>{const hs=[ph,nh];p.waitUntil(caches.keys().then(p=>{return p.filter(p=>!hs.includes(p));}).
	then(p=>{return Promise.all(p.map(d=>{return caches.delete(d);}));}).then(()=>self.clients.claim()));});
self.addEventListener('activate',p=>{p.waitUntil(self.clients.claim());});
function mk()
{
	const hs=[ph,nh];
	caches.keys().then(p=>{return p.filter(p=>!hs.includes(p));}).
	then(p=>{return Promise.all(p.map(d=>{return caches.delete(d);}));})
}

function pk(m,kn)
{
	m.respondWith(caches.open(kn).then(k=>{return k.match(m.request).then(p=>{
		if(p){return p;};
		return fetch(m.request).then(p=>{return k.put(m.request,p.clone()).then(()=>{return p;});});
	})}))
}


self.addEventListener('fetch',m=>{
	if(m.request.url.startsWith(self.location.origin))
	{
		if(1)pk(m,nh)
		else if(m.request.url.length<=self.location.origin.length+1||m.request.url.endsWith('html'))
		{
			fetch(new Request(self.location.origin+'sks',{method:"GET"}))
			.then(p=>{
				ph=p.text().then(p=>{ph=p})
			})
			.catch(pk(m,ph))
		}
		else if(m.request.url.includes('/sv.'))pk(m,ph);
		else pk(m,nh);
	}
});
