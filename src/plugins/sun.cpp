#include "../helper.h"

using namespace std;

//sun.com - last check: 2012-06-04
//example1: http://sdlc-esd.sun.com/ESD6/JSCDL/jdk/6u32-b05/chromeinstall.exe?AuthParam=1336412799_0b084276aa4af7e966bfb97f5e4ce56b&GroupName=JSC&FilePath=/ESD6/JSCDL/jdk/6u32-b05/chromeinstall.exe&File=chromeinstall.exe&BHost=javadl.sun.com
//example2: http://sdlc-esd.sun.com/ESD6/JSCDL/jdk/6u32-b05/jre/jre1.6.0_32-c-l.msi?AuthParam=1336412834_3bed7f9b4590b8c42bcc08472b7632aa&GroupName=JSC&FilePath=/ESD6/JSCDL/jdk/6u32-b05/jre/jre1.6.0_32-c-l.msi&File=jre1.6.0_32-c-l.msi&BHost=javadl.sun.com
//example3: http://javadl-esd.sun.com/update/1.7.0/sp-1.7.0_04-b22/java_sp.dll

int sun(string *domain, string *urlf)
{
	if(regexMatch("\\.sun\\.com/$", *domain)){
		if (regexMatch("^http://(javadl|sdlc)\\-esd\\.sun\\.com/", *domain)) {
			if (regexMatch("\\.(exe|msi|cab|sh|bin|rpm|MST|dll)", *urlf)) {
				*urlf = "http://sun.inComum/" + get_path(*urlf, 'Y');
			}
		}
		return 1;
	}
	return 0;
}
