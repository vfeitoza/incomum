#include "../helper.h"

using namespace std;

//xvideos.com -last check: 2012-09-13
//example1: http://porn126.xvideos.com/videos/flv/9/b/4/xvideos.com_9b4f0e80763bb256f1a4e27a32ffcbe6.flv?e=1324741579&ri=1024&rs=85&h=1503fe575697f4dab651d1244ffc18fb
//example2: http://porn.im.bb5e2e73.440865.x.xvideos.com/videos/flv/4/d/0/xvideos.com_4d072c0a2c7010634e67409de25067e1.flv?e=1337053115&ri=1024&rs=85&h=58deb7f6ad5002766b399d7b205b57c3
//example3: http://porn.im.bb5e2004.563779.x.xvideos.com/videos/flv/7/6/2/xvideos.com_7626137114a489afaf7f14d05511e35a.flv;v=1?e=1337060820&ri=1024&rs=85&h=c21a7523642ef13b988330ce7b4936ad
//example4: http://porn.im.b136c917.54818.x.xvideos.com/videos/flv/6/1/3/xvideos.com_61398f9c361275d8509ada5b8d0f4048.mp4?e=1344880217&ri=1024&rs=85&h=1d5ef3e40fd876aeb4248023e0ef52c5

int xvideos(string *domain, string *urlf)
{
	if (regexMatch("\\.xvideos\\.com/$", *domain)){
		if (regexMatch("^http://porn.{1,3}\\.xvideos\\.com/$", *domain) || regexMatch("^http://porn\\.im\\..{1,}\\.xvideos.com/$", *domain)) {
			if (regexMatch("\\.(flv|mp4)", *urlf)) {
				*urlf = "http://xvideos.inComum/" + get_path(*urlf, 'Y') + "?rs=" + get_var(*urlf, "rs") + "&ri=" + get_var(*urlf, "ri") + "&start=" + get_var(*urlf, "start") + get_var(*urlf, "fs");
			}
		}			
		return 1;
	}
	return 0;
}
