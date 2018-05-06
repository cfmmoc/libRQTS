/**
    `libRQTS` is an implementation of Restricted QuadTreeS (https://github.com/cfmmoc/libRQTS/)
    Licensed under The GNU General Public License v3.0 (GPLv3)
    Any modification, re-utilization or copy of the source or binary format in other software or publications should mention a CITATION of this library.
    Copyright (c) 2016-2018 by Authors (Jin Yan, Guanghong Gong, Ni Li and Luhao Xiao)
**/

/**@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%&@@@@*,,,,,,*%&@@@@@
@@@&%#*,* @@@@@@@@@@@@@&%#*,*@@@@@@@@@@@@@@@@@*             @@@*            .@@
@@@.    ,@@@@@@@@&@@@@@,    .@@@@@@@@@@@@@@@@*    @@@@.  .@@@@#.   @@@@@@@   @@
@@@@@   .@@@@@@*  ,@@@@@@.  .@@@@@@@@@@@@@@@,  .@@@@@@.  .@@@@.  .@@@@@@@@.  @@
@@@@@,  .@@@@@@   ,@@@@@@.  @@@@@@@@@@@@@@@@@.  *@@@@@.  .@@@@.   &@@@@@@@.  .@
@@@@@.   @@@@@@    @@@@@@,  @@@@@@@@@@@@@@@@@@    .,,,   .@@@@. ,@@@@@@@@@.  .@
@@@@@. .@@@@@@@@@@@@@@@@@.  @@@@@@@@@@@@@@@@@@*          .@@@@. ,@@@@@@@@@.  .@
@@@@@, .@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@    @@@@.  .@@@@.  *@@@@@@@@.  .@
@@@@@  .@@@@@@@@@@@@@@@@@  .@@@@@@@@@@@@@@@@@@  .@@@@@.  .@@@@.  .@@&%%&@@.   @
@@@@@   @@@@@@@@&&@@@@@@@  .@@@&%@@@@@@@@/,/@@  .@@@@@.  .@@@@   ,@.   @@@.  @@
@@@@@  @@@@@     .@@@@@@#  ./.     *@@@@@   .    @@@/,    .#@@@      .(#.    @@
@@@@@  @@@@@     .@@@@@@.     @@@   *@@@@@      @@@@        &@@@             @@
@@@@*  @@@@@@@.  .@@@@@@.   @@@@@@@  .@@@@@@&&@@@@@@@@@@@@@@@@@&   .#%%%@@@@@@@
@@@@.  @@@@@@@.   @@@@@@, . @@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@*   @&%%%@@@@@@@
@@@@. .@@@@@@@. .@@@@@@#. .@@@@@@@@@  ,@@.                 @@@.           *#@@@
@@@@, .@@@@@@@, .@@@@@@.  .@@@@@@@@@  .@@. .@@@@@  .@@@@   @@@.    @@@@@@   ,@@
@@@#. .@@@@@@*  .@@@@@@.   @@@@@@@@@  .@@  .@@@@@  .@@@@   @@@.   @@@@@@@@   @@
@@@.   @@@@@@.   @@@@@@, .@@@@@@@@@#   @@@@@@@@@@  .@@@@@@@@@@   @@@@@@@@#   @@
@@@. .@@@@@@@, .@@@@@@@. .@@@@@@@@@.  @@@@@@@@@@@  .@@@@@@@@@@@@@@&%%*,.    @@@
@@@, .@@@@@@@, .@@@@@@@  .@@@@@@@@@,  @@@@@@@@@@@  .@@@@@@@@@@@#          @@@@@
@@#. .@@@@@@*  .@@@@@@@   @@@@@@@@*   @@@@@@@@@@@  .@@@@@@@@@@*     @@@@@@@@@@@
@@.   @@@@@@.   @@@@@@@  #@@@@@@@*   @@@@@@@@@@@@  .@@@@@@@@@,   @@@@@@@@@*,*@@
@@,  @@@@@@@,  @@@@@@@#  ,@@@@@@@   @@@@@@@@@@@@@  .@@@@@@@@@.  @@@@@@@@@@   @@
,.   .,/@@,.   .,/@@@@.   .#@@#*   @@@@@@@@@@@%%(  .(%&@@@@@@@   *#@@&%#.    @@
       .@#       .@@@@. @   ,,   @@@@@@@@@@@@#        .@@@@@@@@    .,        @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**/

/**
	@brief  A class representing neighbors of a tile.
**/

#include "neig.h"

/**
    	@remarks
        	defualt constructor
**/
CTBNeighbor::CTBNeighbor(void)
{
}

/**
    	@remarks
        	initialize eight neighbors (two neighbors on each side of a square) of a tile
    	@par
        	*neighbor	filenames of eight neighbors
**/
CTBNeighbor::CTBNeighbor(std::string* neighbor)
{
	for (int i = 0; i < 8; i++)
	{
		mNeighbor[i] = neighbor[i];
	}
}

/**
    	@remarks
        	defualt deconstructor
**/
CTBNeighbor::~CTBNeighbor(void)
{
}

/**
    	@remarks
        	return neighbor of a tile for given side
    	@par
        	i	given side (from 0 to 7)
**/
std::string CTBNeighbor::GetNeighbor(int i)
{
	return mNeighbor[i];
}

/**
    	@remarks
        	update the filename of neighbor of a tile for given side
    	@par
        	i	given side (from 0 to 7)
		name	filename of neighbor
**/
void CTBNeighbor::SetNeighbor(int i, std::string name)
{
	mNeighbor[i] = name;
}
