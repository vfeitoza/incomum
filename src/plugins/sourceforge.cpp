#include "../helper.h"

using namespace std;

//dl.sourceforge.net -last check: 2012-03-08
//example: http://tenet.dl.sourceforge.net/project/aresgalaxy/aresgalaxy/AresRegular218_020212/AresRegular218_020212.zip
int sourceforge(string *domain, string *url,string *urlf)
{
	if(regexMatch("\\.(sourceforge|sf)\\.net", *domain)){
		if(regexMatch("^http://.*\\.dl\\.sourceforge\\.net/$", *domain)){
			if (regexMatch("^project/", get_path(*url, 'Y'))){
				*urlf = "http://dl.sourceforge.inComum/" + get_path(*url, 'Y');
			}
		}
	return 1;
	}
	return 0;
}
