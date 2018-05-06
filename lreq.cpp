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
  @brief  A class representing a load request.
**/

#include "lreq.h"

/**
    	@remarks
        	default constructor
**/
CTBLoadReq::CTBLoadReq(void)
{
}

/**
    	@remarks
        	initialize a load request
    	@par
        	split	indicates request type (split/merge)
		name	filename of the request
**/
CTBLoadReq::CTBLoadReq(bool split, std::string name)
{
	mSplitReq = split;
	mReqName = name;
	mReqCount = 0;
	mReqOverCount = 0;
}

/**
    	@remarks
        	default deconstructor
**/
CTBLoadReq::~CTBLoadReq(void)
{
}

/**
    	@remarks
        	return type of load request, true for split request
**/
bool CTBLoadReq::IsSplitReq()
{
	return mSplitReq;
}

/**
    	@remarks
        	return filename of load request
**/
std::string CTBLoadReq::GetReqName()
{
	return mReqName;
}

/**
    	@remarks
        	return counter of request
**/
int CTBLoadReq::GetReqCount()
{
	return mReqCount;
}

/**
    	@remarks
        	return counter of finished request
**/
int CTBLoadReq::GetReqOverCount()
{
	return mReqOverCount;
}

/**
    	@remarks
        	increase counter of request by one
		for split request, the maximum value of counter is four
		for merge request, the maximum value of counter is one
**/
void CTBLoadReq::IncReqCount()
{
	if (mSplitReq && mReqCount < 4)
	{
		mReqCount++;
	}
	if (!mSplitReq && mReqCount < 1)
	{
		mReqCount++;
	}
}

/**
    	@remarks
        	increase counter of finished request by one
		for split request, the maximum value of counter is four
**/
void CTBLoadReq::IncReqOverCount()
{
	if (mSplitReq && mReqOverCount < 4)
	{
		mReqOverCount++;
	}
}
