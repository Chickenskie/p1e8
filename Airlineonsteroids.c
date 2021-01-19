#include <stdio.h>

int main(void)
{
	int cost_AM, cost_NB, i, j, AM[30][6]={0}, NB[22][4]={0}, row, col, T_seats_AM, T_seats_NB; 
	char name_AM[180][20], name_NB[88][20], keno[1][20];
	int pin_AM[180][4], pin_NB[88][4], pin_am[30][6], pin_nb[22][4], empty[1], th, pin_nb_count;
	int ep_aer, ep_Menu, ak_th, ak_seir, diad_th, seira, kwdikos_pin, nAM, nNB, pin_am_count, nep; //nep --> Noumero epivati.
	
	nAM = nNB = 0;
	
	nep = 0;
	
	pin_am_count = pin_nb_count = 0;
	                    						
	T_seats_AM = T_seats_NB =0;
	// T_seats ---> TAKEN SEATS.
	
	cost_AM = cost_NB = 0;
	//Kerdos ana aeroplano.
	
	while(ep_Menu!=8)
	{
	    do
	    {
		    printf("--------------------------------------------------------------------------------------------------------------\n");
		    printf("\nEpilekste aeroskafos: (1.AM57(30 SEIRES/6 KATHISMATA) H 2.NB3842(22 SEIRES/4 KATHISMATA))\n\n");
		    scanf("%d", &ep_aer);
		    if(ep_aer<1 || ep_aer>2)
	        {
			    printf("\nError, lathos noumero entolhs.\n");
		    }
	    } while(ep_aer<1 || ep_aer>2);
	    
	    do
	    {
	    	printf("\nMenu Selections.\n");
	    	printf("1.Emfanish eleutherwn thesewn.\n");
	    	printf("2.Krathsh tuxaias eleutherhs theshs.\n");
	    	printf("3.Krathsh sugkekrimenhs theshs.\n");
	    	printf("4.Krathsh pollwn diadoxikwn eleutherwn thesewn (MEXRI 3).\n");
	    	printf("5.Akurwsh theshs.\n");
	    	printf("6.Emfanish sunolikou posou aeroplanou.\n");
	    	printf("7.Emfanish onomatos mias theshs.\n");
	    	printf("8.EXIT.\n\n");
	    	scanf("%d", &ep_Menu);
	    	if(ep_Menu<1 || ep_Menu>8)
	    	{
	    		printf("\nError, lathos noumero entolhs. \n");
			}
		} while(ep_Menu<1 || ep_Menu>8);
		
		switch(ep_Menu)
		{
			case 1:
				if(ep_aer==1)
				{
					printf("\nEleutheres theseis sto aeroskafos AM57 einai: \n");
					for(i=0; i<30; i++)
					{
						for(j=0; j<6; j++)
						{
							if(AM[i][j]==0)
							{
								printf("O");    // O shmainei oti h thesh einai eleutherh.
							}
							if(AM[i][j]==1)
							{
								printf("X");    // X shmainei oti h thesh den einai eleutherh.
							}
							if(j/2==1 && j<3)
							{
								printf("   ");
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
							if(NB[i][j]==0)
							{
								printf("O");   // O shmainei oti h thesh einai eleutherh.
							}
							if(NB[i][j]==1)
							{
								printf("X");    // X shmainei oti h thesh den einai eleutherh.
							}
							if(j/1==1 && j<2)
							{
								printf("   ");
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
						row = rand() % 30;    /*Xrhsimopoiw thn rand() gia na epileksw mia tuxaia thesh. */
						col = rand() % 6;
						T_seats_AM++;
						printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
						cost_AM=cost_AM+30;
						AM[row][col]=1;
						printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
						scanf("%s", &name_AM[nAM]);
						nAM++;
						printf("\nDwse PIN (XXXX).\n");
						scanf("%d", &pin_AM[pin_am_count][0]);
						pin_am[row][col]=pin_AM[pin_am_count][0];
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
						row = rand() % 22;     /*Xrhsimopoiw thn rand() gia na epileksw mia tuxaia thesh. */
						col = rand() % 4;
						T_seats_NB++;
						printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_NB);
						cost_NB=cost_NB+20;
						NB[row][col]=1;		
						printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");					
						scanf("%s", &name_NB[nNB]);
						nNB++;
						printf("\nDwse PIN (XXXX).\n");
						scanf("%d", &pin_NB[pin_nb_count][0]);
						pin_nb[row][col]=pin_NB[pin_nb_count][0];
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
						if(row<1 || row>30)
						printf("\nError: EDOSES LATHOS NOUMERO.\n");
					} while(row<1 || row>30);
					
					row--;    //Afairw 1, giati h arithmish arxizei apo to 0.
					
					for(i=0; i<6; i++)
					{
						col = rand() % 6;
						if(AM[row][col]==0)
						{
							AM[row][col]=1;
							T_seats_AM++;
							printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
							cost_AM=cost_AM+30;
							printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
							scanf("%s", &name_AM[nAM]);
							nAM++;
							printf("\nDwse PIN (XXXX).\n");
							scanf("%d", &pin_AM[pin_am_count][0]);
							pin_am[row][col]=pin_AM[pin_am_count][0];
							break;
						}
						else if(AM[row][0]==1 && AM[row][1]==1 && AM[row][2]==1 && AM[row][3]==1 && AM[row][4]==1 && AM[row][5]==1)
						{
							printf("\nAuth h seira einai gemath.\n");
							break;
						}
					}
				}
				else
				{
					do
					{
						printf("\nDwse seira [1-22]: \n");
						scanf("%d", &row);
						if(row<1 || row>22)
						printf("\nError: EDOSES LATHOS NOUMERO.\n");
					} while(row<1 || row>22);
					
					row--;      //Afairw 1, giati h arithmish arxizei apo to 0.
					
					for(i=0; i<4; i++)
					{
						col = rand() % 4;
						if(NB[row][col]==0)
						{
							NB[row][col]=1;
							cost_NB=cost_NB+20;
							T_seats_NB++;
							printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_NB);
							printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
							scanf("%s", &name_NB[nNB]);
							nNB++;
							printf("\nDwse PIN (XXXX).\n");
							scanf("%d", &pin_NB[pin_nb_count][0]);
							pin_nb[row][col]=pin_NB[pin_nb_count][0];
							break;
						}
						else if(NB[row][0]==1 && NB[row][1]==1 && NB[row][2]==1 && NB[row][3]==1)
						{
							printf("\nAuth h seira einai gemath.\n");
							break;
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
							if(AM[i][0]+AM[i][1]==0)
							{
								AM[i][0]=1;
								AM[i][1]=1;
								cost_AM=cost_AM+60;
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][0]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][1]=pin_AM[pin_am_count][0];
								break;
							}
							else if(AM[i][1]+AM[i][2]==0)
							{
								AM[i][1]=1;
								AM[i][2]=1;
								cost_AM=cost_AM+60;
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][1]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][2]=pin_AM[pin_am_count][0];
								break;
							}
							else if(AM[i][3]+AM[i][4]==0)
							{
								AM[i][3]=1;
								AM[i][4]=1;
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								cost_AM=cost_AM+60;
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][3]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][4]=pin_AM[pin_am_count][0];
								break;
							}
							else if(AM[i][4]+AM[i][5]==0)
							{
								AM[i][4]=1;
								AM[i][5]=1;
								cost_AM=cost_AM+60;
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][4]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][5]=pin_AM[pin_am_count][0];
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
							if(AM[i][0]+AM[i][1]+AM[i][2]==0)
							{
								AM[i][0]=1;
								AM[i][1]=1;
								AM[i][2]=1;
								cost_AM=cost_AM+90;
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][0]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][1]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][2]=pin_AM[pin_am_count][0];
								break;
							}
							else if(AM[i][3]+AM[i][4]+AM[i][5]==0)
							{
								AM[i][3]=1;
								AM[i][4]=1;
								AM[i][5]=1;
								cost_AM=cost_AM+90;
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][3]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][4]=pin_AM[pin_am_count][0];
								T_seats_AM++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_AM);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_AM[nAM]);
								nAM++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_AM[pin_am_count][0]);
								pin_am[i][5]=pin_AM[pin_am_count][0];
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
						printf("\nMporeis na pareis mono 2 diadoxikes theseis.\n");
						printf("Theleis na pareis ? (1.NAI / 2.OXI)");
						scanf("%d", &diad_th);
					} while(diad_th<1 || diad_th>2);
					
					if(diad_th==1)
					{
						for(i=0; i<22; i++)
						{
							if(NB[i][0]+NB[i][1]==0)
							{
								NB[i][0]=1;
								NB[i][1]=1;
								cost_NB=cost_NB+40;
								T_seats_NB++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_NB);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_NB[nNB]);
								nNB++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_NB[pin_nb_count][0]);
								pin_nb[i][0]=pin_NB[pin_nb_count][0];
								T_seats_NB++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_NB);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_NB[nNB]);
								nNB++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_NB[pin_nb_count][0]);
								pin_nb[i][1]=pin_NB[pin_nb_count][0];
								break;
							}
							else if(NB[i][2]+NB[i][3]==0)
							{
								NB[i][2]=1;
								NB[i][3]=1;
								cost_NB=cost_NB+40;
								T_seats_NB++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_NB);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_NB[nNB]);
								nNB++;
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_NB[pin_nb_count][0]);
								pin_nb[i][2]=pin_NB[pin_nb_count][0];
								T_seats_NB++;
								printf("\nEsu eisai o epeivatis noumero: %d\n", T_seats_NB);
								printf("\nDwse onoma. (MEXRI 20 XARAKTHRES)\n");
								scanf("%s", &name_NB[nNB]);
								nNB++;	
								printf("\nDwse PIN (XXXX).\n");
								scanf("%d", &pin_NB[pin_nb_count][0]);
								pin_nb[i][3]=pin_NB[pin_nb_count][0];													
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
					
					if(AM[ak_seir][ak_th]==1)
					{
						printf("\nDwse kwdiko PIN (XXXX) gia na mporeseis na kaneis akurwsh.\n");
						scanf("%d", &kwdikos_pin);
						printf("\nPoio noumero epivati einai.\n");
						scanf("%d", &nep);
						nep--;
						if(kwdikos_pin==pin_am[ak_seir][ak_th])
						{
							AM[ak_seir][ak_th]=0;
							T_seats_AM--;
							cost_AM=cost_AM+22;
							name_AM[nep][0]=keno[0];
							pin_am[ak_seir][ak_th]=empty[0];
						}
						else
						{
							printf("\nEdwses lathos PIN (XXXX).\n");
						}
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
					
					if(NB[ak_seir][ak_th]==1)
					{
						printf("\nDwse kwdiko PIN (XXXX) gia na mporeseis na kaneis akurwsh.\n");
						scanf("%d", &kwdikos_pin);
						printf("\nPoio noumero epivati einai.\n");
						scanf("%d", &nep);
						nep--;
						if(kwdikos_pin==pin_nb[ak_seir][ak_th])
						{
							NB[ak_seir][ak_th]=0;
							cost_NB=cost_NB+13;
							T_seats_NB--;
							name_NB[nep][0]=keno[0];
							pin_nb[ak_seir][ak_th]=empty[0];
						}
					}
					else
					{
						printf("\nH thesh pou evales einai lathos giati einai hdh kenh.\n");
					}
				}
			break;
			
			case 6:
				if(ep_aer==1)
				{
					printf("\nTo sunoliko poso pou exei eispraxthei gia to aeroplano AM57 einai: %d\n", cost_AM);
				}
				else
				{
					printf("\nTo sunoliko poso pou exei eispraxthei gia to aeroplano NB3842 einai: %d\n", cost_NB);
				}
			break;
			
			case 7:
				if(ep_aer==1)
				{
					if(T_seats_AM==0)
					{
						printf("\nDen uparxoun epivates.\n");
						break;
					}
					else
					{					
						do
						{
							printf("\nDwse seira [1-30].\n");
							scanf("%d", &seira);
							if(seira<1 || seira>30)
							{
								printf("\nLathos ksanaprospatheise.\n");
							}
						} while(seira<1 || seira>30);
						
						seira--;      //Afairw 1, giati h arithmish arxizei apo to 0.
						
						do
						{
							printf("\nDwse thesh [1-6].\n");
							scanf("%d", &th);
							if(th<1 || th>6)
							{
								printf("\nLathos ksanaprospatheise.\n");
							}
						} while(th<1 || th>6);
						
						th--;       //Afairw 1, giati h arithmish arxizei apo to 0.
						
						do
						{
							printf("\nPoio noumero epivati einai.\n");
							scanf("%d", &nep);
							if(nep<0 || nep>T_seats_NB)
							{
								printf("\nLathos ksanaprospatheise.\n");
							}
						} while(nep<0 || nep>T_seats_NB);
						
						nep--;       //Afairw 1, giati h arithmish arxizei apo to 0.
						
						if(AM[seira][th]==0)
						{
							printf("\nAuth h thesh einai kenh.\n");
							break;
						}
						else
						{
							printf("\nSe auth th thesh einai o/h %s . \n", name_AM[nep]);
							break;
						}
					}
				}
				else
				{
					if(T_seats_NB==0)
					{
						printf("\nDen uparxoun epivates.\n");
						break;
					}
					else
					{
						do
						{
							printf("\nDwse seira [1-22].\n");
							scanf("%d", &seira);
							if(seira<1 || seira>22)
							{
								printf("\nLathos ksanaprospatheise.\n");
							}
						} while(seira<1 || seira>22 );
						
						seira--;      //Afairw 1, giati h arithmish arxizei apo to 0.
						
						do
						{
							printf("\nDwse mia thesh [1-4].\n");
							scanf("%d", &th);
							if(th<1 || th>4 )
							{
								printf("\nLathos ksanaprospatheise.\n");
							} 
						} while(th<1 || th>4);
						
						th--;      //Afairw 1, giati h arithmish arxizei apo to 0.
						
						do
						{
							printf("\nPoio noumero epivati einai.\n");
							scanf("%d", &nep);
							if(nep<0 || nep>T_seats_NB)
							{
								printf("\nLathos ksanaprospatheise.\n");
							}
						} while(nep<0 || nep>T_seats_NB);
						
						nep--;       //Afairw 1, giati h arithmish arxizei apo to 0.
							
						if(NB[seira][th]==0)
						{
							printf("\nAuth h thesh einai kenh.\n");
							break;
						}
						else
						{
							printf("\nSe auth th thesh einai o/h %s . \n", name_NB[nep]);
							break;
						}
					}
				}
			
			case 8:
				return 0;
			break;				
		}
	}
}
