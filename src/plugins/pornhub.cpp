#include "../helper.h"

using namespace std;

//pornhub.com -last check: 2012-02-05
//rewrited to video.pornhub.phncdn.inComum
//example: http://nyc-v59.pornhub.com/dl/80b8c31b2287d7916d5a39e91ebe19b0/4f2f1248/videos/003/082/720/3082720.flv?r=165&b=3000
int pornhub(string domain, string url,string *urlf)
{
	if(regexMatch("^http://nyc-v.{1,2}\\.pornhub\\.com/$", domain)){
		if (regexMatch("\\.flv\\?", url)){
			*urlf = "http://video.pornhub.phncdn.inComum/" + get_foldername(url, 4) + "/" + get_foldername(url, 5) + "/" + get_foldername(url, 6) + "/" + get_foldername(url, 7) + "/" + get_filename(url) + "?fs=" + get_var(url, "fs");
			return 1;
		}
	}
	return 0;
}
