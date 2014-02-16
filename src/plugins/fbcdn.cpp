#include "../helper.h"

using namespace std;

//fbcdn.net -last check: 2012-03-06
//example1: http://profile.ak.fbcdn.net/hprofile-ak-snc4/275217_100002839600343_396666461_q.jpg
//example2: http://a5.sphotos.ak.fbcdn.net/hphotos-ak-ash2/s320x320/64623_374387329246111_333203666697811_1398687_226247264_n.jpg
//example3: http://a1.sphotos.ak.fbcdn.net/hphotos-ak-snc7/424783_404954249531812_315543425139562_1667258_488161428_n.jpg
//example4: http://photos-e.ak.fbcdn.net/hphotos-ak-snc7/424783_404954249531812_315543425139562_1667258_488161428_n.jpg
int fbcdn(string *domain, string *urlf)
{
	if(regexMatch("\\.fbcdn\\.net/$", *domain)){
		if(regexMatch("(profile|sphotos|photos-.).ak.fbcdn.net/h?profile-ak-.{4}/", *urlf)){
			*urlf = "http://fbcdn.inComum/profile/" + get_filename(*urlf);
		} else if(regexMatch("(profile|sphotos|photos-.).ak.fbcdn.net/h?photos-ak-.{4}/", *urlf)) { //redirect sphotos and photos-[a-z] to the same url
			*urlf = "http://fbcdn.inComum/photos/" + get_foldername(*urlf, 2) + "/" + get_filename(*urlf);
		}
		return 1;
	}
	return 0;
}
