/*

Practica #2: Computabilidad y Algoritmia

Name: word_analyzer.h
Purpose of the code: Analyze the words of an entry
                     file and import those words, categorized,
                     into an exit file.

Content of the file: Declaration of the cclass analyzer_t,
                     the constructor, destructor, Comparation
                     method and the Write methods.

Author: Noah Sanchez Geurts
Date: 02/10/2019

*/

#include <iostream>
#include <set>
#include <regex>
#include <ctype.h>
#include <fstream>
#include <sstream>

using namespace std;

class analyzer_t {

  private:

    set<string> special_;
    set<string> oper_;
    set<string> sign_;

  public:

    analyzer_t(void);
    ~analyzer_t(){}

    void Comparation(char* fich, char* fich2);
    void Write(char* file, string type, string pal);
    void Write_Special(char* file, string pal);
};


/*

Practica #2: Computabilidad y Algoritmia

Name: word_analyzer.h
Purpose of the code: Analyze the words of an entry
                     file and import those words, categorized,
                     into an exit file.

Content of the file: Declaration of the cclass analyzer_t,
                     the constructor, destructor, Comparation
                     method and the Write methods.

Author: Noah Sanchez Geurts
Date: 02/10/2019

*/

#include <iostream>
#include <set>
#include <regex>
#include <ctype.h>
#include <fstream>
#include <sstream>

using namespace std;

class analyzer_t {

  private:

    set<string> special_;
    set<string> oper_;
    set<string> sign_;

  public:

    analyzer_t(void);
    ~analyzer_t(){}

    void Comparation(char* fich, char* fich2);
    void Write(char* file, string type, string pal);
    void Write_Special(char* file, string pal);
};


