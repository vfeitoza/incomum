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
	#include <unistd.h>
#endif
using namespace std;
string get_var(const string url,const string var); //get some var from url
string get_path(const string url, const char removeQuery); //path only (optionally remove query string)
string get_domain(const string url); //get domain only (remove path)
string get_filename(const string url); //get filename only
string get_foldername(const string url, const int position); //get folder name of a specified position.
int regexMatch(string er, string line); //implement regex by regex.h
