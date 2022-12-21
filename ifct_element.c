//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

//환자 1명에 대한 정보 구조체 만들기  
 typedef struct ifs_ele{  //typedef 썼으니까 인제부터 struct 안써도 된다~ 
 	int index;		//번호(정수) 
	int age;	//나이(정수) 
	int detected_time;	//감염 시점(정수) 
	place_t place[N_HISTORY];	 //감염 직전 이동 경로(place_t 배열, size는N_HISTORY) 
 } ifs_ele_t;
 
 
 void* ifctele_genElement(int index, int age, unsigned int detected_time, int place[N_HISTORY]) //구조체 안에 넣는 함수 
 {   
 	ifs_ele_t* ptr;
    ptr = malloc(sizeof(ptr));
	
 	ptr->index = index;
 	ptr->age = age;
 	ptr->detected_time = detected_time;
 	//for 문돌려서 해야함 : ptr->place[N_HISTORY] = place[N_HISTORY]; //for 문돌려서 해야함 
 	int n=0;
	for(n=0;n<N_HISTORY;n++)
		ptr->place[n] = place[n];
 	return ptr;
 }

int ifctele_getHistPlaceIndex(void* obj, int index)
{
 	ifs_ele_t* ptr = (ifs_ele_t *)obj; 
  
 	return ptr->place[index];
 }

unsigned int ifctele_getinfestedTime(void* obj)
{
 	ifs_ele_t* ptr = (ifs_ele_t *)obj; 
  
 	return ptr->detected_time;
 }
  
//위의 두개도 같은 방식으로 코딩  
 int ifctele_getAge(void* obj)
 {
 	ifs_ele_t* ptr = (ifs_ele_t *)obj; 
  
 	return ptr->age; //나이를 알고자 하는 함수이므로 
 }
  
//return country name pointer from country number
 char* ifctele_getPlaceName (int pIndex) //placeIndex 이건가  
{
	/*
	char ptr*;
	ptr = &placeIndex;
	*/
	return countryName[pIndex];
 } 
 
 void ifctele_printElement(void* obj)
 {
 	ifs_ele_t* strPtr = (ifs_ele_t*)obj;
 	
 	printf("%i\n", obj); 
 	//print element
 }
 
