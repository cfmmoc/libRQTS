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

#pragma once

#include <string>
#include <vector>
#include <tr1/unordered_map>
#include "neig.h"
#include "lreq.h"

/**
    	@remarks
        	replace the trailing letter of a tile's filename
	@par
		name	filename of a given tile
**/
std::string replaceNamend(std::string name);

/**
	@brief  Core class of libRQTS, mainly for split/merge checking, invoking splitting/merging and maintaining neighbors of tiles.
**/

class libRQTS
{
public:
	/**
    	@remarks
        	allocate shared memory and initialize neighbors of initial tiles
	**/
	libRQTS(void);
	/**
    	@remarks
        	free shared memory
	**/
	~libRQTS(void);
	/**
    	@remarks
        	check whether a tile could be split or not
	@par
		filename	filename of a given tile
	**/
	bool checksplit(std::string filename);
	/**
    	@remarks
        	check whether a group of tiles (represented by their parents) could be merged or not one by one
	@par
		filenames	a group of parents of every four sibling tiles to be merged
	**/
	bool checkmerge(std::vector<std::string> filenames);
	/**
    	@remarks
        	check whether four tiles could be merged or not
	@par
		filename	filename of parent of given four tiles
	**/	
	bool checkMerge(std::string filename);
	/**
    	@remarks
        	actual operation of merging four tiles
	@par
		filename	filename of the parent of four tiles
	**/
	void merge(std::string filename);
	/**
    	@remarks
        	actual operation of splitting a tile
	@par
		filename	filename of a given tile
	**/
	void split(std::string filename);
	/**
    	@remarks
        	check load queue, and return load request from load queue for merging request
		for splitting request, increase its counter and return one of its child according to its counter
	**/
	std::string checkfile();
	/**
    	@remarks
        	erase and return load request from load queue for merging request
		for splitting request, increase its finished counter until four, 
		and then erase and return load request from load queue
	**/
	std::string getfile();
	/**
    	@remarks
        	return whether load queue is empty, true if empty
	**/
	bool isdone();
	/**
    	@remarks
        	send load requests to fore-end process
	**/
	void sendfile();
	/**
    	@remarks
        	receive load requests from back-end process
	**/
	bool recvfile();
	/**
    	@remarks
        	check neighbors of given tile for given side
	@par
		filename	filename of a given tile
		side		indicates the give side (from 0 to 7)
		*mask		indicates the level of detail of four side of the corresponding neighbor (depends on side) for given tile
	**/
	std::string checkbound(std::string filename, unsigned char side, unsigned char* mask);

private:
	/**
    	@remarks
        	initialize neighbors of six initial tiles
	**/
	void initRootNeighbor();
	/**
    	@remarks
        	allocate shared memory
	**/
	void initSharedM();
	/**
    	@remarks
        	free shared memory
	**/
	void closeSharedM();
	
	// a map from tiles to their neighbors
	std::tr1::unordered_map<std::string, CTBNeighbor*>* mHashTile2Neighbor;
	// a queue of load requests
	std::vector<CTBLoadReq*> mLoadQueue;
	// a copy of queue of load requests
	std::vector<CTBLoadReq*> mLoadQueueReg;

	// shared memory and related variables of sharing load requests between back-end and fore-end processes
	void *mSharedMemLoad;
	struct SHARED_LOAD_RQ *mSharedSttLoad;
	int mSharedIDLoad;

};
