#include "../helper.h"

using namespace std;

//phncdn.com -last check: 2012-02-05
//example1: http://cdn3.image.pornhub.phncdn.com/thumbs/004/258/475/small.jpg?cache=3012728
//example2: http://cdn1.public.keezmovies.phncdn.com/201112/16/731238/240p_371k_731238.mp4?sr=1440&int=614400b&nvb=20120203194641&nva=20120203214641&hash=00f3f3ae0d7e28916817a&start=530
int phncdn(string *domain, string *url, string *urlf)
{
	if(regexMatch("\\.phncdn\\.com/$", *domain)){
		if (regexMatch("^http://cdn.\\.(image|static)\\.pornhub\\.phncdn.com/$", *domain)){
			*urlf = "http://image.pornhub.phncdn.inComum/" + get_path(*url, 'Y');
		} else if (regexMatch("^http://cdn.[ab]\\.video\\.pornhub\\.phncdn.com/$", *domain)){
			*urlf = "http://video.pornhub.phncdn.inComum/" + get_path(*url, 'Y') + "?fs=" + get_var(*url, "fs");
		} else if (regexMatch("^http://cdn.\\.(image|static)\\.tube8\\.phncdn.com/$", *domain)){		  
			*urlf = "http://tube8.phncdn.inComum/" + get_path(*url, 'Y');
		} else if (regexMatch("^http://cdn.\\.(image|static|public)\\.keezmovies\\.phncdn.com/$", *domain)){
			*urlf = "http://keezmovies.phncdn.inComum/" + get_path(*url, 'Y') + "?start=" + get_var(*url, "start");;
		} else if (regexMatch("^http://cdn.\\.(image|static|public)\\.extremetube\\.phncdn.com/$", *domain)){
			*urlf = "http://public.extremetube.phncdn.inComum/" + get_path(*url, 'Y') + "?start=" + get_var(*url, "start");;
		} else if (regexMatch("^http://cdn.\\.(image|static|public)\\.spankwire\\.phncdn.com/$", *domain)){
			*urlf = "http://public.spankwire.phncdn.inComum/" + get_path(*url, 'Y') + "?start=" + get_var(*url, "start");;
		}
		return 1;
	}
	return 0;
}
