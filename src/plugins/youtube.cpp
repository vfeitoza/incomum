#include "../helper.h"

using namespace std;

//youtube and googlevideos plugin
int youtube(string domain, string url, string *urlf)
{
	//youtube/googlevideo plugin
	if(regexMatch("(youtube|googlevideo)\\.com/$", domain)){
		if(regexMatch("/(get_video|videoplayback|videoplay)\\?.*id=", url)){
			if(url.find("noflv=") != string::npos && url.find("ptk=") == string::npos){ //(noflv AND !ptk) => redirecting URL
				  return 0;
			}else{
				  *urlf = "http://flv.youtube.inComum/?id="+get_var(url, "id")+get_var(url, "video_id")+"&quality="+get_var(url, "fmt")+get_var(url, "itag")+"&redirect_counter="+get_var(url, "redirect_counter")+get_var(url, "st")+"&begin="+get_var(url,"begin")+"&range="+get_var(url, "range");
				  return 1;
			}
		}			
	}
	return 0;
}
