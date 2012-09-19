#include "../helper.h"

using namespace std;

//tumblr.com -last check: 2012-09-13
int tumblr(string *domain, string *urlf)
{
	if(regexMatch("\\.tumblr\\.com/$", *domain)){
		if(regexMatch("^http://(.{1,2}\\.){0,1}media\\.tumblr\\.com/$", *domain)){
			  *urlf = "http://tumblr.inComum/" + get_path(*urlf,'N');
			  return 1;
		}
	}
	return 0;
}
