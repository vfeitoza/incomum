#include "../helper.h"

using namespace std;

//globo plugin
int globo(string *domain, string *urlf)
{
	if(regexMatch("\\.globo\\.com/$", *domain)){
		if(regexMatch("^http://flashvideo\\.globo\\.com/.*\\.mp4", *urlf)){
			*urlf = "http://flashvideo.globo.inComum/" + get_path(*urlf,'Y');
		}
		return 1;
	}
	return 0;
}
