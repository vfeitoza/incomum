#include "../helper.h"

using namespace std;

// Kaspersky updates plugin - last check: 2012-07-10
// example1: http://dnl-08.geo.kaspersky.com/bases/av/kdb/i386/dailyc.kdc
// example2: http://dnl-01.geo.kaspersky.com/bases/av/kdb/i386/kdb-i386-0607g.xml.dif
// example3: http://dnl-18.geo.kaspersky.com/bases/ids/i386/idsbase.kdz
// example4: http://dnl-12.geo.kaspersky.com/diffs/bases/ids/i386/idsbase.kdz.srf 
// rewrite to: http://kaspersky.inComum/path/file.ext

int kaspersky(string *domain, string *urlf)
{
	if(regexMatch("\\.kaspersky\\.com", *domain)){
		if(regexMatch("^http://dnl-.{2}\\.geo\\.kaspersky\\.com/", *urlf)){
			*urlf = "http://kaspersky.inComum/" + get_path(*urlf,'N');
		}
		return 1;
	}
	return 0;
}
