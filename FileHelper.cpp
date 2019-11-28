// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu
//
//
// FileHelper.cpp
// This is cpp file for FileHelper class
// */
// #include<iostream>
// #include<fstream>
// #include <cereal/types/unordered_map.hpp>
// #include <cereal/types/memory.hpp>
// #include <cereal/archives/binary.hpp>
//
// #include "FileHelper.h"
//
//
// using namespace std;
//
// FileHelper::FileHelper(string fileName)
// {
//   inputFile = fileName;
// }
//
//
//
// FileHelper::~FileHelper()
// {
//
// }
//
//
// void readStudentBST()
// {
//    ofstream wf("studentTree.dat", ios::out | ios::binary);
//    if(!wf)
//    {
//       cout << "Cannot open file!" << endl;
//       return 1;
//    }
//
//    if(!wf.good()) {
//       cout << "Error occurred at writing time!" << endl;
//       return 1;
//    }
//
//    ifstream rf("studentTree.dat", ios::out | ios::binary);
//    if(!rf) {
//       cout << "Cannot open file!" << endl;
//       return 1;
//    }
// }
//
//    rf.close();
//   template <class Archive>
//      void serialize( Archive & ar )
//      {
//        ar( x, y, z );
//      }
//    return 0;
