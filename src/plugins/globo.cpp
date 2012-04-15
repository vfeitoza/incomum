#include "../helper.h"

using namespace std;

//globo plugin
int globo(string domain, string url, string *urlf)
{
	if(regexMatch("^http://flashvideo\\.globo\\.com/$", domain)){
		if(regexMatch("\\.mp4", url)){
			*urlf = "http://flashvideo.globo.inComum/" + get_path(url,'Y');
			return 1;
		}
	}
	return 0;
}
