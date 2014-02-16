#include "../helper.h"

using namespace std;

//youtube and googlevideos plugin
int youtube(string *domain, string *urlf)
{
	//youtube/googlevideo plugin
	if(regexMatch("(youtube|googlevideo)\\.com/$", *domain)){
		if(regexMatch("/(get_video|videoplayback|videoplay)\\?.*id=", *urlf)){
			*urlf = "http://video.youtube.inComum/?id="+get_var(*urlf, "id")+get_var(*urlf, "video_id")+"&quality="+get_var(*urlf, "fmt")+get_var(*urlf, "itag")+"&redirect_counter="+get_var(*urlf, "redirect_counter")+get_var(*urlf, "st")+"&begin="+get_var(*urlf,"begin")+"&range="+get_var(*urlf, "range");
		}
		return 1;
	}
	return 0;
}


// http://r13---sn-ab5e6nsd.c.youtube.com/videoplayback?algorithm=throttle-factor&burst=40&cp=U0hUTVZQUF9MUUNONF9OSlRJOjFtQlNYNzJXajNE&expire=1358652877&factor=1.25&fexp=913562%2C910207%2C916612%2C910810%2C920704%2C912806%2C922403%2C922405%2C929901%2C913605%2C925710%2C929104%2C929110%2C913563%2C908493%2C920201%2C913302%2C919009%2C911116%2C926403%2C910221%2C901451&id=6f4105d154ecf437&ip=177.2.117.3&ipbits=8&itag=34&key=yt1&ms=au&mt=1358632634&mv=m&newshard=yes&signature=074524E1636C1F41CBF977671C76480630CA6F11.CEF7A305485B88D72121729C5A1A25CB15B03D2C&source=youtube&sparams=algorithm%2Cburst%2Ccp%2Cfactor%2Cid%2Cip%2Cipbits%2Citag%2Csource%2Cupn%2Cexpire&sver=3&upn=5JYHcoilowA&ptk=youtube_none&cpn=2MC8XMAOKnlpQ8n7
