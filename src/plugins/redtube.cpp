#include "../helper.h"

using namespace std;

//redtube.com -last check: 2011-12-30
//example: http://videos.flv2.redtubefiles.com/_videos_t4vn23s9jc5498tgj49icfj4678/0000090/_h264flv/0090017.flv?47aac1f74dca44b0626f9b5acf21d75cd5dee7e8937c9cd51b27114cbb64d1abdacd57b1c8f7662835b5852858f0556998fb41dad6317b0e2c76&ec_seek=49672846
int redtube(string *domain, string *urlf)
{
	if(regexMatch("\\.redtubefiles\\.com/$", *domain)){
		if(regexMatch("^http://(img..|videos\\.flv.{0,1})\\.redtubefiles\\.com/", *domain)){
			*urlf = "http://redtube.inComum/" + get_path(*urlf, 'Y') + "?start=" + get_var(*urlf, "ec_seek");
		}
		return 1;
	}
	return 0;
}
