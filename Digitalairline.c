#include <stdio.h>

int main(void)
{
	int i, cost, j, ep_aer, AM57[30][6]={0}, NB3842[22][4]={0}, ep_M, row, col, T_seats_NB, T_seats_AM, diad_th, ak_th, ak_seir;

	T_seats_AM = T_seats_NB = cost = 0;
	// T_seats --> TAKEN SEATS
	
	while(ep_M!=7)
	{
		do
		{
			printf("\n---------------------------------------------------------------------------------------------\n");
		    printf("\nEpilekste aeroskafos: (1.AM57(30 SEIRES/6 KATHISMATA) H 2.NB3842(22 SEIRES/4 KATHISMATA))\n");
		    scanf("%d", &ep_aer);
		    if(ep_aer<1 || ep_aer>2)
		    {
		    	printf("\nError, lathos noumero entolhs. \n");
			}
	    } while(ep_aer<1 || ep_aer>2);
	    
	    do
	    {
	    	printf("\nMenu Selections\n");
	    	printf("\n1.Emfanish eleutherwn thesewn.\n");
	    	printf("\n2.Krathsh tuxaias eleutherhs theshs.\n");
	    	printf("\n3.Krathsh sugkekrimenhs theshs.\n");
	    	printf("\n4.Krathsh pollwn diadoxikwn eleutherwn thesewn (MEXRI 3).\n");
	    	printf("\n5.Akurwsh theshs.\n");
	    	printf("\n6.Emfanish sunolikou posou.\n");
	    	printf("\n7.EXIT.\n\n");
	    	scanf("%d", &ep_M);
	    	if(ep_M<1 || ep_M>7)
	    	{
	    		printf("\nError, lathos noumero entolhs. \\n");
			}
		} while(ep_M<1 || ep_M>7);
		
		switch(ep_M)
		{
			case 1:
			    if(ep_aer==1)
			    {
				    printf("\nEleutheres theseis sto aeroskafos AM57 einai: \n");
				    for(i=0; i<30; i++)
				    {
					    for(j=0; j<6; j++)
					    {
						    if(AM57[i][j]==1)
						    {
							    printf("%2s", "T");     // T einai gia TAKEN seats.
						    }
						    else
						    {
							    printf("%2s", "F");    // F einai gia FREE seats.
						    }
					    }
					    printf("\n");
				    }
			    }
			    else
			    {
				    printf("\nEleutheres theseis sto aeroskafos NB3842 einai: \n");
				    for(i=0; i<22; i++)
				    {
					    for(j=0; j<4; j++)
					    { 
						    if(NB3842[i][j]==1)
						    {
							    printf("%2s", "T");    // T einai gia TAKEN seats.
						    }
						    else
						    {
							    printf("%2s", "F");    // F einai gia FREE seats.
						    }
					    }
					    printf("\n");
				    }
			    }
			break;    
			
			case 2:
				if(ep_aer==1)
				{
					if(T_seats_AM==30*6)
					{
						printf("\n Den uparxoun kenes theseis.\n");
						break;
					}
					else
					{
						row = rand() % 30;     /*Xrhsimopoiw thn rand() gia na epileksw mia tuxaia thesh. */
						col = rand() % 6;
						T_seats_AM++;
						cost=cost+30;
						AM57[row][col]=1;
					}
				}
				else
				{
					if(T_seats_NB==22*4)
					{
						printf("\n Den uparxoun kenes theseis.\n");
						break;
					}		
					else
					{
						row = rand() % 22;      //Xrhsimopoiw thn rand() gia na epileksw mia tuxaia thesh.
						col = rand() % 4;
						T_seats_NB++;
						cost=cost+20;
						NB3842[row][col]=1;
					}			
				}
			break;
			
			case 3:
				if(ep_aer==1)
				{
					do
					{
						printf("\nDwse seira [1-30]: \n");
						scanf("%d", &row);
					} while(row<1 || row>30);
					
					row--;      //Afairw 1, giati h arithmish arxizei apo to 0.
					
					for(i=0; i<6; i++)
					{
						if(AM57[row][i]==0)
						{
							AM57[row][i]=1;
							cost=cost+30;
							T_seats_AM++;
							break;
						}
						else if(AM57[row][0]==1 || AM57[row][1]==1 || AM57[row][2]==1 || AM57[row][3]==1 || AM57[row][4]==1 || AM57[row][5]==1)
						{
							printf("\nAuth h seira einai gemath.\n");
						}
					}
				}
				else
				{
					do
					{
						printf("\nDwse seira [1-22]: \n");
						scanf("%d", &row);
					} while(row<1 || row>22);
					
					row--;    //Afairw 1, giati h arithmish arxizei apo to 0.
					
					for(i=0; i<4; i++)
					{
						if(NB3842[row][i]==0)
						{
							NB3842[row][i]=1;
							cost=cost+20;
							T_seats_NB++;
							break;
						}
						else if(NB3842[row][0]==1 || NB3842[row][1]==1 || NB3842[row][2]==1 || NB3842[row][3]==1)
						{
							printf("\nAuth h seira einai gemath.\n");
						}
					}
				}
			break;
			
			case 4:
				if(ep_aer==1)
				{
					do
					{
						printf("\nPoses diadoxikes theseis theleis?(MEXRI 3) \n");
						scanf("%d", &diad_th);
					} while(diad_th<2 || diad_th>3);
					
					if(diad_th==2)
					{
						for(i=0; i<30; i++)
						{
							if(AM57[i][0]+AM57[i][1]==0)
							{
								AM57[i][0]=1;
								AM57[i][1]=1;
								T_seats_AM=T_seats_AM+2;
								cost=cost+60;
								break;
							}
							else if(AM57[i][1]+AM57[i][2]==0)
							{
								AM57[i][1]=1;
								AM57[i][2]=1;
								T_seats_AM=T_seats_AM+2;
								cost=cost+60;
								break;
							}
							else if(AM57[i][2]+AM57[i][3]==0)
							{
								AM57[i][2]=1;
								AM57[i][3]=1;
								T_seats_AM=T_seats_AM+2;
								cost=cost+60;
								break;
							}
							else if(AM57[i][3]+AM57[i][4]==0)
							{
								AM57[i][3]=1;
								AM57[i][4]=1;
								T_seats_AM=T_seats_AM+2;
								cost=cost+60;
								break;
							}
							else if(AM57[i][4]+AM57[i][5]==0)
							{
								AM57[i][4]=1;
								AM57[i][5]=1;
								T_seats_AM=T_seats_AM+2;
								cost=cost+60;
								break;
							}
							else
							{
								printf("\nAuth h seira einai gemath.\n");
								break;
							}
						}
					}
					else if(diad_th==3)
					{
						for(i=0; i<30; i++)
						{
							if(AM57[i][0]+AM57[i][1]+AM57[i][2]==0)
							{
								AM57[i][0]=1;
								AM57[i][1]=1;
								AM57[i][2]=1;
								T_seats_AM=T_seats_AM+3;
								cost=cost+90;
								break;
							}
							else if(AM57[i][1]+AM57[i][2]+AM57[i][3]==0)
							{
								AM57[i][1]=1;
								AM57[i][2]=1;
								AM57[i][3]=1;
								T_seats_AM=T_seats_AM+3;
								cost=cost+90;
								break;
							}
							else if(AM57[i][2]+AM57[i][3]+AM57[i][4]==0)
							{
								AM57[i][2]=1;
								AM57[i][3]=1;
								AM57[i][4]=1;
								T_seats_AM=T_seats_AM+3;
								cost=cost+90;
								break;
							}
							else if(AM57[i][3]+AM57[i][4]+AM57[i][5]==0)
							{
								AM57[i][3]=1;
								AM57[i][4]=1;
								AM57[i][5]=1;
								T_seats_AM=T_seats_AM+3;
								cost=cost+90;
								break;
							}
							else
							{
								printf("\nAuth h seira einai gemath.\n");
								break;
							}
						}
					}
				}
				else
				{
					do
					{
						printf("\nPoses diadoxikes theseis theleis?(MEXRI 3) \n");
						scanf("%d", &diad_th);
					} while(diad_th<2 || diad_th>3);
					
					if(diad_th==2)
					{
						for(i=0; i<22; i++)
						{
							if(NB3842[i][0]+NB3842[i][1]==0)
							{
								NB3842[i][0]=1;
								NB3842[i][1]=1;
								cost=cost+40;
								T_seats_NB=T_seats_NB+2;
								break;
							}
							else if(NB3842[i][1]+NB3842[i][2]==0)
							{
								NB3842[i][1]=1;
								NB3842[i][2]=1;
								cost=cost+40;
								T_seats_NB=T_seats_NB+2;
								break;
							}
							else if(NB3842[i][2]+NB3842[i][3]==0)
							{
								NB3842[i][2]=1;
								NB3842[i][3]=1;
								cost=cost+40;
								T_seats_NB=T_seats_NB+2;
								break;
							}
							else if(NB3842[i][3]+NB3842[i][4]==0)
							{
								NB3842[i][3]=1;
								NB3842[i][4]=1;
								cost=cost+40;
								T_seats_NB=T_seats_NB+2;
								break;
							}
							else if(NB3842[i][4]+NB3842[i][5]==0)
							{
								NB3842[i][4]=1;
								NB3842[i][5]=1;
								cost=cost+40;
								T_seats_NB=T_seats_NB+2;
								break;
							}
							else
							{
								printf("\nAuth h seira einai gemath.\n");
								break;
							}
						}
					}
					else
					{
						for(i=0; i<22; i++)
						{
							if(NB3842[i][0]+NB3842[i][1]+NB3842[i][2]==0)
							{
								NB3842[i][0]=1;
								NB3842[i][1]=1;
								NB3842[i][2]=1;
								T_seats_NB=T_seats_NB+3;
								cost=cost+60;
								break;
							}
							else if(NB3842[i][1]+NB3842[i][2]+NB3842[i][3]==0)
							{
								NB3842[i][1]=1;
								NB3842[i][2]=1;
								NB3842[i][3]=1;
								cost=cost+60;
								T_seats_NB=T_seats_NB+3;
								break;
							}
							else if(NB3842[i][2]+NB3842[i][3]+NB3842[i][4]==0)
							{
								NB3842[i][2]=1;
								NB3842[i][3]=1;
								NB3842[i][4]=1;
								cost=cost+60;
								T_seats_NB=T_seats_NB+3;
								break;
							}
							else if(NB3842[i][3]+NB3842[i][4]+NB3842[i][5]==0)
							{
								NB3842[i][3]=1;
								NB3842[i][4]=1;
								NB3842[i][5]=1;
								cost=cost+60;
								T_seats_NB=T_seats_NB+3;
								break;
							}
							else
							{
								printf("\nAuth h seira einai gemath.\n");
								break;
							}
						}
					}
				}
			break;
			
			case 5:
				if(ep_aer==1)
				{
					do
					{
						printf("\nDwse seira[1-30] kai thesh[1-6] gia na akurwseis.\n");
						scanf("%d%d", &ak_seir, &ak_th);
					} while((ak_seir<1 || ak_seir>30) && (ak_th<1 || ak_th>6));
					
					ak_seir--;       //Afairw 1, giati h arithmish arxizei apo to 0.
					ak_th--;          //Afairw 1, giati h arithmish arxizei apo to 0.
					
					if(AM57[ak_seir][ak_th]==1)
					{
						AM57[ak_seir][ak_th]=0;
						T_seats_AM=T_seats_AM-1;
						cost=cost+22;
					}
					else
					{
						printf("\nH thesh pou evales einai lathos giati einai hdh kenh.\n");
					}
				}
				else
				{
					do
					{
						printf("\nDwse seira[1-22] kai thesh[1-4] gia na akurwseis.\n");
						scanf("%d%d", &ak_seir, &ak_th);
					} while((ak_seir<1 || ak_seir>22) && (ak_th<1 || ak_th>4));
					
					ak_seir--;       //Afairw 1, giati h arithmish arxizei apo to 0.
					ak_th--;          //Afairw 1, giati h arithmish arxizei apo to 0.
					
					if(NB3842[ak_seir][ak_th]==1)
					{
						NB3842[ak_seir][ak_th]=0;
						T_seats_NB=T_seats_NB-1;
						cost=cost+13;
					}
				}
			break;
			
			case 6:
				printf("\nTo sunoliko poso pou exei uspraxthei einai: %d\n", cost);
			break;	
			
			case 7:
				return 0;
			break;	
        }
    }
}
