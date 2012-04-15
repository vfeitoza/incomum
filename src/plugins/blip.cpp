#include "../helper.h"

using namespace std;

//blip.tv plugin - last check 2012-02-02
//example: http://a14.video2.blip.tv/10020009553710/GiselleAchecar-EcoRicoEp007232.m4v?brs=2493&bri=12.2
//example: http://j14.video2.blip.tv/10020009553710/GiselleAchecar-EcoRicoEp007232.m4v?brs=2493&bri=12.2&showplayer=20120110140747&start=201&referrer=http://blip.tv
//example: http://j2.video2.blip.tv/12950010298587/Sexynerdgirl-Vlog111Follywood875.m4v?brs=2782&bri=4.5&showplayer=20120110140747&start=3&referrer=http://blip.tv
int blip(string domain, string url, string *urlf)
{
	if(regexMatch("\\.blip\\.tv/$", domain)){
		if(regexMatch("video.*m4v", url)){
			*urlf = "http://bliptv.inComum/" + get_path(url,'Y') + "?start=" + get_var(url,"start");
			return 1;
		}
	}
	return 0;
}
