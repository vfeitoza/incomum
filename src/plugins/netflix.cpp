#include "../helper.h"

using namespace std;

//netflix plugin - images and videos 
int netflix(string *domain, string *urlf)
{
	// Videos
	// example iphone: http://nflx.i.bb5e2042.x.br.lvl3.nflxvideo.net/latam/883/700408883.ts.prdy/range/188-7143?etime=20120415024000&movieHash=839&encoded=04a94af83241f35f20061
	// example1 silverlight: http://nflx.i.bb5e201b.x.br.lvl3.nflxvideo.net/latam/891/700485891.isma/range/1501369-1635892?etime=20120415025608&movieHash=839&encoded=0a61864ead69780507295&random=625768884
	// example2 silverlight: http://nflx.i.bb5e201b.x.br.lvl3.nflxvideo.net/latam/325/589848325.ismv/range/41644778-42229775?etime=20120415025608&movieHash=839&encoded=05321af8708a9acfd271e&random=1358775216
	// example3 silverlight: http://netflix391.pop3.la.nflximg.com.edgesuite.net/la22/033/1177907033.ismv/range/17072131-17768721?token=1339290268_a18b7a0b2723c290bf35bca6faa54878&random=456455169
	// example4 silverlight: http://nflx.i.bb216402.x.br.lvl3.nflxvideo.net/latam/489/1377688489.isma?etime=20120609224020&movieHash=652&encoded=01ba65b3601381731eb95
	if(regexMatch("(nflxvideo|nflximg\\.com\\.edgesuite)\\.net/$", *domain)){
		if (regexMatch("(\\.ism(a|v)|(\\.ts\\.prdy))", *urlf)){
			*urlf = "http://netflix.inComum/" + get_path(*urlf, 'Y') + "?movieHash=" + get_var(*urlf, "movieHash");
		}
		return 1;
	}
	
	// Images
	// example image: http://cdn-9.nflximg.com/pt_latam/boxshots/large/60004479.jpg
	if (regexMatch("^http://cdn-.\\.nflximg\\.com/$", *domain)){
		*urlf = "http://netflix.inComum/" + get_path(*urlf, 'Y');
		return 1;
	}
	
	return 0;
}
