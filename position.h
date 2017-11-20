/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001        
*  HW#         :  3
*  Due Date    :  Sep 26th, 2017
*  Description :  Contains the definitions for the Position namespace
				  which includes the Coordinates class and Orientation
				  enum.
********************************************************************/

#ifndef POSITION_H
#define POSITION_H

namespace Position
{
	enum Orientation { HORIZONTAL, VERTICAL };
	struct Coordinates
	{
		int X;
		int Y;
		bool operator==(const Coordinates other);
		Coordinates(int x, int y);
	};	
}

#endif