C       THIS HANDLES MACRO DIALOG OPERATION FOR THE FIRST MACRO DIALOG

        IF(MESSAGE%WIN.EQ.IDD_MACRO) THEN
        CALL WDIALOGSELECT(IDD_MACRO)
C       MACRO PUSH BUTTONS
           SELECT CASE(MESSAGE%VALUE1)
            CASE (IDOK)
C       GATHER UP DATA AND DO STUFF
        CALL WDialogGetMenu(IDF_MENU1,IOPTION,CVALUE)
        IF(IOPTION.NE.0) CVALUE=MACARRAY(IOPTION)
        CVALUE=TRIM(CVALUE)
        MNAME1=CVALUE(1:8)
        MNAME1=TRIM(MNAME1)
        CALL TOUPPER(MNAME1,8)
        CALL WDIALOGGETSTRING(IDF_TOMAC,CVALUE)
        CVALUE=TRIM(CVALUE)
        MNAME2=CVALUE(1:8)
        MNAME2=TRIM(MNAME2)
        CALL TOUPPER(MNAME2,8)
        CALL WDIALOGGETRADIOBUTTON(IDF_MAC1,ISET)
        SELECT CASE (ISET)
        CASE (1)
        INPUT='MREFRESH'
        CALL PROCES
        INPUT='MFL '//MNAME1
        CALL PROCES
        CALL IOSDELETEFILE('MAC_EDIT.DAT')
        CASE (2)
        INPUT='MREFRESH'
        CALL PROCES
        INPUT='LMEDIT '//MNAME1
        CALL PROCES
        INPUT='FL'
        CALL PROCES
        CALL MACARRAY_LOAD(NUMINLIST)
        CALL WDialogPutMenu(IDF_MENU1,MACARRAY,NUMINLIST,1)
        INPUT='MEDIT '//MNAME1
        CALL PROCES
        CASE (3)
        INPUT='MREFRESH'
        CALL PROCES
        INPUT='MRENAME '//MNAME1//' '//MNAME2
        CALL PROCES
        CALL MACARRAY_LOAD(NUMINLIST)
        CALL WDialogPutMenu(IDF_MENU1,MACARRAY,NUMINLIST,1)
        CALL WDialogShow(-1,-1,0,Modeless)
        CALL IOSDELETEFILE('MAC_EDIT.DAT')
        CASE (4)
        INPUT='MREFRESH'
        CALL PROCES
        INPUT='MCOPY '//MNAME1//' '//MNAME2
        CALL PROCES
        CALL MACARRAY_LOAD(NUMINLIST)
        CALL WDialogPutMenu(IDF_MENU1,MACARRAY,NUMINLIST,1)
        CALL WDialogShow(-1,-1,0,Modeless)
        CALL IOSDELETEFILE('MAC_EDIT.DAT')
        CASE (5)
        INPUT='MREFRESH'
        CALL PROCES
        INPUT=MNAME1
        CALL PROCES
        CALL IOSDELETEFILE('MAC_EDIT.DAT')
        CASE (6)
        INPUT='MREFRESH'
        CALL PROCES
        INPUT='MDEL '//MNAME1
        CALL PROCES
        CALL MACARRAY_LOAD(NUMINLIST)
        CALL WDialogPutMenu(IDF_MENU1,MACARRAY,NUMINLIST,1)
        CALL WDialogShow(-1,-1,0,Modeless)
C       RESET RADIO BUTTON TO LIST AND BLANK OUT MACRO NAME FIELDS
C       FOR SAFTEY
C       CALL WDialogPutString(IDF_TOMAC,'        ')
C       CALL WDialogPutRadioButton(IDF_MAC1)
        CALL WDialogShow(-1,-1,0,Modeless)
        CALL IOSDELETEFILE('MAC_EDIT.DAT')
        END SELECT
        CASE(ID_EXIT)
        INPUT='MREFRESH'
        CALL PROCES
        CALL IOSDELETEFILE('MAC_EDIT.DAT')
        CALL WDialogHide()
        CALL WDialogUnload()
        END SELECT
                        END IF
