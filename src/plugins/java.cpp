#include "../helper.h"

using namespace std;

//Java updates - sdlc-esd.sun.com - plugin - last check: 2012-05-07
//example1: http://sdlc-esd.sun.com/ESD6/JSCDL/jdk/6u32-b05/chromeinstall.exe?AuthParam=1336412799_0b084276aa4af7e966bfb97f5e4ce56b&GroupName=JSC&FilePath=/ESD6/JSCDL/jdk/6u32-b05/chromeinstall.exe&File=chromeinstall.exe&BHost=javadl.sun.com
//example2: http://sdlc-esd.sun.com/ESD6/JSCDL/jdk/6u32-b05/jre/jre1.6.0_32-c-l.msi?AuthParam=1336412834_3bed7f9b4590b8c42bcc08472b7632aa&GroupName=JSC&FilePath=/ESD6/JSCDL/jdk/6u32-b05/jre/jre1.6.0_32-c-l.msi&File=jre1.6.0_32-c-l.msi&BHost=javadl.sun.com
int java(string domain, string url, string *urlf)
{
	if (regexMatch("^http://sdlc\\-esd\\.sun.com/", domain)) {
		if (regexMatch("(\\.exe|\\.msi|\\.cab|\\.sh|\\.bin|\\.rpm)", url)) {
			*urlf = "http://java.inComum/" + get_path(url, 'Y');
			return 1;
		}
	}
	return 0;
}
