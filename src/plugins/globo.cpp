#include "../helper.h"

using namespace std;

//globo plugin - last check: 2012-09-20
//example1: flashvideo.globo.com/h264/jornalismo/3//sptv/2012/09/20/EF_CGJ-RJI_T_2148658_mmp4.mp4?05031348157960306137469013482443602119205566aJKkIZeteQkK69RDZGH+wA&start=126.593
int globo(string *domain, string *urlf)
{
	if(regexMatch("\\.globo\\.com/$", *domain)){
		if(regexMatch("^http://flashvideo\\.globo\\.com/.*\\.mp4", *urlf)){
			*urlf = "http://flashvideo.globo.inComum/" + get_path(*urlf,'Y') + "?start=" + get_var(*urlf, "start");
		}
		return 1;
	}
	return 0;
}
