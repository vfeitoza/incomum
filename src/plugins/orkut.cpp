#include "../helper.h"

using namespace std;

//regex ^http:\/\/(img|static)[0-9]\.orkut.com
int orkut(string *domain, string *url,string *urlf)
{
	if(regexMatch("\\.orkut\\.com/$", *domain)){
		if(regexMatch("^http://(img|static)[0-9]\\.", *domain)){
			*urlf = "http://orkut.inComum/" + get_path(*url,'N');
		}
		return 1;
	}
	return 0;
}
