#include "../helper.h"

using namespace std;

//youtube and googlevideos plugin
int youtube(string *domain, string *urlf)
{
	//youtube/googlevideo plugin
	if(regexMatch("(youtube|googlevideo)\\.com/$", *domain)){
		if(regexMatch("/(get_video|videoplayback|videoplay)\\?.*id=", *urlf)){
			if(urlf->find("noflv=") != string::npos && urlf->find("ptk=") == string::npos){ //(noflv AND !ptk) => redirecting URL
				return 1;
			}else{
				*urlf = "http://flv.youtube.inComum/?id="+get_var(*urlf, "id")+get_var(*urlf, "video_id")+"&quality="+get_var(*urlf, "fmt")+get_var(*url, "itag")+"&redirect_counter="+get_var(*url, "redirect_counter")+get_var(*url, "st")+"&begin="+get_var(*urlf,"begin")+"&range="+get_var(*urlf, "range");
			}
		}
		return 1;
	}
	return 0;
}
