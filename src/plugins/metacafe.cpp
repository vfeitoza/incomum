#include "../helper.h"

using namespace std;

//metacafe plugin - last check: 2012-06-04
//example1: http://v.mccont.com/ItemFiles/%5BFrom%20www.metacafe.com%5D%208289728.22118066.4.mp4?__gda__=1333049973_2f86c14a2a86295b58ca8d1fe0bc1a20
//example2: http://v.mccont.com/ItemFiles/%5BFrom%20www.metacafe.com%5D%208604392.22804109.14.mp4?__gda__=1338865588_0bf063402c4c79165c2ea68cc9c1215a
int metacafe(string domain, string url, string *urlf)
{
	if(regexMatch("mccont\\.com/$", domain)){
		if(regexMatch("^http://v\\.mccont\\.com/ItemFiles/%5BFrom%20www\\.metacafe\\.com%5D%.{21,22}mp4\\?", url)){
			*urlf = "http://metacafe.inComum/" + get_path(url,'Y');
			return 1;
		}
	}
	return 0;
}
