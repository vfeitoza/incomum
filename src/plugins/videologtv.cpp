#include "../helper.h"

using namespace std;

//Videolog.tv plugin - last check: 2012-03-05
//example1: http://play-cdn3ch.videolog.tv/videos/2457ccdf33a0ad7a429fe1c35e6276bd/4eedf191/a7/c4/728988.mp4?start=0
//example2: http://cdn-play1.videolog.tv/videos/e71392e28918556fcda405297fb5f5ba/4eedf378/9c/5c/730043.mp4?start=0
//example3: http://cdn-br.videolog.tv/e3/8b/740092.mp4?epochTTL=1336008481&token=ca416eeb04e5e4e302bf1038738259e4&ri=10485760&rs=600&start=0
//example4: http://play-cdn3ch.videolog.tv/videos/21310683967ce91ce95ba418f015df9c/4eedf2dd/a7/c4/728988_HD.mp4?start=0
int videologtv(string *domain, string *urlf)
{
	if(regexMatch("videolog.tv\\/$", *domain)){
		if(regexMatch("cdn", *domain) && regexMatch("\\.mp4$", get_filename(*urlf))){
			*urlf = "http://videologtv.inComum/" + get_filename(*urlf) + "?start=" + get_var(*urlf,"start") + "&rs=" + get_var(*urlf, "rs");
		}
		return 1;
	}
	return 0;
}
