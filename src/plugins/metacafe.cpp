#include "../helper.h"

using namespace std;

//metacafe plugin - last check: 2012-03-29
//example: http://v.mccont.com/ItemFiles/%5BFrom%20www.metacafe.com%5D%208289728.22118066.4.mp4?__gda__=1333049973_2f86c14a2a86295b58ca8d1fe0bc1a20
int metacafe(string domain, string url, string *urlf)
{
	if(regexMatch("mccont\\.com/$", domain)){
		if(regexMatch("^http://v\\.mccont\\.com/ItemFiles/%5BFrom%20www\\.metacafe\\.com%5D%.{21}mp4\\?", url)){
			*urlf = "http://metacafe.inComum/" + get_path(url,'Y');
			return 1;
		}
	}
	return 0;
}
