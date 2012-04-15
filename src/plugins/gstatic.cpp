#include "../helper.h"

using namespace std;

//gstatic.com -last check: 2012-03-09
//example: http://t3.gstatic.com/images?q=tbn:ANd9GcQa4Z8ImpTJY5B0pPDKCrWBRFb2-d3muKU6w-t022cnkEpq7vn4Cg
//example: http://t0.gstatic.com/images?q=tbn:ANd9GcRgND_XF1bNj1TyhmiBwPro0WW-lOdJHD47LF0Q38ciLwJCu8pv
int gstatic(string domain, string url,string *urlf)
{
	if(regexMatch("^http://t.\\.gstatic\\.com/$", domain)){
		*urlf = "http://gstatic.inComum/" + get_path(url, 'N');
		return 1;
	}
	return 0;
}
