//
// Created by zbz on 1/5/19.
//
#include <opencv2/opencv.hpp>
#include <iostream>
#include <zbar.h>

#include "json/json.h"

using namespace cv;
using namespace std;
using namespace zbar;

int main(int argc,char* argv[])
{
    if(argc != 2){
        cout << "Error: the number of argument is incorrect!" << endl;
        return -1;
    }
    char windowNameString[50];

    Mat grayImage;
    string img_path =  argv[1];
    sprintf(windowNameString,"result");
    Mat result = imread(img_path);
    if(!result.empty()) {
        //现在开始识别
        cvtColor(result, grayImage, CV_RGB2GRAY);

        int width = grayImage.cols;   // extract dimensions
        int height = grayImage.rows;
        Image image(width, height, "Y800", grayImage.data, width * height);
        // Create a zbar reader
        ImageScanner scanner;
        // Configure the reader
        scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

//            imshow(windowNameString,grayImage);
//            waitKey(0);
        Json::StyledWriter sw;
        //根节点
        Json::Value root;
        root["output"] = Json::Value("");
        //子节点
        Json::Value partner;
        partner["pic_name"] = Json::Value(img_path);
        int n = scanner.scan(image);
        if (image.symbol_begin() == image.symbol_end()) {
//            cout << "pic name:\t" << img_path << endl << "查询条码失败，请检查图片！"
//                 << endl << "==================" << endl;
            partner["code_type"] = Json::Value("Null");
            partner["decode_string"] = Json::Value("Null");
        }

        for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
//            cout << "pic name:\t" << img_path << endl << "code type:\t" << symbol->get_type_name() << endl << \
//                    "decode string:\t" << symbol->get_data() << endl << "==================" << endl;
//            image.set_data(NULL, 0);
            partner["code_type"] = Json::Value(symbol->get_type_name());
            partner["decode_string"] = Json::Value( symbol->get_data());
        }
        root["output"]=Json::Value(partner);
        cout<<sw.write(root);
    }

    waitKey(0);
    return 1;
}
