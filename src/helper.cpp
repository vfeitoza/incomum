#include "helper.h"

using namespace std;
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
