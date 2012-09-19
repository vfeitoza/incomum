#include "../helper.h"

using namespace std;

//metacafe plugin - last check: 2012-09-17
//example1: http://v.mccont.com/ItemFiles/%5BFrom%20www.metacafe.com%5D%208604392.22804109.14.mp4?__gda__=1338865588_0bf063402c4c79165c2ea68cc9c1215a
//example2: http://vl.mccont.com/ItemFiles/%5BFrom%20www.metacafe.com%5D%201242693.6637584.11.flv?__gda__=1345434590_8ffca4bddb07acf5a2227ea3f41c1920
int metacafe(string *domain, string *urlf)
{
	if(regexMatch("mccont\\.com/$", *domain)){
		if(regexMatch("^http://v.?\\.mccont\\.com/ItemFiles/%5BFrom%20www\\.metacafe\\.com%5D%.{21,22}mp4\\?", *urlf)){
			*urlf = "http://metacafe.inComum/" + get_path(*urlf,'Y');
		}
		return 1;
	}
	return 0;
}
