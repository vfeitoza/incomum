#include "../helper.h"

using namespace std;

// googlesyndication.com plugin
// example1: http://o-o.preferred.nqt-gig1.v2.cache.c.googlesyndication.com/videoplayback/id/c46309509f2dc031/itag/18/source/gfp_video_ads/ip/0.0.0.0/ipbits/0/expire/1340905636/sparams/ip,ipbits,expire,id,itag,source/signature/5997E88BF4206E2BA98BCB5DD6B6A805E302D7FB.151C53332C6FC438094A24D62B1175171B13342C/key/ck1.mp4?ms=nvh&mt=1340883914&cms_redirect=yes
// example2: http://o-o.preferred.tiws-gru4.v21.cache.c.googlesyndication.com/videoplayback/id/1a74e7b18bf6ccc2/itag/5/source/gfp_video_ads/ip/0.0.0.0/ipbits/0/expire/1340910725/sparams/ip,ipbits,expire,id,itag,source/signature/5B275D671CC051EB6792E9ACC2097F742DBD65C6.1105A2E1FA790051C44AA9DFF6B1A6319B281201/key/ck1.flv?ms=nvh&mt=1340889015&cms_redirect=yes
// rewrite to: http://googlesyndication.inComum/videoplayback/id/XXXXXXX/itag/X/source/XXXXXXX/key/XXXXXXX

int googlesyndication(string *domain, string *url, string *urlf)
{
	if(regexMatch("\\.googlesyndication\\.com/$", *domain)){
		if(url->find("/videoplayback") != string::npos && url->find("cms_redirect=yes") != string::npos){
			*urlf = "http://googlesyndication.inComum/" + get_foldername(*url,1) + "/" + get_foldername(*url,2) + "/" + get_foldername(*url,3) + "/" + get_foldername(*url,4) + "/" + get_foldername(*url,5) + "/" + get_foldername(*url,6)  + "/" + get_foldername(*url,7) + "/" + get_foldername(*url,18) + "/" + get_filename(*url);
		}
		return 1;
	}
	return 0;
}
