#include "dictionary.h"

Dictionary::Dictionary(){
    words.begin()=words.end();
}

Dictionary::Dictionary(const Dictionary & other){
    words = other.words;
}

bool Dictionary::exists(const string & val) const{
    bool existe = false;
    set<string>::iterator pos;
    for(pos = words.begin(); pos != words.end(); ++pos){
        if((*pos)==val) existe = true;
    }
    return existe;
}

bool Dictionary::insert(const string & val){
    return words.insert(val).second;
}

bool Dictionary::erase(const string & val){
    return words.erase(val);
}

void Dictionary::clear(){
    words.clear();
}

bool Dictionary::empty()const{
    return words.empty();
}

unsigned int Dictionary::size()const{
    return words.size();
}

int Dictionary::getOccurences(const char c){
    int ocurrencias = 0;
    set<string>::iterator pos;
    for(pos = words.begin(); pos != words.end(); ++pos){
        for(int i=0; i<(*pos).size(); i++){
            if((*pos)[i] == c) ocurrencias++;
        }
    }
    return ocurrencias;
}

int Dictionary::getTotalLetters(){
    int total = 0;
    set<string>::iterator pos;
    for(pos = words.begin(); pos != words.end(); ++pos){
        total += (*pos).size();
    }
    return total;
}

vector<string> Dictionary::wordsOfLength(int length){
    vector<string> palabras;
    set<string>::iterator pos;
    for(pos = words.begin(); pos != words.end(); ++pos){
        if((*pos).size()==length) palabras.push_back((*pos));
    }
    return palabras;
}

ostream & operator << (ostream & os, const Dictionary & d){

    set<string>::iterator pos;
    for(pos = d.words.begin(); pos != d.words.end(); ++pos){
       os << (*pos) << endl;
    }
    return os;
}


istream & operator >> (istream & is, Dictionary & d) {
    string palabra;
    while(is){
        is >> palabra;
        d.words.insert(palabra);
    }
    return is;
}
