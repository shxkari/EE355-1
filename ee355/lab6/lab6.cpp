/* IMPORTANT NOTES:
 * This is just a sample code.
 * You may/should change/delete many parts of this file.
 * You can just get some hints on how to start your code here.
 * DO NOT consider this file as a template. 
 */


#include <iostream>
#include <limits>
#include <dirent.h>
#include <stdlib.h>
#include <fstream>

#include "bmplib.h"
#define PATH_IN "/home/student/ee355/lab6/Pictures/Before/"
#define PATH_OUT "/home/student/ee355/lab6/Pictures/After/"
using namespace std;

void showMainMenu(){
    cout << "0: Exit \n";
    cout << "1: Flip \n";
    cout << "2: Mirror \n";
    cout << "3: GreyScaling \n";
    cout << "4: Color Inversion \n";
    cout << "5: Zoom In \n";
    cout << "6: Copy \n";
    cout << "7: WaterMark \n";
}


void copy(string filename, unsigned char dest[SIZE][SIZE][3]){

    unsigned char src[SIZE][SIZE][3];
    readRGBBMP(filename.c_str(), src);

    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            for (int k=0; k<3; k++){
                dest[i][j][k] = src[i][j][k];
            }
        }
    }
}

int main(){
    const int SIZE = 256;
    int option, flip_option;
    unsigned char res [SIZE][SIZE][3];
    unsigned char in[SIZE][SIZE][3];
    unsigned char out[SIZE][SIZE][3];
    unsigned char temp[SIZE][SIZE][3];
    unsigned char dest[SIZE][SIZE];



    while(1){

        DIR *read_dir, *write_dir;
        struct dirent *ent;
        string extension = "bmp";
        string fname_new;
        cout << "\033[2J\033[1;1H";
        showMainMenu();
        cout << "Select an option: ";
        cin >> option;
        switch(option){
            case 0:
                cout << "EXIT \n";;
                return 0;

            case 1: 
                cout << "FLIP \n Select an option\n";
                cout << "1. 90 degrees clockwise\n";
                cout << "2. 180 degrees (upside down) \n";
                cin >> flip_option;

                if(flip_option == 1){
                    cout << "Image was rotated 90degrees clockwise\n";
                    if ((read_dir = opendir(PATH_IN)) != NULL) {
                        while ((ent = readdir(read_dir)) != NULL) {
                            string fname = ent->d_name;
                            cout << fname <<endl;
                            string extensionchk = fname.substr(fname.find('.')+1);
                            if (extensionchk == extension){
                                fname_new = PATH_IN + fname;
                                readRGBBMP(fname_new.c_str(), in);
                                for(int i = 0; i < SIZE; i++){
                                    for(int j=0; j<SIZE; j++){
                                        for(int k=0; k<3; k++)
                                            out[i][j][k] = in[SIZE-1-j][i][k];
                                    }
                                }
                                showRGBBMP(out);
                                fname = "flip90_" + fname;
                                fname = PATH_OUT + fname;
                                writeRGBBMP(fname.c_str(), out);
                            }

                        }
                            closedir (read_dir);
                    } 
                    else
                        perror ("No directory!");

                }
                else if(flip_option == 2){
                    cout << "Image was rotated 180 degrees\n";
                    if ((read_dir = opendir(PATH_IN)) != NULL) {
                        while ((ent = readdir(read_dir)) != NULL) {
                            string fname = ent->d_name;
                            cout << fname <<endl;
                            string extensionchk = fname.substr(fname.find('.')+1);
                            if (extensionchk == extension){
                                fname_new = PATH_IN + fname;
                                readRGBBMP(fname_new.c_str(), in);
                                for(int i = 0; i < SIZE; i++){
                                    for(int j=0; j<SIZE; j++){
                                        for(int k=0; k<3; k++)
                                            temp[i][j][k] = in[SIZE-1-j][i][k];
                                    }
                                }
                                for(int i = 0; i < SIZE; i++){
                                    for(int j=0; j<SIZE; j++){
                                        for(int k=0; k<3; k++)
                                            out[i][j][k] = temp[SIZE-1-j][i][k];
                                    }
                                }
                                showRGBBMP(out);
                                fname = "flip180_" + fname;
                                fname = PATH_OUT + fname;
                                writeRGBBMP(fname.c_str(), out);
                            }

                        }
                            closedir (read_dir);
                    } 
                    else
                        perror ("No directory!");
                }
                else{
                    cout << "incorrect option";
                }

                break;

            case 2: 
                cout << "MIRROR \n";
                if ((read_dir = opendir(PATH_IN)) != NULL) {
                        while ((ent = readdir(read_dir)) != NULL) {
                            string fname = ent->d_name;
                            cout << fname <<endl;
                            string extensionchk = fname.substr(fname.find('.')+1);
                            if (extensionchk == extension){
                                fname_new = PATH_IN + fname;
                                readRGBBMP(fname_new.c_str(), in);
                                for(int i= 0; i < SIZE; i++){
                                    for(int j = 0; j < SIZE/2; j++){
                                        for(int k = 0; k < 3; k++){
                                            swap(in[i][j][k], in[i][SIZE-1-j][k]);
                                        }
                                    }
                                }
                                showRGBBMP(in);
                                fname = "mirror_" + fname;
                                fname = PATH_OUT + fname;
                                writeRGBBMP(fname.c_str(), in);
                            }

                        }
                            closedir (read_dir);
                    } 
                    else
                        perror ("No directory!");
                break;

            case 3:
                cout << "GreyScaling \n";
                if ((read_dir = opendir(PATH_IN)) != NULL) {
                        while ((ent = readdir(read_dir)) != NULL) {
                            string fname = ent->d_name;
                            cout << fname <<endl;
                            string extensionchk = fname.substr(fname.find('.')+1);
                            if (extensionchk == extension){
                                fname_new = PATH_IN + fname;
                                readRGBBMP(fname_new.c_str(), in);
                                for (int i=0; i<SIZE; i++) {
                                    for (int j=0; j<SIZE; j++) {
                                      unsigned char r = in[i][j][0];
                                      unsigned char g = in[i][j][1];
                                      unsigned char b = in[i][j][2];
                                      dest[i][j] = (unsigned char)(.299*r + .587*g + .114*b);
                                   }
                                }
                                showGSBMP(dest);
                                fname = "GreyScale_" + fname;
                                fname = PATH_OUT + fname;
                                writeGSBMP(fname.c_str(), dest);
                            }

                        }
                            closedir (read_dir);
                    } 
                    else
                        perror ("No directory!");
            
                break;

            case 4:
                cout << "Color Inversion\n";
                if ((read_dir = opendir(PATH_IN)) != NULL) {
                        while ((ent = readdir(read_dir)) != NULL) {
                            string fname = ent->d_name;
                            cout << fname <<endl;
                            string extensionchk = fname.substr(fname.find('.')+1);
                            if (extensionchk == extension){
                                fname_new = PATH_IN + fname;
                                readRGBBMP(fname_new.c_str(), in);
                                for (int i=0; i<SIZE; i++) {
                                   for (int j=0; j<SIZE; j++) {
                                      for (int c=0; c<3; c++) {
                                         out[i][j][c] = 255-in[i][j][c];
                                      }
                                   }
                                }
                                showRGBBMP(out);
                                fname = "inversion_" + fname;
                                fname = PATH_OUT + fname;
                                writeRGBBMP(fname.c_str(), out);
                            }

                        }
                            closedir (read_dir);
                    } 
                    else
                        perror ("No directory!");
                break;

            case 5:
                cout << "ZOOM\n";
                if ((read_dir = opendir(PATH_IN)) != NULL) {
                        while ((ent = readdir(read_dir)) != NULL) {
                            string fname = ent->d_name;
                            cout << fname <<endl;
                            string extensionchk = fname.substr(fname.find('.')+1);
                            if (extensionchk == extension){
                                fname_new = PATH_IN + fname;
                                readRGBBMP(fname_new.c_str(), in);
                                for(int i=0; i < SIZE; i++){
                                    for(int j=0; j < SIZE; j++){
                                        for(int k=0; k < 3; k++)
                                            out[i][j][k] = in[SIZE/4 + i/2][SIZE/4 + j/2][k];
                                    }
                                }
                                showRGBBMP(out);
                                fname = "zoom_" + fname;
                                fname = PATH_OUT + fname;
                                writeRGBBMP(fname.c_str(), out);
                            }

                        }
                            closedir (read_dir);
                    } 
                    else
                        perror ("No directory!");
                break;

            case 6:
                cout << "COPY \n";
                if ((read_dir = opendir(PATH_IN)) != NULL) {
                        while ((ent = readdir(read_dir)) != NULL) {
                            string fname = ent->d_name;
                            cout << fname <<endl;
                            string extensionchk = fname.substr(fname.find('.')+1);
                            if (extensionchk == extension){
                                fname_new = PATH_IN + fname;
                                copy(fname_new.c_str(), in);
                                fname = "copy_" + fname;
                                fname = PATH_OUT + fname;
                                writeRGBBMP(fname.c_str(), in);
                            }

                        }
                            closedir (read_dir);
                    } 
                    else
                        perror ("No directory!");
                break;
            case 7:

                cout << "WATERMARK \n";
                break;

            default:
                cout << "OPTION NOT FOUND! \n";
                break;
        }
    }

    return 0;
}