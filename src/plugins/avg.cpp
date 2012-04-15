#include "../helper.h"

using namespace std;

//AVG plugin - last check: 2012-02-02
//example: http://af.avg.com/softw/80free/update/u8iavi4164u4162uy.bin
int avg(string domain, string url, string *urlf)
{
	if(regexMatch("\\.avg\\.c(om|z)/$", domain)){
		if(regexMatch("^http://(backup|a.|pupdate-aa)\\.avg\\.c(om|z)/softw/", url)){
			*urlf = "http://avg.inComum/" + get_filename(url);
			return 1;
		}
	}
	return 0;
}
