#include "../helper.h"

using namespace std;

//msn catalog videos plugin - last check: 2012-03-20
//example: http://content4.catalog.video.msn.com/e2/ds/f9d00167-fc4a-4832-9e75-9ac7ac725d55.mp4
int msn(string *domain, string *urlf)
{
	if(regexMatch("\\.msn\\.com/$", *domain)){
		if(regexMatch("^http://(img|content).{1,2}\\.catalog\\.video\\.msn\\.com/", *urlf)){
			*urlf = "http://catalog.msn.inComum/" + get_path(*urlf,'N');
		}
		return 1;
	}
	return 0;
}
