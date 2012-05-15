#include "../helper.h"

using namespace std;

//TV UOL plugin - last check 2011-12-30
//example1: http://video7.mais.uol.com.br/12381354.mp4?ver=1
//example2: http://storage.mais.uol.com.br/12304309.flv?cfmhwNs,bhpIoqWzmeyNg
//example3: http://thumb.mais.uol.com.br/12093127-medium.jpg?ver=1
int tvuol(string domain, string url, string *urlf)
{

	if(regexMatch("^http://(video.{1,2}|thumb|storage)\\.mais\\.uol\\.com\\.br/", domain)){
		if(regexMatch("\\.(mp4|flv|jpg)\\?", url)){
			*urlf = "http://maisuol.inComum/" + get_path(url,'Y');
			return 1;
		}
	}
	return 0;
}