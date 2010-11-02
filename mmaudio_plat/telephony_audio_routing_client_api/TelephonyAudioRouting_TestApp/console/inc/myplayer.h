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
* Description:  Console Myplayer
*
*/

#if 0
#include <MdaAudioSamplePlayer.h> 

_LIT(KWavFile, "c:\\sounds\\digital\\sample.wav");


class CMyPlayer : public CBase, MMdaAudioPlayerCallback 
    {
public:
    static CMyPlayer* NewL();
    void ConstructL();
    void Play();
public:
    virtual void MapcInitComplete(TInt aError, const TTimeIntervalMicroSeconds &aDuration);
    virtual void MapcPlayComplete(TInt aError);
    
private:
    CMdaAudioPlayerUtility* iPlayer;
    };


CMyPlayer* CMyPlayer::NewL()
    {
    CMyPlayer* self = new(ELeave) CMyPlayer;
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(self);
    }
void CMyPlayer::ConstructL()
    {
    iPlayer = CMdaAudioPlayerUtility::NewL(*this);
    iPlayer->OpenFileL(KWavFile);
    }
void CMyPlayer::Play()
    {
    iPlayer->Play();
    }
void CMyPlayer::MapcInitComplete(TInt aError, const TTimeIntervalMicroSeconds &aDuration)
    {
    console->Printf(_L("Init complete with err = %d\n"), aError);
    }
void CMyPlayer::MapcPlayComplete(TInt aError)
    {
    console->Printf(_L("play complete with err = %d\n"), aError);
    }
#endif
