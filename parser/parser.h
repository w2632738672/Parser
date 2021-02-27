#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "production.h"
#include "lritem.h"
#include "../scanner/token.h"
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef  pair<string, int> psi;
typedef  vector<psi> vpsi;
typedef  set<LR1_item> LR1set;

class Parser
{
private:
	vector<Production> grammar;   // store grammar
	vector<LR1set > closurelist;  // closure list
	map<LR1set, int> closuremap;  // closure map
	vector<vpsi > transfer;       // transfer function
	vector<map<string, psi>> action;     // action table
	vector<map<string, int>> go;         // goto table
	set<string > variables;                 // variable symbol set
	set<string > terminals;                 // terminal symbol set

	set<string> get_f(const string &symbol);                   // get first(symbol)
	set<string> get_f(const vector<string> &beta);   // get first(beta), beta = A1A2...An
	map<string, set<string>> first_map;  // first_map[X] = first(X), X is a symbol
	void build_first_map();                                   // build first map

	set<LR1_item> get_Closure(const LR1_item &item);      // get closure
	void get_Closure(LR1set &closure);                       // merge closure
	int translate(int id, string name);
public:
	Parser() {}

	bool openfile(const string &fileName);
	void build();

	vector<Production> get_grammar();

	vector< LR1set > get_closurelist();
	map< LR1set, int> get_closure_map();
	vector< vpsi > get_transfer();
	vector< map<string, psi>> get_action();
	vector< map<string, int>> get_go();
	int analyse(const vector<Token> &tokens);
	set< string > get_variables();
	set< string > get_terminals();
};
#endif // PARSER_H_INCLUDED