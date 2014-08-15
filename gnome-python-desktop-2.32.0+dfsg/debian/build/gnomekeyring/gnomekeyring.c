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


#line 4 "gnomekeyring.override"
#include <Python.h>
#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>
#include <gnome-keyring.h>
#include "config.h"

gboolean  pygnomekeyring_result_check        (GnomeKeyringResult result);
PyObject* pygnomekeyring_result_to_exception (GnomeKeyringResult result);

typedef struct {
    PyObject *func, *data;
} PyGtkCustomNotify;

static void
pygtk_custom_destroy_notify(gpointer user_data)
{
    PyGtkCustomNotify *cunote = user_data;
    PyGILState_STATE state;

    g_return_if_fail(user_data);
    state = pyg_gil_state_ensure();
    Py_XDECREF(cunote->func);
    Py_XDECREF(cunote->data);
    pyg_gil_state_release(state);
    
    g_free(cunote);
}


#ifndef GNOME_KEYRING_TYPE_INFO
# define GNOME_KEYRING_TYPE_INFO pygnome_keyring_info_get_type()

static GType
pygnome_keyring_info_get_type(void)
{
    static GType our_type = 0;
  
    if (our_type == 0)
        our_type = g_boxed_type_register_static("PyGnomeKeyringInfo",
                                                (GBoxedCopyFunc)gnome_keyring_info_copy,
                                                (GBoxedFreeFunc)gnome_keyring_info_free);
    return our_type;
}

#endif /* #ifndef GNOME_KEYRING_TYPE_INFO */

#ifndef GNOME_KEYRING_TYPE_ITEM_INFO
# define GNOME_KEYRING_TYPE_ITEM_INFO pygnome_keyring_item_info_get_type()

static GType
pygnome_keyring_item_info_get_type(void)
{
    static GType our_type = 0;
  
    if (our_type == 0)
        our_type = g_boxed_type_register_static("PyGnomeKeyringItemInfo",
                                                (GBoxedCopyFunc)gnome_keyring_item_info_copy,
                                                (GBoxedFreeFunc)gnome_keyring_item_info_free);
    return our_type;
}

#endif /* #ifndef GNOME_KEYRING_TYPE_ITEM_INFO */

#ifndef GNOME_KEYRING_TYPE_APPLICATION_REF
# define GNOME_KEYRING_TYPE_APPLICATION_REF pygnome_keyring_application_ref_get_type()
static GType
pygnome_keyring_application_ref_get_type(void)
{
    static GType our_type = 0;
  
    if (our_type == 0)
        our_type = g_boxed_type_register_static("PyGnomeKeyringApplicationRef",
                                                (GBoxedCopyFunc)gnome_keyring_application_ref_copy,
                                                (GBoxedFreeFunc)gnome_keyring_application_ref_free);
    return our_type;
}
#endif /* #ifndef GNOME_KEYRING_APPLICATION_REF_TYPE */

#ifndef GNOME_KEYRING_TYPE_ACCESS_CONTROL
# define GNOME_KEYRING_TYPE_ACCESS_CONTROL pygnome_keyring_access_control_get_type()
static GType
pygnome_keyring_access_control_get_type(void)
{
    static GType our_type = 0;
  
    if (our_type == 0)
        our_type = g_boxed_type_register_static("PyGnomeKeyringAccessControl",
                                                (GBoxedCopyFunc)gnome_keyring_access_control_copy,
                                                (GBoxedFreeFunc)gnome_keyring_access_control_free);
    return our_type;
}
#endif /* #ifndef GNOME_KEYRING_ACCESS_CONTROL_TYPE */

#ifndef GNOME_KEYRING_TYPE_FOUND
# define GNOME_KEYRING_TYPE_FOUND pygnome_keyring_found_get_type()
GnomeKeyringFound *
pygnome_keyring_found_copy (GnomeKeyringFound *found)
{
    GnomeKeyringFound *copy;

    copy = g_new (GnomeKeyringFound, 1);
    memcpy (copy, found, sizeof (GnomeKeyringFound));

    copy->keyring = g_strdup (copy->keyring);
    copy->attributes = gnome_keyring_attribute_list_copy (copy->attributes);
    copy->secret = g_strdup (copy->secret);

    return copy;
}

static GType
pygnome_keyring_found_get_type(void)
{
    static GType our_type = 0;
  
    if (our_type == 0)
        our_type = g_boxed_type_register_static("PyGnomeKeyringFound",
                                                (GBoxedCopyFunc)pygnome_keyring_found_copy,
                                                (GBoxedFreeFunc)gnome_keyring_found_free);
    return our_type;
}
#endif /* #ifndef GNOME_KEYRING_ACCESS_CONTROL_TYPE */

static GnomeKeyringAttributeList *
pygnome_keyring_attribute_list_from_pyobject(PyObject *py_attrlist)
{
    GnomeKeyringAttributeList *attrlist;
    Py_ssize_t iter = 0;
    PyObject *key, *value;
    
    if (!PyDict_Check(py_attrlist)) {
        PyErr_SetString(PyExc_TypeError, "dict expected for attribute list parameter");
        return NULL;
    }

    attrlist = gnome_keyring_attribute_list_new();
    while (PyDict_Next(py_attrlist, &iter, &key, &value)) {
        char *name;
        if (!PyString_Check(key)) {
            PyErr_SetString(PyExc_TypeError, "dict keys must be strings, when converting attribute list parameter");
            gnome_keyring_attribute_list_free(attrlist);
            return NULL;
        }
        name = PyString_AsString(key);
        if (PyInt_Check(value))
            gnome_keyring_attribute_list_append_uint32(attrlist, name,
                                                       PyInt_AsLong(value));
        else if (PyLong_Check(value)) {
            gnome_keyring_attribute_list_append_uint32(attrlist, name,
                                                       PyLong_AsUnsignedLong(value));
            if (PyErr_Occurred()) {
                gnome_keyring_attribute_list_free(attrlist);
                return NULL;
            }
        }
        else if (PyString_Check(value))
            gnome_keyring_attribute_list_append_string(attrlist, name,
                                                       PyString_AsString(value));
        else {
            PyErr_SetString(PyExc_TypeError, "dict values must be strings, ints or longs,"
                            " when converting attribute list parameter");
            gnome_keyring_attribute_list_free(attrlist);
            return NULL;
        }
    }
    return attrlist;
}

static PyObject *
pygnome_keyring_attribute_list_as_pyobject(GnomeKeyringAttributeList *attrlist)
{
    PyObject *py_attrlist;
    int i, len = ((GArray *) attrlist)->len;

    py_attrlist = PyDict_New();
    for (i = 0; i < len; ++i) {
        GnomeKeyringAttribute *attr;
        PyObject *val = NULL;

        attr = &gnome_keyring_attribute_list_index(attrlist, i);

        switch (attr->type)
        {
        case GNOME_KEYRING_ATTRIBUTE_TYPE_STRING:
            val = PyString_FromString(attr->value.string);
            break;
	case GNOME_KEYRING_ATTRIBUTE_TYPE_UINT32:
            val = PyLong_FromUnsignedLong(attr->value.integer);
            break;
        default:
            Py_DECREF(py_attrlist);
            PyErr_SetString(PyExc_AssertionError, "invalided GnomeKeyringAttributeType"
                            " (congratulations, you found bug in bindings or C library)");
            return NULL;
        }

        if (PyDict_SetItemString(py_attrlist, attr->name, val)) {
            Py_DECREF(py_attrlist);
            return NULL;
        }
    }

    return py_attrlist;
}


#line 227 "gnomekeyring.c"


/* ---------- types from other modules ---------- */


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringAccessControl_Type;
PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringInfo_Type;
PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringItemInfo_Type;
PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringApplicationRef_Type;
PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringFound_Type;

#line 240 "gnomekeyring.c"



/* ----------- GnomeKeyringAccessControl ----------- */

static int
_wrap_gnome_keyring_access_control_new(PyGBoxed *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "application", "types_allowed", NULL };
    GnomeKeyringApplicationRef *application = NULL;
    PyObject *py_application;
    int types_allowed;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Oi:Gnome.AccessControl.__init__", kwlist, &py_application, &types_allowed))
        return -1;
    if (pyg_boxed_check(py_application, GNOME_KEYRING_TYPE_APPLICATION_REF))
        application = pyg_boxed_get(py_application, GnomeKeyringApplicationRef);
    else {
        PyErr_SetString(PyExc_TypeError, "application should be a GnomeKeyringApplicationRef");
        return -1;
    }
    self->gtype = GNOME_KEYRING_TYPE_ACCESS_CONTROL;
    self->free_on_dealloc = FALSE;
    self->boxed = gnome_keyring_access_control_new(application, types_allowed);

    if (!self->boxed) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GnomeKeyringAccessControl object");
        return -1;
    }
    self->free_on_dealloc = TRUE;
    return 0;
}

static PyObject *
_wrap_gnome_keyring_item_ac_get_display_name(PyObject *self)
{
    gchar *ret;

    
    ret = gnome_keyring_item_ac_get_display_name(pyg_boxed_get(self, GnomeKeyringAccessControl));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_ac_set_display_name(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    char *value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gnome.AccessControl.set_display_name", kwlist, &value))
        return NULL;
    
    gnome_keyring_item_ac_set_display_name(pyg_boxed_get(self, GnomeKeyringAccessControl), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_ac_get_path_name(PyObject *self)
{
    gchar *ret;

    
    ret = gnome_keyring_item_ac_get_path_name(pyg_boxed_get(self, GnomeKeyringAccessControl));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_ac_set_path_name(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    char *value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gnome.AccessControl.set_path_name", kwlist, &value))
        return NULL;
    
    gnome_keyring_item_ac_set_path_name(pyg_boxed_get(self, GnomeKeyringAccessControl), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_ac_get_access_type(PyObject *self)
{
    int ret;

    
    ret = gnome_keyring_item_ac_get_access_type(pyg_boxed_get(self, GnomeKeyringAccessControl));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gnome_keyring_item_ac_set_access_type(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gnome.AccessControl.set_access_type", kwlist, &value))
        return NULL;
    
    gnome_keyring_item_ac_set_access_type(pyg_boxed_get(self, GnomeKeyringAccessControl), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGnomeKeyringAccessControl_methods[] = {
    { "get_display_name", (PyCFunction)_wrap_gnome_keyring_item_ac_get_display_name, METH_NOARGS,
      NULL },
    { "set_display_name", (PyCFunction)_wrap_gnome_keyring_item_ac_set_display_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_path_name", (PyCFunction)_wrap_gnome_keyring_item_ac_get_path_name, METH_NOARGS,
      NULL },
    { "set_path_name", (PyCFunction)_wrap_gnome_keyring_item_ac_set_path_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_access_type", (PyCFunction)_wrap_gnome_keyring_item_ac_get_access_type, METH_NOARGS,
      NULL },
    { "set_access_type", (PyCFunction)_wrap_gnome_keyring_item_ac_set_access_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringAccessControl_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "AccessControl",                   /* tp_name */
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
    (struct PyMethodDef*)_PyGnomeKeyringAccessControl_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_gnome_keyring_access_control_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GnomeKeyringInfo ----------- */

static int
pygobject_no_constructor(PyObject *self, PyObject *args, PyObject *kwargs)
{
    gchar buf[512];

    g_snprintf(buf, sizeof(buf), "%s is an abstract widget", self->ob_type->tp_name);
    PyErr_SetString(PyExc_NotImplementedError, buf);
    return -1;
}

static PyObject *
_wrap_gnome_keyring_info_set_lock_on_idle(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gnome.Info.set_lock_on_idle", kwlist, &value))
        return NULL;
    
    gnome_keyring_info_set_lock_on_idle(pyg_boxed_get(self, GnomeKeyringInfo), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_info_get_lock_on_idle(PyObject *self)
{
    int ret;

    
    ret = gnome_keyring_info_get_lock_on_idle(pyg_boxed_get(self, GnomeKeyringInfo));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gnome_keyring_info_set_lock_timeout(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    unsigned long value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"k:Gnome.Info.set_lock_timeout", kwlist, &value))
        return NULL;
    
    gnome_keyring_info_set_lock_timeout(pyg_boxed_get(self, GnomeKeyringInfo), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_info_get_lock_timeout(PyObject *self)
{
    guint32 ret;

    
    ret = gnome_keyring_info_get_lock_timeout(pyg_boxed_get(self, GnomeKeyringInfo));
    
    return PyLong_FromUnsignedLong(ret);

}

static PyObject *
_wrap_gnome_keyring_info_get_mtime(PyObject *self)
{
    time_t ret;

    
    ret = gnome_keyring_info_get_mtime(pyg_boxed_get(self, GnomeKeyringInfo));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gnome_keyring_info_get_ctime(PyObject *self)
{
    time_t ret;

    
    ret = gnome_keyring_info_get_ctime(pyg_boxed_get(self, GnomeKeyringInfo));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gnome_keyring_info_get_is_locked(PyObject *self)
{
    int ret;

    
    ret = gnome_keyring_info_get_is_locked(pyg_boxed_get(self, GnomeKeyringInfo));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyGnomeKeyringInfo_methods[] = {
    { "set_lock_on_idle", (PyCFunction)_wrap_gnome_keyring_info_set_lock_on_idle, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_lock_on_idle", (PyCFunction)_wrap_gnome_keyring_info_get_lock_on_idle, METH_NOARGS,
      NULL },
    { "set_lock_timeout", (PyCFunction)_wrap_gnome_keyring_info_set_lock_timeout, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_lock_timeout", (PyCFunction)_wrap_gnome_keyring_info_get_lock_timeout, METH_NOARGS,
      NULL },
    { "get_mtime", (PyCFunction)_wrap_gnome_keyring_info_get_mtime, METH_NOARGS,
      NULL },
    { "get_ctime", (PyCFunction)_wrap_gnome_keyring_info_get_ctime, METH_NOARGS,
      NULL },
    { "get_is_locked", (PyCFunction)_wrap_gnome_keyring_info_get_is_locked, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringInfo_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "Info",                   /* tp_name */
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
    (struct PyMethodDef*)_PyGnomeKeyringInfo_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)pygobject_no_constructor,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GnomeKeyringItemInfo ----------- */

static int
_wrap_gnome_keyring_item_info_new(PyGBoxed *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,":Gnome.ItemInfo.__init__", kwlist))
        return -1;
    self->gtype = GNOME_KEYRING_TYPE_ITEM_INFO;
    self->free_on_dealloc = FALSE;
    self->boxed = gnome_keyring_item_info_new();

    if (!self->boxed) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GnomeKeyringItemInfo object");
        return -1;
    }
    self->free_on_dealloc = TRUE;
    return 0;
}

static PyObject *
_wrap_gnome_keyring_item_info_set_type(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", NULL };
    int type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gnome.ItemInfo.set_type", kwlist, &type))
        return NULL;
    
    gnome_keyring_item_info_set_type(pyg_boxed_get(self, GnomeKeyringItemInfo), type);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_info_get_secret(PyObject *self)
{
    gchar *ret;

    
    ret = gnome_keyring_item_info_get_secret(pyg_boxed_get(self, GnomeKeyringItemInfo));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_info_set_secret(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    char *value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gnome.ItemInfo.set_secret", kwlist, &value))
        return NULL;
    
    gnome_keyring_item_info_set_secret(pyg_boxed_get(self, GnomeKeyringItemInfo), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_info_get_display_name(PyObject *self)
{
    gchar *ret;

    
    ret = gnome_keyring_item_info_get_display_name(pyg_boxed_get(self, GnomeKeyringItemInfo));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_info_set_display_name(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    char *value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gnome.ItemInfo.set_display_name", kwlist, &value))
        return NULL;
    
    gnome_keyring_item_info_set_display_name(pyg_boxed_get(self, GnomeKeyringItemInfo), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_item_info_get_mtime(PyObject *self)
{
    time_t ret;

    
    ret = gnome_keyring_item_info_get_mtime(pyg_boxed_get(self, GnomeKeyringItemInfo));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gnome_keyring_item_info_get_ctime(PyObject *self)
{
    time_t ret;

    
    ret = gnome_keyring_item_info_get_ctime(pyg_boxed_get(self, GnomeKeyringItemInfo));
    
    return PyInt_FromLong(ret);
}

static const PyMethodDef _PyGnomeKeyringItemInfo_methods[] = {
    { "set_type", (PyCFunction)_wrap_gnome_keyring_item_info_set_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_secret", (PyCFunction)_wrap_gnome_keyring_item_info_get_secret, METH_NOARGS,
      NULL },
    { "set_secret", (PyCFunction)_wrap_gnome_keyring_item_info_set_secret, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_display_name", (PyCFunction)_wrap_gnome_keyring_item_info_get_display_name, METH_NOARGS,
      NULL },
    { "set_display_name", (PyCFunction)_wrap_gnome_keyring_item_info_set_display_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_mtime", (PyCFunction)_wrap_gnome_keyring_item_info_get_mtime, METH_NOARGS,
      NULL },
    { "get_ctime", (PyCFunction)_wrap_gnome_keyring_item_info_get_ctime, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringItemInfo_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "ItemInfo",                   /* tp_name */
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
    (struct PyMethodDef*)_PyGnomeKeyringItemInfo_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_gnome_keyring_item_info_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GnomeKeyringApplicationRef ----------- */

static int
_wrap_gnome_keyring_application_ref_new(PyGBoxed *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,":Gnome.ApplicationRef.__init__", kwlist))
        return -1;
    self->gtype = GNOME_KEYRING_TYPE_APPLICATION_REF;
    self->free_on_dealloc = FALSE;
    self->boxed = gnome_keyring_application_ref_new();

    if (!self->boxed) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GnomeKeyringApplicationRef object");
        return -1;
    }
    self->free_on_dealloc = TRUE;
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringApplicationRef_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "ApplicationRef",                   /* tp_name */
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
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_gnome_keyring_application_ref_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GnomeKeyringFound ----------- */

static PyObject *
_wrap_gnome_keyring_found__get_keyring(PyObject *self, void *closure)
{
    const gchar *ret;

    ret = pyg_boxed_get(self, GnomeKeyringFound)->keyring;
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_found__get_item_id(PyObject *self, void *closure)
{
    guint ret;

    ret = pyg_boxed_get(self, GnomeKeyringFound)->item_id;
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_gnome_keyring_found__get_attributes(PyObject *self, void *closure)
{
    GnomeKeyringAttributeList* ret;

    ret = pyg_boxed_get(self, GnomeKeyringFound)->attributes;
return pygnome_keyring_attribute_list_as_pyobject(ret);
}

static PyObject *
_wrap_gnome_keyring_found__get_secret(PyObject *self, void *closure)
{
    const gchar *ret;

    ret = pyg_boxed_get(self, GnomeKeyringFound)->secret;
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyGetSetDef gnome_keyring_found_getsets[] = {
    { "keyring", (getter)_wrap_gnome_keyring_found__get_keyring, (setter)0 },
    { "item_id", (getter)_wrap_gnome_keyring_found__get_item_id, (setter)0 },
    { "attributes", (getter)_wrap_gnome_keyring_found__get_attributes, (setter)0 },
    { "secret", (getter)_wrap_gnome_keyring_found__get_secret, (setter)0 },
    { NULL, (getter)0, (setter)0 },
};

PyTypeObject G_GNUC_INTERNAL PyGnomeKeyringFound_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "Found",                   /* tp_name */
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
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)gnome_keyring_found_getsets,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)pygobject_no_constructor,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_gnome_keyring_is_available(PyObject *self)
{
    int ret;

    
    ret = gnome_keyring_is_available();
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gnome_keyring_set_default_keyring_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", NULL };
    char *keyring;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"z:set_default_keyring_sync", kwlist, &keyring))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_set_default_keyring_sync(keyring);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 236 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_get_default_keyring_sync(PyObject *self)
{
    gint ret;
    char *keyring;
    
    pyg_begin_allow_threads;
    ret = gnome_keyring_get_default_keyring_sync(&keyring);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    if (keyring)
        return PyString_FromString(keyring);
    else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

#line 998 "gnomekeyring.c"


#line 257 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_list_keyring_names_sync(PyObject *self)
{
    gint ret;
    GList *keyrings, *l;
    PyObject *py_keyrings = NULL;

    pyg_begin_allow_threads;
    ret = gnome_keyring_list_keyring_names_sync(&keyrings);
    pyg_end_allow_threads;

    py_keyrings = PyList_New(0);
    for (l = keyrings; l; l = l->next) {
        PyObject *item = PyString_FromString((char *) l->data);
        PyList_Append(py_keyrings, item);
        Py_DECREF(item);
        g_free(l->data);
    }
    g_list_free(keyrings);
    if (pygnomekeyring_result_check(ret))
        return NULL;
    return py_keyrings;
}
#line 1025 "gnomekeyring.c"


static PyObject *
_wrap_gnome_keyring_lock_all_sync(PyObject *self)
{
    GnomeKeyringResult ret;

    pyg_begin_allow_threads;
    ret = gnome_keyring_lock_all_sync();
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_create_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring_name", "password", NULL };
    char *keyring_name, *password;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sz:create_sync", kwlist, &keyring_name, &password))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_create_sync(keyring_name, password);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_unlock_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "password", NULL };
    char *keyring, *password;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zs:unlock_sync", kwlist, &keyring, &password))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_unlock_sync(keyring, password);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_lock_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", NULL };
    char *keyring;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"z:lock_sync", kwlist, &keyring))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_lock_sync(keyring);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_delete_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", NULL };
    char *keyring;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"z:delete_sync", kwlist, &keyring))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_delete_sync(keyring);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gnome_keyring_change_password_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "original", "password", NULL };
    char *keyring, *original, *password;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zss:change_password_sync", kwlist, &keyring, &original, &password))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_change_password_sync(keyring, original, password);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 417 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_get_info_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", NULL };
    char *keyring;
    gint ret;
    GnomeKeyringInfo *info = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"z:get_info_sync", kwlist, &keyring))
        return NULL;

    pyg_begin_allow_threads;
    ret = gnome_keyring_get_info_sync(keyring, &info);
    pyg_end_allow_threads;

    /* pyg_boxed_new handles NULL checking */
    if (pygnomekeyring_result_check(ret))
        return NULL;
    return pyg_boxed_new(GNOME_KEYRING_TYPE_INFO, info, FALSE, TRUE);
}
#line 1153 "gnomekeyring.c"


static PyObject *
_wrap_gnome_keyring_set_info_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "info", NULL };
    char *keyring;
    PyObject *py_info;
    GnomeKeyringResult ret;
    GnomeKeyringInfo *info = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zO:set_info_sync", kwlist, &keyring, &py_info))
        return NULL;
    if (pyg_boxed_check(py_info, GNOME_KEYRING_TYPE_INFO))
        info = pyg_boxed_get(py_info, GnomeKeyringInfo);
    else {
        PyErr_SetString(PyExc_TypeError, "info should be a GnomeKeyringInfo");
        return NULL;
    }
    pyg_begin_allow_threads;
    ret = gnome_keyring_set_info_sync(keyring, info);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 563 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_list_item_ids_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", NULL };
    char *keyring;
    gint ret;
    GList *ids = NULL, *l;
    PyObject *py_ids;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"z:list_item_ids_sync", kwlist, &keyring))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_list_item_ids_sync(keyring, &ids);
    pyg_end_allow_threads;

    py_ids = PyList_New(0);
    for (l = ids; l; l = l->next)
    {
        PyObject *item;
        item = PyLong_FromUnsignedLong(GPOINTER_TO_UINT(l->data));
        PyList_Append(py_ids, item);
        Py_DECREF(item);
    }
    g_list_free(ids);
    if (pygnomekeyring_result_check(ret))
        return NULL;
    return py_ids;
}

#line 1212 "gnomekeyring.c"


static PyObject *
_wrap_gnome_keyring_daemon_set_display_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "display", NULL };
    char *display;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:daemon_set_display_sync", kwlist, &display))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_daemon_set_display_sync(display);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 752 "gnomekeyring.override"

typedef struct _GetItemsData
{
    GnomeKeyringAttributeList *attributes;
    PyObject *func;
    PyObject *data;
} GetItemsData;

void
GetItemsData__free (GetItemsData *data)
{
    gnome_keyring_attribute_list_free(data->attributes);
    Py_XDECREF(data->func);
    Py_XDECREF(data->data);
    g_free(data);
}

static void
_wrap_GnomeKeyringOperationGetListCallback(GnomeKeyringResult result,
                                           GList             *found,
                                           gpointer           data)
{
    GetItemsData *cb_data = data;
    PyObject *py_found;
    PyObject *ret;
    PyGILState_STATE state;
    GList *l;

    state = pyg_gil_state_ensure();

    py_found = PyList_New(0);
    for (l = found; l; l = l->next)
    {
        PyObject *item = pyg_boxed_new(GNOME_KEYRING_TYPE_FOUND, l->data, TRUE, TRUE);
        PyList_Append(py_found, item);
        Py_DECREF(item);
    }
    if (cb_data->data)
        ret = PyEval_CallFunction(cb_data->func, "NNO", pygnomekeyring_result_to_exception(result),
                                  py_found, cb_data->data);
    else
        ret = PyEval_CallFunction(cb_data->func, "NN", pygnomekeyring_result_to_exception(result),
                                  py_found);
    Py_XDECREF(ret);
    if (PyErr_Occurred())
        PyErr_Print();
    pyg_gil_state_release(state);
}

static PyObject *
_wrap_gnome_keyring_find_items(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", "attributes", "callback", "user_data", NULL };

    PyObject *py_type;
    GnomeKeyringItemType type;

    PyObject *py_attributes;
    GnomeKeyringAttributeList *attributes;

    PyObject *func, *data = NULL;
    GetItemsData *cb_data;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOO|O:find_items", kwlist,
                                     &py_type, &py_attributes, &func, &data))
        return NULL;

    if (pyg_enum_get_value(G_TYPE_NONE, py_type, (gint *)&type))
        return NULL;

    attributes = pygnome_keyring_attribute_list_from_pyobject(py_attributes);
    if (!attributes)
        return NULL;

    if (!PyCallable_Check(func)) {
        PyErr_SetString(PyExc_TypeError, "callback function not callable");
        return NULL;
    }
    cb_data = g_new(GetItemsData, 1);
    cb_data->func = func; Py_INCREF(func);
    cb_data->data = data; Py_XINCREF(data);
    cb_data->attributes = attributes;

    gnome_keyring_find_items(type, attributes,
                             _wrap_GnomeKeyringOperationGetListCallback,
                             cb_data, (GDestroyNotify) GetItemsData__free);

    Py_INCREF(Py_None);
    return Py_None;
}

#line 1325 "gnomekeyring.c"


#line 594 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_find_items_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", "attributes", NULL };
    PyObject *py_type = NULL;
    GnomeKeyringAttributeList * attributes;
    GnomeKeyringItemType type;
    gint ret;
    PyObject * py_attributes;
    GList *found = NULL, *l;
    PyObject *py_found;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:find_items_sync", kwlist, &py_type, &py_attributes))
        return NULL;
    if (pyg_enum_get_value(G_TYPE_NONE, py_type, (gint *)&type))
        return NULL;
    attributes = pygnome_keyring_attribute_list_from_pyobject(py_attributes);
    if (!attributes)
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_find_items_sync(type, attributes, &found);
    pyg_end_allow_threads;
    gnome_keyring_attribute_list_free(attributes);

    py_found = PyList_New(0);
    for (l = found; l; l = l->next)
    {
        PyObject *item = pyg_boxed_new(GNOME_KEYRING_TYPE_FOUND, l->data, FALSE, TRUE);
        PyList_Append(py_found, item);
        Py_DECREF(item);
    }
    g_list_free(found);

    if (pygnomekeyring_result_check(ret))
        return NULL;
    return py_found;
}

#line 1367 "gnomekeyring.c"


#line 634 "gnomekeyring.override"

static void
_wrap_GnomeKeyringOperationGetIntCallback(GnomeKeyringResult result,
                                          guint32            val,
                                          gpointer           data)
{
    PyGtkCustomNotify *cb_data = data;
    PyObject *ret;
    PyGILState_STATE state;

    state = pyg_gil_state_ensure();

    if (cb_data->data)
        
        ret = PyEval_CallFunction(cb_data->func, "OIO", pygnomekeyring_result_to_exception(result),
                                  val, cb_data->data);
    else
        ret = PyEval_CallFunction(cb_data->func, "OI", pygnomekeyring_result_to_exception(result),
                                  val);
    Py_XDECREF(ret);
    if (PyErr_Occurred())
        PyErr_Print();
    pyg_gil_state_release(state);
}

static PyObject *
_wrap_gnome_keyring_item_create(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "type", "display_name", "attributes",
                              "secret", "update_if_exists", "callback", "user_data", NULL };
    char *keyring, *display_name, *secret;
    int type, update_if_exists;
    PyObject *py_attributes;
    GnomeKeyringAttributeList * attributes;
    PyObject *func, *data = NULL;
    PyGtkCustomNotify *cb_data;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zisOsiO|O:item_create", kwlist,
                                     &keyring, &type, &display_name, &py_attributes,
                                     &secret, &update_if_exists, &func, &data))
        return NULL;

    if (!PyCallable_Check(func)) {
        PyErr_SetString(PyExc_TypeError, "callback function not callable");
        return NULL;
    }
    attributes = pygnome_keyring_attribute_list_from_pyobject(py_attributes);
    cb_data = g_new(PyGtkCustomNotify, 1);
    cb_data->func = func; Py_INCREF(func);
    cb_data->data = data; Py_XINCREF(data);

    gnome_keyring_item_create(keyring, type, display_name, attributes, secret, update_if_exists,
                              _wrap_GnomeKeyringOperationGetIntCallback, cb_data,
                              pygtk_custom_destroy_notify);
    
    gnome_keyring_attribute_list_free(attributes);
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1431 "gnomekeyring.c"


#line 439 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_item_create_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "type", "display_name", "attributes", "secret", "update_if_exists", NULL };
    PyObject * py_attributes;
    PyObject *py_type = NULL;
    char *keyring, *display_name, *secret;
    int update_if_exists;
    GnomeKeyringAttributeList * attributes;
    GnomeKeyringItemType type;
    gint ret;
    guint32 item_id = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zOsOsi:item_create_sync", kwlist, &keyring, &py_type, &display_name, &py_attributes, &secret, &update_if_exists))
        return NULL;
    if (pyg_enum_get_value(G_TYPE_NONE, py_type, (gint *)&type))
        return NULL;
    attributes = pygnome_keyring_attribute_list_from_pyobject(py_attributes);
    if (!attributes)
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_item_create_sync(keyring, type, display_name, attributes, secret, update_if_exists, &item_id);
    pyg_end_allow_threads;
    gnome_keyring_attribute_list_free(attributes);
    if (pygnomekeyring_result_check(ret))
        return NULL;
    return PyLong_FromUnsignedLong(item_id);
}

#line 1464 "gnomekeyring.c"


static PyObject *
_wrap_gnome_keyring_item_delete_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", NULL };
    char *keyring;
    GnomeKeyringResult ret;
    unsigned long id;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zk:item_delete_sync", kwlist, &keyring, &id))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_item_delete_sync(keyring, id);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 696 "gnomekeyring.override"

static void
_wrap_GnomeKeyringOperationGetItemInfoCallback(GnomeKeyringResult    result,
                                               GnomeKeyringItemInfo *info,
                                               gpointer              data)
{
    PyGtkCustomNotify *cb_data = data;
    PyObject *py_info;
    PyObject *ret;
    PyGILState_STATE state;

    state = pyg_gil_state_ensure();
    py_info = pyg_boxed_new(GNOME_KEYRING_TYPE_ITEM_INFO, info, TRUE, TRUE);
    if (cb_data->data)
        ret = PyEval_CallFunction(cb_data->func, "NNO", pygnomekeyring_result_to_exception(result),
                                  py_info, cb_data->data);
    else
        ret = PyEval_CallFunction(cb_data->func, "NN", pygnomekeyring_result_to_exception(result),
                                  py_info);
    Py_XDECREF(ret);
    if (PyErr_Occurred())
        PyErr_Print();
    pyg_gil_state_release(state);
}

static PyObject *
_wrap_gnome_keyring_item_get_info(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", "callback", "user_data", NULL };
    char *keyring;
    unsigned long id;
    PyObject *func, *data = NULL;
    PyGtkCustomNotify *cb_data;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zkO|O:item_get_info", kwlist,
                                     &keyring, &id, &func, &data))
        return NULL;

    if (!PyCallable_Check(func)) {
        PyErr_SetString(PyExc_TypeError, "callback function not callable");
        return NULL;
    }
    cb_data = g_new(PyGtkCustomNotify, 1);
    cb_data->func = func; Py_INCREF(func);
    cb_data->data = data; Py_XINCREF(data);

    gnome_keyring_item_get_info(keyring, id,
                              _wrap_GnomeKeyringOperationGetItemInfoCallback, cb_data,
                              pygtk_custom_destroy_notify);

    Py_INCREF(Py_None);
    return Py_None;
}

#line 1541 "gnomekeyring.c"


#line 470 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_item_get_info_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", NULL };
    char *keyring;
    unsigned long id;
    gint ret;
    GnomeKeyringItemInfo *info = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zk:item_get_info_sync", kwlist, &keyring, &id))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_item_get_info_sync(keyring, id, &info);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    return pyg_boxed_new(GNOME_KEYRING_TYPE_ITEM_INFO, info, FALSE, TRUE);
}

#line 1564 "gnomekeyring.c"


static PyObject *
_wrap_gnome_keyring_item_set_info_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", "info", NULL };
    char *keyring;
    PyObject *py_info;
    GnomeKeyringItemInfo *info = NULL;
    unsigned long id;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zkO:item_set_info_sync", kwlist, &keyring, &id, &py_info))
        return NULL;
    if (pyg_boxed_check(py_info, GNOME_KEYRING_TYPE_ITEM_INFO))
        info = pyg_boxed_get(py_info, GnomeKeyringItemInfo);
    else {
        PyErr_SetString(PyExc_TypeError, "info should be a GnomeKeyringItemInfo");
        return NULL;
    }
    pyg_begin_allow_threads;
    ret = gnome_keyring_item_set_info_sync(keyring, id, info);
    pyg_end_allow_threads;
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 282 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_item_get_attributes_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", NULL };
    char *keyring;
    unsigned long id;
    gint ret;
    GnomeKeyringAttributeList *attrlist = NULL;
    PyObject *py_attrlist;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zk:item_get_attributes_sync", kwlist, &keyring, &id))
        return NULL;

    pyg_begin_allow_threads;
    ret = gnome_keyring_item_get_attributes_sync(keyring, id, &attrlist);
    pyg_end_allow_threads;

    if (pygnomekeyring_result_check(ret))
        return NULL;

    py_attrlist = pygnome_keyring_attribute_list_as_pyobject(attrlist);
    if (!py_attrlist)
        return NULL;
    return py_attrlist;
}

#line 1621 "gnomekeyring.c"


static PyObject *
_wrap_gnome_keyring_item_set_attributes_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", "attributes", NULL };
    char *keyring;
    GnomeKeyringAttributeList * attributes;
    PyObject * py_attributes;
    unsigned long id;
    GnomeKeyringResult ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zkO:item_set_attributes_sync", kwlist, &keyring, &id, &py_attributes))
        return NULL;
    attributes = pygnome_keyring_attribute_list_from_pyobject(py_attributes);
    pyg_begin_allow_threads;
    ret = gnome_keyring_item_set_attributes_sync(keyring, id, attributes);
    pyg_end_allow_threads;
    gnome_keyring_attribute_list_free(attributes);
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 532 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_item_get_acl_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", NULL };
    char *keyring;
    unsigned long id;
    gint ret;
    GList *acl, *l;
    PyObject *pyacl;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zk:item_get_acl_sync", kwlist, &keyring, &id))
        return NULL;
    pyg_begin_allow_threads;
    ret = gnome_keyring_item_get_acl_sync(keyring, id, &acl);
    pyg_end_allow_threads;

    pyacl = PyList_New(0);
    for (l = acl; l; l = l->next) {
          /* steals ownership of the acl from the list */
        PyObject *item = pyg_boxed_new(GNOME_KEYRING_TYPE_ACCESS_CONTROL, l->data, FALSE, TRUE);
        PyList_Append(pyacl, item);
        Py_DECREF(item);
    }
    g_list_free(acl);
    if (pygnomekeyring_result_check(ret))
        return NULL;
    return pyacl;
}

#line 1677 "gnomekeyring.c"


#line 491 "gnomekeyring.override"

static PyObject *
_wrap_gnome_keyring_item_set_acl_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "id", "acl", NULL };
    char *keyring;
    unsigned long id;
    gint ret, i, len;
    PyObject *pyacl;
    GList *acl = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"zkO!:item_set_acl_sync", kwlist, &keyring, &id,
                                     &PyList_Type, &pyacl))
        return NULL;

    len = PyList_Size(pyacl);
    for (i = 0; i < len; ++i) {
        PyObject *item = PyList_GET_ITEM(pyacl, i);
        if (pyg_boxed_check(item, GNOME_KEYRING_TYPE_ACCESS_CONTROL))
            acl = g_list_prepend(acl, pyg_boxed_get(item, GnomeKeyringAccessControl));
        else {
            PyErr_SetString(PyExc_TypeError, "acl elements must be of type gnomekeyring.AccessControl");
            g_list_free(acl);
            return NULL;
        }
    }
    acl = g_list_reverse(acl);

    pyg_begin_allow_threads;
    ret = gnome_keyring_item_set_acl_sync(keyring, id, acl);
    pyg_end_allow_threads;

    g_list_free(acl);
    if (pygnomekeyring_result_check(ret))
        return NULL;
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1720 "gnomekeyring.c"


#line 349 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_find_network_password_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "user", "domain", "server", "object", "protocol", "authtype", "port", NULL };
    char *user = NULL;
    char *domain = NULL;
    char *server = NULL;
    char *object = NULL;
    char *protocol = NULL;
    char *authtype = NULL;
    unsigned long port = 0l;
    gint ret;
    GList *result = NULL, *l;
    PyObject *py_result;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"|zzzzzzk:find_network_password_sync", kwlist,
                                     &user, &domain, &server, &object, &protocol, &authtype, &port))
        return NULL;

    pyg_begin_allow_threads;
    ret = gnome_keyring_find_network_password_sync(user, domain, server, object,
                                                   protocol, authtype, port, &result);
    pyg_end_allow_threads;

    py_result = PyList_New(0);
    for (l = result; l; l = l->next) {
        GnomeKeyringNetworkPasswordData *data = l->data;
        PyObject *dict = PyDict_New();

        PyList_Append(py_result, dict);
        Py_DECREF(dict);

#define copy_string_attr(name)                                  \
        if (data->name) {                                       \
            PyObject *item = PyString_FromString(data->name);   \
            PyDict_SetItemString(dict, #name, item);            \
            Py_DECREF(item);                                    \
        }
#define copy_guint32_attr(name)                                         \
        if (data->name) {                                               \
            PyObject *item = PyLong_FromUnsignedLong(data->name);       \
            PyDict_SetItemString(dict, #name, item);                    \
            Py_DECREF(item);                                            \
        }
        
        copy_string_attr(keyring);
        copy_guint32_attr(item_id);
        copy_string_attr(protocol);
        copy_string_attr(server);
        copy_string_attr(object);
        copy_string_attr(authtype);
        copy_guint32_attr(port);
        copy_string_attr(user);
        copy_string_attr(domain);
        copy_string_attr(password);

#undef copy_guint32_attr
#undef copy_string_attr

    }
    gnome_keyring_network_password_list_free(result);
    if (pygnomekeyring_result_check(ret))
        return NULL;
    return py_result;
}

#line 1790 "gnomekeyring.c"


#line 310 "gnomekeyring.override"
static PyObject *
_wrap_gnome_keyring_set_network_password_sync(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keyring", "user", "domain", "server", "object",
                              "protocol", "authtype", "port", "password", NULL };
    char *keyring = NULL;
    char *user = NULL;
    char *domain = NULL;
    char *server = NULL;
    char *object = NULL;
    char *protocol = NULL;
    char *authtype = NULL;
    char *password = NULL;
    unsigned long port = 0;
    gint ret;
    guint32 item_id;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"|zzzzzzzks:set_network_password_sync", kwlist,
                                     &keyring, &user, &domain, &server, &object, &protocol,
                                     &authtype, &port, &password))
        return NULL;

    if (!password) {
        PyErr_SetString(PyExc_TypeError, "set_network_password_sync() argument 'password' must be supplied");
        return NULL;
    }

    pyg_begin_allow_threads;
    ret = gnome_keyring_set_network_password_sync(keyring, user, domain, server, object,
                                                  protocol, authtype, port, password, &item_id);
    pyg_end_allow_threads;

    if (pygnomekeyring_result_check(ret))
        return NULL;
    return PyLong_FromUnsignedLong(item_id);
}

#line 1831 "gnomekeyring.c"


const PyMethodDef pygnomekeyring_functions[] = {
    { "is_available", (PyCFunction)_wrap_gnome_keyring_is_available, METH_NOARGS,
      NULL },
    { "set_default_keyring_sync", (PyCFunction)_wrap_gnome_keyring_set_default_keyring_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_default_keyring_sync", (PyCFunction)_wrap_gnome_keyring_get_default_keyring_sync, METH_NOARGS,
      NULL },
    { "list_keyring_names_sync", (PyCFunction)_wrap_gnome_keyring_list_keyring_names_sync, METH_NOARGS,
      NULL },
    { "lock_all_sync", (PyCFunction)_wrap_gnome_keyring_lock_all_sync, METH_NOARGS,
      NULL },
    { "create_sync", (PyCFunction)_wrap_gnome_keyring_create_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unlock_sync", (PyCFunction)_wrap_gnome_keyring_unlock_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "lock_sync", (PyCFunction)_wrap_gnome_keyring_lock_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "delete_sync", (PyCFunction)_wrap_gnome_keyring_delete_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "change_password_sync", (PyCFunction)_wrap_gnome_keyring_change_password_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_info_sync", (PyCFunction)_wrap_gnome_keyring_get_info_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_info_sync", (PyCFunction)_wrap_gnome_keyring_set_info_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "list_item_ids_sync", (PyCFunction)_wrap_gnome_keyring_list_item_ids_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "daemon_set_display_sync", (PyCFunction)_wrap_gnome_keyring_daemon_set_display_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "find_items", (PyCFunction)_wrap_gnome_keyring_find_items, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "find_items_sync", (PyCFunction)_wrap_gnome_keyring_find_items_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_create", (PyCFunction)_wrap_gnome_keyring_item_create, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_create_sync", (PyCFunction)_wrap_gnome_keyring_item_create_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_delete_sync", (PyCFunction)_wrap_gnome_keyring_item_delete_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_get_info", (PyCFunction)_wrap_gnome_keyring_item_get_info, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_get_info_sync", (PyCFunction)_wrap_gnome_keyring_item_get_info_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_set_info_sync", (PyCFunction)_wrap_gnome_keyring_item_set_info_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_get_attributes_sync", (PyCFunction)_wrap_gnome_keyring_item_get_attributes_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_set_attributes_sync", (PyCFunction)_wrap_gnome_keyring_item_set_attributes_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_get_acl_sync", (PyCFunction)_wrap_gnome_keyring_item_get_acl_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_set_acl_sync", (PyCFunction)_wrap_gnome_keyring_item_set_acl_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "find_network_password_sync", (PyCFunction)_wrap_gnome_keyring_find_network_password_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_network_password_sync", (PyCFunction)_wrap_gnome_keyring_set_network_password_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
pygnomekeyring_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ITEM_GENERIC_SECRET", strip_prefix), GNOME_KEYRING_ITEM_GENERIC_SECRET);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ITEM_NETWORK_PASSWORD", strip_prefix), GNOME_KEYRING_ITEM_NETWORK_PASSWORD);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ITEM_NOTE", strip_prefix), GNOME_KEYRING_ITEM_NOTE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ITEM_LAST_TYPE", strip_prefix), GNOME_KEYRING_ITEM_LAST_TYPE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ITEM_NO_TYPE", strip_prefix), GNOME_KEYRING_ITEM_NO_TYPE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ACCESS_ASK", strip_prefix), GNOME_KEYRING_ACCESS_ASK);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ACCESS_DENY", strip_prefix), GNOME_KEYRING_ACCESS_DENY);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ACCESS_ALLOW", strip_prefix), GNOME_KEYRING_ACCESS_ALLOW);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ATTRIBUTE_TYPE_STRING", strip_prefix), GNOME_KEYRING_ATTRIBUTE_TYPE_STRING);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ATTRIBUTE_TYPE_UINT32", strip_prefix), GNOME_KEYRING_ATTRIBUTE_TYPE_UINT32);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ACCESS_READ", strip_prefix), GNOME_KEYRING_ACCESS_READ);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ACCESS_WRITE", strip_prefix), GNOME_KEYRING_ACCESS_WRITE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GNOME_KEYRING_ACCESS_REMOVE", strip_prefix), GNOME_KEYRING_ACCESS_REMOVE);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
pygnomekeyring_register_classes(PyObject *d)
{

#line 1926 "gnomekeyring.c"
    pyg_register_boxed(d, "AccessControl", GNOME_KEYRING_TYPE_ACCESS_CONTROL, &PyGnomeKeyringAccessControl_Type);
    pyg_register_boxed(d, "Info", GNOME_KEYRING_TYPE_INFO, &PyGnomeKeyringInfo_Type);
    pyg_register_boxed(d, "ItemInfo", GNOME_KEYRING_TYPE_ITEM_INFO, &PyGnomeKeyringItemInfo_Type);
    pyg_register_boxed(d, "ApplicationRef", GNOME_KEYRING_TYPE_APPLICATION_REF, &PyGnomeKeyringApplicationRef_Type);
    pyg_register_boxed(d, "Found", GNOME_KEYRING_TYPE_FOUND, &PyGnomeKeyringFound_Type);
}
