/******************************************************************************
 * Keetchi - A library for opportunistic communications.
 *
 * Copyright (C) 2016, Communication Networks, University of Bremen, Germany
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 * This file is part of the Keetchi library
 *
 ******************************************************************************/

/**
* Main class that is instantiated by the Keetchi layer of every node to perform
* all Keetchi related activities. There should only be one instance of these 
* objects per node.
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/

#ifndef KLKeetchi_H
#define KLKeetchi_H

#include <list>
#include <string>
#include <cstring>
#include <iostream>

#include "KLTypes.h"
#include "KLAction.h"
#include "KLNodeInfo.h"
#include "KLFeedbackMsg.h"
#include "KLDataMsg.h"
#include "KLDataMgr.h"
#include "KLCacheEntry.h"
#include "KLAppInfo.h"
#include "KLCommMgr.h"
#include "KLResourceMgr.h"

using namespace std;

class KLKeetchi
{
	public:
		KLKeetchi(int cachePolicy, int cacheSize, string ownAddr);
		~KLKeetchi(void);
		
		int registerApplication(string appName, string prefixName, double currentTime);
		int deregisterApplication(string appName, double currentTime);
		KLAction* processFeedbackMsg(int fromWhere, KLFeedbackMsg *feedbackMsg, double currentTime);
		KLAction* processDataMsg(int fromWhere, KLDataMsg *dataMsg, double currentTime);
		list<KLAction*> processNewNeighbourList(list<KLNodeInfo*> nodeInfoList, double currentTime);
		int ageData(double currentTime);
		
	private:
		int maxCacheSize;
		int cacheReplacementPolicy;
		string ownAddress;
		
		KLDataMgr *dataMgr;
		KLCommMgr *commMgr;
		KLResourceMgr *resourceMgr;
		list<KLAppInfo*> registeredAppInfoList;

};

#endif
