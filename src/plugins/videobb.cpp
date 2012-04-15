#include "../helper.h"

using namespace std;

//videobb.com -last check: 2012-01-24
//example: http://s269.videobb.com/s?v=QeHwaooHQQ5G&t=1327417389&u=&r=2&c=e6db2e6cc7ea3366b4f65ff07e74cc6262ecd39d8727a94e9003e93210f1e4236b0352125b8fbd3af49be21c84030668&start=0
int videobb(string domain, string url, string *urlf)
{
	if(regexMatch("^http://s[0-9]{0,3}\\.videobb\\.com/", domain)){
		*urlf = "http://videobb.inComum/?id=" + get_var(url, "v") + "&quality=" + get_var(url, "r") + "&start=" + get_var(url, "start");
		return 1;
	}
	return 0;
}
