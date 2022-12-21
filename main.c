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


//int trackInfester(int patient_no, int *detected_time, int *��place); //
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
             
            case MENU_PATIENT: //��ȣ, ����, ���� Ȯ������, �ֱ� 5�� �̵����  
                printf("Patient index :"); //ȯ�ڹ�ȣ �ޱ�  
				scanf("%i", &index);		 //ȯ�ڹ�ȣ �ޱ� 
				//ifctdb_getData(index);
			
				printf("-------------------------------------------------\n");
				printf("Patient index :"); //ȯ�ڹ�ȣ ���
				//ifctdb_getData(index);
				ifctele_printElement(index);
				
				printf("Patient age: "); //ȯ�� ���� ���  
				ifctele_printElement(ifctele_getAge(ifctdb_getData(index))); 
				 
				printf("Detected time: "); //���� Ȯ������ ���  
				ifctele_printElement(ifctele_getinfestedTime(ifctdb_getData(index)));
				
				printf("Path History: "); 
				ifctele_printElement(ifctele_getHistPlaceIndex(ifctdb_getData(index), index);
				//ifctele_printElement(ifctele_getPlaceName(ifctele_getHistPlaceIndex(ifctdb_getData(index), index))); 
			
                break;
                
            case MENU_PLACE: //�ߺ� Ȯ���� �� ȯ�� ���� ���� ��� 
				printf("input place :\n");
				scanf("%s", &pIndex); //��� �Է� �ް�,
	
				ifctele_getPlaceName(pIndex);
				//printf("");//�ߺ� Ȯ���� �� ȯ�� ����� ���� ��� 
				 
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
