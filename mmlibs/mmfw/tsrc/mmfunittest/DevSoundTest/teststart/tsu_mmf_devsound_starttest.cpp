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

#include <ecom/ecom.h>
#include <ecom/implementationproxy.h>
#include "tsu_mmf_devsound_starttest.h"

// CStartToolTest 

MAudioSvrService* CStartToolTest::NewL()
	{
    CStartToolTest* result = new (ELeave) CStartToolTest;
	return result;
	}

CStartToolTest::~CStartToolTest()
    {
    REComSession::DestroyedImplementation(iDestructorKey);
    }
	
CStartToolTest::CStartToolTest()
	{
    delete iServer;
	}
	
void CStartToolTest::PassDestructorKey(TUid aDestructorKey)
	{
	iDestructorKey = aDestructorKey;
	}

TInt CStartToolTest::Load()
    {
    TRAPD(err, iServer = CStartToolTestSvr::NewL());
    return err;
    }
	
TInt CStartToolTest::Start()
    {
    RDebug::Print(_L("CStartToolTest::StartL()"));
    TRAPD(err, iServer->StartL());
    return err;
    }

void CStartToolTest::Release()
    {
    delete this;
    }

void CStartToolTest::Stop()
    {
    // assume we don't have to handle this as such, and if we did the subsequent delete would do.
    }

// CStartToolTestSvr

CStartToolTestSvr* CStartToolTestSvr::NewL()
    {
    CStartToolTestSvr* result = new (ELeave) CStartToolTestSvr;
    CleanupStack::PushL(result);
    result->ConstructL();
    CleanupStack::Pop(result);
    return result;
    }

CStartToolTestSvr::CStartToolTestSvr():
        CServer2(0)
    {
    // nothing to do
    }

CStartToolTestSvr::~CStartToolTestSvr()
    {
    // nothing to do
    }

void CStartToolTestSvr::ConstructL()
    {
    // nothing to do
    }

void CStartToolTestSvr::StartL()
    {
    CServer2::StartL(KStartToolTestSvrName);
    }

CSession2* CStartToolTestSvr::NewSessionL(const TVersion& /*aVersion*/,const RMessage2& /*aMessage*/) const
    {
    RDebug::Print(_L("CStartToolTestSvr::NewSessionL"));
    User::Leave(KTestCaseErrorCode); // new session fails with special error code. test expected to check that
    return NULL;
    }

//
// ImplementationTable
//

const TImplementationProxy ImplementationTable[] = 
    {
    IMPLEMENTATION_PROXY_ENTRY(KUidStartTestPlugin, CStartToolTest::NewL)
    };


//
// ImplementationGroupProxy
//
//

EXPORT_C const TImplementationProxy* ImplementationGroupProxy(TInt& aTableCount)
    {
    aTableCount = sizeof(ImplementationTable) / sizeof(TImplementationProxy);

    return ImplementationTable;
    }
