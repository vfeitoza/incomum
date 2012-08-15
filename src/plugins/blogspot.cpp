#include "../helper.h"

using namespace std;

//bp.blogspot.com -last check: 2012-03-23
int blogspot(string *domain, string *url,string *urlf)
{
	if(regexMatch("\\.blogspot\\.com/$", *domain)){
		if(regexMatch("^http://.\\.bp.blogspot\\.com/$", *domain)){
			*urlf = "http://bp.blogspot.inComum/" + get_path(*url,'N');
		}
		return 1;
	}
	return 0;
}
