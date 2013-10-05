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

/**
 *  CSVファイルを扱うクラス
 */
class CSV {
public:
    /**
     *  コンストラクタ
     *
     *  @param filepath ファイルパス
     *  @param delimiter  区切り文字
     */
    CSV(const string& filepath = "", const char delimiter = ',') : cols(0), rows(0), delimiter(delimiter) {
        if(filepath != "") {
            this->Read(filepath, delimiter);
        }
    }

    /**
     *  CSVファイルの読み込みを行う
     *
     *  @param filepath ファイルパス
     *  @param delimiter  区切り文字
     *
     *  @return CSVファイル読み込み結果
     */
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

    /**
     *  CSVファイルへの書き込みを行う
     *
     *  @param filepath ファイルパス
     *  @param isAppend 追記するかどうか
     */
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

    /**
     *  CSVファイルの指定された位置にある文字列を取得する
     *
     *  @param x x座標
     *  @param y y座標
     *
     *  @return 文字列
     */
    string At(int x, int y) const {
        if(x < 0 || x >= this->cols || y < 0 || y >= this->rows) {
            cerr << "Error: CSV At (Out of Index)" << endl;
            return "";
        }
        int index = y * this->cols + x;
        return this->data[index];
    }

    /**
     *  出力用シフト演算子オーバーロード
     *
     *  @param os  出力先への参照
     *  @param obj 出力されるCSVオブジェクト
     *
     *  @return 出力先への参照
     */
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
    
    /**
     *  CSVファイルの行数を取得する
     *
     *  @return CSVファイルの行数
     */
    int Rows() {
        return this->rows;
    }
    
    /**
     *  CSVファイルの列数を取得する
     *
     *  @return CSVファイルの列数
     */
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
