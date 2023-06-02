#pragma once

#include <stack>
#include <vector>
#include <cstring>

namespace vulgar {
    namespace blueprint {
        class Flow;

        class Context {
        public:
            std::vector<std::map<std::string, void*>> _data;

            Context() {
            }

            virtual ~Context() = default;

            void pushContext() {
                this->_data.emplace_back();
            }

            void popContext() {
                for(auto[key, value]: _data.back()){
                    free(value);
                }
                this->_data.pop_back();

            }

            template<typename T>
            T getVar(const std::string& varName) {
                for (int i = (int)_data.size() - 1 ; i >= 0; i--) {
                    if (_data[i].find(varName) != _data[i].end()) {
                        return *((T*)_data[i][varName]);
                    }
                }
                exit(404); //TODO: throw exception here
            }

            template<typename T>
            bool setVar(const std::string& varName, T value) {
                for (int i = (int)_data.size() - 1 ; i >= 0; i--) {
                    if (_data[i].find(varName) != _data[i].end()) {
                        *((T*)(_data[i][varName])) = value;
                        return true;
                    }
                }
                return false;
            }

            template<typename T>
            void newVar(const std::string& varName, T value) {
                void *var = calloc(sizeof(T), 1);
                *((T*)var) = value;
                _data.back()[varName] = var;
            }
        };
    };
};