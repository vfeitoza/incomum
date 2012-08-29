#include "../helper.h"

using namespace std;

//AVG plugin - last check: 2012-02-02
//example: http://af.avg.com/softw/80free/update/u8iavi4164u4162uy.bin
int avg(string *domain, string *urlf, string *urlf)
{
	if(regexMatch("\\.avg\\.c(om|z)/$", *domain)){
		if(regexMatch("^http://(backup|a.|pupdate-aa)\\.avg\\.c(om|z)/softw/", *urlf)){
			*urlf = "http://avg.inComum/" + get_filename(*urlf);
		}
		return 1;
	}
	return 0;
}
