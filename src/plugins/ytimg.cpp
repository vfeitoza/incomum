#include "../helper.h"

using namespace std;

//ytimg.com -last check: 2011-05-15
int ytimg(string *domain, string *url,string *urlf)
{
	if(regexMatch("\\.ytimg\\.com/$", *domain)){
		if(regexMatch("^http://i(|.)\\.", *domain)){
			*urlf = "http://ytimg.inComum/"+get_path(*url,'N');
		}
		return 1;
	}
	return 0;
}
