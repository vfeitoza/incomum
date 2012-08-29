#include "../helper.h"

using namespace std;

//porntube - last check: 2012-01-04
//example: http://wpc.porntube.com/main/0/0/0/2/6/9/9/3/6.m4v?8d60b61b4448364398b401494c894bc195a5f1bff1823579e8a03ccc17eec2c348849ab9508b639c426db8550c0166ff7bd490eabaa2ada9e7a5f94da78f4282fcc99e8d32f33a373e18c20d03b5b487ce2dbfd02702293e92cc64a3f31d18c68c2ceaa7272c272136751a6e8ea966b71abdf764538766263f1becd733138414b0fe603fb65537cd1c45b4ef16df2d2354349e98437484ba1be2861354ea04535f9fb37a62be5add9838fc2aba0c3e3d2fdff34af309d6632b06edd5cfd096feeda7&ec_seek=0
int porntube(string *domain, string *urlf)
{
	if(regexMatch("\\.porntube\\.com/$", *domain)){
		if(regexMatch("^http://wpc\\.porntube\\.com/", *domain)){
			if(regexMatch("\\.m4v\\?",*urlf)){
				*urlf = "http://porntube.inComum/" + get_path(*urlf,'Y') + "?start=" + get_var(*urlf, "ec_seek");
			}
		}
		return 1;
	}
	return 0;
}
