//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


//int trackInfester(int patient_no, int *detected_time, int *기place); //
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pIndex;
	int age, time;
    int placeHist[N_HISTORY];
    int index;
    
    int i1;
    int i2;
	 
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc == NULL)
    
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen("patientInfo_sample.txt","r");

    if (fp == NULL)
	{
    	printf("[ERROR] Failed to open database file!! (%s)\n", "patientInfo_sample.txt");
    	return -1;
   	}
    

	while ( 3 == fscanf(fp,"%i %i %i", &index, &age, &time))
    {
    	int i;
    	for (i=0;i<5;i++)
			fscanf(fp, "%i", &placeHist[i]) ;
			
		ifct_element = ifctele_genElement(index, age, time, placeHist); // struct made 
		ifctdb_addTail(ifct_element); 
		//-------------do not change 
	
	}
	
    //1-3. FILE pointer close
    fclose(fp);

    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT(1)
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
		
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
             
            case MENU_PATIENT: //번호, 나이, 감염 확인일자, 최근 5개 이동경로  
                printf("Patient index :"); //환자번호 받기  
				scanf("%i", &index);		 //환자번호 받기 
				//ifctdb_getData(index);
			
				printf("-------------------------------------------------\n");
				printf("Patient index :"); //환자번호 출력
				//ifctdb_getData(index);
				ifctele_printElement(index);
				
				printf("Patient age: "); //환자 나이 출력  
				ifctele_printElement(ifctele_getAge(ifctdb_getData(index))); 
				 
				printf("Detected time: "); //감염 확인일자 출력  
				ifctele_printElement(ifctele_getinfestedTime(ifctdb_getData(index)));
				
				printf("Path History: "); 
				ifctele_printElement(ifctele_getHistPlaceIndex(ifctdb_getData(index), index);
				//ifctele_printElement(ifctele_getPlaceName(ifctele_getHistPlaceIndex(ifctdb_getData(index), index))); 
			
                break;
                
            case MENU_PLACE: //발병 확인이 된 환자 관련 정보 출력 
				printf("input place :\n");
				scanf("%s", &pIndex); //장소 입력 받고,
	
				ifctele_getPlaceName(pIndex);
				//printf("");//발병 확인이 된 환자 모두의 정보 출력 
				 
                //printf("age: %i\n", ifctele_getAge(ifct_element));
                //break;
                
            case MENU_AGE: 

            	printf("minimal age: ");
            	scanf("%i", &i1);
            	printf("maximal age: ");
            	scanf("%i", &i2);
            	
            	//if()
                printf("age: %i\n", ifctele_getAge(age));
                break;
                
            case MENU_TRACK:
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0; 
}
