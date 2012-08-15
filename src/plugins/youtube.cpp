#include "../helper.h"

using namespace std;

//youtube and googlevideos plugin
int youtube(string *domain, string *url, string *urlf)
{
	//youtube/googlevideo plugin
	if(regexMatch("(youtube|googlevideo)\\.com/$", *domain)){
		if(regexMatch("/(get_video|videoplayback|videoplay)\\?.*id=", *url)){
			if(url->find("noflv=") != string::npos && url->find("ptk=") == string::npos){ //(noflv AND !ptk) => redirecting URL
				return 1;
			}else{
				*urlf = "http://flv.youtube.inComum/?id="+get_var(*url, "id")+get_var(*url, "video_id")+"&quality="+get_var(*url, "fmt")+get_var(*url, "itag")+"&redirect_counter="+get_var(*url, "redirect_counter")+get_var(*url, "st")+"&begin="+get_var(*url,"begin")+"&range="+get_var(*url, "range");
			}
		}
		return 1;
	}
	return 0;
}


#http://o-o---preferred---mia05s03---v8---lscache5.c.youtube.com/videoplayback?upn=YGZWCSV5KNU&sparams=cp%2Cgcr%2Cid%2Cip%2Cipbits%2Citag%2Cratebypass%2Csource%2Cupn%2Cexpire&fexp=914054%2C910048%2C915507%2C907217%2C922401%2C919804%2C920704%2C912806%2C906055%2C924500%2C906831%2C925701%2C924700%2C911406%2C913550%2C904721%2C920706%2C907344%2C912706&key=yt1&itag=43&ipbits=8&signature=0DADA8344A9D332F54461209F776716652BC78EF.4AE4A3FFF56C39B83D50E654F0E8C0684DA27087&mv=m&sver=3&mt=1344971891&ratebypass=yes&source=youtube&ms=au&gcr=br&expire=1344995490&ip=200.142.0.13&cp=U0hTSVlUU19OSkNOM19RTldFOjB0YVJkaGpZOGln&id=ec54e4a3b33c151a