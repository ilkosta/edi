#ifndef EDI_MAINVIEW_H_
# define EDI_MAINVIEW_H_

#include <Elementary.h>
#include <Evas.h>

#include "Edi.h"

#include "mainview/edi_mainview_item.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file
 * @brief These routines are used for managing the main area of the Edi interface.
 */

/**
 * @brief UI management functions.
 * @defgroup UI
 *
 * @{
 *
 * Initialisation and management of the main view UI
 *
 */

/**
 * Initialize a new Edi main view and add it to the parent panel.
 *
 * @param parent The parent into which the panel will be loaded.
 * @param win The window the panel will be using
 *
 * @ingroup UI
 */
void edi_mainview_add(Evas_Object *parent, Evas_Object *win);

/**
 * @}
 *
 * 
 * @brief Content management functions.
 * @defgroup Content
 *
 * @{
 *
 * Opening and managing content within the view.
 *
 */

/**
 * Open the file at path for editing using the type specified.
 * Supported types are "text" and "image".
 *
 * @param path The absolute path of the file to open.
 *
 * @ingroup Content
 */
void edi_mainview_open_path(const char *path);

/**
 * Open the file described in the provided options - path and location etc.
 *
 * @param path The path and options of the file to open.
 *
 * @ingroup Content
 */
void edi_mainview_open(Edi_Path_Options *options);

/**
 * Open the file at path for editing in a new window using the type specified.
 * Supported types are "text" and "image".
 * If the path is already open it will be moved to a new window.
 *
 * @param path The absolute path of the file to open.
 *
 * @ingroup Content
 */
void edi_mainview_open_window_path(const char *path);

/**
 * Open the file described in the provided options in a new window - path and location etc.
 *
 * @param path The path and options of the file to open.
 *
 * @ingroup Content
 */
void edi_mainview_open_window(Edi_Path_Options *options);

/**
 * Save the current file.
 *
 * @ingroup Content
 */
void edi_mainview_save();

/**
 * Move the current tab to a new window.
 *
 * @ingroup Content
 */
void edi_mainview_new_window();

/**
 * Close the current file.
 *
 * @ingroup Content
 */
void edi_mainview_close();

/**
 * Cut the current selection into the clipboard.
 *
 * @ingroup Content
 */
void edi_mainview_cut();

/**
 * Copy the current selection into the clipboard.
 *
 * @ingroup Content
 */
void edi_mainview_copy();

/**
 * Paste the current clipboard contents at the current cursor position.
 *
 * @ingroup Content
 */
void edi_mainview_paste();

/**
 * Search the current view's contents.
 *
 * @ingroup Content
 */
void edi_mainview_search();

/**
 * Go to a requested line in the current view's contents.
 *
 * @param line the line number (1 based) to scroll to
 *
 * @ingroup Content
 */
void edi_mainview_goto(int line);

/**
 * Present a popup that will initiate a goto in the current view.
 *
 * @ingroup Content
 */
void edi_mainview_goto_popup_show();

/**
 * @}
 *
 *
 * @brief Tab management functions.
 * @defgroup Tabs
 *
 * @{
 *
 * Manipulating the open files within the application.
 *
 */

Edi_Mainview_Item *edi_mainview_item_current_get();

/**
 * Select the passed item in the mainview UI.
 * By definition this will already be an open file as the Edi_Mainview_Item will
 * only exist for an open item.
 * If this is an external window it will raise that instead of selecting a tab.
 *
 * @ingroup Tabs
 */
void edi_mainview_item_select(Edi_Mainview_Item *item);

/**
 * Select the previous open tab.
 * Previous means the next tab left, if there is one.
 *
 * @ingroup Tabs
 */
void edi_mainview_item_prev();

/**
 * Select the next open tab.
 * Next means the next tab to the right, if there is one.
 *
 * @ingroup Tabs
 */
void edi_mainview_item_next();

/**
 * @}
 *
 */

#ifdef __cplusplus
}
#endif

#endif /* EDI_MAINVIEW_H_ */
