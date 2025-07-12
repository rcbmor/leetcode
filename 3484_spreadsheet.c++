/**
 * LeetCode problem 3484
 * https://leetcode.com/problems/design-spreadsheet/
 */

#include<cassert>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Spreadsheet {
    map<string, int> table;
public:
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        this->table[cell] = value;
    }

    int getCell(string cell) {
        //return this->table[cell];//if not found, adds (key, 0) -> 0
        int v = 0;
        try {
            v = this->table.at(cell);
        } catch(std::out_of_range e) {
            return 0;
        }
        return v;
    }

    void resetCell(string cell) {
        this->table[cell] = 0;        
    }
    
    int getValue(string formula) {

        int plus = formula.find("+");
        string oper1 = formula.substr(1, plus-1);
        string oper2 = formula.substr(plus + 1);

        int v1 = (isdigit(oper1.at(0))) ? atoi(oper1.c_str()) : this->getCell(oper1);
        int v2 = (isdigit(oper2.at(0))) ? atoi(oper2.c_str()) : this->getCell(oper2);

        int res = v1 + v2;
        return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
int main()
{

    { // example 1
        // ["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
        // [[3],             ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]

        Spreadsheet* s1 = new Spreadsheet(3);
        string input = "=5+7";
        int output = 0;
        output = s1->getValue(input);
        cout << "> " << input << " : " << output << endl;
        assert((output == 12));

        s1->setCell("A1", 10);
        output = s1->getCell("A1");
        cout << "> " << output << endl;
        assert((output == 10));

        input = "=A1+6";
        output = s1->getValue(input);
        cout << "> " << input << " : " << output << endl;
        assert((output == 16));

        s1->setCell("B2", 15);
        input = "=A1+B2";
        output = s1->getValue(input);
        cout << "> " << input << " : " << output << endl;
        assert((output == 25));

        s1->resetCell("A1");
        output = s1->getValue(input);
        cout << "> " << input << " : " << output << endl;
        assert((output == 15));

        input = "=O126+10272";
        output = s1->getValue(input);
        cout << "> " << input << " : " << output << endl;
        assert((output == 10272));

    }

    return 0;
}
