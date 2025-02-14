const ph='p9';
const nh='n3';
const phs=['5.html','sv.js','sv.data','sv.wasm','sv.aw.js','sv.ww.js'];

self.addEventListener('install',p=>{p.waitUntil(caches.open(ph).then(p=>p.addAll(phs)).then(self.skipWaiting()))});

self.addEventListener('activate',p=>{const hs=[ph,nh];p.waitUntil(caches.keys().then(p=>{return p.filter(p=>!hs.includes(p));}).
	then(p=>{return Promise.all(p.map(d=>{return caches.delete(d);}));}).then(()=>self.clients.claim()));});

self.addEventListener('fetch',m=>{if(m.request.url.startsWith(self.location.origin)){m.respondWith(caches.match(m.request).then(p=>{if(p){return p;};
	return caches.open(nh).then(d=>{return fetch(m.request).then(p=>{return d.put(m.request,p.clone()).then(()=>{return p;});});});
}));}});
