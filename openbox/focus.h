#ifndef __focus_h
#define __focus_h

#include <X11/Xlib.h>
#include <glib.h>

struct Client;

/*! The window which gets focus when nothing else will be focused */
extern Window focus_backup;

/*! The client which is currently focused */
extern struct Client *focus_client;

/* The number of FocusIn events which should be ignored for tracking the focus
   order */
extern int focus_ignore_in;

/*! The recent focus order on each desktop */
extern GList **focus_order;

/*! Should new windows be focused */
extern gboolean focus_new;
/*! Should focus follow the mouse pointer */
extern gboolean focus_follow;

void focus_startup();
void focus_shutdown();

/*! Specify which client is currently focused, this doesn't actually
  send focus anywhere, its called by the Focus event handlers */
void focus_set_client(struct Client *client);

/*! Call this when you need to focus something! */
void focus_fallback(gboolean switching_desks);

#endif
