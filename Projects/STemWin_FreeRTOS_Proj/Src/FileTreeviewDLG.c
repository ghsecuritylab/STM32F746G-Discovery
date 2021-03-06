/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "ff.h"
#include <string.h>
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0     (GUI_ID_USER + 0x00)
#define ID_PROGBAR_0     (GUI_ID_USER + 0x02)
#define ID_TREEVIEW_0     GUI_ID_TREEVIEW0

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
DIR MyDirectory;
FILINFO MyFileInfo;
DWORD fre_clust;
FATFS *pfs;

uint64_t TotalSize = 0, FreeSize = 0;
char rtext[24] = {0};
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "FileTreeview", ID_FRAMEWIN_0, 120, 0, 240, 272, 0, 0x0, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_0, 0, 227, 230, 20, 0, 0x0, 0 },
  { TREEVIEW_CreateIndirect, NULL, ID_TREEVIEW_0, 0, 0, 230, 227, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
/*********************************************************************
*
*       _InitTreeview
*
* Purpose:
*   Adds some data to the treeview widget
*/
static void _InitTreeview(WM_HWIN hTree)
{
	TREEVIEW_ITEM_Handle hItem, hNode;
	FRESULT res;
	hNode = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, 0,     0,                           "0:/");
	res = f_opendir(&MyDirectory, "/");
	if(res == FR_OK)
	{
		for(;;)
		{
			res = f_readdir(&MyDirectory, &MyFileInfo);
			if(res != FR_OK || MyFileInfo.fname[0] == 0) break;
//			if(MyFileInfo.fname[0] == '.') continue;
			if(!(MyFileInfo.fattrib & AM_DIR))
			{
//				hNode = TREEVIEW_GetItem(hTree, 0,     TREEVIEW_GET_FIRST);
				hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hNode, TREEVIEW_INSERT_FIRST_CHILD, (const char *)MyFileInfo.fname);
			}
			else
			{
				hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, hNode, TREEVIEW_INSERT_FIRST_CHILD, (const char *)MyFileInfo.fname);
				TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_FIRST_CHILD, "");
			}
		}
	}
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, hNode, TREEVIEW_INSERT_FIRST_CHILD, "Pictures");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, hItem, TREEVIEW_INSERT_BELOW,       "Movies");
//	hNode = TREEVIEW_GetItem(hTree, 0,     TREEVIEW_GET_FIRST);
//	hNode = TREEVIEW_GetItem(hTree, hNode, TREEVIEW_GET_FIRST_CHILD);
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, hNode, TREEVIEW_INSERT_FIRST_CHILD, "BMP");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, hItem, TREEVIEW_INSERT_BELOW,       "GIF");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, hItem, TREEVIEW_INSERT_BELOW,       "JPEG");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_NODE, hItem, TREEVIEW_INSERT_BELOW,       "PNG");
//	hNode = TREEVIEW_GetItem(hTree, hNode, TREEVIEW_GET_FIRST_CHILD);
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hNode, TREEVIEW_INSERT_FIRST_CHILD, "Cat.bmp");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_BELOW,       "Dog.bmp");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_BELOW,       "Frog.bmp");
//	hNode = TREEVIEW_GetItem(hTree, hNode, TREEVIEW_GET_NEXT_SIBLING);
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hNode, TREEVIEW_INSERT_FIRST_CHILD, "Flowchart.gif");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_BELOW,       "Projects.gif");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_BELOW,       "Interlaced.gif");
//	hNode = TREEVIEW_GetItem(hTree, hNode, TREEVIEW_GET_NEXT_SIBLING);
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hNode, TREEVIEW_INSERT_FIRST_CHILD, "Tree.jpeg");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_BELOW,       "Nature.jpeg");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_BELOW,       "Paul.jpeg");
//	hNode = TREEVIEW_GetItem(hTree, hNode, TREEVIEW_GET_NEXT_SIBLING);
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hNode, TREEVIEW_INSERT_FIRST_CHILD, "Parrot.png");
//	hNode = TREEVIEW_GetItem(hTree, hNode, TREEVIEW_GET_PARENT);
//	hNode = TREEVIEW_GetItem(hTree, hNode, TREEVIEW_GET_NEXT_SIBLING);
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hNode, TREEVIEW_INSERT_FIRST_CHILD, "Smilie.gif");
//	hItem = TREEVIEW_InsertItem(hTree, TREEVIEW_ITEM_TYPE_LEAF, hItem, TREEVIEW_INSERT_BELOW,       "Cats.gif");
	TREEVIEW_SetAutoScrollH(hTree, 1);
	TREEVIEW_SetAutoScrollV(hTree, 1);
	TREEVIEW_ITEM_Expand(TREEVIEW_GetItem(hTree, 0, TREEVIEW_GET_FIRST));
	WM_SetFocus(hTree);
}
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN                hItem;
  int                    NCode;
  int                    Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'FileTreeview'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of 'uSD'
    //
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TREEVIEW_0);
	_InitTreeview(hItem);
    // USER START (Optionally insert additional code for further widget initialization)
	if(f_getfree("/", &fre_clust, &pfs) == FR_OK)
	{
		TotalSize = (pfs->n_fatent - 2) * pfs->csize/2;//unit:byte.
		FreeSize = fre_clust * pfs->csize/2;//unit:byte.
	}
	hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
	PROGBAR_SetMinMax(hItem, 0, TotalSize);
	PROGBAR_SetValue(hItem, TotalSize - FreeSize);
	sprintf(rtext, "%2.2f%%(%2.2fMB/%2.2fMB)", ((float)(TotalSize - FreeSize) / (float)TotalSize) * 100, (float)(TotalSize - FreeSize) / 1024, (float)TotalSize / 1024);
	PROGBAR_SetText(hItem, (const char *)rtext);
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_TREEVIEW_0: // Notifications sent by 'uSD'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateFileTreeview
*/
WM_HWIN CreateFileTreeview(void);
WM_HWIN CreateFileTreeview(void)
{
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	FRAMEWIN_AddCloseButton(hWin, FRAMEWIN_BUTTON_RIGHT, 0);
//	FRAMEWIN_SetMoveable(hWin, 1);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
