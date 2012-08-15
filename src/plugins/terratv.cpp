#include "../helper.h"

using namespace std;

//Terra TV Plugin - last check 2012-08-12
//example1: http://pd-vdp-cdn03-mia.terra.com/terratv/699137.flv?p1=20120507162416&p2=br&h1=216OMDItE3Xab/H2rFvZLg==&h2=oJ9tSHkovWS4ZZhLzzdBuw==
//example2: http://pd-vdp-cdn13-cis.terra.com/terratv/1409298.mp4?p1=20120502024539&p2=br&h1=0szOI7/Akdj5rBewCIBuvg==&h2=tF1ZFp/ijxlG3J42XDeQ6A==
//example3: http://pd-vdp-cdn14-cis.terra.com/terratv/1426834.mp4?p1=20120505215703&p2=br&h1=mXmqmhHElusNZdLdGQFcVw==&h2=MB9uEfMx6pNj6/2XNQkjww==
int terratv(string *domain, string *url, string *urlf)
{
	if(regexMatch("\\.terra\\.com/$", *domain)){
		if(regexMatch("^http://pd-vdp-cdn.{2}-.{3}\\.terra\\.com/", *domain)){
			if (regexMatch("terratv/.*\\.(flv|mp4)", get_path(*url, 'Y'))){
				*urlf = "http://terratv.inComum/" + get_path(*url,'Y');
			}
		}
		return 1;
	}
	return 0;
}
