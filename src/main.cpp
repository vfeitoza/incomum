#include "helper.h"
#include "plugins/plugins.h"

/*
 * BSD License
 *
Copyright (c) 2012, The inComum Team.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. The names of developers may not be used to endorse or promote
products derived from this software without specific prior written
permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*
* to compile, use following line:
* make all
*
* If using boost library, use this:
* make all ENABLE_BOOST=y
* 
* To compile in debug mode (to show URL rewrites on /tmp/inComum-*.log)
* make all DEBUG=y
*
* If you add another plugin, please, send us a copy to email:
* luciano.pinheiro@gmail.com
* 
* 
* Version 0.4
*
*/

using namespace std;

int main(int argc, char **argv)
{
	string url, urlf, id, domain;
	string::size_type x;
	
	#if debug
		pid_t pid;
		pid = getpid();

		stringstream stream;
		stream << "/tmp/inComum-" << pid << ".log";
		string arraystring = stream.str();

		ofstream SaveLine(arraystring.c_str(), ios::out);
		//ofstream SaveLine("/tmp/inComum-" + pid + ".log", ios::out);
	#endif
		
	if(argc > 1){
		if(argv[1][0] == '-' && argv[1][1] == 'v' ) {
			cout << "inComum 0.4 (2012-08-14)  http://sourceforge.net/projects/incomum/" << endl;
			cout << "===========" << endl;
			cout << "-anitube" << endl;
			cout << "-avast" << endl;
			//cout << "-avg" << endl;
			cout << "-blip.tv" << endl;
			cout << "-blogspot" << endl;
			cout << "-facebook fbcdn" << endl;
			cout << "-ggpht" << endl;
			cout << "-globo.com" << endl;
			cout << "-google gstatic" << endl;
			cout << "-google syndication" << endl;
			cout << "-google video" << endl;
			cout << "-kaspersky" << endl;
			cout << "-modovideo.com" << endl;
			cout << "-msn video" << endl;
			cout << "-netflix img/video" << endl;
			cout << "-orkut img/static" << endl;
			cout << "-phncdn.com" << endl;
			cout << "-photobucket" << endl;
			cout << "-porntube.com" << endl;
			cout << "-pornhub.com" << endl;
			cout << "-redtube.com" << endl;
			cout << "-sourceforge.net" << endl;
			cout << "-sun" << endl;
			cout << "-terratv" << endl;
			cout << "-tumblr" << endl;
			cout << "-tvuol.uol.com.br" << endl;
			cout << "-videobb.com" << endl;
			cout << "-videolog.tv" << endl;
			cout << "-vimeo" << endl;
			cout << "-xvideos.com" << endl;
			cout << "-youtube" << endl;

			
			#if debug
				cout << "-=[ Running in debug mode. Check /tmp/inComum-*.log files ]=-" << endl;
			#endif
			return 0;
		}
	}

	while(getline(std::cin, url)){ // main loop receive all redirecting URL

		x = url.find_first_of(" ");
		if(x != string::npos){
			url = url.erase(x);
		}
		domain = get_domain(url);

		//https is just tunneling (can't cache) - don't cache ftp either
		if(url.substr(0,8) == "https://" || url.substr(0,6) == "ftp://"){
			cout << url << endl;
			continue;
		}

		//squid may send a blank line to exit
		if(url.empty()){
			cout << url << endl;
			continue;
		}

		urlf=url;
		if(!fbcdn(&domain,&urlf))
		if(!youtube(&domain,&urlf))
		if(!orkut(&domain,&urlf))
		if(!ytimg(&domain,&urlf))
		if(!ggpht(&domain,&urlf))
		if(!gstatic(&domain,&urlf))
		if(!googlesyndication(&domain,&urlf))
		if(!tumblr(&domain,&urlf))
		if(!photobucket(&domain,&urlf))
		if(!blogspot(&domain,&urlf))
		if(!avast(&domain,&urlf))
		//if(!avg(&domain,&urlf))
		if(!kaspersky(&domain,&urlf))
		if(!vimeo(&domain,&urlf))
		if(!metacafe(&domain,&urlf))
		if(!blip(&domain,&urlf))
		if(!globo(&domain,&urlf))
		if(!tvuol(&domain,&urlf))
		if(!netflix(&domain,&urlf))
		if(!porntube(&domain,&urlf))
		if(!redtube(&domain,&urlf))
		if(!xvideos(&domain,&urlf))
		if(!phncdn(&domain,&urlf))
		if(!pornhub(&domain,&urlf))
		if(!msn(&domain,&urlf))
		if(!videobb(&domain,&urlf))
		if(!modovideo(&domain,&urlf))
		if(!videologtv(&domain,&urlf))
		if(!terratv(&domain,&urlf))
		if(!sun(&domain,&urlf))
		if(!anitube(&domain,&urlf))
			sourceforge(&domain,&urlf);

		#if debug
			if(urlf == url){
				SaveLine << url + " > (same)\n";
			}else{
				SaveLine << url + " > " + urlf + "\n";
			}
			SaveLine.flush();
		#endif
		//send urlf back to squid
		cout << urlf << endl;

	}
	#if debug
		SaveLine.close();
	#endif
}
