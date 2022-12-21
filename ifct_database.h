//
//  ifct_database.h
//  infection Path
//
//  Created by Juyeop Kim on 2022/10/20.
//

#ifndef ifct_database_h
#define ifct_database_h


int ifctdb_addTail(void* obj);          //add data to tail
int ifctdb_deleteData(int index);       //delete data
int ifctdb_len(void);                   //get database length
void* ifctdb_getData(int index);        //get index'th data 창고역할 index에 3넣고 그런식으 

#endif /* ifct_database_h */
