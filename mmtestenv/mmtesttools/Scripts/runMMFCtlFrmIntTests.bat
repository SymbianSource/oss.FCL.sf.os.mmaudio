rem Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
rem All rights reserved.
rem This component and the accompanying materials are made available
rem under the terms of "Eclipse Public License v1.0"
rem which accompanies this distribution, and is available
rem at the URL "http://www.eclipse.org/legal/epl-v10.html".
rem
rem Initial Contributors:
rem Nokia Corporation - initial contribution.
rem
rem Contributors:
rem
rem Description:
rem

del E:\Logs\TestResults\TSI_MMF_CTLFRM.htm
del E:\Logs\TestResults\TSI_MMF_CTLFRM_PREEMPTION.htm
md E:\Logs\
md E:\Logs\TestResults\

REM ***********************************************
REM ***************** CTLFRM TESTS ****************
REM ***********************************************

md c:\TsiMmfCtlfrmData\

copy E:\inttest\MMF\TsiMmfCtlfrmData\test.wav c:\TsiMmfCtlfrmData\test.wav
copy E:\inttest\MMF\TsiMmfCtlfrmData\test2.wav c:\TsiMmfCtlfrmData\test2.wav

testframework TSI_MMF_CTLFRM.script

move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

testframework TSI_MMF_CTLFRM_PREEMPTION.script

move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

del c:\TsiMmfCtlfrmData\*.*