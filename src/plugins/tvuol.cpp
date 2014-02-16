#include "../helper.h"

using namespace std;

//TV UOL plugin - last check 2011-12-30
//example1: http://video7.mais.uol.com.br/12381354.mp4?ver=1
//example2: http://storage.mais.uol.com.br/12304309.flv?cfmhwNs,bhpIoqWzmeyNg
//example3: http://thumb.mais.uol.com.br/12093127-medium.jpg?ver=1
//example4: http://videohd3.mais.uol.com.br/13200230.mp4?ver=0&r=http%3A%2F%2Fplayer.mais.uol.com.br%2Fembed_v2.swf%3FmediaId%3D13200230%26p%3Dtvuol
int tvuol(string *domain, string *urlf)
{

	if(regexMatch("\\.uol\\.com\\.br/$", *domain)){
		if(regexMatch("^http://(video.{1,3}|thumb|storage)\\.mais\\.uol\\.com\\.br/", *domain)){
			if(regexMatch("\\.(mp4|flv|jpg)\\?", *urlf)){
				*urlf = "http://maisuol.inComum/" + get_path(*urlf,'Y');
			}
		}
		return 1;
	}
	return 0;
}

//Request/Response example
//
//http://videohd4.mais.uol.com.br/13200230.mp4?ver=0&r=http%3A%2F%2Fplayer.mais.uol.com.br%2Fembed_v2.swf%3FmediaId%3D13200230%26p%3Dtvuol
//
//GET http://videohd4.mais.uol.com.br/13200230.mp4?ver=0&r=http%3A%2F%2Fplayer.mais.uol.com.br%2Fembed_v2.swf%3FmediaId%3D13200230%26p%3Dtvuol HTTP/1.1
//Host: videohd4.mais.uol.com.br
//User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:17.0) Gecko/20100101 Firefox/17.0
//Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
//Accept-Language: pt-br,en-us;q=0.7,en;q=0.3
//Accept-Encoding: gzip, deflate
//Proxy-Connection: keep-alive
//Referer: http://player.mais.uol.com.br/embed_v2.swf?mediaId=13200230&p=tvuol
//Cookie: UOL_VIS=B|189.21.38.19|1291766318.559116|1357367070; s_vi=[CS]v1|267F65328514A7B3-400001646004D59F[CE]; __utma=187695351.1461417619.1322756438.1322756438.1322756438.1; RMTRK.ID=b2630c99-757b-4ed4-bbf1-55352a5e047d; s_sess=%20s_cc%3Dtrue%3B%20s_sq%3D%3B; s_pers=%20s_visit%3D1%7C1358649035931%3B
//
//HTTP/1.0 200 OK
//Server: balaio 1.0.11
//Date: Sat, 19 Jan 2013 23:01:11 GMT-03:00
//Cache-Control: no-cache
//Pragma: no-cache
//Expires: Thu, 01 Dec 1994 16:00:00 GMT
//Content-Type: video/mp4
//Cache-Hit: HIT-OLD
//Vary: User-Agent
//Last-Modified: Sat, 19 Jan 2013 09:44:41 GMT-03:00
//Accept-Ranges: bytes
//Content-Length: 8088898
//X-Cache: MISS from ta_de_brinks
//X-Cache-Lookup: MISS from ta_de_brinks:3128
//Via: 1.1 ta_de_brinks:3128 (squid/2.7.STABLE9)
//Connection: keep-alive
//Proxy-Connection: keep-alive