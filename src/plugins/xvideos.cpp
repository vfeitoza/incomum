#include "../helper.h"

using namespace std;

//xvideos.com -last check: 2011-12-24
//example: http://porn126.xvideos.com/videos/flv/9/b/4/xvideos.com_9b4f0e80763bb256f1a4e27a32ffcbe6.flv?e=1324741579&ri=1024&rs=85&h=1503fe575697f4dab651d1244ffc18fb
int xvideos(string domain, string url, string *urlf)
{
	if (regexMatch("^http://porn.{1,3}\\.xvideos\\.com/", domain)) {
		if (regexMatch("\\.flv\\?", url)) {
			*urlf = "http://xvideos.inComum/" + get_path(url, 'Y') + "?start=" + get_var(url, "fs");
			return 1;
		}
	}	
	return 0;
}
