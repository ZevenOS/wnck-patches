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


#line 4 "wnck.override"
#include <Python.h>

#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#include <libwnck/libwnck.h>
#include <libwnck/class-group.h>
#include <libwnck/window-action-menu.h>

#include "config.h"

#line 32 "wnck.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGtkContainer_Type;
#define PyGtkContainer_Type (*_PyGtkContainer_Type)
static PyTypeObject *_PyGtkWindow_Type;
#define PyGtkWindow_Type (*_PyGtkWindow_Type)
static PyTypeObject *_PyGtkMenuBar_Type;
#define PyGtkMenuBar_Type (*_PyGtkMenuBar_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyWnckApplication_Type;
PyTypeObject G_GNUC_INTERNAL PyWnckClassGroup_Type;
PyTypeObject G_GNUC_INTERNAL PyWnckPager_Type;
PyTypeObject G_GNUC_INTERNAL PyWnckScreen_Type;
PyTypeObject G_GNUC_INTERNAL PyWnckTasklist_Type;
PyTypeObject G_GNUC_INTERNAL PyWnckWindow_Type;
PyTypeObject G_GNUC_INTERNAL PyWnckWorkspace_Type;
PyTypeObject G_GNUC_INTERNAL PyWnckSelector_Type;

#line 56 "wnck.c"



/* ----------- WnckApplication ----------- */

static PyObject *
_wrap_wnck_application_get_xid(PyGObject *self)
{
    gulong ret;

    
    ret = wnck_application_get_xid(WNCK_APPLICATION(self->obj));
    
    return PyLong_FromUnsignedLong(ret);

}

#line 28 "wnck.override"
static PyObject*
_wrap_wnck_application_get_windows (PyGObject *self, PyObject args)
{
    GList *list, *tmp;
    PyObject *ret;

    list = wnck_application_get_windows(WNCK_APPLICATION(self->obj));

    ret = PyList_New(0);
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        GtkWidget *widget = tmp->data;
        PyObject *item = pygobject_new((GObject *)widget);

        PyList_Append(ret, item);
        Py_DECREF(item);
    }
    return ret;
}
#line 93 "wnck.c"


static PyObject *
_wrap_wnck_application_get_n_windows(PyGObject *self)
{
    int ret;

    
    ret = wnck_application_get_n_windows(WNCK_APPLICATION(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_application_get_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_application_get_name(WNCK_APPLICATION(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_application_get_icon_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_application_get_icon_name(WNCK_APPLICATION(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_application_get_pid(PyGObject *self)
{
    int ret;

    
    ret = wnck_application_get_pid(WNCK_APPLICATION(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_application_get_icon(PyGObject *self)
{
    GdkPixbuf *ret;

    
    ret = wnck_application_get_icon(WNCK_APPLICATION(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_application_get_mini_icon(PyGObject *self)
{
    GdkPixbuf *ret;

    
    ret = wnck_application_get_mini_icon(WNCK_APPLICATION(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_application_get_icon_is_fallback(PyGObject *self)
{
    int ret;

    
    ret = wnck_application_get_icon_is_fallback(WNCK_APPLICATION(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_application_get_startup_id(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_application_get_startup_id(WNCK_APPLICATION(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyWnckApplication_methods[] = {
    { "get_xid", (PyCFunction)_wrap_wnck_application_get_xid, METH_NOARGS,
      NULL },
    { "get_windows", (PyCFunction)_wrap_wnck_application_get_windows, METH_NOARGS,
      NULL },
    { "get_n_windows", (PyCFunction)_wrap_wnck_application_get_n_windows, METH_NOARGS,
      NULL },
    { "get_name", (PyCFunction)_wrap_wnck_application_get_name, METH_NOARGS,
      NULL },
    { "get_icon_name", (PyCFunction)_wrap_wnck_application_get_icon_name, METH_NOARGS,
      NULL },
    { "get_pid", (PyCFunction)_wrap_wnck_application_get_pid, METH_NOARGS,
      NULL },
    { "get_icon", (PyCFunction)_wrap_wnck_application_get_icon, METH_NOARGS,
      NULL },
    { "get_mini_icon", (PyCFunction)_wrap_wnck_application_get_mini_icon, METH_NOARGS,
      NULL },
    { "get_icon_is_fallback", (PyCFunction)_wrap_wnck_application_get_icon_is_fallback, METH_NOARGS,
      NULL },
    { "get_startup_id", (PyCFunction)_wrap_wnck_application_get_startup_id, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyWnckApplication_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.Application",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyWnckApplication_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- WnckClassGroup ----------- */

#line 88 "wnck.override"
static PyObject*
_wrap_wnck_class_group_get_windows(PyGObject *self, PyObject args)
{
    GList *list, *tmp;
    PyObject *ret;

    list = wnck_class_group_get_windows(WNCK_CLASS_GROUP(self->obj));

    ret = PyList_New(0);
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        GtkWidget *widget = tmp->data;
        PyObject *item = pygobject_new((GObject *)widget);

        PyList_Append(ret, item);
        Py_DECREF(item);
    }
    return ret;
}
#line 288 "wnck.c"


static PyObject *
_wrap_wnck_class_group_get_res_class(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_class_group_get_res_class(WNCK_CLASS_GROUP(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_class_group_get_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_class_group_get_name(WNCK_CLASS_GROUP(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_class_group_get_icon(PyGObject *self)
{
    GdkPixbuf *ret;

    
    ret = wnck_class_group_get_icon(WNCK_CLASS_GROUP(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_class_group_get_mini_icon(PyGObject *self)
{
    GdkPixbuf *ret;

    
    ret = wnck_class_group_get_mini_icon(WNCK_CLASS_GROUP(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyWnckClassGroup_methods[] = {
    { "get_windows", (PyCFunction)_wrap_wnck_class_group_get_windows, METH_NOARGS,
      NULL },
    { "get_res_class", (PyCFunction)_wrap_wnck_class_group_get_res_class, METH_NOARGS,
      NULL },
    { "get_name", (PyCFunction)_wrap_wnck_class_group_get_name, METH_NOARGS,
      NULL },
    { "get_icon", (PyCFunction)_wrap_wnck_class_group_get_icon, METH_NOARGS,
      NULL },
    { "get_mini_icon", (PyCFunction)_wrap_wnck_class_group_get_mini_icon, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyWnckClassGroup_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.ClassGroup",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyWnckClassGroup_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- WnckPager ----------- */

static int
_wrap_wnck_pager_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "screen", NULL };
    PyGObject *screen;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Pager.__init__", kwlist, &PyWnckScreen_Type, &screen))
        return -1;
    self->obj = (GObject *)wnck_pager_new(WNCK_SCREEN(screen->obj));

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create WnckPager object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_wnck_pager_set_screen(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "screen", NULL };
    PyGObject *screen;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Pager.set_screen", kwlist, &PyWnckScreen_Type, &screen))
        return NULL;
    
    wnck_pager_set_screen(WNCK_PAGER(self->obj), WNCK_SCREEN(screen->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_pager_set_orientation(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "orientation", NULL };
    GtkOrientation orientation;
    PyObject *py_orientation = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Pager.set_orientation", kwlist, &py_orientation))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_ORIENTATION, py_orientation, (gpointer)&orientation))
        return NULL;
    
    wnck_pager_set_orientation(WNCK_PAGER(self->obj), orientation);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_pager_set_n_rows(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "n_rows", NULL };
    int n_rows;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Pager.set_n_rows", kwlist, &n_rows))
        return NULL;
    
    wnck_pager_set_n_rows(WNCK_PAGER(self->obj), n_rows);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_pager_set_display_mode(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "mode", NULL };
    PyObject *py_mode = NULL;
    WnckPagerDisplayMode mode;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Pager.set_display_mode", kwlist, &py_mode))
        return NULL;
    if (pyg_enum_get_value(WNCK_TYPE_PAGER_DISPLAY_MODE, py_mode, (gpointer)&mode))
        return NULL;
    
    wnck_pager_set_display_mode(WNCK_PAGER(self->obj), mode);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_pager_set_show_all(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show_all_workspaces", NULL };
    int show_all_workspaces;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Pager.set_show_all", kwlist, &show_all_workspaces))
        return NULL;
    
    wnck_pager_set_show_all(WNCK_PAGER(self->obj), show_all_workspaces);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_pager_set_shadow_type(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "shadow_type", NULL };
    PyObject *py_shadow_type = NULL;
    GtkShadowType shadow_type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Pager.set_shadow_type", kwlist, &py_shadow_type))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_SHADOW_TYPE, py_shadow_type, (gpointer)&shadow_type))
        return NULL;
    
    wnck_pager_set_shadow_type(WNCK_PAGER(self->obj), shadow_type);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyWnckPager_methods[] = {
    { "set_screen", (PyCFunction)_wrap_wnck_pager_set_screen, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_orientation", (PyCFunction)_wrap_wnck_pager_set_orientation, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_n_rows", (PyCFunction)_wrap_wnck_pager_set_n_rows, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_display_mode", (PyCFunction)_wrap_wnck_pager_set_display_mode, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_show_all", (PyCFunction)_wrap_wnck_pager_set_show_all, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_shadow_type", (PyCFunction)_wrap_wnck_pager_set_shadow_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyWnckPager_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.Pager",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyWnckPager_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_wnck_pager_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- WnckScreen ----------- */

static PyObject *
_wrap_wnck_screen_get_number(PyGObject *self)
{
    int ret;

    
    ret = wnck_screen_get_number(WNCK_SCREEN(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_screen_get_workspace(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "workspace", NULL };
    int workspace;
    WnckWorkspace *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Screen.get_workspace", kwlist, &workspace))
        return NULL;
    
    ret = wnck_screen_get_workspace(WNCK_SCREEN(self->obj), workspace);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_screen_get_workspace_index(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "space", NULL };
    PyGObject *space;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Screen.get_workspace_index", kwlist, &PyWnckWorkspace_Type, &space))
        return NULL;
    
    ret = wnck_screen_get_workspace_index(WNCK_SCREEN(self->obj), WNCK_WORKSPACE(space->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_screen_get_workspace_neighbor(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "space", "direction", NULL };
    PyGObject *space;
    PyObject *py_direction = NULL;
    WnckMotionDirection direction;
    WnckWorkspace *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!O:Wnck.Screen.get_workspace_neighbor", kwlist, &PyWnckWorkspace_Type, &space, &py_direction))
        return NULL;
    if (pyg_enum_get_value(WNCK_TYPE_MOTION_DIRECTION, py_direction, (gpointer)&direction))
        return NULL;
    
    ret = wnck_screen_get_workspace_neighbor(WNCK_SCREEN(self->obj), WNCK_WORKSPACE(space->obj), direction);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_screen_get_active_workspace(PyGObject *self)
{
    WnckWorkspace *ret;

    
    ret = wnck_screen_get_active_workspace(WNCK_SCREEN(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 133 "wnck.override"
static PyObject*
_wrap_wnck_screen_get_workspaces (PyGObject *self)
{
    GList *list, *tmp;
    PyObject *ret;

    list = wnck_screen_get_workspaces(WNCK_SCREEN(self->obj));

    ret = PyList_New(0);
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        GtkWidget *widget = tmp->data;
        PyObject *item = pygobject_new((GObject *)widget);

        PyList_Append(ret, item);
        Py_DECREF(item);
    }
    return ret;
}
#line 681 "wnck.c"


static PyObject *
_wrap_wnck_screen_get_active_window(PyGObject *self)
{
    WnckWindow *ret;

    
    ret = wnck_screen_get_active_window(WNCK_SCREEN(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_screen_get_previously_active_window(PyGObject *self)
{
    WnckWindow *ret;

    
    ret = wnck_screen_get_previously_active_window(WNCK_SCREEN(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 48 "wnck.override"
static PyObject*
_wrap_wnck_screen_get_windows (PyGObject *self, PyObject args)
{
    GList *list, *tmp;
    PyObject *ret;

    list = wnck_screen_get_windows(WNCK_SCREEN(self->obj));

    ret = PyList_New(0);
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        GtkWidget *widget = tmp->data;
        PyObject *item = pygobject_new((GObject *)widget);

        PyList_Append(ret, item);
        Py_DECREF(item);
    }
    return ret;
}
#line 727 "wnck.c"


#line 68 "wnck.override"
static PyObject*
_wrap_wnck_screen_get_windows_stacked(PyGObject *self, PyObject args)
{
    GList *list, *tmp;
    PyObject *ret;

    list = wnck_screen_get_windows_stacked(WNCK_SCREEN(self->obj));

    ret = PyList_New(0);
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        GtkWidget *widget = tmp->data;
        PyObject *item = pygobject_new((GObject *)widget);

        PyList_Append(ret, item);
        Py_DECREF(item);
    }
    return ret;
}
#line 749 "wnck.c"


static PyObject *
_wrap_wnck_screen_force_update(PyGObject *self)
{
    
    wnck_screen_force_update(WNCK_SCREEN(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_screen_get_workspace_count(PyGObject *self)
{
    int ret;

    
    ret = wnck_screen_get_workspace_count(WNCK_SCREEN(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_screen_change_workspace_count(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "count", NULL };
    int count;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Screen.change_workspace_count", kwlist, &count))
        return NULL;
    
    wnck_screen_change_workspace_count(WNCK_SCREEN(self->obj), count);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_screen_get_window_manager_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_screen_get_window_manager_name(WNCK_SCREEN(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_screen_net_wm_supports(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "atom", NULL };
    char *atom;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Wnck.Screen.net_wm_supports", kwlist, &atom))
        return NULL;
    
    ret = wnck_screen_net_wm_supports(WNCK_SCREEN(self->obj), atom);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_screen_get_background_pixmap(PyGObject *self)
{
    gulong ret;

    
    ret = wnck_screen_get_background_pixmap(WNCK_SCREEN(self->obj));
    
    return PyLong_FromUnsignedLong(ret);

}

static PyObject *
_wrap_wnck_screen_get_width(PyGObject *self)
{
    int ret;

    
    ret = wnck_screen_get_width(WNCK_SCREEN(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_screen_get_height(PyGObject *self)
{
    int ret;

    
    ret = wnck_screen_get_height(WNCK_SCREEN(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_screen_get_showing_desktop(PyGObject *self)
{
    int ret;

    
    ret = wnck_screen_get_showing_desktop(WNCK_SCREEN(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_screen_toggle_showing_desktop(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show", NULL };
    int show;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Screen.toggle_showing_desktop", kwlist, &show))
        return NULL;
    
    wnck_screen_toggle_showing_desktop(WNCK_SCREEN(self->obj), show);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_screen_move_viewport(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "x", "y", NULL };
    int x, y;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Wnck.Screen.move_viewport", kwlist, &x, &y))
        return NULL;
    
    wnck_screen_move_viewport(WNCK_SCREEN(self->obj), x, y);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_screen_try_set_workspace_layout(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "current_token", "rows", "columns", NULL };
    int current_token, rows, columns, ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iii:Wnck.Screen.try_set_workspace_layout", kwlist, &current_token, &rows, &columns))
        return NULL;
    
    ret = wnck_screen_try_set_workspace_layout(WNCK_SCREEN(self->obj), current_token, rows, columns);
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_screen_release_workspace_layout(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "current_token", NULL };
    int current_token;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Screen.release_workspace_layout", kwlist, &current_token))
        return NULL;
    
    wnck_screen_release_workspace_layout(WNCK_SCREEN(self->obj), current_token);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyWnckScreen_methods[] = {
    { "get_number", (PyCFunction)_wrap_wnck_screen_get_number, METH_NOARGS,
      NULL },
    { "get_workspace", (PyCFunction)_wrap_wnck_screen_get_workspace, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_workspace_index", (PyCFunction)_wrap_wnck_screen_get_workspace_index, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_workspace_neighbor", (PyCFunction)_wrap_wnck_screen_get_workspace_neighbor, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active_workspace", (PyCFunction)_wrap_wnck_screen_get_active_workspace, METH_NOARGS,
      NULL },
    { "get_workspaces", (PyCFunction)_wrap_wnck_screen_get_workspaces, METH_NOARGS,
      NULL },
    { "get_active_window", (PyCFunction)_wrap_wnck_screen_get_active_window, METH_NOARGS,
      NULL },
    { "get_previously_active_window", (PyCFunction)_wrap_wnck_screen_get_previously_active_window, METH_NOARGS,
      NULL },
    { "get_windows", (PyCFunction)_wrap_wnck_screen_get_windows, METH_NOARGS,
      NULL },
    { "get_windows_stacked", (PyCFunction)_wrap_wnck_screen_get_windows_stacked, METH_NOARGS,
      NULL },
    { "force_update", (PyCFunction)_wrap_wnck_screen_force_update, METH_NOARGS,
      NULL },
    { "get_workspace_count", (PyCFunction)_wrap_wnck_screen_get_workspace_count, METH_NOARGS,
      NULL },
    { "change_workspace_count", (PyCFunction)_wrap_wnck_screen_change_workspace_count, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_window_manager_name", (PyCFunction)_wrap_wnck_screen_get_window_manager_name, METH_NOARGS,
      NULL },
    { "net_wm_supports", (PyCFunction)_wrap_wnck_screen_net_wm_supports, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_background_pixmap", (PyCFunction)_wrap_wnck_screen_get_background_pixmap, METH_NOARGS,
      NULL },
    { "get_width", (PyCFunction)_wrap_wnck_screen_get_width, METH_NOARGS,
      NULL },
    { "get_height", (PyCFunction)_wrap_wnck_screen_get_height, METH_NOARGS,
      NULL },
    { "get_showing_desktop", (PyCFunction)_wrap_wnck_screen_get_showing_desktop, METH_NOARGS,
      NULL },
    { "toggle_showing_desktop", (PyCFunction)_wrap_wnck_screen_toggle_showing_desktop, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "move_viewport", (PyCFunction)_wrap_wnck_screen_move_viewport, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "try_set_workspace_layout", (PyCFunction)_wrap_wnck_screen_try_set_workspace_layout, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "release_workspace_layout", (PyCFunction)_wrap_wnck_screen_release_workspace_layout, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyWnckScreen_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.Screen",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyWnckScreen_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- WnckTasklist ----------- */

static int
_wrap_wnck_tasklist_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "screen", NULL };
    PyGObject *screen;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Tasklist.__init__", kwlist, &PyWnckScreen_Type, &screen))
        return -1;
    self->obj = (GObject *)wnck_tasklist_new(WNCK_SCREEN(screen->obj));

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create WnckTasklist object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_wnck_tasklist_set_screen(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "screen", NULL };
    PyGObject *screen;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Tasklist.set_screen", kwlist, &PyWnckScreen_Type, &screen))
        return NULL;
    
    wnck_tasklist_set_screen(WNCK_TASKLIST(self->obj), WNCK_SCREEN(screen->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 108 "wnck.override"
static PyObject *
_wrap_wnck_tasklist_get_size_hint_list(PyGObject *self)
{
    const int *list;
    PyObject *pylist;
    int i, len = 0;

    list = wnck_tasklist_get_size_hint_list(WNCK_TASKLIST(self->obj), &len);
    pylist = PyList_New(len);
    for (i = 0; i < len; ++i)
        PyList_SET_ITEM(pylist, i, PyInt_FromLong(list[i]));
    return pylist;
}
#line 1069 "wnck.c"


static PyObject *
_wrap_wnck_tasklist_set_grouping(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "grouping", NULL };
    PyObject *py_grouping = NULL;
    WnckTasklistGroupingType grouping;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Tasklist.set_grouping", kwlist, &py_grouping))
        return NULL;
    if (pyg_enum_get_value(WNCK_TYPE_TASKLIST_GROUPING_TYPE, py_grouping, (gpointer)&grouping))
        return NULL;
    
    wnck_tasklist_set_grouping(WNCK_TASKLIST(self->obj), grouping);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_tasklist_set_switch_workspace_on_unminimize(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "switch_workspace_on_unminimize", NULL };
    int switch_workspace_on_unminimize;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Tasklist.set_switch_workspace_on_unminimize", kwlist, &switch_workspace_on_unminimize))
        return NULL;
    
    wnck_tasklist_set_switch_workspace_on_unminimize(WNCK_TASKLIST(self->obj), switch_workspace_on_unminimize);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_tasklist_set_grouping_limit(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "limit", NULL };
    int limit;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Tasklist.set_grouping_limit", kwlist, &limit))
        return NULL;
    
    wnck_tasklist_set_grouping_limit(WNCK_TASKLIST(self->obj), limit);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_tasklist_set_include_all_workspaces(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "include_all_workspaces", NULL };
    int include_all_workspaces;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Tasklist.set_include_all_workspaces", kwlist, &include_all_workspaces))
        return NULL;
    
    wnck_tasklist_set_include_all_workspaces(WNCK_TASKLIST(self->obj), include_all_workspaces);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_tasklist_set_button_relief(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "relief", NULL };
    GtkReliefStyle relief;
    PyObject *py_relief = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Tasklist.set_button_relief", kwlist, &py_relief))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_RELIEF_STYLE, py_relief, (gpointer)&relief))
        return NULL;
    
    wnck_tasklist_set_button_relief(WNCK_TASKLIST(self->obj), relief);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_tasklist_set_minimum_width(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    int size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Tasklist.set_minimum_width", kwlist, &size))
        return NULL;
    
    wnck_tasklist_set_minimum_width(WNCK_TASKLIST(self->obj), size);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_tasklist_get_minimum_width(PyGObject *self)
{
    int ret;

    
    ret = wnck_tasklist_get_minimum_width(WNCK_TASKLIST(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_tasklist_set_minimum_height(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    int size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Tasklist.set_minimum_height", kwlist, &size))
        return NULL;
    
    wnck_tasklist_set_minimum_height(WNCK_TASKLIST(self->obj), size);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_tasklist_get_minimum_height(PyGObject *self)
{
    int ret;

    
    ret = wnck_tasklist_get_minimum_height(WNCK_TASKLIST(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_tasklist_set_orientation(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "orientation", NULL };
    GtkOrientation orientation;
    PyObject *py_orientation = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Tasklist.set_orientation", kwlist, &py_orientation))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_ORIENTATION, py_orientation, (gpointer)&orientation))
        return NULL;
    
    wnck_tasklist_set_orientation(WNCK_TASKLIST(self->obj), orientation);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyWnckTasklist_methods[] = {
    { "set_screen", (PyCFunction)_wrap_wnck_tasklist_set_screen, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_size_hint_list", (PyCFunction)_wrap_wnck_tasklist_get_size_hint_list, METH_VARARGS,
      NULL },
    { "set_grouping", (PyCFunction)_wrap_wnck_tasklist_set_grouping, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_switch_workspace_on_unminimize", (PyCFunction)_wrap_wnck_tasklist_set_switch_workspace_on_unminimize, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_grouping_limit", (PyCFunction)_wrap_wnck_tasklist_set_grouping_limit, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_include_all_workspaces", (PyCFunction)_wrap_wnck_tasklist_set_include_all_workspaces, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_button_relief", (PyCFunction)_wrap_wnck_tasklist_set_button_relief, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_minimum_width", (PyCFunction)_wrap_wnck_tasklist_set_minimum_width, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_minimum_width", (PyCFunction)_wrap_wnck_tasklist_get_minimum_width, METH_NOARGS,
      NULL },
    { "set_minimum_height", (PyCFunction)_wrap_wnck_tasklist_set_minimum_height, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_minimum_height", (PyCFunction)_wrap_wnck_tasklist_get_minimum_height, METH_NOARGS,
      NULL },
    { "set_orientation", (PyCFunction)_wrap_wnck_tasklist_set_orientation, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyWnckTasklist_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.Tasklist",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyWnckTasklist_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_wnck_tasklist_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- WnckWindow ----------- */

static PyObject *
_wrap_wnck_window_get_screen(PyGObject *self)
{
    WnckScreen *ret;

    
    ret = wnck_window_get_screen(WNCK_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_has_name(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_has_name(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_get_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_window_get_name(WNCK_WINDOW(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_has_icon_name(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_has_icon_name(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_get_icon_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_window_get_icon_name(WNCK_WINDOW(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_get_application(PyGObject *self)
{
    WnckApplication *ret;

    
    ret = wnck_window_get_application(WNCK_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_get_transient(PyGObject *self)
{
    WnckWindow *ret;

    
    ret = wnck_window_get_transient(WNCK_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_get_group_leader(PyGObject *self)
{
    gulong ret;

    
    ret = wnck_window_get_group_leader(WNCK_WINDOW(self->obj));
    
    return PyLong_FromUnsignedLong(ret);

}

static PyObject *
_wrap_wnck_window_get_xid(PyGObject *self)
{
    gulong ret;

    
    ret = wnck_window_get_xid(WNCK_WINDOW(self->obj));
    
    return PyLong_FromUnsignedLong(ret);

}

static PyObject *
_wrap_wnck_window_get_class_group(PyGObject *self)
{
    WnckClassGroup *ret;

    
    ret = wnck_window_get_class_group(WNCK_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_get_session_id(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_window_get_session_id(WNCK_WINDOW(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_get_session_id_utf8(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_window_get_session_id_utf8(WNCK_WINDOW(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_get_pid(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_get_pid(WNCK_WINDOW(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_window_get_sort_order(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_get_sort_order(WNCK_WINDOW(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_window_set_sort_order(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "order", NULL };
    int order;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Window.set_sort_order", kwlist, &order))
        return NULL;
    
    wnck_window_set_sort_order(WNCK_WINDOW(self->obj), order);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_get_window_type(PyGObject *self)
{
    gint ret;

    
    ret = wnck_window_get_window_type(WNCK_WINDOW(self->obj));
    
    return pyg_enum_from_gtype(WNCK_TYPE_WINDOW_TYPE, ret);
}

static PyObject *
_wrap_wnck_window_set_window_type(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "wintype", NULL };
    PyObject *py_wintype = NULL;
    WnckWindowType wintype;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Window.set_window_type", kwlist, &py_wintype))
        return NULL;
    if (pyg_enum_get_value(WNCK_TYPE_WINDOW_TYPE, py_wintype, (gpointer)&wintype))
        return NULL;
    
    wnck_window_set_window_type(WNCK_WINDOW(self->obj), wintype);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_is_minimized(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_minimized(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_maximized_horizontally(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_maximized_horizontally(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_maximized_vertically(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_maximized_vertically(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_maximized(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_maximized(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_shaded(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_shaded(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_above(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_above(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_below(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_below(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_skip_pager(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_skip_pager(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_skip_tasklist(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_skip_tasklist(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_fullscreen(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_fullscreen(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_sticky(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_sticky(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_needs_attention(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_needs_attention(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_or_transient_needs_attention(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_or_transient_needs_attention(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_set_skip_pager(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "skip", NULL };
    int skip;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Window.set_skip_pager", kwlist, &skip))
        return NULL;
    
    wnck_window_set_skip_pager(WNCK_WINDOW(self->obj), skip);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_set_skip_tasklist(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "skip", NULL };
    int skip;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Window.set_skip_tasklist", kwlist, &skip))
        return NULL;
    
    wnck_window_set_skip_tasklist(WNCK_WINDOW(self->obj), skip);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_set_fullscreen(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "fullscreen", NULL };
    int fullscreen;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Wnck.Window.set_fullscreen", kwlist, &fullscreen))
        return NULL;
    
    wnck_window_set_fullscreen(WNCK_WINDOW(self->obj), fullscreen);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_close(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "timestamp", NULL };
    unsigned long timestamp;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:Wnck.Window.close", kwlist, &timestamp))
        return NULL;
    
    wnck_window_close(WNCK_WINDOW(self->obj), timestamp);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_minimize(PyGObject *self)
{
    
    wnck_window_minimize(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unminimize(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "timestamp", NULL };
    unsigned long timestamp;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:Wnck.Window.unminimize", kwlist, &timestamp))
        return NULL;
    
    wnck_window_unminimize(WNCK_WINDOW(self->obj), timestamp);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_maximize(PyGObject *self)
{
    
    wnck_window_maximize(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unmaximize(PyGObject *self)
{
    
    wnck_window_unmaximize(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_maximize_horizontally(PyGObject *self)
{
    
    wnck_window_maximize_horizontally(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unmaximize_horizontally(PyGObject *self)
{
    
    wnck_window_unmaximize_horizontally(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_maximize_vertically(PyGObject *self)
{
    
    wnck_window_maximize_vertically(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unmaximize_vertically(PyGObject *self)
{
    
    wnck_window_unmaximize_vertically(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_shade(PyGObject *self)
{
    
    wnck_window_shade(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unshade(PyGObject *self)
{
    
    wnck_window_unshade(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_make_above(PyGObject *self)
{
    
    wnck_window_make_above(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unmake_above(PyGObject *self)
{
    
    wnck_window_unmake_above(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_make_below(PyGObject *self)
{
    
    wnck_window_make_below(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unmake_below(PyGObject *self)
{
    
    wnck_window_unmake_below(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_stick(PyGObject *self)
{
    
    wnck_window_stick(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unstick(PyGObject *self)
{
    
    wnck_window_unstick(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_keyboard_move(PyGObject *self)
{
    
    wnck_window_keyboard_move(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_keyboard_size(PyGObject *self)
{
    
    wnck_window_keyboard_size(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_get_workspace(PyGObject *self)
{
    WnckWorkspace *ret;

    
    ret = wnck_window_get_workspace(WNCK_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_move_to_workspace(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "space", NULL };
    PyGObject *space;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Window.move_to_workspace", kwlist, &PyWnckWorkspace_Type, &space))
        return NULL;
    
    wnck_window_move_to_workspace(WNCK_WINDOW(self->obj), WNCK_WORKSPACE(space->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_is_pinned(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_pinned(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_pin(PyGObject *self)
{
    
    wnck_window_pin(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_unpin(PyGObject *self)
{
    
    wnck_window_unpin(WNCK_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_activate(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "timestamp", NULL };
    unsigned long timestamp;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:Wnck.Window.activate", kwlist, &timestamp))
        return NULL;
    
    wnck_window_activate(WNCK_WINDOW(self->obj), timestamp);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_is_active(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_active(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_most_recently_activated(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_is_most_recently_activated(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_activate_transient(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "timestamp", NULL };
    unsigned long timestamp;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:Wnck.Window.activate_transient", kwlist, &timestamp))
        return NULL;
    
    wnck_window_activate_transient(WNCK_WINDOW(self->obj), timestamp);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_transient_is_most_recently_activated(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_transient_is_most_recently_activated(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_get_icon(PyGObject *self)
{
    GdkPixbuf *ret;

    
    ret = wnck_window_get_icon(WNCK_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_get_mini_icon(PyGObject *self)
{
    GdkPixbuf *ret;

    
    ret = wnck_window_get_mini_icon(WNCK_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_get_icon_is_fallback(PyGObject *self)
{
    int ret;

    
    ret = wnck_window_get_icon_is_fallback(WNCK_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_set_icon_geometry(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "x", "y", "width", "height", NULL };
    int x, y, width, height;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iiii:Wnck.Window.set_icon_geometry", kwlist, &x, &y, &width, &height))
        return NULL;
    
    wnck_window_set_icon_geometry(WNCK_WINDOW(self->obj), x, y, width, height);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_get_actions(PyGObject *self)
{
    guint ret;

    
    ret = wnck_window_get_actions(WNCK_WINDOW(self->obj));
    
    return pyg_flags_from_gtype(WNCK_TYPE_WINDOW_ACTIONS, ret);
}

static PyObject *
_wrap_wnck_window_get_state(PyGObject *self)
{
    guint ret;

    
    ret = wnck_window_get_state(WNCK_WINDOW(self->obj));
    
    return pyg_flags_from_gtype(WNCK_TYPE_WINDOW_STATE, ret);
}

#line 153 "wnck.override"
static PyObject *
_wrap_wnck_window_get_client_window_geometry(PyGObject *self)
{
    int x, y, width, height;

    wnck_window_get_client_window_geometry(WNCK_WINDOW(self->obj), &x, &y, &width, &height);
    return Py_BuildValue("iiii", x, y, width, height);
}
#line 2126 "wnck.c"


#line 123 "wnck.override"
static PyObject *
_wrap_wnck_window_get_geometry(PyGObject *self)
{
    int x, y, width, height;

    wnck_window_get_geometry(WNCK_WINDOW(self->obj), &x, &y, &width, &height);
    return Py_BuildValue("iiii", x, y, width, height);
}
#line 2138 "wnck.c"


static PyObject *
_wrap_wnck_window_set_geometry(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "gravity", "geometry_mask", "x", "y", "width", "height", NULL };
    PyObject *py_gravity = NULL, *py_geometry_mask = NULL;
    int x, y, width, height;
    WnckWindowGravity gravity;
    WnckWindowMoveResizeMask geometry_mask;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOiiii:Wnck.Window.set_geometry", kwlist, &py_gravity, &py_geometry_mask, &x, &y, &width, &height))
        return NULL;
    if (pyg_enum_get_value(WNCK_TYPE_WINDOW_GRAVITY, py_gravity, (gpointer)&gravity))
        return NULL;
    if (pyg_flags_get_value(WNCK_TYPE_WINDOW_MOVE_RESIZE_MASK, py_geometry_mask, (gpointer)&geometry_mask))
        return NULL;
    
    wnck_window_set_geometry(WNCK_WINDOW(self->obj), gravity, geometry_mask, x, y, width, height);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_window_is_visible_on_workspace(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "workspace", NULL };
    PyGObject *workspace;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Window.is_visible_on_workspace", kwlist, &PyWnckWorkspace_Type, &workspace))
        return NULL;
    
    ret = wnck_window_is_visible_on_workspace(WNCK_WINDOW(self->obj), WNCK_WORKSPACE(workspace->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_on_workspace(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "workspace", NULL };
    PyGObject *workspace;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Window.is_on_workspace", kwlist, &PyWnckWorkspace_Type, &workspace))
        return NULL;
    
    ret = wnck_window_is_on_workspace(WNCK_WINDOW(self->obj), WNCK_WORKSPACE(workspace->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_window_is_in_viewport(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "workspace", NULL };
    PyGObject *workspace;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Wnck.Window.is_in_viewport", kwlist, &PyWnckWorkspace_Type, &workspace))
        return NULL;
    
    ret = wnck_window_is_in_viewport(WNCK_WINDOW(self->obj), WNCK_WORKSPACE(workspace->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyWnckWindow_methods[] = {
    { "get_screen", (PyCFunction)_wrap_wnck_window_get_screen, METH_NOARGS,
      NULL },
    { "has_name", (PyCFunction)_wrap_wnck_window_has_name, METH_NOARGS,
      NULL },
    { "get_name", (PyCFunction)_wrap_wnck_window_get_name, METH_NOARGS,
      NULL },
    { "has_icon_name", (PyCFunction)_wrap_wnck_window_has_icon_name, METH_NOARGS,
      NULL },
    { "get_icon_name", (PyCFunction)_wrap_wnck_window_get_icon_name, METH_NOARGS,
      NULL },
    { "get_application", (PyCFunction)_wrap_wnck_window_get_application, METH_NOARGS,
      NULL },
    { "get_transient", (PyCFunction)_wrap_wnck_window_get_transient, METH_NOARGS,
      NULL },
    { "get_group_leader", (PyCFunction)_wrap_wnck_window_get_group_leader, METH_NOARGS,
      NULL },
    { "get_xid", (PyCFunction)_wrap_wnck_window_get_xid, METH_NOARGS,
      NULL },
    { "get_class_group", (PyCFunction)_wrap_wnck_window_get_class_group, METH_NOARGS,
      NULL },
    { "get_session_id", (PyCFunction)_wrap_wnck_window_get_session_id, METH_NOARGS,
      NULL },
    { "get_session_id_utf8", (PyCFunction)_wrap_wnck_window_get_session_id_utf8, METH_NOARGS,
      NULL },
    { "get_pid", (PyCFunction)_wrap_wnck_window_get_pid, METH_NOARGS,
      NULL },
    { "get_sort_order", (PyCFunction)_wrap_wnck_window_get_sort_order, METH_NOARGS,
      NULL },
    { "set_sort_order", (PyCFunction)_wrap_wnck_window_set_sort_order, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_window_type", (PyCFunction)_wrap_wnck_window_get_window_type, METH_NOARGS,
      NULL },
    { "set_window_type", (PyCFunction)_wrap_wnck_window_set_window_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_minimized", (PyCFunction)_wrap_wnck_window_is_minimized, METH_NOARGS,
      NULL },
    { "is_maximized_horizontally", (PyCFunction)_wrap_wnck_window_is_maximized_horizontally, METH_NOARGS,
      NULL },
    { "is_maximized_vertically", (PyCFunction)_wrap_wnck_window_is_maximized_vertically, METH_NOARGS,
      NULL },
    { "is_maximized", (PyCFunction)_wrap_wnck_window_is_maximized, METH_NOARGS,
      NULL },
    { "is_shaded", (PyCFunction)_wrap_wnck_window_is_shaded, METH_NOARGS,
      NULL },
    { "is_above", (PyCFunction)_wrap_wnck_window_is_above, METH_NOARGS,
      NULL },
    { "is_below", (PyCFunction)_wrap_wnck_window_is_below, METH_NOARGS,
      NULL },
    { "is_skip_pager", (PyCFunction)_wrap_wnck_window_is_skip_pager, METH_NOARGS,
      NULL },
    { "is_skip_tasklist", (PyCFunction)_wrap_wnck_window_is_skip_tasklist, METH_NOARGS,
      NULL },
    { "is_fullscreen", (PyCFunction)_wrap_wnck_window_is_fullscreen, METH_NOARGS,
      NULL },
    { "is_sticky", (PyCFunction)_wrap_wnck_window_is_sticky, METH_NOARGS,
      NULL },
    { "needs_attention", (PyCFunction)_wrap_wnck_window_needs_attention, METH_NOARGS,
      NULL },
    { "or_transient_needs_attention", (PyCFunction)_wrap_wnck_window_or_transient_needs_attention, METH_NOARGS,
      NULL },
    { "set_skip_pager", (PyCFunction)_wrap_wnck_window_set_skip_pager, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_skip_tasklist", (PyCFunction)_wrap_wnck_window_set_skip_tasklist, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_fullscreen", (PyCFunction)_wrap_wnck_window_set_fullscreen, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "close", (PyCFunction)_wrap_wnck_window_close, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "minimize", (PyCFunction)_wrap_wnck_window_minimize, METH_NOARGS,
      NULL },
    { "unminimize", (PyCFunction)_wrap_wnck_window_unminimize, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "maximize", (PyCFunction)_wrap_wnck_window_maximize, METH_NOARGS,
      NULL },
    { "unmaximize", (PyCFunction)_wrap_wnck_window_unmaximize, METH_NOARGS,
      NULL },
    { "maximize_horizontally", (PyCFunction)_wrap_wnck_window_maximize_horizontally, METH_NOARGS,
      NULL },
    { "unmaximize_horizontally", (PyCFunction)_wrap_wnck_window_unmaximize_horizontally, METH_NOARGS,
      NULL },
    { "maximize_vertically", (PyCFunction)_wrap_wnck_window_maximize_vertically, METH_NOARGS,
      NULL },
    { "unmaximize_vertically", (PyCFunction)_wrap_wnck_window_unmaximize_vertically, METH_NOARGS,
      NULL },
    { "shade", (PyCFunction)_wrap_wnck_window_shade, METH_NOARGS,
      NULL },
    { "unshade", (PyCFunction)_wrap_wnck_window_unshade, METH_NOARGS,
      NULL },
    { "make_above", (PyCFunction)_wrap_wnck_window_make_above, METH_NOARGS,
      NULL },
    { "unmake_above", (PyCFunction)_wrap_wnck_window_unmake_above, METH_NOARGS,
      NULL },
    { "make_below", (PyCFunction)_wrap_wnck_window_make_below, METH_NOARGS,
      NULL },
    { "unmake_below", (PyCFunction)_wrap_wnck_window_unmake_below, METH_NOARGS,
      NULL },
    { "stick", (PyCFunction)_wrap_wnck_window_stick, METH_NOARGS,
      NULL },
    { "unstick", (PyCFunction)_wrap_wnck_window_unstick, METH_NOARGS,
      NULL },
    { "keyboard_move", (PyCFunction)_wrap_wnck_window_keyboard_move, METH_NOARGS,
      NULL },
    { "keyboard_size", (PyCFunction)_wrap_wnck_window_keyboard_size, METH_NOARGS,
      NULL },
    { "get_workspace", (PyCFunction)_wrap_wnck_window_get_workspace, METH_NOARGS,
      NULL },
    { "move_to_workspace", (PyCFunction)_wrap_wnck_window_move_to_workspace, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_pinned", (PyCFunction)_wrap_wnck_window_is_pinned, METH_NOARGS,
      NULL },
    { "pin", (PyCFunction)_wrap_wnck_window_pin, METH_NOARGS,
      NULL },
    { "unpin", (PyCFunction)_wrap_wnck_window_unpin, METH_NOARGS,
      NULL },
    { "activate", (PyCFunction)_wrap_wnck_window_activate, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_active", (PyCFunction)_wrap_wnck_window_is_active, METH_NOARGS,
      NULL },
    { "is_most_recently_activated", (PyCFunction)_wrap_wnck_window_is_most_recently_activated, METH_NOARGS,
      NULL },
    { "activate_transient", (PyCFunction)_wrap_wnck_window_activate_transient, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "transient_is_most_recently_activated", (PyCFunction)_wrap_wnck_window_transient_is_most_recently_activated, METH_NOARGS,
      NULL },
    { "get_icon", (PyCFunction)_wrap_wnck_window_get_icon, METH_NOARGS,
      NULL },
    { "get_mini_icon", (PyCFunction)_wrap_wnck_window_get_mini_icon, METH_NOARGS,
      NULL },
    { "get_icon_is_fallback", (PyCFunction)_wrap_wnck_window_get_icon_is_fallback, METH_NOARGS,
      NULL },
    { "set_icon_geometry", (PyCFunction)_wrap_wnck_window_set_icon_geometry, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_actions", (PyCFunction)_wrap_wnck_window_get_actions, METH_NOARGS,
      NULL },
    { "get_state", (PyCFunction)_wrap_wnck_window_get_state, METH_NOARGS,
      NULL },
    { "get_client_window_geometry", (PyCFunction)_wrap_wnck_window_get_client_window_geometry, METH_NOARGS,
      NULL },
    { "get_geometry", (PyCFunction)_wrap_wnck_window_get_geometry, METH_NOARGS,
      NULL },
    { "set_geometry", (PyCFunction)_wrap_wnck_window_set_geometry, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_visible_on_workspace", (PyCFunction)_wrap_wnck_window_is_visible_on_workspace, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_on_workspace", (PyCFunction)_wrap_wnck_window_is_on_workspace, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_in_viewport", (PyCFunction)_wrap_wnck_window_is_in_viewport, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyWnckWindow_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.Window",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyWnckWindow_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- WnckWorkspace ----------- */

static PyObject *
_wrap_wnck_workspace_get_number(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_get_number(WNCK_WORKSPACE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_workspace_get_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = wnck_workspace_get_name(WNCK_WORKSPACE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_workspace_change_name(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Wnck.Workspace.change_name", kwlist, &name))
        return NULL;
    
    wnck_workspace_change_name(WNCK_WORKSPACE(self->obj), name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_workspace_get_screen(PyGObject *self)
{
    WnckScreen *ret;

    
    ret = wnck_workspace_get_screen(WNCK_WORKSPACE(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_workspace_activate(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "timestamp", NULL };
    unsigned long timestamp;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:Wnck.Workspace.activate", kwlist, &timestamp))
        return NULL;
    
    wnck_workspace_activate(WNCK_WORKSPACE(self->obj), timestamp);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_workspace_get_width(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_get_width(WNCK_WORKSPACE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_workspace_get_height(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_get_height(WNCK_WORKSPACE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_workspace_get_viewport_x(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_get_viewport_x(WNCK_WORKSPACE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_workspace_get_viewport_y(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_get_viewport_y(WNCK_WORKSPACE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_workspace_is_virtual(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_is_virtual(WNCK_WORKSPACE(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_wnck_workspace_get_layout_row(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_get_layout_row(WNCK_WORKSPACE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_workspace_get_layout_column(PyGObject *self)
{
    int ret;

    
    ret = wnck_workspace_get_layout_column(WNCK_WORKSPACE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_wnck_workspace_get_neighbor(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "direction", NULL };
    PyObject *py_direction = NULL;
    WnckWorkspace *ret;
    WnckMotionDirection direction;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Wnck.Workspace.get_neighbor", kwlist, &py_direction))
        return NULL;
    if (pyg_enum_get_value(WNCK_TYPE_MOTION_DIRECTION, py_direction, (gpointer)&direction))
        return NULL;
    
    ret = wnck_workspace_get_neighbor(WNCK_WORKSPACE(self->obj), direction);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyWnckWorkspace_methods[] = {
    { "get_number", (PyCFunction)_wrap_wnck_workspace_get_number, METH_NOARGS,
      NULL },
    { "get_name", (PyCFunction)_wrap_wnck_workspace_get_name, METH_NOARGS,
      NULL },
    { "change_name", (PyCFunction)_wrap_wnck_workspace_change_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_screen", (PyCFunction)_wrap_wnck_workspace_get_screen, METH_NOARGS,
      NULL },
    { "activate", (PyCFunction)_wrap_wnck_workspace_activate, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_width", (PyCFunction)_wrap_wnck_workspace_get_width, METH_NOARGS,
      NULL },
    { "get_height", (PyCFunction)_wrap_wnck_workspace_get_height, METH_NOARGS,
      NULL },
    { "get_viewport_x", (PyCFunction)_wrap_wnck_workspace_get_viewport_x, METH_NOARGS,
      NULL },
    { "get_viewport_y", (PyCFunction)_wrap_wnck_workspace_get_viewport_y, METH_NOARGS,
      NULL },
    { "is_virtual", (PyCFunction)_wrap_wnck_workspace_is_virtual, METH_NOARGS,
      NULL },
    { "get_layout_row", (PyCFunction)_wrap_wnck_workspace_get_layout_row, METH_NOARGS,
      NULL },
    { "get_layout_column", (PyCFunction)_wrap_wnck_workspace_get_layout_column, METH_NOARGS,
      NULL },
    { "get_neighbor", (PyCFunction)_wrap_wnck_workspace_get_neighbor, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyWnckWorkspace_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.Workspace",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyWnckWorkspace_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- WnckSelector ----------- */

static int
_wrap_wnck_selector_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":wnck.Selector.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create wnck.Selector object");
        return -1;
    }
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyWnckSelector_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "wnck.Selector",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
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
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_wnck_selector_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_wnck_application_get(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "xwindow", NULL };
    WnckApplication *ret;
    unsigned long xwindow;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:application_get", kwlist, &xwindow))
        return NULL;
    
    ret = wnck_application_get(xwindow);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_class_group_get(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "res_class", NULL };
    char *res_class;
    WnckClassGroup *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:class_group_get", kwlist, &res_class))
        return NULL;
    
    ret = wnck_class_group_get(res_class);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_screen_get_default(PyObject *self)
{
    WnckScreen *ret;

    
    ret = wnck_screen_get_default();
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_screen_get(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "index", NULL };
    int index;
    WnckScreen *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:screen_get", kwlist, &index))
        return NULL;
    
    ret = wnck_screen_get(index);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_screen_get_for_root(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "root_window_id", NULL };
    WnckScreen *ret;
    unsigned long root_window_id;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:screen_get_for_root", kwlist, &root_window_id))
        return NULL;
    
    ret = wnck_screen_get_for_root(root_window_id);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_set_client_type(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "ewmh_sourceindication_client_type", NULL };
    int ewmh_sourceindication_client_type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:set_client_type", kwlist, &ewmh_sourceindication_client_type))
        return NULL;
    
    wnck_set_client_type(ewmh_sourceindication_client_type);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_gtk_window_set_dock_type(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "window", NULL };
    PyGObject *window;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:gtk_window_set_dock_type", kwlist, &PyGtkWindow_Type, &window))
        return NULL;
    
    wnck_gtk_window_set_dock_type(GTK_WINDOW(window->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_wnck_create_window_action_menu(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "window", NULL };
    PyGObject *window;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:create_window_action_menu", kwlist, &PyWnckWindow_Type, &window))
        return NULL;
    
    ret = wnck_create_window_action_menu(WNCK_WINDOW(window->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_wnck_window_get(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "xwindow", NULL };
    unsigned long xwindow;
    WnckWindow *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:window_get", kwlist, &xwindow))
        return NULL;
    
    ret = wnck_window_get(xwindow);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

const PyMethodDef pywnck_functions[] = {
    { "application_get", (PyCFunction)_wrap_wnck_application_get, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "class_group_get", (PyCFunction)_wrap_wnck_class_group_get, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "screen_get_default", (PyCFunction)_wrap_wnck_screen_get_default, METH_NOARGS,
      NULL },
    { "screen_get", (PyCFunction)_wrap_wnck_screen_get, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "screen_get_for_root", (PyCFunction)_wrap_wnck_screen_get_for_root, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_client_type", (PyCFunction)_wrap_wnck_set_client_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "gtk_window_set_dock_type", (PyCFunction)_wrap_wnck_gtk_window_set_dock_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "create_window_action_menu", (PyCFunction)_wrap_wnck_create_window_action_menu, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "window_get", (PyCFunction)_wrap_wnck_window_get, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
pywnck_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("WNCK_CLIENT_TYPE_APPLICATION", strip_prefix), WNCK_CLIENT_TYPE_APPLICATION);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("WNCK_CLIENT_TYPE_PAGER", strip_prefix), WNCK_CLIENT_TYPE_PAGER);
  pyg_enum_add(module, "PagerDisplayMode", strip_prefix, WNCK_TYPE_PAGER_DISPLAY_MODE);
  pyg_enum_add(module, "MotionDirection", strip_prefix, WNCK_TYPE_MOTION_DIRECTION);
  pyg_enum_add(module, "TasklistGroupingType", strip_prefix, WNCK_TYPE_TASKLIST_GROUPING_TYPE);
  pyg_flags_add(module, "WindowState", strip_prefix, WNCK_TYPE_WINDOW_STATE);
  pyg_flags_add(module, "WindowActions", strip_prefix, WNCK_TYPE_WINDOW_ACTIONS);
  pyg_enum_add(module, "WindowType", strip_prefix, WNCK_TYPE_WINDOW_TYPE);
  pyg_enum_add(module, "WindowGravity", strip_prefix, WNCK_TYPE_WINDOW_GRAVITY);
  pyg_flags_add(module, "WindowMoveResizeMask", strip_prefix, WNCK_TYPE_WINDOW_MOVE_RESIZE_MASK);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
pywnck_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkContainer_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Container");
        if (_PyGtkContainer_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Container from gtk");
            return ;
        }
        _PyGtkWindow_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Window");
        if (_PyGtkWindow_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Window from gtk");
            return ;
        }
        _PyGtkMenuBar_Type = (PyTypeObject *)PyObject_GetAttrString(module, "MenuBar");
        if (_PyGtkMenuBar_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name MenuBar from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }


#line 2952 "wnck.c"
    pygobject_register_class(d, "WnckApplication", WNCK_TYPE_APPLICATION, &PyWnckApplication_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(WNCK_TYPE_APPLICATION);
    pygobject_register_class(d, "WnckClassGroup", WNCK_TYPE_CLASS_GROUP, &PyWnckClassGroup_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(WNCK_TYPE_CLASS_GROUP);
    pygobject_register_class(d, "WnckPager", WNCK_TYPE_PAGER, &PyWnckPager_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pygobject_register_class(d, "WnckScreen", WNCK_TYPE_SCREEN, &PyWnckScreen_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(WNCK_TYPE_SCREEN);
    pygobject_register_class(d, "WnckTasklist", WNCK_TYPE_TASKLIST, &PyWnckTasklist_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pygobject_register_class(d, "WnckWindow", WNCK_TYPE_WINDOW, &PyWnckWindow_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(WNCK_TYPE_WINDOW);
    pygobject_register_class(d, "WnckWorkspace", WNCK_TYPE_WORKSPACE, &PyWnckWorkspace_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(WNCK_TYPE_WORKSPACE);
    pygobject_register_class(d, "WnckSelector", WNCK_TYPE_SELECTOR, &PyWnckSelector_Type, Py_BuildValue("(O)", &PyGtkMenuBar_Type));
    pyg_set_object_has_new_constructor(WNCK_TYPE_SELECTOR);
}
