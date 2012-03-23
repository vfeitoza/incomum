#if ENABLE_BOOST
  #include <boost/typeof/std/iostream.hpp>
  #include <boost/regex.h>
  #include <boost/algorithm/string.hpp>
  #include <boost/typeof/vector.hpp>
#else
  #include <iostream>
  #include <regex.h>
  #include <string>
  #include <vector>
#endif
#if debug
	#include <fstream>
	#include <sys/types.h>
	#include <sstream>
#endif

/*
 * BSD License
 *
Copyright (c) 2012, inComum Team.
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
* g++ -Wall -o "inComum" "inComum.cpp"
* If using boost library, use this:
* g++ -DENABLE_BOOST -lboost_regex -o inComum inComum.cpp
* To compile in debug mode (to show URL rewrites on /etc/inComum-*.log)
* g++ -Ddebug -o inComum_debug inComum.cpp
*
* If you add another plugin, please, send us a copy to email:
* luciano.pinheiro@gmail.com
*
* verion 0.3.9
*
*/

using namespace std;

string get_var(const string url,const string var); //get some var from url
string get_path(const string url, const char removeQuery); //path only (optionally remove query string)
string get_domain(const string url); //get domain only (remove path)
string get_filename(const string url); //get filename only
string get_foldername(const string url, const int position); //get folder name of a specified position.
int regexMatch(string er, string line); //implement regex by regex.h

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
			cout << "inComum 0.3.9 (2012-03-23) http://sourceforge.net/projects/incomum/" << endl;
			cout << "===========" << endl;
			cout << "-youtube" << endl;
			cout << "-google video" << endl;
			cout << "-orkut img/static" << endl;
			cout << "-facebook fbcdn" << endl;
			cout << "-ggpht" << endl;
			cout << "-google gstatic" << endl;
			cout << "-tumblr" << endl;
			cout << "-blogspot" << endl;
			cout << "-photobucket" << endl;
			cout << "-avast" << endl;
			cout << "-avg" << endl;
			cout << "-vimeo" << endl;
			cout << "-blip.tv" << endl;
			cout << "-globo.com" << endl;
			cout << "-tvuol.uol.com.br" << endl;
			cout << "-redtube.com" << endl;
			cout << "-porntube.com" << endl;
			cout << "-pornhub.com" << endl;
			cout << "-phncdn.com" << endl;
			cout << "-xvideos.com" << endl;
			cout << "-globo.com" << endl;
			cout << "-msn catalog" << endl;
			cout << "-videobb.com" << endl;
			cout << "-sourceforge.net" << endl;
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
		urlf = url;
		domain = get_domain(url);

		//https is just tunneling (can't cache) - don't cache ftp either
		if(url.substr(0,8) == "https://" || url.substr(0,6) == "ftp://"){
			cout << url << endl;
			continue;
		}

		//squid may send a blank line to exit
		if(url.empty() || url.substr(0,7) != "http://"){
			cout << url << endl;
			return 0;
		}

		// inComum plugins below

		//youtube/googlevideo plugin
		if(regexMatch("(youtube|googlevideo)\\.com/$", domain)){
			if(regexMatch("/(get_video|videoplayback|videoplay)\\?.*id=", url)){
				if(url.find("noflv=") != string::npos && url.find("ptk=") == string::npos){ //(noflv AND !ptk) => redirecting URL
					urlf = url;
				}else{
					urlf = "http://flv.youtube.inComum/?id="+get_var(url, "id")+get_var(url, "video_id")+"&quality="+get_var(url, "fmt")+get_var(url, "itag")+"&redirect_counter="+get_var(url, "redirect_counter")+get_var(url, "st")+"&begin="+get_var(url,"begin")+"&range="+get_var(url, "range");
				}
			}

		//orkut img/static plugin
		}else if(regexMatch("\\.orkut\\.com/$", domain)){
			if(regexMatch("^http://(img|static)[0-9]\\.", domain)){
				urlf = "http://orkut.inComum/"+get_path(url,'N');
			}

		//fbcdn.net -last check: 2012-03-06
		//example1: http://profile.ak.fbcdn.net/hprofile-ak-snc4/275217_100002839600343_396666461_q.jpg
		//example2: http://a5.sphotos.ak.fbcdn.net/hphotos-ak-ash2/s320x320/64623_374387329246111_333203666697811_1398687_226247264_n.jpg
		//example3: http://a1.sphotos.ak.fbcdn.net/hphotos-ak-snc7/424783_404954249531812_315543425139562_1667258_488161428_n.jpg
		//example4: http://photos-e.ak.fbcdn.net/hphotos-ak-snc7/424783_404954249531812_315543425139562_1667258_488161428_n.jpg
		}else if(regexMatch("(profile|sphotos|photos-[a-z])\\.ak\\.fbcdn\\.net/$", domain)){
			if(regexMatch("hprofile-ak-.{1,}", get_foldername(url, 1))){
				urlf = "http://profile.fbcdn.inComum/hprofile-ak/" + get_filename(url);
			} else if(regexMatch("hphotos-ak-.{1,}", get_foldername(url, 1))) { //redirect sphotos and photos-[a-z] to the same url
				if (get_foldername(url,2) == "") { //Check if path contains a second folder or not.
				  urlf = "http://sphotos.fbcdn.inComum/hphotos-ak/" + get_filename(url);
				} else {
				  urlf = "http://sphotos.fbcdn.inComum/hphotos-ak/" + get_foldername(url, 2) + "/" + get_filename(url);
				}
			}

		//ytimg.com -last check: 2011-05-15
		}else if(regexMatch("\\.ytimg\\.com/$", domain)){
		  if(regexMatch("^http://i(|.)\\.", domain)){
			urlf = "http://ytimg.inComum/"+get_path(url,'N');
		}

		//ggpht.com -last check: 2011-05-15
		}else if(regexMatch("\\.ggpht\\.com/$", domain)){
			if(regexMatch("^http://lh.\\.", domain)){
			    urlf = "http://ggpht.inComum/"+get_path(url,'N');
			}

		//gstatic.com -last check: 2012-03-09
		//example: http://t3.gstatic.com/images?q=tbn:ANd9GcQa4Z8ImpTJY5B0pPDKCrWBRFb2-d3muKU6w-t022cnkEpq7vn4Cg
		//example: http://t0.gstatic.com/images?q=tbn:ANd9GcRgND_XF1bNj1TyhmiBwPro0WW-lOdJHD47LF0Q38ciLwJCu8pv
		}else if(regexMatch("^http://t.\\.gstatic\\.com/$", domain)){
		      urlf = "http://gstatic.inComum/" + get_path(url, 'N');

		//tumblr.com -last check: 2011-05-15
		}else if(regexMatch("\\.media\\.tumblr\\.com/$", domain)){
		    if(regexMatch("^http://.{1,2}\\.", domain)){
		      urlf = "http://tumblr.inComum/"+get_path(url,'N');
		    }

		//photobucket.com -last check: 2011-05-15
		}else if(regexMatch("\\.photobucket\\.com/$", domain)){
		    if(regexMatch("^http://(i|th).{1,4}\\.", domain)){
			urlf = "http://photobucket.inComum/"+get_path(url,'N');
		    }

		//bp.blogspot.com -last check: 2012-03-23
		}else if(regexMatch("^http://.\\.bp.blogspot\\.com/$", domain)){
			urlf = "http://bp.blogspot.inComum/"+get_path(url,'N');

		//avast plugin
		}else if(regexMatch("\\.avast\\.com/$", domain)){
			if(regexMatch("^http://download", domain)){
				urlf = "http://download.avast.inComum/"+get_path(url,'N');
			}

		//AVG plugin - last check: 2012-02-02
		//example: http://af.avg.com/softw/80free/update/u8iavi4164u4162uy.bin
		}else if(regexMatch("\\.avg\\.c(om|z)/$", domain)){
			if(regexMatch("^http://(backup|a.|pupdate-aa)\\.avg\\.c(om|z)/softw/", url)){
				urlf = "http://avg.inComum/" + get_filename(url);
			}

		//vimeo plugin -last check: 2012-01-11
		// TODO: has start var?
		//example: http://av.vimeo.com/68769/772/77100523.mp4?token=1326296561_d50e78c38a4d49174b08e77c6b2bd0f4
		}else if(regexMatch("\\.vimeo\\.com/$", domain)){
			if(regexMatch("^http://av\\.vimeo\\.com/.*\\?token=", url)){
				urlf = "http://vimeo.inComum/"+get_path(url,'Y');
			}

		//metacafe plugin
		// TODO: has start var?
		}else if(regexMatch("mccont\\.com/$", domain)){
			if(regexMatch("^http://v\\.mccont\\.com/ItemFiles/%5BFrom%20www\\.metacafe\\.com%5D%.{20}flv\\?", url)){
				urlf = "http://metacafe.inComum/"+get_path(url,'Y');
			}

		//blip.tv plugin - last check 2012-02-02
		//example: http://a14.video2.blip.tv/10020009553710/GiselleAchecar-EcoRicoEp007232.m4v?brs=2493&bri=12.2
		//example: http://j14.video2.blip.tv/10020009553710/GiselleAchecar-EcoRicoEp007232.m4v?brs=2493&bri=12.2&showplayer=20120110140747&start=201&referrer=http://blip.tv
		//example: http://j2.video2.blip.tv/12950010298587/Sexynerdgirl-Vlog111Follywood875.m4v?brs=2782&bri=4.5&showplayer=20120110140747&start=3&referrer=http://blip.tv
		}else if(regexMatch("\\.blip\\.tv/$", domain)){
			if(regexMatch("video.*m4v", url)){
				urlf = "http://bliptv.inComum/"+get_path(url,'Y')+"?start="+get_var(url,"start");
			}

		//globo plugin
		// TODO: has start var?
		}else if(regexMatch("^http://flashvideo\\.globo\\.com/$", domain)){
			if(regexMatch("\\.mp4", url)){
				urlf = "http://flashvideo.globo.inComum/"+get_path(url,'Y');
			}

		//TV UOL plugin - last check 2011-12-30
		//example1: http://video7.mais.uol.com.br/12381354.mp4?ver=1
		//example2: http://storage.mais.uol.com.br/12304309.flv?cfmhwNs,bhpIoqWzmeyNg
		//example3: http://thumb.mais.uol.com.br/12093127-medium.jpg?ver=1
		}else if(regexMatch("^http://(video.{1,2}|thumb|storage)\\.mais\\.uol\\.com\\.br/", domain)){
			if(regexMatch("\\.(mp4|flv|jpg)\\?", url)){
				urlf = "http://maisuol.inComum/"+get_path(url,'Y');
			}

		//porntube - last check: 2012-01-04
		//example: http://wpc.porntube.com/main/0/0/0/2/6/9/9/3/6.m4v?8d60b61b4448364398b401494c894bc195a5f1bff1823579e8a03ccc17eec2c348849ab9508b639c426db8550c0166ff7bd490eabaa2ada9e7a5f94da78f4282fcc99e8d32f33a373e18c20d03b5b487ce2dbfd02702293e92cc64a3f31d18c68c2ceaa7272c272136751a6e8ea966b71abdf764538766263f1becd733138414b0fe603fb65537cd1c45b4ef16df2d2354349e98437484ba1be2861354ea04535f9fb37a62be5add9838fc2aba0c3e3d2fdff34af309d6632b06edd5cfd096feeda7&ec_seek=0
		}else if(regexMatch("^http://wpc\\.porntube\\.com/", domain)){
			if(regexMatch("\\.m4v\\?",url)){
				urlf = "http://porntube.inComum/" + get_path(url,'Y') + "?start=" + get_var(url, "ec_seek");
			}

		//redtube.com -last check: 2011-12-30
		//example: http://videos.flv2.redtubefiles.com/_videos_t4vn23s9jc5498tgj49icfj4678/0000090/_h264flv/0090017.flv?47aac1f74dca44b0626f9b5acf21d75cd5dee7e8937c9cd51b27114cbb64d1abdacd57b1c8f7662835b5852858f0556998fb41dad6317b0e2c76&ec_seek=49672846
		}else if(regexMatch("^http://(img..|videos\\.flv.{0,1})\\.redtubefiles\\.com/", domain)){
			urlf = "http://redtube.inComum/" + get_path(url, 'Y') + "?start=" + get_var(url, "ec_seek");

		//xvideos.com -last check: 2011-12-24
		//example: http://porn126.xvideos.com/videos/flv/9/b/4/xvideos.com_9b4f0e80763bb256f1a4e27a32ffcbe6.flv?e=1324741579&ri=1024&rs=85&h=1503fe575697f4dab651d1244ffc18fb
		} else if (regexMatch("^http://porn.{1,3}\\.xvideos\\.com/", domain)) {
			if (regexMatch("\\.flv\\?", url)) {
				urlf = "http://xvideos.inComum/" + get_path(url, 'Y') + "?start=" + get_var(url, "fs");
			}

		//phncdn.com -last check: 2012-02-05
		//example1: http://cdn3.image.pornhub.phncdn.com/thumbs/004/258/475/small.jpg?cache=3012728
		//example2: http://cdn1.public.keezmovies.phncdn.com/201112/16/731238/240p_371k_731238.mp4?sr=1440&int=614400b&nvb=20120203194641&nva=20120203214641&hash=00f3f3ae0d7e28916817a&start=530
		}else if(regexMatch("\\.phncdn\\.com/$", domain)){

			if (regexMatch("^http://cdn.\\.(image|static)\\.pornhub\\.phncdn.com/$", domain)){
				urlf = "http://image.pornhub.phncdn.inComum/" + get_path(url, 'Y');

			} else if (regexMatch("^http://cdn.[ab]\\.video\\.pornhub\\.phncdn.com/$", domain)){
				urlf = "http://video.pornhub.phncdn.inComum/" + get_path(url, 'Y') + "?fs=" + get_var(url, "fs");

			} else if (regexMatch("^http://cdn.\\.(image|static)\\.tube8\\.phncdn.com/$", domain)){
				urlf = "http://tube8.phncdn.inComum/" + get_path(url, 'Y');

			} else if (regexMatch("^http://cdn.\\.(image|static|public)\\.keezmovies\\.phncdn.com/$", domain)){
				urlf = "http://keezmovies.phncdn.inComum/" + get_path(url, 'Y') + "?start=" + get_var(url, "start");;

			} else if (regexMatch("^http://cdn.\\.(image|static|public)\\.extremetube\\.phncdn.com/$", domain)){
				urlf = "http://public.extremetube.phncdn.inComum/" + get_path(url, 'Y') + "?start=" + get_var(url, "start");;

			} else if (regexMatch("^http://cdn.\\.(image|static|public)\\.spankwire\\.phncdn.com/$", domain)){
				urlf = "http://public.spankwire.phncdn.inComum/" + get_path(url, 'Y') + "?start=" + get_var(url, "start");;
			}

		//pornhub.com -last check: 2012-02-05
		//rewrited to video.pornhub.phncdn.inComum
		//example: http://nyc-v59.pornhub.com/dl/80b8c31b2287d7916d5a39e91ebe19b0/4f2f1248/videos/003/082/720/3082720.flv?r=165&b=3000
		}else if(regexMatch("^http://nyc-v.{1,2}\\.pornhub\\.com/$", domain)){
			if (regexMatch("\\.flv\\?", url)){
				urlf = "http://video.pornhub.phncdn.inComum/" + get_foldername(url, 4) + "/" + get_foldername(url, 5) + "/" + get_foldername(url, 6) + "/" + get_foldername(url, 7) + "/" + get_filename(url) + "?fs=" + get_var(url, "fs");
			}

		//msn catalog videos plugin - last check: 2012-03-20
		//example: http://content4.catalog.video.msn.com/e2/ds/f9d00167-fc4a-4832-9e75-9ac7ac725d55.mp4
		//
		}else if(regexMatch("^http://(img|content).{1,2}.catalog.video.msn.com/", url)){
			urlf = "http://catalog.msn.inComum/"+get_path(url,'N');

		//videobb.com -last check: 2012-01-24
		//example: http://s269.videobb.com/s?v=QeHwaooHQQ5G&t=1327417389&u=&r=2&c=e6db2e6cc7ea3366b4f65ff07e74cc6262ecd39d8727a94e9003e93210f1e4236b0352125b8fbd3af49be21c84030668&start=0
		}else if(regexMatch("^http://s[0-9]{0,3}\\.videobb\\.com/", domain)){
			urlf = "http://videobb.inComum/?id="+get_var(url, "v")+"&quality="+get_var(url, "r")+"&start="+get_var(url, "start");

		//dl.sourceforge.net -last check: 2012-03-08
		//example: http://tenet.dl.sourceforge.net/project/aresgalaxy/aresgalaxy/AresRegular218_020212/AresRegular218_020212.zip
		}else if(regexMatch("^http://.*\\.dl\\.sourceforge\\.net/$", domain)){
			if (regexMatch("^project/", get_path(url, 'Y'))){
				urlf = "http://dl.sourceforge.inComum/" + get_path(url, 'Y');
			}
		}

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
	return 0;
}

/* return the value of a URL var */
string get_var(const string url,const string var)
{
	string par, v, valor, vars;

	if(url.find("?") != string::npos){
		vars = url.substr(url.find("?")+1);
	}

	while(!vars.empty()){
		par = vars.substr(vars.find_last_of("&")+1);
		v = par.substr(0,par.find_first_of("="));
		valor = par.substr(par.find_first_of("=")+1);
		if(v == var){
			return par.substr(par.find_first_of("=")+1);
		}
		if(vars.find_last_of("&") != string::npos){
			vars.erase(vars.find_last_of("&"));
		}else{
			vars.erase();
		}
	}
	return "";
}

/* return URL path */
string get_path(const string url, const char removeQuery)
{
	string temp, path;
	string::size_type x;

	temp = url.substr(7);
	x = temp.find_first_of("/");
	if(x != string::npos){
		path = temp.substr(x+1);
		if(removeQuery == 'Y'){
			x = path.find_first_of("?");
			if(x != string::npos){
				path = path.erase(x);
			}
		}
		return path;
	}else{
		return "";
	}
}

/* return URL domain */
string get_domain(const string url)
{
	string retorno;
	string::size_type x;

	x = url.find_first_of("/", 7);
	if(x != string::npos){
		return url.substr(0,x+1);
	}else{
		return url;
	}

}

/* return filename */
string get_filename(const string url) {
	string::size_type x;
	string path;

	path = get_path(url,'Y');
	x = path.find_last_of("/");
	if (x != string::npos) {
		return path.substr(x + 1);
	} else {
		return path;
	}
}

/* return folder name of a specified position
 * position starts on 1 (0 is blank)
 * */
string get_foldername(const string url, const int position) {
        string::size_type i;
        string::size_type nextPosition;
        string::size_type start, end;
        int contador = 1;

        string path =  "/" + get_path(url, 'Y');
        for(i = path.find("/", 0); i != string::npos; i = path.find("/", i)) {
                if (contador == position) {
                        nextPosition = path.find("/", i+1);
                        start = i+1;
                        end = nextPosition - start;
                        if (nextPosition != string::npos){
                                return path.substr(start,end);
                        } else {
                                return "";
                        }
                }
                contador++;
                i++;
        }
        return "";
}


/* regex */
int regexMatch(string er, string line)
{
    int error;
    regmatch_t match;
    regex_t reg;
    if ((regcomp(&reg, er.c_str(), REG_EXTENDED | REG_NEWLINE)) == 0) {
        error = regexec(&reg, line.c_str(), 1, &match, 0);
        if (error == 0) {
			regfree(&reg);
            return 1;
        }
    }
    regfree(&reg);
	return 0;
}
