#include "../helper.h"

using namespace std;

//photobucket.com -last check: 2011-05-15
int photobucket(string *domain, string *urlf)
{
	if(regexMatch("\\.photobucket\\.com/$", *domain)){
		if(regexMatch("^http://(i|th).{1,4}\\.", *domain)){
			*urlf = "http://photobucket.inComum/" + get_path(*urlf,'N');
		}
		return 1;
	}
	return 0;
}
