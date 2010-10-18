// Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/sfl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

/**
 @file
 @internalComponent
*/

#ifndef MMFMEDIACLIENTEXTDISPLAYTESTPROVIDER_H_
#define MMFMEDIACLIENTEXTDISPLAYTESTPROVIDER_H_

#include <mmf/plugin/mmfmediaclientextdisplayinterface.h>
#include <e32base.h>

class CExtDisplayTestConnectionProvider;

class CExtDisplayConnectionTimer : public CTimer
    {
public:
    static CExtDisplayConnectionTimer* NewL(CExtDisplayTestConnectionProvider* iParent, TTimeIntervalMicroSeconds32 aInterval);
    void Start();

private:
    void RunL();
    CExtDisplayConnectionTimer(CExtDisplayTestConnectionProvider* iParent, TTimeIntervalMicroSeconds32 aInterval);
    
private:
    CExtDisplayTestConnectionProvider* iParent;
    TTimeIntervalMicroSeconds32 iInterval;
    };

NONSHARABLE_CLASS(CExtDisplayTestConnectionProvider) : public CExtDisplayConnectionProviderInterface
    {
public:
    static CExtDisplayTestConnectionProvider* NewL();
    ~CExtDisplayTestConnectionProvider();
    
    // Used by CExtDisplayConnectionTimer
    void TimerExpired();
    
    // CExtDisplayConnectionProviderInterface
    void SetExtDisplayConnectionProviderCallback(MExtDisplayConnectionProviderCallback& aCallback);
    TExtDisplayConnectionProviderConnType ExtDisplayConnType();
    TInt ExtDisplayId();
    
private:
    CExtDisplayTestConnectionProvider();
    void ConstructL();
    void ReadConnectionInfoL();
    void InitialiseConnectionChangeTimerL();
    
private:
    MExtDisplayConnectionProviderCallback* iCallback; // not owned
    TExtDisplayConnectionProviderConnType iInitialConnectionType;
    TExtDisplayConnectionProviderConnType iConnectionTypeToBeNotified;
    CExtDisplayConnectionTimer* iExtDisplayConnectionTimer;
    };

#endif /* MMFMEDIACLIENTEXTDISPLAYTESTPROVIDER_H_ */
