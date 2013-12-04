iint gen_rand()
{
 int r = rand()%9;
 ret r;
};

void simonSays()
{
	int aSpot = 0, button, gDurr = 3, gNow, swSpot = 0;
	const int GAME_MAX = 64;
	int gArr[GAME_MAX];

	while(gDurr != GAME_MAX)
	{
		gNow  = gDurr;

		//this loop shows the light order
		do
		{
	 		if(aSpot != 0)
	 			ledC(button, OFF);
	 		button = gen_rand();
	 		gArr[aSpot] = button;
	 		ledC(button, ON);
	 		aSpot++;
			lightDelay();
			lightDelay();
		}while(aSpot != gDurr);

		aSpot = 0;

		//this loop is when the user puts in the numbers
		do
		{
		//change to the buttons function
	 		while((sw1)&&(sw2)&&(sw3)&&(sw4)&&(sw5)&&(sw6)&&(sw7)&&(sw8)&&(sw9))//because of active low if thw Switch = 1 it is not being pushed
			{
			}
			if(!sw1)
				swSpot = 1;
			else
				if(!sw2)
					swSpot = 2;
				else
					if(!sw3)
						swSpot = 3;
					else
					if(!sw4)
						swSpot = 4;
					else
					if(!sw5)
						swSpot = 5;
					else
					if(!sw6)
						swSpot = 6;
					else
					if(!sw7)
						swSpot = 7;
					else
					if(!sw8)
						swSpot = 8;
					else
					if(!sw9)
						swSpot = 9;
			if(swSpot == gArr[aSpot])
			{
		 		ledC(gArr[aSpot], ON);
		 		aSpot++;
				lightDelay();
				lightDelay();
		 		ledC(gArr[aSpot], OFF);
		 		if( aSpot == gDurr)
		 		{	
		    		victory();
					gDurr++;
				 }
			}
			else
			{
		 		failure();
				ret;	
			} 
	  	 	
	    }while(gDurr == gNow);
	}
	ret;

};
void victory()
{
   ledC( 1, ON);
   lightDelay();
   ledC( 2, ON);
   lightDelay();
   ledC( 3, ON);
   lightDelay();
   ledC( 6, ON);
   lightDelay();
   ledC( 9, ON);
   lightDelay();
   ledC( 8, ON);
   lightDelay();
   ledC( 7, ON);
   lightDelay();
   ledC( 4, ON);
   lightDelay();
   lightDelay();
   lightDelay();

   ledC( 1, OFF);
   ledC( 2, OFF);
   ledC( 3, OFF);
   ledC( 4, OFF);
   ledC( 6, OFF);
   ledC( 7, OFF);
   ledC( 8, OFF);
   ledC( 9, OFF);

   ret;

};
void failure()
{
   ledC( 1, ON);
   ledC( 3, ON);
   ledC( 5, ON);
   ledC( 7, ON);
   ledC( 9, ON);
   lightDelay();
   lightDelay();
   lightDelay();
   lightDelay();
   lightDelay();

   ledC( 1, OFF);
   ledC( 3, OFF);
   ledC( 5, OFF);
   ledC( 7, OFF);
   ledC( 9, OFF);

   ret;

 };