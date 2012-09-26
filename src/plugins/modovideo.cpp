#include "../helper.h"

using namespace std;

//Modovideo plugin - last check: 2012-09-02
//example: http://s10.modovideo.com/vid/bb04ca3d81f1dfbdfb2eebaec496321b/4f937c33/flv/3bcf6myn6xmnfpm1jqr06085nn9x2c86.flv?start=0
//example iPhone: http://s08i.modovideo.com/uploadvideos/videos/3qvaz9n8j17ub039p54jdq7mbyv0ijmu/3qvaz9n8j17ub039p54jdq7mbyv0ijmu-1.ts
int modovideo(string *domain, string *urlf)
{
	if(regexMatch("\\.modovideo\\.com/$", *domain)){
		if(regexMatch("^http://s.{2,3}\\.modovideo\\.com/(vid|uploadvideos)/.*\\.(flv|ts)", *urlf)){
			*urlf = "http://modovideo.inComum/" + get_filename(*urlf) + "?start=" + get_var(*urlf,"start");
		}
		return 1;
	}
	return 0;
}
