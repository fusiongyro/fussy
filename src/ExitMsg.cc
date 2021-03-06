/* $Id: ExitMsg.cc,v 1.2 2006/01/17 18:57:09 sbhatnag Exp $ */
/******************************************************************
 * Copyright (c) 2000-2018, 2019 S.Bhatnagar
 *
 *  This file is part of fussy.
 *
 *  fussy is a free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  fussy is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with fussy.  If not, see <https://www.gnu.org/licenses/>.
 *

  History:

    First version.

               Sanjay Bhatnagar, May 2000
               sanjay@ncra.tifr.res.in

******************************************************************/
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <defns.h>
#include "namespace.h"
extern string Calc_prompt;
extern bool VMState_Quit;

void ExitMsg(ostream& user,string MsgData)
{
  extern int Persistance;
  extern pid_t Seed;
  extern int Tolerance;
  string Home(getenv("HOME"));
  MsgData = Home + "/." + MsgData;

  srand(Seed);

  user << endl << " Treat me well - say \"bye\" to leave."  
       << endl << Calc_prompt;
  if (Persistance < Tolerance)
    {
      ifstream db(MsgData.c_str());
      if (db)
	{
	  vector<streampos> offsets;
	  int N=0,ch;
	  while(!db.eof())
	    if ((db.get()=='%'))
	      {
		N++;
		offsets.resize(N);
		offsets[N-1]=db.tellg()+(streampos)1;
	      }
	  N--;

	  //	  N=(int) (N*(float)rand()/RAND_MAX);
	  N = rand() % N;
	  Seed = rand();
	  db.clear();
	  db.seekg(offsets[N],ios::beg);

	  while (((ch=db.get())!=EOF) && (ch!='%') && (ch!='#')) user << (char)ch;
	  user << endl;
	  user << endl << Calc_prompt;
	}
      else
	{
	  //	  Tolerance = 4;
	}
    }
  else
    {
      user << endl << "Oh well...since you insist.  "
	"  But be nice next time!  Say \"bye\" to exit" << endl;
      VMState_Quit=true;
      Persistance = Tolerance+1;
      // ExitException e;
      // throw(e);
    }
  Persistance++;
}
