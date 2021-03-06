rem Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

del E:\Logs\TestResults\TSI_ICL_FRM_FS.*
md E:\Logs\
md E:\Logs\TestResults\

REM ***********************************************
REM ***************** FRM TESTS *******************
REM ***********************************************

md c:\ICL\
md c:\ICL\TestImages\
md c:\ICL\RefImages\

copy z:\ICL\TSI_ICL_FRM_00.ini c:\ICL\TSI_ICL_FRM_00.ini

copy E:\inttest\icl\testimages\jfif444_8.jpg c:\ICL\TestImages\jfif444_8.jpg
copy E:\inttest\icl\refimages\jfif444_8.mbm c:\ICL\RefImages\jfif444_8.mbm
copy E:\inttest\icl\testimages\jfif444.jpg c:\ICL\TestImages\jfif444.jpg
copy E:\inttest\icl\testimages\jfif444.drm c:\ICL\TestImages\jfif444.drm
copy E:\inttest\icl\refimages\jfif444.mbm c:\ICL\RefImages\jfif444.mbm
copy E:\inttest\icl\testimages\trans_1.gif c:\ICL\TestImages\trans_1.gif
copy E:\inttest\icl\testimages\trans_8.gif c:\ICL\TestImages\trans_8.gif
copy E:\inttest\icl\refimages\trans_1.mbm c:\ICL\RefImages\trans_1.mbm
copy E:\inttest\icl\refimages\trans_8.mbm c:\ICL\RefImages\trans_8.mbm
copy E:\inttest\icl\testimages\bmp8bpp_8.bmp c:\ICL\TestImages\bmp8bpp_8.bmp
copy E:\inttest\icl\refimages\bmp8bpp_8.mbm c:\ICL\RefImages\bmp8bpp_8.mbm
copy E:\inttest\icl\testimages\operator.ota c:\ICL\TestImages\operator.ota
copy E:\inttest\icl\testimages\operator.drm c:\ICL\TestImages\operator.drm
copy E:\inttest\icl\refimages\operator.mbm c:\ICL\RefImages\operator.mbm
copy E:\inttest\icl\testimages\sun.wbmp c:\ICL\TestImages\sun.wbmp
copy E:\inttest\icl\refimages\sun.mbm c:\ICL\RefImages\sun.mbm
copy E:\inttest\icl\testimages\png4_8.png c:\ICL\TestImages\png4_8.png
copy E:\inttest\icl\refimages\png4_8.mbm c:\ICL\RefImages\png4_8.mbm
copy E:\inttest\icl\testimages\tif3_4.tif c:\ICL\TestImages\tif3_4.tif
copy E:\inttest\icl\refimages\tif3_4.mbm c:\ICL\RefImages\tif3_4.mbm
copy E:\inttest\icl\testimages\wmf3_8.wmf c:\ICL\TestImages\wmf3_8.wmf
copy E:\inttest\icl\refimages\wmf3_8.mbm c:\ICL\RefImages\wmf3_8.mbm
copy E:\inttest\icl\testimages\icoepoc.ico c:\ICL\TestImages\icoepoc.ico
copy E:\inttest\icl\refimages\icoepoc.mbm c:\ICL\RefImages\icoepoc.mbm
copy E:\inttest\icl\testimages\jfif444_8_cropped.jpg c:\ICL\TestImages\jfif444_8_cropped.jpg
copy E:\inttest\icl\refimages\mbm24bpp_4.mbm c:\ICL\RefImages\mbm24bpp_4.mbm
copy E:\inttest\icl\testimages\mbm24bpp_4.mbm c:\ICL\TestImages\mbm24bpp_4.mbm
copy E:\inttest\icl\testimages\back.gif c:\ICL\TestImages\back.gif
copy E:\inttest\icl\testimages\clock.gif c:\ICL\TestImages\clock.gif
copy E:\inttest\icl\testimages\jfif444_8.bmp c:\ICL\TestImages\jfif444_8.bmp
copy E:\inttest\icl\refimages\minimum.mbm c:\ICL\RefImages\minimum.mbm
copy E:\inttest\icl\testimages\drmstub.drm c:\ICL\TestImages\drmstub.drm
copy E:\inttest\icl\testimages\textfile.jpg C:\ICL\TestImages\textfile.jpg
copy E:\inttest\icl\refimages\textfile.mbm C:\ICL\RefImages\textfile.mbm
copy E:\inttest\icl\testimages\img_1705.jpg C:\ICL\TestImages\img_1705.jpg
copy E:\inttest\icl\refimages\img_1705.mbm C:\ICL\RefImages\img_1705.mbm

testframework -q TSI_ICL_FRM_FS.script

move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

del c:\icl\testimages\*.*
del c:\icl\refimages\*.*
del c:\icl\*.*