int gen_rand()
{
 int r = rand()%9;
 ret r;
}

void simonSays()
{
	int aSpot = 0, button, gDurr = 3, gNow;
	const int GAME_MAX = 64;
	int gArr[GAME_MAX];

	while(gDurr != GAME_MAX)
	{
		gNow  = gDurr;
		do
		{
	 		if(aSpot != 0)
	 			ledC(button, OFF);
	 		button = gen_rand();
	 		gArr[aSpot] = button;
	 		ledC(button, ON);
	 		aSpot++;
			//also needs a delay
		}while(aSpot != gDurr);

		aSpot = 0;

		do
		{
		//change to the buttons function
	 		while((!buttons[1])&&(!buttons[2])&&(!buttons[3])&&(!buttons[4])&&(!buttons[5])&&(!buttons[6])&&(!buttons[7])&&(!buttons[8])&&(!buttons[9]))
			{
			}
			if(buttons[aSpot])
			{
		 		ledC(gArr[aSpot], ON);
		 		aSpot++;
				 //Needs a delay of some sort
		 		ledC(gArr[aSpot], OFF);
		 		if( aSpot == gDurr)
		 		{	
		    		victory();//function still needs to be added
					gDurr++;
				 }
			}
			else
			{
		 		failure();//function still needs to be added
				ret;	
			} 
	  	 	
	    }while(gDurr == gNow);
	}
	ret;

}