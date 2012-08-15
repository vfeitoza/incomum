#include "../helper.h"

using namespace std;

//avast plugin
int avast(string *domain, string *url, string *urlf)
{
	if(regexMatch("\\.avast\\.com/$", *domain)){
		if(regexMatch("^http://download", *domain)){
			*urlf = "http://download.avast.inComum/" + get_path(*url,'N');
		}
		return 1;
	}
	return 0;
}
