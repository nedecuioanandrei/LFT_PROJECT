#include <bits/stdc++.h>
#include "Print.h"
#include "Const.h"
#include "Context.h"
#include "Cast.h"
#include "GetVar.h"
#include "SetVar.h"
#include "fstream"
#include "BinaryFunction.h"
#include "Branch.h"
#include "NewVar.h"
#include "ContextNodes.h"

using namespace std;
using namespace vulgar::blueprint;


std::map<int, Node *> nodes;
Context context;

int main(int argc, char **argv) {
    ifstream f1(argv[1]);
    ifstream f2(argv[1]);

    std::string line;
    nodes[0] = nullptr;
    while (std::getline(f1, line)) {
        istringstream sline(line);
        int id;
        std::string type;

        sline >> id >> type;

        //CONST
        if (type == "CONST_INT") {
            int value;
            sline >> value;
            auto node = new Const<int>(value);
            nodes[id] = node;
        } else if (type == "CONST_FLOAT") {
            float value;
            sline >> value;
            auto node = new Const<float>(value);
            nodes[id] = node;
        } else if (type == "CONST_STR") {
            std::string value;
            char c;
            sline.get();
            while(sline.get(c)) {
                if (c != '"') value.push_back(c);
            }
            auto node = new Const<std::string>(value);
            nodes[id] = node;
        } else if (type == "CONST_BOOL") {
            bool value;
            sline >> value;
            auto node = new Const<bool>(value);
            nodes[id] = node;
        }
            //OPERATORS
        else if (type == "SUM_INT") {
            auto node = new Sum<int>;
            nodes[id] = node;
        } else if (type == "SUM_FLOAT") {
            auto node = new Sum<float>;
            nodes[id] = node;
        } else if (type == "SUM_STR") {
            auto node = new Sum<std::string>;
            nodes[id] = node;
        } else if (type == "SUB_INT") {
            auto node = new Subtract<int>;
            nodes[id] = node;
        } else if (type == "SUB_FLOAT") {
            auto node = new Subtract<float>;
            nodes[id] = node;
        } else if (type == "MUL_INT") {
            auto node = new Multiply<int>;
            nodes[id] = node;
        } else if (type == "MUL_FLOAT") {
            auto node = new Multiply<float>;
            nodes[id] = node;
        } else if (type == "DIV_INT") {
            auto node = new Divide<int>;
            nodes[id] = node;
        } else if (type == "DIV_FLOAT") {
            auto node = new Divide<float>;
            nodes[id] = node;
        } else if (type == "MOD") {
            auto node = new Modulo<int>;
            nodes[id] = node;
        }
            //LOGICAL
        else if (type == "AND") {
            auto node = new And;
            nodes[id] = node;
        } else if (type == "OR") {
            auto node = new Or;
            nodes[id] = node;
        }
            //COMPARISON
        else if (type == "LT_INT") {
            auto node = new Less<int>();
            nodes[id] = node;
        } else if (type == "LT_FLOAT") {
            auto node = new Less<float>();
            nodes[id] = node;
        } else if (type == "LE_INT") {
            auto node = new LessEqual<int>;
            nodes[id] = node;
        } else if (type == "LE_FLOAT") {
            auto node = new LessEqual<float>;
            nodes[id] = node;
        } else if (type == "EQ_INT") {
            auto node = new Equal<int>;
            nodes[id] = node;
        } else if (type == "EQ_FLOAT") {
            auto node = new Equal<float>;
            nodes[id] = node;
        } else if (type == "EQ_STR") {
            auto node = new Equal<std::string>;
            nodes[id] = node;
        } else if (type == "EQ_BOOL") {
            auto node = new Equal<bool>;
            nodes[id] = node;
        } else if (type == "GE_INT") {
            auto node = new GreaterEqual<int>;
            nodes[id] = node;
        } else if (type == "GE_FLOAT") {
            auto node = new GreaterEqual<float>;
            nodes[id] = node;
        } else if (type == "GT_INT") {
            auto node = new Greater<int>;
            nodes[id] = node;
        } else if (type == "GT_FLOAT") {
            auto node = new Greater<float>;
            nodes[id] = node;
        } else if (type == "NE_INT") {
            auto node = new NotEqual<int>;
            nodes[id] = node;
        } else if (type == "NE_FLOAT") {
            auto node = new NotEqual<float>;
            nodes[id] = node;
        }
            // SET / GET / NEW
        else if (type == "SET_INT") {
            auto node = new SetVar<int>();
            nodes[id] = node;
        } else if (type == "SET_FLOAT") {
            auto node = new SetVar<float>;
            nodes[id] = node;
        } else if (type == "SET_STR") {
            auto node = new SetVar<std::string>();
            nodes[id] = node;
        } else if (type == "SET_BOOL") {
            auto node = new SetVar<bool>();
            nodes[id] = node;
        }
        else if (type == "GET_INT") {
            auto node = new GetVar<int>();
            nodes[id] = node;
        } else if (type == "GET_FLOAT") {
            auto node = new GetVar<float>();
            nodes[id] = node;
        } else if (type == "GET_STR") {
            auto node = new GetVar<std::string>();
            nodes[id] = node;
        } else if (type == "GET_BOOL") {
            auto node = new GetVar<bool>();
            nodes[id] = node;
        }
        else if(type == "NEW_INT") {
            auto node = new NewVar<int>();
            nodes[id] = node;
        } else if(type == "NEW_FLOAT") {
            auto node = new NewVar<float>();
            nodes[id] = node;
        } else if(type == "NEW_STR") {
            auto node = new NewVar<std::string>();
            nodes[id] = node;
        } else if(type == "NEW_BOOL") {
            auto node = new NewVar<bool>();
            nodes[id] = node;
        }
        else if(type == "PUSH_CONTEXT") {
            auto node = new PushContext();
            nodes[id] = node;
        } else if(type == "POP_CONTEXT") {
            auto node = new PopContext();
            nodes[id] = node;
        }
            // CAST
        else if(type == "CAST_FLOAT_INT"){
            auto node = new Cast<float, int>();
            nodes[id] = node;
        } else if(type == "CAST_STR_INT"){
            auto node = new Cast<std::string, int>();
            nodes[id] = node;
        } else if(type == "CAST_BOOL_INT"){
            auto node = new Cast<bool, int>();
            nodes[id] = node;
        }
        else if (type == "CAST_INT_STR") {
            auto node = new Cast<int, std::string>();
            nodes[id] = node;
        } else if (type == "CAST_FLOAT_STR"){
            auto node = new Cast<float, std::string>();
            nodes[id] = node;
        } else if(type == "CAST_BOOL_STR") {
            auto node = new Cast<bool, std::string>();
            nodes[id] = node;
        }
        else if (type == "CAST_INT_FLOAT") {
            auto node = new Cast<int, float>();
            nodes[id] = node;
        } else if (type == "CAST_STR_FLOAT"){
            auto node = new Cast<std::string, float>();
            nodes[id] = node;
        } else if(type == "CAST_BOOL_FLOAT") {
            auto node = new Cast<bool, float>();
            nodes[id] = node;
        }
        else if (type == "CAST_INT_BOOL") {
            auto node = new Cast<int, bool>();
            nodes[id] = node;
        } else if (type == "CAST_FLOAT_STR"){
            auto node = new Cast<float, bool>();
            nodes[id] = node;
        } else if(type == "CAST_STR_BOOL") {
            auto node = new Cast<std::string, bool>();
            nodes[id] = node;
        }
        //Flow control
        else if (type == "IF") {
            auto node = new Branch();
            nodes[id] = node;
        } else if(type == "PRINT") {
            auto node = new Print();
            nodes[id] = node;
        }
    }


    //LINKING
    while (std::getline(f2, line)) {
        istringstream sline(line);
        int id;
        std::string type;
        sline >> id >> type;

        //CONST
        if (type == "CONST_INT") {

        } else if (type == "CONST_FLOAT") {

        } else if (type == "CONST_STR") {

        } else if (type == "CONST_BOOL") {

        }
            //OPERATORS
        else if (type == "SUM_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Sum<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "SUM_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Sum<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "SUM_STR") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Sum<std::string>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<std::string>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<std::string>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "SUB_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Subtract<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "SUB_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Subtract<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "MUL_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Multiply<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "MUL_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Multiply<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "DIV_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Divide<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "DIV_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Divide<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "MOD") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Modulo<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        }
            //LOGICAL
        else if (type == "AND") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<And*>(nodes[id]);
            auto i1 = dynamic_cast<Data<bool>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<bool>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "OR") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Or*>(nodes[id]);
            auto i1 = dynamic_cast<Data<bool>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<bool>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        }
            //COMPARISON
        else if (type == "LT_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Less<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "LT_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Less<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "LE_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<LessEqual<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "LE_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<LessEqual<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "EQ_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Equal<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "EQ_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Equal<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "EQ_STR") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Equal<std::string>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<std::string>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<std::string>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "EQ_BOOL") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Equal<bool>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<bool>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<bool>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "GE_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<GreaterEqual<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "GE_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<GreaterEqual<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "GT_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Greater<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "GT_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<Greater<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "NE_INT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<NotEqual<int>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<int>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<int>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        } else if (type == "NE_FLOAT") {
            int id1, id2;
            sline >> id1 >> id2;
            auto node = dynamic_cast<NotEqual<float>*>(nodes[id]);
            auto i1 = dynamic_cast<Data<float>*>(nodes[id1]);
            auto i2 = dynamic_cast<Data<float>*>(nodes[id2]);
            node->param1 = i1;
            node->param2 = i2;
        }
            // SET / GET / NEW
        else if (type == "SET_INT") {
            int id_input, id_next;
            std::string varName;
            sline >> varName >> id_input >> id_next;

            auto node = dynamic_cast<SetVar<int>*>(nodes[id]);
            node->varName = varName;
            node->input = dynamic_cast<Data<int>*>(nodes[id_input]);
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if (type == "SET_FLOAT") {
            int id_input, id_next;
            std::string varName;
            sline >> varName >> id_input >> id_next;

            auto node = dynamic_cast<SetVar<float>*>(nodes[id]);
            node->varName = varName;
            node->input = dynamic_cast<Data<float>*>(nodes[id_input]);
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if (type == "SET_STR") {
            int id_input, id_next;
            std::string varName;
            sline >> varName >> id_input >> id_next;

            auto node = dynamic_cast<SetVar<std::string>*>(nodes[id]);
            node->varName = varName;
            node->input = dynamic_cast<Data<std::string>*>(nodes[id_input]);
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if (type == "SET_BOOL") {
            int id_input, id_next;
            std::string varName;
            sline >> varName >> id_input >> id_next;

            auto node = dynamic_cast<SetVar<bool>*>(nodes[id]);
            node->varName = varName;
            node->input = dynamic_cast<Data<bool>*>(nodes[id_input]);
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if (type == "GET_INT") {
            std::string varName;
            sline >> varName;

            auto node = dynamic_cast<GetVar<int>*>(nodes[id]);
            node->varName = varName;
        } else if (type == "GET_FLOAT") {
            std::string varName;
            sline >> varName;

            auto node = dynamic_cast<GetVar<float>*>(nodes[id]);
            node->varName = varName;
        } else if (type == "GET_STR") {
            std::string varName;
            sline >> varName;

            auto node = dynamic_cast<GetVar<std::string>*>(nodes[id]);
            node->varName = varName;
        } else if (type == "GET_BOOL") {
            std::string varName;
            sline >> varName;

            auto node = dynamic_cast<GetVar<bool>*>(nodes[id]);
            node->varName = varName;
        }
        else if(type == "NEW_INT") {
            int id_next;
            int value;
            std::string varName;
            sline >> varName >> id_next >> value;

            auto node = dynamic_cast<NewVar<int>*>(nodes[id]);
            node->varName = varName;
            node->value = value;
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if(type == "NEW_FLOAT") {
            int id_next;
            float value;
            std::string varName;
            sline >> varName >> id_next >> value;

            auto node = dynamic_cast<NewVar<float>*>(nodes[id]);
            node->varName = varName;
            node->value = value;
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if(type == "NEW_STR") {
            int id_next;
            std::string value;
            std::string varName;
            sline >> varName >> id_next;

            char c;
            sline.get();
            while(sline.get(c)) {
                if (c != '"') value.push_back(c);
            }

            auto node = dynamic_cast<NewVar<std::string>*>(nodes[id]);
            node->varName = varName;
            node->value = value;
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if(type == "NEW_BOOL") {
            int id_next;
            bool value;
            std::string varName;
            sline >> varName >> id_next >> value;

            auto node = dynamic_cast<NewVar<bool>*>(nodes[id]);
            node->varName = varName;
            node->value = value;
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        }
        else if(type == "PUSH_CONTEXT") {
            int id_next;
            sline >> id_next;
            auto node = dynamic_cast<PushContext*>(nodes[id]);
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        } else if(type == "POP_CONTEXT") {
            int id_next;
            sline >> id_next;
            auto node = dynamic_cast<PopContext*>(nodes[id]);
            node->nextFlow = dynamic_cast<Flow*>(nodes[id_next]);
        }
            // CAST
        else if(type == "CAST_FLOAT_INT"){
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<float,int>*>(nodes[id]);
            auto input = dynamic_cast<Data<float>*>(nodes[id_input]);
            node->param = input;
        } else if(type == "CAST_STR_INT"){
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<std::string,int>*>(nodes[id]);
            auto input = dynamic_cast<Data<std::string>*>(nodes[id_input]);
            node->param = input;
        } else if(type == "CAST_BOOL_INT"){
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<bool,int>*>(nodes[id]);
            auto input = dynamic_cast<Data<bool>*>(nodes[id_input]);
            node->param = input;
        }
        else if (type == "CAST_INT_STR") {
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<int, std::string>*>(nodes[id]);
            auto input = dynamic_cast<Data<int>*>(nodes[id_input]);
            node->param = input;
        } else if (type == "CAST_FLOAT_STR"){
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<float, std::string>*>(nodes[id]);
            auto input = dynamic_cast<Data<float>*>(nodes[id_input]);
            node->param = input;
        } else if(type == "CAST_BOOL_STR") {
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<bool, std::string>*>(nodes[id]);
            auto input = dynamic_cast<Data<bool>*>(nodes[id_input]);
            node->param = input;
        }
        else if (type == "CAST_INT_FLOAT") {
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<int, float>*>(nodes[id]);
            auto input = dynamic_cast<Data<int>*>(nodes[id_input]);
            node->param = input;
        } else if (type == "CAST_STR_FLOAT"){
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<std::string, float>*>(nodes[id]);
            auto input = dynamic_cast<Data<std::string>*>(nodes[id_input]);
            node->param = input;
        } else if(type == "CAST_BOOL_FLOAT") {
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<bool, float>*>(nodes[id]);
            auto input = dynamic_cast<Data<bool>*>(nodes[id_input]);
            node->param = input;
        }
        else if (type == "CAST_INT_BOOL") {
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<int, bool>*>(nodes[id]);
            auto input = dynamic_cast<Data<int>*>(nodes[id_input]);
            node->param = input;
        } else if (type == "CAST_FLOAT_STR"){
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<float, std::string>*>(nodes[id]);
            auto input = dynamic_cast<Data<float>*>(nodes[id_input]);
            node->param = input;
        } else if(type == "CAST_STR_BOOL") {
            int id_input;
            sline >> id_input;
            auto node = dynamic_cast<Cast<std::string, bool>*>(nodes[id]);
            auto input = dynamic_cast<Data<std::string>*>(nodes[id_input]);
            node->param = input;
        }
        //Flow control
        else if (type == "IF") {
            int id_cond, id_true, id_false;
            sline >> id_cond >> id_true >> id_false;
            auto node = dynamic_cast<Branch*>(nodes[id]);
            auto cond = dynamic_cast<Data<bool>*>(nodes[id_cond]);
            auto true_node = dynamic_cast<Flow*>(nodes[id_true]);
            auto false_node = dynamic_cast<Flow*>(nodes[id_false]);

            node->condition = cond;
            node->trueFlow = true_node;
            node->falseFlow = false_node;
        } else if(type == "PRINT") {
            int input_id, id_next;
            sline >> input_id >> id_next ;

            auto node = dynamic_cast<Print*>(nodes[id]);
            auto input = dynamic_cast<Data<std::string>*>(nodes[input_id]);
            auto next = dynamic_cast<Flow*>(nodes[id_next]);

            node->input = input;
            node->nextFlow = next;
        }
    }

    context.pushContext();
    for (Flow *flow = dynamic_cast<Flow *>(nodes[1]); flow; flow = flow->getNextFlow(context)) {
        flow->run(context);
    }

    return 0;
}