#include <bits/stdc++.h>
// #include<conio.h>
#define maximum 100
using namespace std;

int main()
{
    while(1)
    {
        int sw;
        printf("\n\n\t\t\t 1. FOR BIT STUFFING/DE-STUFFING: \n");
        printf("\n\n\t\t\t 2. FOR BYTE STUFFING/DE-DESTUFFING: \n");
        printf("\n\n\t\t\t 3. FOR CYCLIC REDUNDANY CHECK AND PARITY CHECKER:  \n");
        printf("\n\n\t\t\t 4. FOR ERROR DETECTION MECHANISM:  \n");
        printf("\n\n\t\t\t 5. FOR DECIMAL TO BINARY CONVERT:  \n");
        printf("\n\n\t\t\t INPUT SWITCHING VALUE ");

        scanf("%d",&sw);
        /*** switch case ****/
    switch(sw)
    {
        /******bit stuffing *****/
        case 1 :
        {
            /*like input: 00111111101110*/
            char *p,*q;
            char n[maximum];
            char stuff[maximum];
            char destuff[maximum];
            int count=0;
            printf("\n\n\t\t ENTER THE INPUT CHARECTER STRING (0 & 1 ONLY):  ");
            scanf("%s",n);
            p=n;// input data
            q=stuff;
            while(*p!='\0')
            {
                if(*p=='0') /* *p == 0 so that shift next index for find only 1*/
                {
                    *q=*p; /* swap 0 from p to q that means stuffing array */
                    q++;
                    p++;
                }
                else
                {
                    while(*p=='1' && count!=5) /*here find p=1 also check next five index also 1 or not
if found 0 without 5 index then swap to orginal value to staffing */
                    {
                        count++; /* update count for shift next five index is 1 */
                        *q=*p;
                        q++;
                        p++;
                    }

                    if(count==5)/* if found next five index back to back 1
then set Flag 0 after 1 one's */
                    {
                        *q='0'; /* this line only for stuffing not for de stuffing code*/
                        q++;
                    }
                    count=0; /* after set flag 0 then count start from began */
                }
            }
            *q='\0';
            printf("\n\t 01111110 : '%s' : 01111110",stuff);
            printf("\n\n\n\n\n\t\t\t ******De-STUFFING START HERE ****************");
            printf("\n\n\t\t *****DE STUFFING VALUE FORM STUFFED VALUE ***** \n");
            p=stuff; /* inisialization stuff array value */
            q=destuff;
            while(*p!='\0')
            {
                if(*p=='0')
                {
                    *q=*p;
                    q++;
                    p++;
                }
                else
                {
                    while(*p=='1' && count!=5)
                    {
                        count++;
                        *q=*p;
                        q++;
                        p++;
                    }
                    if(count==5)
                    {
                        p++;
                    }
                    count=0;
                }
            }
            *q='\0';
            printf("\n\n\t\t 01111110 : '%s' : 01111110",destuff);

            break;
        };
        /********case 1 end*******/
        case 2 :
        {
            char data[maximum],stuff[maximum],destuff[maximum];
            int i,j,cnt=1,c,flug,dsize,frames,denter,n;
            printf("\n\n\t\t ENTER STRING DATA: ");
            scanf("%s",data);
            dsize = strlen(data);
            printf("\n\n\t\t ENTER FRAME SIZE: ");
            scanf("%d",&flug);

            denter= flug-2;
            frames = (dsize/denter)+1;
            n= dsize+(frames*2);
            n=dsize+(frames*2); /* each freame containes 2 flug bits */
            j=0;
            for(i=0; i<n; i++)
            {
                if(i%flug==0)
                {
                    stuff[i]='D';  /*opening flag set*/
                }
                else if(i==(flug*cnt)-1)
                {
                    stuff[i]='D';/*ESC flag set*/
                    cnt++;
                }
                else
                {
                    if(data[j]=='\0')
                    {
                        c=1;
                        break;
                    }
                    stuff[i]=data[j];
                    j++;
                }
            }
            if(c==1)
            {
                stuff[n-1]='D'; /*closing flag set*/
            }
            stuff[n]='\0';
            printf("\n\n\t\t AFTER STUFFING DATA IS: %s \n",stuff);
            /*Destuffing start here  */

            j=0;
            for(i=0; i<n; i++)
            {
                if(stuff[i]!='D')
                {
                    destuff[j]=stuff[i];
                    j++;
                }
            }
            destuff[j]='\0';
            printf("\n\n\t\t AFTER DE-STUFFING: %s",destuff);

            break;
        };


        /********case 2 end +***************/



        case 3 :
        {
            int i,j,Divident_Len,msg_Len,fg=0;
            char n[maximum],Divident[maximum],temp[maximum];
            char quot[maximum],rem[maximum],copyof_key[maximum];

            printf("\n\n\t\t INPUT YOUR MESSAGE: ");
            scanf("%s",n);

            printf("\n\n\t\t ENTER KEY MESSAGE FOR DIVISOR: ");
            scanf("%s",Divident);

            Divident_Len = strlen(Divident);
            msg_Len=strlen(n);
            strcpy(copyof_key,Divident);

            for(i=0; i<Divident_Len-1; i++)
            {
                n[msg_Len+i]='0';
            }
            for(i=0; i<msg_Len; i++)
            {

                temp[i] = n[i];
            }

            for(i=0; i<msg_Len; i++)
            {
                quot[i]=temp[0];
                if(quot[i]=='0')
                {
                    for(j=0; j<Divident_Len; j++)
                    {
                        Divident[j]='0';
                    }
                }
                else
                {
                    for(j=0; j<Divident_Len; j++)
                    {
                        Divident[j]=copyof_key[j];
                    }
                }
                for(j=Divident_Len-1; j>0; j--)
                {
                    if(temp[j]==Divident[j])
                    {
                        rem[j-1]='0';
                    }
                    else
                        rem[j-1]='1';
                }
                rem[Divident_Len-1]=n[i+Divident_Len];
                strcpy(temp,rem);
            }
            strcpy(rem,temp);
            printf("\n\n\t\t QUOTIENT IS: ");
            for(i=0; i<msg_Len; i++)
            {
                printf("%c",quot[i]);
            }
            printf("\n\n\t\t REMAINDER IS: ");
            for(i=0; i<Divident_Len-1; i++)
            {
                printf("%c",rem[i]);
            }
            printf("\n\n\t\t CODEWORD DATA WITH REDUNDENCY IS: ");
            for(i=0; i<msg_Len; i++)
            {
                printf("%c",n[i]);
            }
            for(i=0; i<Divident_Len-1; i++)
            {
                printf("%c",rem[i]);
            }

            printf("\n\n\t\t***** REMOVE  REDUNDENCY DATA ********\n");

            char temp1[20];
            printf("\n\n\t\t PLEASE INPUT CODEWORD DATA WITHOUT CHANGE FOR BACK ORGINAL DATA: ");
            scanf("%s",temp1);

            for(i=0; i<Divident_Len; i++)
            {
                temp[i]=temp1[i];
            }
            for(i=0; i<msg_Len; i++)
            {
                quot[i]=temp[0];
                if(quot[i]=='0')
                {
                    for(j=0; j<Divident_Len; j++)
                    {
                        Divident[j]='0';
                    }
                }
                else
                {
                    for(j=0; j<Divident_Len; j++)
                    {
                        Divident[j]=copyof_key[j];
                    }
                }

                for(j=Divident_Len-1; j>0; j--)
                {
                    if(temp[j]==Divident[j])
                    {
                        rem[j-1]='0';
                    }
                    else
                    {
                        rem[j-1]='1';
                    }
                }
                rem[Divident_Len-1]=temp1[i+Divident_Len];
                strcpy(temp,rem);
            }

            strcpy(rem,temp);
            printf("\n\n\t\t QUOTIENT IS: ");
            for(i=0; i<msg_Len; i++)
            {
                printf("%c",quot[i]);
            }
            printf("\n\n\t\t REMAINDER IS: ");
            for(i=0; i<Divident_Len-1; i++)
            {
                printf("%c",rem[i]);
            }
            fg=0;
            for(i=0; i<Divident_Len-1; i++)
            {
                if(rem[i]=='1')
                {
                    fg=1;
                }
                else
                    fg=0;
            }
            if(fg==0)
            {
                printf("\n\n\t\t NO ERORR. WE BACK ORIGINAL DATA FROM CODEWORD.  \n\n\n");
            }
            else
            {
                printf("\n\n\t\t \a FOUND ERROR IN MESSAGE.\n\n\n");
            }



            break;
        };
        /*********** case 3 end *****************/
        case 4 :
        {
            /*input: 1 1 1 0
            1st output: 0 R=0 1 0 1 10 now change R
            2nd output: Error Found.... BETTER LUCK FOR NEXT TIME...
                                    0  0 1  0 1 1  0*/
            int data[maximum],Parity[maximum],c1,c2,c3;
            cout<< "ENTER THE 4 BITS: "<<endl;

            scanf("%d",&data[3]);
            scanf("%d",&data[5]);
            scanf("%d",&data[6]);
            scanf("%d",&data[7]);

            data[1] =data[3]^data[5]^data[7];
            data[2] =data[3]^data[6]^data[7];
            data[4] =data[5]^data[6]^data[7];
            for(int i =1; i<8; i++)
            {

                printf("\t\t %d ",data[i]);/*Seven bits: */
            }

            printf(" \n\n\t\t ENTER 7 BITS: ");

            for(int i =1; i<8; i++)
            {
                scanf("%d",&Parity[i]);
            }
            c1= Parity[1]^Parity[3]^Parity[5]^Parity[7];
            c2= Parity[2]^Parity[3]^Parity[6]^Parity[7];
            c3= Parity[4]^Parity[5]^Parity[6]^Parity[7];

            int p=c1*1+c2*2 +c3*4; /* too decimal*/
            if(p==0)
            {

                printf("\n\n\t\t THERE IS NO ERROR. GOOD LUCK! \n");
            }
            else
            {
                printf("\n\n\t\t ERROR FOUND.... BETTER LUCK FOR NEXT TIME... \a ");
                if(Parity[p]==0)
                    Parity[p]=1;
                else
                {
                    Parity[p]=0;
                }
                for(int i=1; i<8; i++)
                {
                    printf("\t %d ",Parity[i]);
                }
            }


            break;
        };
        /*********case 4 end*********/
        case 5 :
        {

            printf("\n\n\t\t INPUT DECIMAL TO CHECK BINARY:  ");
            int n;
            scanf("%d",&n);
            int binaryNum[32];
            int i = 0;
            while (n > 0)
            {
                binaryNum[i] = n % 2;
                n = n / 2;
                i++;
            }
            cout <<"\n\n \t\t BINARY: ";
            for (int j = i - 1; j >= 0; j--)
                cout <<binaryNum[j]<<" ";
            cout<<endl<<endl;
            break;
        };
            /*********case 5 end*********/

    }
  }
}