#include "parser.h"
#include "production.h"
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>

using namespace std;

 stack< string> strStack;
 stack< string> varStack;
int tempNum;
int labelNum;

 string i_to_temp(int i)
{
     ostringstream temp;
    temp<<"T"<<i;
    return temp.str();
}

 string i_to_label(int i)
{
     ostringstream temp;
    temp<<"label"<<i;
    return temp.str();
}

 string varStackPop()
{
    auto var = varStack.top();
    varStack.pop();
    return var;
}

 string strStackPop()
{
    auto str = strStack.top();
    strStack.pop();
    return str;
}

 string cmd( string a,  string b,  string c,  string d)
{
    return  "(" + a + ", " + b + ", " + c + ", " + d + ")";
}

int Parser::translate(int id,  string name)
{
    switch(id)
    {
        case 3:
        {
            varStackPop();
            varStackPop();
            break;
        }

        case 9: case 10:
        {
            auto str = strStackPop();
             ostringstream os;
            os <<  endl << str;
            strStack.push(os.str());
            break;
        }

        case 13:
        {
            varStackPop();
            break;
        }

        case 15:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            strStack.push(os.str());
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            varStack.push(lvar);
            break;
        }

        case 24:
        {
            auto r = varStackPop();
            auto l = varStackPop();
             ostringstream os;
            os << strStackPop();
            os << cmd("=", r, "", l) <<  endl;
            strStack.push(os.str());
            varStack.push(l);
            break;
        }
        case 27:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("or", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 29:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("and", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 31:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("==", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 32:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("!=", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 34:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("<", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 35:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd(">", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 36:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("<=", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 37:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd(">=", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 39:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("+", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 40:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("-", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 42:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("*", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 43:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            os << lstr << rstr;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << cmd("/", lvar, rvar, i_to_temp(tempNum)) <<  endl;
            strStack.push(os.str());
            varStack.push(i_to_temp(tempNum));
            tempNum++;
            break;
        }
        case 44: case 45: case 46: case 47:
        {
            strStack.push("");
            break;
        }

        case 49:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            auto rvar = varStackPop();
            auto lvar = varStackPop();

            os << cmd(i_to_label(labelNum), "", "", "") <<  endl;
            os << lstr;
            os << cmd("J!=", lvar, "0", i_to_label(labelNum + 1)) <<  endl;
            os << cmd("J", "", "", i_to_label(labelNum + 2)) <<  endl;
            os << cmd(i_to_label(labelNum + 1), "", "", "") <<  endl;
            os << rstr;
            os << cmd("J", "", "", i_to_label(labelNum)) <<  endl;
            os << cmd(i_to_label(labelNum + 2), "", "", "") <<  endl;
            labelNum += 3;
            strStack.push(os.str());
            varStack.push(lvar);
            break;
        }

        case 52:
        {
            auto rstr = strStackPop();
            auto lstr = strStackPop();
             ostringstream os;
            auto rvar = varStackPop();
            auto lvar = varStackPop();
            os << lstr;
            os << cmd("J!=", lvar, "0", i_to_label(labelNum)) <<  endl;
            os << cmd("J", "", "", i_to_label(labelNum + 1)) <<  endl;
            os << cmd(i_to_label(labelNum), "", "", "") <<  endl;;
            os << rstr;
            os << cmd(i_to_label(labelNum + 1), "", "", "") <<  endl;
            labelNum += 2;
            strStack.push(os.str());
            varStack.push(lvar);
            break;
        }

        case 53:
        {
            auto rstr = strStackPop();
            auto midstr = strStackPop();
            auto lstr = strStackPop();

             ostringstream os;
            auto rvar = varStackPop();
            auto midvar = varStackPop();
            auto lvar = varStackPop();

            os << lstr;
            os << cmd("J!=", lvar, "0", i_to_label(labelNum)) <<  endl;
            os << cmd("J", "", "", i_to_label(labelNum + 1)) <<  endl;
            os << cmd(i_to_label(labelNum), "", "", "") <<  endl;;
            os << midstr;
            os << cmd("J", "", "", i_to_label(labelNum + 2)) <<  endl;
            os << cmd(i_to_label(labelNum + 1), "", "", "") <<  endl;
            os << rstr;
            os << cmd(i_to_label(labelNum + 2), "", "", "") <<  endl;
            labelNum += 3;
            strStack.push(os.str());
            varStack.push(lvar);
            break;
        }

        default:
            break;
    }
    return 1;
}

// analyze the tokens with grammar
int Parser::analyse(const  vector<Token> &tokens)
{
    tempNum = 0;
    labelNum = 0;
    build();
     stack< pair<unsigned int,  string>> st;
    st.push({0,"$"});

    auto iter = tokens.cbegin();
    for(; ; )
    {
        auto I = st.top().first;
         string type;
        if(iter->get_type() == Token_Type::ID || iter->get_type() == Token_Type::CHAR
           || iter->get_type() == Token_Type::INT || iter->get_type()== Token_Type::FLOAT )
            type = TokenDict[iter->get_type()];
        else
            type = iter->getname();

        if(action[I].find(type) != action[I].end())
        {
            auto act = action[I][type];
            if(act.first == "S")
            {
                if(iter->get_type() == Token_Type::ID || iter->get_type() == Token_Type::CHAR
                   || iter->get_type() == Token_Type::INT || iter->get_type()== Token_Type::FLOAT )
                    {
                        varStack.push(iter->getname());
                        //cout<<"[pushVAR] "<<iter->getname() <<"   [at line "<<iter->get_line()<<"]"<<endl;
                    }
                st.push({act.second, type});
                iter++;
            }
            else if(act.first == "r")
            {
                auto id = act.second;
                auto right = grammar[id].get_right();
                for(unsigned int i=0; i<right.size(); i++)
                    if(right[i] != "@")
                        st.pop();
                auto newI = st.top().first;
                st.push({go[newI][grammar[id].get_left()],grammar[id].get_left()});
                if(!translate(id, iter->getname()))
                {
                     cout<<"ERROR! at line "<<iter->get_line()<< endl;
                    return iter->get_line();
                }
            }
            else if(act.first == "acc")
            {
                 cout<<"Accept!"<< endl<< endl;
                 cout<<strStack.top()<< endl;
                return 0;
            }
        }
        else
        {
             cout<<"ERROR! at line "<<iter->get_line()<< endl;
            return iter->get_line();
        }
    }
    return 0;
}

// get one symbol's first set
 set< string> Parser::get_f(const  string &symbol)
{
    if(first_map.find(symbol) != first_map.end())         // have this set, then return
        return first_map[symbol];
     set< string> ret;
    if(terminals.find(symbol) != terminals.end())   // is a terminal symbol
    {
        ret.insert(symbol);
        return ret;
    }
    else                                                // is a variable symbol
    {
        for(auto production:grammar)
        {
            if(production.get_left() == symbol)
            {
                auto right = production.get_right();
                if(right.size() == 1 && right[0] == "@")  //insert @
                {
                    ret.insert("@");
                    continue;
                }
                else if(right.size() > 0                //insert the first terminal symbol
                        && terminals.find(right[0]) != terminals.end())
                {
                    ret.insert(right[0]);
                    continue;
                }
            }
        }
    }
    return ret;
}

// build the first Map, first_map[x] = first(x)
void Parser::build_first_map()
{
    first_map.clear();

    // basic
    for(auto symbol : terminals)
        first_map.insert({symbol, get_f(symbol)});
    for(auto symbol : variables)
        first_map.insert({symbol, get_f(symbol)});

    // merge
    for(; ; )
    {
        bool changed = false;
        for(auto symbol : variables)
        {
            //if(symbol == "ADD")cout<<"get first (add) "<<endl;
            for(;;)
            {
                auto temp = first_map[symbol];
                //if(symbol == "ADD"){cout<<"first= ";for(auto e:temp)cout<<e<<" ";cout<<endl;}
                for(auto produciton : grammar)
                {
                    if(produciton.get_left() == symbol)
                    {
                        bool allEmpty = true;
                        auto right = produciton.get_right();
                        //if(symbol == "ADD"){cout<<"  right= ";for(auto e:right)cout<<e<<" ";cout<<endl;}
                        for(auto one:right)
                        {
                            auto oneSet = first_map[one];
                            //if(symbol == "ADD"){cout<<"  oneset= ";for(auto e:oneSet)cout<<e<<" ";cout<<endl;}
                            if(oneSet.erase("@"))
                            {
                                temp.insert(oneSet.begin(), oneSet.end());
                            }
                            else
                            {
                                temp.insert(oneSet.begin(), oneSet.end());
                                allEmpty = false;
                                break;
                            }
                        }
                        if(allEmpty)
                            temp.insert("@");
                    }
                }
                //if(symbol == "ADD"){cout<<" now tot = ";for(auto e:temp)cout<<e<<" ";cout<<endl;}
                if(temp == first_map[symbol])
                    break;
                first_map[symbol] = temp;
                changed = true;
            }
        }
        if(!changed)
            break;
    }
}

// get first(beta), beta = A1A2...An
 set< string> Parser::get_f(const  vector< string> &beta)
{
     set< string> ret;
    bool allEmpty = true;
    for(auto one:beta)
    {
        auto oneSet = first_map[one];
        if(oneSet.erase("@"))
        {
            ret.insert(oneSet.begin(), oneSet.end());
        }
        else
        {
            ret.insert(oneSet.begin(), oneSet.end());
            allEmpty = false;
            break;
        }
    }
    if(allEmpty)
        ret.insert("@");
    return ret;
}

// build action and goto table
void Parser::build()
{
    if(closuremap.size() != 0)                      // have built action and goto table
        return;

    build_first_map();

    auto closure0 = get_Closure(LR1_item(LR0_item(0,0), "$"));

     queue<LR1set> q;
    q.push(closure0);

    //closuremap[closure0] = closuremap.size();     // first insert closure, then map[closure] = 1

    closurelist.push_back(closure0);
    closuremap.insert(make_pair(closure0, closuremap.size()));

	static int ip = 1;
    while(!q.empty())
    {
		//cout << ip++ << endl;
        auto lr1set = q.front();
        q.pop();
        transfer.push_back(vpsi());

        for(auto variable:variables)
        {
            LR1set newset;
            for(auto lr1:lr1set)
            {
                auto lr0 = lr1.get_left();
                auto id = lr0.get_left();
                auto pointpos = lr0.get_right();
                if(grammar[id].get_right().size()>pointpos && grammar[id].get_right()[pointpos]==variable)
                    newset.insert(LR1_item(LR0_item(id,pointpos+1),lr1.get_right()));
            }
            if(newset.size()!=0)
            {
                get_Closure(newset);
                if(closuremap.find(newset)==closuremap.end())
                {
                    closurelist.push_back(newset);
                    closuremap.insert(make_pair(newset,closuremap.size()));
                    q.push(newset);
                }
                transfer[transfer.size()-1].push_back(make_pair(variable,closuremap[newset]));
            }
        }

        for(auto terminal:terminals)
        {
            LR1set newset;
            for(auto lr1:lr1set)
            {
                auto lr0 = lr1.get_left();
                auto id = lr0.get_left();
                auto pointpos = lr0.get_right();
                if(grammar[id].get_right().size()!=pointpos && grammar[id].get_right()[pointpos]==terminal)
                    newset.insert(LR1_item(LR0_item(id,pointpos+1),lr1.get_right()));
            }
            if(newset.size()!=0)
            {
                get_Closure(newset);
                if(closuremap.find(newset)==closuremap.end())
                {
                    closurelist.push_back(newset);
                    closuremap.insert(make_pair(newset,closuremap.size()));
                    //closuremap[newset]=closuremap.size();
                    q.push(newset);
                }
                transfer[transfer.size()-1].push_back( make_pair(terminal,closuremap[newset]));
            }
        }
    }

    for(unsigned int i=0; i<closurelist.size(); i++)
    {
        action.push_back( map< string, psi>());
        go.push_back( map< string, int>());

        for(auto lr1:closurelist[i])
        {
            auto point = lr1.get_left().get_right();
            auto right = grammar[lr1.get_left().get_left()].get_right();
            if(point < right.size() && terminals.find(right[point])!=terminals.end())
            {
                for(auto go:transfer[i])
                    if(go.first==right[point])
                    {
                        action[i][right[point]]= make_pair("S",go.second);
                    }
            }
        }

        for(auto tf:transfer[i])
        {
            if(variables.find(tf.first)!=variables.end())
            {
                go[i][tf.first]=tf.second;

            }
        }

        for(auto lr1:closurelist[i])
        {
            auto lookahead = lr1.get_right();
            auto lr0 = lr1.get_left();
            auto id = lr0.get_left();
            auto point = lr0.get_right();
            auto right = grammar[id].get_right();

            if(point == right.size())
            {
                // deal with if else / if
                if(!(action[i].find(lookahead)!=action[i].end()
                   && action[i][lookahead]!= pair< string,int>("r",id)))
                    action[i][lookahead]= make_pair("r",id);

                if(lookahead=="$" && id==0)
                {
                    action[i][lookahead]= make_pair("acc",0);
                }
            }
        }
    }
}

// open grammar.txt, read grammar
bool Parser::openfile(const  string &fileName)
{
     ifstream in(fileName);

    if(in)
    {
         string str;
        int type = 0;
        while(in>>str)
        {
            if(str=="[terminal]")
            {
                type = 1;
                continue;
            }
            else if(str=="[variable]")
            {
                type = 2;
                continue;
            }
            else if(str=="[production]")
                break;
            else
            {
                if(type==1)
                    terminals.insert(str);
                else if(type==2)
                    variables.insert(str);
            }
        }

        while(getline(in,str))
        {
            if(str.empty())
                continue;
             string temp;
             istringstream iss =  istringstream(str);
            Production production;
            iss >> temp;
            iss >> temp;
            production.set_left(temp);
            while(iss >> temp)
            {
              if(temp == "->")
                continue;
              production.add_right(temp);
            }
            grammar.push_back(production);
        }
        return true;
    }
    else
    {
        return false;
    }
}

// get grammar
 vector<Production> Parser::get_grammar()
{
    return grammar;
}

// get a closure set with LR1_item item
 set<LR1_item> Parser::get_Closure(const LR1_item &item)
{
     set<LR1_item> closure = {item};
    get_Closure(closure);
    return closure;
}

// get the closure
void Parser::get_Closure( set<LR1_item> &closure)
{
     set<LR1_item> temp;

    for(;;)
    {
        temp = closure;

        for(auto lr1:closure)
        {
            LR0_item lr0 = lr1.get_left();
             string lookahead = lr1.get_right();

            unsigned int pointPos = lr0.get_right();
            auto right = grammar[lr0.get_left()].get_right();

            if(pointPos != right.size() && variables.find(right[pointPos]) != variables.end())
            {
                 string B = right[pointPos];

                 vector< string> beta;
                for(unsigned int i = pointPos + 1; i < right.size(); i++)
                    beta.push_back(right[i]);
                beta.push_back(lookahead);

                auto first = get_f(beta);

                for(unsigned int productionID = 0; productionID < grammar.size(); productionID++)
                {
                    const Production &production = grammar[productionID];
                    if(production.get_left() == B)
                    {
                        for(auto terminal:first)
                        {
                            LR1_item newItem;
                            if(production.get_right().size() == 1 && production.get_right()[0] == "@")
                                newItem = LR1_item(LR0_item(productionID, 1), terminal);
                            else
                                newItem = LR1_item(LR0_item(productionID, 0), terminal);
                            if(closure.find(newItem) == closure.end())
                                temp.insert(newItem);
                        }
                    }
                }
            }
        }
        if(temp == closure)
            break;
        else
            closure = temp;
    }
}

// get closure list
 vector<  set<LR1_item> > Parser::get_closurelist()
{
    return closurelist;
}

// get closure map
 map<  set<LR1_item>, int> Parser::get_closure_map()
{
    return closuremap;
}

// get transfer
 vector< vpsi > Parser::get_transfer()
{
    return transfer;
}

// get action table
 vector<  map< string, psi>> Parser::get_action()
{
    return action;
}

// get goto table
 vector<  map< string, int>> Parser::get_go()
{
    return go;
}

// get variable symbol set
 set<  string > Parser::get_variables()
{
    return variables;
}

// get terminal symbol set
 set<  string > Parser::get_terminals()
{
    return terminals;
}
