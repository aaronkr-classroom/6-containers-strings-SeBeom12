#ifndef GUARD_border_h

#define GUARD_border_h


#include<string>
#include<vector>

using namespace std;

string::size_type width(const vector<string>& v);
vector<string>frame(const vector<string>& v);

vector<string>vcat(const vector<string>&,
	const vector<string>&);

vector<string>hcat(const vector<string>&,
	const vector<string>& );

#endif
