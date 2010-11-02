/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  TelephonyAudioRouting Test Application
*
*/


#ifndef __MYPLAYER_PAN__
#define __MYPLAYER_PAN__

/** MyPlayer application panic codes */
enum TMyPlayerPanics
    {
    EMyPlayerUi = 1
    // add further panics here
    };

inline void Panic(TMyPlayerPanics aReason)
    {
    _LIT(applicationName, "MyPlayer");
    User::Panic(applicationName, aReason);
    }

#endif // __MYPLAYER_PAN__
