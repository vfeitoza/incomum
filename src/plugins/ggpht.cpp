#include "../helper.h"

using namespace std;

//ggpht.com -last check: 2011-05-15
int ggpht(string *domain, string *url, string *urlf)
{
	if(regexMatch("\\.ggpht\\.com/$", *domain)){
		if(regexMatch("^http://lh.\\.", *domain)){
			*urlf = "http://ggpht.inComum/" + get_path(*url,'N');
		}
		return 1;
	}
	return 0;
}
