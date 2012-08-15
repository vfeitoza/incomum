#include "../helper.h"

using namespace std;

// Anitube videos plugin - last check: 2012-07-10
// example1: http://vid29-wdc07.anitube.com.br/a2b85a360804eecbafb243974fb6fc5a/4ffca930/38452.flv?start=55.013
// example2: http://lb02-wdc.anitube.com.br/mobile/b9751d0c6c19328ec03cb4408aadaeff/4ffca46f/46283.mp4
// rewrite to: http://anitube.inComum/file.flv or http://anitube.inComum/mobile/file.mp4

int anitube(string *domain, string *url, string *urlf)
{
	if(regexMatch("anitube\\.com\\.br/$", *domain)){
		if (regexMatch("\\.flv$", get_filename(*url))){
			*urlf = "http://anitube.inComum/" + get_filename(*url) + "?start=" + get_var(*url, "start");
		} else if (regexMatch("\\.mp4$", get_filename(*url))){
			*urlf = "http://anitube.inComum/mobile/" + get_filename(*url);
		}
		return 1;
	}
	return 0;
}
