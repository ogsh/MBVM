//
//  CSV.h
//  MBVM
//
//  Created by ogsh on 2013/10/05.
//  Copyright (c) 2013年 ogsh. All rights reserved.
//

#ifndef MBVM_CSV_h
#define MBVM_CSV_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class CSV {
public:
    CSV(const string& filepath = "", const char delimiter = ',') : cols(0), rows(0), delimiter(delimiter) {
        if(filepath != "") {
            this->Read(filepath, delimiter);
        }
    }

    int Read(const string& filepath = "", const char delimiter = ',') {
        string line_buff;
        string buff;

        ifstream ifs(filepath);
        if(!ifs) {
            cerr << "Error: CSV Read (No such file: " << filepath << ")" << endl;
            return -1;
        }
        
        this->cols = 0;
        this->rows = 0;
        while(getline(ifs, line_buff)) {
            int tmp_cols = 0;
            istringstream stream(line_buff);
            while(getline(stream, buff, delimiter)) {
                if(this->rows == 0) {
                    this->cols ++;
                }
                tmp_cols ++;
            }
            if(this->cols != tmp_cols) {
                cerr << "Error: Invalid CSV File" << endl;
                return -1;
            }
            this->rows ++;
        }
        
        ifs.close();
        ifs.open(filepath);
        
        this->data = vector<string>(0);
        while(getline(ifs, line_buff)) {
            istringstream stream(line_buff);
            while(getline(stream, buff, delimiter)) {
                this->data.push_back(buff);
            }
        }
        
        ifs.close();
        
        return 0;
    }
    
    void Write(const string& filepath, bool isAppend) {
        ofstream ofs(filepath, isAppend? ios::app : ios::out);
        
        for(int j=0; j < this->rows; ++j) {
            for(int i=0; i < this->cols; ++i) {
                ofs << this->At(i, j);
                if(i == this->cols - 1) {
                    ofs << endl;
                }
                else {
                    ofs << this->delimiter;
                }
            }
        }

        ofs.close();
        
    }
    
    string At(int x, int y) const {
        if(x < 0 || x >= this->cols || y < 0 || y >= this->rows) {
            cerr << "Error: CSV At (Out of Index)" << endl;
            return "";
        }
        int index = y * this->cols + x;
        return this->data[index];
    }
    
    friend ostream& operator<<(ostream& os, const CSV& obj) {
        string dbar(30, '=');
        string bar(30, '-');
        os << dbar << endl;
        os << "cols:" << obj.cols << " rows:" << obj.rows << endl;
        os << bar << endl;
        for(int j=0; j < obj.rows; ++j) {
            for(int i=0; i < obj.cols; ++i) {
                os << obj.At(i, j);
                if(i == obj.cols - 1) {
                    os << endl;
                }
                else {
                    os << obj.delimiter;
                }
            }
        }
        os << dbar << endl;
        return os;
    }
    
    int Rows() {
        return this->rows;
    }
    int Cols() {
        return this->cols;
    }

private:
    int rows;
    int cols;
    char delimiter;
    vector<string> data;

};

#endif
