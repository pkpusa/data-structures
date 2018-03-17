#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
 
void computeLPSArray(char *pat, int M, int *lps);
 
// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            printf("\n\n\t\t\tFound - ( %s ) - pattern at index %d ",pat, (i-j));
            j = lps[j-1];  
            
          
        }
        
        
        
		else if (i < N && pat[j] != txt[i])
        {
            
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
        
        
        
    }
	if(j != M)
        {
        	printf("\n\n\t\t\t\t********\tThere is no More Match for the Given String\t*********");
        	//break;
		}
    
}

 

void computeLPSArray(char *pat, int M, int *lps)
{
    
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
void layout()
{
	printf("\n\t\t9th Data Structure Lab");
	printf("\n\t\t____________________________________________________________________________\n");
	printf("\t\t\t\tKMP PATTERN MATCHING PROGRAM\n");
	printf("\t\t_______________________________________________________________________________");
}

/* -------------------------------------  Main Function Starts Here -------------------------------------------------------------------------------*/


int main()
{
    char txt[100];
    char pat[50];
    char option;
    int choice;
    
    
    do{
    	system("cls");
    	layout();
	
    	printf("\n\nEnter any  text or sentence :\n\t");
    	fflush(stdin);
    	gets(txt); 
    	
    	do{
	
			printf("\n\nEnter the pattern You Wnat to search in the String : \t");
			//getchar();
			fflush(stdin);
    		gets(pat);
    		KMPSearch(pat, txt);
    
    
    		printf("\n\nDO you want to search more in same String Press 1 for Yes Otherwise Press 0 :\t");
    		scanf("%d",&choice);
			}while(choice == 1);
    		/*if(choice == 1)
    		{
    		goto a;
			}*/
    
    		printf("\n\n\nDo you want to Check Pattern with new Sring again\nPress Y or y for Continue..\n\tEnter your option here :\t ");
    		getchar();
    		scanf("%c",&option);
    		//getchar();
    }while(option == 'y' || option == 'Y');
    return 0;
}



