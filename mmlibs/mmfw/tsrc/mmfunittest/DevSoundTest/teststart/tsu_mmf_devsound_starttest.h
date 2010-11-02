// Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef TSU_MMF_DEVSOUND_STARTTEST_H
#define TSU_MMF_DEVSOUND_STARTTEST_H

#include <e32base.h>
#include <mmf/common/mmfipc.h>
#ifdef SYMBIAN_ENABLE_SPLIT_HEADERS
#include <mmf/common/mmfipcserver.h>
#endif
#include <a3f/mmfaudiosvrservice.h>
#include "tsu_mmf_devsound_starttest.hrh"

class CStartToolTestSvr;

class CStartToolTest : public CBase,
                       public MAudioSvrService

	{
public:
	static MAudioSvrService* NewL();
	~CStartToolTest();
	
private:
	CStartToolTest();
	
	// from MAudioSvrService
    void PassDestructorKey(TUid aDestructorKey);
    TInt Load();
    void Release();
    TInt Start();
    void Stop();
	
private:
	TUid iDestructorKey;
	CStartToolTestSvr* iServer;
	};

_LIT(KStartToolTestSvrName, "!StartToolSvr");
const TInt KTestCaseErrorCode = -999;

class CStartToolTestSvr: public CServer2
    {
public:
    static CStartToolTestSvr* NewL();
    ~CStartToolTestSvr();
    
    void StartL();
    
private:
    CStartToolTestSvr();
    void ConstructL();
    
    // from CServer2
    CSession2* NewSessionL(const TVersion& aVersion,const RMessage2& aMessage) const;
    };


#endif 
