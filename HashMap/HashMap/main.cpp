//
//  main.cpp
//  HashMap
//
//  Created by Emil Shirima on 10/31/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#include <iostream>
#include "HashMap.hpp"

int main(int argc, const char * argv[]) {

    HashMap hashObject;
//    hashObject.print(); // tests Default Constructor
    
    // Unique Strings
    hashObject.addItem("fOkH6jfoZN");
    hashObject.addItem("S8EjFyubWj");
    hashObject.addItem("stAT08eQyK");
    hashObject.addItem("1D0xj2skAP");
    hashObject.addItem("lBlEwWj90J");
    hashObject.addItem("jfjRUaLevG");
    hashObject.addItem("RABIjOlDRO");
    hashObject.addItem("5R6ypEBm2m");
    hashObject.addItem("Ueq2Y5avyx");
    hashObject.addItem("TRPeJCalia");
    hashObject.addItem("9agFWTM1Db");
    hashObject.addItem("PHQJ5Eszn8");
    hashObject.addItem("mRxqhNSEWy");
    hashObject.addItem("kPtelfJDdi");
    hashObject.addItem("43JN9E6xOI");
    hashObject.addItem("OMHAnj1y12");
    hashObject.addItem("rV8a42NGy4");
    hashObject.addItem("qjJ290kwoT");
    hashObject.addItem("FkjG9VadQW");
    hashObject.addItem("NhQCfqZFPZ");
    
    hashObject.addItem("H6jfoZNfOk");
    hashObject.addItem("H6jfofOkZN");
    hashObject.addItem("fofOkZNH6j");
    hashObject.addItem("fOkZNH6jfo");
    
    hashObject.printFilledAreasOfTheMap();
//    hashObject.printEntireMap();
    
    // Constant time search
    hashObject.search("fOkH6jfoZN");
    
    // Linked List search
    hashObject.search("FkjG9VadQW");
    hashObject.search("hello");
    
    hashObject.remove("hello"); // non-existence-element-with-unique-index removal
//    hashObject.printFilledAreasOfTheMap();
    
    hashObject.remove("H6jfOkfoZN"); // non-existence-element-without-a-unique-index removal
//    hashObject.printFilledAreasOfTheMap();
    
    hashObject.remove("fOkH6jfoZN"); // constant removal
//    hashObject.printFilledAreasOfTheMap();
    
    hashObject.remove("RABIjOlDRO"); // single bucket removal
//    hashObject.printFilledAreasOfTheMap();
    
    hashObject.remove("H6jfoZNfOk"); // remove from head of the bucket
//    hashObject.printFilledAreasOfTheMap();
    
    hashObject.remove("H6jfofOkZN"); // middle of bucket removal
//    hashObject.printFilledAreasOfTheMap();
    
    hashObject.remove("fOkZNH6jfo"); // last element in the bucket removal
    
    hashObject.printFilledAreasOfTheMap();
    
    return 0;
}
