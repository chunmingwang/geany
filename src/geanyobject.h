/*
 *      geanyobject.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2007 The Geany contributors
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along
 *      with this program; if not, write to the Free Software Foundation, Inc.,
 *      51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#ifndef GEANY_OBJECT_H
#define GEANY_OBJECT_H 1

#include "document.h"
#include "editor.h"
#include "filetypes.h"

#include "Scintilla.h"

#include "gtkcompat.h"


G_BEGIN_DECLS

typedef enum
{
	GCB_DOCUMENT_NEW,
	GCB_DOCUMENT_OPEN,
	GCB_DOCUMENT_RELOAD,
	GCB_DOCUMENT_BEFORE_SAVE,
	GCB_DOCUMENT_SAVE,
	GCB_DOCUMENT_FILETYPE_SET,
	GCB_DOCUMENT_ACTIVATE,
	GCB_DOCUMENT_CLOSE,
	GCB_PROJECT_OPEN,
	GCB_PROJECT_SAVE,
	GCB_PROJECT_CLOSE,
	GCB_PROJECT_BEFORE_CLOSE,
	GCB_PROJECT_DIALOG_OPEN,
	GCB_PROJECT_DIALOG_CONFIRMED,
	GCB_PROJECT_DIALOG_CLOSE,
	GCB_UPDATE_EDITOR_MENU,
	GCB_EDITOR_NOTIFY,
	GCB_GEANY_STARTUP_COMPLETE,
	GCB_BUILD_START,
	GCB_SAVE_SETTINGS,
	GCB_LOAD_SETTINGS,
	GCB_KEY_PRESS_NOTIFY,
	GCB_DOCUMENT_BEFORE_SAVE_AS,
	GCB_GEANY_BEFORE_QUIT,
	GCB_MAX
}
GeanyCallbackId;


#define GEANY_OBJECT_TYPE				(geany_object_get_type())
#define GEANY_OBJECT(obj)				(G_TYPE_CHECK_INSTANCE_CAST((obj),\
		GEANY_OBJECT_TYPE, GeanyObject))
#define GEANY_OBJECT_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST((klass),\
		GEANY_OBJECT_TYPE, GeanyObjectClass))
#define IS_GEANY_OBJECT(obj)				(G_TYPE_CHECK_INSTANCE_TYPE((obj),\
		GEANY_OBJECT_TYPE))
#define IS_GEANY_OBJECT_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE((klass),\
		GEANY_OBJECT_TYPE))

typedef struct _GeanyObject				GeanyObject;
typedef struct _GeanyObjectClass			GeanyObjectClass;

/** @gironly
 * Instance structure for GeanyObject */
struct _GeanyObject
{
	GObject parent;
	/* add your public declarations here */
};

extern GObject *geany_object;

/** @gironly
 * Class structure for @a GeanyObject */
struct _GeanyObjectClass
{
	GObjectClass parent_class;
};

GType		geany_object_get_type	(void);
GObject*	geany_object_new		(void);

G_END_DECLS

#endif /* GEANY_OBJECT_H */
