#include "../helper.h"

using namespace std;

//vimeo plugin - last check: 2012-03-29
//example: http://av.vimeo.com/79146/961/44048636.mp4?aksessionid=092cfa1ba7d4500771e530a1ed1201ed&token=1333042766_2b2fd33e8b8324cc4a8e3c3afe1b8b1b
int vimeo(string *domain, string *url, string *urlf)
{
	if(regexMatch("\\.vimeo\\.com/$", *domain)){
		if(regexMatch("^http://av\\.vimeo\\.com/.*(&|\\?)aksessionid=", *url)){
			*urlf = "http://vimeo.inComum/" + get_path(*url,'Y');
		}
		return 1;
	}
	return 0;
}
