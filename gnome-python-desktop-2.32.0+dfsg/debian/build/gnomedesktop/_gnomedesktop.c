/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#define PY_SSIZE_T_CLEAN
#include <Python.h>




#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
typedef inquiry lenfunc;
typedef intargfunc ssizeargfunc;
typedef intobjargproc ssizeobjargproc;
#endif


#line 4 "_gnomedesktop.override"
#include <Python.h>

#define NO_IMPORT_PYGOBJECT
#include "pygobject.h"
#include <libgnome/gnome-desktop-item.h>

#include "config.h"

/*
 This wrapper does not free the string in the list, just the list itself
 */
static PyObject *
_helper_wrap_string_glist (GList *list)
{
    GList *tmp;
    PyObject *py_list;

    if ((py_list = PyList_New(0)) == NULL) {
        g_list_free(list);
        return NULL;
    }
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        PyObject *str_obj =  PyString_FromString ((char*)tmp->data);

        if (str_obj == NULL) {
            g_list_free(list);
            Py_DECREF(py_list);
            return NULL;
        }
        PyList_Append(py_list, str_obj);
        Py_DECREF(str_obj);
    }
    g_list_free(list);
    return py_list;
}

static PyObject *
_helper_wrap_string_array (char **strings)
{
    int i;
    PyObject *py_list;

    if ((py_list = PyList_New(0)) == NULL) {
        return NULL;
    }
    
    for (i = 0; strings[i] != NULL; i++) {
        PyObject *str_obj =  PyString_FromString (strings[i]);

        if (str_obj == NULL) {
            Py_DECREF(py_list);
            return NULL;
        }
        PyList_Append(py_list, str_obj);
        Py_DECREF(str_obj);
    }
    return py_list;
}

#line 80 "_gnomedesktop.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGtkIconTheme_Type;
#define PyGtkIconTheme_Type (*_PyGtkIconTheme_Type)
static PyTypeObject *_PyGdkScreen_Type;
#define PyGdkScreen_Type (*_PyGdkScreen_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyGnomeDesktopItem_Type;

#line 93 "_gnomedesktop.c"



/* ----------- GnomeDesktopItem ----------- */

static int
_wrap_gnome_desktop_item_new(PyGBoxed *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,":GnomeDesktopItem.DesktopItem.__init__", kwlist))
        return -1;
    self->gtype = GNOME_TYPE_DESKTOP_ITEM;
    self->free_on_dealloc = FALSE;
    self->boxed = gnome_desktop_item_new();

    if (!self->boxed) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GnomeDesktopItem object");
        return -1;
    }
    self->free_on_dealloc = TRUE;
    return 0;
}

static PyObject *
_wrap_gnome_desktop_item_copy(PyObject *self)
{
    GnomeDesktopItem *ret;

    
    ret = gnome_desktop_item_copy(pyg_boxed_get(self, GnomeDesktopItem));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GNOME_TYPE_DESKTOP_ITEM, ret, TRUE, TRUE);
}

static PyObject *
_wrap_gnome_desktop_item_save(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "under", "force", NULL };
    char *under;
    int force, ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:GnomeDesktopItem.DesktopItem.save", kwlist, &under, &force))
        return NULL;
    
    ret = gnome_desktop_item_save(pyg_boxed_get(self, GnomeDesktopItem), under, force, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gnome_desktop_item_ref(PyObject *self)
{
    GnomeDesktopItem *ret;

    
    ret = gnome_desktop_item_ref(pyg_boxed_get(self, GnomeDesktopItem));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GNOME_TYPE_DESKTOP_ITEM, ret, TRUE, TRUE);
}

static PyObject *
_wrap_gnome_desktop_item_unref(PyObject *self)
{
    
    gnome_desktop_item_unref(pyg_boxed_get(self, GnomeDesktopItem));
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 194 "_gnomedesktop.override"
static PyObject *
_wrap_gnome_desktop_item_launch (PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char  *kwlist[] = { "file_list", "flags", "env", NULL };
    
    PyObject   *pyfile_list;
    PyObject   *pyenv = Py_None;
    GnomeDesktopItemLaunchFlags flags = 0;
    int         i;
    int         n_files = 0;
    GList      *files = NULL;
    int         n_env = 0;
    char      **envp = NULL;
    GError     *error = NULL;
    int         result;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O|iO:GnomeDesktopItem.launch", kwlist,
                                     &pyfile_list, &flags, &pyenv)) {
        return NULL;
    }

    if (!PyList_Check(pyfile_list) && !PyTuple_Check(pyfile_list)) {
        PyErr_SetString(PyExc_TypeError, "1st argument not a tuple or list");
        return NULL;
    }
           
    n_files = PySequence_Length(pyfile_list);
    for (i = 0; i < n_files; i++) {
        PyObject *item = PySequence_GetItem(pyfile_list, i);
        Py_DECREF(item); 
        files = g_list_append (files, PyString_AsString(item));
    }
    
    if (pyenv != Py_None) {
        if (!PyList_Check(pyenv) && !PyTuple_Check(pyenv)) {
            PyErr_SetString(PyExc_TypeError, "3rd argument not a tuple or list");
            return NULL;
        }
    
        n_env = PySequence_Length(pyenv);
        envp = g_new(gchar *, n_env + 1);
        for (i = 0; i < n_env; i++) {
            PyObject *item = PySequence_GetItem(pyenv, i);
            Py_DECREF(item); 
            envp[i] = PyString_AsString(item);
        }
        envp[n_env] = NULL;
        
        result = gnome_desktop_item_launch_with_env (
                            pyg_boxed_get(self, GnomeDesktopItem),
                            files,
                            flags,
                            envp,
                            &error);
    }
    else {
        result = gnome_desktop_item_launch (
                            pyg_boxed_get(self, GnomeDesktopItem),
                            files,
                            flags,
                            &error);
    }
    g_free (envp);
    g_list_free (files);
    
    if (pyg_error_check(&error))
        return NULL;
        
    return PyInt_FromLong(result);
}
#line 243 "_gnomedesktop.c"


#line 267 "_gnomedesktop.override"
static PyObject *
_wrap_gnome_desktop_item_launch_on_screen (PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char  *kwlist[] = { "file_list", "flags", "screen", "workspace", NULL };
    
    PyObject   *pyfile_list;
    PyObject   *pyscreen;
    GnomeDesktopItemLaunchFlags flags = 0;
    int workspace;
    
    int         i;
    int         n_files = 0;
    GList      *files = NULL;
    GError     *error = NULL;
    int         result;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "OiOi:GnomeDesktopItem.launch", kwlist,
                                     &pyfile_list, &flags, &PyGdkScreen_Type, &pyscreen, &workspace)) {
        return NULL;
    }

    if (!PyList_Check(pyfile_list) && !PyTuple_Check(pyfile_list)) {
        PyErr_SetString(PyExc_TypeError, "1st argument not a tuple or list");
        return NULL;
    }
            
    n_files = PySequence_Length(pyfile_list);
    for (i = 0; i < n_files; i++) {
        PyObject *item = PySequence_GetItem(pyfile_list, i);
        Py_DECREF(item); 
        files = g_list_append (files, PyString_AsString(item));
    }
        
    result = gnome_desktop_item_launch_on_screen (
                        pyg_boxed_get(self, GnomeDesktopItem),
                        files,
                        flags,
                        GDK_SCREEN (pygobject_get (pyscreen)),
                        workspace,
                        &error);
    
    g_list_free (files);
    if (pyg_error_check(&error))
        return NULL;
        
    return PyInt_FromLong(result);
}
#line 295 "_gnomedesktop.c"


#line 150 "_gnomedesktop.override"
static PyObject *
_wrap_gnome_desktop_item_drop_uri_list (PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri_list", "flags", "env", NULL };
    char       *uri_list;
    GnomeDesktopItemLaunchFlags flags = 0;
    PyObject   *pyenv = Py_None;
    int         n_env = 0;
    char      **envp = NULL;
    GError     *error = NULL;
    int i;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|iO:GnomeDesktopItem.drop_uri_list", kwlist,
                                                    &uri_list, &flags, &pyenv))
        return NULL;
    
    if (pyenv != Py_None) {
        if (!PyList_Check(pyenv) && !PyTuple_Check(pyenv)) {
            PyErr_SetString(PyExc_TypeError, "3rd argument not a tuple or list");
            return NULL;
        }
    
        n_env = PySequence_Length(pyenv);
        envp = g_new(gchar *, n_env + 1);
        for (i = 0; i < n_env; i++) {
            PyObject *item = PySequence_GetItem(pyenv, i);
            Py_DECREF(item); 
            envp[i] = PyString_AsString(item);
        }
        envp[n_env] = NULL;
        ret = gnome_desktop_item_drop_uri_list_with_env (pyg_boxed_get(self, GnomeDesktopItem), uri_list, flags, envp, &error);
    }
    else {
        ret = gnome_desktop_item_drop_uri_list (pyg_boxed_get(self, GnomeDesktopItem), uri_list, flags, &error);
    }
    g_free (envp);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyInt_FromLong(ret);
}
#line 341 "_gnomedesktop.c"


static PyObject *
_wrap_gnome_desktop_item_exists(PyObject *self)
{
    int ret;

    
    ret = gnome_desktop_item_exists(pyg_boxed_get(self, GnomeDesktopItem));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gnome_desktop_item_get_entry_type(PyObject *self)
{
    int ret;

    
    ret = gnome_desktop_item_get_entry_type(pyg_boxed_get(self, GnomeDesktopItem));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gnome_desktop_item_set_entry_type(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", NULL };
    int type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:GnomeDesktopItem.DesktopItem.set_entry_type", kwlist, &type))
        return NULL;
    
    gnome_desktop_item_set_entry_type(pyg_boxed_get(self, GnomeDesktopItem), type);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_get_location(PyObject *self)
{
    const gchar *ret;

    
    ret = gnome_desktop_item_get_location(pyg_boxed_get(self, GnomeDesktopItem));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_set_location(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "location", NULL };
    char *location;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.set_location", kwlist, &location))
        return NULL;
    
    gnome_desktop_item_set_location(pyg_boxed_get(self, GnomeDesktopItem), location);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_set_location_file(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "file", NULL };
    char *file;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.set_location_file", kwlist, &file))
        return NULL;
    
    gnome_desktop_item_set_location_file(pyg_boxed_get(self, GnomeDesktopItem), file);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_get_file_status(PyObject *self)
{
    int ret;

    
    ret = gnome_desktop_item_get_file_status(pyg_boxed_get(self, GnomeDesktopItem));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gnome_desktop_item_get_icon(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "icon_theme", NULL };
    PyGObject *icon_theme;
    gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:GnomeDesktopItem.DesktopItem.get_icon", kwlist, &PyGtkIconTheme_Type, &icon_theme))
        return NULL;
    
    ret = gnome_desktop_item_get_icon(pyg_boxed_get(self, GnomeDesktopItem), GTK_ICON_THEME(icon_theme->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_attr_exists(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char *attr;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.attr_exists", kwlist, &attr))
        return NULL;
    
    ret = gnome_desktop_item_attr_exists(pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gnome_desktop_item_get_string(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char *attr;
    const gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.get_string", kwlist, &attr))
        return NULL;
    
    ret = gnome_desktop_item_get_string(pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_set_string(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", "value", NULL };
    char *attr, *value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:GnomeDesktopItem.DesktopItem.set_string", kwlist, &attr, &value))
        return NULL;
    
    gnome_desktop_item_set_string(pyg_boxed_get(self, GnomeDesktopItem), attr, value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_get_attr_locale(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char *attr;
    const gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.get_attr_locale", kwlist, &attr))
        return NULL;
    
    ret = gnome_desktop_item_get_attr_locale(pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_get_localestring(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char *attr;
    const gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.get_localestring", kwlist, &attr))
        return NULL;
    
    ret = gnome_desktop_item_get_localestring(pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_get_localestring_lang(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", "language", NULL };
    char *attr, *language;
    const gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:GnomeDesktopItem.DesktopItem.get_localestring_lang", kwlist, &attr, &language))
        return NULL;
    
    ret = gnome_desktop_item_get_localestring_lang(pyg_boxed_get(self, GnomeDesktopItem), attr, language);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

#line 76 "_gnomedesktop.override"
static PyObject *
_wrap_gnome_desktop_item_get_languages (PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char        *attr;
    GList       *langs;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s:GnomeDesktopItem.get_languages", kwlist, &attr))
        return NULL;
    
    langs = gnome_desktop_item_get_languages (pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    return _helper_wrap_string_glist (langs);
}
#line 576 "_gnomedesktop.c"


static PyObject *
_wrap_gnome_desktop_item_set_localestring(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", "value", NULL };
    char *attr, *value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:GnomeDesktopItem.DesktopItem.set_localestring", kwlist, &attr, &value))
        return NULL;
    
    gnome_desktop_item_set_localestring(pyg_boxed_get(self, GnomeDesktopItem), attr, value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_set_localestring_lang(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", "language", "value", NULL };
    char *attr, *language, *value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sss:GnomeDesktopItem.DesktopItem.set_localestring_lang", kwlist, &attr, &language, &value))
        return NULL;
    
    gnome_desktop_item_set_localestring_lang(pyg_boxed_get(self, GnomeDesktopItem), attr, language, value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_clear_localestring(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char *attr;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.clear_localestring", kwlist, &attr))
        return NULL;
    
    gnome_desktop_item_clear_localestring(pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 92 "_gnomedesktop.override"
static PyObject *
_wrap_gnome_desktop_item_get_strings (PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char        *attr;
    char       **strings;
    PyObject    *ret;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s:GnomeDesktopItem.get_strings", kwlist, &attr))
        return NULL;
    
    strings = gnome_desktop_item_get_strings (pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    ret = _helper_wrap_string_array (strings);
    /* FIXME: The doc says to: gnome_desktop_item_free_string_list (strings);
       But this function does not exists, using g_strfreev.. */
    g_strfreev (strings);
    
    return ret;
}
#line 645 "_gnomedesktop.c"


#line 114 "_gnomedesktop.override"
static PyObject *
_wrap_gnome_desktop_item_set_strings (PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", "strings", NULL };
    char        *attr;
    PyObject   *pystrings;
    int         i;
    int         n_strings = 0;
    char       **strings;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "sO:GnomeDesktopItem.set_strings", kwlist, &attr, &pystrings))
        return NULL;
    
    if (!PyList_Check(pystrings) && !PyTuple_Check(pystrings)) {
        PyErr_SetString(PyExc_TypeError, "2nd argument not a tuple or list");
        return NULL;
    }

    n_strings = PySequence_Length(pystrings);
    strings = g_new(gchar *, n_strings + 1);
    for (i = 0; i < n_strings; i++) {
        PyObject *item = PySequence_GetItem(pystrings, i);
        Py_DECREF(item); 
        strings[i] = PyString_AsString(item);
    }
    strings[n_strings] = NULL;
        
    gnome_desktop_item_set_strings (pyg_boxed_get(self, GnomeDesktopItem), attr, strings);
    
    g_free (strings);
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 683 "_gnomedesktop.c"


static PyObject *
_wrap_gnome_desktop_item_get_boolean(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", NULL };
    char *attr;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.get_boolean", kwlist, &attr))
        return NULL;
    
    ret = gnome_desktop_item_get_boolean(pyg_boxed_get(self, GnomeDesktopItem), attr);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gnome_desktop_item_set_boolean(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "attr", "value", NULL };
    char *attr;
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:GnomeDesktopItem.DesktopItem.set_boolean", kwlist, &attr, &value))
        return NULL;
    
    gnome_desktop_item_set_boolean(pyg_boxed_get(self, GnomeDesktopItem), attr, value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_set_launch_time(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "timestamp", NULL };
    unsigned long timestamp;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:GnomeDesktopItem.DesktopItem.set_launch_time", kwlist, &timestamp))
        return NULL;
    
    gnome_desktop_item_set_launch_time(pyg_boxed_get(self, GnomeDesktopItem), timestamp);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_desktop_item_clear_section(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "section", NULL };
    char *section;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GnomeDesktopItem.DesktopItem.clear_section", kwlist, &section))
        return NULL;
    
    gnome_desktop_item_clear_section(pyg_boxed_get(self, GnomeDesktopItem), section);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGnomeDesktopItem_methods[] = {
    { "copy", (PyCFunction)_wrap_gnome_desktop_item_copy, METH_NOARGS,
      NULL },
    { "save", (PyCFunction)_wrap_gnome_desktop_item_save, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "ref", (PyCFunction)_wrap_gnome_desktop_item_ref, METH_NOARGS,
      NULL },
    { "unref", (PyCFunction)_wrap_gnome_desktop_item_unref, METH_NOARGS,
      NULL },
    { "launch", (PyCFunction)_wrap_gnome_desktop_item_launch, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "launch_on_screen", (PyCFunction)_wrap_gnome_desktop_item_launch_on_screen, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "drop_uri_list", (PyCFunction)_wrap_gnome_desktop_item_drop_uri_list, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "exists", (PyCFunction)_wrap_gnome_desktop_item_exists, METH_NOARGS,
      NULL },
    { "get_entry_type", (PyCFunction)_wrap_gnome_desktop_item_get_entry_type, METH_NOARGS,
      NULL },
    { "set_entry_type", (PyCFunction)_wrap_gnome_desktop_item_set_entry_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_location", (PyCFunction)_wrap_gnome_desktop_item_get_location, METH_NOARGS,
      NULL },
    { "set_location", (PyCFunction)_wrap_gnome_desktop_item_set_location, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_location_file", (PyCFunction)_wrap_gnome_desktop_item_set_location_file, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_file_status", (PyCFunction)_wrap_gnome_desktop_item_get_file_status, METH_NOARGS,
      NULL },
    { "get_icon", (PyCFunction)_wrap_gnome_desktop_item_get_icon, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "attr_exists", (PyCFunction)_wrap_gnome_desktop_item_attr_exists, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_string", (PyCFunction)_wrap_gnome_desktop_item_get_string, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_string", (PyCFunction)_wrap_gnome_desktop_item_set_string, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_attr_locale", (PyCFunction)_wrap_gnome_desktop_item_get_attr_locale, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_localestring", (PyCFunction)_wrap_gnome_desktop_item_get_localestring, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_localestring_lang", (PyCFunction)_wrap_gnome_desktop_item_get_localestring_lang, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_languages", (PyCFunction)_wrap_gnome_desktop_item_get_languages, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_localestring", (PyCFunction)_wrap_gnome_desktop_item_set_localestring, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_localestring_lang", (PyCFunction)_wrap_gnome_desktop_item_set_localestring_lang, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "clear_localestring", (PyCFunction)_wrap_gnome_desktop_item_clear_localestring, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_strings", (PyCFunction)_wrap_gnome_desktop_item_get_strings, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_strings", (PyCFunction)_wrap_gnome_desktop_item_set_strings, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_boolean", (PyCFunction)_wrap_gnome_desktop_item_get_boolean, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_boolean", (PyCFunction)_wrap_gnome_desktop_item_set_boolean, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_launch_time", (PyCFunction)_wrap_gnome_desktop_item_set_launch_time, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "clear_section", (PyCFunction)_wrap_gnome_desktop_item_clear_section, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGnomeDesktopItem_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gnomedesktop.DesktopItem",                   /* tp_name */
    sizeof(PyGBoxed),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGnomeDesktopItem_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_gnome_desktop_item_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_gnome_desktop_item_new_from_file(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "file", "flags", NULL };
    char *file;
    int flags;
    GError *error = NULL;
    GnomeDesktopItem *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:item_new_from_file", kwlist, &file, &flags))
        return NULL;
    
    ret = gnome_desktop_item_new_from_file(file, flags, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GNOME_TYPE_DESKTOP_ITEM, ret, FALSE, TRUE);
}

static PyObject *
_wrap_gnome_desktop_item_new_from_uri(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "flags", NULL };
    char *uri;
    int flags;
    GError *error = NULL;
    GnomeDesktopItem *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:item_new_from_uri", kwlist, &uri, &flags))
        return NULL;
    
    ret = gnome_desktop_item_new_from_uri(uri, flags, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GNOME_TYPE_DESKTOP_ITEM, ret, FALSE, TRUE);
}

static PyObject *
_wrap_gnome_desktop_item_new_from_string(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "string", "length", "flags", NULL };
    char *uri, *string;
    int flags;
    GnomeDesktopItem *ret;
    GError *error = NULL;
    gssize length;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ssli:item_new_from_string", kwlist, &uri, &string, &length, &flags))
        return NULL;
    
    ret = gnome_desktop_item_new_from_string(uri, string, length, flags, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GNOME_TYPE_DESKTOP_ITEM, ret, FALSE, TRUE);
}

static PyObject *
_wrap_gnome_desktop_item_new_from_basename(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "basename", "flags", NULL };
    char *basename;
    int flags;
    GError *error = NULL;
    GnomeDesktopItem *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:item_new_from_basename", kwlist, &basename, &flags))
        return NULL;
    
    ret = gnome_desktop_item_new_from_basename(basename, flags, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GNOME_TYPE_DESKTOP_ITEM, ret, FALSE, TRUE);
}

static PyObject *
_wrap_gnome_desktop_item_find_icon(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "icon_theme", "icon", "desired_size", "flags", NULL };
    PyGObject *icon_theme;
    char *icon;
    int desired_size, flags;
    gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!sii:find_icon", kwlist, &PyGtkIconTheme_Type, &icon_theme, &icon, &desired_size, &flags))
        return NULL;
    
    ret = gnome_desktop_item_find_icon(GTK_ICON_THEME(icon_theme->obj), icon, desired_size, flags);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

const PyMethodDef py_gnomedesktop_functions[] = {
    { "item_new_from_file", (PyCFunction)_wrap_gnome_desktop_item_new_from_file, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_new_from_uri", (PyCFunction)_wrap_gnome_desktop_item_new_from_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_new_from_string", (PyCFunction)_wrap_gnome_desktop_item_new_from_string, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_new_from_basename", (PyCFunction)_wrap_gnome_desktop_item_new_from_basename, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "find_icon", (PyCFunction)_wrap_gnome_desktop_item_find_icon, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
py_gnomedesktop_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_NULL", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_NULL);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_OTHER", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_OTHER);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_APPLICATION", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_APPLICATION);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_LINK", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_LINK);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_FSDEVICE", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_FSDEVICE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_MIME_TYPE", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_MIME_TYPE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_DIRECTORY", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_DIRECTORY);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_SERVICE", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_SERVICE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_TYPE_SERVICE_TYPE", strip_prefix), GNOME_DESKTOP_ITEM_TYPE_SERVICE_TYPE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_UNCHANGED", strip_prefix), GNOME_DESKTOP_ITEM_UNCHANGED);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_CHANGED", strip_prefix), GNOME_DESKTOP_ITEM_CHANGED);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_DISAPPEARED", strip_prefix), GNOME_DESKTOP_ITEM_DISAPPEARED);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_LOAD_ONLY_IF_EXISTS", strip_prefix), GNOME_DESKTOP_ITEM_LOAD_ONLY_IF_EXISTS);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_LOAD_NO_TRANSLATIONS", strip_prefix), GNOME_DESKTOP_ITEM_LOAD_NO_TRANSLATIONS);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_LAUNCH_ONLY_ONE", strip_prefix), GNOME_DESKTOP_ITEM_LAUNCH_ONLY_ONE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_LAUNCH_USE_CURRENT_DIR", strip_prefix), GNOME_DESKTOP_ITEM_LAUNCH_USE_CURRENT_DIR);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_LAUNCH_APPEND_URIS", strip_prefix), GNOME_DESKTOP_ITEM_LAUNCH_APPEND_URIS);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_LAUNCH_APPEND_PATHS", strip_prefix), GNOME_DESKTOP_ITEM_LAUNCH_APPEND_PATHS);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ICON_NO_KDE", strip_prefix), GNOME_DESKTOP_ITEM_ICON_NO_KDE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_NO_FILENAME", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_NO_FILENAME);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_UNKNOWN_ENCODING", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_UNKNOWN_ENCODING);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_CANNOT_OPEN", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_CANNOT_OPEN);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_NO_EXEC_STRING", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_NO_EXEC_STRING);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_BAD_EXEC_STRING", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_BAD_EXEC_STRING);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_NO_URL", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_NO_URL);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_NOT_LAUNCHABLE", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_NOT_LAUNCHABLE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_DESKTOP_ITEM_ERROR_INVALID_TYPE", strip_prefix), GNOME_DESKTOP_ITEM_ERROR_INVALID_TYPE);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
py_gnomedesktop_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkIconTheme_Type = (PyTypeObject *)PyObject_GetAttrString(module, "IconTheme");
        if (_PyGtkIconTheme_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name IconTheme from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk.gdk")) != NULL) {
        _PyGdkScreen_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Screen");
        if (_PyGdkScreen_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Screen from gtk.gdk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk.gdk");
        return ;
    }


#line 1054 "_gnomedesktop.c"
    pyg_register_boxed(d, "DesktopItem", GNOME_TYPE_DESKTOP_ITEM, &PyGnomeDesktopItem_Type);
}
