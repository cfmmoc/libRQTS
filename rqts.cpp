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

#include "rqts.h"
#include <sys/shm.h>
#include <string>
#include <string.h>
#include <iostream>

libRQTS::libRQTS(void)
{
	std::string copyrightinfo("libRQTS is an implementation of Restricted QuadTreeS.\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%&@@@@*,,,,,,*%&@@@@@\n@@@&%#*,* @@@@@@@@@@@@@&%#*,*@@@@@@@@@@@@@@@@@*             @@@*            .@@\n@@@.    ,@@@@@@@@&@@@@@,    .@@@@@@@@@@@@@@@@*    @@@@.  .@@@@#.   @@@@@@@   @@\n@@@@@   .@@@@@@*  ,@@@@@@.  .@@@@@@@@@@@@@@@,  .@@@@@@.  .@@@@.  .@@@@@@@@.  @@\n@@@@@,  .@@@@@@   ,@@@@@@.  @@@@@@@@@@@@@@@@@.  *@@@@@.  .@@@@.   &@@@@@@@.  .@\n@@@@@.   @@@@@@    @@@@@@,  @@@@@@@@@@@@@@@@@@    .,,,   .@@@@. ,@@@@@@@@@.  .@\n@@@@@. .@@@@@@@@@@@@@@@@@.  @@@@@@@@@@@@@@@@@@*          .@@@@. ,@@@@@@@@@.  .@\n@@@@@, .@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@    @@@@.  .@@@@.  *@@@@@@@@.  .@\n@@@@@  .@@@@@@@@@@@@@@@@@  .@@@@@@@@@@@@@@@@@@  .@@@@@.  .@@@@.  .@@&%%&@@.   @\n@@@@@   @@@@@@@@&&@@@@@@@  .@@@&%@@@@@@@@/,/@@  .@@@@@.  .@@@@   ,@.   @@@.  @@\n@@@@@  @@@@@     .@@@@@@#  ./.     *@@@@@   .    @@@/,    .#@@@      .(#.    @@\n@@@@@  @@@@@     .@@@@@@.     @@@   *@@@@@      @@@@        &@@@             @@\n@@@@*  @@@@@@@.  .@@@@@@.   @@@@@@@  .@@@@@@&&@@@@@@@@@@@@@@@@@&   .#%%%@@@@@@@\n@@@@.  @@@@@@@.   @@@@@@, . @@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@*   @&%%%@@@@@@@\n@@@@. .@@@@@@@. .@@@@@@#. .@@@@@@@@@  ,@@.                 @@@.           *#@@@\n@@@@, .@@@@@@@, .@@@@@@.  .@@@@@@@@@  .@@. .@@@@@  .@@@@   @@@.    @@@@@@   ,@@\n@@@#. .@@@@@@*  .@@@@@@.   @@@@@@@@@  .@@  .@@@@@  .@@@@   @@@.   @@@@@@@@   @@\n@@@.   @@@@@@.   @@@@@@, .@@@@@@@@@#   @@@@@@@@@@  .@@@@@@@@@@   @@@@@@@@#   @@\n@@@. .@@@@@@@, .@@@@@@@. .@@@@@@@@@.  @@@@@@@@@@@  .@@@@@@@@@@@@@@&%%*,.    @@@\n@@@, .@@@@@@@, .@@@@@@@  .@@@@@@@@@,  @@@@@@@@@@@  .@@@@@@@@@@@#          @@@@@\n@@#. .@@@@@@*  .@@@@@@@   @@@@@@@@*   @@@@@@@@@@@  .@@@@@@@@@@*     @@@@@@@@@@@\n@@.   @@@@@@.   @@@@@@@  #@@@@@@@*   @@@@@@@@@@@@  .@@@@@@@@@,   @@@@@@@@@*,*@@\n@@,  @@@@@@@,  @@@@@@@#  ,@@@@@@@   @@@@@@@@@@@@@  .@@@@@@@@@.  @@@@@@@@@@   @@\n,.   .,/@@,.   .,/@@@@.   .#@@#*   @@@@@@@@@@@%%(  .(%&@@@@@@@   *#@@&%#.    @@\n       .@#       .@@@@. @   ,,   @@@@@@@@@@@@#        .@@@@@@@@    .,        @@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\nAuthors:\nJin Yan (kinian@126.com) from Capital University of Economics and Business,\nGuanghong Gong (ggh@buaa.edu.cn) and Ni Li* (lini@buaa.edu.cn) from Beihang University,\nLuhao Xiao (shawmoso@163.com) from Beijing ChuangQi Horizon Technology Co., Ltd.\nLicensed under The GNU General Public License v3.0 (GPLv3).\nAny modification, re-utilization or copy of the source or binary format in other software or publications should mention a CITATION (https://github.com/cfmmoc/) of this library.\n");
	std::cout<<std::endl<<copyrightinfo;
	initSharedM();
	initRootNeighbor();
}

libRQTS::~libRQTS(void)
{
	closeSharedM();
}

void libRQTS::initRootNeighbor()
{
	mHashTile2Neighbor = new std::tr1::unordered_map<std::string, CTBNeighbor*>;

	std::string neighbor[8];

	neighbor[0] = std::string("y");		neighbor[1] = neighbor[0];
	neighbor[2] = std::string("v");		neighbor[3] = neighbor[2];
	neighbor[4] = std::string("x");		neighbor[5] = neighbor[4];
	neighbor[6] = std::string("w");		neighbor[7] = neighbor[6];
	(*mHashTile2Neighbor)[std::string("u")] = new CTBNeighbor(neighbor);

	neighbor[0] = std::string("u");		neighbor[1] = neighbor[0];
	neighbor[2] = std::string("y");		neighbor[3] = neighbor[2];
	neighbor[4] = std::string("w");		neighbor[5] = neighbor[4];
	neighbor[6] = std::string("z");		neighbor[7] = neighbor[6];
	(*mHashTile2Neighbor)[std::string("v")] = new CTBNeighbor(neighbor);

	neighbor[0] = std::string("u");		neighbor[1] = neighbor[0];
	neighbor[2] = std::string("v");		neighbor[3] = neighbor[2];
	neighbor[4] = std::string("x");		neighbor[5] = neighbor[4];
	neighbor[6] = std::string("z");		neighbor[7] = neighbor[6];
	(*mHashTile2Neighbor)[std::string("w")] = new CTBNeighbor(neighbor);

	neighbor[0] = std::string("u");		neighbor[1] = neighbor[0];
	neighbor[2] = std::string("w");		neighbor[3] = neighbor[2];
	neighbor[4] = std::string("y");		neighbor[5] = neighbor[4];
	neighbor[6] = std::string("z");		neighbor[7] = neighbor[6];
	(*mHashTile2Neighbor)[std::string("x")] = new CTBNeighbor(neighbor);

	neighbor[0] = std::string("u");		neighbor[1] = neighbor[0];
	neighbor[2] = std::string("x");		neighbor[3] = neighbor[2];
	neighbor[4] = std::string("v");		neighbor[5] = neighbor[4];
	neighbor[6] = std::string("z");		neighbor[7] = neighbor[6];
	(*mHashTile2Neighbor)[std::string("y")] = new CTBNeighbor(neighbor);

	neighbor[0] = std::string("w");		neighbor[1] = neighbor[0];
	neighbor[2] = std::string("v");		neighbor[3] = neighbor[2];
	neighbor[4] = std::string("x");		neighbor[5] = neighbor[4];
	neighbor[6] = std::string("y");		neighbor[7] = neighbor[6];
	(*mHashTile2Neighbor)[std::string("z")] = new CTBNeighbor(neighbor);

}

void libRQTS::initSharedM()
{
	mSharedIDLoad = shmget((key_t)1335, sizeof(struct SHARED_LOAD_RQ), 0666|IPC_CREAT);
	mSharedMemLoad = shmat(mSharedIDLoad, (void*)0, 0);
	mSharedSttLoad = (struct SHARED_LOAD_RQ*)mSharedMemLoad;
}

void libRQTS::closeSharedM()
{
	shmdt(mSharedMemLoad);
	shmctl(mSharedIDLoad, IPC_RMID, 0);
}

void libRQTS::sendfile()
{
    if(mSharedSttLoad->mWritable != 1)
    {
        for (std::vector<CTBLoadReq*>::iterator it = mLoadQueueReg.begin();
            it != mLoadQueueReg.end(); it++)
        {
            mSharedSttLoad->mIsSplit[mSharedSttLoad->mLength] = (*it)->IsSplitReq();
            strcpy(mSharedSttLoad->mFilename[mSharedSttLoad->mLength],
                (*it)->GetReqName().c_str());
            mSharedSttLoad->mLength++;
        }
        mLoadQueueReg.clear();
        mSharedSttLoad->mWritable = 1;
    }
}

bool libRQTS::recvfile()
{
    bool ret = false;
    if(mSharedSttLoad->mWritable != 0)
    {
        if (mSharedSttLoad->mLength > 0)
        {
            for (unsigned int i = 0; i < mSharedSttLoad->mLength; i++)
            {
                CTBLoadReq *req = new CTBLoadReq(mSharedSttLoad->mIsSplit[i],
                    mSharedSttLoad->mFilename[i]);
                mLoadQueueReg.push_back(req);
            }
            mSharedSttLoad->mLength = 0;
            ret = true;
        }
        mSharedSttLoad->mWritable = 0;
    }
    if (mLoadQueue.empty())
    {
        mLoadQueue = mLoadQueueReg;
        mLoadQueueReg.clear();
    }
    return ret;
}

bool libRQTS::checksplit(std::string filename)
{
    bool can_split[4] = {false, false, false, false};
    CTBNeighbor *neighbor = (*mHashTile2Neighbor)[filename];
	for (int i = 0; i < 4; i++)
	{
		if (neighbor->GetNeighbor(i * 2).length() == 0 || neighbor->GetNeighbor(i * 2).length() >= filename.length())
		{
			can_split[i] = true;
		}
		else
		{
			can_split[i] = checksplit(neighbor->GetNeighbor(i * 2));
		}
	}

	if (can_split[0] && can_split[1] && can_split[2] && can_split[3])
	{
		bool found = false;
		for (std::vector<CTBLoadReq*>::iterator it = mLoadQueue.begin();
			it != mLoadQueue.end(); it++)
		{
			CTBLoadReq *req = *it;
			if (req->GetReqName() == filename)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			CTBLoadReq *req = new CTBLoadReq(true, filename);
			mLoadQueue.push_back(req);
			mLoadQueueReg.push_back(req);
		}
	}
	return true;
}

bool libRQTS::checkmerge(std::vector<std::string> filenames)
{
    for (std::vector<std::string>::iterator it = filenames.begin();
		it != filenames.end(); it++)
	{
		if (checkMerge(*it))
		{
			return true;
		}
	}

	return false;
}

bool libRQTS::checkMerge(std::string filename)
{
    std::string sub_name[4] = {"/q", "/r", "/s", "/t"};
	unsigned int son_neighbor[4][4] = {0, 1, 2, 3,
		0, 1, 4, 5,
		2, 3, 6, 7,
		4, 5, 6, 7};

	for (int i = 0; i < 4; i++)
	{
		CTBNeighbor *neighbor = (*mHashTile2Neighbor)[filename + sub_name[i]];
		if (neighbor == NULL)
		{
			int a = 0;
		}
		if (neighbor->GetNeighbor(son_neighbor[i][0]) != neighbor->GetNeighbor(son_neighbor[i][1]))
		{
			return false;
		}
		if (neighbor->GetNeighbor(son_neighbor[i][2]) != neighbor->GetNeighbor(son_neighbor[i][3]))
		{
			return false;
		}
	}

	CTBLoadReq *req = new CTBLoadReq(false, filename);
	mLoadQueue.push_back(req);
	mLoadQueueReg.push_back(req);

	return true;
}

void libRQTS::split(std::string filename)
{

	std::string sub_name[4] = {"/q", "/r", "/s", "/t"};
	unsigned int inter_map[4][8] = {0, 0, 0, 0, 2, 2, 3, 3,
		0, 0, 1, 1, 0, 0, 4, 4,
		1, 1, 0, 0, 4, 4, 0, 0,
		2, 2, 3, 3, 0, 0, 0, 0};
	unsigned int son_of_neighbor2[8] = {0, 1, 0, 2, 1, 3, 2, 3};

	for (int i = 0; i < 4; i++)
	{
		(*mHashTile2Neighbor)[filename + sub_name[i]] = new CTBNeighbor();
	}

	for (int i = 0; i < 4; i++)
	{
		CTBNeighbor *neighbor = (*mHashTile2Neighbor)[filename + sub_name[i]];
		for (int j = 0; j < 8; j++)
		{
			if (inter_map[i][j])
			{
				neighbor->SetNeighbor(j, filename + sub_name[inter_map[i][j] - 1]);
			}
		}
	}

	CTBNeighbor *neighbor_of_father = (*mHashTile2Neighbor)[filename];
	for (int i = 0; i < 8; i = i + 2)
	{
		if (neighbor_of_father->GetNeighbor(i) != ""|| neighbor_of_father->GetNeighbor(i + 1) != "")
		{
			if (neighbor_of_father->GetNeighbor(i) == neighbor_of_father->GetNeighbor(i + 1))
			{
				CTBNeighbor *neighbor_of_neighbor = (*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i)];
				for (int j = 0; j < 8; j = j + 2)
				{
					if (neighbor_of_neighbor->GetNeighbor(j) == filename)
					{
						(*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i)]->SetNeighbor(j,
							filename + sub_name[son_of_neighbor2[i]]);
						(*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i)]->SetNeighbor(j + 1,
							filename + sub_name[son_of_neighbor2[i + 1]]);
						break;
					}
				}
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i]]]->SetNeighbor(i,
					neighbor_of_father->GetNeighbor(i));
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i]]]->SetNeighbor(i + 1,
					neighbor_of_father->GetNeighbor(i + 1));
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i + 1]]]->SetNeighbor(i,
					neighbor_of_father->GetNeighbor(i));
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i + 1]]]->SetNeighbor(i + 1,
					neighbor_of_father->GetNeighbor(i + 1));
			}
			else
			{
				CTBNeighbor *neighbor_of_neighbor;
				if (neighbor_of_father->GetNeighbor(i) != "")
                {
                    neighbor_of_neighbor = (*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i)];
                }
                else if (neighbor_of_father->GetNeighbor(i + 1) != "")
                {
                    neighbor_of_neighbor = (*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i + 1)];
                }
				for (int j = 0; j < 8; j = j + 2)
				{
					if (neighbor_of_neighbor->GetNeighbor(j) == filename)
					{
                        if (neighbor_of_father->GetNeighbor(i) != "")
                        {
                            (*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i)]->SetNeighbor(j,
                                filename + sub_name[son_of_neighbor2[i]]);
                            (*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i)]->SetNeighbor(j + 1,
                                filename + sub_name[son_of_neighbor2[i]]);
                        }
                        if (neighbor_of_father->GetNeighbor(i + 1) != "")
                        {
                            (*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i + 1)]->SetNeighbor(j,
                                filename + sub_name[son_of_neighbor2[i + 1]]);
                            (*mHashTile2Neighbor)[neighbor_of_father->GetNeighbor(i + 1)]->SetNeighbor(j + 1,
                                filename + sub_name[son_of_neighbor2[i + 1]]);
                        }
						break;
					}
				}
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i]]]->SetNeighbor(i,
					neighbor_of_father->GetNeighbor(i));
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i]]]->SetNeighbor(i + 1,
					neighbor_of_father->GetNeighbor(i));
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i + 1]]]->SetNeighbor(i,
					neighbor_of_father->GetNeighbor(i + 1));
				(*mHashTile2Neighbor)[filename + sub_name[son_of_neighbor2[i + 1]]]->SetNeighbor(i + 1,
					neighbor_of_father->GetNeighbor(i + 1));
			}
		}
	}

	std::tr1::unordered_map<std::string, CTBNeighbor*>::iterator it = (*mHashTile2Neighbor).find(filename);
	(*mHashTile2Neighbor).erase(it);

}

void libRQTS::merge(std::string filename)
{

	std::string sub_name[4] = {"/q", "/r", "/s", "/t"};

	(*mHashTile2Neighbor)[filename] = new CTBNeighbor();

	unsigned int son_to_neighbor[8][2] = {0, 0,
		1, 0,
		0, 2,
		2, 2,
		1, 4,
		3, 4,
		2, 6,
		3, 6};

	CTBNeighbor *neighbor = (*mHashTile2Neighbor)[filename];
	for (int i = 0; i < 8; i++)
	{
		CTBNeighbor *neighbor_of_son = (*mHashTile2Neighbor)[filename + sub_name[son_to_neighbor[i][0]]];
		neighbor->SetNeighbor(i, neighbor_of_son->GetNeighbor(son_to_neighbor[i][1]));
	}

	for (int i = 0; i < 8; i = i + 2)
	{
		unsigned int s1 = son_to_neighbor[i][0];
		unsigned int p1 = son_to_neighbor[i][1];
		unsigned int s2 = son_to_neighbor[i + 1][0];
		unsigned int p2 = son_to_neighbor[i + 1][1];
		CTBNeighbor *neighbor_of_son1 = (*mHashTile2Neighbor)[filename + sub_name[s1]];
		CTBNeighbor *neighbor_of_son2 = (*mHashTile2Neighbor)[filename + sub_name[s2]];

		CTBNeighbor *neighbor_of_neighbor;
		if (neighbor_of_son1->GetNeighbor(p1) != "")
		{
			neighbor_of_neighbor = (*mHashTile2Neighbor)[neighbor_of_son1->GetNeighbor(p1)];
			for (int j = 0; j < 8; j++)
			{
				if (neighbor_of_neighbor->GetNeighbor(j) == filename + sub_name[s1])
				{
					neighbor_of_neighbor->SetNeighbor(j, filename);
				}
			}
		}
		if (neighbor_of_son2->GetNeighbor(p2) != "")
		{
			neighbor_of_neighbor = (*mHashTile2Neighbor)[neighbor_of_son2->GetNeighbor(p2)];
			for (int j = 0; j < 8; j++)
			{
				if (neighbor_of_neighbor->GetNeighbor(j) == filename + sub_name[s2])
				{
					neighbor_of_neighbor->SetNeighbor(j, filename);
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		std::tr1::unordered_map<std::string, CTBNeighbor*>::iterator it = (*mHashTile2Neighbor).find(filename + sub_name[i]);
		(*mHashTile2Neighbor).erase(it);
	}

}

std::string libRQTS::checkfile()
{
	std::string name;
	if (!mLoadQueue.empty())
	{
		CTBLoadReq *req = mLoadQueue[0];
		if (req->IsSplitReq())
		{
			std::string reqName = req->GetReqName();
			switch (req->GetReqCount())
			{
			case  0:
				name = reqName + "/q";
				break;
			case  1:
				name = reqName + "/r";
				break;
			case  2:
				name = reqName + "/s";
				break;
			case  3:
				name = reqName + "/t";
				break;
			}
			req->IncReqCount();
		}
		else
		{
			std::string reqName = req->GetReqName();
			if (req->GetReqCount() == 0)
			{
				name = reqName;
				req->IncReqCount();
			}
		}
	}
	return name;
}

std::string libRQTS::getfile()
{
	std::string name;
	CTBLoadReq *req = mLoadQueue[0];
	if (req->IsSplitReq())
	{
		req->IncReqOverCount();
	}
	else
	{
		name = "m";
		mLoadQueue.erase(mLoadQueue.begin());
	}
	if (req->GetReqOverCount() == 4)
	{
                name = req->GetReqName();
		mLoadQueue.erase(mLoadQueue.begin());
	}
	return name;
}

bool libRQTS::isdone()
{
	return mLoadQueue.empty();
}

std::string libRQTS::checkbound(std::string filename, unsigned char side, unsigned char* mask)
{
	CTBNeighbor *neighbor = (*mHashTile2Neighbor)[filename];
	std::string neighborname = neighbor->GetNeighbor(side * 2);
	*mask = 0;
	if (neighborname.length() == filename.length())
	{
		CTBNeighbor *neighborofneighbor = (*mHashTile2Neighbor)[neighborname];
		for (unsigned int i = 0; i < 4; i++)
		{
			if (neighborofneighbor->GetNeighbor(i * 2).length() > neighborname.length() ||
				neighborofneighbor->GetNeighbor(i * 2) == filename)
			{
				*mask |= (1 << i);
			}
		}
	}
	return neighborname;
}

std::string replacefile(std::string name)
{
    if (name.length() < 2)
    {
        return name;
    }
    char endname = *(name.end() - 1) - 'q' + 'w';
    name.erase(name.end() - 1);
    return name + endname;
}
